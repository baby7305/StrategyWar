//C++ Header
//API-Header
//Own Header
#include "EventHandler.h"
#include "InputHandler.h"

namespace game{

	bool EventHandler::OnEvent(const irr::SEvent& event)
	{
		switch (event.EventType)
		{
		case irr::EEVENT_TYPE::EET_GUI_EVENT:
			break;
		case irr::EEVENT_TYPE::EET_JOYSTICK_INPUT_EVENT:
			break;
		case irr::EEVENT_TYPE::EET_KEY_INPUT_EVENT:
			InputHandler::getSingletonPtr()->keyEvent(event.KeyInput);
			break;
		case irr::EEVENT_TYPE::EET_LOG_TEXT_EVENT:
			break;
		case irr::EEVENT_TYPE::EET_MOUSE_INPUT_EVENT:
			InputHandler::getSingletonPtr()->mouseEvent(event.MouseInput);
			break;
		case irr::EEVENT_TYPE::EET_USER_EVENT:
			break;
		default:
			break;
		}
	
		return false;
	}

}