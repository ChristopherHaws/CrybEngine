#ifndef CE_FIRST_PERSON_CAMERA_H
#define CE_FIRST_PERSON_CAMERA_H

#include <ceConfig.h>
#include <Camera/ceBaseCamera.h>

class ceFirstPersonCamera : public ceBaseCamera
{
public:
	ceFirstPersonCamera( void );
	virtual ~ceFirstPersonCamera( void );

	virtual void Update( ceReal32 ElapsedTime );

	void GetRotation( ceReal32 *X, ceReal32 *Y, ceReal32 *Z );
	ceVector3 GetRotation( void );

	void SetRotationSpeedX( ceReal32 x );
	void SetRotationSpeedY( ceReal32 y );
	void SetSpeed( ceReal32 speed );
	void SetSlideSpeed( ceReal32 speed );

	void SetRotation( ceReal32 x, ceReal32 y, ceReal32 z );
	void SetPosition( ceVector3 &position );
	void SetRight( ceVector3 &right );
	void SetUp( ceVector3 &up );
	void SetDirection( ceVector3 &direction );

private:
	ceReal32 m_Speed;
	ceReal32 m_Slide;

	void RecalculateAxes( void );
};

#endif