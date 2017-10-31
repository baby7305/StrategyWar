#pragma once
//C++ Header
#include <array>
//API-Header
#include <Irrlicht.h>
//Own Header
#include "../Util/Singleton.h"

namespace game{
	class InputHandler : public Util::Singleton<InputHandler>
	{
	public:
		InputHandler();

		void keyEvent(const irr::SEvent::SKeyInput e);

		bool isPressed(const irr::EKEY_CODE key) const;
		bool isPressedOnce(const irr::EKEY_CODE key) const;
	private:
		std::array<bool, irr::EKEY_CODE::KEY_KEY_CODES_COUNT> m_tastatur;
		std::array<bool, irr::EKEY_CODE::KEY_KEY_CODES_COUNT> m_tastaturOnce;
	};
}