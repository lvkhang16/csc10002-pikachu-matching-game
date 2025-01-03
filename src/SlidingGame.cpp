#include "SlidingGame.h"

void SlidingGame::moveUp() // Moves cell upward
{
    for (int i = x; i <= width; i++)
    {
        for (int j = y - 1; j >= 1; j--)
        {
            if (findNode(i, j) != NULL)
            {
                findNode(x, y)->isHovered = false;
                x = i;
                y = j;
                findNode(x, y)->isHovered = true;
                playSound("move.wav");
                return;
            }
        }
    }

    for (int i = x - 1; i >= 1; i--)
    {
        for (int j = y - 1; j >= 1; j--)
        {
            if (findNode(i, j) != NULL)
            {
                findNode(x, y)->isHovered = false;
                x = i;
                y = j;
                findNode(x, y)->isHovered = true;
                playSound("move.wav");
                return;
            }
        }
    }
}

void SlidingGame::moveDown() // Moves cell downward
{
    for (int i = x; i <= width; i++)
    {
        for (int j = y + 1; j <= height; j++)
        {
            if (findNode(i, j) != NULL)
            {
                findNode(x, y)->isHovered = false;
                x = i;
                y = j;
                findNode(x, y)->isHovered = true;
                playSound("move.wav");
                return;
            }
        }
    }

    for (int i = x - 1; i >= 1; i--)
    {
        for (int j = y + 1; j <= height; j++)
        {
            if (findNode(i, j) != NULL)
            {
                findNode(x, y)->isHovered = false;
                x = i;
                y = j;
                findNode(x, y)->isHovered = true;
                playSound("move.wav");
                return;
            }
        }
    }
}

void SlidingGame::moveRight() // Moves cell to the right
{
    for (int i = y; i >= 1; i--)
    {
        for (int j = x + 1; j <= width; j++)
        {
            if (findNode(j, i) != NULL)
            {
                findNode(x, y)->isHovered = false;
                x = j;
                y = i;
                findNode(x, y)->isHovered = true;
                playSound("move.wav");
                return;
            }
        }
    }

    for (int i = y + 1; i <= height; i++) {
        for (int j = x + 1; j <= width; j++) {
            if (findNode(j, i) != NULL)
            {
                findNode(x, y)->isHovered = false;
                x = j;
                y = i;
                findNode(x, y)->isHovered = true;
                playSound("move.wav");
                return;
            }
        }
    }
}

void SlidingGame::moveLeft() // Moves cell to the left
{
    for (int i = y; i >= 1; i--)
    {
        for (int j = x - 1; j >= 1; j--)
        {
            if (findNode(j, i) != NULL)
            {
                findNode(x, y)->isHovered = false;
                x = j;
                y = i;
                findNode(x, y)->isHovered = true;
                playSound("move.wav");
                return;
            }
        }
    }

    for (int i = y + 1; i <= height; i++)
    {
        for (int j = x - 1; j >= 1; j--)
        {
            if (findNode(j, i) != NULL)
            {
                findNode(x, y)->isHovered = false;
                x = j;
                y = i;
                findNode(x, y)->isHovered = true;
                playSound("move.wav");
                return;
            }
        }
    }
}

