#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <math.h>
#include <string.h>
#include <time.h>

//

#define fn static inline void

#define out return

#define new_type typedef struct

#define type_ptr(type) typedef type *type;

//

#define VECTORS(TYPE)                                                          \
  new_type {                                                                   \
    union {                                                                    \
      TYPE x;                                                                  \
      TYPE r;                                                                  \
    };                                                                         \
    union {                                                                    \
      TYPE y;                                                                  \
      TYPE g;                                                                  \
    };                                                                         \
  }                                                                            \
  TYPE##2;                                                                     \
                                                                               \
  fn TYPE##2_clear(TYPE##2 * v) {                                              \
    v->x = 0;                                                                  \
    v->y = 0;                                                                  \
  }                                                                            \
                                                                               \
  fn TYPE##2_fill(TYPE##2 * v, TYPE val) {                                     \
    v->x = val;                                                                \
    v->y = val;                                                                \
  }                                                                            \
                                                                               \
  fn TYPE##2_add(TYPE##2 * v1, TYPE##2 * v2) {                                 \
    v1->x += v2->x;                                                            \
    v1->y += v2->y;                                                            \
  }                                                                            \
                                                                               \
  fn TYPE##2_sub(TYPE##2 * v1, TYPE##2 * v2) {                                 \
    v1->x -= v2->x;                                                            \
    v1->y -= v2->y;                                                            \
  }                                                                            \
                                                                               \
  fn TYPE##2_mul(TYPE##2 * v1, TYPE##2 * v2) {                                 \
    v1->x *= v2->x;                                                            \
    v1->y *= v2->y;                                                            \
  }                                                                            \
                                                                               \
  fn TYPE##2_div(TYPE##2 * v1, TYPE##2 * v2) {                                 \
    v1->x /= v2->x;                                                            \
    v1->y /= v2->y;                                                            \
  }                                                                            \
                                                                               \
  new_type {                                                                   \
    union {                                                                    \
      TYPE x;                                                                  \
      TYPE r;                                                                  \
    };                                                                         \
    union {                                                                    \
      TYPE y;                                                                  \
      TYPE g;                                                                  \
    };                                                                         \
    union {                                                                    \
      TYPE z;                                                                  \
      TYPE b;                                                                  \
    };                                                                         \
  }                                                                            \
  TYPE##3;                                                                     \
                                                                               \
  fn TYPE##3_clear(TYPE##3 * v) {                                              \
    v->x = 0;                                                                  \
    v->y = 0;                                                                  \
    v->z = 0;                                                                  \
  }                                                                            \
                                                                               \
  fn TYPE##3_fill(TYPE##3 * v, TYPE val) {                                     \
    v->x = val;                                                                \
    v->y = val;                                                                \
    v->z = val;                                                                \
  }                                                                            \
                                                                               \
  fn TYPE##3_add(TYPE##3 * v1, TYPE##3 * v2) {                                 \
    v1->x += v2->x;                                                            \
    v1->y += v2->y;                                                            \
    v1->z += v2->z;                                                            \
  }                                                                            \
                                                                               \
  fn TYPE##3_sub(TYPE##3 * v1, TYPE##3 * v2) {                                 \
    v1->x -= v2->x;                                                            \
    v1->y -= v2->y;                                                            \
    v1->z -= v2->z;                                                            \
  }                                                                            \
                                                                               \
  fn TYPE##3_mul(TYPE##3 * v1, TYPE##3 * v2) {                                 \
    v1->x *= v2->x;                                                            \
    v1->y *= v2->y;                                                            \
    v1->z *= v2->z;                                                            \
  }                                                                            \
                                                                               \
  fn TYPE##3_div(TYPE##3 * v1, TYPE##3 * v2) {                                 \
    v1->x /= v2->x;                                                            \
    v1->y /= v2->y;                                                            \
    v1->z /= v2->z;                                                            \
  }                                                                            \
                                                                               \
  new_type {                                                                   \
    union {                                                                    \
      TYPE x;                                                                  \
      TYPE r;                                                                  \
    };                                                                         \
    union {                                                                    \
      TYPE y;                                                                  \
      TYPE g;                                                                  \
    };                                                                         \
    union {                                                                    \
      TYPE z;                                                                  \
      TYPE b;                                                                  \
    };                                                                         \
    union {                                                                    \
      TYPE w;                                                                  \
      TYPE a;                                                                  \
    };                                                                         \
  }                                                                            \
  TYPE##4;                                                                     \
                                                                               \
  fn TYPE##4_clear(TYPE##4 * v) {                                              \
    v->x = 0;                                                                  \
    v->y = 0;                                                                  \
    v->z = 0;                                                                  \
    v->w = 0;                                                                  \
  }                                                                            \
                                                                               \
  fn TYPE##4_fill(TYPE##4 * v, TYPE val) {                                     \
    v->x = val;                                                                \
    v->y = val;                                                                \
    v->z = val;                                                                \
    v->w = val;                                                                \
  }                                                                            \
                                                                               \
  fn TYPE##4_add(TYPE##4 * v1, TYPE##4 * v2) {                                 \
    v1->x += v2->x;                                                            \
    v1->y += v2->y;                                                            \
    v1->z += v2->z;                                                            \
    v1->w += v2->w;                                                            \
  }                                                                            \
                                                                               \
  fn TYPE##4_sub(TYPE##4 * v1, TYPE##4 * v2) {                                 \
    v1->x -= v2->x;                                                            \
    v1->y -= v2->y;                                                            \
    v1->z -= v2->z;                                                            \
    v1->w -= v2->w;                                                            \
  }                                                                            \
                                                                               \
  fn TYPE##4_mul(TYPE##4 * v1, TYPE##4 * v2) {                                 \
    v1->x *= v2->x;                                                            \
    v1->y *= v2->y;                                                            \
    v1->z *= v2->z;                                                            \
    v1->w *= v2->w;                                                            \
  }                                                                            \
                                                                               \
  fn TYPE##4_div(TYPE##4 * v1, TYPE##4 * v2) {                                 \
    v1->x /= v2->x;                                                            \
    v1->y /= v2->y;                                                            \
    v1->z /= v2->z;                                                            \
    v1->w /= v2->w;                                                            \
  }

