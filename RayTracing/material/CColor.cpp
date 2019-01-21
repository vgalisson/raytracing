#include "CColor.h"

CColor::CColor()
{
}

CColor::CColor(float p_red, float p_green, float p_blue)
{
	m_red	= p_red;
	m_green = p_green;
	m_blue	= p_blue;
}

CColor::~CColor()
{
}

float CColor::getRed()
{
	return m_red;
}

void CColor::setRed(float p_red)
{
	m_red = p_red;
}

float CColor::getGreen()
{
	return m_green;
}

void CColor::setGreen(float p_green)
{
	m_green = p_green;
}

float CColor::getBlue()
{
	return m_blue;
}

void CColor::setBlue(float p_blue)
{
	m_blue = p_blue;
}

void CColor::normalizeColor() 
{ 
	if (m_red > 1.0f) m_red = 1.0f;
	if (m_green > 1.0f) m_green = 1.0f;
	if (m_blue > 1.0f) m_blue = 1.0f; 

	if (m_red < 0.0f) m_red = 0.0f;
	if (m_green < 0.0f) m_green = 0.0f;
	if (m_blue < 0.0f) m_blue = 0.0f;
}

CColor operator*(CColor & p_c1, CColor & p_c2)
{
	return CColor(p_c1.getRed() * p_c2.getRed(), p_c1.getGreen() * p_c2.getGreen(), p_c1.getBlue() * p_c2.getBlue());
}

CColor operator*(CColor & p_c1, float p_multiple)
{
	return CColor(p_c1.getRed() * p_multiple, p_c1.getGreen() * p_multiple, p_c1.getBlue() * p_multiple);
}

CColor operator+(CColor & p_c1, CColor & p_c2)
{
	return CColor(p_c1.getRed() + p_c2.getRed(), p_c1.getGreen() + p_c2.getGreen(), p_c1.getBlue() + p_c2.getBlue());
}

CColor operator-(CColor & p_c1, CColor & p_c2)
{
	return CColor(p_c1.getRed() - p_c2.getRed(), p_c1.getGreen() - p_c2.getGreen(), p_c1.getBlue() - p_c2.getBlue());
}

CColor operator/(CColor & p_c1, float p_multiple)
{
	return CColor(p_c1.getRed() / p_multiple, p_c1.getGreen() / p_multiple, p_c1.getBlue() / p_multiple);
}

bool operator==(CColor & p_c1, CColor & p_c2)
{
	if (p_c1.getRed() == p_c2.getRed() && p_c1.getGreen() == p_c2.getGreen() && p_c1.getBlue() == p_c2.getBlue())
		return true;
	else
		return false;
}

bool operator!=(CColor & p_c1, CColor & p_c2)
{
	if (p_c1.getRed() != p_c2.getRed() || p_c1.getGreen() != p_c2.getGreen() || p_c1.getBlue() != p_c2.getBlue())
		return true;
	else
		return false;
}
