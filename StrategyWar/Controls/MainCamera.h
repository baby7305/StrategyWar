#pragma once
//C++ Header
//API-Header
#include <irrlicht.h>
//Own Header

namespace game{

	class MainCamera
	{
	public:
		MainCamera(irr::scene::ISceneManager* smgr);
		~MainCamera();

		irr::scene::ICameraSceneNode* getNode() { return m_camNode; };
	private:
		irr::scene::ICameraSceneNode* m_camNode;
	};

	class MainCameraAnimator : public irr::scene::ISceneNodeAnimator
	{
	public:
		MainCameraAnimator(MainCamera* camera);
		virtual ~MainCameraAnimator();

		//zu implementierende Methoden
		virtual void animateNode(irr::scene::ISceneNode* node, irr::u32 timeMs);
		virtual irr::scene::ISceneNodeAnimator* createClone(irr::scene::ISceneNode* node, irr::scene::ISceneManager* newManager = nullptr);
	private:
		MainCamera* m_camera;
		irr::core::vector2di m_oldMousePos;
		irr::u32 m_lastTime;
	};
}