#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "ceRenderDevice_OGL.h"
#include "ceWindowSDL_OGL.h"

void ceRenderDeviceOGL::Create( void )
{
	m_pWindow = NULL;
}

void ceRenderDeviceOGL::Release( void )
{
	delete m_pWindow;
	m_pWindow = NULL;
}

void ceRenderDeviceOGL::Reset( void )
{
	Release();
	Create();
}

ceIWindow* ceRenderDeviceOGL::CreateNewWindow( ceWindowProperties* pWinProperties )
{
	m_pWindow = new ceWindowSDL();

	m_pWindow->Create( pWinProperties );

	SetupAPI( pWinProperties->m_uiWidth, pWinProperties->m_uiHeight, pWinProperties->m_b3D );

	return m_pWindow;
}

void ceRenderDeviceOGL::DeleteWindow( void )
{
	delete m_pWindow;
	m_pWindow = NULL;
}

void ceRenderDeviceOGL::ClearBuffers( bool bColorBuffer, bool bDepthBuffer, bool bStencilBuffer )
{
	ceUInt uiFlags = 0;
	
	if( bColorBuffer ) uiFlags |= GL_COLOR_BUFFER_BIT;
	if( bDepthBuffer ) uiFlags |= GL_DEPTH_BUFFER_BIT;
	if( bStencilBuffer ) uiFlags |= GL_STENCIL_BUFFER_BIT;

	glClear( uiFlags );
}

void ceRenderDeviceOGL::Update( void )
{
	m_pWindow->Update();
}

void ceRenderDeviceOGL::SetupAPI( ceUInt uiWidth, ceUInt uiHeight, bool b3D )
{
	if( m_pWindow == NULL ) return;

	// Enable Smooth Shading
	glShadeModel( GL_SMOOTH );

	glPointSize( 10 );

	// Set the background to black
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

	// Depth Buffer setup
	glClearDepth( 1.0f );

	glClearStencil( 0 );

	// Enable depth testing
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );

	// Setup for best perspective calculations
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

	ceReal32 width = (ceReal32)uiWidth;
	ceReal32 height = (ceReal32)uiHeight;

	glCullFace( GL_FRONT );
	glEnable( GL_CULL_FACE );

	// Setup our viewport
	glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );

	if( b3D == false )
	{
		glOrtho( 0, uiWidth, uiHeight, 0, -1.0, 1.0 );	//2d
	}
	else
	{
		gluPerspective( 45, width/height, 0.1, 2048 );	//3d
	}

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void ceRenderDeviceOGL::SetClearColor( const ceColorRGBA& ClearColor )
{
	glClearColor( ClearColor.r, ClearColor.g, ClearColor.b, ClearColor.a );
}

void ceRenderDeviceOGL::SetLookAt( const ceVector3& vPosition, const ceVector3& vPoceIntTo, const ceVector3& vWorldUp )
{
	gluLookAt(	vPosition.x, vPosition.y, vPosition.z,
				vPoceIntTo.x, vPoceIntTo.y, vPoceIntTo.z,
				vWorldUp.x, vWorldUp.y, vWorldUp.z );
}

void ceRenderDeviceOGL::BeginFrame( void )
{
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void ceRenderDeviceOGL::EndFrame( void )
{
}

void ceRenderDeviceOGL::DrawPoint( ceVector3& vVertex1 )
{
	glBegin( GL_POINTS );
		glVertex3f( vVertex1.x, vVertex1.y, vVertex1.z );
	glEnd();
}

void ceRenderDeviceOGL::DrawTriangle( ceVector3& vVertex1, ceVector3& vVertex2, ceVector3& vVertex3 )
{
	glBegin( GL_TRIANGLES );
		glVertex3f( vVertex1.x, vVertex1.y, vVertex1.z );
		glVertex3f( vVertex2.x, vVertex2.y, vVertex2.z );
		glVertex3f( vVertex3.x, vVertex3.y, vVertex3.z );
	glEnd();
}
