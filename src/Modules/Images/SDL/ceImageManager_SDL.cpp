#include "ceImageManager_SDL.h"

ceImageManagerSDL::ceImageManagerSDL( void )
{
}

ceImageManagerSDL::~ceImageManagerSDL( void )
{
}

bool ceImageManagerSDL::LoadImage(	const ceString sFileName )
{
	SDL_Surface *temp, *image;

	// Load the temporary image
	temp = IMG_Load( sFileName.c_str() );

	// If the image loaded ok, conver it to a usable format
	if( temp != NULL )
	{
		image = SDL_DisplayFormat( temp );
		SDL_FreeSurface( temp );
	}
	else
	{
		printf( "Image '%s' failed to load.\n", sFileName.c_str() );
		return false;
	}

	return true;
}

void ceImageManagerSDL::UnloadImage( const ceString sFileName )
{
}