SlidingCell *SlidingGame::findNode(int x, int y) // For accessing a specific cell, it returns the pointer to the cell at a specific coordinates. If that cell no longer exists, the function returns false
{
    if (y < 1 || y > height || x < 1 || x > width)
        return NULL;

    SlidingCell *temp = board[y - 1];
    while (temp != NULL)
    {
        if (temp->j == (x - 1))
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void SlidingGame::deleteNode(int x, int y) // For deleting a cell
{
    SlidingCell *p = findNode(x, y);

    if (x == 1)
    {
        if (board[y - 1]->next == NULL)
        {
            board[y - 1]->deleteBox(player.level);
            delete p;
            board[y - 1] = NULL;
            return;
        }
        else
        {
            board[y - 1] = p->next;


            SlidingCell *temp = board[y - 1];
            while (temp->next != NULL)
            {
                temp->j--;
                temp = temp->next;
            }

            temp->deleteBox(player.level);
            temp->j--;


            p->deleteBox(player.level);
            delete p;
            return;
        }
    }
    else
    {
        SlidingCell *q = findNode(x - 1, y);
        q->next = p->next;

        if (p->next != NULL)
        {
            SlidingCell *temp = p->next;
            while (temp->next != NULL)
            {
                temp->j--;
                temp = temp->next;
            }
            temp->deleteBox(player.level);
            temp->j--;
        }

        p->deleteBox(player.level);

        delete p;

        return;
    }
}

bool SlidingGame::checkEmptyLine(int x1, int y1, int x2, int y2) // Check if there is an empty or unobstructed path between to cells
{
    if (y1 == y2) {
        int a, b, count = 0;

        a = min(x1, x2);
        b = max(x1, x2);

        for (int i = a; i <= b; i++)
        {
            if (findNode(i, y1) != NULL)
            {
                count++;
            }
        }
        if (count == 2)
            return false;
        if ((count == 1) && ((findNode(x1, y1) == NULL && findNode(x2, y2) != NULL) || (findNode(x1, y1) != NULL && findNode(x2, y2) == NULL)))
        {
            return true;
        }
        else if (count == 0) {
            return true;
        }
        return false;
    }

    if (x1 == x2) {
        int a, b, count = 0;
        if (y1 > y2) {
            a = y2;
            b = y1;
        }
        else {
            a = y1;
            b = y2;
        }
        for (int i = a; i <= b; i++)
        {
            if (findNode(x1, i) != NULL)
            {
                count++;
            }
        }
        if (count == 2)
            return false;
        if ((count == 1) && ((findNode(x1, y1) == NULL && findNode(x2, y2) != NULL) || (findNode(x1, y1) != NULL && findNode(x2, y2) == NULL)))
        {
            return true;
        }
        else if (count == 0)
        {
            return true;
        }
        return false;
    }
    return false;
}

bool SlidingGame::checkIMatching(int x1, int y1, int x2, int y2) // Checks I-shaped matching
{
    if (y1 == y2) {
        int a, b;
        a = min(x1, x2);
        b = max(x1, x2);
        for (int i = a + 1; i < b; i++)
        {
            if (findNode(i, y1) != NULL)
            {
                return false;
            }
        }
        return true;
    }

    if (x1 == x2) {
        int a, b;
        if (y1 > y2) {
            a = y2;
            b = y1;
        }
        else {
            a = y1;
            b = y2;
        }
        for (int i = a + 1; i < b; i++)
        {
            if (findNode(x1, i) != NULL)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool SlidingGame::checkLMatching(int x1, int y1, int x2, int y2) // Checks L-shaped matching
{
    if (y1 == y2 || x1 == x2)
    {
        return false;
    }

    bool check1, check2;
    if (findNode(x2, y1) == NULL)
    {
        check1 = checkEmptyLine(x1, y1, x2, y1);
        check2 = checkEmptyLine(x2, y2, x2, y1);
        if (check1 && check2)
        {
            return true;
        }
    }

    if (findNode(x1, y2) == NULL)
    {
        check1 = checkEmptyLine(x1, y1, x1, y2);
        check2 = checkEmptyLine(x2, y2, x1, y2);
        if (check1 && check2)
        {
            return true;
        }
    }
    return false;
}

bool SlidingGame::checkZMatching(int x1, int y1, int x2, int y2) // Checks Z-shaped matching
{
    if (y1 == y2 || x1 == x2)
    {
        return false;
    }

    bool check1, check2, check3;
    int a, b;
    a = min(x1, x2);
    b = max(x1, x2);
    for (int i = a + 1; i < b; i++) {
        check3 = checkEmptyLine(i, y1, i, y2);
        if (check3)
        {
            check1 = checkEmptyLine(x1, y1, i, y1);
            check2 = checkEmptyLine(x2, y2, i, y2);
            if (check1 && check2)
                return true;
        }
    }
    a = min(y1, y2);
    b = max(y1, y2);
    for (int i = a + 1; i < b; i++)
    {
        check3 = checkEmptyLine(x1, i, x2, i);
        if (check3)
        {
            check1 = checkEmptyLine(x1, y1, x1, i);
            check2 = checkEmptyLine(x2, y2, x2, i);
            if (check1 && check2)
                return true;
        }
    }
    return false;
}

bool SlidingGame::checkUMatching(int x1, int y1, int x2, int y2) // Checks U-shaped matching
{
    if (((y1 == y2) && (y1 == 1 || y1 == height) || ((x1 == x2) && (x1 == 1 || x1 == width))))
    {
        return true;
    }

    bool check1, check2, check3;
    int a, b;

    a = min(x1, x2);
    b = max(x1, x2);
    for (int i = 1; i <= width; i++)
    {
        if (i <= a || i >= b)
        {
            check3 = checkEmptyLine(i, y1, i, y2);
            if (check3)
            {
                check1 = checkEmptyLine(x1, y1, i, y1);
                check2 = checkEmptyLine(x2, y2, i, y2);

                if (check1 && check2)
                    return true;
            }
            else if (i == 1 || i == width)
            {
                check1 = checkEmptyLine(x1, y1, i, y1);
                check2 = checkEmptyLine(x2, y2, i, y2);
                if ((check1 && check2) || (check1 && x2 == i) || (x1 == i && check2))
                    return true;
            }
        }
    }

    a = min(y1, y2);
    b = max(y1, y2);
    for (int i = 1; i <= height; i++)
    {
        if (i <= a || i >= b)
        {
            check3 = checkEmptyLine(x1, i, x2, i);
            if (check3)
            {
                check1 = checkEmptyLine(x1, y1, x1, i);
                check2 = checkEmptyLine(x2, y2, x2, i);
                if (check1 && check2)
                    return true;
            }
            else if (i == 1 || i == height)
            {
                check1 = checkEmptyLine(x1, y1, x1, i);
                check2 = checkEmptyLine(x2, y2, x2, i);
                if ((check1 && check2) || (check1 && y2 == i) || (y1 == i && check2))
                    return true;
            }
        }
    }
    return false;
}

bool SlidingGame::checkAllMatchings(int x1, int y1, int x2, int y2) // Checks all matchings
{
    if (checkIMatching(x1, y1, x2, y2))
        return true;
    if (checkLMatching(x1, y1, x2, y2))
        return true;
    if (checkZMatching(x1, y1, x2, y2))
        return true;
    if (checkUMatching(x1, y1, x2, y2))
        return true;
    return false;
}

bool SlidingGame::checkValidPairs() // Checks whether there is any pair that can be matched
{
    char character = 'A';
    while (character >= 'A' && character <= 'Z')
    {
        int count = 0;
        int *pos = new int[remainingPairs * 2 * 2];
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (findNode(j + 1, i + 1) != NULL)
                {
                    if (findNode(j + 1, i + 1)->character == character)
                    {
                        pos[count++] = i;
                        pos[count++] = j;
                    }
                }
            }
        }

        for (int i = 0; i < count - 2; i += 2)
        {
            for (int j = i + 2; j < count; j += 2)
            {
                if (checkAllMatchings(pos[i + 1] + 1, pos[i] + 1, pos[j + 1] + 1, pos[j] + 1))
                {
                    delete[] pos;
                    return true;
                }
            }
        }
        character++;
        delete[] pos;
    }
    return false;
}

int SlidingGame::play() // Start game
{
    system("cls");
    PlaySound(NULL, NULL, 0);
    board[0][0].isHovered = true;
    x = 1, y = 1;

    int temp, key;
    int count = 0;
    int selected = 0;
    Position selectedPos[2];

    printSideMenu();
    printBackground(player.level);
    player.printStatusBar();

    int initialLife = player.life;
    int initialScore = player.currentScore;

    while (true)
    {
        if (player.life == 0)
        {
            Sleep(500);

            if (printYouLostScreen(player) == 1)
            {
                player.updatePlayer();
                return 1;
            }
            else
            {
                player.updatePlayer();
                return -1;
            }
        }

        if (remainingPairs == 0)
            break;

        if (!checkValidPairs())
        {

            player.life--;
            player.comboFactor = 1.0;
            player.printStatusBar();

            while (!checkValidPairs())
                shuffleBoard();

            playSound("shuffle.wav");
        }

        if (findNode(x, y) == NULL) // Find a valid cell if the cell we are hovering on no longer exists
        {
            int delta = 1;
            while (findNode(x, y) == NULL)
            {
                for (int i = -delta; i <= delta; i++)
                {
                    for (int j = -delta; j <= delta; j++)
                    {
                        if (y + i < 1 || y + i > height || x + j < 1 || x + j > width)
                            continue;

                        if (findNode(x + j, y + i) != NULL)
                        {
                            y = y + i;
                            x = x + j;
                            findNode(x, y)->isHovered = true;
                            goto exitLoop;
                        }
                    }
                }
            exitLoop:
                delta++;
            }
        }

        printBoard(); // Repeatedly print out the board

        temp = _getch();
        if (temp && temp != 224)
        {
            if (temp == 'M' || temp == 'm')
            {
                player.life = initialLife;
                player.currentScore = initialScore;
                return -1;
            }
            else if (temp == 'Q' || temp == 'q')
            {
                if (player.life > 1)
                {
                    player.life--;
                    player.printStatusBar();
                    suggestMove();
                }
            }
            else if (temp == 32) //When cell is selected
            {


                findNode(x, y)->isSelected = true;
                selectedPos[selected].x = x;
                selectedPos[selected].y = y;
                selected++;

                if (selected == 1) {
                    playSound("select.wav");
                }

                if (selected == 2)
                {
                    if (!(selectedPos[0].x == selectedPos[1].x && selectedPos[0].y == selectedPos[1].y)) // Check if two cells are not at the same spot
                    {

                        if (findNode(selectedPos[0].x, selectedPos[0].y)->character == findNode(selectedPos[1].x, selectedPos[1].y)->character)
                        {
                            if (checkAllMatchings(selectedPos[0].x, selectedPos[0].y, selectedPos[1].x, selectedPos[1].y))
                            {

                                findNode(selectedPos[0].x, selectedPos[0].y)->drawBox(player.level, 10);
                                findNode(selectedPos[1].x, selectedPos[1].y)->drawBox(player.level, 10);

                                Sleep(200);

                                findNode(selectedPos[0].x, selectedPos[0].y)->isSelected = false;
                                findNode(selectedPos[1].x, selectedPos[1].y)->isSelected = false;

                                int a, b;


                                if (selectedPos[0].x > selectedPos[1].x)
                                {
                                    deleteNode(selectedPos[0].x, selectedPos[0].y);
                                    a = countNodes(board[selectedPos[0].y - 1]);
                                    printCellBackground(player.level, a + 1, selectedPos[0].y);

                                    deleteNode(selectedPos[1].x, selectedPos[1].y);
                                    b = countNodes(board[selectedPos[1].y - 1]);
                                    printCellBackground(player.level, b + 1, selectedPos[1].y);
                                }
                                else
                                {
                                    deleteNode(selectedPos[1].x, selectedPos[1].y);
                                    b = countNodes(board[selectedPos[1].y - 1]);
                                    printCellBackground(player.level, b + 1, selectedPos[1].y);

                                    deleteNode(selectedPos[0].x, selectedPos[0].y);
                                    a = countNodes(board[selectedPos[0].y - 1]);
                                    printCellBackground(player.level, a + 1, selectedPos[0].y);
                                }

                                if (findNode(x, y) != NULL)
                                    findNode(x, y)->isHovered = true;

                                turnOffSuggestions();

                                remainingPairs--;
                                player.currentScore += 10 * player.comboFactor;
                                player.comboFactor += 0.1;
                                player.printStatusBar();
                            } else {
                                findNode(selectedPos[0].x, selectedPos[0].y)->isSelected = false;
                                findNode(selectedPos[1].x, selectedPos[1].y)->isSelected = false;

                                playSound("wrong_match.wav");
                                player.life--;
                                player.comboFactor = 1.0;
                                player.printStatusBar();
                            }
                        }
                        else
                        {
                            findNode(selectedPos[0].x, selectedPos[0].y)->drawBox(player.level, 12);
                            findNode(selectedPos[1].x, selectedPos[1].y)->drawBox(player.level, 12);

                            Sleep(300);

                            findNode(selectedPos[0].x, selectedPos[0].y)->isSelected = false;
                            findNode(selectedPos[1].x, selectedPos[1].y)->isSelected = false;

                            playSound("wrong_match.wav");
                            player.life--;
                            player.comboFactor = 1.0;
                            player.printStatusBar();
                        }
                    }
                    else
                    {
                        findNode(selectedPos[0].x, selectedPos[0].y)->isSelected = false;
                    }
                    selected = 0;
                }
            }
        }
        else
        {
            key = _getch();
            switch (key)
            {
                case KEY_UP:
                    moveUp();
                    break;
                case KEY_DOWN:
                    moveDown();
                    break;
                case KEY_RIGHT:
                    moveRight();
                    break;
                case KEY_LEFT:
                    moveLeft();
                    break;
            }
        }
    }

    if (player.currentScore > player.highestScore)
        player.highestScore = player.currentScore;

    if (player.level == 3) {
        player.currentScore = 0;
        player.level = 1;
        player.life = 10;
        player.comboFactor = 1.0;
    } else {
        player.level++;
        player.comboFactor = 1.0;
    }

    player.updatePlayer();

    Sleep(500);

    system("cls");
    switch (printYouWonScreen(player))
    {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
    }

    return -1;
}

void SlidingGame::initialize() {
    // Getting the number of cells based on the player's level
    switch (player.level) {
        case 1:
            height = 4;
            width = 7;
            break;
        case 2:
            height = 5;
            width = 8;
            break;
        case 3:
            height = 6;
            width = 9;
            break;
    }

    remainingPairs = (height * width) / 2;

    board = new SlidingCell * [height];
    for (int i = 0; i < height; i++) {
        board[i] = NULL;
        for (int j = 0; j < width; j++) {
            SlidingCell *p = new SlidingCell;
            p->i = i;
            p->j = j;
            p->next = NULL;
            push(board[i], p);
        }
    }

    int pairNum = (height * width) / 2;
    while (pairNum) {
        int i, j, cells = 2;
        char character = 65 + rand() % 26; // Getting a random character
        // Assign a pair
        while (cells) {
            i = rand() % height;
            j = rand() % width;
            SlidingCell *p = findNode(j + 1, i + 1);
            if (p->character == ' ') {
                p->character = character;
                cells--;
            }
        }
        pairNum--;
    }
}

void SlidingGame::printBoard() {
    for (int i = 0; i < height; i++) {
        SlidingCell *temp = board[i];
        while (temp != NULL) {
            temp->drawBox(player.level);
            temp = temp->next;
        }
    }
}

// Shuffles the board when there is no valid pair left
void SlidingGame::shuffleBoard() {
    for (int i = 0; i < height; i++) {
        SlidingCell *temp = board[i];
        while (temp != NULL) {
            temp->character = ' ';
            temp = temp->next;
        }
    }

    int temp = remainingPairs;

    while (temp) {
        int index, cells = 2;
        char character = 'A' + rand() % 26;
        while (cells)
        {
            index = rand() % (height * width);
            if (findNode(index % width + 1, index / width + 1) != NULL)
            {
                if (findNode(index % width + 1, index / width + 1)->character == ' ')
                {
                    findNode(index % width + 1, index / width + 1)->character = character;
                    cells--;
                }
            }
        }
        temp--;
    }

}

// Suggest a valid pair to the player, costing 1 HP
void SlidingGame::suggestMove() {
    char character = 'A';
    while (character >= 'A' && character <= 'Z') {
        int count = 0;
        int *pos = new int[remainingPairs * 2 * 2];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (findNode(j + 1, i + 1) != NULL)
                    if (findNode(j + 1, i + 1)->character == character) {
                        pos[count++] = i;
                        pos[count++] = j;
                    }
            }
        }

        for (int i = 0; i < count - 2; i += 2) {
            for (int j = i + 2; j < count; j += 2) {
                if (checkAllMatchings(pos[i + 1] + 1, pos[i] + 1, pos[j + 1] + 1, pos[j] + 1)) {
                    findNode(pos[i + 1] + 1, pos[i] + 1)->isSuggested = true;
                    findNode(pos[j + 1] + 1, pos[j] + 1)->isSuggested = true;

                    delete[] pos;
                    return;
                }
            }
        }
        character++;
        delete[] pos;
    }
}

// Turns off the suggestion if the player don't match the suggested pair
void SlidingGame::turnOffSuggestions() {
    for (int i = 0; i < height; i++) {
        SlidingCell *temp = board[i];
        while (temp != NULL) {
            if (temp->isSuggested == true)
                temp->isSuggested = false;
            temp = temp->next;
        }
    }
}
