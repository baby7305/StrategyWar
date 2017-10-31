#pragma once
//C++ Header
//API-Header
#include <Irrlicht.h>
//Own Header
#include "../Util/Singleton.h"

namespace game {
	class EventHandler : public irr::IEventReceiver, public Util::Singleton<EventHandler>
	{
		SINGLETON_HPP(EventHandler)
	public:
		virtual bool OnEvent(const irr::SEvent& event) override;
	};
}
