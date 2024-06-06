#include <cstddef>
#include <utility>
#include <iostream>

#include "board.h"

std::size_t board::at(std::size_t i, std::size_t j) {
    return width*i + j;
}

void board::update_cell(std::size_t i, std::size_t j) {
    static const std::pair<std::size_t, std::size_t> adj[8] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, };
    std::size_t count = 0;

    for (std::size_t k = 0; k < 8; k++)
        if (0 <= i + adj[k].first && i + adj[k].first < height && 0 <= j + adj[k].second && j + adj[k].second < width)
            count++;

    if (cur[at(i, j)]) {
        if (count < 2) {
            next[at(i, j)] = false;
        } else if (count < 4) {
            next[at(i, j)] = true;
        } else {
            next[at(i, j)] = false;
        }
    } else {
        if (count == 3) {
            next[at(i, j)] = true;
        }
    }
}

void board::update(void) {
    for (std::size_t i = 0; i < height; i++)
        for (std::size_t j = 0; j < width; j++)
            update_cell(i, j);
    std::swap(cur, next);
}

void board::print(void) {
    for (std::size_t i = 0; i < height; i++) {
        for (std::size_t j = 0; j < width; j++)
            std::cout << cur[at(i, j)];
        std::cout << '\n';
    }
}
