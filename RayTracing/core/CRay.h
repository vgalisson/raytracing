#ifndef _CRAY_
#define _CRAY_

#include "CVec3d.h"

class CRay
{
protected:
	CVec3d	m_dir, m_origin;

public:
	CRay();
	CRay(CVec3d p_dir, CVec3d p_origin);
	~CRay();

	CVec3d	getDir();
	void	setDir(CVec3d p_dir);
	CVec3d	getOrigin();
	void	setOrigin(CVec3d p_origin);
};

#endif // !_CRAY_