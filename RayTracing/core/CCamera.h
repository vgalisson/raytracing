#ifndef _CCAMERA_
#define _CCAMERA_

#include "CVec3d.h"
#include "CRay.h"

class CCamera
{
protected:
	CVec3d	m_origin, m_viewDir, m_upVec, m_rightVec, m_upLeft;
	float	m_viewHeight;
	float	m_viewWidth;
	float	m_focal;
	int		m_xResolution;
	int		m_yResolution;

public:
	CCamera();
	CCamera(CVec3d &p_origin, CVec3d &p_viewDir, CVec3d &p_upVec, float p_viewHeight, float p_viewWidth, float p_focal, int p_xResolution, int p_yResolution);
	~CCamera();

	CVec3d	getOrigin();
	CVec3d	getviewDir();
	float	getHeight();
	float	getWidth();
	int		getXRes();
	int		getYRes();
	CVec3d	calcNext(int p_x, int p_y);
};

#endif // !_CCAMERA_
