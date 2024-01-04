#include "raylib.h"


#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600
#define BOX_WIDTH 50
#define BOX_SPACING 30
#define SORT_SPEED 60

//flags
int done = 0  , begin = 0 , setting_change = 0 , sort = 0 ; 

bool pause = false;  

//setting by_default = (setting){10};

//bismillah
int main(void)
{
    // window Initialisation 
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Insertion Sort Of linked list");
    

    SetTargetFPS(60);
    
    int sortedSteps = 0;
    int currentStep = 0;
    
    while (!WindowShouldClose()) {
        // Update
        if(sort==1){
            //sort step update
        }

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            if( begin == 1 )
            { 

                //Visaulising the Step
            
                if( done == 1)
                {

                    if( quitButton() == 1 )
                    {   

                        //quit

                    }
                else if ( playAginButton() == 1 ){

                        //init the flags to begin the sort
                    
                    }
                }

            
            }
            else
            {
                if( setting_change == 1 )
                {   

                    //open setting page 

                }
                else if( quitButton() == 1 )
                {

                    //quit  

                }
                else
                {
                    //generate the linke list 

                    // draw the title of the main menu

                    // buttons logic 

                }
            }
        EndDrawing();
        }

    // De-Initialization    
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}