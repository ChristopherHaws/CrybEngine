#ifndef CE_DEBUG_H
#define CE_DEBUG_H

#define CE_EXCEPTION( ErrorDescription, ErrorLevel ) printf( "ERROR!\n File: %s\n Line: %i\n %s\n", __FILE__, __LINE__, (ErrorDescription).c_str() );
#define CE_ASSERT( exp )
#endif