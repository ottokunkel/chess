#include <bits/stdc++.h>
#include "square.hpp"
using namespace std;

Square::Square(int f, int r){
    file = f;
    rank = r;
    piece = nullptr;
}

int Square::getFile(){return file;}
int Square::getRank(){return rank;}
void Square::setFile(int f){file = f;}
void Square::setRank(int r){rank = r;}
Piece* Square::getPiece(){return piece;}
void Square::setPiece(Piece* p){piece = p;}


