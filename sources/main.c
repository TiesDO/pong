#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "entities.h"
#include "helpers.h"

#define WINDOW_TITLE "My Pong"

// TODO:
// - implement scoring
// - implement enemy ai
// - implement spin
// - implement powerups (speed, slow, net)
// - mess around with shaders

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  // setup random seed
  srand(time(NULL));

  t_paddle player, opponent;
  t_ball ball;

	int player_score = 0;
	int opponent_score = 0;

  init_player(&player);
  init_opponent(&opponent);
  init_ball(&ball);

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_ESCAPE)) {
      break;
    }

    process_player_movement(&player);

    if (process_ball_movement(&ball)) {
			if (ball.pos_x <= 0) {
				opponent_score++;
			} else {
				player_score++;
			}
			reset_ball(&ball);
		}

		handle_ball_collision(&ball, &player);
		handle_ball_collision(&ball, &opponent);

    // Drawing
    BeginDrawing();
    {
      ClearBackground(BLACK);

			// Score
			const char* text = TextFormat("%d | %d", player_score, opponent_score);
			int offset = MeasureText(text, 20) / 2;
			DrawText(text, SCREEN_WIDTH / 2 - offset, 30, 20, WHITE);

			// Entities
      draw_paddle(&player);
      draw_paddle(&opponent);
      DrawCircle(ball.pos_x, ball.pos_y, ball.radius, WHITE);
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
