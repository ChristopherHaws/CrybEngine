#ifndef CE_I_WINDOW_H
#define CE_I_WINDOW_H

#include <ceConfig.h>
#include <Modules/Renderer/ceWindowProperties.h>

class ceIWindow
{
public:
					ceIWindow( void ) {}
	virtual			~ceIWindow( void ) {}

	/// Create a window with the specified properties
	virtual void	Create( ceWindowProperties *pWinProperties ) = 0;

	/// Shut down the window
	virtual void	Release( void ) = 0;

	virtual ceWindowProperties&		GetWindowProperty( void ) = 0;

	/// Switch the back buffer with the front
	virtual void	Update( void ) = 0;

	virtual bool	IsActive( void ) = 0;
	virtual bool	IsValid( void ) = 0;

	virtual ceString	GetTitle( void ) = 0;
	virtual void		SetTitle( ceString title ) = 0;

	virtual ceUInt		GetWidth( void ) = 0;
	virtual ceUInt		GetHeight( void ) = 0;
};

#endif