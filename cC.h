#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

#include <string.h>
#include <math.h>
#include <ctype.h>

//

#ifndef byte
typedef unsigned char _byte;
	#define byte _byte
#endif

#ifndef num
typedef signed short _num;
	#define num _num
#endif

#ifndef unum
typedef unsigned short _unum;
	#define unum _unum
#endif

#ifndef uint
typedef unsigned int _uint;
	#define uint _uint
#endif

#ifndef str
typedef char* _str;
	#define str _str
#endif

//

#define CAT_LINE_SET( a, line ) a##_##line
#define CAT_LINE( a, line ) CAT_LINE_SET( a, line )
#define VAR_LINE( name ) CAT_LINE( name, __LINE__ )

// from v to n
#define to( v, n ) for( typeof( n ) v = 0; v < n; ++v )

// repeat n times
#define rep( n ) for( uint VAR_LINE( LOOP ) = 0; VAR_LINE( LOOP ) < n; ++VAR_LINE( LOOP ) )

// loop forever
#define loop while( true )

// stop the loop
#define stop break

// print string with optional arguments
#define print( s... ) printf( s )

#define null NULL

#define fn void

#define new( type ) calloc( 1, sizeof( type##_struct ) )
#define new_n( type, n ) calloc( n, sizeof( type##_struct ) )