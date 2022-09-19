#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <math.h>
#include <string.h>
#include <time.h>

//

#undef V
typedef void _Void;
#define V _Void

#define FN static inline __attribute( ( always_inline ) )

#define OUT return

//

#define VECTORS( TYPE )                                \
	typedef union                                        \
	{                                                    \
			struct                                           \
			{                                                \
					TYPE x;                                      \
					TYPE y;                                      \
			};                                               \
			struct                                           \
			{                                                \
					TYPE r;                                      \
					TYPE g;                                      \
			};                                               \
	} TYPE##2;                                           \
                                                       \
	FN TYPE##2 TYPE##2_clear( TYPE##2 * v )              \
	{                                                    \
		v->x = 0;                                          \
		v->y = 0;                                          \
	}                                                    \
                                                       \
	FN TYPE##2 TYPE##2_fill( TYPE##2 * v, TYPE val )     \
	{                                                    \
		v->x = val;                                        \
		v->y = val;                                        \
	}                                                    \
                                                       \
	FN TYPE##2 TYPE##2_add( TYPE##2 * v1, TYPE##2 * v2 ) \
	{                                                    \
		v1->x += v2->x;                                    \
		v1->y += v2->y;                                    \
	}                                                    \
                                                       \
	FN TYPE##2 TYPE##2_sub( TYPE##2 * v1, TYPE##2 * v2 ) \
	{                                                    \
		v1->x -= v2->x;                                    \
		v1->y -= v2->y;                                    \
	}                                                    \
                                                       \
	FN TYPE##2 TYPE##2_mul( TYPE##2 * v1, TYPE##2 * v2 ) \
	{                                                    \
		v1->x *= v2->x;                                    \
		v1->y *= v2->y;                                    \
	}                                                    \
                                                       \
	FN TYPE##2 TYPE##2_div( TYPE##2 * v1, TYPE##2 * v2 ) \
	{                                                    \
		v1->x /= v2->x;                                    \
		v1->y /= v2->y;                                    \
	}                                                    \
                                                       \
	typedef union                                        \
	{                                                    \
			struct                                           \
			{                                                \
					TYPE x;                                      \
					TYPE y;                                      \
					TYPE z;                                      \
			};                                               \
			struct                                           \
			{                                                \
					TYPE r;                                      \
					TYPE g;                                      \
					TYPE b;                                      \
			};                                               \
	} TYPE##3;                                           \
                                                       \
	FN TYPE##3 TYPE##3_clear( TYPE##3 * v )              \
	{                                                    \
		v->x = 0;                                          \
		v->y = 0;                                          \
		v->z = 0;                                          \
	}                                                    \
                                                       \
	FN TYPE##3 TYPE##3_fill( TYPE##3 * v, TYPE val )     \
	{                                                    \
		v->x = val;                                        \
		v->y = val;                                        \
		v->z = val;                                        \
	}                                                    \
                                                       \
	FN TYPE##3 TYPE##3_add( TYPE##3 * v1, TYPE##3 * v2 ) \
	{                                                    \
		v1->x += v2->x;                                    \
		v1->y += v2->y;                                    \
		v1->z += v2->z;                                    \
	}                                                    \
                                                       \
	FN TYPE##3 TYPE##3_sub( TYPE##3 * v1, TYPE##3 * v2 ) \
	{                                                    \
		v1->x -= v2->x;                                    \
		v1->y -= v2->y;                                    \
		v1->z -= v2->z;                                    \
	}                                                    \
                                                       \
	FN TYPE##3 TYPE##3_mul( TYPE##3 * v1, TYPE##3 * v2 ) \
	{                                                    \
		v1->x *= v2->x;                                    \
		v1->y *= v2->y;                                    \
		v1->z *= v2->z;                                    \
	}                                                    \
                                                       \
	FN TYPE##3 TYPE##3_div( TYPE##3 * v1, TYPE##3 * v2 ) \
	{                                                    \
		v1->x /= v2->x;                                    \
		v1->y /= v2->y;                                    \
		v1->z /= v2->z;                                    \
	}                                                    \
                                                       \
	typedef union                                        \
	{                                                    \
			struct                                           \
			{                                                \
					TYPE x;                                      \
					TYPE y;                                      \
					TYPE z;                                      \
					TYPE w;                                      \
			};                                               \
			struct                                           \
			{                                                \
					TYPE r;                                      \
					TYPE g;                                      \
					TYPE b;                                      \
					TYPE a;                                      \
			};                                               \
	} TYPE##4;                                           \
                                                       \
	FN TYPE##4 TYPE##4_clear( TYPE##4 * v )              \
	{                                                    \
		v->x = 0;                                          \
		v->y = 0;                                          \
		v->z = 0;                                          \
		v->w = 0;                                          \
	}                                                    \
                                                       \
	FN TYPE##4 TYPE##4_fill( TYPE##4 * v, TYPE val )     \
	{                                                    \
		v->x = val;                                        \
		v->y = val;                                        \
		v->z = val;                                        \
		v->w = val;                                        \
	}                                                    \
                                                       \
	FN TYPE##4 TYPE##4_add( TYPE##4 * v1, TYPE##4 * v2 ) \
	{                                                    \
		v1->x += v2->x;                                    \
		v1->y += v2->y;                                    \
		v1->z += v2->z;                                    \
		v1->w += v2->w;                                    \
	}                                                    \
                                                       \
	FN TYPE##4 TYPE##4_sub( TYPE##4 * v1, TYPE##4 * v2 ) \
	{                                                    \
		v1->x -= v2->x;                                    \
		v1->y -= v2->y;                                    \
		v1->z -= v2->z;                                    \
		v1->w -= v2->w;                                    \
	}                                                    \
                                                       \
	FN TYPE##4 TYPE##4_mul( TYPE##4 * v1, TYPE##4 * v2 ) \
	{                                                    \
		v1->x *= v2->x;                                    \
		v1->y *= v2->y;                                    \
		v1->z *= v2->z;                                    \
		v1->w *= v2->w;                                    \
	}                                                    \
                                                       \
	FN TYPE##4 TYPE##4_div( TYPE##4 * v1, TYPE##4 * v2 ) \
	{                                                    \
		v1->x /= v2->x;                                    \
		v1->y /= v2->y;                                    \
		v1->z /= v2->z;                                    \
		v1->w /= v2->w;                                    \
	}

