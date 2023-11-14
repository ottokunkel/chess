#include <bits/stdc++.h>
#include "square.hpp"
using namespace std;

Square::Square(int f, int r, char c){
    w_attacked = false;
    b_attacked = false;
    highlight = false;
    color = c;
    file = f;
    rank = r;
    piece = nullptr;
}

void Square::setAttacked(char color, bool value){
    if(color == 'b'){
        b_attacked = value;
    }else if(color == 'w'){
        w_attacked = value;
    }
}

bool Square::getAttacked(char color){
    if(color == 'b'){
        return b_attacked;
    }else if(color == 'w'){
        return w_attacked;
    }

    return false;
}
bool Square::getHighlight(){return highlight;}
void Square::setHighlight(bool t){highlight = t;}
char Square::getColor(){return color;}
int Square::getFile(){return file;}
int Square::getRank(){return rank;}
void Square::setColor(char c){color = c;}
void Square::setFile(int f){file = f;}
void Square::setRank(int r){rank = r;}
Piece* Square::getPiece(){return piece;}
void Square::setPiece(Piece* p){piece = p;}

