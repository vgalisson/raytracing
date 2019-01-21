#include "CRay.h"

CRay::CRay()
{
}

CRay::CRay(CVec3d p_dir, CVec3d p_origin)
{
	m_dir		= p_dir;
	m_dir.normalize();

	m_origin	= p_origin;
}

CRay::~CRay()
{
}

CVec3d CRay::getDir()
{
	return m_dir;
}

void CRay::setDir(CVec3d p_dir)
{
	m_dir = p_dir;
	m_dir.normalize();
}

CVec3d CRay::getOrigin()
{
	return m_origin;
}

void CRay::setOrigin(CVec3d p_origin)
{
	m_origin = p_origin;
}
