#include "collision.h"
#include "entities.h"
#include "helpers.h"
#include <stdlib.h>

void reset_ball(t_ball *b) {
  b->pos_x = (float)SCREEN_WIDTH / 2;
  b->pos_y = (float)SCREEN_HEIGHT / 2;
  b->speed = 5;
  b->size = 8;

  b->dir.x = ((rand() % 20) - 10);
  b->dir.y = (float)((rand() % 20) - 10) / 2;
}

void init_ball(t_ball *b) { reset_ball(b); }

void process_ball_movement(t_ball *b) {
  if (b->pos_x < 0 - b->size || b->pos_x > SCREEN_WIDTH + b->size) {
    // TODO: implement scoring a point
    reset_ball(b);
  } else {
    // check upper and lower bound collision
    if (b->pos_y - b->size < 0 || b->pos_y + b->size > SCREEN_HEIGHT) {
      b->dir.y *= -1;
    }

    normalize_vec_2(&b->dir);

    // update movement
    b->pos_x += b->dir.x * b->speed;
    b->pos_y += b->dir.y * b->speed;
  }
}

void handle_ball_collision(t_ball *b, t_paddle *p) {
	// TODO: return the collision point and use it to determine better collide
  if (!collision_sphere_to_box(b->pos_x, b->pos_y, b->size, p->pos_x, p->pos_y,
                               10, p->height)) {
    return;
  }

	// flip x
	if (b->pos_x < p->pos_x || b->pos_x > p->pos_x + 10) {
		b->dir.x *= -1;
	} else if (b->pos_y < p->pos_y || b->pos_y > p->pos_y + p->height) {
		b->dir.y *= -1;
	} 

}
