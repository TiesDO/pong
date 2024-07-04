#include "raylib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "My Pong"

typedef struct Paddle {
  int pos_x;
  int pos_y;
  int height;
} t_paddle;

typedef struct Ball {
  int pos_x;
  int pos_y;
  int speed;
} t_ball;

void init_player(t_paddle *p) {
  p->pos_x = 20;
  p->pos_y = 200;
  p->height = 60;
}

void init_opponent(t_paddle *p) {
  p->pos_x = SCREEN_WIDTH - 20;
  p->pos_y = 200;
  p->height = 60;
}

void init_ball(t_ball *b) {
  b->pos_x = SCREEN_WIDTH / 2;
  b->pos_y = SCREEN_HEIGHT / 2;
}

void draw_paddle(t_paddle *p) {
  DrawRectangle(p->pos_x, p->pos_y, 10, p->height, WHITE);
}

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  t_paddle player, opponent;
  t_ball ball;

  init_player(&player);
  init_opponent(&opponent);
  init_ball(&ball);

  while (!WindowShouldClose()) {

    // Drawing
    BeginDrawing();
    {
      ClearBackground(BLACK);
      draw_paddle(&player);
      draw_paddle(&opponent);
      DrawCircle(ball.pos_x, ball.pos_y, 15, WHITE);
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
