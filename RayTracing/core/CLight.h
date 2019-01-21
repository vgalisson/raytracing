#ifndef _CLIGHT_
#define _CLIGHT_

#include "CVec3d.h"
#include "../object/CObject.h"
#include "../material/CMaterial.h"

class CLight : public CObject
{
protected:
	CVec3d	m_source;
	CColor	m_color;

public:
	CLight();
	CLight(CVec3d p_source, CColor p_color);
	~CLight();

	CVec3d	getSource();
	CColor	getColor();
	bool	intersect(CRay &p_ray, CIntersection &p_intersection);

	CColor	getDiffuseColoration(CVec3d& p_normal, CVec3d& p_intersectionPoint, CMaterial& p_material);
	CColor	getSpecularColoration(CVec3d& p_normal, CVec3d& p_intersectionPoint, CMaterial& p_material, CVec3d& p_viewOrigin);

};


#endif // !_CLIGHT_