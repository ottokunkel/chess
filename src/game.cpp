#include <bits/stdc++.h>
#include "game.hpp"
#include "square.hpp"
#include "piece.hpp"
#include "pawn.hpp"
#include "board.hpp"
#include "rook.hpp"
#include "display.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "queen.hpp"
#include "king.hpp"

using namespace std;

Game::Game(){
    status = Active;
}

void Game::setAttackedSquares(Board* b){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            b->getSquare(i,j)->setAttacked('b', false);
            b->getSquare(i,j)->setAttacked('w', false);
        }
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            
            Square* temp_square = b->getSquare(i, j);

            //if the square contains a piece
            if(temp_square->getPiece() != nullptr){

                Piece* temp_piece = temp_square->getPiece();
                //checks if every square is valid, and sets attacked value
                for(int k = 0; k < 8; k++){
                    for(int m = 0; m < 8; m++){

                        if(temp_piece->validate(b, temp_square, b->getSquare(k,m))){
                            b->getSquare(k,m)->setAttacked(temp_piece->getColor(), true);
                        }
                    }
                }
            }
            
        }
    }
}

void Game::resetBoard(Board* b){
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            b->getSquare(i, j)->setPiece(nullptr);
        }
    }

    b->getSquare(0,1)->setPiece(new Pawn('w', 0, 1));
    b->getSquare(1,1)->setPiece(new Pawn('w', 1, 1));
    b->getSquare(2,1)->setPiece(new Pawn('w', 2, 1));
    b->getSquare(3,1)->setPiece(new Pawn('w', 3, 1));
    b->getSquare(4,1)->setPiece(new Pawn('w', 4, 1));
    b->getSquare(5,1)->setPiece(new Pawn('w', 5, 1));
    b->getSquare(6,1)->setPiece(new Pawn('w', 6, 1));
    b->getSquare(7,1)->setPiece(new Pawn('w', 7, 1));
    b->getSquare(2,0)->setPiece(new Bishop('w', 2, 0));
    b->getSquare(5,0)->setPiece(new Bishop('w', 5, 0));
    b->getSquare(0,0)->setPiece(new Rook('w', 0, 0));
    b->getSquare(7,0)->setPiece(new Rook('w', 7, 0));
    b->getSquare(1,0)->setPiece(new Knight('w', 1, 0));
    b->getSquare(6,0)->setPiece(new Knight('w', 6, 0));
    b->getSquare(3,0)->setPiece(new Queen('w', 3, 0));
    white_king = new King('w', 4, 0);
    b->getSquare(4,0)->setPiece(white_king);

    

    b->getSquare(0,6)->setPiece(new Pawn('b', 0, 6));
    b->getSquare(1,6)->setPiece(new Pawn('b', 1, 6));
    b->getSquare(2,6)->setPiece(new Pawn('b', 2, 6));
    b->getSquare(3,6)->setPiece(new Pawn('b', 3, 6));
    b->getSquare(4,6)->setPiece(new Pawn('b', 4, 6));
    b->getSquare(5,6)->setPiece(new Pawn('b', 5, 6));
    b->getSquare(6,6)->setPiece(new Pawn('b', 6, 6));
    b->getSquare(7,6)->setPiece(new Pawn('b', 7, 6));
    b->getSquare(2,7)->setPiece(new Bishop('b', 2, 7));
    b->getSquare(5,7)->setPiece(new Bishop('b', 5, 7));
    b->getSquare(0,7)->setPiece(new Rook('b', 0, 7));
    b->getSquare(7,7)->setPiece(new Rook('b', 7, 7));
    b->getSquare(1,7)->setPiece(new Knight('b', 1, 7));
    b->getSquare(6,7)->setPiece(new Knight('b', 6, 7));
    b->getSquare(4,7)->setPiece(new Queen('b', 4, 7));
    black_king = new King('b', 3, 7);
    b->getSquare(3,7)->setPiece(black_king);

    //test
    // b->getSquare(0,6)->setPiece(new Queen('w', 0, 6));
    // b->getSquare(5,6)->setPiece(new Queen('w', 5, 6));
    // white_king = new King('w', 4, 0);
    // b->getSquare(4,0)->setPiece(white_king);

    // black_king = new King('b', 3, 7);
    // b->getSquare(3,7)->setPiece(black_king);
    

}

