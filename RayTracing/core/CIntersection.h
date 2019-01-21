#ifndef _CINTERSECTION_
#define _CINTERSECTION_

#include "CVec3d.h"

class CObject;	//forward declaration

class CIntersection
{
protected:
	CVec3d			m_intersectionPoint;
	CVec3d			m_normal;
	CObject *		m_objectIntersected;

public:
	CIntersection();
	CIntersection(CVec3d p_intersectionPoint, CVec3d p_normal, CObject* p_object);
	~CIntersection();

	CVec3d			getIntersectionPoint();
	void			setIntersectionPoint(CVec3d p_intersectionPoint);
	CVec3d			getNormal();
	void			setNormal(CVec3d p_normal);
	CObject *		getObjectIntersected();
	void			setIntersectedObject(CObject * p_object);
};

#endif // !_CINTERSECTION_
