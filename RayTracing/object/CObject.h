#ifndef _COBJECT_
#define _COBJECT_

#include "../core/Utils.h"
#include "../core/CRay.h"
#include "../core/CIntersection.h"
#include "../material/CColor.h"
#include "../material/CMaterial.h"

class CObject
{
protected:
	CMaterial	m_material;

public:
	CObject();
	~CObject();
	virtual bool	intersect(CRay &p_ray, CIntersection &p_intersection);
	virtual char*	toString();

	CMaterial		getMaterial();
	void			setMaterial(CMaterial &p_material);
};

#endif // !_CPRIMITIVE_