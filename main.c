#include<stdio.h>
#include <stdlib.h>
#include "setting.h"
#include "raylib.h"
#include "buttons.h"
#include "node.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define BOX_WIDTH 50
#define BORDER_WIDTH 15
#define BOX_SPACING 30
#define SORT_SPEED 60
#define MonosFont LoadFont("resources\\font\\MONOS.TTF")



// prototypes

void draw_list(Node *head); 
void draw_node(Node *node, Color border_color, Color fill_color); 
void Wait(int milliseconds); 
void renderList(Node *head, Node *current, Node *prev);
void insertionSort(Node **head_ref, int *done);
void insertionSortStep(Node **head_ref, Node **current, Node **prev,int *done);

// nodes init
Node *current;
Node *List=NULL;

// setting structs
setting by_default = (setting){10};
setting save;

// bismillah
int main(void)
{
    // window Initialisation
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Insertion Sort Of linked list");

    SetTargetFPS(60);

    // flags
    int done = 0, begin = 0, setting_change = 0, sort = 0, quit = 0; int settingsSaved =0;

    

    while (!WindowShouldClose())
    {   
        
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if(sort == 1){
            
            while (done!=1)
            {
            insertionSort(&List,&done);
            
            }
            
          
            //
            if (IsKeyPressed(KEY_ENTER)) {
                sort = 0;
                done = 1;
            }

        }

        if (begin == 1)
        {            
            

            if (done == 1)
            {  
                
                

                if (quitButton("Exit", (SCREEN_WIDTH / 2) - (MeasureText("Exit", 40) / 2), SCREEN_HEIGHT / 2) == 1)
                {

                    // quit
                    CloseWindow();
                    return 0;
                }
                else if (playAginButton("Play again", (SCREEN_WIDTH / 2) - (MeasureText("Play again", 40) / 2), SCREEN_HEIGHT / 2 - 100) == 1)
                {

                    // init the flags to begin the sort
                    done = 0, begin = 0, setting_change = 0, sort = 0, quit = 0;
                }
            }
        }
        else
        {
            if (setting_change == 1)
            {
                // open setting page
                openSettingWindow(&by_default,&sort);
                setting_change = 0 , settingsSaved = 1;
            
            }
            else { 
                if (quit == 1)
                {   
                    // quit
                    CloseWindow();
                    return 0;
                }
                else
                {
                // generate the linke list
                if(settingsSaved == 1){
                    FILE *file = fopen("setting.dat", "rb");
                    if (file != NULL) {
                        fread(&save, sizeof(setting), 1, file);
                        fclose(file);
                        generateList(save.number_of_nodes);
                    } 
                }
                else {
                List = generateList(by_default.number_of_nodes);
                }
                // draw the title of the main menu
                
                DrawText("\n \n \n                   Projet de tp Algo :", 40, 40, 50, DARKGRAY);
                DrawText("\n \n \n             \n \n \n             \n \n \n             \n \n \n     ce projet permet de visualiser une liste chainnee en utilisant RAYLIB!!", 20, 20, 30, DARKGRAY);
                DrawText("\n \n \n             \n \n \n             \n \n \n             \n \n \n             \n \n \n   il s'agit d'un triage en changeant la valeur de la liste chainee pour obtenir ", 20, 20, 30, DARKGRAY);
                DrawText("\n \n \n             \n \n \n             \n \n \n             \n \n \n             \n \n \n                \n \n \n                                        une liste trier.", 20, 20, 30, DARKGRAY);
                DrawText("\n \n \n             \n \n \n             \n \n \n             \n \n \n             \n \n \n              \n \n \n              \n \n \n              \n \n \n              \n \n \n                                   Menu ", 30, 30, 40, DARKGRAY);
                
                
                // buttons logic
                
                    sort = startButton("Start", (SCREEN_WIDTH / 2) - (MeasureText("Start", 40) / 2), 500, &begin);
                    setting_change = settingButton("Setting", (SCREEN_WIDTH / 2) - (MeasureText("Setting", 40) / 2), 550);
                    quit = quitButton("Exit", (SCREEN_WIDTH / 2) - (MeasureText("Exit", 40) / 2), 600);
                
            }
        }
    }
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    freeLinkedList(List);

    return 0;
}


//delay time fn 
void Wait(int milliseconds) {
        double startTime = GetTime();
        double currentTime = startTime;

        while ((currentTime - startTime) * 1000 < milliseconds) {
            currentTime = GetTime();
    }
}


// drawing a node according to his position and color . 
void draw_node(Node *node, Color border_color, Color fill_color) {
    int x = node->position.x;
    int y = node->position.y;
    int width = NODE_WIDTH;
    int height = NODE_HEIGHT;

    // Draw the node border
    struct Rectangle r1 = {.x= (float)x,.y=(float)y, .height=(float)height ,.width=(float)width};

    DrawRectangleLinesEx(r1, BORDER_WIDTH, border_color);

    // Draw the node fill color
    DrawRectangleRec(r1, fill_color);
    
    char num[16];
    snprintf(num, sizeof(num), "%d", node->data);
    // Draw the node data (text)
    Vector2 Pos = {.x = x + width / 2 , .y =  y + height / 2};
    DrawTextEx(MonosFont,num,Pos, 20,2,BLACK);
}


//drawing the list by drawing each node
void draw_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        draw_node(current, current->border_color, current->fill_color);
        current = current->next;
    }
}


//fn responsible of updating the list
void renderList(Node *head, Node *current, Node *prev) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw the linked list
    draw_list(head);

    // Highlight the current and previous nodes
    if (current != NULL && prev != NULL) {
        draw_node(current, current->border_color, current->fill_color);
        draw_node(prev, prev->border_color, prev->fill_color);
    }

    Wait(50);
    EndDrawing();

    // Wait for a short period to visualize the process
}



void previous_recursive(Node *prev, Node **current, Color highlight_color) {
   
    if (prev == *current){//stop condition if prev have arrived to current then return
        return;
    }
    //if it's not keep iterating till prev ptr reach the current node
    previous_recursive(prev->next, current, highlight_color);
    
    //the prev nodes is saved in the stack of ram so we can compare each two nodes and swap them backwards
    draw_node(prev,BLACK,YELLOW);
    draw_node(*current,BLACK,YELLOW);
    
    if (prev->data > (*current)->data) { // condition of swaping
        swap(prev, *current); //swaping
        *current = prev; // this is the reason of creating a fake_current 
    } else{
        draw_node(prev,BLACK,RED);
        draw_node(*current,BLACK,RED);
          
    }  
    draw_node(prev,BLACK,WHITE);
    draw_node(*current,BLACK,WHITE);
    


}


void insertionSortStep(Node **head_ref, Node **current, Node **prev,int *done) {
    if (*current == NULL) {
        *done = 1 ; 
        return;  // Sorting completed
    }

    Node *fake_current = *current;

    // Visualize the sorting process
    renderList(*head_ref, fake_current, *prev);

    //inserttion sort recursivly 
    previous_recursive(*prev, &fake_current, RED);


    // Move to the next nodes
    *current = (*current)->next;
    
}


void insertionSort(Node **head_ref, int *done) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        return;
    }

    current = (*head_ref)->next;
    Node *prev = *head_ref;

    insertionSortStep(head_ref, &current, &prev,done);

}

