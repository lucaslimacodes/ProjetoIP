#include "raylib.h"

#define ESQUERDA 1
#define DIREITA 2
#define CIMA 3
#define BAIXO 4
typedef struct{
    Rectangle p;
    int tipoColisao;
} Parede;


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    int posX = 400;
    int posY = 225;
    int posXinimigo =50;
    int posYinimigo =50;
    Camera2D c;
    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "raylib test");
    Rectangle r[4];
    r[0].height = 500;
    r[0].width = 10;
    r[0].x = 0;
    r[0].y = 0;

    r[1].height = 10;
    r[1].width = 500;
    r[1].x = 0;
    r[1].y = 0;
    
    r[2].height = 500;
    r[2].width = 10;
    r[2].x = 500;
    r[2].y = 0;

    r[3].height = 10;
    r[3].width = 510;
    r[3].y = 500;
    r[3].x = 0;

    Parede paredes[4];
    paredes[0].p = r[0];
    paredes[0].tipoColisao = ESQUERDA;
    paredes[1].p = r[1];
    paredes[1].tipoColisao = CIMA;
    paredes[2].p = r[2];
    paredes[2].tipoColisao = DIREITA;
    paredes[3].p = r[3];
    paredes[3].tipoColisao = BAIXO;
    
    while (!WindowShouldClose())    
    {
        
        Vector2 v2 = {posX, posY};
        Vector2 v1 = {400, 225};
        c.rotation = 0;
        c.target = v2;
        c.offset = v1;
        c.zoom = 1;
        Rectangle player;
        player.x = posX-20;
        player.y = posY-15;
        player.width = 40;
        player.height = 30;

        Rectangle enemy;
        enemy.x =posXinimigo-20;
        enemy.y =posYinimigo-15;
        enemy.height = 30;
        enemy.width = 40;

        bool colidiuEsquerda = false;
        bool colidiuDireita = false;
        bool colidiuCima = false;
        bool colidiuBaixo = false;

        
        BeginDrawing();
        BeginMode2D(c);
        ClearBackground(RAYWHITE);
        
        DrawRectangle(posX-20, posY-15, 40, 30, BLUE);
        DrawRectangleRec(r[0], BLACK);
        DrawRectangleRec(r[1], BLACK);
        DrawRectangleRec(r[2], BLACK);
        DrawRectangleRec(r[3], BLACK);
        DrawRectangleRec(enemy, RED);
        
        for(int i=0;i<4;i++){
            if(CheckCollisionRecs(player, paredes[i].p)==true){
                if(paredes[i].tipoColisao== CIMA){
                    colidiuCima = true;
                }
                
                if(paredes[i].tipoColisao== BAIXO){
                    colidiuBaixo = true;
                }
                
                if(paredes[i].tipoColisao== ESQUERDA){
                    colidiuEsquerda = true;
                }
                
                if(paredes[i].tipoColisao== DIREITA){
                    colidiuDireita = true;
                }
                
                
            }
        }
        
        if(CheckCollisionRecs(enemy, player)==true){
            DrawText("O inimigo encostou em você", posX-30, posY+30, 15, RED);
        }
        
        
        
        
        
        if(IsKeyDown(KEY_RIGHT)==true && colidiuDireita==false){
            posX+=2;
        }
        if(IsKeyDown(KEY_LEFT)==true && colidiuEsquerda == false){
            posX-=2;
        }
        if(IsKeyDown(KEY_UP)==true && colidiuCima == false){
            posY-=2;
        }
        if(IsKeyDown(KEY_DOWN)==true && colidiuBaixo == false){
            posY+=2;
        }

        if(posXinimigo>posX){
            posXinimigo--;
        }
        if(posXinimigo<posX){
            posXinimigo++;
        }
        if(posYinimigo>posY){
            posYinimigo--;
        }
        if(posYinimigo<posY){
            posYinimigo++;
        }



           
        
            

            
        EndMode2D();
        EndDrawing();
        
        
    }
    
    
    
    
    CloseWindow();        
    

    return 0;
}