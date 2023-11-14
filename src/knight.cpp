#include "knight.hpp"
#include <bits/stdc++.h>

Knight::Knight(char c, int f, int r){
    file = f;
    rank = r;
    color = c;
    name = 'b';
    if (color == 'w'){
        symbol = "♞";
    }else{
        symbol = "♘";
    }
    
}

char Knight::getName(){
    return name;
}
char Knight::getColor(){
    return color;
}

std::string Knight::getSymbol(){
    return symbol;
}

bool Knight::validate(Board* b, Square* start, Square* end){

    int x = end->getFile() - start->getFile();
    int y = end->getRank() - start->getRank();

    if((y == 2 || y == -2) && (x == 1 || x == -1)){
        return true;
    }else if((x == 2 || x == -2) && (y == 1 || y == -1)){
        return true;
    }

    return false;

}

void Knight::move(Board* b, Square* start, Square* end){

    if(validate(b, start, end)){
        end->setPiece(start->getPiece());
        start->setPiece(nullptr);
        file = end->getFile();
        rank = end->getRank();
    }
        
        
}