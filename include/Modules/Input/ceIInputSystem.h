#ifndef CE_I_INPUT_SYSTEM_H
#define CE_I_INPUT_SYSTEM_H

#include <ceConfig.h>
#include <Modules/ceIBaseSystem.h>
#include <Modules/Input/ceIInputDevice.h>

class ceIInputSystem : public ceIBaseSystem
{
public:
					ceIInputSystem( void ) {}
	virtual			~ceIInputSystem( void ) {}

	void			InitSystem( void ) {};
	void			ShutdownSystem( void ) {};

	virtual ceULong	GetVersion( void ) const { return ENGINE_VERSION; }

	/// Get the input device. If no device exists, a default one is created.
	virtual ceIInputDevice*		GetDevice( void ) = 0;
};

extern "C"
{
	typedef void ( *CREATEINPUTSYSTEM )( ceIInputSystem** );
	typedef void ( *RELEASEINPUTSYSTEM )( ceIInputSystem** );
}

#endif