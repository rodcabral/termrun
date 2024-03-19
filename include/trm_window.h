#ifndef _TRM_WINDOW_H
#define _TRM_WINDOW_H

typedef struct {
    int w;
    int h;
} TRM_Window;

TRM_Window* TRM_CreateWindow(int w, int h);

#endif
