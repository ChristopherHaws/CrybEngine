#ifndef CE_KEYBOARD_DEVICE_SDL_H
#define CE_KEYBOARD_DEVICE_SDL_H

#include <ceConfig.h>
#include <Modules/Input/ceIInputDevice.h>
#include <Modules/Input/ceInputEnums.h>

#include <SDL/SDL.h>

class ceKeyboardDeviceSDL : public ceIKeyboardDevice
{
public:
			ceKeyboardDeviceSDL( void );
			~ceKeyboardDeviceSDL( void );

	bool	KeyPressed( CEKey key );	// Is this key pressed
	bool	KeyHeld( CEKey key );		// Is this key held down

	void	Update( SDL_Event *pEvent );

private:
	bool	m_bKeysPressed[CEK_LAST];
	bool	m_bKeysHeld[CEK_LAST];
};

#endif