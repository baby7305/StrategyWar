//C++ Header
//API-Header
//Own Header
#include "EventHandler.h"

SINGLEON_CPP(game::EventHandler)
namespace game{

EventHandler::EventHandler()
{

}

EventHandler::~EventHandler()
{

}

bool EventHandler::onEvent(const irr::SEvent& event)
{
	switch (event.EventType)
	{
	case irr::EEVENT_TYPE::EET_GUI_EVENT:
		break;
	case irr::EEVENT_TYPE::EET_JOYSTICK_INPUT_EVENT:
		break;
	case irr::EEVENT_TYPE::EET_KEY_INPUT_EVENT:
		break;
	case irr::EEVENT_TYPE::EET_LOG_TEXT_EVENT:
		break;
	case irr::EEVENT_TYPE::EET_MOUSE_INPUT_EVENT:
		break;
	case irr::EEVENT_TYPE::EET_USER_EVENT:
		break;
	default:
		break;
	}

	return false;
}

}