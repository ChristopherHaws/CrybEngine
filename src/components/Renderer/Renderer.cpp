#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>

#include "Renderer/IRenderer.h"

#include <ceTypes.h>

class Renderer : public IRenderer
{
public:
				Renderer( void );
	virtual		~Renderer( void );

	bool		Initialize( UInt Width, UInt Height, bool Fullscreen );
	void		Release( void );
	bool		IsRunning( void );
	
	void		SetWindowCaption( const char *Caption, ... );

	void		StartRendering( bool ClearPixel, bool ClearDepth, bool ClearStencil );
	void		StopRendering( void );

private:
	SDL_Surface	*m_Screen;
	char		*m_Caption;
	bool		m_Running;
};

Renderer::Renderer( void )
{
	m_Screen = NULL;
	m_Caption = "CRYB Engine";
	m_Running = false;
}

Renderer::~Renderer( void )
{
	if( IsRunning() ) Release();
}

bool Renderer::Initialize( UInt Width, UInt Height, bool Fullscreen )
{
	if( IsRunning() ) 
	{
		// Instance of the window is already running.
		printf( "Instance of the window is already running.\n" );
		printf( "- Shutting it down and starting a new one.\n" );
		Release();
	}

	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		printf( "SDL_ERROR: %s\n", SDL_GetError() );
		return false;
	}

	Int flags = SDL_OPENGL | SDL_HWSURFACE | SDL_ANYFORMAT | SDL_DOUBLEBUF;
	if( Fullscreen ) flags |= SDL_FULLSCREEN;

	// Set the renderer attributes ( only 32bit curently supported )
	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 32 );	// Might not work on linux
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	m_Screen = SDL_SetVideoMode( Width, Height, 32, flags );
	if( m_Screen == NULL )
	{
		printf( "SDL_ERROR: %s\n", SDL_GetError() );
		return false;
	}

	glViewport( 0, 0, Width, Height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45.0f, (GLfloat)Width / (GLfloat)Height, 1.0f, 1024.0f );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	m_Running = true;

	return true;
}

void Renderer::Release( void )
{
	// Quit SDL
	SDL_Quit();

	m_Running = false;
}

bool Renderer::IsRunning( void )
{
	return m_Running;
}

void Renderer::SetWindowCaption( const char *Caption, ... )
{
	char buffer[256];

	va_list args;
	va_start( args, Caption );
	vsprintf( buffer, Caption, args );
	va_end( args );

	m_Caption = buffer;
	SDL_WM_SetCaption( buffer, NULL );
}

void Renderer::StartRendering( bool ClearPixel, bool ClearDepth, bool ClearStencil )
{
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

	Int flags = NULL;
	if( ClearPixel ) flags |= GL_COLOR_BUFFER_BIT;
	if( ClearDepth ) flags |= GL_DEPTH_BUFFER_BIT;
	if( ClearStencil ) flags |= GL_STENCIL_BUFFER_BIT;

	glClear( flags );
}

void Renderer::StopRendering( void )
{
	SDL_GL_SwapBuffers();
}