//C++ Header
//API-Header
//Own Header
#include "InputHandler.h"

SINGLEON_CPP(game::InputHandler)
namespace game{
	InputHandler::InputHandler()
	{
		m_tastaturOnce.fill(false);
		m_tastatur.fill(false);
	}
}