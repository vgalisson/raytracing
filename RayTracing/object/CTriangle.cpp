#include "CTriangle.h"

CTriangle::CTriangle()
{
}

CTriangle::CTriangle(CVec3d p_vertexA, CVec3d p_vertexB, CVec3d p_vertexC)
{
	m_vertexA = p_vertexA;
	m_vertexB = p_vertexB;
	m_vertexC = p_vertexC;
}

CTriangle::~CTriangle()
{

}

char* CTriangle::toString()
{
	return "Class CTriangle\n";
}

bool CTriangle::intersect(CRay &p_ray, CIntersection &p_intersection)
{
	CVec3d AB, AC, normal, intersectionPoint;
	float point, denom, triangleArea, ABParea, BCParea, CAParea ;

	AB = m_vertexB - m_vertexA;
	AC = m_vertexC - m_vertexA;

	normal = vectorialProduct(AB, AC);
	normal.normalize();

	// check if ray and plane are parallel or not
	denom = scalarProduct(normal, p_ray.getDir());

	if (denom < EPSILON && denom > - EPSILON)		// if normal and direction are perpendicular, there is no intersection (=0)
		return false;

	point = (scalarProduct(m_vertexA - p_ray.getOrigin() , normal)) / denom;
	
	if (point < 0)		// if the ray is behind
		return false;

	intersectionPoint = p_ray.getOrigin() + (p_ray.getDir() * point) + normal * EPSILON;		// the normal * EPSILON is the shadow bias

	// using the area method to calculate if the point is within the traingle or not
	triangleArea = vectorialProduct(AB, AC).getNorm() / 2;

	ABParea = vectorialProduct(AB, intersectionPoint - m_vertexA).getNorm() / 2;
	BCParea = vectorialProduct(m_vertexC - m_vertexB, intersectionPoint - m_vertexB).getNorm() / 2;
	CAParea = vectorialProduct(-AC, intersectionPoint - m_vertexC).getNorm() / 2;

	if (ABParea + BCParea + CAParea - triangleArea > EPSILON)
		return false;

	p_intersection.setIntersectionPoint(intersectionPoint);

	if (denom < 0)
		p_intersection.setNormal(normal);
	else
		p_intersection.setNormal(-normal);

	p_intersection.setIntersectedObject(this);

	return true;
}

CVec3d CTriangle::getAVertex()
{
	return m_vertexA;
}

void CTriangle::setAVertex(CVec3d p_vertexA)
{
	m_vertexA = p_vertexA;
}

CVec3d CTriangle::getBVertex()
{
	return m_vertexB;
}

void CTriangle::setBVertex(CVec3d p_vertexB)
{
	m_vertexB = p_vertexB;
}

CVec3d CTriangle::getCVertex()
{
	return m_vertexC;
}

void CTriangle::setCVertex(CVec3d p_vertexC)
{
	m_vertexC = p_vertexC;
}
