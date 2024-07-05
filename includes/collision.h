#ifndef COLLISION_H_
#define COLLISION_H_

#include <raylib.h>

bool collision_rect_to_rect(float x_a, float y_a, int w_a, int h_a, float x_b,
                       float y_b, int w_b, int h_b);

bool collision_sphere_to_box(float s_x, float s_y, float s_r, float b_x, float b_y, float b_w, float b_h);

#endif // !COLLISION_H_
