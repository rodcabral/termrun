#include <trm_window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>

struct termios old_term, new_term;

void reset_terminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
    printf("\e[?25h");
}

void config_terminal() {
    tcgetattr(STDIN_FILENO, &old_term);
    
    new_term = old_term;
    new_term.c_lflag &= ~(ICANON | ECHO);
    new_term.c_cc[VMIN] = 0;
    new_term.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &new_term);

    printf("\e[?25l");

    atexit(reset_terminal);
}

TRM_Window* TRM_CreateWindow(int w, int h) {
    config_terminal();
    system("clear");
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

            if(i == 0) {
                if(j == 0) {
                    printf("┌");
                } else if(j == window->w - 1) {
                    printf("┐");
                } else {
                    printf("─");
                }
            } else if(i == window->h - 1) {
                if(j == 0) {
                    printf("└");
                } else if(j == window->w - 1) {
                    printf("┘");
                } else {
                    printf("─");
                }
            } else if(j == 0 || j == window->w - 1) { 
                printf("│");
            } else {
                if(!blink) {
                    printf(" ");
                } else {
                    blink = false;
                }
            }
        }
        printf("\n");
    }
}

void TRM_RenderWindow(TRM_Window* window) {
    printf("\e[%dF\n", window->w);
    printf("\e[1;1H");
    fflush(stdout);
    usleep(11000);
}

void TRM_CloseWindow() {
    reset_terminal();
}
