#include <termrun.h>

int main() {
    TRM_Window* window = TRM_CreateWindow(40, 20);
    TRM_Context* context = TRM_CreateContext();

    context->objects[0].x = 5;
    context->objects[0].y = 5;
    context->objects[0].ch = '@';
    
    context->objects[1].x = 6;
    context->objects[1].y = 17;
    context->objects[1].ch = '&';

    TRM_UpdateWindow(window, context);

    return 0;
}
