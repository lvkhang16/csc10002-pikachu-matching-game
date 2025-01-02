#include "MenuAndControl.h"

// Read a text file containing decoration and prints it out
void readAndPrintDecor(const string &fileName, int x, int y) {
    string filePath = "..\\..\\assets\\graphics\\" + fileName;
    ifstream inputFile(filePath);

    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = x;
    pos.Y = y;

    if (inputFile) {
        string line;
        while (getline(inputFile, line)) {
            SetConsoleCursorPosition(screen, pos);
            pos.Y++;
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "Failed to open the file." << endl;
    }
}

// Prints out the whole background behind the board at the start of a level
void printBackground(int level) {
    fstream fs;
    string line;

    int startingX, startingY;

    switch (level) {
        case 1:
            fs.open("..\\..\\assets\\graphics\\cataperie.txt");
            startingX = 12;
            startingY = 4;
            setColor(10);
            break;
        case 2:
            fs.open("..\\..\\assets\\graphics\\ivysaur.txt");
            startingX = 12;
            startingY = 3;
            setColor(11);
            break;
        case 3:
            fs.open("..\\..\\assets\\graphics\\charizard.txt");
            startingX = 11;
            startingY = 2;
            setColor(12);
            break;
    }

    if (!fs) {
        cout << "Open file unsuccessfully!\n";
        return;
    }

    while (getline(fs, line)) {
        goTo(startingX, startingY++);
        cout << line;
    }

    setColor(15);
}

// Prints out the background behind the cell when it disappears
void printCellBackground(int level, int x, int y) {
    fstream fs;
    string line, cellLine, skipLine;
    int paddingX, paddingY, paddingFileX, paddingFileY;

    switch (level) {
        case 1:
            fs.open("..\\..\\assets\\graphics\\cataperie.txt");
            paddingX = 7;
            paddingY = 8;
            paddingFileX = 3;
            paddingFileY = 8;
            setColor(10);
            break;
        case 2:
            fs.open("..\\..\\assets\\graphics\\ivysaur.txt");
            paddingX = 4;
            paddingY = 6;
            paddingFileX = 0;
            paddingFileY = 7;
            setColor(11);
            break;
        case 3:
            fs.open("..\\..\\assets\\graphics\\charizard.txt");
            paddingX = 2;
            paddingY = 3;
            paddingFileX = 0;
            paddingFileY = 4;
            setColor(12);
            break;
    }

    for (int i = 0; i < paddingFileY + (y - 1) * 4; i++)
        getline(fs, skipLine);

    for (int i = 0; i < 5; i++) {
        getline(fs, line);
        cellLine = line.substr(paddingFileX + (x - 1) * 8, 9);
        goTo(paddingX + x * 8, paddingY + y * 4 + i);
        cout << cellLine;
    }

    setColor(15);
}

// Prints out the Intro screen to the game
void printIntro() {
    setColor(6);
    readAndPrintDecor("matchinggame.txt", 77, 10);

    setColor(6);
    readAndPrintDecor("pokemon_text.txt", 77, 15);
    
    setColor(12);
    readAndPrintDecor("intropokemon.txt", 12, 5);

    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD max_size = GetLargestConsoleWindowSize(screen);

    goTo(95, 30);
    setColor(7);
    cout << ". . . S T A R T I N G  S O O N . . .";

    unsigned char loadingCharacter = 219;
    goTo(77, 32);
    setColor(7);

    for (int i = 0; i <= 70; i++) {
        cout << loadingCharacter;
        Sleep(100);
    }

    setColor(15);
    system("cls");
}

// Prints out the decoration for the Main Menu screen
void printMenuDecor() {
    setColor(15);
    readAndPrintDecor("menutitle.txt", 32, 2);
    setColor(15);
    readAndPrintDecor("line.txt", 5, 17);
    setColor(15);
    goTo(65, 19);
    cout << "The Matching Game Project";
    goTo(63, 21);
    cout << "Lam Vi Khang - Le Nguyen Thao";
    setColor(15);
    readAndPrintDecor("line.txt", 5, 22);
    goTo(57, 24);
    cout << "Use Up arrow key and Down arrow key to move";
    readAndPrintDecor("bordern1.txt", 41, 27);
    readAndPrintDecor("bordern2.txt", 41, 32);
    readAndPrintDecor("bordern3.txt", 86, 27);
    readAndPrintDecor("bordern4.txt", 86, 32);
}

void printSideMenu() {
    setColor(6);
    readAndPrintDecor("bear.txt", 92, 3);

    setColor(15);

    goTo(105, 17);
    cout << "Press any arrow key to navigate";
    goTo(111, 18);
    cout << "through the board!";

    goTo(108, 20);
    cout << "Press space bar to select,";
    goTo(109, 21);
    cout << "press again to deselect";

    goTo(107, 23);
    cout << "Q: Suggest move (costs 1 HP)";
    goTo(117, 25);
    cout << "M: Menu";

    goTo(103, 27);
    cout << "Once there is no valid matching left,";
    goTo(108, 28);
    cout << "the board will automatically";
    goTo(110, 29);
    cout << "shuffle! (costs 1 HP)";
}

void printTutorialScreen() {
    system("cls");
    setColor(14);
    readAndPrintDecor("stars.txt", 6, 1);
    readAndPrintDecor("stars.txt", 93, 1);
    setColor(15);
    readAndPrintDecor("tutorial_table.txt", 46, 6);

    goTo(58, 36);
    cout << "Hit any key to return back to the main menu..." << endl;
    _getch();
}

int Player::chooseMode() // Choose between 'normal' and 'sliding' mode
{
    int choice = 1;

    while (true)
    {
        system("cls");
        setColor(15);
        readAndPrintDecor("game_console.txt", 13, 5);

        setColor(15);
        goTo(30, 30);
        readAndPrintDecor("choose_mode_text.txt", 58, 8);

        setColor(15);
        readAndPrintDecor("border.txt", 58, 20);
        readAndPrintDecor("normal.txt", 62, 21);
        readAndPrintDecor("border.txt", 108, 20);
        readAndPrintDecor("sliding.txt", 114, 21);

        if (mode != "")
        {
            if (mode == "normal")
            {
                goTo(71, 20);
                cout << "(Old data)";
                goTo(122, 20);
                cout << "(New data)";
            }

            if (mode == "sliding")
            {
                goTo(71, 20);
                cout << "(New data)";
                goTo(122, 20);
                cout << "(Old data)";
            }
        }

        goTo(54, 23);
        setColor(15);
        cout << (choice == 1 ? ">>> " : "  ") << endl;

        goTo(104, 23);
        setColor(15);
        cout << (choice == 2 ? ">>> " : "  ") << endl;

        char key = _getch();

        switch (key)
        {
            case 13: // Enter key
                switch (choice)
                {
                    case 1:
                        return 1;
                        break;
                    case 2:
                        // Sliding
                        return 2;
                        break;
                }
                break;
            case 75:
                if (choice > 1)
                {
                    choice--;
                }
                break;
            case 77:
                if (choice < 2) {
                    choice++;
                }
                break;
        }
    }
}

int printYouWonScreen(const Player &p) {
    int choice = 1;
    switch (p.level) {
        case 1:
            system("cls");
            setColor(14);
            readAndPrintDecor("stars.txt", 6, 1);
            readAndPrintDecor("stars.txt", 93, 1);
            setColor(6);
            readAndPrintDecor("sponge.txt", 25, 10);
            setColor(12);
            readAndPrintDecor("game_finished_text.txt", 74, 12);

            setColor(15);
            goTo(58, 36);
            cout << "Hit any key to return back to the main menu..." << endl;
            _getch();
            return 2;
            break;
        case 2:
        case 3:
            while (true) {
                system("cls");
                setColor(14);
                readAndPrintDecor("stars.txt", 6, 1);
                readAndPrintDecor("stars.txt", 93, 1);
                setColor(10);
                readAndPrintDecor("you_won_text.txt", 28, 7);
                setColor(7);
                goTo(30, 30);
                readAndPrintDecor("continue.txt", 59, 20);
                setColor(10);
                readAndPrintDecor("border1.txt", 65, 28);
                setColor(12);
                readAndPrintDecor("border2.txt", 65, 33);

                goTo(61, 30);
                setColor(7);
                cout << (choice == 1 ? ">> " : "  ") << endl;

                goTo(61, 35);
                setColor(7);
                cout << (choice == 2 ? ">> " : "  ") << endl;

                char key = _getch();

                switch (key) {
                    case 13: // Enter key
                        switch (choice) {
                            case 1: // Level up
                                return 1;
                                break;
                            case 2:
                                // Go back to the menu screen
                                return 2;
                                break;
                        }
                        break;
                    case 72: // Up arrow key
                        if (choice > 1) {
                            choice--;
                        }
                        break;
                    case 80: // Down arrow key
                        if (choice < 2) {
                            choice++;
                        }
                        break;
                }
            }
            break;
    }

    return -1;
}

int printYouLostScreen(Player &p) {
    int choice = 1;

    while (true) {
        system("cls");
        setColor(7);
        readAndPrintDecor("computer.txt", 20, 5);
        setColor(10);
        readAndPrintDecor("game_over_text.txt", 43, 8);

        setColor(7);
        goTo(30, 30);
        readAndPrintDecor("replay.txt", 105, 8);
        setColor(10);
        readAndPrintDecor("border1.txt", 110, 18);
        setColor(12);
        readAndPrintDecor("border2.txt", 110, 24);

        goTo(107, 20);
        setColor(7);
        cout << (choice == 1 ? ">> " : "  ") << endl;

        goTo(107, 26);
        setColor(7);
        cout << (choice == 2 ? ">> " : "  ") << endl;

        char key = _getch();

        switch (key) {
            case 13: // Enter key
                switch (choice) {
                    case 1:
                        // Replay
                        p.level = 1;
                        p.life = 10;
                        p.currentScore = 0;
                        p.comboFactor = 1.0;
                        return 1;
                        break;
                    case 2:
                        // Go back to the menu screen
                        p.level = 1;
                        p.life = 10;
                        p.currentScore = 0;
                        p.comboFactor = 1.0;
                        return 2;
                        break;
                }
                break;
            case 72: // Up arrow key
                if (choice > 1) 
                    choice--;
                break;
            case 80: // Down arrow key
                if (choice < 2) 
                    choice++;
                break;
        }
    }
}

void Player::printStatusBar() // Prints out a little bar showing the player's current score and HP
{
    goTo(96, 9);
    cout << "Score: " << currentScore << "   ";
    goTo(96, 11);
    cout << "HP: " << life << "    ";
}

int Player::signIn() // Prints out the screen for signing in
{
    int option = 0;

    system("cls");
    setColor(14);
    readAndPrintDecor("stars.txt", 6, 1);
    readAndPrintDecor("stars.txt", 93, 1);
    setColor(15);
    readAndPrintDecor("sign_in_frame.txt", 40, 8);
    goTo(60, 16);
    cout << "Please enter the username and password " << endl;
    goTo(64, 20);
    cout << "USERNAME: ";
    getline(cin, username);
    goTo(64, 22);
    cout << "PASSWORD: ";
    getline(cin, password);

    system("cls");

    switch (getInfo())
    {
        case 1:
            goTo(63, 16);
            cout << "Sorry! Your account is not found!\n";
            goTo(58, 36);
            cout << "Hit any key to return back to the main menu..." << endl;
            _getch();
            return 1;
            break;

        case 2:
            goTo(63, 13);
            cout << "Wrong password!\n";
            goTo(63, 16);
            cout << "Your password is: " << password << '\n';
            goTo(58, 36);
            cout << "Hit any key to return back to the main menu..." << endl;
            _getch();
            return 2;
            break;

        case 3: // Sign in successfully!

            switch (chooseMode()) // Let the player choose the mode they want to play after signing in successfully
            {
                case 1: // Choose 'Normal'
                    if (mode == "sliding") // If the player chooses a different mode
                    {
                        mode = "normal";
                        level = 1;
                        life = 10;
                        currentScore = 0;
                        comboFactor = 1.0;
                        updatePlayer();
                    }
                    else
                    {
                        mode = "normal";
                        updatePlayer();
                    }
                    break;
                case 2: // Choose 'Sliding'
                    if (mode == "normal") // If the player chooses a different mode
                    {
                        mode = "sliding";
                        level = 1;
                        life = 10;
                        currentScore = 0;
                        comboFactor = 1.0;
                        updatePlayer();
                    }
                    else
                    {
                        mode = "sliding";
                        updatePlayer();
                    }
                    break;
            }

            system("cls");
            setColor(14);
            readAndPrintDecor("stars.txt", 6, 1);
            readAndPrintDecor("stars.txt", 93, 1);
            setColor(15);
            readAndPrintDecor("welcome_text.txt", 60, 16);
            Sleep(300);
            return 3;
    }

    return -1;
}

// Prints out the screen for signing up
int Player::signUp() {
    system("cls");
    setColor(14);
    readAndPrintDecor("stars.txt", 6, 1);
    readAndPrintDecor("stars.txt", 93, 1);
    setColor(15);
    readAndPrintDecor("sign_up_frame.txt", 47, 6);
    goTo(67, 17);
    cout << "Your username: ";
    getline(cin, username);
    goTo(67, 19);
    cout << "Your password: ";
    getline(cin, password);

    fstream fs("..\\..\\assets\\players_database.txt", ios::out | ios::app);
    if (fs)
    {
        if (getInfo() == 2 || getInfo() == 3) // Username already existed, unable to create an account
        {
            goTo(68, 23);
            cout << "Username already existed!\n";
            goTo(58, 36);
            cout << "Hit any key to return back to the main menu..." << endl;
            _getch();
            return 1;
        }
        else // Sign up successfully
        {
            fs << username << ',' << password << ',';
            fs << mode << ',' << 1 << ',' << 0 << ',' << 0 << ',' << 10 << ',' << 1.0 << '\n';
            fs.close();

            goTo(67, 22);
            cout << "Registration is successful!";

            goTo(58, 36);
            cout << "Hit any key to return back to the main menu..." << endl;
            _getch();

            return 2;
        }
    }
    else
    {
        cout << "Can't open file!\n";
        return 0;
    }
}

int Player::getInfo() {
    fstream fs("..\\..\\assets\\data\\players_database.txt", ios::in);
    string getUsername, getPassword, skipLine;
    char skipChar;

    if (!fs) {
        return 0;
    }

    while (getUsername != username && !fs.eof()) {
        getline(fs, skipLine);
        getline(fs, getUsername, ',');
        getline(fs, getPassword, ',');
    }

    // No such player in database
    if (getUsername != username) {
        fs.close();
        return 1;
    } else {
        // Wrong password
        if (getPassword != password) {
            password = getPassword;
            fs.close();
            return 2;
        } else {
            // Correct information
            getline(fs, mode, ',');
            fs >> level >> skipChar;
            fs >> currentScore >> skipChar;
            fs >> highestScore >> skipChar;
            fs >> life >> skipChar;
            fs >> comboFactor;
            fs.close();
            return 3;
        }
    }

    return -1;
}

bool comparePlayerScores(const Player& p1, const Player& p2) {
    return p1.highestScore > p2.highestScore;
}

void sortLeaderboard(Player leaderboard[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparePlayerScores(leaderboard[j + 1], leaderboard[j])) {
                Player temp = leaderboard[j];
                leaderboard[j] = leaderboard[j + 1];
                leaderboard[j + 1] = temp;
            }
        }
    }
}

