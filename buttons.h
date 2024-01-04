#include "raylib.h"


int startButton( const char *text ,int x ,int y ,int *begin){
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
            if (*begin == 0)
            {
                *begin = 1;
            }
            else if(*begin == 1)
            {
                *begin = 0;
            }
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


int settingButton( const char *text ,int x ,int y ,int *begin){
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
            if (*begin == 0)
            {
                *begin = 1;
            }
            else if(*begin == 1)
            {
                *begin = 0;
            }
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


int quitButton( const char *text ,int x ,int y ,int *begin){
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
            if (*begin == 0)
            {
                *begin = 1;
            }
            else if(*begin == 1)
            {
                *begin = 0;
            }
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


int playAginButton( const char *text ,int x ,int y ,int *begin){
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
            if (*begin == 0)
            {
                *begin = 1;
            }
            else if(*begin == 1)
            {
                *begin = 0;
            }
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

