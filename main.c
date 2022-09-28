#include "raylib.h"
#include <stdlib.h>
#define HEADING_UP 1
#define HEADING_RIGHT 2
#define HEADING_DOWN 3
#define HEADING_LEFT 4


typedef struct{
    int posX;
    int posY;
    int frameCounter;
    int walkMode;
    bool isRunning;
    bool collidedUp;
    bool collidedDown;
    bool collidedLeft;
    bool collidedRight;

} Player;

typedef struct{
    Rectangle collision;
    int typeCollision;
} Wall;


void generateCollisionsMainMap(Wall *walls){
    walls[0].collision = (Rectangle){520, 300, 5, 300};
    //                                x  y   lenght height
    walls[0].typeCollision = HEADING_LEFT;
    walls[1].collision = (Rectangle){485, 730, 5, 335};
    walls[1].typeCollision = HEADING_LEFT;
    walls[2].collision = (Rectangle){520, 300, 538, 5};
    walls[2].typeCollision = HEADING_UP;
    walls[3].collision = (Rectangle){1058, 40, 5, 265};
    walls[3].typeCollision = HEADING_LEFT;
    walls[4].collision = (Rectangle){1058, 40, 110, 5};
    walls[4].typeCollision = HEADING_UP;


    
}
void verifyCollision(Wall *walls, int numberWalls,  Rectangle playerCollision, Player *player){
    for(int i=0;i<numberWalls;i++){
        if(CheckCollisionRecs(walls[i].collision, playerCollision)==true){
            if(walls[i].typeCollision==HEADING_DOWN){
                player[0].collidedDown = true;
            }
            else if(walls[i].typeCollision==HEADING_LEFT){
                player[0].collidedLeft = true;
            }
            else if(walls[i].typeCollision==HEADING_UP){
                player[0].collidedUp = true;
            }
            else if(walls[i].typeCollision==HEADING_RIGHT){
                player[0].collidedRight = true;
            }
        }
    }
}

void StartPlayerAnim(int frames, int *frameCounter, int walkMode, bool isRunning, Texture2D walkingUp[], Texture2D walkingDown[], Texture2D walkingLeft[], Texture2D walkingRight[], Player player){
    if(*frameCounter==4){
        *frameCounter = 0;
    }
        
    
    if(isRunning==false){
        *frameCounter = 0;
        if(walkMode==HEADING_DOWN){
            DrawTextureEx(walkingDown[*frameCounter], (Vector2){player.posX, player.posY}, 0, 1.5, RAYWHITE);
        }
        else if(walkMode==HEADING_LEFT){
            DrawTextureEx(walkingLeft[*frameCounter], (Vector2){player.posX, player.posY}, 0, 1.5, RAYWHITE);
        }
        else if(walkMode==HEADING_UP){
            DrawTextureEx(walkingUp[*frameCounter], (Vector2){player.posX, player.posY}, 0, 1.5, RAYWHITE);
        }
        else if(walkMode==HEADING_RIGHT){
            DrawTextureEx(walkingRight[*frameCounter], (Vector2){player.posX, player.posY}, 0, 1.5, RAYWHITE);
        }
    }
    else{
        if(walkMode==HEADING_DOWN){
            DrawTextureEx(walkingDown[*frameCounter], (Vector2){player.posX, player.posY}, 0, 1.5, RAYWHITE);
            if(frames%4==0){
                *frameCounter = *frameCounter + 1;
            }
        }
        else if(walkMode==HEADING_LEFT){
            DrawTextureEx(walkingLeft[*frameCounter], (Vector2){player.posX, player.posY}, 0, 1.5, RAYWHITE);
            if(frames%4==0){
                *frameCounter = *frameCounter + 1;
            }
        }
        else if(walkMode==HEADING_UP){
            DrawTextureEx(walkingUp[*frameCounter], (Vector2){player.posX, player.posY}, 0, 1.5, RAYWHITE);
            if(frames%4==0){
                *frameCounter = *frameCounter + 1;
            }
        }
        else if(walkMode==HEADING_RIGHT){
            DrawTextureEx(walkingRight[*frameCounter], (Vector2){player.posX, player.posY}, 0, 1.5, RAYWHITE);
            if(frames%4==0){
                *frameCounter = *frameCounter + 1;
            }
        }
    }
}

