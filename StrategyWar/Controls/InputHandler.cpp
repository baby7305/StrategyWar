//C++ Header
//API-Header
//Own Header
#include "InputHandler.h"

namespace game{
	InputHandler::InputHandler()
		: m_mouseWheel(0.0f)
	{
		m_keys.fill(false);
		m_keysOnce.fill(false);
	}

	void InputHandler::keyEvent(const irr::SEvent::SKeyInput& e)
	{
		if (!m_keys[e.Key]) {
			m_keysOnce[e.Key] = e.PressedDown;
		}else{
			m_keysOnce[e.Key] = false;
		}

		m_keys[e.Key] = e.PressedDown;
	}

	void InputHandler::mouseEvent(const irr::SEvent::SMouseInput& e)
	{
		m_mousePos.X = e.X;
		m_mousePos.Y = e.Y;

		switch (e.Event)
		{
		case irr::EMOUSE_INPUT_EVENT::EMIE_LMOUSE_PRESSED_DOWN:
			m_keys[numKeyboardKeys + 1] = true;
			m_keysOnce[numKeyboardKeys + 1] = true;
			break;
		case irr::EMOUSE_INPUT_EVENT::EMIE_RMOUSE_PRESSED_DOWN:
			m_keys[numKeyboardKeys + 2] = true;
			m_keysOnce[numKeyboardKeys + 2] = true;
			break;
		case irr::EMOUSE_INPUT_EVENT::EMIE_MMOUSE_PRESSED_DOWN:
			m_keys[numKeyboardKeys + 3] = true;
			m_keysOnce[numKeyboardKeys + 3] = true;
			break;
		case irr::EMOUSE_INPUT_EVENT::EMIE_LMOUSE_LEFT_UP:
			m_keys[numKeyboardKeys + 1] = false;
			m_keysOnce[numKeyboardKeys + 1] = false;
			break;
		case irr::EMOUSE_INPUT_EVENT::EMIE_RMOUSE_LEFT_UP:
			m_keys[numKeyboardKeys + 2] = false;
			m_keysOnce[numKeyboardKeys + 2] = false;
			break;
		case irr::EMOUSE_INPUT_EVENT::EMIE_MMOUSE_LEFT_UP:
			m_keys[numKeyboardKeys + 3] = false;
			m_keysOnce[numKeyboardKeys + 3] = false;
			break;
		case irr::EMOUSE_INPUT_EVENT::EMIE_MOUSE_MOVED:
			break;
		case irr::EMOUSE_INPUT_EVENT::EMIE_MOUSE_WHEEL:
			m_mouseWheel = e.Wheel;
			break;
		default:
			break;
		}
	}

	bool InputHandler::isPressed(const irr::EKEY_CODE key) const
	{
		return m_keys[key];
	}

	bool InputHandler::isPressedOnce(const irr::EKEY_CODE key) const
	{
		return m_keysOnce[key];
	}

	bool InputHandler::isMousePressed(const MouseButton button) const
	{
		return m_keys[numKeyboardKeys + button + 1];
	}

	bool InputHandler::isMousePressedOnce(const MouseButton button) const
	{
		return m_keysOnce[numKeyboardKeys + button + 1];
	}

	irr::f32 InputHandler::getWheelStatus() const
	{
		return m_mouseWheel;
	}

	void InputHandler::frameFinished()
	{
		m_mouseWheel = 0.0f;
		m_keysOnce.fill(false);
	}
}