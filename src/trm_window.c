#include <trm_window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

TRM_Window* TRM_CreateWindow(int w, int h) {
    TRM_Window* win = malloc(sizeof(TRM_Window));

    win->w = w;
    win->h = h;

    return win;
}

void TRM_UpdateWindow(TRM_Window* window, TRM_Context* context) {
    bool blink = false;
    for(int i = 0; i < window->h; i++) {
        for(int j = 0; j < window->w; j++) {
            for(int k = 0; k < context->size; k++) {
                if(context->objects[k].ch != '\0') {
                    if(context->objects[k].x == j && context->objects[k].y == i) {
                        printf("%c", context->objects[k].ch);
                        blink = true;
                    }
                }
            }
            if(!blink) {
                printf("-");
            } else {
                blink = false;
            }
        }
        printf("\n");
    }
};
