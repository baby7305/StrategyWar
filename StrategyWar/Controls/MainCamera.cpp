//C++ Header
#include <iostream>
//API-Header
//Own Header
#include "MainCamera.h"
#include "InputHandler.h"

namespace game{

	MainCamera::MainCamera(irr::scene::ISceneManager* smgr){
		m_camNode = smgr->addCameraSceneNode(nullptr, irr::core::vector3df(0, 30, -40), irr::core::vector3df(0, -30, 100));

		auto target = m_camNode->getTarget();
		m_camNode->setTarget(target.normalize());

		auto anim = new MainCameraAnimator(this);
		m_camNode->bindTargetAndRotation(true);
		m_camNode->addAnimator(anim);
		anim->drop();
	}
	
	MainCamera::~MainCamera(){
		//needed??
	}

	/*
	MainCameraAnimator funtion definitions
	*/
	
	MainCameraAnimator::MainCameraAnimator(MainCamera* camera)
		: m_camera(camera), m_lastTime(0)
	{
		m_oldMousePos = InputHandler::getSingletonPtr()->getMousePos();
	}

	MainCameraAnimator::~MainCameraAnimator()
	{
		//needed??
	}

	void MainCameraAnimator::animateNode(irr::scene::ISceneNode* node, irr::u32 timeMs){
		irr::u32 frameTime = timeMs - m_lastTime;
		constexpr float moveSpeed = 0.5f;
		
		auto& input = InputHandler::getSingleton();
		auto& pos = m_camera->getNode()->getAbsolutePosition();
		auto& lookAt = m_camera->getNode()->getTarget();
		auto lookAtRel = (lookAt - pos).normalize();

		//Movment forward backward
		if (input.isPressed(irr::EKEY_CODE::KEY_KEY_W)) {
			irr::core::vector3df add(lookAtRel.X, 0.0f, lookAtRel.Z);
			add = add.normalize() * static_cast<irr::f32>(frameTime) / 1000.0f * moveSpeed;
			m_camera->getNode()->setPosition(pos + add);
			m_camera->getNode()->setTarget(lookAt + add);

			m_camera->getNode()->updateAbsolutePosition();
		}
		else if (input.isPressed(irr::EKEY_CODE::KEY_KEY_S)) {
			irr::core::vector3df add(lookAtRel.X, 0.0f, lookAtRel.Z);
			add = add.normalize() * static_cast<irr::f32>(frameTime) / 1000.0f * moveSpeed;
			m_camera->getNode()->setPosition(pos - add);
			m_camera->getNode()->setTarget(lookAt - add);

			m_camera->getNode()->updateAbsolutePosition();
		}

		//side movement
		if(input.isPressed(irr::EKEY_CODE::KEY_KEY_A)) {
			float height = pos.Y;
			auto cross = lookAtRel.crossProduct(irr::core::vector3df(0.0f, 1.0f, 0.0f));
			auto add = cross.normalize() * static_cast<irr::f32>(frameTime) / 1000.0f * moveSpeed;
			m_camera->getNode()->setPosition(pos + add);
			m_camera->getNode()->setTarget(lookAt + add);

			m_camera->getNode()->updateAbsolutePosition();
		}
		else if(input.isPressed(irr::EKEY_CODE::KEY_KEY_D)) {
			float height = pos.Y;
			auto cross = lookAtRel.crossProduct(irr::core::vector3df(0.0f, 1.0f, 0.0f));
			auto add = cross.normalize() * static_cast<irr::f32>(frameTime) / 1000.0f * moveSpeed;
			m_camera->getNode()->setPosition(pos - add);
			m_camera->getNode()->setTarget(lookAt - add);

			m_camera->getNode()->updateAbsolutePosition();
		}

		//Rotation
		if (input.isMousePressed(game::MouseButton::MIDDLE_MOUSE_BUTTON)) {
			auto diff2D = input.getMousePos() - m_oldMousePos;
			auto rotation = m_camera->getNode()->getAbsolutePosition();

			
			if (diff2D.X != 0.0f) {
				float angle = static_cast<irr::f32>(frameTime) / 1000.0f * 10.0f;
				angle *= (diff2D.X < 0.0f) ? -1.0f : 1.0f;
				std::cout << angle << '\n';
				irr::core::vector3df add = irr::core::vector3df(0.0f, 1.0f, 0.0f) * angle;
				m_camera->getNode()->setTarget((lookAt + add).normalize());
			}
			
			m_camera->getNode()->setRotation(irr::core::vector3df(0.0f, 1.0f, 0.0f));
		}

		m_oldMousePos = input.getMousePos();
		m_lastTime = timeMs;
	}

	irr::scene::ISceneNodeAnimator* MainCameraAnimator::createClone(irr::scene::ISceneNode * node, irr::scene::ISceneManager * newManager)
	{
		auto newAnimator = new MainCameraAnimator(m_camera);
		return newAnimator;
	}

}