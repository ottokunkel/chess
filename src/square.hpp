#pragma once
#include <bits/stdc++.h>

class Piece;

class Square{
    private:
        bool w_attacked;
        bool b_attacked;
        bool highlight;
        char color;
        int file;
        int rank;
        Piece* piece;

    public:
        Square(int f, int r, char c);
        bool getAttacked(char color);
        void setAttacked(char color, bool value);
        bool getHighlight();
        void setHighlight(bool t);
        int getFile();
        char getColor();
        int getRank();
        void setFile(int f);
        void setRank(int r);
        void setColor(char c);
        Piece* getPiece();
        void setPiece(Piece* p);

};