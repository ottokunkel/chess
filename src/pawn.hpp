#pragma once
#include "piece.hpp"
#include <bits/stdc++.h>

using namespace std;

class Pawn: public Piece{
    private:
        bool moved;
        bool en_passant;
    public:
        Pawn(char c, int f, int r);
        char getName();
        char getColor();
        std::string getSymbol();
        bool getEnPass();
        void setEnPass(bool b);
        void move(Board* b, Square* start, Square* end);
        bool validate(Board* b, Square* start, Square* end);
        
        
};