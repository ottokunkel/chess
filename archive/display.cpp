#include <bits/stdc++.h>
#include "display.hpp"
#include "square.hpp"

void Display::loadSquare(Square* sq){
/*
void Board::displayBoard(){
    cout<<squares[0][0]->getPiece()<<endl;

    vector<string> displayArr[8][8];

    for(int i = 0; i < 8; i++ ){
        for(int j = 0; j <8; j++){
            if(i%2 == 0){
                if (j%2 == 0){
                    displayArr[i][j] = squares[i][j]->displayBlackSQ();
                }else{
                    displayArr[i][j] = squares[i][j]->displayWhiteSQ();
                }
            }else if(i%2 == 1){
                if (j%2 == 0){
                    displayArr[i][j] = squares[i][j]->displayWhiteSQ();
                }else{
                    displayArr[i][j] = squares[i][j]->displayBlackSQ();
                }
            }
            
        }
    }

    for(int i = 0; i<8; i++){
        for(int j = 0; j < displayArr[i][0].size(); j++){
            for(int k = 0; k < 8; k++){
                cout<<displayArr[i][k][j];
            }
            cout<<endl;
        }
    }
    
}
vector<string> Board::displayBlackSQ() {
    if(piece == nullptr){
        vector<string> sq {
            "|######|",
            "|######|",
            "|######|",
            "|######|",
        };
        return sq;
    }else{
        vector<string> sq {
                "|######|",
                "|##\033[1;47m"+piece->getColor()+"\033[0m##|",
                "|##\033[1;31m"+piece->getName()+"\033[0m##|",
                "|######|",
        };
        return sq;
    }
    
}
vector<string> Board::displayWhiteSQ() {

    if (piece == nullptr){
        vector<string> sq {
            "|      |",
            "|      |",
            "|      |",
            "|      |",
        };
        return sq;
    }else{
        
        vector<string> sq {
            "|      |",
            "|  \033[1;47m"+piece->getColor()+"\033[0m  |",
            "|  \033[1;31m"+piece->getName()+"\033[0m  |",
            "|      |",
        };
        return sq;
    }

}

*/
}