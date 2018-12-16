#ifndef CE_I_IMAGE_SYSTEM_H
#define CE_I_IMAGE_SYSTEM_H

#include <ceConfig.h>
#include <Modules/ceIBaseSystem.h>
#include <Modules/Image/ceIImageDevice.h>

class ceIImageSystem : public ceIBaseSystem
{
public:
					ceIImageSystem( void ) {}
	virtual			~ceIImageSystem( void ) {}

	void			InitSystem( void ) {};
	void			ShutdownSystem( void ) {};

	virtual ceULong	GetVersion( void ) const { return ENGINE_VERSION; }

	/// Get the input device. If no device exists, a default one is created.
	virtual ceIImageDevice*		GetDevice( void ) = 0;
};

extern "C"
{
	typedef void ( *CREATEIMAGESYSTEM )( ceIImageSystem** );
	typedef void ( *RELEASEIMAGESYSTEM )( ceIImageSystem** );
}

#endif