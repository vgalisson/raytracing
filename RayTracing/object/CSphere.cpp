#include "CSphere.h"

CSphere::CSphere()
{
	CVec3d();
	m_radius = 1;
}

CSphere::CSphere(CVec3d p_center, float p_radius)
{
	m_center = p_center;
	m_radius = p_radius;
}

CSphere::~CSphere()
{
}

char* CSphere::toString()
{
	return "Class CSphere\n";
}

bool CSphere::intersect(CRay &p_ray, CIntersection &p_intersection)
{
	float a, b, c, det, point, point1, point2;
	CVec3d intersectionPoint, tmpNormal, vecView;

	vecView = p_ray.getOrigin() - m_center;
	
	a = powf(scalarProduct(p_ray.getDir(), p_ray.getDir()), 2);

	b = 2 * scalarProduct(vecView, p_ray.getDir());

	c =  powf(p_ray.getOrigin().getX() - m_center.getX(), 2)
		+ powf(p_ray.getOrigin().getY() - m_center.getY(), 2)
		+ powf(p_ray.getOrigin().getZ() - m_center.getZ(), 2) - m_radius*m_radius;

	det = b*b - 4 * a * c;

	if (det < 0)
		return false;
	else
	{
		if (det != 0)
		{
			det = sqrt(det);
			point1 = (-b + det) / (2 * a);
			point2 = (-b - det) / (2 * a);
			if (point1 < 0 || point2 < 0) return false;

			if (point1 < point2)
				point = point1;
			else
				point = point2;
		}
		else
			point = -b / (2 * a);
			

		intersectionPoint = p_ray.getOrigin() + (p_ray.getDir() * point); 

		tmpNormal = (intersectionPoint - m_center) / m_radius;
		tmpNormal.normalize();

		p_intersection.setIntersectionPoint(intersectionPoint + tmpNormal * EPSILON); 		// normal * EPSILON is the shadow bias
		p_intersection.setNormal(tmpNormal);
		p_intersection.setIntersectedObject(this);

		return true;
	}

}

float CSphere::getRadius()
{
	return m_radius;
}

void CSphere::setRadius(float p_radius)
{
	m_radius = p_radius;
}

CVec3d CSphere::getCenter()
{
	return m_center;
}

void CSphere::setCenter(CVec3d p_center)
{
	m_center = p_center;
}
