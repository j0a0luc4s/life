#include "board.h"
#include <iostream>
#include <unistd.h>

int main(void)
{
    board b;
    b.cur[b.at(2, 2)] = true;
    b.cur[b.at(2, 3)] = true;
    b.cur[b.at(2, 4)] = true;
    b.cur[b.at(3, 1)] = true;
    b.cur[b.at(3, 2)] = true;
    b.cur[b.at(3, 3)] = true;
    while (true) {
        b.print();
        b.update();
        sleep(1);
    }
    return 0;
}
