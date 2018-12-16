#ifndef CE_MODULE_LOADER_H
#define CE_MODULE_LOADER_H

#include <Modules/ceIBaseSystem.h>
#include <ceConfig.h>

void LoadModule( ceString FileName, ceString ReferenceName );
bool LoadSystem( ceString ReferenceName, ceIBaseSystem** System );
bool GetLoadedSystem( ceString ReferenceName, ceIBaseSystem** pSystem );
void UnloadSystem( ceString ReferenceName, ceIBaseSystem** System );

#endif