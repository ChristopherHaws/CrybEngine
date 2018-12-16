#include "Math/ceMatrix.h"
#include "Math/ceVector3.h"
#include "math.h"
#include <string.h>

ceMatrix::ceMatrix( void )
{
}

ceMatrix::~ceMatrix( void )
{
}

void ceMatrix::Identify( void )
{
	float *f = (float*) &this->_11;
	memset( f, 0, sizeof( ceMatrix ) );
	_11 = _22 = _33 = _44 = 1.0f;
}

void ceMatrix::RotateX( float x )
{
	float fCos = cosf( x );
	float fSin = sinf( x );
	_22 = fCos;
	_23 = fSin;
	_32 = -fSin;
	_33 = fCos;
	_11 = _44 = 1.0f;
	_12 = _13 = _14 = _21 = _24 = _31 = _34 = _41 = _42 = _43 = 0.0f;
}

void ceMatrix::RotateY( float y )
{
	float fCos = cosf( y );
	float fSin = sinf( y );
	_11 = fCos;
	_13 = -fSin;
	_31 = fSin;
	_33 = fCos;
	_22 = _44 = 1.0f;
	_12 = _23 = _14 = _21 = _24 = _32 = _34 = _41 = _42 = _43 = 0.0f;
}

void ceMatrix::RotateZ( float z )
{
	float fCos = cosf( z );
	float fSin = sinf( z );
	_11 = fCos;
	_12 = fSin;
	_21 = -fSin;
	_22 = fCos;
	_33 = _44 = 1.0f;
	_13 = _14 = _23 = _24 = _31 = _32 = _34 = _41 = _42 = _43 = 0.0f;
}

void ceMatrix::RotateArbitrary( ceVector3 &vAxis, float theta )
{
	float fCos = cosf( theta );
	float fSin = sinf( theta );
	float fSum = 1.0f - fCos;

	vAxis.Normalize();

	_11 = ( vAxis.x * vAxis.x ) * fSum + fCos;
	_12 = ( vAxis.x * vAxis.y ) * fSum - ( vAxis.z * fSin );
	_13 = ( vAxis.x * vAxis.z ) * fSum + ( vAxis.y * fSin );

	_21 = ( vAxis.y * vAxis.x ) * fSum + ( vAxis.z * fSin );
	_22 = ( vAxis.y * vAxis.y ) * fSum + fCos;
	_23 = ( vAxis.y * vAxis.z ) * fSum - ( vAxis.x * fSin );

	_31 = ( vAxis.z * vAxis.x ) * fSum - ( vAxis.y * fSin );
	_32 = ( vAxis.z * vAxis.y ) * fSum + ( vAxis.x * fSin );
	_33 = ( vAxis.z * vAxis.z ) * fSum + fCos;

	_14 = _24 = _34 = _41 = _42 = _43 = 0.0f;
	_44 = 1.0f;
}

void ceMatrix::Translate( float x, float y, float z )
{
	_41 = x;
	_42 = y;
	_43 = z;
}

void ceMatrix::TransposeOf( const ceMatrix &ceMatrix )
{
	_11 = ceMatrix._11;
	_21 = ceMatrix._12;
	_31 = ceMatrix._13;
	_41 = ceMatrix._14;
	
	_12 = ceMatrix._21;
	_22 = ceMatrix._22;
	_32 = ceMatrix._23;
	_42 = ceMatrix._24;
	
	_13 = ceMatrix._31;
	_23 = ceMatrix._32;
	_33 = ceMatrix._33;
	_43 = ceMatrix._34;
	
	_14 = ceMatrix._41;
	_24 = ceMatrix._42;
	_34 = ceMatrix._43;
	_44 = ceMatrix._44;
}

void ceMatrix::InverseOf( const ceMatrix &ceMatrix )
{
}

ceMatrix ceMatrix::operator * ( const ceMatrix &ceMatrix ) const
{
	return ceMatrix;
}
/*
ceVector3 ceMatrix::operator * ( const ceVector3 &vector ) const
{
	return ceVector3( 0, 0, 0 );
}
*/