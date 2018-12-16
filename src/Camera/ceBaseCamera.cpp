#include "Camera/ceBaseCamera.h"

ceBaseCamera::ceBaseCamera( void )
{
	Initialize();
}

ceBaseCamera::~ceBaseCamera( void )
{
}

void ceBaseCamera::RecalculateAxes( void )
{
	ceQuaternion frame;
	ceMatrix matrix;

	static ceReal32 PI2 = PI * 2;

	// Keep to the range of 360 degrees
	if( m_RotationX > PI2 ) m_RotationX -= PI2;
	else if( m_RotationX < -PI2 ) m_RotationX += PI2;
	
	if( m_RotationY > PI2 ) m_RotationY -= PI2;
	else if( m_RotationY < -PI2 ) m_RotationY += PI2;
	
	if( m_RotationZ > PI2 ) m_RotationZ -= PI2;
	else if( m_RotationZ < -PI2 ) m_RotationZ += PI2;

	// Build a new quaternion for this rotation
	frame.MakeFromEuler( m_RotationX, m_RotationY, m_RotationZ );

	// Add to the current roation by multiplying quaternions
	m_ceQuaternion *= frame;

	// Extract the local axis
	m_ceQuaternion.GetMatrix( &matrix );

	m_Right.x = matrix._11;
	m_Right.y = matrix._21;
	m_Right.z = matrix._31;

	m_Up.x = matrix._12;
	m_Up.y = matrix._22;
	m_Up.z = matrix._32;

	m_Direction.x = matrix._13;
	m_Direction.y = matrix._23;
	m_Direction.z = matrix._33;
}

void ceBaseCamera::Initialize( void )
{
	m_Position.Set( 0.0f, 0.0f, 0.0f );
	m_Right.Set( 1.0f, 0.0f, 0.0f );
	m_Up.Set( 0.0f, 1.0f, 0.0f );
	m_Direction.Set( 0.0f, 0.0f, 1.0f );
	m_Velocity.Set( 0.0f, 0.0f, 0.0f );
	m_ceQuaternion.x = m_ceQuaternion.y = m_ceQuaternion.z = 0.0f;
	m_ceQuaternion.w = 1.0f;

	m_RollSpeed = m_PitchSpeed = m_YawSpeed = 0.0f;
	m_RotationX = m_RotationY = m_RotationZ = m_Thrust = 0.0f;
}