void UnloadPlayerTextures(Texture2D walkingUp[], Texture2D walkingDown[], Texture2D walkingLeft[], Texture2D walkingRight[]){
    for(int i=0;i<4;i++){
        UnloadTexture(walkingUp[i]);
        UnloadTexture(walkingDown[i]);
        UnloadTexture(walkingLeft[i]);
        UnloadTexture(walkingRight[i]);
    }
}
int main()
{
    const int screenWidth = 1800;
    const int screenHeight = 900;
   
    int numberWallsMain = 5;

    SetTargetFPS(60);
    
    InitWindow(screenWidth, screenHeight, "raylib test");

    Player player = (Player){screenWidth/2, screenHeight/2, 0, HEADING_DOWN, false, false, false, false, false};

    
    int frameCounter = 0;
    int frames = 0;

    Texture2D walkingDown[4];
    walkingDown[0] = LoadTexture("Assets/PlayerMovements/PlayerIdleDown.png");
    walkingDown[1] = LoadTexture("Assets/PlayerMovements/PlayerWalkingDown (1).png");
    walkingDown[2] = LoadTexture("Assets/PlayerMovements/PlayerIdleDown.png");
    walkingDown[3] = LoadTexture("Assets/PlayerMovements/PlayerWalkingDown (2).png");

    Texture2D walkingUp[4];
    walkingUp[0] = LoadTexture("Assets/PlayerMovements/PlayerIdleUp.png");
    walkingUp[1] = LoadTexture("Assets/PlayerMovements/PlayerWalkingUp (1).png");
    walkingUp[2] = LoadTexture("Assets/PlayerMovements/PlayerIdleUp.png");
    walkingUp[3] = LoadTexture("Assets/PlayerMovements/PlayerWalkingUp (2).png");

    Texture2D walkingLeft[4];
    walkingLeft[0] = LoadTexture("Assets/PlayerMovements/PlayerIdleLeft.png");
    walkingLeft[1] = LoadTexture("Assets/PlayerMovements/PlayerWalkingLeft (1).png");
    walkingLeft[2] = LoadTexture("Assets/PlayerMovements/PlayerIdleLeft.png");
    walkingLeft[3] = LoadTexture("Assets/PlayerMovements/PlayerWalkingLeft (2).png");

    Texture2D walkingRight[4];
    walkingRight[0] = LoadTexture("Assets/PlayerMovements/PlayerIdleRight.png");
    walkingRight[1] = LoadTexture("Assets/PlayerMovements/PlayerWalkingRight (1).png");
    walkingRight[2] = LoadTexture("Assets/PlayerMovements/PlayerIdleRight.png");
    walkingRight[3] = LoadTexture("Assets/PlayerMovements/PlayerWalkingRight (2).png");

    Texture2D mainMap = LoadTexture("mainMap.png");
    Texture2D background = LoadTexture("background.png");

    Camera2D camera;
    camera.rotation = 0;
    camera.offset = (Vector2){player.posX, player.posY};
    camera.zoom = 1;

    Wall *walls;
    walls = malloc(sizeof(Wall)*numberWallsMain);
    generateCollisionsMainMap(walls);
    


    
    while (!WindowShouldClose())    
    {
        camera.target = (Vector2){player.posX, player.posY};
        
        Rectangle PlayerCollision = (Rectangle){player.posX+3, player.posY+32, 35, 17};

        player.collidedDown = false;
        player.collidedLeft = false;
        player.collidedRight = false;
        player.collidedUp = false;

        verifyCollision(walls, numberWallsMain, PlayerCollision, &player);

        frames++;
        if(frames>24){
            frames = 0;
        }
        


        if(IsKeyDown(KEY_LEFT)==true && player.collidedLeft==false){
            player.posX-=3;
            player.isRunning = true;
            player.walkMode = HEADING_LEFT;
        }
        else if(IsKeyDown(KEY_RIGHT)==true && player.collidedRight==false){
            player.posX+=3;
            player.isRunning = true;
            player.walkMode = HEADING_RIGHT;
        }
        else if(IsKeyDown(KEY_UP)==true && player.collidedUp==false){
            player.posY-=3;
            player.isRunning = true;
            player.walkMode = HEADING_UP;
        }
        else if(IsKeyDown(KEY_DOWN)==true && player.collidedDown==false){
            player.posY+=3;
            player.isRunning = true;
            player.walkMode = HEADING_DOWN;
        }
        else if(IsKeyDown(KEY_LEFT)!=true && IsKeyDown(KEY_RIGHT)!=true && IsKeyDown(KEY_UP)!=true && IsKeyDown(KEY_DOWN)!=true){
            player.isRunning = false;
        }

        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(RAYWHITE);
        DrawTextureEx(background, (Vector2){-900, -1800}, 0, 3, RAYWHITE);
        DrawTextureEx(mainMap, (Vector2){450,0}, 0, 0.5, RAYWHITE);
        DrawRectangleRec(PlayerCollision, RED);
        StartPlayerAnim(frames, &frameCounter, player.walkMode, player.isRunning, walkingUp, walkingDown, walkingLeft, walkingRight, player);
        for(int i=0;i<numberWallsMain;i++){
            DrawRectangleRec(walls[i].collision, BLACK);
        }
        
        
        
    
        


        
        
        EndDrawing();
        EndMode2D();
        
    }
    
    
    
    UnloadPlayerTextures(walkingUp, walkingDown, walkingLeft, walkingRight);
    UnloadTexture(mainMap);
    UnloadTexture(background);
    free(walls);
    CloseWindow();        
    

    return 0;
}