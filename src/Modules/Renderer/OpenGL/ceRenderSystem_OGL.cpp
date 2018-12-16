#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "ceRenderSystem_OGL.h"
#include "ceRenderDevice_OGL.h"

ceIRenderDevice* ceRenderSystemOGL::CreateDevice( void )
{
	ceIRenderDevice* pDevice = new ceRenderDeviceOGL();

	if( !pDevice ) CE_EXCEPTION( ceString(__FUNCTION__) + ": Couldn't create RenderDevice!\n", CE_HARDERROR );

	m_Devices.push_back( pDevice );

	return pDevice;
}

void ceRenderSystemOGL::RemoveDevice( ceIRenderDevice* pDevice )
{
	CE_ASSERT( pDevice != NULL );

	for( ceUInt i = 0; i < m_Devices.size(); i++ )
	{
		if( m_Devices[i] == pDevice )
		{
			pDevice = NULL;
			delete m_Devices[i];
			return;
		}
	}
}

void ceRenderSystemOGL::RemoveAllDevices( void )
{
	for( ceUInt i = 0; i < m_Devices.size(); i++ )
	{
		delete m_Devices[i];
	}

	m_Devices.clear();
}