void showLeaderboard(Player leaderboard[]) {
    system("cls");
    setColor(14);
    readAndPrintDecor("stars.txt", 6, 1);
    readAndPrintDecor("stars.txt", 93, 1);
    setColor(15);
    readAndPrintDecor("leaderboard_text.txt", 18, 2);
    setColor(15);
    readAndPrintDecor("line.txt", 5, 10);
    setColor(15);
    goTo(20, 12);
    cout << "RANK";
    goTo(52, 12);
    cout << "USERNAME";
    goTo(130, 12);
    cout << "SCORE";
    setColor(7);
    readAndPrintDecor("line.txt", 5, 13);
    cout << "\n\n";

    fstream fs("..\\..\\assets\\data\\players_database.txt", ios::in);
    string skipLine, getHighestScore, token;

    int n = 0;
    getline(fs, skipLine); // Skip the first line
    while (getline(fs, leaderboard[n].username, ',')) {
        for (int i = 0; i < 4; i++)
            getline(fs, token, ',');
        fs >> leaderboard[n].highestScore;
        getline(fs, skipLine);
        n++;
    }

    sortLeaderboard(leaderboard, n);

    int rank = 1, numberToShow;
    if (n < 10) {
        numberToShow = n;
    } else {
        numberToShow = 10;
    }

    for (int i = 0; i < numberToShow * 2; i += 2) {
        goTo(20, 15 + i);
        cout << rank;
        goTo(52, 15 + i);
        cout << leaderboard[i / 2].username;
        goTo(130, 15 + i);
        cout << leaderboard[i / 2].highestScore;
        rank++;
    }

    goTo(58, 36);
    cout << "Hit any key to return back to the main menu..." << endl;

    char key = _getch();
}

