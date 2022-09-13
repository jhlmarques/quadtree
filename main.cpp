#include "raylib.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "shapes.h"
#include "actor.h"
using namespace std;

#define ACTOR_AMOUNT 2000

int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    //Create points
    srand(time(NULL));

    vector<Actor*> v_point;
    for(int i = 0; i < ACTOR_AMOUNT; i++){
        v_point.push_back(
            new Actor(
                new shapes::Rectangle(rand() % screenWidth, rand() % screenHeight, 1, 1),
                (rand() % 10) + 1,
                (rand() % 10) + 1
                ));
        cout << v_point[i]->getPos().x << " " << v_point[i]->getPos().y << endl;
    }

    InitWindow(screenWidth, screenHeight, "Quadtree");
    SetTargetFPS(60);              


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        for(auto actor : v_point){
                actor->step();
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for(auto actor : v_point){
                DrawPixel(actor->getPos().x, actor->getPos().y, BLACK);
                bool hit_x = actor->getPos().x < 0 || actor->getPos().x > screenWidth;
                bool hit_y = actor->getPos().y < 0 || actor->getPos().y > screenHeight;
                if(hit_x || hit_y){
                    actor->onBorderHit(hit_x, hit_y);
                }
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}