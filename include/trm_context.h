#ifndef _TRM_CONTEXT_H
#define _TRM_CONTEXT_H

typedef struct {
    int x;
    int y;
    char ch;
} object;

typedef struct {
    int size;
    object objects[1000];
} TRM_Context;

TRM_Context* TRM_CreateContext();

#endif
