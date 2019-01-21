#include "CMaterial.h"

CMaterial::CMaterial()
{
}

CMaterial::CMaterial(CColor p_color, float p_diffuseCoefficient, float p_ambientCoefficient, float	p_specularCoefficient, float p_shininess)
{
	m_color = p_color;

	m_diffuseCoefficient = p_diffuseCoefficient;
	m_ambientCoefficient = p_ambientCoefficient;
	m_specularCoefficient = p_specularCoefficient;
	m_shininess = p_shininess;
}

CMaterial::~CMaterial()
{
}

CColor CMaterial::getColor()
{
	return m_color;
}

void CMaterial::setColor(CColor p_color)
{
	m_color = p_color;
}

float CMaterial::getDiffuseCoefficient()
{
	return m_diffuseCoefficient;
}

void CMaterial::setDiffuseCoefficient(float p_diffuseCoefficient)
{
	m_diffuseCoefficient = p_diffuseCoefficient;
}

float CMaterial::getAmbientCoefficient()
{
	return m_ambientCoefficient;
}

void CMaterial::setAmbiantCoefficient(float p_ambientCoefficient)
{
	m_ambientCoefficient = p_ambientCoefficient;
}

float CMaterial::getSpecularCoefficient()
{
	return m_specularCoefficient;
}

void CMaterial::setSpecularCoefficient(float p_specularCoefficient)
{
	m_specularCoefficient = p_specularCoefficient;
}

float CMaterial::getShininess()
{
	return m_shininess;
}

void CMaterial::setShininess(float p_shininess)
{
	m_shininess = p_shininess;
}
