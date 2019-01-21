#include "CIntersection.h"

CIntersection::CIntersection()
{
}

CIntersection::CIntersection(CVec3d p_intersectionPoint, CVec3d p_normal, CObject * p_object)
{
	m_intersectionPoint		= p_intersectionPoint;
	m_normal				= p_normal;
	m_objectIntersected		= p_object;
}

CIntersection::~CIntersection()
{

}

CVec3d CIntersection::getIntersectionPoint()
{
	return m_intersectionPoint;
}

void CIntersection::setIntersectionPoint(CVec3d p_intersectionPoint)
{
	m_intersectionPoint = p_intersectionPoint;
}

CVec3d CIntersection::getNormal()
{
	return m_normal;
}

void CIntersection::setNormal(CVec3d p_normal)
{
	m_normal = p_normal;
}

CObject * CIntersection::getObjectIntersected()
{
	return m_objectIntersected;
}

void CIntersection::setIntersectedObject(CObject * p_object)
{
	m_objectIntersected = p_object;
}
