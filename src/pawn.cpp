#include "pawn.hpp"
#include <bits/stdc++.h>
using namespace std;

Pawn::Pawn(char c, int f, int r){
    file = f;
    rank = r;
    color = c;
    name = 'p';
    if (color == 'w'){
        symbol = "♟︎";
    }else{
        symbol = "♙";
    }
    moved = false;
    en_passant = false;
}

bool Pawn::getEnPass(){
    return en_passant;
}

char Pawn::getName(){
    return name;
}
char Pawn::getColor(){
    return color;
}

std::string Pawn::getSymbol(){
    return symbol;
}

bool Pawn::validate(Board* b, Square* start, Square* end){

    
    int x = end->getFile() - start->getFile();
    int y = end->getRank() - start->getRank();
    int y_sign = 1;

    
    if(color == 'b'){
        
        y = y * -1;
        y_sign = -1;
    }

    
    //if moving one step
    if((y == 1) && end->getPiece() == nullptr && x == 0){
        
        return true;
    }

    
    //if moving two steps
    if((y == 2 & x == 0) && moved == false && (b->getSquare(start->getFile(), start->getRank() + y_sign)->getPiece() == nullptr) && end->getPiece() == nullptr){
        
        return true; 
    }

    
    //if attacking
    if((y == 1) && ((x == 1) || (x==-1)) && end->getPiece() != nullptr){
        if(end->getPiece()->getColor() != color){
            
            return true;
        }
    }

   

    //if en passant to the left or right
    //at the beginning of turn, set en_passant to false, if double move, set true;
    Piece* en_pass_left = (b->getSquare(start->getFile() - 1, start->getRank())->getPiece());
    Piece* en_pass_right = (b->getSquare(start->getFile() + 1, start->getRank())->getPiece());

    

    
    if((y == 1) && ((x==-1) && end->getPiece() == nullptr && en_pass_left != nullptr)){     
        if(dynamic_cast<Pawn*>(en_pass_left)->getEnPass() && (en_pass_left->getName() == 'p') && en_pass_left->getColor() != color){
           
            return true;
        }
    }

    
    if((y == 1) && ((x==1) && end->getPiece() == nullptr && en_pass_right != nullptr)){
        if(dynamic_cast<Pawn*>(en_pass_right)->getEnPass() && (en_pass_right->getName() == 'p') && en_pass_right->getColor() != color){
            
            return true;
        }
        
    }

   

    return false;

}

void Pawn::setEnPass(bool b){
    en_passant = b;
}

void Pawn::move(Board* b, Square* start, Square* end){

    int x = end->getFile() - start->getFile();
    int y = end->getRank() - start->getRank();

    if(validate(b, start, end)){

        
        if(y == 2 || y == -2){
            //if double moving
                en_passant = true;
                moved = true;
                end->setPiece(start->getPiece());
                start->setPiece(nullptr);
            

        }else if(((x == 1) || (x == -1)) && end->getPiece() == nullptr){
            //if en_passant to the right
                moved = true;
                //sets new spot to moving piece
                    end->setPiece(start->getPiece());
                //empties the start location
                    start->setPiece(nullptr);
                //kills the en_passant piece
                    b->getSquare(end->getFile(), end->getRank() - y)->setPiece(nullptr);
        }else{
            //normal moving/attacking
                moved = true;
                end->setPiece(start->getPiece());
                start->setPiece(nullptr);
                file = end->getFile();
                rank = end->getRank();
                
        }
    }
}