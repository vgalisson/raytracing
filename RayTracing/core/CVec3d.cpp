#include "CVec3d.h"

CVec3d::CVec3d()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
	m_h = 0;
}

CVec3d::CVec3d(float p_x, float p_y, float p_z)
{
	m_x = p_x;
	m_y = p_y;
	m_z = p_z;
	m_h = 1;
}

CVec3d::~CVec3d()
{
}

float CVec3d::getX()
{
	return m_x;
}

float CVec3d::getY()
{
	return m_y;
}

float CVec3d::getZ()
{
	return m_z;
}

float CVec3d::getH()
{
	return m_h;
}

void CVec3d::normalize()
{
	float norm = getNorm();

	m_x = m_x / norm;
	m_y = m_y / norm;
	m_z = m_z / norm;
}

float CVec3d::getNorm()
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

void CVec3d::toCartesian()
{
	m_x = m_x / m_h;
	m_y = m_y / m_h;
	m_y = m_z / m_h;
	m_h = 1;
}

float scalarProduct(CVec3d &p_a, CVec3d &p_b)
{
	return p_a.getX() * p_b.getX() + p_a.getY() * p_b.getY() + p_a.getZ() * p_b.getZ();
}

CVec3d vectorialProduct(CVec3d &p_a, CVec3d &p_b)
{
	float tmpX = p_a.getY() * p_b.getZ() - p_a.getZ() * p_b.getY();
	float tmpY = p_a.getZ() * p_b.getX() - p_a.getX() * p_b.getZ();
	float tmpZ = p_a.getX() * p_b.getY() - p_a.getY() * p_b.getX();

	return CVec3d(tmpX, tmpY, tmpZ);
}

CVec3d reflected(CVec3d &p_incident, CVec3d &p_normal)
{
	return p_incident - 2 * scalarProduct(p_incident, p_normal) * p_normal;
}

float squareLength(CVec3d & p_a, CVec3d & p_b)
{
	return powf(p_b.getX() - p_a.getX(), 2) + powf(p_b.getY() - p_a.getY(), 2) + powf(p_b.getZ() - p_a.getZ(), 2);
}

CVec3d operator+(CVec3d &p_a, CVec3d &p_b)
{
	return CVec3d(p_a.getX() + p_b.getX(), p_a.getY() + p_b.getY(), p_a.getZ() + p_b.getZ());
}

CVec3d operator-(CVec3d &p_a, CVec3d &p_b)
{
	return CVec3d(p_a.getX() - p_b.getX(), p_a.getY() - p_b.getY(), p_a.getZ() - p_b.getZ());
}

CVec3d operator-(CVec3d & p_a)
{
	return CVec3d(-p_a.getX(), -p_a.getY(), -p_a.getZ());
}

CVec3d operator*(float p_a, CVec3d &p_b)
{
	return CVec3d(p_a * p_b.getX(), p_a * p_b.getY(), p_a * p_b.getZ());
}

CVec3d operator*(CVec3d &p_a, float p_b)
{
	return CVec3d(p_a.getX()  * p_b, p_a.getY() * p_b, p_a.getZ() * p_b);
}

CVec3d operator/(CVec3d &p_a, float p_b)
{
	return CVec3d(p_a.getX() / p_b, p_a.getY() / p_b, p_a.getZ() / p_b);
}