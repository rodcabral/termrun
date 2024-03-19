#ifndef _TRM_WINDOW_H
#define _TRM_WINDOW_H

#include <trm_context.h>

typedef struct {
    int w;
    int h;
} TRM_Window;

TRM_Window* TRM_CreateWindow(int w, int h);

void TRM_UpdateWindow(TRM_Window* winow, TRM_Context* context);

void TRM_CloseWindow();

#endif
