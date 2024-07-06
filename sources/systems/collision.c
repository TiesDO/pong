#include "collision.h"
#include <math.h>
#include <stdio.h>

typedef struct MinMaxBox {
  float min_x;
  float max_x;
  float min_y;
  float max_y;
} t_min_max_box;

t_min_max_box min_max_box(float b_x, float b_y, int b_w, int b_h) {
  t_min_max_box b;

  b.min_x = b_x;
  b.max_x = b_x + b_w;
  b.min_y = b_y;
  b.max_y = b_y + b_h;

  return b;
}

bool collision_rect_to_rect(float a_x, float a_y, int a_w, int a_h, float b_x,
                            float b_y, int b_w, int b_h) {
  t_min_max_box a = min_max_box(a_x, a_y, a_w, a_h);
  t_min_max_box b = min_max_box(b_x, b_y, b_w, b_h);

  return (a.min_x <= b.max_x && a.max_x >= b.min_x && a.min_y <= b.max_y &&
          a.max_y >= b.min_y);
}

sphere_box_collision_t collision_sphere_to_box(float s_x, float s_y, float s_r,
                                               float b_x, float b_y, float b_w,
                                               float b_h) {
  t_min_max_box b = min_max_box(b_x, b_y, b_w, b_h);

  float c_x = fmax(b.min_x, fmin(s_x, b.max_x));
  float c_y = fmax(b.min_y, fmin(s_y, b.max_y));

  float d_x = s_x - c_x;
  float d_y = s_y - c_y;

  float d_m = sqrtf(d_x * d_x + d_y * d_y);

  return (sphere_box_collision_t){
      .distance = d_m,
      .projected_x = c_x,
      .projected_y = c_y,
  };
}
