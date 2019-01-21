#ifndef _CVEC3D_H_
#define _CVEC3D_H_

#include "Utils.h"

class CVec3d
{

protected:
	float	m_x, m_y, m_z, m_h;	// m_h pour le représentation homogène

public:
	CVec3d();
	CVec3d(float p_x, float p_y, float p_z);
	~CVec3d();

	float	getX();
	float	getY();
	float	getZ();
	float	getH();

	void	normalize();
	float	getNorm();											// the length, same as squareLength() but with the square root
	void	toCartesian();
};

float	scalarProduct(CVec3d &p_a, CVec3d &p_b);
CVec3d	vectorialProduct(CVec3d &p_a, CVec3d &p_b);
CVec3d	reflected(CVec3d &p_incident, CVec3d &p_normal);

float	squareLength(CVec3d &p_a, CVec3d &p_b);					// to save computation time, it doesn't use the square root
CVec3d	operator+(CVec3d &p_a, CVec3d &p_b);
CVec3d	operator-(CVec3d &p_a, CVec3d &p_b);
CVec3d	operator-(CVec3d &p_a);
CVec3d	operator*(float p_a, CVec3d &p_b);
CVec3d	operator*(CVec3d &p_a, float p_b);
CVec3d	operator/(CVec3d &p_a, float p_b);

#endif // !_CVEC3D_H_