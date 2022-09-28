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
    walls[5].collision = (Rectangle){1168, 40, 5, 115};
    walls[5].typeCollision = HEADING_RIGHT;
    walls[6].collision = (Rectangle){1168, 155, 35, 5};
    walls[6].typeCollision = HEADING_UP;
    walls[7].collision = (Rectangle){1200, 0, 5, 155};
    walls[7].typeCollision = HEADING_LEFT;
    walls[8].collision = (Rectangle){1200, 0, 118, 5};
    walls[8].typeCollision = HEADING_UP;
    walls[9].collision = (Rectangle){1318, 0, 5, 175};
    walls[9].typeCollision = HEADING_RIGHT;
    walls[10].collision = (Rectangle){1280, 175, 45, 5};
    walls[10].typeCollision = HEADING_DOWN;
    walls[11].collision = (Rectangle){1280, 175, 5, 135};
    walls[11].typeCollision = HEADING_RIGHT;
    walls[12].collision = (Rectangle){1280, 310, 225, 5};
    walls[12].typeCollision = HEADING_UP;
    walls[13].collision = (Rectangle){1505, 310, 5, 186};
    walls[13].typeCollision = HEADING_RIGHT;
    walls[14].collision = (Rectangle){1279, 496, 230, 5};
    walls[14].typeCollision = HEADING_DOWN;
    walls[15].collision = (Rectangle){1279, 496, 5, 60};
    walls[15].typeCollision = HEADING_RIGHT;
    walls[16].collision = (Rectangle){1166, 556, 115, 5};
    walls[16].typeCollision = HEADING_DOWN;
    walls[17].collision = (Rectangle){1166, 446, 5, 120};
    walls[17].typeCollision = HEADING_LEFT;
    walls[18].collision = (Rectangle){980, 440, 190, 5};
    walls[18].typeCollision = HEADING_DOWN;
    walls[19].collision = (Rectangle){980, 400, 5, 40};
    walls[19].typeCollision = HEADING_LEFT;
    walls[20].collision = (Rectangle){710, 400, 265, 5};
    walls[20].typeCollision = HEADING_DOWN;
    walls[21].collision = (Rectangle){710, 400, 5, 80};
    walls[21].typeCollision = HEADING_RIGHT;
    walls[22].collision = (Rectangle){638, 480, 77, 5};
    walls[22].typeCollision = HEADING_DOWN;
    walls[23].collision = (Rectangle){638, 480, 5, 13};
    walls[23].typeCollision = HEADING_RIGHT;
    walls[24].collision = (Rectangle){638, 493, 75, 5};
    walls[24].typeCollision = HEADING_UP;
    walls[25].collision = (Rectangle){713 , 493, 5, 40};
    walls[25].typeCollision = HEADING_RIGHT;
    walls[26].collision = (Rectangle){713, 533, 260, 5};
    walls[26].typeCollision = HEADING_UP;
    walls[27].collision = (Rectangle){973, 533, 5, 75};
    walls[27].typeCollision = HEADING_RIGHT;
    walls[28].collision = (Rectangle){973, 608, 195, 5};
    walls[28].typeCollision = HEADING_UP;
    walls[29].collision = (Rectangle){1168, 570, 5, 40};
    walls[29].typeCollision = HEADING_LEFT;
    walls[30].collision = (Rectangle){1168, 570, 110, 5};
    walls[30].typeCollision = HEADING_UP;
    walls[31].collision = (Rectangle){1278, 570, 5, 60};
    walls[31].typeCollision = HEADING_RIGHT;
    walls[32].collision = (Rectangle){1240, 625, 40, 5};
    walls[32].typeCollision = HEADING_DOWN;
    walls[33].collision = (Rectangle){1240, 625, 5, 50};
    walls[33].typeCollision = HEADING_RIGHT;
    walls[34].collision = (Rectangle){1240, 675, 300, 5};
    walls[34].typeCollision = HEADING_UP;
    walls[35].collision = (Rectangle){1540, 630, 5, 40};
    walls[35].typeCollision = HEADING_LEFT;
    walls[36].collision = (Rectangle){1540, 630, 135, 5};
    walls[36].typeCollision = HEADING_UP;
    walls[37].collision = (Rectangle){1675, 630, 5, 430};
    walls[37].typeCollision = HEADING_RIGHT;
    walls[38].collision = (Rectangle){485, 1060, 1200, 5};
    walls[38].typeCollision = HEADING_DOWN;
    walls[39].collision = (Rectangle){485, 600, 5, 130};
    walls[39].typeCollision = HEADING_LEFT;
    walls[40].collision = (Rectangle){485, 600, 40, 5};
    walls[40].typeCollision = HEADING_UP;
    walls[41].collision = (Rectangle){1010, 940, 575, 5};
    walls[41].typeCollision = HEADING_UP;
    walls[42].collision = (Rectangle){1580, 800, 5, 145};
    walls[42].typeCollision = HEADING_LEFT;
    walls[43].collision = (Rectangle){975, 795, 605, 5};
    walls[43].typeCollision = HEADING_DOWN;
    walls[44].collision = (Rectangle){975, 795, 5, 35};
    walls[44].typeCollision = HEADING_RIGHT;
    walls[45].collision = (Rectangle){975, 830, 35, 5};
    walls[45].typeCollision = HEADING_UP;
    walls[46].collision = (Rectangle){1010, 830, 5, 110};
    walls[46].typeCollision = HEADING_RIGHT;
    walls[47].collision = (Rectangle){675, 735, 150, 5};
    walls[47].typeCollision = HEADING_DOWN;
    walls[48].collision = (Rectangle){825, 735, 5, 215};
    walls[48].typeCollision = HEADING_LEFT;
    walls[49].collision = (Rectangle){630, 950, 200, 5};
    walls[49].typeCollision = HEADING_UP;
    walls[50].collision = (Rectangle){625, 798, 5, 157};
    walls[50].typeCollision = HEADING_RIGHT;
    walls[51].collision = (Rectangle){625, 793, 50, 5};
    walls[51].typeCollision = HEADING_DOWN;
    walls[52].collision = (Rectangle){675, 735, 5, 60};
    walls[52].typeCollision = HEADING_RIGHT;



    
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
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
   
    int numberWallsMain = 53;

    SetTargetFPS(60);
    
    InitWindow(screenWidth, screenHeight, "raylib test");
    InitAudioDevice();

    Player player = (Player){900, 650, 0, HEADING_DOWN, false, false, false, false, false};

    
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
    camera.offset = (Vector2){player.posX, player.posY-200};
    camera.zoom = 1;

    Wall *walls;
    walls = malloc(sizeof(Wall)*numberWallsMain);
    generateCollisionsMainMap(walls);
    
    Music m = LoadMusicStream("MainSongSample.mp3");
    
    
    
    while (!WindowShouldClose())    
    {
        UpdateMusicStream(m);
        PlayMusicStream(m);
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
        
        StartPlayerAnim(frames, &frameCounter, player.walkMode, player.isRunning, walkingUp, walkingDown, walkingLeft, walkingRight, player);
        
        
        
        
        
        
        
    
        


        
        
        EndDrawing();
        EndMode2D();
        
    }
    
    
    
    UnloadPlayerTextures(walkingUp, walkingDown, walkingLeft, walkingRight);
    UnloadTexture(mainMap);
    UnloadTexture(background);
    UnloadMusicStream(m);
    free(walls);
    CloseAudioDevice();
    CloseWindow();        
    

    return 0;
}