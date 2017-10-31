//C++ Header
#include <iostream>
//API-Header
//Own Header
#include "InputHandler.h"

//SINGLEON_CPP(game::InputHandler)
namespace game{
	InputHandler::InputHandler()
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

		std::cout << e.Key << '\n';
	}

	void InputHandler::mouseEvent(const irr::SEvent::SMouseInput& e)
	{
		mousePos.X = e.X;
		mousePos.Y = e.Y;

		switch (e.Event)
		{
		case irr::EMOUSE_INPUT_EVENT::EMIE_LMOUSE_PRESSED_DOWN:
			if (!m_keys[numKeyboardKeys + 1]) {
				m_keysOnce[numKeyboardKeys + 1] = true;
			}else{
				m_keysOnce[numKeyboardKeys + 1] = false;
			}
			m_keys[numKeyboardKeys + 1] = true;
			break;
		case irr::EMOUSE_INPUT_EVENT::EMIE_RMOUSE_PRESSED_DOWN:
			if (!m_keys[numKeyboardKeys + 2]) {
				m_keysOnce[numKeyboardKeys + 2] = true;
			}
			else {
				m_keysOnce[numKeyboardKeys + 2] = false;
			}
			m_keys[numKeyboardKeys + 2] = true;
			break;
		case irr::EMOUSE_INPUT_EVENT::EMIE_MMOUSE_PRESSED_DOWN:
			if (!m_keys[numKeyboardKeys + 3]) {
				m_keysOnce[numKeyboardKeys + 3] = true;
			}
			else {
				m_keysOnce[numKeyboardKeys + 3] = false;
			}
			m_keys[numKeyboardKeys + 3] = true;
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
}