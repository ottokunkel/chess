#include <bits/stdc++.h>
using namespace std;
#include "square.hpp"
#include "board.hpp"


Board::Board(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i%2 == 0)){
                if (j%2 == 0){
                    board_array[i][j] = new Square(j, i, 'b');
                }else{
                    board_array[i][j] = new Square(j, i, 'w');
                }
                
            }else if (i%2 == 1){
                if (j%2 == 1){
                    board_array[i][j] = new Square(j, i, 'b');
                }else{
                    board_array[i][j] = new Square(j, i, 'w');
                }
            }
            
        }
    }

    
}


Square* Board::getSquare(int file, int rank){
    return board_array[rank][file];
}




