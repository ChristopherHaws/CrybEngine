#ifndef CE_I_RENDER_SYSTEM_H
#define CE_I_RENDER_SYSTEM_H

#include <ceConfig.h>
#include <Modules/ceIBaseSystem.h>
#include "ceIRenderDevice.h"

class ceIRenderSystem : public ceIBaseSystem
{
public:
					ceIRenderSystem( void ) {}
	virtual			~ceIRenderSystem( void ) {}

	void			InitSystem( void ) {}
	void			ShutdownSystem( void ) {}

	/// Get the current version of the render module
	virtual ULong	GetVersion( void ) const { return ENGINE_VERSION; }

	/// Create a render device
	virtual ceIRenderDevice*		CreateDevice( void ) = 0;

	/// Remove a render device
	virtual void				RemoveDevice( ceIRenderDevice* pDevice ) = 0;

	// Remove all created render devices
	virtual void				RemoveAllDevices( void ) = 0;
};

extern "C"
{
	EXPORTS void CreateRenderSystem( ceRenderSystem ** );
	typedef void ( *CREATERENDERSYSTEM )( ceRenderSystem** );
	EXPORTS void ReleaseRenderSystem( ceRenderSystem ** );
	typedef void ( *RELEASERENDERSYSTEM )( ceRenderSystem** );
}

#endif