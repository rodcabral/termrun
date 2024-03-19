#include <trm_window.h>
#include <stdlib.h>

TRM_Window* TRM_CreateWindow(int w, int h) {
    TRM_Window* win = malloc(sizeof(TRM_Window));

    win->w = w;
    win->h = h;

    return win;
}
