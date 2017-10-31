#pragma once
//C++ Header
//API-Header
#include <Irrlicht.h>
//Own Header
#include "../Util/Singleton.h"

namespace game {
	class EventHandler : public irr::IEventReceiver, Util::Singleton<EventHandler>
	{
	public:
		EventHandler();
		~EventHandler();
		virtual bool onEvent(const irr::SEvent& event);
	};
}
