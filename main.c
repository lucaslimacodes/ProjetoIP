#include "raylib.h"
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

} Player;




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
            DrawTextureEx(walkingUp[*frameCounter], (Vector2){player.posX, player.posY}, 0, 1.5, RAYWHITE);
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
   
    SetTargetFPS(60);
    
    InitWindow(screenWidth, screenHeight, "raylib test");

    Player player = (Player){screenWidth/2, screenHeight/2, 0, HEADING_DOWN, false};
    
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
    
    while (!WindowShouldClose())    
    {
        
        frames++;
        if(frames>24){
            frames = 0;
        }
        


        if(IsKeyDown(KEY_LEFT)==true){
            player.posX-=3;
            player.isRunning = true;
            player.walkMode = HEADING_LEFT;
        }
        else if(IsKeyDown(KEY_RIGHT)==true){
            player.posX+=3;
            player.isRunning = true;
            player.walkMode = HEADING_RIGHT;
        }
        else if(IsKeyDown(KEY_UP)==true){
            player.posY-=3;
            player.isRunning = true;
            player.walkMode = HEADING_UP;
        }
        else if(IsKeyDown(KEY_DOWN)==true){
            player.posY+=3;
            player.isRunning = true;
            player.walkMode = HEADING_DOWN;
        }
        else if(IsKeyDown(KEY_LEFT)!=true && IsKeyDown(KEY_RIGHT)!=true && IsKeyDown(KEY_UP)!=true && IsKeyDown(KEY_DOWN)!=true){
            player.isRunning = false;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        StartPlayerAnim(frames, &frameCounter, player.walkMode, player.isRunning, walkingUp, walkingDown, walkingLeft, walkingRight, player);
        
        
    
        


        
        
        EndDrawing();
        
    }
    
    
    
    UnloadPlayerTextures(walkingUp, walkingDown, walkingLeft, walkingRight);
    CloseWindow();        
    

    return 0;
}