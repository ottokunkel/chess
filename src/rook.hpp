#pragma once
#include "piece.hpp"
#include <bits/stdc++.h>

using namespace std;

class Rook : public Piece{
    private:
        bool moved;
    public:
        Rook(char c, int f, int r);
        char getName();
        char getColor();
        std::string getSymbol();
        void move(Board* b, Square* start, Square* end);
        bool validate(Board* b, Square* start, Square* end);
        bool getMoved();
        
};