#include "raylib.h"
#include "buttons.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define BOX_WIDTH 50
#define BOX_SPACING 30
#define SORT_SPEED 60


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

    //flags
    int done = 0  , begin = 0 , setting_change = 0 , sort = 0 , quit = 0 ; 
    
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

                    if( quitButton( "Exit",(SCREEN_WIDTH/2) - (MeasureText("Exit",40)/2),SCREEN_HEIGHT/2,&begin) == 1 )
                    {   

                        //quit

                    }
                else if ( playAginButton( "Play again" ,(SCREEN_WIDTH/2) - (MeasureText("Play again",40)/2) , SCREEN_HEIGHT / 2 - 100 ,&begin) == 1 ){

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
                else if( quit == 1 )
                {

                    //quit  

                }
                else
                {
                    //generate the linke list 

                    // draw the title of the main menu

                    // buttons logic 
                    sort           =  startButton("Start",(SCREEN_WIDTH/2) - (MeasureText("Start",40)/2),500,&begin);
                    setting_change =  settingButton("Setting",(SCREEN_WIDTH/2) - (MeasureText("Setting",40)/2),550,&begin);
                    quit           =  quitButton("Exit",(SCREEN_WIDTH/2) - (MeasureText("Exit",40)/2),600,&begin);
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