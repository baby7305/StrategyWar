//C++ Header
#include <iostream>
//API-Header
#include <irrlicht.h>
//Own Header
#include "Util\Singleton.h"
#include "Controls\EventHandler.h"
#include "Controls\InputHandler.h"
#include "Controls\MainCamera.h"
using namespace irr;

int main() {

	//Setup
	IrrlichtDevice *device = createDevice(video::EDT_DIRECT3D9, core::dimension2d<u32>(800, 600), 32, false/*fullscreen*/, false/*stencilBuffer*/, true/*vsync*/, game::EventHandler::getSingletonPtr());

	if (!device) {
		return EXIT_FAILURE;
	}

	//get important pointer
	device->setWindowCaption(L"StrategyWar: WW1");
	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();
	gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
	
	//create Camera
	game::MainCamera camera(smgr);

	//testing
	guienv->addStaticText(L"Hello World! Test Text!", core::rect<s32>(10, 10, 260, 22), true);
	scene::IAnimatedMesh* mesh = smgr->getMesh("res/irr/sydney.md2");
	if (!mesh)
	{
		device->drop();
		return 1;
	}

	scene::IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);

	if (node)
	{
		node->setMaterialFlag(video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_STAND);
		node->setMaterialTexture(0, driver->getTexture("res/irr/sydney.bmp"));
	}

	while (device->run())
	{
		//rendering
		driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();

		//show FPS
		//if((device->getTimer()->getTime() % 60) < 8)
			//std::cout << "FPS: " << driver->getFPS() << '\n';

		//signal InputHandler the frame is finished
		game::InputHandler::getSingletonPtr()->frameFinished();
	}

	device->drop();
	return EXIT_SUCCESS;
}
