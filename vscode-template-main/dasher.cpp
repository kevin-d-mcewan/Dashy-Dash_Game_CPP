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
  

  // Sprite Variables:
  Texture2D scarfy = LoadTexture("textures/scarfy.png");
  Rectangle scarfyRec;
  scarfyRec.width = scarfy.width / 6;
  scarfyRec.height = scarfy.height;
  scarfyRec.x = 0;
  scarfyRec.y = 0;
  Vector2 scarfyPos;
  scarfyPos.x = windowWidth / 2 - scarfyRec.width / 2;
  scarfyPos.y = windowHeight - scarfyRec.height;

  // to fly upward must go in the negative direction from og start point THIS IS INTIALIZE  VELO
  int velocity{0}; 

  // Check to see if already in air.
  bool isInAir{false};

  // Jump Velocity.
  const int jumpVelo{-18};

  // Game Variables
  SetTargetFPS(60);

  // WindowShouldClose() is a 'raylib' predefined function
  while (!WindowShouldClose())
    {
      // Game Logic Begins
      BeginDrawing();
      
      ClearBackground(BLUE);


      // ground check
      if (scarfyPos.y >= windowHeight - scarfyRec.height)
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
      scarfyPos.y += velocity;
      
      // Drawing the scarfMan sprite to window.
      DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

      EndDrawing();
      // Game Logic Ends
    }

  // To close things properly must "unloadTexture" before closing down program
  UnloadTexture(scarfy);
  // Raylib function to ensure window closes properly
  CloseWindow();

}
