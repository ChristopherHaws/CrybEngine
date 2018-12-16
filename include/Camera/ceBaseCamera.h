#ifndef CE_BASE_CAMERA_H
#define CE_BASE_CAMERA_H

#include <ceConfig.h>
#include <Math/ceVector3.h>
#include <Math/ceMatrix.h>
#include <Math/ceQuaternion.h>

class ceBaseCamera
{
public:
	ceBaseCamera( void );
	virtual ~ceBaseCamera( void );

	virtual void Update( ceReal32 ElapsedTime ) = 0;

	// Accessor Methods
	ceVector3 GetPos( void );
	ceVector3 GetRight( void );
	ceVector3 GetUp( void );
	ceVector3 GetDirection( void );
	ceVector3 GetVelocity( void );

protected:
	ceVector3 m_Position;
	ceVector3 m_Right;
	ceVector3 m_Up;
	ceVector3 m_Direction;
	ceVector3 m_Velocity;
	ceQuaternion m_ceQuaternion;

	// Rotation speed on local axis
	ceReal32 m_RollSpeed;
	ceReal32 m_PitchSpeed;
	ceReal32 m_YawSpeed;

	ceReal32 m_RollSpeedMax;
	ceReal32 m_PitchSpeedMax;
	ceReal32 m_YawSpeedMax;

	// Rotation angle on local axis
	ceReal32 m_RotationX;
	ceReal32 m_RotationY;
	ceReal32 m_RotationZ;

	ceReal32 m_Thrust;

	// Methods
	virtual void RecalculateAxes( void );
	virtual void Initialize( void );
};

#endif