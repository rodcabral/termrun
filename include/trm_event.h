#ifndef _TRM_EVENT_H
#define _TRM_EVENT_H

// Arrows
#define TRM_UP 'A'
#define TRM_DOWN 'B'
#define TRM_RIGHT 'C'
#define TRM_LEFT 'D'

typedef struct {
    char key;
} TRM_Event;

void TRM_GetKey(TRM_Event* event);

#endif
