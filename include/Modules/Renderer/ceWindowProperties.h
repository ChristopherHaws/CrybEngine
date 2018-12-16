#ifndef CE_WINDOW_PROPERTIES_H
#define CE_WINDOW_PROPERTIES_H

#include <ceConfig.h>

class ceWindowProperties
{
public:
	ceUInt m_uiXPosition;
	ceUInt m_uiYPosition;
	ceUInt m_uiWidth;
	ceUInt m_uiHeight;
	ceUInt m_uiColorBuffer;
	ceUInt m_uiStencilBuffer;
	ceUInt m_uiDepthBuffer;
	bool m_bFullscreen;
	bool m_bAntiAliasing;
	bool m_bVSync;
	bool m_b3D;
	ceString m_sTitle;

	ceWindowProperties( void ) {}

	ceWindowProperties( ceUInt x, ceUInt y, ceUInt w, ceUInt h, bool fullscreen, ceString title )
	{
		m_uiXPosition = x;
		m_uiYPosition = y;
		m_uiWidth = w;
		m_uiHeight = h;
		m_uiColorBuffer = 32;
		m_uiStencilBuffer = 32;
		m_uiDepthBuffer = 32;
		m_bFullscreen = false;
		m_bAntiAliasing = false;
		m_bVSync = false;
		m_sTitle = title;
		m_b3D = true;
	}

	~ceWindowProperties( void ) {}
};

#endif