bool Game::checkMove(Board* b, Square* start, Square* end){
    
    return start->getPiece()->validate(b, start, end);
}

void Game::highlightMoves(Board* b, Square* start){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            
            Square* temp = b->getSquare(i, j);
            
            if(start->getPiece()->validate(b, start, temp)){
                
                temp->setHighlight(true);
            }else{
                
                temp->setHighlight(false);
            }
        }
    }
    
}

void Game::deHighlightMoves(Board* b){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Square* temp = b->getSquare(i, j);
            temp->setHighlight(false);
        }
    }
}

void Game::move(Board* b, Square* start, Square* end){
    start->getPiece()->move(b,start,end);
}

void Game::resetEnPassant(Board* b, char c){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            Square* temp_square = b->getSquare(i,j);
            if(temp_square->getPiece() != nullptr){

                Piece* temp_piece = temp_square->getPiece();
                if(temp_piece->getName() == 'p' && temp_piece->getColor() == 'c'){
                    Pawn* temp_pawn = dynamic_cast<Pawn*>(temp_piece);
                    temp_pawn->setEnPass(false);
                    
                }
            }
        }
    }
}

bool Game::checkInput(std::string input, Board* b, char color, char type){
    if(input.size() > 2){
        return false;
    }
    
    if(isalpha(input[0])){
        if(
            (((input[0] - 'a') < 8) && ((input[0] - 'a') >= 0) ||
            ((input[0] - 'A') < 8) && ((input[0] - 'A') >= 0)) &&
            (input[1] - '0' < 9 && input[1] - '0' > 0)
            ){
                Piece* piece = b->getSquare(fileMap[input[0]], input[1] - '0' - 1)->getPiece();
                if( 
                    (piece != nullptr) &&
                    (piece->getColor() == color) &&
                    (type == 's')
                ){
                    return true;
                }else if(
                    (type == 'e') &&
                    (
                        ((piece != nullptr) && (piece->getColor() != color)) ||
                        (piece == nullptr)
                    )
                    
                ){
                    return true;
                }
            }
    }
    return false;
}

bool Game::checkChecked(Board* b, char c){
    if(c == 'b'){
        return black_king->checkCheck(b, b->getSquare(black_king->getFile(), black_king->getRank()));
    }

    if(c == 'w'){
        return white_king->checkCheck(b, b->getSquare(white_king->getFile(), white_king->getRank()));
    }

    return false;
}

bool Game::checkUncheck(Board* b, char c, Square* start, Square* end){
    
    bool uncheck = false;
    Piece* temp_piece = end->getPiece();
    end->setPiece(start->getPiece());
    start->setPiece(nullptr);

    if(checkChecked(b,c)){
        uncheck = true;
    }
    
    start->setPiece(end->getPiece());
    end->setPiece(temp_piece);

    return uncheck;
    
}

void Game::checkForWin(Board* b, char c){
    //check for white win
    
        
    bool opposing_win = checkChecked(b, c);
    bool draw = false;
    if(!opposing_win){
        draw = true;
    }

    //for each square
    for(int i = 0; i < 8; i++){
        
        for(int j = 0; j < 8; j++){
            
            //temp square
            Square* temp_square = b->getSquare(i, j);

            //if the square isn't empty
            if(temp_square->getPiece() != nullptr){
                
                Piece* temp_piece = temp_square->getPiece();

                //if the piece is the same color
                if(temp_piece->getColor() == c){
                    
                    //checks if every move can uncheck
                    for(int k = 0; k < 8; k++){
                        
                        for(int m = 0; m < 8; m++){
                            
                            //if move is valid and can uncheck then set win to false;
                            if(temp_piece->validate(b, temp_square, b->getSquare(k,m))){

                                if(opposing_win && checkUncheck(b, c, temp_square, b->getSquare(k,m))){
                                    opposing_win = false;
                                }
                                draw = false;
                            }
                        }
                    }
                }
            }
        }
    }   

    if(opposing_win){
        if(c == 'b'){
            status = WhiteWin;
        }else if(c == 'w'){
            status = BlackWin;
        }
    }else if(draw){
        status = Draw;
    }

    

}

