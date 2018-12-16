#ifndef CE_TYPES_H
#define CE_TYPES_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef unsigned int ceUInt;
typedef int ceInt;
typedef unsigned char ceUInt8;
typedef char ceInt8;
typedef unsigned short ceUInt16;
typedef short ceInt16;
typedef unsigned int ceUInt32;
typedef int ceInt32;
typedef unsigned __int64 ceUInt64;
typedef __int64 ceInt64;
typedef unsigned long ceULong;

typedef float ceReal32;
typedef double ceReal64;

#define ceString std::string
#define ceArray std::vector
#define ceMap std::map

struct ceColorRGBA
{
	float r, g, b, a;
	ceColorRGBA( float Red = 1.0f, float Green = 1.0f, float Blue = 1.0f, float Alpha = 1.0f )
	{
		r = Red;
		g = Green;
		b = Blue;
		a = Alpha;
	}
};
/*
struct ceVector3
{
	float x, y, z;
	ceVector3( float X = 0.0f, float Y = 0.0f, float Z = 0.0f )
	{
		x = X;
		y = Y;
		z = Z;
	}
};
*/
/// A time value measured in milliseconds (1/1000 of a second)
typedef unsigned int ceTicks;

#endif