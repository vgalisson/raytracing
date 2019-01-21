#include "CLight.h"

CLight::CLight()
{

}

CLight::CLight(CVec3d p_source, CColor p_color)
{
	m_source = p_source;
	m_color = p_color;
}

CLight::~CLight()
{

}

CVec3d CLight::getSource()
{
	return m_source;
}

CColor CLight::getColor()
{
	return m_color;
}

bool CLight::intersect(CRay &p_ray, CIntersection &p_intersection)
{
	return false;
}

CColor CLight::getDiffuseColoration(CVec3d & p_normal, CVec3d & p_intersectionPoint, CMaterial & p_material)
{
	CVec3d	vecLight;
	CColor	color;
	float	angle, distLight, lightFallOff;

	vecLight = m_source - p_intersectionPoint ;
	distLight = vecLight.getNorm();

	p_normal.normalize();
	vecLight.normalize();

	lightFallOff = FALLOFF / distLight;

	angle = scalarProduct(p_normal, vecLight);
	
	if (angle <= 0)
		color = CColor(0.0f, 0.0f, 0.0f);
	else
		color = p_material.getColor() * p_material.getDiffuseCoefficient() * angle * lightFallOff * m_color ;

	return color;
}

CColor CLight::getSpecularColoration(CVec3d & p_normal, CVec3d & p_intersectionPoint, CMaterial & p_material, CVec3d & p_viewOrigin)
{
	CColor	color;
	CVec3d	vecLight, vecMedian;
	float	angle, distLight, lightFallOff;

	vecLight = m_source - p_intersectionPoint;
	distLight = vecLight.getNorm();

	vecMedian = vecLight + (p_viewOrigin - p_intersectionPoint);

	vecMedian.normalize();

	lightFallOff = FALLOFF / distLight;

	angle = scalarProduct(p_normal, vecMedian);

	if (angle <= 0)
		color = CColor(0.0f, 0.0f, 0.0f);
	else
		color = p_material.getColor() * p_material.getSpecularCoefficient() * powf(angle, p_material.getShininess()) * lightFallOff * m_color;

	return color;
}
