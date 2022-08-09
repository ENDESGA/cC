#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

#include <setjmp.h>
#include <string.h>
#include <ctype.h>

//

#ifndef byte
typedef unsigned char _byte;
	#define byte _byte
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

// function arguments
#define args( type ) type ARGS, ...
#define args_start \
	va_list ARGS_VA; \
	va_start( ARGS_VA, ARGS )
#define args_loop \
	args_start;     \
	loop
#define args_end va_end( ARGS_VA )
#define args_stop \
	args_end;       \
	stop
#define args_next va_arg( ARGS_VA, typeof( ARGS ) )

//

void print_args_string( args( char* ) )
{
	args_loop
	{
		char* cp = args_next;
		if( cp != NULL ) printf( "%s", cp );
		else
			args_stop;
	}
}
#define print( a... ) print_args_string( "", a, NULL )

void print_args_string_n( args( char* ) )
{
	args_loop
	{
		char* cp = args_next;
		if( cp != NULL ) printf( "%s\n", cp );
		else
			args_stop;
	}
}
#define printn( a... ) print_args_string_n( "", a, NULL )

str _to_str_TEMP = "";
str to_str( int i )
{
	sprintf( _to_str_TEMP, "%i", i );
	return _to_str_TEMP;
}