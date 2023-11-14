#pragma once
#include "square.hpp"
class Board
{
    Square* board_array[8][8];
    public:
        Board();
        Square* getSquare(int file, int rank);
};
