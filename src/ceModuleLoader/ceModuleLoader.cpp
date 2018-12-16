#include <SDL/SDL.h>
#include <SDL/SDL_loadso.h>

#include "ceModuleLoader.h"
#include <ceConfig.h>
#include <Modules/ceIBaseSystem.h>

typedef void (*CREATESYSTEM)	( ceIBaseSystem** System );
typedef void (*RELEASESYSTEM)	( ceIBaseSystem** System );

/**
ceModule structure for handling a module library
*/
struct ceModule
{
	ceString		m_sFileName;			// The actual file's name.
	ceString		m_sReferenceName;		// A name the user gives to this module.
	void*			m_SDLHandle;			// A poceInter to the SDL handle.
	ceIBaseSystem*	m_pSystem;				// A poceInter to the created instance of the module
	CREATESYSTEM	m_CreateFunc;			// Function poceInter to the creator of the module
	RELEASESYSTEM	m_ReleaseFunc;			// Function poceInter to the creator of the module

	// Constructer the creates a blank ceModule
	ceModule()
	{
		m_sFileName = "";
		m_sReferenceName = "";
		m_pSystem = NULL;
	}
};

// This holds all of the modules that have been loaded thus far.
ceArray<ceModule> LoadedModules;


void LoadModule( ceString FileName, ceString ReferenceName )
{
	ceModule module;
	module.m_sFileName = FileName;
	module.m_sReferenceName = ReferenceName;
	module.m_SDLHandle = SDL_LoadObject( module.m_sFileName.c_str() );

	// Check to make sure the module didn't fail to load
	if( module.m_SDLHandle == NULL )
	{
		ceString error = "";
		error += "Module Object Load Error: " + FileName + "\n";
		error += "  SDL Error: ";
		error += SDL_GetError();
		error += "\n";
		CE_EXCEPTION( error, CE_ERROR );
	}

	module.m_CreateFunc = (CREATESYSTEM) SDL_LoadFunction( module.m_SDLHandle, "CreateSystem" );

	// Check to make sure the create function didn't fail to load
	if( module.m_CreateFunc == NULL )
	{
		ceString error = "";
		error += "Module Function Load Error: " + FileName + "\n";
		error += "  CreateSystem() error.\n";
		error += "  SDL Error: ";
		error += SDL_GetError();
		error += "\n";
		CE_EXCEPTION( error, CE_ERROR );
	}

	module.m_ReleaseFunc = (RELEASESYSTEM) SDL_LoadFunction( module.m_SDLHandle, "ReleaseSystem" );
	
	// Check to make sure the release function didn't fail to load
	if( module.m_ReleaseFunc == NULL )
	{
		ceString error = "";
		error += "Module Function Load Error: " + FileName + "\n";
		error += "  ReleaseSystem() error.\n";
		error += "  SDL Error: ";
		error += SDL_GetError();
		error += "\n";
		CE_EXCEPTION( error, CE_ERROR );
	}

	// Add this module to the list of loaded modules.
	LoadedModules.push_back( module );
}

bool LoadSystem( ceString ReferenceName, ceIBaseSystem** System )
{
	for( ceUInt i = 0; i < LoadedModules.size(); i++ )
	{
		// Is this module the one were looking for?
		if( LoadedModules[i].m_sReferenceName == ReferenceName )
		{
			LoadedModules[i].m_CreateFunc( System );
			LoadedModules[i].m_pSystem = *System;
			return true; // System Loaded
		}
	}

	// No module found with the specified reference name
	return false;
}


bool GetLoadedSystem( ceString ReferenceName, ceIBaseSystem** pSystem )
{
	ceArray<ceModule>::iterator it;

	for( it = LoadedModules.begin(); it != LoadedModules.end(); ++it )
	{
		if( (*it).m_sReferenceName == ReferenceName )
		{
			*pSystem = (*it).m_pSystem;
			return true; // Library was already loaded
		}
	}

	// Library wasnt already loaded
	return false;
}

void UnloadSystem( ceString ReferenceName, ceIBaseSystem** System )
{
	CE_ASSERT( *System != NULL );

	ceArray<ceModule>::iterator it;

	for( it = LoadedModules.begin(); it != LoadedModules.end(); ++it )
	{
		if( (*it).m_sReferenceName == ReferenceName )
		{
			ceModule module = *it;
			module.m_ReleaseFunc( System );
			module.m_pSystem = NULL;
			System = NULL;
			return;
		}
	}
}
