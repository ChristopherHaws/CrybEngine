#ifndef CE_IMAGE_TYPES_H
#define CE_IMAGE_TYPES_H

#include <ceConfig.h>

typedef struct cePaletteType
{
	ceUInt32 m_iNumberOfColors;
	ceColorRGBA *m_cColors;
} cePalette;

typedef struct cePixelFormatType
{
	cePalette	*m_pPalette;	// NULL if not 8bit
	ceUInt8		m_iBitsPerPixel;
	ceUInt8		m_iBytesPerPixel;
	ceUInt8		m_iRloss, m_iGloss, m_iBloss, m_iAloss;
	ceUInt8		m_iRshift, m_iGshift, m_iBshift, m_iAlphaShift;
	ceUInt32	m_iRmask, m_iGmask, m_iBmask, m_iAlphaMask;
	ceUInt32	m_iColorKey;
	ceUInt8		m_iAlpha;

} cePixelFormat;

typedef struct ceImageType
{
	ceString		m_sName;				// Image Filename
	cePixelFormat	*m_pFormat;				// Image format information
	ceUInt32		m_iWidth, m_iHeight;	// Width and Height information
	void			*m_pPixels;				// Image Data
	ceUInt32		m_iReferenceCount;		// Used for freeing images
} ceImage;

#endif