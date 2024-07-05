#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "collision.h"
#include "entities.h"
#include "helpers.h"

#define WINDOW_TITLE "My Pong"

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
