#include "raylib.h"
#include "raymath.h"
#include "Farmer.h"
#include "Plant.h"

int main()
{
  const int winWidth{1920};
  const int winHeight{1080};

  InitWindow(winWidth, winHeight, "FarmGame");

  // load Map
  Texture2D worldMap = LoadTexture("map/map.png");
  Vector2 mapPos{0.f, 0.f};
  float mapScale{4.f};

  // collision mask
  Image maskImg = LoadImage("map/mapmask.png");
  Color *maskPixels = LoadImageColors(maskImg);
  int maskW = maskImg.width;
  int maskH = maskImg.height;
  UnloadImage(maskImg);

  // Character variable
  Farmer farmer(winWidth, winHeight);

  // Plant variable
  Plant plant(&farmer);

  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    // deltaTime
    const float dT{GetFrameTime()};

    // start drawing
    BeginDrawing();
    ClearBackground(WHITE);

    mapPos = Vector2Scale(farmer.getWorldPos(), -1);

    // Draw Map
    DrawTextureEx(worldMap, mapPos, 0.f, mapScale, WHITE);

    // Draw character
    farmer.DrawFarmer(dT, maskPixels, maskW, maskH);
    plant.DrawPlant(mapPos);

    EndDrawing();
  }

  UnloadTexture(worldMap);
  UnloadImageColors(maskPixels);
  CloseWindow();
}