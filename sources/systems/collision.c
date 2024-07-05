#include "collision.h"

bool aabb_rect_to_rect(float x_a, float y_a, int w_a, int h_a, float x_b,
                       float y_b, int w_b, int h_b) {
  float min_x_a = x_a;
  float max_x_a = x_a + w_a;
  float min_y_a = y_a;
  float max_y_a = y_a + h_a;

  float min_x_b = x_b;
  float max_x_b = x_b + w_b;
  float min_y_b = y_b;
  float max_y_b = y_b + h_b;

  return (min_x_a <= max_x_b && max_x_a >= min_x_b && min_y_a <= max_y_b &&
          max_y_a >= min_y_b);
}
