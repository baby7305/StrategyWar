#pragma once
//C++ Header
#include <array>
//API-Header
#include <Irrlicht.h>
//Own Header
#include "../Util/Singleton.h"

namespace game{

	//Used to get pressed button on mouse
	enum MouseButton {
		LEFT_MOUSE_BUTTON,
		RIGHT_MOUSE_BUTTON,
		MIDDLE_MOUSE_BUTTON,
		NUM_MOUSE_BUTTONS //Not in use
	};

	constexpr size_t keyCount = 1 + irr::EKEY_CODE::KEY_KEY_CODES_COUNT + MouseButton::NUM_MOUSE_BUTTONS; //size of key array
	constexpr size_t numKeyboardKeys = irr::EKEY_CODE::KEY_KEY_CODES_COUNT;

	class InputHandler : public Util::Singleton<InputHandler>
	{
		SINGLETON_SPECIAL_CONSTRUCTOR(InputHandler)
	public:
		//Updateing the input values
		void keyEvent(const irr::SEvent::SKeyInput& e);
		void mouseEvent(const irr::SEvent::SMouseInput& e);

		//getting the state of the key
		bool isPressed(const irr::EKEY_CODE key) const;
		bool isPressedOnce(const irr::EKEY_CODE key) const;

		//getting the state of a mouse button
		bool isMousePressed(const MouseButton button) const;
		bool isMousePressedOnce(const MouseButton button) const;

		//getting the mouseWheel status
		//  0:				no change
		//  positiv value:	scrolling up
		//  negative value: scrolling down
		irr::f32 getWheelStatus() const;

		//Call after rendering the frame
		void frameFinished();
	private:
		std::array<bool, keyCount> m_keys; //True if key is pressed
		std::array<bool, keyCount> m_keysOnce; //True if this is the first frame, the key is pressed
		irr::core::vector2d<irr::s32> m_mousePos; //Mous epos on screen
		irr::f32 m_mouseWheel; //Mouse wheel delta
	};
}