#pragma once
#include "piece.hpp"
#include <bits/stdc++.h>



class Square{
    private:
        int file;
        int rank;
        Piece* piece;

    public:
        Square(int f, int r);
        int getFile();
        int getRank();
        void setFile(int f);
        void setRank(int r);
        Piece* getPiece();
        void setPiece(Piece* p);

};