#include "Camera/ceFirstPersonCamera.h"
#include "Math/ceMatrix.h"
#include "Math/ceVector3.h"
#include "string.h"

ceFirstPersonCamera::ceFirstPersonCamera( void )
{
}

ceFirstPersonCamera::~ceFirstPersonCamera( void )
{
}

void ceFirstPersonCamera::Update( ceReal32 ElapsedTime )
{
	ceVector3 speed;

	// Add rotation speed
	m_RotationX += ( m_PitchSpeed * ElapsedTime );
	m_RotationY += ( m_YawSpeed * ElapsedTime );
	m_RotationZ += ( m_RollSpeed * ElapsedTime );

	// Calculate Axes
	RecalculateAxes();

	// Calculate speed vector
	m_Velocity = m_Direction * m_Speed * ElapsedTime;
	speed = m_Right * m_Slide * ElapsedTime;

	// Move Position
	m_Position += m_Velocity + speed;
}

void ceFirstPersonCamera::GetRotation( ceReal32 *X, ceReal32 *Y, ceReal32 *Z )
{
	if( X ) *X = m_RotationX;
	if( Y ) *Y = m_RotationY;
	if( Z ) *Z = m_RotationZ;
}

ceVector3 ceFirstPersonCamera::GetRotation( void )
{
	return ceVector3( m_RotationX, m_RotationY, m_RotationZ );
}

void ceFirstPersonCamera::SetRotationSpeedX( ceReal32 x )
{
	m_PitchSpeed = x;
}

void ceFirstPersonCamera::SetRotationSpeedY( ceReal32 y )
{
	m_YawSpeed = y;
}

void ceFirstPersonCamera::SetSpeed( ceReal32 speed )
{
	m_Speed = speed;
}

void ceFirstPersonCamera::SetSlideSpeed( ceReal32 speed )
{
	m_Slide = speed;
}

void ceFirstPersonCamera::SetRotation( ceReal32 x, ceReal32 y, ceReal32 z )
{
	m_RotationX = x;
	m_RotationY = y;
	m_RotationZ = z;

	RecalculateAxes();
}

void ceFirstPersonCamera::SetPosition( ceVector3 &position )
{
	memcpy( &m_Position, &position, sizeof( ceVector3 ) );
}

void ceFirstPersonCamera::SetRight( ceVector3 &right )
{
	memcpy( &m_Right, &right, sizeof( ceVector3 ) );
}

void ceFirstPersonCamera::SetUp( ceVector3 &up )
{
	memcpy( &m_Up, &up, sizeof( ceVector3 ) );
}

void ceFirstPersonCamera::SetDirection( ceVector3 &direction )
{
	memcpy( &m_Direction, &direction, sizeof( ceVector3 ) );
}

void ceFirstPersonCamera::RecalculateAxes( void )
{
	ceMatrix matrix;

	static ceReal32 PI2 = PI * 2;

	// Keep in range of 2 PI = 360 degrees
	if( m_RotationY > PI2 ) m_RotationY -= PI2;
	else if( m_RotationY < -PI2 ) m_RotationY += PI2;

	// Up/Down max 80 degrees
	if( m_RotationX > 1.4f ) m_RotationX = 1.4f;
	else if( m_RotationX < -1.4f ) m_RotationX = 1.4f;

	// Initializing Axis
	m_Right = ceVector3( 1.0f, 0.0f, 0.0f );
	m_Up = ceVector3( 0.0f, 1.0f, 0.0f );
	m_Direction = ceVector3( 0.0f, 0.0f, 1.0f );

	// Rotate around Y-Axis
	matrix.RotateArbitrary( m_Up, m_RotationY );
	m_Right = m_Right * matrix;
	m_Direction = m_Direction * matrix;
	
	// Rotate around X-Axis
	matrix.RotateArbitrary( m_Right, m_RotationX );
	m_Up = m_Up * matrix;
	m_Direction = m_Direction * matrix;

	// Correct rounding errors
	m_Direction.Normalize();
	m_Right.CrossProduct( m_Up, m_Direction );
	m_Right.Normalize();
	m_Up.CrossProduct( m_Direction, m_Right );
	m_Up.Normalize();
}