void Game::askMove(char color, Board* b, Display* display){

    bool valid_move = false;
    bool checked = checkChecked(b, color);
    
    while(!valid_move){
        bool valid_start = false;
        Square* s = nullptr;
        Square* e = nullptr;
        while(!valid_start){
            std::cout<<"Which Piece would you like to move: ";
            std::string input_start;
            std::cin>>input_start;
            std::cout<<"\n";
            if(checkInput(input_start, b, color, 's')){
                valid_start = true;
                s = b->getSquare(fileMap[input_start[0]], input_start[1] - '0' - 1);
                highlightMoves(b,s);

                //clears the screen
                std::system("clear");

                display->updateDisplay(b);
                display->printDisplay();
                deHighlightMoves(b);

            }else{
                std::cout<<"That was not a valid piece to move. Try again.";
            }
        }
        
        bool valid_end = false;
        while(!valid_end){
            std::cout<<"Where would you like to move to? ";

            std::string input_end;
            std::cin>>input_end;
            
            
            if(checkInput(input_end, b, color, 'e')){
                
                
                valid_end = true;
                
                
                e = b->getSquare(fileMap[input_end[0]], input_end[1] - '0' - 1);
                
                
            }else{
                std::cout<<"That was not a valid place to move to. Try again."<<"\n";
            }
        }

        
        checked = checkUncheck(b, color, s, e);
        
        if(checkMove(b, s, e) && !checked){           
            valid_move = true;
            move(b, s, e);
        }else{
            std::cout<<"That was not a valid move. Try again."<<"\n";

        }
    }


    
    //std::cout<<isalpha(input[0]);
    
}

void Game::start(){
    //At game start, initializes board object
    Board mainBoard;
    Display display;
    resetBoard(&mainBoard);
    
    

    while(status == Active){
        //prints display
        display.updateDisplay(&mainBoard);
        display.printDisplay();

        //asks white side if they want to move
        std::cout<<"White turn: "<<"\n";
        askMove('w', &mainBoard, &display);
        //clears the screen
        std::system("clear");

        //resets en_passant for blackside
        resetEnPassant(&mainBoard, 'b');

        //checks if black lost
        checkForWin(&mainBoard, 'b');
        if(status != Active){
            break;
        }

        //sets attacked squares
        setAttackedSquares(&mainBoard);

        //clears the screen
        std::system("clear");

        //prints the display
        display.updateDisplay(&mainBoard);
        display.printDisplay();
        //asks black if they want to move
        std::cout<<"Black turn: "<<"\n";
        askMove('b', &mainBoard, &display);

        //checks if white lost
        checkForWin(&mainBoard, 'w');
        std::system("clear");

        //resets white's en_passants
        resetEnPassant(&mainBoard, 'w');

        setAttackedSquares(&mainBoard);

    }
    
    //game over screen
    if(status == WhiteWin){
        std::cout<<"\n\n\n-------------------------------------WHITE WINS!-------------------------------------\n\n\n";
    }

    if(status == BlackWin){
        std::cout<<"\n\n\n-------------------------------------BLACK WINS!-------------------------------------\n\n\n";
    }

    if(status == Draw){
        std::cout<<"\n\n\n------------------------------------------Draw!------------------------------------------\n\n\n";
    }
    





    
}

