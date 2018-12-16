#include <ceConfig.h>
#include <Modules/Renderer/ceIRenderSystem.h>
#include "ceRenderSystem_OGL.h"

extern "C" 
{
	EXPORTS void CreateSystem( ceIRenderSystem ** );
	typedef void ( *CREATESYSTEM )( ceIRenderSystem** );
	EXPORTS void ReleaseSystem( ceIRenderSystem ** );
	typedef void ( *RELEASESYSTEM )( ceIRenderSystem** );
}

void CreateSystem( ceIRenderSystem** ppSys )
{
	if( *ppSys == NULL )
	{
		*ppSys = new ceRenderSystemOGL();
	}
}

void ReleaseSystem( ceIRenderSystem** ppSys )
{
	if( *ppSys != NULL )
	{
		delete *ppSys;
	}

	*ppSys = NULL;
}