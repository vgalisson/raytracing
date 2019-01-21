#include "CCamera.h"

CCamera::CCamera()
{
}

CCamera::CCamera(CVec3d &p_origin, CVec3d &p_viewDir, CVec3d &p_upVec/*, CVec3d &p_rightVec*/, float p_viewHeight, float p_viewWidth, float p_focal, int p_xResolution, int p_yResolution)
{
	m_origin		= p_origin;
	m_viewDir		= p_viewDir;
	m_viewDir.normalize();
	m_upVec			= p_upVec;
	m_upVec.normalize();
	m_rightVec		= vectorialProduct(p_viewDir, m_upVec);
	m_rightVec.normalize();
	m_viewHeight	= p_viewHeight;
	m_viewWidth		= p_viewWidth;
	m_focal			= p_focal;
	m_xResolution	= p_xResolution;
	m_yResolution	= p_yResolution;

	m_upLeft = m_origin + ((m_viewDir*m_focal) + (m_upVec*(m_viewHeight / 2.0f))) - (m_rightVec*(m_viewWidth / 2.0f));
}

CCamera::~CCamera()
{
}

CVec3d CCamera::getOrigin()
{
	return m_origin;
}

CVec3d CCamera::getviewDir()
{
	return m_viewDir;
}

float CCamera::getHeight()
{
	return m_viewHeight;
}

float CCamera::getWidth()
{
	return m_viewWidth;
}

int CCamera::getXRes()
{
	return m_xResolution;
}

int CCamera::getYRes()
{
	return m_yResolution;
}

CVec3d CCamera::calcNext(int p_x, int p_y)
{
		float xIndent, yIndent;

		xIndent = m_viewWidth / (float) m_xResolution;
		yIndent = m_viewHeight / (float) m_yResolution;

		return (m_upLeft + m_rightVec*xIndent*p_x - m_upVec*yIndent*p_y) - m_origin;
}
