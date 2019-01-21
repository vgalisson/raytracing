#ifndef _CTRIANGLE_
#define _CTRIANGLE_

#include "../core/CVec3d.h"
#include "CObject.h"

class CTriangle : public CObject
{
protected:
	CVec3d	m_vertexA, m_vertexB, m_vertexC;

public:
	CTriangle();
	CTriangle(CVec3d p_vertexA, CVec3d p_vertexB, CVec3d p_vertexC);
	~CTriangle();
	char*	toString();

	bool	intersect(CRay &p_ray, CIntersection &p_intersection);

	CVec3d	getAVertex();
	void	setAVertex(CVec3d p_vertexA);
	CVec3d	getBVertex();
	void	setBVertex(CVec3d p_vertexB);
	CVec3d	getCVertex();
	void	setCVertex(CVec3d p_vertexC);
};

#endif // !_CTRIANGLE_
