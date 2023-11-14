#include "piece.hpp"
#include "board.hpp"
#include "square.hpp"
#include <bits/stdc++.h>

char Piece::getName(){
    return name;
}
char Piece::getColor(){
    return color;
}

int Piece::getFile(){
    return file;
}

int Piece::getRank(){
    return rank;
}

void Piece::setFile(int f){
    file = f;
}

void Piece::setRank(int r){
    rank = r;
}