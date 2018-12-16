#ifndef CE_I_RENDER_DEVICE_H
#define CE_I_RENDER_DEVICE_H

#include <ceConfig.h>
#include <Modules/Renderer/ceWindowProperties.h>
#include <Modules/Renderer/ceIWindow.h>

// Math
#include <Math/ceVector3.h>

class ceIRenderDevice
{
public:
						ceIRenderDevice( void ) {}
	virtual				~ceIRenderDevice( void ) {}

	/// Initialize the available video modes
	virtual void		Create( void ) = 0;

	/// Removes this device
	virtual void		Release( void ) = 0;

	/// Reset this device to its default state
	virtual void		Reset( void ) = 0;

	/// Create a window
	virtual ceIWindow*	CreateNewWindow( ceWindowProperties* pWinProperties ) = 0;

	/// Delete the window
	virtual void		DeleteWindow( void ) = 0;

	/// Clears all of the buffers
	virtual void		ClearBuffers( bool bColorBuffer = true, bool bDepthBuffer = true, bool bStencilBuffer = false ) = 0;

	/// Updates the screen
	virtual void		Update( void ) = 0;

	/// Set up the specific API
	virtual void		SetupAPI( ceUInt uiWidth, ceUInt uiHeight, bool b3D ) = 0;

	/// Set the clear color for the screen (default: black)
	virtual void		SetClearColor( const ceColorRGBA& ClearColor ) = 0;

	/// Set the look at poceInt for your camera
	virtual void		SetLookAt( const ceVector3& vPosition, const ceVector3& vPoceIntTo, const ceVector3& vWorldUp ) = 0;

	/// Start the current render frame
	virtual void		BeginFrame( void ) = 0;

	/// End the current render frame
	virtual void		EndFrame( void ) = 0;

	/// Draws a poceInt onto the screen
	virtual void		DrawPoint( ceVector3& vVertex1 ) = 0;

	/// Draws a triangle onto the screen
	virtual void		DrawTriangle( ceVector3& vVertex1, ceVector3& vVertex2, ceVector3& vVertex3 ) = 0;
};

#endif