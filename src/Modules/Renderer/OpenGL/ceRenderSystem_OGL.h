#ifndef CE_RENDER_SYSTEM_OGL_H
#define CE_RENDER_SYSTEM_OGL_H

#include <ceConfig.h>
#include <Modules/Renderer/ceIRenderSystem.h>

class ceRenderSystemOGL : public ceIRenderSystem
{
public:
						ceRenderSystemOGL( void ) {}
	virtual				~ceRenderSystemOGL( void ) {}

	ceIRenderDevice*	CreateDevice( void );
	void				RemoveDevice( ceIRenderDevice* pDevice );
	void				RemoveAllDevices( void );

	ceULong				GetVersion( void ) const { return ENGINE_VERSION; }

private:
	ceArray<ceIRenderDevice*> m_Devices;
};

#endif