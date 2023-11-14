#pragma once
#include "piece.hpp"
#include <bits/stdc++.h>

using namespace std;

class Knight: public Piece{
    private:

    public:
        Knight(char c, int f, int r);
        char getName();
        char getColor();
        std::string getSymbol();
        void move(Board* b, Square* start, Square* end);
        bool validate(Board* b, Square* start, Square* end);
        
};