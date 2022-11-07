#include "raylib.h"

int main(int argc, char const *argv[])
{
  //  Game Window Dimensions
  const int windowWidth{960};
  const int windowHeight{540};

  // Initialize the Game Window 
  InitWindow(windowWidth, windowHeight, "Dashy Dash");

  // acceleration due to gravity (pixels/frame)/frame
  const int gravity{1};
  const int jumpVelo{-18};

  // Rectangle Dimensions (player)
  const int width{50};
  const int height{80};

  //  y-pos for Rectangle (be placed on "ground")  must minus height from char bc total dimension of window is full pix of 540
  int posY{windowHeight - height};
  // to fly upward must go in the negative direction from og start point THIS IS INTIALIZE  VELO
  int velocity{0}; 

  // Check to see if already in air.
  bool isInAir{false};

  // Game Variables
  SetTargetFPS(60);

  // WindowShouldClose() is a 'raylib' predefined function
  while (!WindowShouldClose())
    {
      // Game Logic Begins
      BeginDrawing();
      
      ClearBackground(WHITE);


      // ground check
      if (posY >= windowHeight - height)
      {
        /* Rectangle is on ground */
        
          isInAir = false;
         velocity = 0;
      }
      else
      {
        // Rectangle is in air 
        // Apply gravity.
        velocity += gravity;
        isInAir = true;
      }

      // Check for Jumping
      if (IsKeyPressed(KEY_SPACE) && !isInAir)
      {
        velocity += jumpVelo;
        
      }
      
      

      // apply gravity
      

      // Update Velocity
      posY += velocity;
      DrawRectangle(windowWidth/2, posY, width, height, BLUE);
      

      EndDrawing();
      // Game Logic Ends
    }

  // Raylib function to ensure window closes properly
  CloseWindow();

}
