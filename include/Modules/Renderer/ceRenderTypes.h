#ifndef CE_RENDER_TYPES_H
#define CE_RENDER_TYPES_H

#include <ceConfig.h>

typedef enum ceEVertexAttribSize
{
	CE_RS_VT_FLOAT1,
	CE_RS_VT_FLOAT2,
	CE_RS_VT_FLOAT3,
	CE_RS_VT_FLOAT4,
	CE_RS_VT_UBYTE4,
	CE_RS_VT_SHORT2,
	CE_RS_VT_SHORT4
} ceVertexAttributeSize;

typedef enum ceEVertexUsage
{
	CE_RS_VU_TEXCOORD0=0,
	CE_RS_VU_TEXCOORD1,
	CE_RS_VU_TEXCOORD2,
	CE_RS_VU_TEXCOORD3,
	CE_RS_VU_TEXCOORD4,
	CE_RS_VU_TEXCOORD5,
	CE_RS_VU_TEXCOORD6,
	CE_RS_VU_TEXCOORD7,
	CE_RS_VU_POSITION,		// This MUST have 2, 3 or 4 components! Else: Exception
	CE_RS_VU_NORMAL,		// This MUST have 3 components! Else: Exception
	CE_RS_VU_COLOR			// This MUST have 3 or 4 components! Else: Exception
} ceVertexUsage;

class ceVertexInfo
{
	ceVertexInfo( void ) {}
	~ceVertexInfo( void )
	{
		m_vOffsets.clear();
		m_vAttributeSizes.clear();
		m_vUsages.clear();
	}

	void Add( const ceUInt8 Offset, const ceVertexAttributeSize Size, const ceVertexUsage Usage )
	{
		m_vOffsets.push_back( Offset );
		m_vAttributeSizes.push_back( Size );
		m_vUsages.push_back( Usage );
	}

	ceInt8 GetOffset( const ceUInt ID ) const
	{
		if( ID < m_vOffsets.size() ) return m_vOffsets[ID];
		return -1;
	}

	ceInt8 GetAttributeSize( const ceUInt ID ) const
	{
		if( ID < m_vAttributeSizes.size() ) return m_vAttributeSizes[ID];
		return -1;
	}

	ceUInt8 GetOffsetsSize( void ) const
	{
		return m_vOffsets.size();
	}

	ceUInt8 GetVertexSize( void ) const
	{
		ceUInt uiReturnValue = 0;

		for( ceInt i = 0; i < m_vAttributeSizes.size(); i++ )
		{
			switch( m_vAttributeSizes[i] )
			{
			case CE_RS_VT_SHORT2:
				uiReturnValue += sizeof(ceInt16) * 2;
				break;
			case CE_RS_VT_SHORT4:
				uiReturnValue += sizeof(ceInt16) * 4;
				break;
			case CE_RS_VT_UBYTE4:
				uiReturnValue += sizeof(ceUInt8) * 4;
				break;
			case CE_RS_VT_FLOAT1:
				uiReturnValue += sizeof(float);
				break;
			case CE_RS_VT_FLOAT2:
				uiReturnValue += sizeof(float) * 2;
				break;
			case CE_RS_VT_FLOAT3:
				uiReturnValue += sizeof(float) * 3;
				break;
			case CE_RS_VT_FLOAT4:
				uiReturnValue += sizeof(float) * 4;
				break;
			}
		}

		return uiReturnValue;
	}

private:
	ceArray<ceUInt8> m_vOffsets;
	ceArray<ceVertexAttributeSize> m_vAttributeSizes;
	ceArray<ceVertexUsage> m_vUsages;
};

#endif