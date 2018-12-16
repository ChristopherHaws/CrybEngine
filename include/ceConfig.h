#ifndef CE_CONFIG_H
#define CE_CONFIG_H

#include <ceTypes.h>
#include <ceDebug.h>

#define ENGINE_VERSION 0x00000010

#define PI 3.14159265358979323846f

// Module Macros
#if defined(WIN32)
#  define DLL_EXPORT __declspec(dllexport)
#  define DLL_IMPORT __declspec(dllimport)
#endif

#define EXPORTS	DLL_EXPORT

#endif