#include "CScene.h"
#include <iostream>

CScene::CScene()
{
}

CScene::~CScene()
{
}

CObject * CScene::getObject(int p_index)
{
	return m_objects.at(p_index);
}

CLight * CScene::getLight(int p_index)
{
	return m_lights.at(p_index);
}

void CScene::setCamera(CCamera * p_camera)
{
	m_camera = p_camera;
}

void CScene::addObject(CObject * p_object)
{
	m_objects.push_back(p_object);
}

void CScene::addLight(CLight * p_light)
{
	m_lights.push_back(p_light);
}

CColor CScene::raytrace(CRay & p_ray)
{
	std::vector<CObject*>::iterator		itO;
	float								tmpDistance;
	float								bestDistance = INFINITY;
	CIntersection						tmpIntersection;
	CIntersection						closestIntersection;
	bool								intersection = false;
	
	std::vector<CLight*>::iterator		itL;
	CVec3d								vecShadow;
	CVec3d								shadowIntersectionToLight;
	CRay								rayShadow;
	float								distLightToIntersection;
	float								distLightToNewIntersection;
	bool								bLightBlocked;
	CIntersection						shadowIntersection;

	CMaterial							tmpMaterial;
	CColor								color = CColor(0.0f, 0.0f, 0.0f);

	// going through all the objects
	for (itO = m_objects.begin(); itO != m_objects.end(); itO++)
	{
		// if the ray intersect the object
		if ((*itO)->intersect(p_ray, tmpIntersection))
		{
			intersection = true;
			tmpDistance = squareLength(tmpIntersection.getIntersectionPoint(), p_ray.getOrigin());

			// if the object intersected is closer to the camera than the others
			if (tmpDistance < bestDistance)
			{
				bestDistance = tmpDistance;
				closestIntersection = tmpIntersection;
			}
		}
	}

	
	if (intersection)
	{
		tmpMaterial = closestIntersection.getObjectIntersected()->getMaterial();				// material of the rendered object

		// going through all the lights
		for (itL = m_lights.begin(); itL != m_lights.end(); itL++)
		{
			bLightBlocked = false;

			// creating a shadow ray from the intersection to the light and see if an object is obscuring the intersection point
			vecShadow = (*itL)->getSource() - closestIntersection.getIntersectionPoint();		// A->B = B - A
			distLightToIntersection = vecShadow.getNorm();

			rayShadow.setOrigin(closestIntersection.getIntersectionPoint());
			rayShadow.setDir(vecShadow);														// vecShadow is normalized within the setDir()

			// looking for any intersection between the shadow ray and the objects
			for (itO = m_objects.begin(); itO != m_objects.end(); itO++)
			{
				//if ((*itO) != closestIntersection.getObjectIntersected())						// if it's not itself
				if ((*itO)->intersect(rayShadow, shadowIntersection))
				{
					shadowIntersectionToLight = (*itL)->getSource() - shadowIntersection.getIntersectionPoint();

					// check if the new intersection is behind the light or not
					if (scalarProduct(shadowIntersectionToLight, rayShadow.getDir()) > 0)
					{
						distLightToNewIntersection = shadowIntersectionToLight.getNorm();
						if (distLightToNewIntersection < distLightToIntersection)
							bLightBlocked = true;												// point in shadow
					}
				}
			}

			// if the light hits directly the intersection point
			if (!bLightBlocked)
			{
				color = color + (*itL)->getDiffuseColoration(closestIntersection.getNormal(), closestIntersection.getIntersectionPoint(), tmpMaterial);									// DIFFUSE COLOR
				color = color + (*itL)->getSpecularColoration(closestIntersection.getNormal(), closestIntersection.getIntersectionPoint(), tmpMaterial, m_camera->getOrigin());			// SPECULAR COLOR
			}
		}

		color = color + (tmpMaterial.getColor() * tmpMaterial.getAmbientCoefficient());																									// AMBIENT COLOR
	}
	
	color.normalizeColor();
	return color;
}

void CScene::render()
{
	int			width			= m_camera->getXRes();
	int			height			= m_camera->getYRes();
	FIBITMAP *	img				= FreeImage_Allocate(width, height, 24);
	CColor *	currentPixel	= NULL;
	RGBQUAD		pixelColor;
	CVec3d		dir;
	CRay		currentRay;

	int			progress		= 0;


	currentRay.setOrigin(m_camera->getOrigin());

	for(int y = 0;  y < height; y++)
		for (int x = 0; x < width; x++)
		{

			dir = m_camera->calcNext(x, y);
			dir.normalize();
			currentRay.setDir(dir);

			currentPixel = &raytrace(currentRay);

			pixelColor.rgbRed		= (BYTE) (currentPixel->getRed() * 255);
			pixelColor.rgbGreen		= (BYTE) (currentPixel->getGreen() * 255);
			pixelColor.rgbBlue		= (BYTE) (currentPixel->getBlue() * 255);
			FreeImage_SetPixelColor(img, x, height - y, &pixelColor);
		}

	if (FreeImage_Save(FIF_BMP, img, "img.bmp", 0))
		std::cout << "Save completed. \n";

	FreeImage_Unload(img);
	
}
