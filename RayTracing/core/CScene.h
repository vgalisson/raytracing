#ifndef _CSCENE_
#define _CSCENE_

#include "../../FreeImage/FreeImage.h"
#include "../object/CObject.h"
#include "CLight.h"
#include "CCamera.h"
#include "../material/CColor.h"
#include <vector>

class CScene
{
protected :
	CCamera *					m_camera;
	std::vector<CObject*>		m_objects;
	std::vector<CLight*>		m_lights;

public:
	CScene();
	~CScene();

	CObject *		getObject(int p_index);
	CLight *		getLight(int p_index);

	void			setCamera(CCamera * p_camera);
	void			addObject(CObject * p_object);
	void			addLight(CLight * p_light);

	CColor			raytrace(CRay & p_ray);
	void			render();
};

#endif // !_CSCENE_