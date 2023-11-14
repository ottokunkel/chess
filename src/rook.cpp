#include "rook.hpp"
#include <bits/stdc++.h>

Rook::Rook(char c, int f, int r){
    moved = false;
    file = f;
    rank = r;
    color = c;
    name = 'r';
    if (color == 'w'){
        symbol = "♜";
    }else{
        symbol = "♖";
    }
    
}


bool Rook::getMoved(){
    return moved;
}

char Rook::getName(){
    return name;
}
char Rook::getColor(){
    return color;
}

std::string Rook::getSymbol(){
    return symbol;
}

bool Rook::validate(Board* b, Square* start, Square* end){

    if(end->getPiece() != nullptr){
        if(end->getPiece()->getColor() == color){
            return false;
        }
    }

    int x = end->getFile() - start->getFile();
    int y = end->getRank() - start->getRank();

    int x_sign;
    int y_sign;

    if (x > 0){
        x_sign = 1;
    }else if (x < 0){
        x_sign = -1;
    }else{
        x_sign = 0;
    }

    if (y > 0){
        y_sign = 1;
    }else if (y < 0){
        y_sign = -1;
    }else{
        y_sign = 0;
    }
    
    if ((y != 0 && x != 0) || (x == 0 && y == 0)){
        return false;
    }
    
    for(int i = 1; i < max(abs(x), abs(y)); i++){
        Piece* temp = b->getSquare(start->getFile() + i*x_sign, start->getRank() + i*y_sign)->getPiece();
        if(temp != nullptr && temp != end->getPiece()){
            return false;
        }
    }

    
    return true;

}

void Rook::move(Board* b, Square* start, Square* end){

    if(validate(b, start, end)){
        moved = true;
        end->setPiece(start->getPiece());
        start->setPiece(nullptr);
        file = end->getFile();
        rank = end->getRank();
    }
        
        
}