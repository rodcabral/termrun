#include "trm_window.h"
#include <stdbool.h>
#include <termrun.h>
#include <unistd.h>

#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 30

int main() {
    TRM_Context* context = TRM_CreateContext();
    TRM_Window* window = TRM_CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT);

    int player_x = 1;
    int player_y = 1;

    context->objects[0].x = player_x;
    context->objects[0].y = player_y;
    context->objects[0].ch = '#';

    context->objects[1].x = 10;
    context->objects[1].y = 10;
    context->objects[1].ch = '@';

    bool loop = true;
    TRM_Event event;
    while(loop) {
        TRM_UpdateWindow(window, context);
        TRM_GetKey(&event);

        if(event.key == 'q') {
            loop = false;
        }

        context->objects[0].x += player_x;

        if(context->objects[0].x >= WINDOW_WIDTH - 1) {
            player_x--;
        }

        if(context->objects[0].x <= 0) {
            player_x++;
        }

        context->objects[0].y += player_y;

        if(context->objects[0].y >= WINDOW_HEIGHT - 1) {
            player_y--;
        }

        if(context->objects[0].y <= 0) {
            player_y++;
        }

        switch(event.key) {
            case TRM_UP:
                context->objects[1].y--;
                break;
            case TRM_DOWN:
                context->objects[1].y++;
                break;
            case TRM_RIGHT:
                context->objects[1].x++;
                break;
            case TRM_LEFT:
                context->objects[1].x--;
                break;
        }

        TRM_RenderWindow(window);
    }

    TRM_DestroyContext(context);
    TRM_DestroyWindow(window);
    TRM_CloseWindow();

    return 0;
}
