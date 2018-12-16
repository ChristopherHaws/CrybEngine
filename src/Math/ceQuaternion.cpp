#include <Math/ceQuaternion.h>
#include <math.h>
#include <string.h>

ceQuaternion::ceQuaternion( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

ceQuaternion::ceQuaternion( float X, float Y, float Z, float W )
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}

void ceQuaternion::GetMatrix( ceMatrix *ceMatrix )
{
	float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;

	// Identity ceMatrix
	memset( ceMatrix, 0, sizeof( ceMatrix ) );
	ceMatrix->_44 = 1.0f;

	x2 = x + x;
	y2 = y + y;
	z2 = z + z;

	xx = x * x2;
	xy = x * y2;
	xz = x * z2;

	yy = y * y2;
	yz = y * z2;
	zz = z * z2;

	wx = w * x2;
	wy = w * y2;
	wz = w * z2;

	ceMatrix->_11 = 1.0f - ( yy + zz );
	ceMatrix->_12 = xy - wz;
	ceMatrix->_13 = xz + wy;

	ceMatrix->_21 = xy + wz;
	ceMatrix->_22 = 1.0f - ( xx + zz );
	ceMatrix->_23 = yz - wx;

	ceMatrix->_31 = xz - wy;
	ceMatrix->_32 = yz + wx;
	ceMatrix->_33 = 1.0f - ( xx + yy );
}

void ceQuaternion::MakeFromEuler( float fPitch, float fYaw, float fRoll )
{
	float cosX, cosY, cosZ;
	float sinX, sinY, sinZ;
	float cYcZ, sYsZ, cYsZ, sYcZ;	// mixtures of some

	fPitch *= 0.5f;
	fYaw *= 0.5f;
	fRoll *= 0.5f;

	cosX = cosf( fPitch );
	cosY = cosf( fYaw );
	cosZ = cosf( fRoll );

	sinX = sinf( fPitch );
	sinY = sinf( fYaw );
	sinZ = sinf( fRoll );

	cYcZ = cosY * cosZ;
	sYsZ = sinY * sinZ;
	cYsZ = cosY * sinZ;
	sYcZ = sinY * cosZ;

	w = cosX * cYcZ + sinX * sYsZ;
	x = sinX * cYcZ - cosX * sYsZ;
	y = cosX * sYcZ + sinX * cYsZ;
	z = cosX * cYsZ - sinX * sYcZ;
}

ceQuaternion ceQuaternion::operator * ( const ceQuaternion &q ) const
{
	ceQuaternion result;

	result.w = (w * q.w) - (x * q.x) - (y * q.y) - (z * q.z);
	result.x = (w * q.x) + (x * q.w) + (y * q.z) - (z * q.y);
	result.y = (w * q.y) + (y * q.w) + (z * q.x) - (x * q.z);
	result.z = (w * q.z) + (z * q.w) + (x * q.y) - (y * q.x);

	return result;
}

void ceQuaternion::operator *= ( const ceQuaternion &q )
{
	float X, Y, Z, W;

	W = (w * q.w) - (x * q.x) - (y * q.y) - (z * q.z);
	X = (w * q.x) + (x * q.w) + (y * q.z) - (z * q.y);
	Y = (w * q.y) + (y * q.w) + (z * q.x) - (x * q.z);
	Z = (w * q.z) + (z * q.w) + (x * q.y) - (y * q.x);

	x = X;
	y = Y;
	z = Z;
	w = W;
}
