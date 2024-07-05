#ifndef COLLISION_H_
#define COLLISION_H_

#include <raylib.h>

bool aabb_rect_to_rect(float x_a, float y_a, int w_a, int h_a, float x_b,
                       float y_b, int w_b, int h_b);

#endif // !COLLISION_H_
