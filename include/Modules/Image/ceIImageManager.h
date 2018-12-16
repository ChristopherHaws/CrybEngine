#ifndef CE_I_IMAGE_MANAGER_H
#define CE_I_IMAGE_MANAGER_H

#include <ceConfig.h>
#include <Modules/Image/ceImageTypes.h>

class ceIImageManager
{
public:
						ceIImageManager( void ) {}
	virtual				~ceIImageManager( void ) {}

	virtual bool		LoadImage(	const ceString sFileName ) = 0;
	virtual void		UnloadImage( const ceString sFileName ) = 0;
};

#endif