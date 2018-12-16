#ifndef CE_QUATERNION_H
#define CE_QUATERNION_H

#include <Math/ceMatrix.h>

class ceQuaternion
{
public:
	float x, y, z, w;

	ceQuaternion( void );
	ceQuaternion( float X, float Y, float Z, float W );

	void GetMatrix( ceMatrix *ceMatrix );
	void MakeFromEuler( float fPitch, float fYaw, float fRoll );

	ceQuaternion operator * ( const ceQuaternion &q ) const;
	void operator *= ( const ceQuaternion &q );
};

#endif