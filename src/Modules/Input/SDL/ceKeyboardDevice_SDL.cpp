#include <ceConfig.h>
#include "ceKeyboardDevice_SDL.h"

#include <SDL/SDL.h>

ceKeyboardDeviceSDL::ceKeyboardDeviceSDL( void )
{
	memset( m_bKeysPressed, 0, sizeof( m_bKeysPressed ) );
	memset( m_bKeysHeld, 0, sizeof( m_bKeysHeld ) );
}

ceKeyboardDeviceSDL::~ceKeyboardDeviceSDL( void )
{
}

bool ceKeyboardDeviceSDL::KeyPressed( CEKey key )
{
	if( m_bKeysPressed[key] == true )
	{
		m_bKeysPressed[key] = false;
		return true;
	}

	return false;
}

bool ceKeyboardDeviceSDL::KeyHeld( CEKey key )
{
	return m_bKeysHeld[key];
}

void ceKeyboardDeviceSDL::Update( SDL_Event *pEvent )
{
	if( pEvent->type == SDL_KEYDOWN )
	{
		m_bKeysPressed[pEvent->key.keysym.sym] = true;
		m_bKeysHeld[pEvent->key.keysym.sym] = true;
	}
	else if( pEvent->type == SDL_KEYUP )
	{
		m_bKeysPressed[pEvent->key.keysym.sym] = false;
		m_bKeysHeld[pEvent->key.keysym.sym] = false;
	}
}
