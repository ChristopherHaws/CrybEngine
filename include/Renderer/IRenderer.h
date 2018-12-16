#ifndef I_RENDERER_H
#define I_RENDERER_H

#include <ceTypes.h>

class IRenderer
{
public:
					IRenderer( void ) {}
	virtual			~IRenderer( void ) {}

	/// Creates a window that can be drawn to.
	virtual bool	Initialize( UInt Width, UInt Height, bool Fullscreen ) = 0;

	/// Closes the window.
	virtual void	Release( void ) = 0;

	/// Is the window curently running?
	virtual bool	IsRunning( void ) = 0;

	/// Set the caption of the game window.
	virtual void	SetWindowCaption( const char *Caption, ... ) = 0;

	/// Start rendering and clear the screen.
	virtual void	StartRendering( bool ClearPixel, bool ClearDepth, bool ClearStencil ) = 0;

	/// Stop rendering
	virtual void	StopRendering( void ) = 0;
};

#endif