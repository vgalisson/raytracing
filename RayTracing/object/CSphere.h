#ifndef _CSPHERE_
#define _CSPHERE_

#include "../core/CVec3d.h"
#include "CObject.h"

class CSphere : public CObject
{
protected:
	CVec3d	 m_center;
	float	 m_radius;

public:
	CSphere();
	CSphere(CVec3d p_center, float p_radius);
	~CSphere();
	char*	toString();

	bool	intersect(CRay &p_ray, CIntersection &p_intersection);

	float	getRadius();
	void	setRadius(float p_radius);
	CVec3d	getCenter();
	void	setCenter(CVec3d p_center);
};

#endif // !_CSPHERE_