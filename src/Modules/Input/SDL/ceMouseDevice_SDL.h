#ifndef CE_MOUSE_DEVICE_SDL_H
#define CE_MOUSE_DEVICE_SDL_H

#include <ceConfig.h>
#include <Modules/Input/ceIInputDevice.h>

#include <SDL/SDL.h>

class ceMouseDeviceSDL : public ceIMouseDevice
{
public:
			ceMouseDeviceSDL( void );
			~ceMouseDeviceSDL( void );

	ceInt		GetPositionX( void );	// X-Position of the mouse
	ceInt		GetPositionY( void );	// Y-Position of the mouse
	ceInt		GetRelativeX( void );	// X-Relative Position of the mouse
	ceInt		GetRelativeY( void );	// Y-Relative Position of the mouse

	void	SetPosition( ceUInt x, ceUInt y );	// Set the position of the mouse cursor

	bool	ButtonPressed( ceUInt8 button );	// Is this button pressed
	bool	ButtonHeld( ceUInt8 button );		// Is this button held down

	void	Update( SDL_Event *pEvent );

private:
	bool	m_bButtonsPressed[8];
	bool	m_bButtonsHeld[8];

	ceUInt16	m_uiPosX;
	ceUInt16	m_uiPosY;
	ceUInt16	m_uiRelX;
	ceUInt16	m_uiRelY;
};

#endif