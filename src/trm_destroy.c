#include <trm_destroy.h>
#include <stdlib.h>

void TRM_DestroyWindow(TRM_Window* window) {
    free(window);
}

void TRM_DestroyContext(TRM_Context* context) {
    free(context);
}
