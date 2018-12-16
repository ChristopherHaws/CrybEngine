#ifndef CE_RENDER_OBJECT_OGL_H
#define CE_RENDER_OBJECT_OGL_H

#include <ceConfig.h>
#include <Modules/Renderer/ceIRenderObject.h>

class ceVertexBufferOGL : public ceIVertexBuffer
{
public:
			ceVertexBufferOGL( void ) {}
			~ceVertexBufferOGL( void ) {}

	/// This creates a vertex buffer for a static object (nonchanging)
	void	CreateStatic(	const cePrimitive Primitive,	ceVertexInformation& VertexInfo,
							const float* pVertices,			const ceUInt uiNumberOfVertices );
	
	/// This creates a vertex buffer for a dynamic object (changing)
	void	CreateDynamic(	const cePrimitive Primitive,	ceVertexInformation& VertexInfo,
							const float* pVertices,			const ceUInt uiNumberOfVertices );

	/// Deletes this Vertex Buffer
	void	Release( void );

	/// Locks the buffer to allow for writing. Returns a poceInter to the memory address.
	void*	Lock( void );

	/// Unlocks the buffer so it can be read again by the renderer.
	void	Unlock( void );

	/// Returnes the number of vertices
	ceUInt	GetNumberOfVertices( void );

	/// Returnes the type of RenderObject this vertex buffer is.
	ceRenderObjectType	GetType( void );
};

class ceIndexBufferOGL : public ceIIndexBuffer
{
public:
			ceIndexBufferOGL( void ) {}
			~ceIndexBufferOGL( void ) {}

	/// This creates an index buffer
	void	Create(	const cePrimitive Primitive,	bool bDynamic,
					ceUInt uiNumberOfIndices,		const ceUInt16* pIndices );

	/// Deletes this Vertex Buffer
	void	Release( void );

	/// Locks the buffer to allow for writing. Returns a poceInter to the memory address.
	void*	Lock( void );

	/// Unlocks the buffer so it can be read again by the renderer.
	void	Unlock( void );

	/// Returnes the number of vertices
	ceUInt	GetNumberOfIndices( void );

	/// Returnes the type of RenderObject this vertex buffer is.
	ceRenderObjectType	GetType( void );
};

#endif