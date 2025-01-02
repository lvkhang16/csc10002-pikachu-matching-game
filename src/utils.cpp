#include "utils.h"

// Sets color of a specific text
void setColor(int colorCode) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, colorCode);
}

// Move the cursor to a specified coordinate
void goTo(short x, short y) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Coord;
    Coord.X = x;
    Coord.Y = y;
    SetConsoleCursorPosition(hStdout, Coord);
}

// Hides the mouse cursor
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

// Zooms the console window
void zoomScreen() {
    HWND Hwnd = GetForegroundWindow();
    ShowWindow(Hwnd, SW_MAXIMIZE);
}

// Zooms the console to full screen
void zoomScreen2() {
    HWND Hwnd = GetForegroundWindow();
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    LONG winstyle = GetWindowLong(Hwnd, GWL_STYLE);
    SetWindowLong(Hwnd, GWL_STYLE, (winstyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
    SetWindowPos(Hwnd, HWND_TOP, 0, 0, x, y, 0);
}

void playMusic(const string& fileName) {
    string filePath = "..\\..\\assets\\sounds\\" + fileName;
    PlaySound(TEXT(filePath.c_str()), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void playSound(const string& fileName) {
    string filePath = "..\\..\\assets\\sounds\\" + fileName;
    PlaySound(TEXT(filePath.c_str()), NULL, SND_FILENAME | SND_ASYNC);
}

void playBackgroundMusic() {
    playMusic("background_music.wav");
}

// For debugging
void log(const string& message) {
    ofstream logFile("game_log.txt", ios::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
}
