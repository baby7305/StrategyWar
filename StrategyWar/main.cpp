#include <irrlicht.h>
#include "Util\Singleton.h"
using namespace irr;

int main() {

	IrrlichtDevice *device = createDevice(video::EDT_DIRECT3D9, core::dimension2d<u32>(640, 480), 32, false, false, true, nullptr);

	if (!device)
		return 1;

	device->setWindowCaption(L"StrategyWar: WW1");
	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();
	gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!", core::rect<s32>(10, 10, 260, 22), true);
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

	smgr->addCameraSceneNode(0, core::vector3df(0, 30, -40), core::vector3df(0, 5, 0));

	while (device->run())
	{
		driver->beginScene(true, true, video::SColor(255, 100, 101, 140));

		smgr->drawAll();
		guienv->drawAll();

		driver->endScene();
	}

	device->drop();
	return 0;
}