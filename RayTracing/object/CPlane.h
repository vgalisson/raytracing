#ifndef _CPLANE_
#define _CPLANE_

#include "../core/CVec3d.h"
#include "CObject.h"

class CPlane : public CObject
{
protected:
	CVec3d	m_point, m_normal;

public:
	CPlane();
	CPlane(CVec3d p_point, CVec3d p_normal);
	~CPlane();
	char*	toString();

	bool	intersect(CRay &p_ray, CIntersection &p_intersection);

	CVec3d	getPoint();
	void	setPoint(CVec3d p_point);
	CVec3d	getNormal();
	void	setNormal(CVec3d p_normal);
};

#endif // !_CPLANE_