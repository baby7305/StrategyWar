#pragma once
//C++ Header
#include <array>
//API-Header
#include <Irrlicht.h>
//Own Header
#include "../Util/Singleton.h"

namespace game{
	constexpr size_t keyCount = 1 + irr::EKEY_CODE::KEY_KEY_CODES_COUNT + 3; //3 mouse buttons
	constexpr size_t numKeyboardKeys = irr::EKEY_CODE::KEY_KEY_CODES_COUNT;

	class InputHandler : public Util::Singleton<InputHandler>
	{
		SINGLETON_SPECIAL_CONSTRUCTOR(InputHandler)
	public:

		void keyEvent(const irr::SEvent::SKeyInput& e);
		void mouseEvent(const irr::SEvent::SMouseInput& e);

		bool isPressed(const irr::EKEY_CODE key) const;
		bool isPressedOnce(const irr::EKEY_CODE key) const;
	private:
		std::array<bool, keyCount> m_keys;
		std::array<bool, keyCount> m_keysOnce;
		irr::core::vector2d<irr::s32> mousePos;
	};
}