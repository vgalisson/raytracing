#include "../FreeImage/FreeImage.h"
#include "../SDL2-2.0.3/SDL2.h"

#include <iostream>

#include "./core/CVec3d.h"
#include "./object/CObject.h"
#include "./object/CSphere.h"
#include "./object/CPlane.h"
#include "./object/CTriangle.h"
#include "./core/CLight.h"
#include "./core/CRay.h"
#include "./core/CCamera.h"
#include "./core/CScene.h"

int main(int argc, char ** argv)
{
	CScene		myScene;

	CCamera *	myCamera			= NULL;
	CVec3d		cameraOrigin		= CVec3d(0, 5, -10);
	CVec3d		cameraViewDir		= CVec3d(0, 0, 1);
	CVec3d		cameraUpVec			= CVec3d(0, 1, 0);
	float		cameraViewHeight	= 0.35f;
	float		cameraViewWidth		= 0.5f;
	float		cameraFocal			= 1.0f;
	int			xRes				= 640;
	int			yRes				= 480;

	// OBJECTS

	CPlane *	plan				= NULL;
	CVec3d		planPos				= CVec3d(0, 0, 0);		// when on same height as the camera, NOT WORKING PROPERLY
	CVec3d		planNormal			= CVec3d(0, 1, 0);

	CPlane *	plan2				= NULL;
	CVec3d		plan2Pos			= CVec3d(-6, 0, 0);		
	CVec3d		plan2Normal			= CVec3d(1, 0, 0);

	CSphere *	sphere				= NULL;
	CVec3d		spherePos			= CVec3d(6, 7, 20);
	int			sphereRadius		= 2;

	CSphere *	sphere2				= NULL;
	CVec3d		sphere2Pos			= CVec3d(-1, 5, 30);
	int			sphere2Radius		= 1;

	CSphere *	sphere3				= NULL;
	CVec3d		sphere3Pos			= CVec3d(-5, 1, 30);
	int			sphere3Radius		= 2;

	CTriangle * triangle			= NULL;
	CVec3d		point1				= CVec3d(9, 8, 50);
	CVec3d		point2				= CVec3d(6, 1, 30);
	CVec3d		point3				= CVec3d(2, 1, 30);

	// LIGHTS

	CLight *	light				= NULL;
	CVec3d		lightPos			= CVec3d(10, 12, 20);
	CColor		lightColor			= CColor(1.0f, 1.0f, 1.0f);

	CLight *	light2				= NULL;
	CVec3d		light2Pos			= CVec3d(-5, 20, 25);
	CColor		light2Color			= CColor(1.0f, 1.0f, 1.0f);

	// MATERIALS

	CMaterial *	material			= NULL;
	CColor		color1				= CColor(0.25f, 0.6f, 1.0f);

	CMaterial *	material2			= NULL;
	CColor		color2				= CColor(1.0f, 0.5f, 0.05f);

	// ------- creating the objects ----------------
	myCamera	= new CCamera(cameraOrigin, cameraViewDir, cameraUpVec, cameraViewHeight, cameraViewWidth, cameraFocal, xRes, yRes);

	light		= new CLight(lightPos, lightColor);
	light2		= new CLight(light2Pos, light2Color);

	plan		= new CPlane(planPos, planNormal);
	plan2		= new CPlane(plan2Pos, plan2Normal);
	sphere		= new CSphere(spherePos, sphereRadius);
	sphere2		= new CSphere(sphere2Pos, sphere2Radius);
	sphere3		= new CSphere(sphere3Pos, sphere3Radius);
	triangle	= new CTriangle(point1, point2, point3);

	material	= new CMaterial(color1, 1.0f, 0.15f, 0.15f, 1.0f);
	material2	= new CMaterial(color2, 1.0f, 0.15f, 1.0f, 100.0f);

	// ------ setting the materials ---------------
	plan->setMaterial(*material);
	plan2->setMaterial(*material);
	sphere2->setMaterial(*material2);
	sphere3->setMaterial(*material2);
	triangle->setMaterial(*material2);
	
	// ------ adding the objects ------------------
	myScene.addObject(plan);
	myScene.addObject(plan2);
	//myScene.addObject(sphere);
	myScene.addObject(sphere2);
	myScene.addObject(sphere3);
	myScene.addObject(triangle);

	myScene.setCamera(myCamera);
	myScene.addLight(light);
	myScene.addLight(light2);


	// -------- Image calculation ------------------
	myScene.render();

	// -------- SDL display ------------------------

	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image",	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, xRes, yRes, 0);

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = SDL_LoadBMP("img.bmp");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}