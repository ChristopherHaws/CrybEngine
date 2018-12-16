#ifndef CE_MATRIX_H
#define CE_MATRIX_H

#include <Math/ceVector3.h>

class ceMatrix
{
public:
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;

public:
	ceMatrix( void );
	~ceMatrix( void );

	void Identify( void );	// Make an identity ceMatrix
	void RotateX( float x );	// Rotate around the X axis
	void RotateY( float y );	// Rotate around the Y axis
	void RotateZ( float z );	// Rotate around the Z axis
	void RotateArbitrary( ceVector3 &vAxis, float theta );
	void Translate( float x, float y, float z );	// Translate the ceMatrix

	void TransposeOf( const ceMatrix &ceMatrix );
	void InverseOf( const ceMatrix &ceMatrix );

	ceMatrix operator * ( const ceMatrix &ceMatrix ) const;
	//ceVector3 operator * ( const ceVector3 &vector ) const;
};

#endif