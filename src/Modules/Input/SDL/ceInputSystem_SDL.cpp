#include <ceConfig.h>
#include "ceInputSystem_SDL.h"
#include "ceInputDevice_SDL.h"

ceIInputDevice* ceInputSystemSDL::GetDevice( void )
{
	if( !m_Device )
	{
		m_Device = new ceInputDeviceSDL( &m_Device );
	}
	else
	{
		m_Device->AddRef();
	}

	return m_Device;
}