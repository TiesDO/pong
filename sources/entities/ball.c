#include "collision.h"
#include "entities.h"
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

void reset_ball(t_ball *b) {
  // b->pos_x = (float)SCREEN_WIDTH / 2;
  // b->pos_y = (float)SCREEN_HEIGHT / 2;
	b->pos_x = 20;
	b->pos_y = 10;
  b->speed = 5;
  b->radius = 8;

  // b->dir.x = ((rand() % 20) - 10);
  // b->dir.y = (float)((rand() % 20) - 10) / 2;
	b->dir.x = 0;
	b->dir.y = 1;
}

void init_ball(t_ball *b) { reset_ball(b); }

void process_ball_movement(t_ball *b) {
  if (b->pos_x < 0 - b->radius || b->pos_x > SCREEN_WIDTH + b->radius) {
    // TODO: implement scoring a point
    reset_ball(b);
  } else {
    // check upper and lower bound collision
    if (b->pos_y - b->radius < 0 || b->pos_y + b->radius > SCREEN_HEIGHT) {
      b->dir.y *= -1;
    }

    normalize_vec_2(&b->dir);

    // update movement
    b->pos_x += b->dir.x * b->speed;
    b->pos_y += b->dir.y * b->speed;
  }
}

void handle_ball_collision(t_ball *b, t_paddle *p) {
  sphere_box_collision_t c = collision_sphere_to_box(
      b->pos_x, b->pos_y, b->radius, p->pos_x, p->pos_y, 10, p->height);

	// if the ball is somehow inside, pop it back to it's previous position

	if (c.distance > b->radius) { return; }

  // flip x
  if (b->pos_x < p->pos_x || b->pos_x > p->pos_x + 10) {
		// 
		if (c.projected_x >= p->pos_x + 10) {
			b->pos_x = c.projected_x + b->radius;
		} else {
			b->pos_x = c.projected_x - b->radius;
		}
    b->dir.x *= -1;
		// TODO: app spin to the ball
		// b->dir.y += p->vel.y;

	// flip y
  } else if (b->pos_y < p->pos_y || b->pos_y > p->pos_y + p->height) {
		if (c.projected_y >= p->pos_y + p->height) {
			b->pos_y = c.projected_y + b->radius;
		} else {
			b->pos_y = c.projected_y - b->radius;
		}
    b->dir.y *= -1;
  }
}
