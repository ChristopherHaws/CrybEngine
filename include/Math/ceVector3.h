#ifndef CE_VECTOR3_H
#define CE_VECTOR3_H

class ceMatrix;

class ceVector3
{
public:
	// Coordinates
	float x;
	float y;
	float z;
	float w;

public:
	ceVector3( ceVector3 &v );
	ceVector3( float X = 0.0f, float Y = 0.0f, float Z = 0.0f, float W = 1.0f );

	// Fuctions
	void Set( float X, float Y, float Z, float W = 1.0f );	// Set X, Y, Z, and W

	float GetLength( void );				// Get the length of the Vector
	float GetSquareLength( void ) const;	// Get the square root length
	float GetAngleWith( ceVector3 &v );		// Get the angle between two vectors, in radians
	float GetAngleWithDegrees( ceVector3 &v );	//Get the angle between 2 vectors, in degrees
	void Negate( void );					// Multiply Vector by -1
	ceVector3& Normalize( void );				// Normalize this Vector
	void Difference( const ceVector3 &v1, const ceVector3 &v2 );	// Find the difference between v1 and v2
	void CrossProduct( const ceVector3 &v1, const ceVector3 &v2 );	// Find the cross product of v1 and v2

	// Operators
	void operator += ( const ceVector3 &v );				// operator +=
	void operator -= ( const ceVector3 &v );				// operator -=
	void operator *= ( float f );						// scale vector
	void operator /= ( float f );						// scale down
	void operator += ( float f );						// add scalar
	void operator -= ( float f );						// subtract scalar
	float operator * ( const ceVector3 &v )const;			// dot product
	ceVector3 operator * ( float f )const;				// scale vector
	ceVector3 operator * ( ceMatrix &m ) const;
	ceVector3 operator / ( float f )const;				// scalar divide
	ceVector3 operator + ( float f )const;				// add scalar
	ceVector3 operator - ( float f )const;				// scale down
	ceVector3 operator + ( const ceVector3 &v )const;		// addition
	ceVector3 operator - ( const ceVector3 &v )const;		// subtraction
	ceVector3 operator % ( const ceVector3 &v ) const;
	bool operator == ( float f ) const;
	bool operator != ( float f ) const;
};

#endif