#ifndef CE_IMAGE_MANAGER_SDL_H
#define CE_IMAGE_MANAGER_SDL_H

#include <ceConfig.h>
#include <Modules/Image/ceImageTypes.h>
#include <Modules/Image/ceIImageManager.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class ceImageManagerSDL : public ceIImageManager
{
public:
	ceImageManagerSDL( void );
	~ceImageManagerSDL( void );

	bool LoadImage(	const ceString sFileName );
	void UnloadImage( const ceString sFileName );

private:
	ceMap< ceString, ceImage* > m_mImages;
};

#endif