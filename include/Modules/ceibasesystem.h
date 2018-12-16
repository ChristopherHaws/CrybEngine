#ifndef CE_I_BASE_SYSTEM_H
#define CE_I_BASE_SYSTEM_H

#include <ceConfig.h>

class ceIBaseSystem
{
public:
					ceIBaseSystem( void ) {}
	virtual			~ceIBaseSystem( void ) {}

	virtual void	InitSystem( void ) = 0;
	virtual void	ShutdownSystem( void ) = 0;
	virtual ceULong	GetVersion( void ) const = 0;
};

#endif