#ifndef CE_I_INPUT_DEVICE_H
#define CE_I_INPUT_DEVICE_H

#include <ceConfig.h>
#include <Modules/Input/ceInputEnums.h>

class ceIMouseDevice
{
public:
					ceIMouseDevice( void ) {}
	virtual			~ceIMouseDevice( void ) {}

	virtual ceInt		GetPositionX( void ) = 0;			// X-Position of the mouse
	virtual ceInt		GetPositionY( void ) = 0;			// Y-Position of the mouse
	virtual ceInt		GetRelativeX( void ) = 0;			// X-Relative Position of the mouse
	virtual ceInt		GetRelativeY( void ) = 0;			// Y-Relative Position of the mouse
	
	virtual void	SetPosition( ceUInt x, ceUInt y ) = 0;	// Set the position of the mouse cursor

	virtual bool	ButtonPressed( ceUInt8 button ) = 0;	// Is this button pressed
	virtual bool	ButtonHeld( ceUInt8 button ) = 0;		// Is this button held down
};

class ceIKeyboardDevice
{
public:
					ceIKeyboardDevice( void ) {}
	virtual			~ceIKeyboardDevice( void ) {}

	virtual bool	KeyPressed( CEKey key ) = 0;	// Is this key pressed
	virtual bool	KeyHeld( CEKey key ) = 0;		// Is this key held down
};

class ceIInputDevice
{
public:
						ceIInputDevice( void ) {}
	virtual				~ceIInputDevice( void ) {}

	virtual void		AddRef( void ) = 0;
	virtual void		Release( void ) = 0;

	/// Updates the input for all devices
	virtual bool		Update( void ) = 0;

	/// Get the keyboard's device
	virtual ceIKeyboardDevice*	GetKeyboardDevice( void ) = 0;

	/// Get the mouse's device
	virtual ceIMouseDevice*		GetMouseDevice( void ) = 0;
};

#endif