#pragma once
#include <bits/stdc++.h>
#include "board.hpp"
#include "square.hpp"

class Display{
    private:
        std::vector<std::string> display_array[9][9];

    public:
        void updateDisplay(Board* board);
        void loadSquare(Square* sq);
        void printDisplay();
};