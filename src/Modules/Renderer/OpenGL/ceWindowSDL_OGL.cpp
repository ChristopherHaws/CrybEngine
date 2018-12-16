#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "ceWindowSDL_OGL.h"
#include <Modules/Renderer/ceIWindow.h>
#include <Modules/Renderer/ceWindowProperties.h>

ceWindowSDL::ceWindowSDL( void )
{
	static bool SDLInitialized = false;

	if( !SDLInitialized )
	{
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		{
			ceString error = "";
			error += "SDL failed to initialize!\n";
			error += "  SDL Error: ";
			error += SDL_GetError();
			error += "\n";
			CE_EXCEPTION( error, CE_HARDERROR );
		}

		SDLInitialized = true;
	}

	m_pSurface = NULL;
}

ceWindowSDL::~ceWindowSDL( void )
{
	if( m_pSurface != NULL ) SDL_FreeSurface( m_pSurface );
	m_pSurface = NULL;
}

void ceWindowSDL::Create( ceWindowProperties *pWinProperties )
{
	memcpy( &m_WindowProperties, pWinProperties, sizeof( ceWindowProperties ) );

	ceUInt uiBPP = pWinProperties->m_uiColorBuffer;
	switch( uiBPP )
	{
		default:
		case 16:
			SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
			SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
			SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
			break;
		case 32:
			SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
			SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
			SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
			break;
	}

	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, pWinProperties->m_uiDepthBuffer );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	if( pWinProperties->m_bAntiAliasing )
	{
		SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS, 1 );
		SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES, 1 );
	}

	ceUInt uiFlags = 0;
	uiFlags |= SDL_OPENGL;

	if( pWinProperties->m_bFullscreen ) uiFlags |= SDL_FULLSCREEN;

	uiFlags |= SDL_GL_DOUBLEBUFFER;
	uiFlags |= SDL_RESIZABLE;

	m_pSurface = SDL_SetVideoMode( pWinProperties->m_uiWidth, pWinProperties->m_uiHeight, uiBPP, uiFlags);

	if( pWinProperties->m_bAntiAliasing )
		glEnable( GL_MULTISAMPLE_ARB );

	if( m_pSurface == NULL )
	{
		ceString error = "";
		error += "SDL failed to create surface!\n";
		error += "  SDL Error: ";
		error += SDL_GetError();
		error += "\n";
		CE_EXCEPTION( error, CE_HARDERROR );
	}
}

void ceWindowSDL::Release( void )
{
	if( m_pSurface != NULL ) SDL_FreeSurface( m_pSurface );
	m_pSurface = NULL;
}

void ceWindowSDL::Update( void )
{
	SDL_GL_SwapBuffers();
}

void ceWindowSDL::SetTitle( ceString title )
{
	SDL_WM_SetCaption( title.c_str(), NULL );
	m_WindowProperties.m_sTitle = title;
}
