#ifndef CE_RENDER_DEVICE_OGL_H
#define CE_RENDER_DEVICE_OGL_H

#include <ceConfig.h>
#include <Modules/Renderer/ceIRenderDevice.h>
#include <Modules/Renderer/ceIWindow.h>
#include <Modules/Renderer/ceWindowProperties.h>


// TODO
//	- Add Skin Manager
//	- Add clipping plane support (near, far)
//	- 2Dto3D ( give a point, get a starting vector and direction vector )
//	- 3Dto2D ( give a vector, get a point )
//	- Add ability to change through Perspective, Othogonal, and "world = screen cords"
class ceRenderDeviceOGL : public ceIRenderDevice
{
public:
				ceRenderDeviceOGL( void ) {}
				~ceRenderDeviceOGL( void ) {}

	void		Create( void );
	void		Release( void );
	void		Reset( void );

	ceIWindow*	CreateNewWindow( ceWindowProperties *pWinProperties );
	void		DeleteWindow( void );

	void		ClearBuffers( bool bColorBuffer = true, bool bDepthBuffer = true, bool bStencilBuffer = false );
	void		Update( void );
	void		SetupAPI( ceUInt uiWidth, ceUInt uiHeight, bool b3D );

	void		SetClearColor( const ceColorRGBA& ClearColor );
	void		SetLookAt( const ceVector3& vPosition, const ceVector3& vPoceIntTo, const ceVector3& vWorldUp );

	void		BeginFrame( void );
	void		EndFrame( void );

	void		DrawPoint( ceVector3& vVertex1 );
	void		DrawTriangle( ceVector3& vVertex1, ceVector3& vVertex2, ceVector3& vVertex3 );

private:
	ceIWindow*	m_pWindow;
	bool		m_bOverlay;
};

#endif