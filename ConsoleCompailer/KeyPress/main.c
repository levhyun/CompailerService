#include <stdio.h>
#include "KeyEventInput.c"

int main() {
    init_keyboard();
    while (1) {
        if (_kbhit()) {
            int ch = _getch();
            _putch(ch);
            if(ch == 27){
                printf("ESC key!");
                return 0;
            }
        }
    }
    close_keyboard();
}