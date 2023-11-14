#include "king.hpp"
#include "rook.hpp"
#include <bits/stdc++.h>

King::King(char c, int f, int r){
    moved = false;
    check = false;
    file = f;
    rank = r;
    color = c;
    name = 'b';
    if (color == 'w'){
        symbol = "♚";
    }else{
        symbol = "♔";
    }
    
}

char King::getName(){
    return name;
}
char King::getColor(){
    return color;
}

std::string King::getSymbol(){
    return symbol;
}

bool King::validate(Board* b, Square* start, Square* end){

    int x = end->getFile() - start->getFile();
    int y = end->getRank() - start->getRank();

    char opp_color = 'b';
    int sign = 1;
    int k_castle = 3;
    int q_castle = -4;

    if(color == 'b'){
        opp_color = 'w';
        sign = -1;
        k_castle = -3;
        q_castle = 4;
    }

    

    if(end->getPiece() != nullptr){
        if(end->getPiece()->getColor() == color){
            return false;
        }
    }

    //if trying to castle kingside
    
    if((y == 0) && !(check) && !(moved) && (x == k_castle - sign) && b->getSquare(start->getFile() + k_castle, start->getRank())->getPiece() != nullptr){

        Piece* k_side_piece = dynamic_cast<Piece*>(b->getSquare(start->getFile() + k_castle, start->getRank())->getPiece());

        //checks if the piece is a rook
        if(k_side_piece->getName() == 'r'){
            Rook* k_side_rook = (Rook*)k_side_piece;
            //checks if the rook has moved
            
            if(k_side_rook->getMoved()){
                return false;
            }
            for(int i = 0; i < abs(k_castle); i++){
                if(b->getSquare(start->getFile() - i*sign, start->getRank())->getAttacked(opp_color)){
                    return false;
                }
            }
            return true;

        }

    }

    //if trying to castle queenside
    
    if((y == 0) && !(check) && !(moved) && (x == q_castle + sign) && b->getSquare(start->getFile() + q_castle, start->getRank())->getPiece() != nullptr){

        Piece* q_side_piece = dynamic_cast<Piece*>(b->getSquare(start->getFile() + q_castle, start->getRank())->getPiece());

        //checks if the piece is a rook
        if(q_side_piece->getName() == 'r'){
            
            Rook* q_side_rook = (Rook*)q_side_piece;
            //checks if the rook has moved
            
            if(q_side_rook->getMoved()){
                return false;
            }
            for(int i = 0; i < abs(q_castle); i++){
                if(b->getSquare(start->getFile() + i*sign, start->getRank())->getAttacked(opp_color)){
                    return false;
                }
            }
            return true;

        }

    }


    //if any other move
    if(abs(x) > 1 || abs(y) > 1 || start == end){
        return false;
    }

    if(checkCheck(b, end)){
        return false;
    }
    
    return true;

}

bool King::checkCheck(Board* b, Square* end){

    //for every square on the board
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            Piece* tempPiece = b->getSquare(i, j)->getPiece();
            //checks if the square has a piece
            if(tempPiece != nullptr){

                //checks if the piece is not the same color
                if(tempPiece->getColor() != color){

                    //checks if the piece can attack the king in this spot
                    if (tempPiece->validate(b, b->getSquare(i, j), end)){
                        check = true;
                        return true;
                    }
                }
            }
        }
    }

    check = false;
    return false;
}

void King::move(Board* b, Square* start, Square* end){

    
    if(validate(b, start, end)){
        
        
        int x = (end->getFile() - start->getFile());
        //check if castling kingside
        
        
        if(abs(x) > 1){
            
            int side = (abs(x) == 2) ? 1 : -1; 
            int sign = (color == 'w') ? 1 : -1;

            Square* rook_square;
            rook_square = b->getSquare(end->getFile() + (side * sign), end->getRank());
           

            
            Square* new_rook_square = b->getSquare(end->getFile() - (side * sign), end->getRank());
            new_rook_square->setPiece(rook_square->getPiece());
            rook_square->setPiece(nullptr);
            new_rook_square->getPiece()->setFile(new_rook_square->getFile());
            new_rook_square->getPiece()->setRank(new_rook_square->getRank());
            
        }

        moved = true;
        end->setPiece(start->getPiece());
        start->setPiece(nullptr);
        file = end->getFile();
        rank = end->getRank();

    }
        
        
}