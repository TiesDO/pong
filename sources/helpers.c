#include "helpers.h"
#include <math.h>

void normalize_vec_2(Vector2 *v) {
  float f = (float)1 / sqrtf(v->y * v->y + v->x * v->x);
  v->y *= f;
  v->x *= f;
}
