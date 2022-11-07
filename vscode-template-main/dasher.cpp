#include "raylib.h"

int main(int argc, char const *argv[])
{
  //  Game Window Dimensions
  const int windowWidth{960};
  const int windowHeight{540};

  // Initialize the Game Window 
  InitWindow(windowWidth, windowHeight, "Dashy Dash");

  // Rectangle Dimensions (player)
  const int width{50};
  const int height{80};

  //  y-pos for Rectangle (be placed on "ground")  must minus height from char bc total dimension of window is full pix of 540
  int posY{windowHeight - height};
  // to fly upward must go in the negative direction from og start point
  int velocity{0}; 

  // Game Variables
  SetTargetFPS(60);

  // WindowShouldClose() is a 'raylib' predefined function
  while (!WindowShouldClose())
    {
      // Game Logic Begins
      BeginDrawing();
      
      ClearBackground(WHITE);

      

      if (IsKeyPressed(KEY_SPACE))
      {
        velocity -= 10;
        
      }
      

      posY += velocity;
      DrawRectangle(windowWidth/2, posY, width, height, BLUE);
      

      EndDrawing();
      // Game Logic Ends
    }

  // Raylib function to ensure window closes properly
  CloseWindow();

}
