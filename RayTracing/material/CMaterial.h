#ifndef _CMATERIAL_
#define _CMATERIAL_

#include "../core/CVec3d.h"
#include "CColor.h"

class CMaterial
{
protected:
	CColor	m_color;

	float	m_diffuseCoefficient;
	float	m_ambientCoefficient;
	float	m_specularCoefficient;
	float	m_shininess;				// specular exponent


public:
	CMaterial();
	CMaterial(CColor p_color, float p_diffuseCoefficient, float p_ambientCoefficient, float	p_specularCoefficient, float p_shininess);
	~CMaterial();

	CColor	getColor();
	void	setColor(CColor p_color);

	float	getDiffuseCoefficient();
	void	setDiffuseCoefficient(float p_diffuseCoefficient);
	float	getAmbientCoefficient();
	void	setAmbiantCoefficient(float p_ambientCoefficient);
	float	getSpecularCoefficient();
	void	setSpecularCoefficient(float p_specularCoefficient);
	float	getShininess();
	void	setShininess(float p_shininess);

};

#endif // !_CMATERIAL_