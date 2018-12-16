#include <ceConfig.h>
#include "ceMouseDevice_SDL.h"

#include <SDL/SDL.h>

ceMouseDeviceSDL::ceMouseDeviceSDL( void )
{
	memset( m_bButtonsPressed, 0, sizeof( m_bButtonsPressed ) );
	memset( m_bButtonsHeld, 0, sizeof( m_bButtonsHeld ) );
}

ceMouseDeviceSDL::~ceMouseDeviceSDL( void )
{
}

ceInt ceMouseDeviceSDL::GetPositionX( void )
{
	return m_uiPosX;
}

ceInt ceMouseDeviceSDL::GetPositionY( void )
{
	return m_uiPosY;
}

ceInt ceMouseDeviceSDL::GetRelativeX( void )
{
	return m_uiRelX;
}

ceInt ceMouseDeviceSDL::GetRelativeY( void )
{
	return m_uiRelY;
}

void ceMouseDeviceSDL::SetPosition( ceUInt x, ceUInt y )
{
	m_uiPosX = x;
	m_uiPosY = y;
	SDL_WarpMouse( x, y );
}

bool ceMouseDeviceSDL::ButtonPressed( ceUInt8 button )
{
	if( m_bButtonsPressed[button] == true )
	{
		m_bButtonsPressed[button] = false;
		return true;
	}

	return false;
}

bool ceMouseDeviceSDL::ButtonHeld( ceUInt8 button )
{
	return m_bButtonsHeld[button];
}

void ceMouseDeviceSDL::Update( SDL_Event *pEvent )
{
	if( pEvent->type == SDL_MOUSEBUTTONDOWN )
	{
		m_bButtonsPressed[pEvent->button.button] = true;
		m_bButtonsHeld[pEvent->button.button] = true;
		
		m_uiPosX = pEvent->button.x;
		m_uiPosY = pEvent->button.y;
	}
	else if( pEvent->type == SDL_MOUSEBUTTONUP )
	{
		m_bButtonsPressed[pEvent->button.button] = false;
		m_bButtonsHeld[pEvent->button.button] = false;
		
		m_uiPosX = pEvent->button.x;
		m_uiPosY = pEvent->button.y;
	}
	else if( pEvent->type == SDL_MOUSEMOTION )
	{
		m_uiPosX = pEvent->motion.x;
		m_uiPosY = pEvent->motion.y;
	}
}