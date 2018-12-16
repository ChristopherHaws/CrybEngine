#ifndef CE_INPUT_DEVICE_SDL_H
#define CE_INPUT_DEVICE_SDL_H

#include <ceConfig.h>
#include <Modules/Input/ceIInputDevice.h>
#include <SDL/SDL.h>

#include "ceKeyboardDevice_SDL.h"
#include "ceMouseDevice_SDL.h"

class ceInputDeviceSDL : public ceIInputDevice
{
public:
						ceInputDeviceSDL( ceInputDeviceSDL** pDevice );
	virtual				~ceInputDeviceSDL( void );

	void				AddRef( void );
	void				Release( void );

	/// Updates the input
	bool				Update( void );

	/// Get the keyboard's device
	ceIKeyboardDevice*	GetKeyboardDevice( void );

	/// Get the mouse's device
	ceIMouseDevice*		GetMouseDevice( void );

private:
	ceKeyboardDeviceSDL*	m_pKeyboardDevice;
	ceMouseDeviceSDL*		m_pMouseDevice;
	ceInputDeviceSDL**		m_pDevice;
	ceUInt					m_uiRefCounter;
};

#endif