#include "raylib.h"

int main(int argc, char const *argv[])
{
  //  Game Window Dimensions
  const int window_width{960};
  const int window_height{540};

  // Initialize the Game Window 
  InitWindow(window_width, window_height, "Dashy Dash");

  // Game Variables
  SetTargetFPS(60);

  // WindowShouldClose() is a 'raylib' predefined function
  while (!WindowShouldClose())
    {
      // Game Logic Begins
      BeginDrawing();
      
      ClearBackground(WHITE);
      
      
      EndDrawing();
      // Game Logic Ends
    }

  // Raylib function to ensure window closes properly
  CloseWindow();

}
