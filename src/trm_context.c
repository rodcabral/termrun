#include <trm_context.h>
#include <stdlib.h>

TRM_Context* TRM_CreateContext() {
    TRM_Context* context = malloc(sizeof(TRM_Context));

    context->size = 1000;

    for(int i = 0; i < context->size; i++) {
        context->objects[i].ch = '\0';
    }
    
    return context;
}
