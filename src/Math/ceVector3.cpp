#include <ceConfig.h>
#include <Math/ceVector3.h>
#include <Math/ceMatrix.h>
#include <math.h>

ceVector3::ceVector3( ceVector3 &v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

ceVector3::ceVector3( float X, float Y, float Z, float W )
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}

void ceVector3::Set( float X, float Y, float Z, float W )
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}

float ceVector3::GetLength( void )
{
	return (float)sqrt( x*x + y*y + z*z );
}

float ceVector3::GetSquareLength( void ) const
{
	return ( x*x + y*y + z*z );
}

float ceVector3::GetAngleWith( ceVector3 &v )
{
	return (float)acos( (( *this ) * v ) / ( GetLength() * v.GetLength() ) );
}

float ceVector3::GetAngleWithDegrees( ceVector3 &v )
{
	float angle = (float)acos( (( *this ) * v ) / ( GetLength() * v.GetLength() ) );
	return (float)(angle*(180/PI));
}

void ceVector3::Negate( void )
{
	x = -x;
	y = -y;
	z = -z;
	w = -w;
}

ceVector3& ceVector3::Normalize( void )
{
	float length = GetLength();

	if( length != 0.0f )
	{
		x /= length;
		y /= length;
		z /= length;
		w /= length;
	}

	return *this;
}

void ceVector3::Difference( const ceVector3 &v1, const ceVector3 &v2 )
{
	x = v2.x - v1.x;
	y = v2.y - v1.y;
	z = v2.z - v1.z;
	w = v2.w - v1.w;
}

void ceVector3::CrossProduct( const ceVector3 &v1, const ceVector3 &v2 )
{
	x = v1.y * v2.z - v1.z * v2.y;
	y = v1.z * v2.x - v1.x * v2.z;
	z = v1.x * v2.y - v1.y * v2.x;
	w = 1.0f;
}

void ceVector3::operator += ( const ceVector3 &v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

void ceVector3::operator -= ( const ceVector3 &v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}

void ceVector3::operator *= ( float f )
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;
}

void ceVector3::operator /= ( float f )
{
	x /= f;
	y /= f;
	z /= f;
	w /= f;
}

void ceVector3::operator += ( float f )
{
	x += f;
	y += f;
	z += f;
	w += f;
}

void ceVector3::operator -= ( float f )
{
	x -= f;
	y -= f;
	z -= f;
	w -= f;
}

/**
 * Multiply two ceVector3's (dot product)
 */
float ceVector3::operator * ( const ceVector3 &v )const
{
	return ( v.x * x + v.y * y + v.z * z );
}

ceVector3 ceVector3::operator * ( float f )const
{
	return ceVector3( x * f, y * f, z * f, w * f );
}

ceVector3 ceVector3::operator * ( ceMatrix &m ) const
{
	ceVector3 result;

	result.x = (x * m._11) + (y * m._21) + (z * m._31) + m._41;
	result.y = (x * m._12) + (y * m._22) + (z * m._32) + m._42;
	result.z = (x * m._13) + (y * m._23) + (z * m._33) + m._43;
	result.w = (x * m._14) + (y * m._24) + (z * m._34) + m._44;

	result.x = result.x / result.w;
	result.y = result.y / result.w;
	result.z = result.z / result.w;
	result.w = 1.0f;

	return result;
}

ceVector3 ceVector3::operator / ( float f )const
{
	return ceVector3( x / f, y / f, z / f, w / f );
}

ceVector3 ceVector3::operator + ( float f )const
{
	return ceVector3( x + f, y + f, z + f, w + f );
}

ceVector3 ceVector3::operator - ( float f )const
{
	return ceVector3( x - f, y - f, z - f, w - f );
}

ceVector3 ceVector3::operator + ( const ceVector3 &v )const
{
	return ceVector3( x + v.x, y + v.y, z + v.z, w + v.w );
}

ceVector3 ceVector3::operator - ( const ceVector3 &v )const
{
	return ceVector3( x - v.x, y - v.y, z - v.z, w - v.w );
}

ceVector3 ceVector3::operator % ( const ceVector3 &v ) const
{
	return ceVector3( y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x, 1.0f );
}

bool ceVector3::operator == ( float f ) const
{
	if( x != f || y != f || z != f || w != f ) return false;
	return true;
}

bool ceVector3::operator != ( float f ) const
{
	if( x == f && y == f && z == f && w == f ) return false;
	return true;
}
