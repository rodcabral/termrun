#include <trm_event.h>
#include <unistd.h>

void TRM_GetKey(TRM_Event* event) {
    char buf;
    int n = read(0, &buf, 1);

    event->key = buf;
}
