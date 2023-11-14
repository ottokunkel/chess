#include "queen.hpp"
#include <bits/stdc++.h>

Queen::Queen(char c, int f, int r){
    file = f;
    rank = r;
    color = c;
    name = 'b';
    if (color == 'w'){
        symbol = "♛";
    }else{
        symbol = "♕";
    }
    
}

char Queen::getName(){
    return name;
}
char Queen::getColor(){
    return color;
}

std::string Queen::getSymbol(){
    return symbol;
}

bool Queen::validate(Board* b, Square* start, Square* end){

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
    }else if(x == 0){
        x_sign = 0;
    }

    if (y > 0){
        y_sign = 1;
    }else if (y < 0){
        y_sign = -1;
    }else if (y == 0){
        y_sign = 0;
    }
    
    if (
        //if start position
        (x == 0 && y == 0) ||
        //or if x and y are not equal with both not equalling 0
        (abs(x) != abs(y) && (x != 0 && y != 0))){
        
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

void Queen::move(Board* b, Square* start, Square* end){

    if(validate(b, start, end)){
        end->setPiece(start->getPiece());
        start->setPiece(nullptr);
        file = end->getFile();
        rank = end->getRank();
    }
        
        
}