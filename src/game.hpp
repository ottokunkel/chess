#pragma once
#include "board.hpp"
#include "square.hpp"
#include "piece.hpp"
#include "display.hpp"
#include "king.hpp"


class Game{
    private:
        enum outcome {
            Active,
            BlackWin,
            WhiteWin,
            Draw
        };
        outcome status;
        std::map<char, int> fileMap = {
            { 'A', 0 },
            { 'B', 1 },
            { 'C', 2 },
            { 'D', 3 },
            { 'E', 4 },
            { 'F', 5 },
            { 'G', 6 },
            { 'H', 7 },
            { 'a', 0 },
            { 'b', 1 },
            { 'c', 2 },
            { 'd', 3 },
            { 'e', 4 },
            { 'f', 5 },
            { 'g', 6 },
            { 'h', 7 },
        };
        King* black_king;
        King* white_king;
    public:
        Game();
        void setAttackedSquares(Board* b);
        void checkForWin(Board* b, char c);
        void resetEnPassant(Board* b, char c);
        void start();
        void resetBoard(Board* b);
        bool checkMove(Board* b, Square* start, Square* end);
        void move(Board* b, Square* start, Square* end);
        void askMove(char color, Board* b, Display* display);
        bool checkInput(std::string, Board* b, char color, char type);
        void highlightMoves(Board* b, Square* start);
        void deHighlightMoves(Board* b);
        bool checkChecked(Board* b, char c);
        bool checkUncheck(Board* b, char c, Square* start, Square* end);

        

};