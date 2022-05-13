#pragma once

void drawLoadMenu();
void saveGame(HANDLE old);
void writeSaveFile();
void gotoXY(int x, int y);
bool start = false;
unsigned long long countDownStartTime = 0;
void setTextColor(int color);
void countDown();
void drawBoard(int height, int width, int posX, int posY);
#define GameWidth 100
#define GameHeight 30

#define InteractOrigin_x 0
#define InteractOrigin_y 0
void drawIntroduction();
HANDLE old = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE buffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);