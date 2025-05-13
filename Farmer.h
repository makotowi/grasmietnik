#ifndef FARMER_H
#define FARMER_H

#include "raylib.h"

class Farmer
{
private:
  Texture2D farmer = LoadTexture("Player/Player.png");
  Vector2 screenPos{}; // pozycja gdzie farmer jest rysowany na ekranie (kamera ustawia go zawsze w centrum)
  Vector2 worldPos{};  // pozycja farmera w świecie gry (na mapie)
  Vector2 walk{};
  Vector2 screenCenter{};
  float width;
  float height;
  float scale{4.f};
  int frameWidth{};
  int frameHight{};
  int maxFrameWidth{6};
  int maxFrameHight{10};
  float updateTime{1.f / 12.f};
  float runningTime{};
  int rightLeft = 1;

public:
  Farmer(int winWidth, int winHeight);
  Vector2 getWorldPos()
  {
    return worldPos;
  }
  Vector2 getScreenPos()
  {
    return screenPos;
  }
  void DrawFarmer(float deltaTime, Color *maskPixels, int maskW, int maskH);
};
#endif