//

#undef F
typedef float _Float;
#define F _Float

#define V F
VECTORS(V);
#undef V

typedef struct {
  V2 v1, v2;
} M2;

typedef struct {
  V3 v1, v2, v3;
} M3;

typedef struct {
  V4 v1, v2, v3, v4;
} M4;

F V3_dot(V3 *v1, V3 *v2) { out v1->x * v2->x + v1->y * v2->y + v1->z * v2->z; }

F V3_n2(V3 *v) { out V3_dot(v, v); }

fn V3_norm(V3 *v) {
  F n = V3_n2(v);

  if (n == 0.0f) {
    V3_clear(v);
    out;
  }

  n = sqrtf(n);

  v->x *= 1.0f / n;
  v->y *= 1.0f / n;
  v->z *= 1.0f / n;
}

fn V3_cross(V3 *v1, V3 *v2) {
  V3 tv1 = *v1;
  v1->x = tv1.y * v2->z - tv1.z * v2->y;
  v1->y = tv1.z * v2->x - tv1.x * v2->z;
  v1->z = tv1.x * v2->y - tv1.y * v2->x;
}

M4 perspective(F fov, F aspect, F near, M4 *dest) {
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

  F range = tanf(fov / 2.0f) * near;

  dest->v1.x = near / (range * aspect);
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

M4 lookat(V3 *eye, V3 *look, V3 *up, M4 *dest) {
  V3 f = *look;
  V3_sub(&f, eye);
  V3_norm(&f);
  V3 s = f;
  V3_cross(&s, up);
  V3_norm(&s);
  V3 u = s;
  V3_cross(&u, &f);

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

  dest->v4.x = -V3_dot(&s, eye);
  dest->v4.y = -V3_dot(&u, eye);
  dest->v4.z = V3_dot(&f, eye);
  dest->v4.w = 1;
}

//

#undef I
typedef signed int _Int;
#define I _Int

VECTORS(I);

//

#undef U
typedef unsigned int _Uint;
#define U _Uint

VECTORS(U);

//

#undef B
typedef unsigned char _Byte;
#define B _Byte

VECTORS(B);

//

#undef $
typedef char *_String;
#define $ _String

//

#define CAT_LINE_SET(a, line) a##_##line
#define CAT_LINE(a, line) CAT_LINE_SET(a, line)
#define VAR_LINE(name) CAT_LINE(name, __LINE__)

// from v to n
#define to(v, n) for (typeof(n) v = 0; v < n; ++v)

// repeat n times
#define rep(n)                                                                 \
  for (uint VAR_LINE(LOOP) = 0; VAR_LINE(LOOP) < n; ++VAR_LINE(LOOP))

// loop forever
#define loop while (1)

// stop the loop
#define stop break

// print string with optional arguments
#define print(s...) printf(s)

#define null NULL

#define new(type) calloc(1, sizeof(type))
#define new_n(type, n) calloc(n, sizeof(type))

//

fn strrem(char *str, char char_to_remove) {
  I i, j;
  I len = strlen(str);
  for (i = 0; i < len; i++) {
    if (str[i] == char_to_remove) {
      for (j = i; j < len; j++) {
        str[j] = str[j + 1];
      }
      len--;
      i--;
    }
  }
}

struct timespec time_delta(struct timespec t1, struct timespec t2) {
  struct timespec td;
  td.tv_nsec = t2.tv_nsec - t1.tv_nsec;
  td.tv_sec = t2.tv_sec - t1.tv_sec;
  if (td.tv_sec > 0 && td.tv_nsec < 0) {
    td.tv_nsec += 1e9;
    td.tv_sec--;
  } else if (td.tv_sec < 0 && td.tv_nsec > 0) {
    td.tv_nsec -= 1e9;
    td.tv_sec++;
  }
  return td;
}

fn sleep(U ms) {
  struct timespec ts;
  I s;

  ts.tv_sec = ms / 1000;
  ts.tv_nsec = (ms % 1000) * 1000000;

  do {
    s = nanosleep(&ts, &ts);
  } while (s);
}