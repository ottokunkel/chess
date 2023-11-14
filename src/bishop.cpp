#include "bishop.hpp"
#include <bits/stdc++.h>

Bishop::Bishop(char c, int f, int r){
    file = f; 
    rank = r; 
    color = c;
    name = 'b';
    if (color == 'w'){
        symbol = "♝";
    }else{
        symbol = "♗";
    }
    
}

char Bishop::getName(){
    return name;
}
char Bishop::getColor(){
    return color;
}

std::string Bishop::getSymbol(){
    return symbol;
}

bool Bishop::validate(Board* b, Square* start, Square* end){

    int x = end->getFile() - start->getFile();
    
    int y = end->getRank() - start->getRank();
    
    int x_sign;
    int y_sign;

    if (x > 0){
        x_sign = 1;
    }else{
        x_sign = -1;
    }

    if (y > 0){
        y_sign = 1;
    }else{
        y_sign = -1;
    }


    if(abs(x) != abs(y) || x == 0 || y == 0){
        return false;
    }

    for(int i = 1; i <= abs(x); i++){
        Piece* temp = b->getSquare(start->getFile() + x_sign*i, start->getRank() + y_sign*i)->getPiece();
        if(temp != nullptr && temp != end->getPiece()){
        
            return false;
        }
    }


    if(end->getPiece() != nullptr){

        if(end->getPiece()->getColor() != color){
            return true;
        }else{
            return false;
        }
        
    }
    return true;

}

void Bishop::move(Board* b, Square* start, Square* end){


    if(validate(b, start, end)){
        end->setPiece(start->getPiece());
        start->setPiece(nullptr);
        file = end->getFile();
        rank = end->getRank();
    }
        
        
}