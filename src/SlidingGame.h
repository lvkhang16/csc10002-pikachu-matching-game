#pragma once

#include "utils.h"
#include "MenuAndControl.h"
#include "Cell.h"

struct SlidingGame {
    Player player;
    int x = 1, y = 1;
    SlidingCell **board = NULL;
    int height;
    int width;
    int remainingPairs;

    bool checkEmptyLine(int x1, int y1, int x2, int y2);
    bool checkIMatching(int x1, int y1, int x2, int y2);
    bool checkLMatching(int x1, int y1, int x2, int y2);
    bool checkZMatching(int x1, int y1, int x2, int y2);
    bool checkUMatching(int x1, int y1, int x2, int y2);
    bool checkAllMatchings(int x1, int y1, int x2, int y2);
    bool checkValidPairs();

    SlidingCell *findNode(int x, int y);
    void deleteNode(int x, int y);

    void initialize();
    void printBoard();
    void shuffleBoard();
    int play();

    void suggestMove();
    void turnOffSuggestions();

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
};

