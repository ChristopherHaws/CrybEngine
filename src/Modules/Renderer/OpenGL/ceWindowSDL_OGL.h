#ifndef CE_WINDOW_SDL_OGL_H
#define CE_WINDOW_SDL_OGL_H

#include <ceConfig.h>
#include <Modules/Renderer/ceIWindow.h>
#include <Modules/Renderer/ceWindowProperties.h>

class ceWindowSDL : public ceIWindow
{
protected:
	/// This windows properties
	ceWindowProperties	m_WindowProperties;
	/// Is this window the active window
	bool				m_bActive;
	/// Is this window still valid (open)
	bool				m_bValid;
	/// This is sdl's screen that it renders to
	SDL_Surface*		m_pSurface;

public:
				ceWindowSDL( void );
				~ceWindowSDL( void );

	void		Create( ceWindowProperties *pWinProperties );
	void		Release( void );

	ceWindowProperties&		GetWindowProperty( void ) { return m_WindowProperties; }

	void		Update( void );

	bool		IsActive( void ) { return m_bActive; }
	bool		IsValid( void ) { return m_bValid; }

	ceString	GetTitle( void ) { return m_WindowProperties.m_sTitle; }
	void		SetTitle( ceString title );

	ceUInt		GetWidth( void ) { return m_WindowProperties.m_uiWidth; }
	ceUInt		GetHeight( void ) { return m_WindowProperties.m_uiHeight; }
};

#endif