// Prints out the main menu screen
int Player::printMenu() {
    playBackgroundMusic();

    int choice = 1;
    while (true) {
        system("cls");
        printMenuDecor();
        setColor(15);
        goTo(38, 29);
        cout << (choice == 1 ? ">> " : "  ") << endl;
        goTo(38, 34);
        cout << (choice == 2 ? ">> " : "  ") << endl;
        goTo(83, 29);
        cout << (choice == 3 ? ">> " : "  ") << endl;
        goTo(83, 34);
        cout << (choice == 4 ? ">> " : "  ") << endl;

        switch (_getch()) {
            case 13: // Click 'Enter'
                switch (choice) {
                    case 1: // Sign in
                        return 1;
                        break;
                    case 2: // Sign up
                        return 2;
                        break;
                    case 3: // Show leaderboard
                        return 3;
                        break;
                    case 4: // Show tutorial
                        return 4;
                        break;
                }
                break;
            case 72: // Up arrow key
                if (choice > 1) {
                    choice--;
                }
                break;
            case 80: // Down arrow key
                if (choice < 4) {
                    choice++;
                }
                break;
        }
    }
}

// Updates the player's info to the file players_database.txt
void Player::updatePlayer() {
    fstream input("..\\..\\assets\\data\\players_database.txt", ios::in);
    fstream output("..\\..\\assets\\data\\PlayersData2.txt", ios::out);
    if (!input || !output) {
        cout << "Unable to update player's data!\n";
        return;
    }

    string getUsername, getPassword, skipLine, line;
    char skipChar;

    getline(input, line); // Ignore first line
    output << line << '\n';

    getline(input, getUsername, ',');
    while (getUsername != username) {
        output << getUsername << ',';
        getline(input, line);
        output << line << '\n';
        getline(input, getUsername, ',');
    }

    output << username << ',' << password << ',' << mode << ',' << level << ',' << currentScore << ',' << highestScore << ',' << life << ',' << comboFactor << '\n';

    getline(input, skipLine);

    while (getline(input, line)) {
        output << line << '\n';
    }

    input.close();
    output.close();

    remove("..\\..\\assets\\data\\players_database.txt");
    rename("..\\..\\assets\\data\\PlayersData2.txt", "..\\..\\assets\\data\\players_database.txt");
}
