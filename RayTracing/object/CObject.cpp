#include "CObject.h"

CObject::CObject()
{
}

CObject::~CObject()
{
}

bool CObject::intersect(CRay & p_ray, CIntersection & p_intersection)
{
	return true;
}

char* CObject::toString()
{
	return "Class CObject\n";
}

CMaterial CObject::getMaterial()
{
	return m_material;
}

void CObject::setMaterial(CMaterial & p_material)
{
	m_material = p_material;
}

