#pragma once
#include <bits/stdc++.h>
#include "board.hpp"
#include "square.hpp"

class Piece{
    protected:
        int file;
        int rank;
        std::string symbol;
        char name;
        char color;
    public:
        virtual int getFile();
        virtual int getRank();
        virtual void setFile(int f);
        virtual void setRank(int r);
        virtual char getName();
        virtual char getColor();
        virtual std::string getSymbol() = 0;
        virtual void move(Board* b, Square* start, Square* end) = 0;
        virtual bool validate(Board* b, Square* start, Square* end) = 0;


};