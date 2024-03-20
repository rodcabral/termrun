#include <termrun.h>
#include <stdbool.h>

int main() {
    TRM_Context* context = TRM_CreateContext();
    TRM_Window* window = TRM_CreateWindow(40, 20);

    context->objects[0].x = 5;
    context->objects[0].y = 5;
    context->objects[0].ch = '@';

    context->objects[2].x = 16;
    context->objects[2].y = 9;
    context->objects[2].ch = 'X';
    
    context->objects[3].x = 10;
    context->objects[3].y = 10;
    context->objects[3].ch = 'V';

    context->objects[1].x = 6;
    context->objects[1].y = 17;
    context->objects[1].ch = '&';

    TRM_Event event;

    bool loop = true;
    while(loop) {
        TRM_UpdateWindow(window, context);

        TRM_GetKey(&event);

        switch(event.key) {
            case 'q':
                TRM_CloseWindow();
                loop = false;
                break;
            case TRM_UP:
                context->objects[3].y--;
                break;
            case TRM_DOWN:
                context->objects[3].y++;
                break;
            case TRM_RIGHT:
                context->objects[3].x++;
                break;
            case TRM_LEFT:
                context->objects[3].x--;
                break;
        }   

        TRM_RenderWindow(window);
    }

    TRM_CloseWindow();
    TRM_DestroyContext(context);
    TRM_DestroyWindow(window);

    return 0;
}
