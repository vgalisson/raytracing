#ifndef _CCOLOR_
#define _CCOLOR_

class CColor
{
protected:
	float	m_red, m_green, m_blue;

public:
	CColor();
	CColor(float p_red, float p_green, float p_blue);
	~CColor();

	float	getRed();
	void	setRed(float p_red);
	float	getGreen();
	void	setGreen(float p_green);
	float	getBlue();
	void	setBlue(float p_blue);
	void	normalizeColor();
};

CColor	operator* (CColor& p_c1, CColor& p_c2);
CColor	operator* (CColor& p_c1, float p_multiple);
CColor	operator+ (CColor& p_c1, CColor& p_c2);
CColor	operator- (CColor& p_c1, CColor& p_c2);
CColor	operator/ (CColor& p_c1, float p_multiple);
bool	operator== (CColor& p_c1, CColor& p_c2);
bool	operator!= (CColor& p_c1, CColor& p_c2);

#endif // !_CCOLOR_