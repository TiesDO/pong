#include "math.h"
#include "raylib.h"
#include "time.h"
#include "stdlib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define STD_MOVE_SPEED (5)

#define WINDOW_TITLE "My Pong"


typedef struct Paddle {
  float pos_x;
  float pos_y;
  int height;
  int move_spd;
} t_paddle;

typedef struct Ball {
  float pos_x;
  float pos_y;
  int speed;
  int size;
  Vector2 dir;
} t_ball;

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

void reset_ball(t_ball *b) {
  b->pos_x = (float)SCREEN_WIDTH / 2;
  b->pos_y = (float)SCREEN_HEIGHT / 2;
  b->speed = 5;
  b->size = 8;

  b->dir.x = ((rand() % 20) - 10);
  b->dir.y = (float)((rand() % 20) - 10) / 2;
}

void normalize_vec_2(Vector2 *v) {
  float f = (float)1 / sqrtf(v->y * v->y + v->x * v->x);
  v->y *= f;
  v->x *= f;
}

void init_ball(t_ball *b) { reset_ball(b); }

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

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

	// setup random seed
	srand(time(NULL));

  t_paddle player, opponent;
  t_ball ball;

  init_player(&player);
  init_opponent(&opponent);
  init_ball(&ball);

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_ESCAPE)) {
      break;
    }

    process_player_movement(&player);
    process_ball_movement(&ball);

    // Drawing
    BeginDrawing();
    {
      ClearBackground(BLACK);
      draw_paddle(&player);
      draw_paddle(&opponent);
      DrawCircle(ball.pos_x, ball.pos_y, ball.size, WHITE);
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
