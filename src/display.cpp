#include "bits/stdc++.h"
#include "board.hpp"
#include "piece.hpp"
#include "pawn.hpp"
#include "display.hpp"
#include "square.hpp"

void Display::updateDisplay(Board* board){
    std::string files[9] = {"     ","  A  ","  B  ","  C  ","  D  ","  E  ","  F  ","  G  ","  H  "};
    std::string ranks[9] = {"     ","  1  ","  2  ","  3  ","  4  ","  5  ","  6  ","  7  ","  8  "};
    for (int i = 0; i < 9; i++){
        std::vector<std::string> rank {
            "     ",
            ranks[i],
            "     ",
        };
        display_array[i][0] = rank;

        std::vector<std::string> file {
            "     ",
            files[i],
            "     ",
        };
        display_array[0][i] = file;
    }
    

    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            loadSquare(board->getSquare(i,j));
        }
    }
}

void Display::loadSquare(Square* sq){

    std::string highlightText1 = "";
    std::string highlightText2 = "";
    if(sq->getHighlight()){
        highlightText1 = "\x1B[32m";
        highlightText2 = "\033[0m";
    }

    if(sq->getColor() == 'w'){
        if(sq->getPiece() == nullptr){
            std::vector<std::string> square_picture {
                highlightText1 + "█████" + highlightText2,
                highlightText1 + "█████" + highlightText2,
                highlightText1 + "█████" + highlightText2,
            };
            display_array[sq->getRank()+1][sq->getFile()+1] = square_picture;
         }else{
                std::vector<std::string> square_picture {
                highlightText1 + "█████" + highlightText2,
                highlightText1 + "██"+sq->getPiece()->getSymbol()+"██" + highlightText2,
                highlightText1 + "█████" + highlightText2,
            };
            display_array[sq->getRank()+1][sq->getFile()+1] = square_picture;
         }
    }else {
        if(sq->getPiece() == nullptr){
            std::vector<std::string> square_picture {
                highlightText1+"▒▒▒▒▒" + highlightText2,
                highlightText1+"▒▒▒▒▒" + highlightText2,
                highlightText1+"▒▒▒▒▒" + highlightText2,

            };
            display_array[sq->getRank()+1][sq->getFile()+1] = square_picture;
         }else{
            std::vector<std::string> square_picture {
            highlightText1 + "▒▒▒▒▒" + highlightText2,
            highlightText1 + "▒▒"+sq->getPiece()->getSymbol()+"▒▒" + highlightText2,
            highlightText1 + "▒▒▒▒▒" + highlightText2,

            };
            display_array[sq->getRank()+1][sq->getFile()+1] = square_picture;
         }
    }
    
}

void Display::printDisplay(){
    //std::cout<<"test";
    //display rows
    for(int i = 9; i >= 0; i--){

        //image rows
        for (int j = 0; j < 3; j++){

            //display columns
            for(int k = 0; k < 9; k++){
                std::cout<<display_array[i][k][j];
            }
           std::cout<<"\n"; 
        }
        
    }
}