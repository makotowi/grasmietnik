#include "Plant.h"
#include "Farmer.h"
#include "raylib.h"
#include "raymath.h"

Plant::Plant(Farmer *farmer)
{
  farmerptr = farmer;

  plantWidth = plant.width / 6;
  plantHeight = plant.height / 2;
}

void Plant::DrawPlant(Vector2 mapPos)
{

  if (IsKeyPressed(KEY_SPACE))
  {
    playerPosition = farmerptr->getWorldPos();
    isPlanted = true;
  }
  if (isPlanted)
  {
    Vector2 planted = Vector2Add(Vector2Scale(playerPosition, scale), mapPos);
    Rectangle source = {plantWidth, 0, plantWidth, plantHeight};
    Vector2 origin = {plantWidth / 2, plantHeight};
    Rectangle dest = {planted.x * scale + mapPos.x, planted.y * scale + mapPos.y, 4 * plantWidth, 4 * plantHeight};
    DrawTexturePro(plant, source, dest, origin, 0.f, WHITE);
  }
}