#ifndef CE_I_RENDER_DEVICE_H
#define CE_I_RENDER_DEVICE_H

#include <ceConfig.h>
#include <Modules\Renderer\ceWindowProperties.h>
#include <Modules\Renderer\ceIWindow.h>

class ceIRenderDevice
{
public:
					ceIRenderDevice( void ) {}
	virtual			~ceIRenderDevice( void ) {}

	/// Initialize the available video modes
	virtual void	Create( void ) = 0;

	/// Removes this device
	virtual void	Release( void ) = 0;

	/// Reset this device to its default state
	virtual void	Reset( void ) = 0;

	/// Create a window
	virtual ceIWindow*	CreateWindow( ceWindowProperties *pWinProperties ) = 0;

	/// Delete the window
	virtual void		DeleteWindow( void ) = 0;

	/// Clears all of the buffers
	virtual void ClearBuffers( bool bColorBuffer = true, bool bDepthBuffer = ture, bool bStencilBuffer = false ) = 0;

	/// Updates the screen
	virtual void Update( void ) = 0;
};

#endif