//

#undef F
typedef float _Float;
#define F _Float

VECTORS( F );

typedef struct
{
		F2 v1, v2;
} V2;

typedef struct
{
		F3 v1, v2, v3;
} V3;

typedef struct
{
		F4 v1, v2, v3, v4;
} V4;

FN F F3_dot( F3* v1, F3* v2 )
{
	OUT v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

FN F F3_n2( F3* v )
{
	OUT F3_dot( v, v );
}

FN V F3_norm( F3* v )
{
	F n = F3_n2( v );

	if( n == 0.0f )
	{
		F3_clear( v );
		OUT;
	}

	n = sqrtf( n );

	v->x *= 1.0f / n;
	v->y *= 1.0f / n;
	v->z *= 1.0f / n;
}

FN V F3_cross( F3* v1, F3* v2 )
{
	F3 tv1 = *v1;
	v1->x = tv1.y * v2->z - tv1.z * v2->y;
	v1->y = tv1.z * v2->x - tv1.x * v2->z;
	v1->z = tv1.x * v2->y - tv1.y * v2->x;
}

V4 perspective( F fov, F aspect, F near, V4* dest )
{
	// finite:
	// (requires "F far" param)

	/*F f, ff;

	F4_clear( &dest->v1 );
	F4_clear( &dest->v2 );
	F4_clear( &dest->v3 );
	F4_clear( &dest->v4 );

	f = 1.0f / tanf( fov * 0.5f );
	ff = 1.0f / ( near - far );

	dest->v1.x = f / aspect;
	dest->v2.y = f;
	dest->v3.z = ( near + far ) * ff;
	dest->v3.w = -1.0f;
	dest->v4.z = 2.0f * near * far * ff;*/

	// infinite:

	F range = tanf( fov / 2.0f ) * near;

	dest->v1.x = near / ( range * aspect );
	dest->v1.y = 0.0f;
	dest->v1.z = 0.0f;
	dest->v1.w = 0.0f;

	dest->v2.x = 0.0f;
	dest->v2.y = near / range;
	dest->v2.z = 0.0f;
	dest->v2.w = 0.0f;

	dest->v3.x = 0.0f;
	dest->v3.y = 0.0f;
	dest->v3.z = -1.0f;
	dest->v3.w = -1.0f;

	dest->v4.x = 0.0f;
	dest->v4.y = 0.0f;
	dest->v4.z = -near;
	dest->v4.w = 0.0f;
}

V4 lookat( F3* eye, F3* look, F3* up, V4* dest )
{
	F3 f = *look;
	F3_sub( &f, eye );
	F3_norm( &f );
	F3 s = f;
	F3_cross( &s, up );
	F3_norm( &s );
	F3 u = s;
	F3_cross( &u, &f );

	dest->v1.x = s.x;
	dest->v1.y = u.x;
	dest->v1.z = -f.x;
	dest->v1.w = 0;

	dest->v2.x = s.y;
	dest->v2.y = u.y;
	dest->v2.z = -f.y;
	dest->v1.w = 0;

	dest->v3.x = s.z;
	dest->v3.y = u.z;
	dest->v3.z = -f.z;
	dest->v1.w = 0;

	dest->v4.x = -F3_dot( &s, eye );
	dest->v4.y = -F3_dot( &u, eye );
	dest->v4.z = F3_dot( &f, eye );
	dest->v4.w = 1;
}

//

#undef I
typedef signed int _Int;
#define I _Int

VECTORS( I );

//

#undef U
typedef unsigned int _Uint;
#define U _Uint

VECTORS( U );

//

#undef B
typedef unsigned char _Byte;
#define B _Byte

VECTORS( B );

//

#undef $
typedef char* _String;
#define $ _String

//

#define CAT_LINE_SET( a, line ) a##_##line
#define CAT_LINE( a, line ) CAT_LINE_SET( a, line )
#define VAR_LINE( name ) CAT_LINE( name, __LINE__ )

// from v to n
#define to( v, n ) for( typeof( n ) v = 0; v < n; ++v )

// repeat n times
#define rep( n ) for( uint VAR_LINE( LOOP ) = 0; VAR_LINE( LOOP ) < n; ++VAR_LINE( LOOP ) )

// loop forever
#define loop while( 1 )

// stop the loop
#define stop break

// print string with optional arguments
#define print( s... ) printf( s )

#define null NULL

#define new( type ) calloc( 1, sizeof( type ) )
#define new_n( type, n ) calloc( n, sizeof( type ) )

//

FN V strrem( char* str, char char_to_remove )
{
	I i, j;
	I len = strlen( str );
	for( i = 0; i < len; i++ )
	{
		if( str[ i ] == char_to_remove )
		{
			for( j = i; j < len; j++ )
			{
				str[ j ] = str[ j + 1 ];
			}
			len--;
			i--;
		}
	}
}

FN struct timespec time_delta( struct timespec t1, struct timespec t2 )
{
	struct timespec td;
	td.tv_nsec = t2.tv_nsec - t1.tv_nsec;
	td.tv_sec = t2.tv_sec - t1.tv_sec;
	if( td.tv_sec > 0 && td.tv_nsec < 0 )
	{
		td.tv_nsec += 1e9;
		td.tv_sec--;
	} else if( td.tv_sec < 0 && td.tv_nsec > 0 )
	{
		td.tv_nsec -= 1e9;
		td.tv_sec++;
	}
	return td;
}

FN V sleep( U ms )
{
		struct timespec ts;
		I s;

		ts.tv_sec = ms / 1000;
		ts.tv_nsec = ( ms % 1000 ) * 1000000;

		do {
			s = nanosleep( &ts, &ts );
		} while( s );
}