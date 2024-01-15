#ifndef SETTING_H
#define SETTING_H
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


#include <stdio.h>
#include<string.h>

#include "raylib.h"


int begin = 0;


int settingsSaved = 0;

typedef struct {
    int number_of_nodes;
} setting;


// Save the setting to a file
void saveSetting(setting save) {
    FILE *file = fopen("setting.dat", "wb");
    if (file != NULL) {
        fwrite(&save, sizeof(setting), 1, file);
        fclose(file);
    }
}





int saveButton( const char *text ,int x ,int y ){
    // SET RECTANGLE
    
    struct Rectangle r1 = {.x = (float)(x - 10), .y = (float)(y - 5), .width = (float)(MeasureText(text, 40) + 20), .height = 50};
    // Hover detection
    if (CheckCollisionPointRec(GetMousePosition(), r1))
    {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        DrawText(text, x, y, 40,GRAY);

        //pressing
        if (IsMouseButtonPressed(0))
        {
            return 1;
        }
    }
    else
    {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        DrawText(text, x, y, 40, BLACK);
        return 0;
    }
    return 0;
}


void openSettingWindow(setting *save, int *start)
{
    char input[64] = { 0 };  // Buffer for text input
    int inputLength = 0;
    bool editInput = false;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw input field label
        DrawText("Enter the number of nodes (1-15):", 10, 10, 20, BLACK);

        // Draw input field
        DrawRectangle(10, 40, 200, 40, DARKGRAY);

        // Draw the input value or "Click to Edit" message
        if (editInput)
        {
            DrawText(input, 20, 50, 30, MAROON);
        }
        else
        {
            DrawText("Click to Edit", 20, 50, 20, GRAY);
        }

        // Detect mouse click inside input field
        Rectangle inputArea = {10, 40, 200, 40};

        if (CheckCollisionPointRec(GetMousePosition(), inputArea))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                editInput = !editInput;  // Toggle edit mode

                if (editInput)
                {
                    // Clear the input buffer
                    memset(input, 0, sizeof(input));
                    inputLength = 0;
                }
            }
        }

        if (editInput)
        {
            // Process text input
            int key = GetKeyPressed();

            if (key >= 32 && key <= 125 && inputLength < 63)
            {
                input[inputLength] = (char)key;
                inputLength++;
            }
            else if (key == KEY_BACKSPACE && inputLength > 0)
            {
                inputLength--;
                input[inputLength] = '\0';
            }
            else if (key == KEY_ENTER)
            {
                // Update save struct with input value
                save->number_of_nodes = atoi(input);

                // Close the setting window
                CloseWindow();
            }
        }

        // Clamp input to range (1-14)
        int inputValue = atoi(input);
        if (inputValue < 1)
            inputValue = 1;
        else if (inputValue > 14)
            inputValue = 14;

        // Draw save button
        int click = saveButton("SAVE", 10 , 100);

        if (click)
        {
            // Update save struct with input value
            save->number_of_nodes = inputValue;

            // Save the setting to a file
            saveSetting(*save);  // Function to save the setting to a file

           
            // If you want to go back to the menu, update the state accordingly
            *start = 1;  // Assuming start is the variable indicating the menu page

            return;
            
        }

        EndDrawing();
    }
}

#endif