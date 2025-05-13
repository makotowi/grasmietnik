#include "raylib.h"
#include "Farmer.h"

class Plant
{
private:
    Texture2D plant = LoadTexture("plants/Basic_Plants.png");
    Vector2 playerPosition{};
    Vector2 screenPos{};
    Farmer *farmerptr;
    bool isPlanted;
    float plantWidth;
    float plantHeight;
    float scale{4.f};

public:
    Plant(Farmer *farmer);
    void DrawPlant(Vector2 mapPos);
};