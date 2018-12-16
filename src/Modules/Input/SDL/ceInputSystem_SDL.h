#ifndef CE_INPUT_SYSTEM_SDL_H
#define CE_INPUT_SYSTEM_SDL_H

#include <ceConfig.h>
#include <Modules/Input/ceIInputSystem.h>

#include "ceInputDevice_SDL.h"

class ceInputSystemSDL : public ceIInputSystem
{
public:
					ceInputSystemSDL( void ) : m_Device( 0 ) {}
	virtual			~ceInputSystemSDL( void ) {}

	/// Get the input device. If no device exists, a default one is created.
	virtual ceIInputDevice*		GetDevice( void );

private:
	ceInputDeviceSDL*	m_Device;
};

#endif