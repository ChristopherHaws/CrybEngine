#include <stdlib.h>
#include <stdio.h>

#include <Modules/ceModuleLoader.h>

// Renderer
#include <Modules/Renderer/ceIRenderSystem.h>
#include <Modules/Renderer/ceIRenderDevice.h>
#include <Modules/Renderer/ceWindowProperties.h>

// Input
#include <Modules/Input/ceIInputSystem.h>
#include <Modules/Input/ceIInputDevice.h>

// Math
#include <Math/ceMatrix.h>
#include <Math/ceVector3.h>
#include <Math/ceQuaternion.h>

// Image
#include <Modules/Image/ceImageTypes.h>
#include <Modules/Image/ceIImageManager.h>

// Camera
#include <Camera/ceFirstPersonCamera.h>

// Variable Types
#include <ceTypes.h>

ceInt main( ceInt argc, char *argv[] )
{
	ceIRenderSystem *pRenderSystem = NULL;
	ceIInputSystem *pInputSystem = NULL;
	ceIImageSystem *pImageSystem = NULL;

	LoadModule( "ceRenderOpenGL.dll", "OpenGL Renderer" );
	LoadModule( "ceInputSDL.dll", "SDL Input" );
	LoadModule( "ceImageSDL.dll", "SDL Image" );

	LoadSystem( "OpenGL Renderer", (ceIBaseSystem**) &pRenderSystem );
	LoadSystem( "SDL Input", (ceIBaseSystem**) &pInputSystem );
	LoadSystem( "SDL Image", (ceIBaseSystem**) &pImageSystem );

	ceIRenderDevice *pRenderDevice = pRenderSystem->CreateDevice();
	ceIInputDevice *pInputDevice = pInputSystem->GetDevice();
	ceIImageDevice *pImageDevice = pImageSystem->GetDevice();

	ceIKeyboardDevice *pKeyboard = pInputDevice->GetKeyboardDevice();
	ceIMouseDevice *pMouse = pInputDevice->GetMouseDevice();

	ceWindowProperties pWindow;
	pWindow.m_uiXPosition = 100;
	pWindow.m_uiYPosition = 100;
	pWindow.m_uiWidth = 640;
	pWindow.m_uiHeight = 460;
	pWindow.m_uiColorBuffer = 32;
	pWindow.m_uiStencilBuffer = 32;
	pWindow.m_uiDepthBuffer = 32;
	pWindow.m_bFullscreen = false;
	pWindow.m_bAntiAliasing = false;
	pWindow.m_bVSync = false;
	pWindow.m_b3D = false;
	pWindow.m_sTitle = "CRYB Application";

	pRenderDevice->Create();
	pRenderDevice->CreateNewWindow( &pWindow );

	ceReal32 i = 5.0f;
	while( pInputDevice->Update() && !pKeyboard->KeyPressed( CEK_ESCAPE ) )
	{
		if( pKeyboard->KeyPressed( CEK_h ) ) printf( "h Pressed!\n" );
		if( pKeyboard->KeyHeld( CEK_g ) ) printf( "g Held!\n" );
		if( pMouse->ButtonHeld( 1 ) )
		{
			i = i + 0.03f;
			printf( "Left Mouse Button Pressed at ( %i, %i )!\n", pMouse->GetPositionX(), pMouse->GetPositionY() );
		}
		if( pMouse->ButtonHeld( 3 ) )
		{
			i = i - 0.03f;
			printf( "Right Mouse Button Pressed at ( %i, %i )!\n", pMouse->GetPositionX(), pMouse->GetPositionY() );
		}
		//printf( "( %i, %i )\n", pInputDevice->GetMouseState().x, pInputDevice->GetMouseState().y );
		//if( pInputDevice->GetMouseState().buttons[1] == 1 ) printf( "BUTTON!\n" );

		pRenderDevice->BeginFrame();
		pRenderDevice->ClearBuffers( );

		pRenderDevice->DrawTriangle(	ceVector3( 10.0f, 10.0f, 0.0f ),
										ceVector3( 50.0f, 0.0f, 0.0f ),
										ceVector3( 0.0f, 50.0f, 0.0f ) );

		pRenderDevice->EndFrame();
		pRenderDevice->Update();
	}

	return 0;
}