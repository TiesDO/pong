#include "entities.h"
#include "helpers.h"

void init_player(t_paddle *p) {
  p->pos_x = 20;
  p->pos_y = 200;
  p->height = 60;
  p->move_spd = STD_MOVE_SPEED;
}

void init_opponent(t_paddle *p) {
  p->pos_x = SCREEN_WIDTH - 20;
  p->pos_y = 200;
  p->height = 60;
  p->move_spd = STD_MOVE_SPEED;
}

void draw_paddle(t_paddle *p) {
  DrawRectangle(p->pos_x, p->pos_y, 10, p->height, WHITE);
}

void process_player_movement(t_paddle *p) {
  bool key_up = IsKeyDown(KEY_UP);
  bool key_down = IsKeyDown(KEY_DOWN);

  if (key_up && key_down) {
    return;
  } else if (key_up) {
    if (p->pos_y - p->move_spd < 0) {
      p->pos_y = 0;
    } else {
      p->pos_y -= p->move_spd;
    }
  } else if (key_down) {
    if (p->pos_y + p->height + p->move_spd > SCREEN_HEIGHT) {
      p->pos_y = SCREEN_HEIGHT - p->height;
    } else {
      p->pos_y += p->move_spd;
    }
  }
}
