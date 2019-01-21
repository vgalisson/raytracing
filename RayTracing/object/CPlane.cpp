#include "CPlane.h"

CPlane::CPlane()
{
}

CPlane::CPlane(CVec3d p_point, CVec3d p_normal)
{
	m_point		= p_point;
	m_normal	= p_normal;
	m_normal.normalize();
}

CPlane::~CPlane()
{
}

char* CPlane::toString()
{
	return "Class CPlane\n";
}

bool CPlane::intersect(CRay &p_ray, CIntersection &p_intersection)
{
	float point, denom;
	
	denom = scalarProduct(m_normal, p_ray.getDir());

	if (denom < EPSILON && denom > -EPSILON)		// if normal and direction are perpendicular, there is no intersection (N.RAY = 0)
		return false;

	point = scalarProduct(m_point - p_ray.getOrigin() , m_normal ) / denom;

	if (point < 0)		// if ray is behind the plane
		return false;

	p_intersection.setIntersectionPoint(p_ray.getOrigin() + (p_ray.getDir() * point) + m_normal * EPSILON);		// the m_normal * EPSILON is the shadow bias

	if (denom < 0)
		p_intersection.setNormal(m_normal);
	else
		p_intersection.setNormal(-m_normal);

	p_intersection.setIntersectedObject(this);

	return true;
}

CVec3d CPlane::getPoint()
{
	return m_point;
}

void CPlane::setPoint(CVec3d p_point)
{
	m_point = p_point;
}

CVec3d CPlane::getNormal()
{
	return m_normal;
}

void CPlane::setNormal(CVec3d p_normal)
{
	m_normal = p_normal;
	m_normal.normalize();
}
