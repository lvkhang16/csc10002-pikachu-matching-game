#pragma once

#include "utils.h"

struct Player {
    string username, password, mode;
    int currentScore, highestScore, life, level;
    float comboFactor;

    int getInfo();
    int signIn();
    int signUp();
    int chooseMode();

    int printMenu();
    void printStatusBar();
    void updatePlayer();
};

void readAndPrintDecor(const string &fileName, int x, int y);
void printBackground(int level);
void printCellBackground(int level, int x, int y);
void printIntro();
void printMenuDecor();
void printSideMenu();
void printTutorialScreen();
int printYouWonScreen(const Player &p);
int printYouLostScreen(Player &p);
bool comparePlayerScores(const Player& p1, const Player& p2);
void sortLeaderboard(Player leaderboard[], int n);
void showLeaderboard(Player leaderboard[]);