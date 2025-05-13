#include "Farmer.h"
#include "raymath.h"

Farmer::Farmer(int winWidth, int winHeight)
{
  worldPos = {256.f, 180.f};

  width = farmer.width / 6;
  height = farmer.height / 10;

  screenCenter = {
      static_cast<float>(winWidth) / 2.f,
      static_cast<float>(winHeight) / 2.f};

  screenPos = {
      static_cast<float>(winWidth) / 2.f - scale * width / 2,
      static_cast<float>(winHeight) / 2.f - scale * height / 2};
}

static inline bool IsWalkable(int x, int y, Color *px, int w, int h)
{
  if (x < 0 || y < 0 || x >= w || y >= h)
    return false;
  {
    Color c = px[y * w + x];
    return (c.r > 200 && c.g > 200 && c.b > 200);
  }
}

void Farmer::DrawFarmer(float deltaTime, Color *maskPixels, int maskW, int maskH)
{
  walk = {};
  if (IsKeyDown(KEY_D))
  {
    walk.x += 1;
    frameHight = 4;
    rightLeft = 1;
  }
  if (IsKeyDown(KEY_A))
  {
    walk.x -= 1;
    frameHight = 4;
    rightLeft = -1;
  }
  if (IsKeyDown(KEY_W))
  {
    walk.y -= 1;
    frameHight = 5;
  }
  if (IsKeyDown(KEY_S))
  {
    walk.y += 1;
    frameHight = 3;
  }
  if (Vector2Length(walk) != 0.f)
  {
    Vector2 propPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(walk), 4.f));

    float camCorrectedX = propPos.x + screenCenter.x;
    float camCorrectedY = propPos.y + screenCenter.y;

    int mx = static_cast<int>(camCorrectedX / scale);
    int my = static_cast<int>(camCorrectedY / scale);

    if (IsWalkable(mx, my, maskPixels, maskW, maskH))
    {
      worldPos = propPos;
    }
  }
  if (Vector2Length(walk) == 0.f)
  {
    frameHight = 0;
  }

  // Animation
  runningTime += deltaTime;
  if (runningTime >= updateTime)
  {
    runningTime = 0.f;
    frameWidth++;
    if (frameWidth >= maxFrameWidth)
    {
      frameWidth = 0;
    }
  }

  // Draw character
  Rectangle source = {width * frameWidth, height * frameHight, rightLeft * width, height};
  Rectangle dest = {screenPos.x, screenPos.y, 4 * width, 4 * height};
  Vector2 origin = {};
  DrawTexturePro(farmer, source, dest, origin, 0.f, WHITE);
}