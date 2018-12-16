#include <ceConfig.h>
#include "ceInputSystem_SDL.h"

extern "C" EXPORTS void CreateSystem( ceIInputSystem** ppSys )
{
	if( *ppSys == NULL )
	{
		if( ( *ppSys = new ceInputSystemSDL() ) == NULL )
		{
			CE_EXCEPTION( (ceString)"CreateSystem( ceInputSystemSDL ) failes!", CE_ERROR );
		}
	}
}

extern "C" EXPORTS void ReleaseSystem( ceIInputSystem** ppSys )
{
	if( *ppSys != NULL )
	{
		delete *ppSys;
	}

	*ppSys = NULL;
}