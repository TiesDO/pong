#ifndef ENITIES_H_
#define ENITIES_H_

#include <raylib.h>

// PADDLE

typedef struct Paddle {
  float pos_x;
  float pos_y;
  int height;
  int move_spd;
} t_paddle;

void init_player(t_paddle *p);
void init_opponent(t_paddle *p);
void process_player_movement(t_paddle *p);
void draw_paddle(t_paddle *p);

// BALL

typedef struct Ball {
  float pos_x;
  float pos_y;
  int speed;
  int size;
  Vector2 dir;
} t_ball;

void init_ball(t_ball *b);
void reset_ball(t_ball *b);
void process_ball_movement(t_ball *b);
void handle_ball_collision(t_ball *b, t_paddle *p);

#endif // !ENITIES_H_
