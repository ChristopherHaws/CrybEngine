#include <SDL/SDL.h>
#include <ceConfig.h>
#include "ceInputDevice_SDL.h"

ceInputDeviceSDL::ceInputDeviceSDL( ceInputDeviceSDL** pDevice )
{
	m_pDevice = pDevice;
	m_uiRefCounter = 1;

	if( SDL_WasInit( SDL_INIT_EVERYTHING ) == 0 )
	{
		SDL_Init( SDL_INIT_EVERYTHING );
	}

	if( SDL_WasInit( SDL_INIT_EVENTTHREAD ) == 0 )
	{
		SDL_InitSubSystem( SDL_INIT_EVENTTHREAD );
	}

	m_pKeyboardDevice = new ceKeyboardDeviceSDL();
	m_pMouseDevice = new ceMouseDeviceSDL();

	//SDL_EnableUNICODE( SDL_ENABLE );
}

ceInputDeviceSDL::~ceInputDeviceSDL( void )
{
}

void ceInputDeviceSDL::AddRef( void )
{
	m_uiRefCounter++;
}

void ceInputDeviceSDL::Release( void )
{
	if( --m_uiRefCounter == 0 )
	{
		*m_pDevice = NULL;
		delete this;
	}
}

bool ceInputDeviceSDL::Update( void )
{
	bool bReturnValue = true;
	SDL_Event pEvent;

	while( SDL_PollEvent( &pEvent ) )
	{
		m_pKeyboardDevice->Update( &pEvent );
		m_pMouseDevice->Update( &pEvent );

		if( pEvent.type == SDL_QUIT )
		{
			bReturnValue = false;
		}
	}

	return bReturnValue;
}

ceIKeyboardDevice* ceInputDeviceSDL::GetKeyboardDevice( void )
{
	return (ceIKeyboardDevice*)m_pKeyboardDevice;
}

ceIMouseDevice* ceInputDeviceSDL::GetMouseDevice( void )
{
	return (ceIMouseDevice*)m_pMouseDevice;
}
