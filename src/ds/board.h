#include <bitset>
#include <cstddef>

class board {
public:
    static constexpr std::size_t width = 10;
    static constexpr std::size_t height = 10;

    static std::size_t at(std::size_t i, std::size_t j);

    void update_cell(std::size_t i, std::size_t j);

    std::bitset<width*height> cur;
    std::bitset<width*height> next;

    void update(void);
    void print(void);
};
