#include "raylib.h"
#define HEADING_UP 1
#define HEADING_RIGHT 2
#define HEADING_DOWN 3
#define HEADING_LEFT 4


typedef struct{
    int posX;
    int posY;
    int frameCounter;
    Rectangle playerCollision;
    int walkMode;
    int isRunning;

} Player;
int main()
{
    const int screenWidth = 1800;
    const int screenHeight = 900;
   
    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "raylib test");
    Texture2D t = LoadTexture("Assets/PlayerMovements/PlayerIdleDown.png");
    
    while (!WindowShouldClose())    
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(t, 900, 450, RAYWHITE);


        
        
        EndDrawing();
        
    }
    
    
    
    UnloadTexture(t);
    CloseWindow();        
    

    return 0;
}