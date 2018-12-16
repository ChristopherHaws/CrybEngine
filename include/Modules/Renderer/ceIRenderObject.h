#ifndef CE_I_RENDER_OBJECT_H
#define CE_I_RENDER_OBJECT_H

// This file contains the ceInterfaces for ceIRenderObject, ceIVertexBuffer, and ceIIndexBuffer

typedef enum ceERenderObjectType
{
	CE_RENDEROBJECT_VERTEX_BUFFER,
	CE_RENDEROBJECT_INDEX_BUFFER
} ceRenderObjectType;

typedef enum ceEPrimitive
{
	CE_PRIM_POceIntS,
	CE_PRIM_LINES,
	CE_PRIM_LINE_STRIP,
	CE_PRIM_TRIANGLES,
	CE_PRIM_TRIANGLE_STRIP,
	CE_PRIM_TRIANGLE_FAN
} cePrimitive;

class ceIRenderObject
{
public:
					ceIRenderObject( void ) {}
	virtual			~ceIRenderObject( void ) {}

	/// This deletes this render object
	virtual void	Release( void ) = 0;

	/// Get the type of object this is (ex. CE_RENDEROBJECT_VERTEX_BUFFER)
	virtual ceRenderObjectType	GetType( void ) = 0;
};

class ceIVertexBuffer : public ceIRenderObject
{
public:
					ceIVertexBuffer( void ) {}
	virtual			~ceIVertexBuffer( void ) {}

	/// This creates a vertex buffer for a static object (nonchanging)
	virtual void	CreateStatic(	const cePrimitive Primitive,	ceVertexInformation& VertexInfo,
									const float* pVertices,			const ceUInt uiNumberOfVertices ) = 0;
	
	/// This creates a vertex buffer for a dynamic object (changing)
	virtual void	CreateDynamic(	const cePrimitive Primitive,	ceVertexInformation& VertexInfo,
									const float* pVertices,			const ceUInt uiNumberOfVertices ) = 0;

	/// Deletes this Vertex Buffer
	virtual void	Release( void ) = 0;

	/// Locks the buffer to allow for writing. Returns a poceInter to the memory address.
	virtual void*	Lock( void ) = 0;

	/// Unlocks the buffer so it can be read again by the renderer.
	virtual void	Unlock( void ) = 0;

	/// Returnes the number of vertices
	virtual ceUInt	GetNumberOfVertices( void ) = 0;

	/// Returnes the type of RenderObject this vertex buffer is.
	virtual ceRenderObjectType	GetType( void ) = 0;
};

class ceIIndexBuffer : public ceIRenderObject
{
public:
					ceIIndexBuffer( void ) {}
	virtual			~ceIIndexBuffer( void ) {}

	/// This creates an index buffer
	virtual void	Create(	const cePrimitive Primitive,	bool bDynamic,
							ceUInt uiNumberOfIndices,		const ceUInt16* pIndices ) = 0;

	/// Deletes this Vertex Buffer
	virtual void	Release( void ) = 0;

	/// Locks the buffer to allow for writing. Returns a poceInter to the memory address.
	virtual void*	Lock( void ) = 0;

	/// Unlocks the buffer so it can be read again by the renderer.
	virtual void	Unlock( void ) = 0;

	/// Returnes the number of vertices
	virtual ceUInt	GetNumberOfIndices( void ) = 0;

	/// Returnes the type of RenderObject this vertex buffer is.
	virtual ceRenderObjectType	GetType( void ) = 0;
};

#endif