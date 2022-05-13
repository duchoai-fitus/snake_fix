#include <iostream>
#include <windows.h>
#include <string>
#include <chrono>
#include <thread>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <locale>
#include <codecvt>
#include <ctime>
#include <io.h>
#include <fcntl.h>
#include <algorithm>
#include <conio.h>
#include <ctype.h>
#include <sstream>
#include "sound.h"
#include "game.h"

using namespace std;

wifstream fin;

using namespace std;

void gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm đổi màu chữ
void FixConsoleColor(int k)
{
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, k);
}

// Hàm cố định cửa sổ console
void FixConsoleWindow()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// Hàm vẽ bảng thông báo bao gồm (tọa độ góc trái cùng, độ cao và chiều dài)
void DrawMessBoard(int x, int y, int h, int w)
{
    // Vẽ góc
    /*FixConsoleColor(244);*/
    gotoXY(x, y);
    cout << "╔";
    /*FixConsoleColor(244);*/
    gotoXY(x + w, y);
    cout << "╗";
    /*FixConsoleColor(244);*/
    gotoXY(x, y + h);
    cout << "╚";
    /*FixConsoleColor(244);*/
    gotoXY(x + w, y + h);
    cout << "╝";

    for (int i = 1; i < h; i++)
    {
        // Vẽ cột
        /*FixConsoleColor(244);*/
        gotoXY(x, y + i);
        cout << "║";
        /*FixConsoleColor(244);*/
        gotoXY(x + w, y + i);
        cout << "║";
    }

    for (int i = 1; i < w; i++)
    {
        // Vẽ dòng
        /*FixConsoleColor(244);*/
        gotoXY(x + i, y);
        cout << "═";
        /*FixConsoleColor(244);*/
        gotoXY(x + i, y + h);
        cout << "═";
    }
    cout << endl;
}

// Hàm hiển thị tên các thành viên nhóm
void Mes_Exit(int x, int y)
{
    FixConsoleColor(244);
    gotoXY(x, y);
    cout << " Trưởng nhóm:   Vũ Tiến Đạt.";
    FixConsoleColor(244);
    gotoXY(x, y + 2);
    cout << " Thành viên:";
    FixConsoleColor(244);
    gotoXY(x + 15, y + 2);
    cout << " Nguyễn Đức Hoài.";
    FixConsoleColor(244);
    gotoXY(x + 15, y + 3);
    cout << " Nguyễn Gia Huy.";
    FixConsoleColor(244);
    gotoXY(x + 15, y + 4);
    cout << " Châu Hoàng Khoa.";
    FixConsoleColor(244);
    gotoXY(x + 15, y + 5);
    cout << " Trương Thế Hiển.";
}

// show info.
void Mes_exit()
{
    sound.playCredit();
    // 43 - 15 - 50 - 13
    const int Mes_BoardX = 33;
    const int Mes_BoardY = 15;
    const int Mes_BoardH = 13;
    const int X = Mes_BoardX;
    const int Y = Mes_BoardH + Mes_BoardY;
    for (int i = Y; i > -Y+18; i--)
    {
        int j = 0;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "  Trường Đại học Khoa học Tự nhiên     ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "                                        ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            cout << "        ĐỒ ÁN CUỐI KÌ KTLT      ";

        }; j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "  MÔ PHỎNG RẮN SĂN MỒI - SNAKE GAME ";

        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "                                        ";
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "Lớp:                                    ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "             21CTT4                     ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "                                        ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "Giảng viên hướng dẫn:              ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "             Trương Toàn Thịnh    ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "                                        ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "Nhóm thực hiện:                   ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "             Nhóm 5               ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y) cout << "                                        ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "Các thành viên:                   ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "             Vũ Tiến Đạt. (C)";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "             Trương Thế Hiển.           ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "             Nguyễn Đức Hoài.          ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "             Nguyễn Gia Huy.       ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "             Châu Hoàng Khoa.       ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "                                        ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "                                        ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "                                        ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "                                        ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "                                        ";
            ;
        }j++;
        if (i + j > Mes_BoardY && i + j < Y)
        {
            gotoXY(X, i + (j));
            if (i + j <= Y)
                cout << "                                        ";
            ;
        }j++;
        Sleep(450);
    }
}

// Hàm intro (fixed)
void loading()
{
    // Đổi nền thành màu trắng
    system("color f0");

    // Đổi màu cho các kí tự in ra
    for (int i = 249; i < 253; i++) {
        gotoXY(1, 1);
        FixConsoleColor(i);
        cout << "▓▓░░░░";
        gotoXY(1, 2);
        FixConsoleColor(i);
        cout << "▒▒████";
        gotoXY(1, 3);
        FixConsoleColor(i);
        cout << "▒▒▒▒▒▒████";
        gotoXY(1, 4);
        FixConsoleColor(i);
        cout << "▒▒▒▒░░▒▒▒▒▒▒";
        gotoXY(1, 5);
        FixConsoleColor(i);
        cout << "░░░░▒▒▒▒▒▒▒▒▓▓██";
        gotoXY(1, 6);
        FixConsoleColor(i);
        cout << "▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒████                ██████";
        gotoXY(1, 7);
        FixConsoleColor(i);
        cout << "▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒██████        ██▒▒▒▒▒▒██████████          ████████";
        gotoXY(1, 8);
        FixConsoleColor(i);
        cout << "▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
        gotoXY(1, 9);
        FixConsoleColor(i);
        cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████        ██▓▓▒▒▒▒▒▒▓▓██";
        gotoXY(1, 10);
        FixConsoleColor(i);
        cout << "  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓██  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██    ▒▒▒▒▒▒▒▒  ██▒▒▒▒▒▒██";
        gotoXY(1, 11);
        FixConsoleColor(i);
        cout << "▒▒    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓██  ▒▒▒▒██████▒▒▒▒  ██▒▒██▒▒████";
        gotoXY(1, 12);
        FixConsoleColor(i);
        cout << "▒▒▒▒▒▒    ▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████  ▒▒▒▒██░░░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██";
        gotoXY(1, 13);
        FixConsoleColor(i);
        cout << "▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░  ██    ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██████";
        gotoXY(1, 14);
        FixConsoleColor(i);
        cout << "▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████░░    ██    ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██████";
        gotoXY(1, 15);
        FixConsoleColor(i);
        cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██    ██    ██▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██";
        gotoXY(1, 16);
        FixConsoleColor(i);
        cout << "▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒      ▒▒▒▒████    ██▒▒▒▒▓▓████▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██";
        gotoXY(1, 17);
        FixConsoleColor(i);
        cout << "██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒  ▒▒▒▒▒▒████▒▒▒▒▒▒██▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██";
        gotoXY(1, 18);
        FixConsoleColor(i);
        cout << "  ██████▓▓▒▒▒▒▒▒▒▒▒▒▒▒  ░░████  ▒▒▒▒  ▒▒▒▒▒▒████  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░██  ▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒██";
        gotoXY(1, 19);
        FixConsoleColor(i);
        cout << "        ████▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓██    ▒▒▒▒▒▒██▓▓▓▓██  ▒▒▒▒▒▒▒▒▒▒    ░░██░░██  ▒▒▒▒▓▓██▒▒▒▒▒▒██";
        gotoXY(1, 20);
        FixConsoleColor(i);
        cout << "            ██▓▓▒▒▓▓▓▓▒▒▒▒▒▒██▓▓▓▓▒▒▒▒▒▒██▓▓▓▓▒▒▓▓▓▓░░▒▒▒▒░░░░▓▓▓▓▓▓░░▓▓██  ░░  ▒▒▒▒▒▒▒▒▓▓░░";
        gotoXY(1, 21);
        FixConsoleColor(i);
        cout << "              ████▒▒▓▓██▒▒▒▒▒▒▒▒▒▒██████▓▓▓▓▓▓▓▓▒▒████░░░░████▓▓▓▓▓▓██▓▓▓▓██████  ██████";
        gotoXY(1, 22);
        FixConsoleColor(i);
        cout << "                  ██▒▒▒▒██▒▒▒▒▒▒▒▒▓▓▒▒▓▓██▓▓▓▓▒▒██░░░░████▓▓▓▓████▓▓▓▓▓▓██      ██";
        gotoXY(1, 23);
        FixConsoleColor(i);
        cout << "                    ██▓▓██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓████▒▒██░░░░░░▒▒████░░░░██████░░    ";
        gotoXY(1, 24);
        FixConsoleColor(i);
        cout << "                          ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓▓░░░░░░░░░░░░░░░░░░░░██▒▒▓▓  ";
        gotoXY(1, 25);
        FixConsoleColor(i);
        cout << "                            ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓████░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓";
        gotoXY(1, 26);
        FixConsoleColor(i);
        cout << "                                ██████▒▒▒▒▒▒▒▒▒▒▒▒▓▓██░░░░░░████████░░░░░░░░░░  ██";
        gotoXY(1, 27);
        FixConsoleColor(i);
        cout << "                                      ████▒▒▒▒▒▒▒▒▒▒▓▓██░░██▓▓▓▓██  ██████░░░░░░  ██";
        gotoXY(1, 28);
        FixConsoleColor(i);
        cout << "                                          ████▒▒▒▒▒▒▒▒▓▓████▒▒▒▒██  ██▓▓▓▓████░░░░  ████    ██";
        gotoXY(1, 29);
        FixConsoleColor(i);
        cout << "                                              ████▒▒▒▒▒▒▒▒▒▒██▒▒██    ████▓▓▓▓██░░░░    ████  ██";
        gotoXY(1, 30);
        FixConsoleColor(i);
        cout << "                                                  ██▒▒▒▒▒▒▒▒▓▓██░░░░████▓▓▒▒██  ▓▓██░░░░░░░░░░██";
        gotoXY(1, 31);
        FixConsoleColor(i);
        cout << "                                                    ████▒▒▒▒▒▒▓▓████▓▓▓▓▒▒██        ████░░░░██";
        gotoXY(1, 32);
        FixConsoleColor(i);
        cout << "                                                    ░░░░▓▓▒▒▒▒▒▒▓▓▓▓▒▒████░░          ░░██▓▓░░";
        gotoXY(1, 33);
        FixConsoleColor(i);
        cout << "                                                          ████▒▒▒▒████";
        gotoXY(1, 34);
        FixConsoleColor(i);
        cout << "                                                              ████";

        Sleep(1000);
    }
    system("cls");
    system("color f0");
    gotoXY(20, 1);
    FixConsoleColor(244);
    cout << "░██████╗███╗░░██╗░█████╗░██╗░░██╗███████╗  ░██████╗░░█████╗░███╗░░░███╗███████╗";
    gotoXY(20, 2);
    FixConsoleColor(244);
    cout << "██╔════╝████╗░██║██╔══██╗██║░██╔╝██╔════╝  ██╔════╝░██╔══██╗████╗░████║██╔════╝";
    gotoXY(20, 3);
    FixConsoleColor(244);
    cout << "╚█████╗░██╔██╗██║███████║█████═╝░█████╗░░  ██║░░██╗░███████║██╔████╔██║█████╗░░";
    gotoXY(20, 4);
    FixConsoleColor(244);
    cout << "░╚═══██╗██║╚████║██╔══██║██╔═██╗░██╔══╝░░  ██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░";
    gotoXY(20, 5);
    FixConsoleColor(244);
    cout << "██████╔╝██║░╚███║██║░░██║██║░╚██╗███████╗  ╚██████╔╝██║░░██║██║░╚═╝░██║███████╗";
    gotoXY(20, 6);
    FixConsoleColor(244);
    cout << "╚═════╝░╚═╝░░╚══╝╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝  ░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝";


    gotoXY(20, 9);
    FixConsoleColor(244);
    cout << " █▄░▒█ ▒█░▒█ ▒█▀▀▀█ ▒█▀▄▀█   █▀▀";
    gotoXY(20, 10);
    FixConsoleColor(244);
    cout << "▒█▒█▒█ ▒█▀▀█ ▒█░░▒█ ▒█▒█▒█   ▀▀▄";
    gotoXY(20, 11);
    FixConsoleColor(244);
    cout << "▒█░░▀█ ▒█░▒█ ▒█▄▄▄█ ▒█░░▒█   ▄▄▀";



    gotoXY(36, 20);
    cout << " Loading...\n";
    gotoXY(36, 22);
    for (int i = 1; i <= 50; i++)
    {
        for (int t = 0; t <= 88888888; t++);
        FixConsoleColor(244);
        cout << "█";
    }
    Sleep(500);
    gotoXY(48, 24);
    cout << "⃝ PRESS B TO BEGIN ⃝" << endl;
    for (int i = 1; i <= 2; ++i)
    {
        Sleep(250);
        gotoXY(48, 24);
        cout << "                          ";
        Sleep(250);
        gotoXY(48, 24);
        cout << "⃝ PRESS B TO BEGIN ⃝" << endl;
    }
    while (true)
    {
        if (GetAsyncKeyState(0x42))
        {
            break;
        }
    }

}

// thank for playing (fixed)
void ExitGame()
{
    system("cls");
    FixConsoleColor(208);
    gotoXY(3, 5);
    cout << "▀▀█▀▀▒█░▒█░█▀▀█▒█▄░▒█▒█░▄▀▒█▀▀▀█   ▒█▀▀▀▒█▀▀▀█▒█▀▀█   ▒█▀▀█▒█░░░░█▀▀█▒█░░▒█▀█▀▒█▄░▒█▒█▀▀█";
    gotoXY(3, 6);
    cout << "░▒█░░▒█▀▀█▒█▄▄█▒█▒█▒█▒█▀▄░░▀▀▀▄▄   ▒█▀▀▀▒█░░▒█▒█▄▄▀   ▒█▄▄█▒█░░░▒█▄▄█▒█▄▄▄█▒█░▒█▒█▒█▒█░▄▄";
    gotoXY(3, 7);
    cout << "░▒█░░▒█░▒█▒█░▒█▒█░░▀█▒█░▒█▒█▄▄▄█   ▒█░░░▒█▄▄▄█▒█░▒█   ▒█░░░▒█▄▄█▒█░▒█░░▒█░░▄█▄▒█░░▀█▒█▄▄█";
    gotoXY(3, 8);
    cout << "";
    gotoXY(20, 9);
    cout << "";
    gotoXY(20, 10);
    cout << "";

    FixConsoleColor(209);
    DrawMessBoard(25, 13, 16, 50);
    FixConsoleColor(208);
    Mes_exit();
    gotoXY(35, 19);
    FixConsoleColor(208);
    cout << "█▀▀ █▀█ █▀█ █▀▄   █▄▄ █▄█ █▀▀ █";
    gotoXY(35, 20);
    cout << "█▄█ █▄█ █▄█ █▄▀   █▄█ ░█░ ██▄ ▄";
    gotoXY(41, 29);
    cout << "⃝ PRESS ESC TO END ⃝" << endl;
    while (true)
    {
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
    }
    //Mes_Exit(45, 15);
    writeSaveFile();
    SetConsoleActiveScreenBuffer(old);
    exit(0);
}

enum snakeState
{
    outside,
    goingIn,
    inside,
    goingOut
};

enum gameState{inMenu,inGame,inLoad,inPaused};

gameState state = inMenu;

struct coordinate
{
    int X, Y;
};
// Toa do
struct frame
{
    int sizeX, sizeY;
    vector<wchar_t> character;
    vector<int> color;
    frame() : sizeX(0), sizeY(0), character(), color() {};
    frame(int x, int y)
    {
        sizeX = x;
        sizeY = y;
        character.resize(x * y);
        color.resize(x * y);
    }
    void inputFrame()
    {
        for (int i = 0; i < sizeX * sizeY; i++)
        {
            fin >> character[i];
            if (character[i] == L'~')
                character[i] = L' ';
        }
        for (int i = 0; i < sizeX * sizeY; i++)
            fin >> color[i];
    }
};

frame map[10];

unordered_map<wstring, frame> object;

struct button
{
    int index;
    coordinate coordi;
    int sizeX, sizeY;
    LPCWSTR str;
};

list<button> buttons{
    {0, {35, 8}, 11, 3, L"RESUME"},
    {1, {35, 14}, 11, 3, L"SAVE GAME"},
    {2, {35, 20}, 11, 3, L"MAIN MENU"} };
list<button>::iterator cursor = buttons.begin();

int cursor2 = 0;
int cursor3 = 0;

int loadMics()
{
    fin.close();
    fin.open("resources//misc.txt");
    fin.imbue(locale(fin.getloc(), new codecvt_utf8_utf16<wchar_t>));
    int n, x, y;
    wstring t;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> t;
        fin >> x >> y;
        object[t] = frame(x, y);
        object[t].inputFrame();
    }
    return n;
}

int loadMap()
{
    fin.close();
    fin.open("resources//maps.txt");
    int n, x, y;
    fin >> n;
    for (int i = 1; i <= n + 1; i++)
    {
        fin >> x >> y;
        map[i] = frame(x, y);
        map[i].inputFrame();
    }
    return n;
}


unsigned long long frameN = 0;
int levelScore = 5;
int level = 0;
bool paused = true;
const int width = 50, height = 30; // Chieu rong , chieu cao

struct screen {
    int width, height;
    wchar_t* characters; // Ma tran man hinh
    WORD* color;     // Ma tran mau
    screen(const int width1, const int height1) {
        width = width1, height = height1;
        characters = (wchar_t*)malloc((width1 * height1) * sizeof(wchar_t)); // Ma tran man hinh
        color = (WORD*)malloc((width1 * height1) * sizeof(WORD));     // Ma tran mau
    }
    ~screen() {
        free(characters);
        free(color);
    }
};

screen screen1(width, height), screen2(width * 2, height);
// Khai bao 2 ma tran
// Hàm đổi từ mảng 2 chiều sang mảng 1 chiều

int index(const int& x, const int& y, screen& s)
{
    return y * s.width + x;
}
// Trên bản đồ có đồ ăn ko
// Tạo đồ ăn
unordered_set<int> food;
bool valid(int x, int y, int sizeX, int sizeY)
{
    for (int i = x; i < x + sizeX; i++)
        for (int j = y; j < y + sizeY; j++)
            if (screen1.characters[index(i, j, screen1)] != ' ')
                return false;
    return true;
}
coordinate findSpace(int sizeX = 1, int sizeY = 1)
{
    int x, y;
    do
    {
        x = rand() % height;
        y = rand() % height;
    } while (!valid(x, y, sizeX, sizeY));
    return { x, y };
}
coordinate portalPos = { -1, -1 };
int portalOrientation = 0;
unsigned long long portalSpawnTime = 0;
wstring MSSV = L"211204322112045021120454211204812112046821120432211204502112045421120481211204682112043221120450211204542112048121120468211204322112045021120454211204812112046821120432211204502112045421120481211204682112043221120450211204542112048121120468";

void drawFood(unordered_set<int> food)
{
    for (int x : food)
    {
        screen1.characters[x] = L'&';
        screen1.color[x] = 12 + 12 * 16;
    }
}
struct snake
{
    int score;
    unsigned long long deadTime;
    char direction;
    bool dead, levelFinished;
    float speed;
    snakeState state;
    list<coordinate> body;
    snake()
    {
        score = 0;
        levelFinished = false;
        deadTime = 0;
        state = inside;
        direction = 'D'; // Ban đầu hướng di chuyển là sang phải
        speed = 1;       // Tốc độ ban đầu của rắn
        dead = false;
        body = {
            {-50, -50},
            {-50 - 1, -50},
            {-50 - 2, -50},
            {-50 - 3, -50},
            {-50 - 4, -50},
        };
    }
    snake(const snake& old) {
        score = old.score;
        levelFinished = old.levelFinished;
        deadTime = old.deadTime;
        state = old.state;
        direction = old.direction; // Ban đầu hướng di chuyển là sang phải
        speed = old.speed;       // Tốc độ ban đầu của rắn
        dead = old.dead;
        body = list<coordinate>(old.body);

    }
    void resetData()
    {
        *this = snake();
    }
    // Di chuyen
    void move(char c)
    {
        switch (c)
        {
        case 'D':
            body.push_front({ body.front().X + 1, body.front().Y });
            break;
        case 'A':
            body.push_front({ body.front().X - 1, body.front().Y });
            break;
        case 'S':
            body.push_front({ body.front().X, body.front().Y + 1 });
            break;
        case 'W':
            body.push_front({ body.front().X, body.front().Y - 1 });
        } // Thêm vào đầu mới với vị trí theo hướng di chuyển

        // Kiem tra ran chet chua
        if (screen1.characters[index(body.front().X, body.front().Y, screen1)] == L'&')
        {
            // speed+=0.5;
            score++;
            sound.playEat1();
            food.erase(index(body.front().X, body.front().Y, screen1));
            if (!levelFinished)
            {
                coordinate t = findSpace();
                food.insert(index(t.X, t.Y, screen1));
            }
            return;
        }

        body.pop_back(); // Xoá phần đuôi
        if (state == goingIn && body.back().X < 0 && body.back().Y < 0)
        {
            state = inside;
        }
        if (state == goingOut && body.back().X >= 0 && body.back().Y >= 0)
        {
            state = outside;
            coordinate t = findSpace();
            food.insert(index(t.X, t.Y, screen1));
            levelFinished = false;
            portalPos = { -1, -1 };
        }
        if (screen1.characters[index(body.front().X, body.front().Y, screen1)] == L'I')
        {
            state = goingIn;
            body.front() = { -50, -50 };
            direction = 'W';
        }
        if (screen1.characters[index(body.front().X, body.front().Y, screen1)] != ' ' && (body.front().X >= 0 && body.front().Y >= 0)) // Nếu đầu rắn đi tới chỗ không phải là khoảng trống
        {
            // sound.playHitting();
            sound.playLose1();
            deadTime = frameN;
            dead = true;
        }
    }

} snake1;

// Ve ran
void draw(snake x)
{
    int j = x.body.size() - 1;
    for (list<coordinate>::reverse_iterator a = x.body.rbegin(); a != x.body.rend(); a++, j--)
        if (a->X >= 0 && a->Y >= 0)
        {
            if (x.dead)
            {
                if (frameN - x.deadTime < 120)
                {
                    screen1.color[index(a->X, a->Y, screen1)] = ((frameN - x.deadTime) / 15) % 2 ? (j == 0 ? 15 + 4 * 16 : 15 + 12 * 16) : (j == 0 ? 7 + 11 * 16 : 7 + 16 * 3);
                }
                else
                {
                    screen1.color[index(a->X, a->Y, screen1)] = j == 0 ? 15 + 4 * 16 : 15 + 12 * 16;
                }
                screen1.characters[index(a->X, a->Y, screen1)] = j == 0 ? L'x' : MSSV[j - 1];
            }
            else
            {
                screen1.color[index(a->X, a->Y, screen1)] = j == 0 ? 7 + 11 * 16 : 7 + 16 * 3;
                screen1.characters[index(a->X, a->Y, screen1)] = j == 0 ? (x.direction == 'D' || x.direction == 'A' ? ':' : '\"') : MSSV[j - 1];
            }
        }
}

void drawScore(snake a)
{
    wsprintfW(&screen1.characters[index(35, 10, screen1)], L"SCORE: %d/%d", a.score, levelScore);
    wsprintfW(&screen1.characters[index(35, 12, screen1)], L"LENGTH: %d", a.body.size());
}

void draw(screen& s, frame a, coordinate w, int orientation = 0, bool drawColor = true, bool drawSpace = false)
{
    int k;
    for (int i = 0; i < a.sizeX; i++)
        for (int j = 0; j < a.sizeY; j++)
        {
            switch (orientation)
            {
            case 0:
                k = index(w.X + i, w.Y + j, s);
                break;
            case 1:
                k = index(w.X - i + a.sizeX - 1, w.Y - j + a.sizeY - 1, s);
                break;
            case 2:
                k = index(w.X + j, w.Y + i, s);
                break;
            case 3:
                k = index(w.X - j + a.sizeY - 1, w.Y - i + a.sizeX - 1, s);
            }
            s.characters[k] = a.character[i + j * a.sizeX];
            if (drawColor && (s.characters[k] != ' ' || drawSpace))
                s.color[k] = a.color[i + j * a.sizeX];
        }
}

void drawPortal()
{
    if (portalPos.X >= 0 && portalPos.Y >= 0)
    {
        if (frameN - portalSpawnTime <= 60)
        {
            if (((frameN - portalSpawnTime) / 15) % 2)
                draw(screen1, object[L"portal"], portalPos, portalOrientation);
        }
        else
            draw(screen1, object[L"portal"], portalPos, portalOrientation);
    }
}

// Xoa man hinh
void clear(screen& s)
{
    for (int i = 0; i < s.width * s.height; i++)
    {
        s.characters[i] = L' ';   //Đặt kí tự khoảng trống
        s.color[i] = 14 * 16; // Mặc định chữ trắng, nền đen
    }
}

void resetGame()
{
    level--;
    snake1.resetData();
    food.clear();
}
// Lấy các lệnh di chuyển
unordered_map<char, bool> key = { {'W', false}, {'S', false}, {'A', false}, {'D', false}, {' ', false},{'[', false},{']', false},{'|',false} };

struct Save
{
    wstring name;
    int level;
    chrono::system_clock::time_point saveTime;
    snake snak;
};

vector<Save> save;

void writeSaveFile()
{
    fin.close();
    wofstream fout;
    fout.open("resources//save.txt");
    fout << save.size() << '\n';
    for (auto i : save)
    {
        fout << i.name << '\n';
        fout << i.level << '\n';
        fout << chrono::system_clock::to_time_t(i.saveTime) << '\n';
        fout << i.snak.score << '\n';
        fout << i.snak.deadTime << '\n';
        fout << i.snak.levelFinished << '\n';
        fout << i.snak.state << '\n';
        fout << (int)i.snak.direction << '\n';
        fout << i.snak.speed << '\n';
        fout << i.snak.dead << '\n';
        fout << i.snak.body.size() << '\n';
        for (auto a = i.snak.body.begin(); a != i.snak.body.end(); a++)
            fout << a->X << ' ' << a->Y << '\n';
    }
    fout.close();
}

void loadSaveFile()
{
    fin.close();
    fin.open("resources//save.txt");
    int n, t;
    time_t T;
    coordinate coordi;
    fin >> n;
    if (n > 0)
        save.resize(n);
    for (int i = 0; i < n; i++)
    {
        fin >> save[i].name;
        fin >> save[i].level;
        fin >> T;
        save[i].saveTime = chrono::system_clock::from_time_t(T);
        fin >> save[i].snak.score;
        fin >> save[i].snak.deadTime;
        fin >> save[i].snak.levelFinished;
        fin >> t;
        save[i].snak.state = (snakeState)t;
        fin >> t;
        save[i].snak.direction = (char)t;
        fin >> save[i].snak.speed;
        fin >> save[i].snak.dead;
        fin >> t;
        for (int j = 0; j < t; j++)
        {
            fin >> coordi.X >> coordi.Y;
            save[i].snak.body.push_back(coordi);
        }
    }
}

void loadSave(Save& save)
{
    snake1 = snake(save.snak);
    level = save.level;
    food.clear();
    coordinate t = findSpace();
    food.insert(index(t.X, t.Y, screen1));
}

void saveGame(HANDLE old)
{
    coordinate coordi = { 10, height / 2 };
    DWORD BytesWritten = 0;
    int sizeX = 30, sizeY = 4;
    for (int i = 0; i < sizeX; i++)
        for (int j = 0; j < sizeY; j++)
        {
            screen1.characters[index(coordi.X + i, coordi.Y + j, screen1)] = ' ';
            screen1.color[index(coordi.X + i, coordi.Y + j, screen1)] = j == 2 && !(i == 0 || i == sizeX - 1) ? 15 : 15 * 16;
        }
    wsprintfW(&screen1.characters[index(coordi.X + 2, coordi.Y + sizeY / 2 - 1, screen1)], L"ENTER YOUR NAME");

    WriteConsoleOutputCharacterW(old, screen1.characters, width * height, { 0, 0 }, &BytesWritten);
    WriteConsoleOutputAttribute(old, screen1.color, width * height, { 0, 0 }, &BytesWritten);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    SetConsoleCursorPosition(old, { (SHORT)(coordi.X + 2), (SHORT)(coordi.Y + 2) });
    save.resize(save.size() + 1);
    wcin >> save[save.size() - 1].name;
    save[save.size() - 1].snak = snake1;
    save[save.size() - 1].level = level;
    save[save.size() - 1].saveTime = chrono::system_clock::now();
    if (cursor3 < 0) cursor3 = 0;
    sound.playEnter();
}

bool optionAscendingTime(Save& a, Save& b) {
    return a.saveTime > b.saveTime;
}
bool optionAscendingScore(Save& a, Save& b) {
    return a.snak.score > b.snak.score;

}
int startLoadIndex = 0;

void input(HANDLE old)
{
    if ((GetAsyncKeyState('W') & 0x8000) && !key['W'] && (paused || snake1.direction != 'S'))
    {
        key['W'] = true;
        switch (state) {
        case inMenu:
            if (cursor2 > 0)
            {
                cursor2--;
                sound.playMenu();
            }
            break;
        case inGame:
            if (snake1.direction != 'S')
                snake1.direction = 'W';
            break;
        case inPaused:
            if (cursor != buttons.begin()) {
                cursor--;
                sound.playMenu();
            }
            if (snake1.dead)
            {
                state = inGame;
                sound.playError();
                resetGame();
            }
            break;
        case inLoad:
            if (save.size() > 1)
            {
                sound.playMenu();
            }
            
            if (cursor3 == 0 && startLoadIndex>0)
                startLoadIndex--;
            else if (cursor3 > 0)
                cursor3--;
            break;
        }
    }
    if (GetAsyncKeyState('W') == 0)
        key['W'] = false;

    if ((GetAsyncKeyState('D') & 0x8000) && !key['D'] && (paused || snake1.direction != 'A'))
    {
        key['D'] = true;
        if (paused)
        {
            if (snake1.dead)
            {
                state = inGame;
                sound.playError();
                resetGame();
                
            }
                
        }
        else
        {
            if (snake1.direction != 'A')
                snake1.direction = 'D';
        }
    }
    if (GetAsyncKeyState('D') == 0)
        key['D'] = false;

    if ((GetAsyncKeyState('S') & 0x8000) && !key['S'] && (paused || snake1.direction != 'W'))
    {
        key['S'] = true;
        switch (state) {
        case inMenu:
            if (cursor2 < 4)
            {
                sound.playMenu();
                cursor2++;
            }
            break;
        case inGame:
            if (snake1.direction != 'W')
                snake1.direction = 'S';
            break;
        case inPaused:
            if (cursor != prev(buttons.end())) {
                sound.playMenu();
                cursor++;
            }
            if (snake1.dead)
            {
                state = inGame;
                sound.playError();
                resetGame();
            }
            break;
        case inLoad:
            if (save.size() > 1)
            {
                sound.playMenu();
            }
            if (cursor3 == 18 && cursor3 + startLoadIndex+1 < save.size())
                startLoadIndex++;
            else if (cursor3 < min(save.size()- startLoadIndex-1, 18))
                cursor3++;
            break;
        }
        
    }
    if (GetAsyncKeyState('S') == 0)
        key['S'] = false;

    if ((GetAsyncKeyState('A') & 0x8000) && !key['A'] && (paused || snake1.direction != 'D'))
    {
        key['A'] = true;
        if (paused)
        {
            if (snake1.dead)
            {
                state = inGame;
                sound.playError();
                resetGame();
            }
        }
        else
        {
            if (snake1.direction != 'D')
                snake1.direction = 'A';
        }
    }
    if (GetAsyncKeyState('A') == 0)
        key['A'] = false;

    if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && !key[' '])
    {
        key[' '] = true;

        if (state==inPaused||state==inGame) {
            if (state == inPaused) state = inGame;
            else if (state == inGame) state = inPaused;
            paused = !paused;
            cursor = buttons.begin();
            if (snake1.dead)
            {
                state = inGame;
                sound.playError();
                resetGame();
            }
        }
    }
    if (GetAsyncKeyState(VK_SPACE) == 0)
        key[' '] = false;

    if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) && !key['['])
    {
        key['['] = true;
        switch (state) {
        case inPaused:
        case inGame:
            if (state == inPaused) state = inGame;
            if (state == inGame) state = inPaused;
            paused = !paused;
            cursor = buttons.begin();
            if (snake1.dead)
            {
                state = inGame;
                sound.playError();
                resetGame();
            }
            break;
        case inLoad:
            sound.playEnter();
            cursor2 = 0;
            state = inMenu;
            break;
        }
    }
    if (GetAsyncKeyState(VK_ESCAPE) == 0)
        key['['] = false;

    if ((GetAsyncKeyState(VK_DELETE) & 0x8000) && !key['|'])
    {
        key['|'] = true;

        if (state == inLoad) {
            if (save.size())
                save.erase(save.begin() + cursor3 + startLoadIndex);
            if (cursor3 == save.size() - startLoadIndex) cursor3--;
        }
    }
    if (GetAsyncKeyState(VK_DELETE) == 0)
        key['|'] = false;

    if ((GetAsyncKeyState(VK_RETURN) & 0x8000) && !key[']'])
    {
        key[']'] = true;
        switch (state) {
        case inMenu:
            sound.playEnter();
            switch (cursor2) {
            case 0:
                countDownStartTime = frameN;
                start = true;
                level = 0;
                snake1.resetData();
                sound.playReady();
                //activeMenu = false;
                break;
            case 1:
                sound.playEnter();
                if (save.size() > 0) {
                    countDownStartTime = frameN;
                    start = true;
                    sort(save.begin(), save.end(), optionAscendingTime);
                    loadSave(save.back());
                    sound.playReady();
                }
                break;
            case 2:
                sound.playEnter();
                state = inLoad;
                break;
            case 3:
                sound.playEnter();
                drawIntroduction();
                break;
            case 4:
                system("color D0");
                ExitGame();
            }
            break;
        case inPaused:
            switch (cursor->index)
            {
            case 0:
                sound.playEnter(); 
                state = inGame;
                paused = !paused;
                break;
            case 1:
                sound.playEnter();
                saveGame(old);
                writeSaveFile();
                break;
            case 2:
                sound.playEnter();
                state = inMenu;

                break;
            }
            break;
        case inLoad:
            loadSave(save[cursor3]);
            countDownStartTime = frameN;
            start = true;
            sound.playReady();
            break;
        }
    }
    if (GetAsyncKeyState(VK_RETURN) == 0)
        key[']'] = false;
}

void spawnPortal()
{
    portalOrientation = rand() % 4;
    coordinate t;
    if (portalOrientation < 2)
        t = findSpace(10, 3);
    else
        t = findSpace(3, 10);
    switch (portalOrientation)
    {
    case 0:
        portalPos = { t.X + 8, t.Y };
        break;
    case 2:
        portalPos = { t.X, t.Y + 8 };
        break;
    case 1:
    case 3:
        portalPos = t;
    }
}

void nextLevel()
{
    sound.playPassLevel();
    level++;
    snake1.score = 0;
    snake1.state = goingOut;
    coordinate snakePos;
    draw(screen1, map[level], { 0, 0 });
    spawnPortal();
    switch (portalOrientation)
    {
    case 0:
        snake1.direction = 'A';
        snakePos = { portalPos.X - 1, portalPos.Y + 1 };
        break;
    case 1:
        snake1.direction = 'D';
        snakePos = { portalPos.X + 2, portalPos.Y + 1 };
        break;
    case 2:
        snake1.direction = 'W';
        snakePos = { portalPos.X + 1, portalPos.Y - 1 };
        break;
    case 3:
        snake1.direction = 'S';
        snakePos = { portalPos.X + 1, portalPos.Y + 2 };
    }
    snake1.body.front() = snakePos;
}

void update()
{
    if (snake1.dead)
        paused = true;
    if (!paused)
        snake1.move(snake1.direction);
    if (snake1.state == inside)
        nextLevel();
    if (snake1.score >= levelScore && !snake1.levelFinished)
    {
        spawnPortal();
        portalSpawnTime = frameN;
        food.clear();
        snake1.levelFinished = true;
    }
    if (level > 5)
    {
        snake1.speed += 0.2;
        level = 1;
    }
}

void drawInfo()
{
    if (snake1.dead)
    {
        paused = true;
        wsprintfW(&screen1.characters[index(35, 12, screen1)], L"Dead");
        for (int i = 35; i < 35 + 4; i++)
            screen1.color[index(i, 12, screen1)] = 4;
        wsprintfW(&screen1.characters[index(35, 13, screen1)], L"PRESS ANYKEY");
    }
    wsprintfW(&screen1.characters[index(35, 8, screen1)], L"LEVEL %d", level);
    drawScore(snake1);
}

void drawScoreBar()
{
    coordinate t = { 35, 26 };
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 12; j++)
            if (i == 0 || j == 0 || i == 5 || j == 11)
            {
                screen1.characters[index(t.X + i, t.Y - j, screen1)] = L'B';
                screen1.color[index(t.X + i, t.Y - j, screen1)] = 255;
            }
            else
            {
                if (j <= (snake1.score / (float)levelScore) * 10)
                {
                    screen1.characters[index(t.X + i, t.Y - j, screen1)] = L'B';
                    screen1.color[index(t.X + i, t.Y - j, screen1)] = 10 + 16 * 10;
                }
                else
                    screen1.color[index(t.X + i, t.Y - j, screen1)] = 0;
            }
    }
}

void draw(button b, bool selected)
{
    if (b.sizeX - 2 <= wcslen(b.str))
        b.sizeX = wcslen(b.str) + 2;
    for (int i = 0; i < b.sizeX; i++)
        for (int j = 0; j < b.sizeY; j++)
        {
            screen1.characters[index(b.coordi.X + i, b.coordi.Y + j, screen1)] = L' ';
            screen1.color[index(b.coordi.X + i, b.coordi.Y + j, screen1)] = selected ? 6 * 16 : 15 * 16;
        }
    wsprintfW(&screen1.characters[index(b.coordi.X + (b.sizeX - wcslen(b.str)) / 2, b.coordi.Y + b.sizeY / 2, screen1)], b.str);
}

void drawSideBar()
{
    if (paused && !snake1.dead)
    {
        wsprintfW(&screen1.characters[index(35, 5, screen1)], L"PAUSED");
        for (list<button>::iterator b = buttons.begin(); b != buttons.end(); b++)
            draw(*b, b == cursor);
    }
    else
    {
        wsprintfW(&screen1.characters[index(35, 5, screen1)], L"RUNNING");
        drawInfo();
        drawScoreBar();
    }
}

void drawMenu() {
    draw(screen2, object[L"menu"], { 0,0 }, 0, true, true);
    switch (cursor2) {
    case 0:
        draw(screen2, object[L"newGame"], { 33,18 }, 0, false, false);
        break;
    case 1:
        draw(screen2, object[L"continue"], { 35,18 }, 0, false, false);
        break;
    case 2:
        draw(screen2, object[L"loadGame"], { 33, 18 }, 0, false, false);
        break;
    case 3:
        draw(screen2, object[L"introduction"], { 27,18 }, 0, false, false);
        break;
    case 4:
        draw(screen2, object[L"exit"], { 44,18 }, 0, false, false);
        break;
    }
}

void drawLoadMenu() {
    time_t t;
    draw(screen2, object[L"loadGame"],{width-17,2},0,false);
    draw(screen2, object[L"border"], {3,6}, 0, false);
    for (int i = 0; i < min(19,save.size()); i++) {
        t = chrono::system_clock::to_time_t(save[startLoadIndex+i].saveTime);
        char* str= ctime(&t);
        wstring wstr(str, str + strlen(str));
        wstr.pop_back();
        if (i == cursor3)
            for (int k = 4; k <= width * 2 - 5; k++)
                screen2.color[index(k,i+9,screen2)] = 96;
        wsprintfW(&screen2.characters[index(15, 9 + i, screen2)], &save[startLoadIndex+i].name[0]);
        wsprintfW(&screen2.characters[index(42, 9 + i, screen2)], L"%d", save[startLoadIndex+ i].level);
        wsprintfW(&screen2.characters[index(57, 9 + i, screen2)], L"%d", save[startLoadIndex+i].snak.score);
        wsprintfW(&screen2.characters[index(65, 9 + i, screen2)], &wstr[0]);
    }
        
}

void countDown() {
    
    if (countDownStartTime + 4 * 60 > frameN && start) {
        clear(screen2);
        float t = (frameN - countDownStartTime) / 60;
        
        if (t < 1)
            draw(screen2, object[L"three"], { width - 3,height / 2 - 3 });
        else if (t < 2)
            draw(screen2, object[L"two"], { width - 3,height / 2 - 3 });
        else if (t < 3)
            draw(screen2, object[L"one"], { width - 3,height / 2 - 3 });
        else if (t <4)
            draw(screen2, object[L"go"], { width - 9,height / 2 - 3 },0,false,false);
    }
    else if (countDownStartTime + 4 * 60 == frameN && start) {
        state = inGame;
        paused = false;
    }
}

void setTextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawBoard(int height, int width, int posX, int posY)
{
    gotoXY(posX, posY); cout << "╔";
    for (int i = 1, j = 1; i < height + width; i++, j++)
    {
        if (i < width) { gotoXY(posX + i, posY + 0); cout << "═"; }
        else if (i == width) { gotoXY(posX + width, posY + 0); cout << "╗"; }
        else { gotoXY(posX + width, posY + i - width); cout << "║"; }

        if (j < height) { gotoXY(posX + 0, posY + j); cout << "║"; }
        else if (i == height) { gotoXY(posX + 0, posY + height); cout << "╚"; }
        else { gotoXY(posX + j - height, posY + height); cout << "═"; }
    }
    gotoXY(posX + width, posY + height); cout << "╝";
}

#define GameWidth 100
#define GameHeight 30

#define InteractOrigin_x 0
#define InteractOrigin_y 0

// fixed.
void drawIntroduction()
{
    system("cls");
    system("color D0");
    Sleep(50);
    //chỉ số bảng thông tin của ae
    const int BoardLeftX = InteractOrigin_x + 3;
    const int BoardLeftY = InteractOrigin_y + 2 + 4 + 2;
    const int BoardLeftW = GameWidth / 3 + 10;
    const int BoardLeftH = GameHeight - 4 - 4 - 2;
    const int MemX = BoardLeftX + 5;
    const int FirstMemY = BoardLeftY + 5;
    const int SecMemY = BoardLeftY + 7;
    const int ThirdMemY = BoardLeftY + 9;
    const int FourthMemY = BoardLeftY + 11;
    const int FifthMemy = BoardLeftY + 13;

    //Chỉ số bảng HowToPlay
    const int BoardRightW = GameWidth - BoardLeftW - 6;
    const int BoardRightH = GameHeight - 4;
    const int BoardRightX = BoardLeftX + BoardLeftW + 2;
    const int BoardRightY = InteractOrigin_y + 3;
    while (true) {
        //Nội dung bảng Howtoplay
        setTextColor(208);
        /*gotoXY(BoardRightX + BoardRightW / 2 - 6, BoardRightY - 1);*/
        gotoXY(BoardRightX + BoardRightW / 2 - 20, BoardRightY - 2);
        /*cout << "HOW TO PLAY";*/
        cout << "█░█ █▀█ █░█░█  ▀█▀ █▀█  █▀█ █░░ ▄▀█ █▄█";
        gotoXY(BoardRightX + BoardRightW / 2 - 20, BoardRightY - 1);
        cout << "█▀█ █▄█ ▀▄▀▄▀  ░█░ █▄█  █▀▀ █▄▄ █▀█ ░█░";
        setTextColor(209);
        drawBoard(BoardRightH, BoardRightW, BoardRightX - 1, BoardRightY);
        setTextColor(208);
        gotoXY(BoardRightX + 9, BoardRightY + 3);
        cout << "                          W   ";
        gotoXY(BoardRightX + 9, BoardRightY + 4);
        cout << "Control your snake with A   D ";
        gotoXY(BoardRightX + 9, BoardRightY + 5);
        cout << "                          S   ";
        gotoXY(BoardRightX + 9, BoardRightY + 7);
        cout << "Avoid hitting walls";
        gotoXY(BoardRightX + 9, BoardRightY + 9);
        cout << "Avoid hitting yourself";
        gotoXY(BoardRightX + 9, BoardRightY + 11);
        cout << "Try to eat enough food";
        gotoXY(BoardRightX + 9 + 10, BoardRightY + 12);
        cout << " to pass each level";
        gotoXY(BoardRightX + 9, BoardRightY + 14);
        cout << "Press Space to pause the game";
        gotoXY(BoardRightX + 5, BoardRightY + 18);
        setTextColor(214);
        cout << "FROM GROUP 5 - 21CTT4 - HCMUS WITH LOVE";
        //Nội dung bảng thông tin

        setTextColor(208);
        gotoXY(BoardLeftX + 3, BoardLeftY - 4);
        cout << "▄▄▄▄▄ ▄▄▄  ▄▄▄   ▄▄  ▄▄     ▄▄▄▄▄▄ ";
        gotoXY(BoardLeftX + 3, BoardLeftY - 3);
        cout << "  █   █■■ ▄█■█▄  █▀▄▄▀█     █▄▄▄▄▄ ";
        gotoXY(BoardLeftX + 3, BoardLeftY - 2);
        cout << "  ▀   ▀▀▀ ▀   ▀  ▀ ▀▀ ▀     ▄▄▄▄▄█ ";
        gotoXY(BoardLeftX + 3, BoardLeftY - 1);

        setTextColor(209);
        drawBoard(BoardLeftH, BoardLeftW, BoardLeftX - 1, BoardLeftY);
        setTextColor(208);
        gotoXY(MemX, FirstMemY);  cout << "Vũ Tiến Đạt             21120432";
        gotoXY(MemX, SecMemY); cout << "Trương Thế Hiển         21120450";
        gotoXY(MemX, ThirdMemY);    cout << "Nguyễn Đức Hoài         21120454";
        gotoXY(MemX, FourthMemY);  cout << "Nguyễn Gia Huy          21120468";
        gotoXY(MemX, FifthMemy); cout << "Châu Hoàng Khoa         21120481";
        setTextColor(208);
        gotoXY(BoardRightX + 10, BoardRightY + 23);
        cout << "⃝ PRESS ENTER TO RETURN MENU ⃝" << endl;
        if (GetAsyncKeyState(VK_RETURN))
            return;
    }
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{

    //-----------------------------------------------------------------
    // Thiet lap buffer
    LPCWSTR title = L"SNAKE - GROUP 5 - 21CTT4 - HCMUS";
    SetConsoleTitleW(title);
    SetConsoleOutputCP(CP_UTF8);
    ShowConsoleCursor(false);
    
    /*FixConsoleWindow();
    sound.playBackground();
    loading();*/
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
    SMALL_RECT rect2 = { 0, 0, width * 2 - 1, height - 1 };
    SetConsoleWindowInfo(buffer, TRUE, &rect);
    SetConsoleWindowInfo(old, TRUE, &rect2);
    SetConsoleScreenBufferSize(buffer, { width, height });
    SetConsoleScreenBufferSize(old, { width * 2, height });
    // resizeConsole(width, height);
    DWORD BytesWritten = 0;
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 18; // Width of each character in the font
    cfi.dwFontSize.Y = 18; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_REGULAR;
    wcscpy(cfi.FaceName, L"Terminal"); // Choose your font
    SetCurrentConsoleFontEx(buffer, FALSE, &cfi);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(buffer, &info);
    SetConsoleCursorInfo(old, &info);

    _setmode(_fileno(stdin), _O_U8TEXT);
    /*_setmode(_fileno(stdout), _O_U8TEXT);*/
    

    //-----------------------------------------------------------------
    

    loadMics();
    loadMap();
    loadSaveFile();


    srand(chrono::system_clock::now().time_since_epoch().count());
    clear(screen1);
    clear(screen2);
    nextLevel();

    using clock = std::chrono::steady_clock;
    chrono::nanoseconds deltaTime(0ms), accumulator(0ms), accumulator1(0ms);
    auto t1 = clock::now();
    chrono::nanoseconds timestep(16ms);



    while (true)
    {
        deltaTime = clock::now() - t1;
        t1 = clock::now();
        accumulator += deltaTime;
        accumulator1 += deltaTime;
        input(buffer); // Nhập các lệnh di chuyển

        switch (state) {
        case inMenu:
            if (accumulator > 120ms * (1.0 / snake1.speed))
                accumulator -= chrono::duration_cast<chrono::nanoseconds>(120ms * (1.0 / snake1.speed));
            SetConsoleActiveScreenBuffer(old);
            if (accumulator1 > timestep)
            {
                frameN++;
                accumulator1 -= timestep;
                clear(screen2);
                drawMenu();
                countDown();
                WriteConsoleOutputCharacterW(old, screen2.characters, width * height * 2, { 0, 0 }, &BytesWritten);
                WriteConsoleOutputAttribute(old, screen2.color, width * height * 2, { 0, 0 }, &BytesWritten);
            }
            break;
        case inGame:
        case inPaused:
            SetConsoleActiveScreenBuffer(buffer);

            // Nếu nếu khoảng thời gian từ mốc thời gian trước đến hiện tại bé hơn một khoảng thời gian thì thực hiện việc di chuyển rắn
            if (accumulator > 120ms * (1.0 / snake1.speed))
            {
                accumulator -= chrono::duration_cast<chrono::nanoseconds>(120ms * (1.0 / snake1.speed));
                update();
            }

            if (accumulator1 > timestep)
            {
                frameN++;
                accumulator1 -= timestep;
                clear(screen1); // Xoa man hinh
                draw(screen1, map[level], { 0, 0 }, 0, 1, 1);
                drawFood(food);
                drawPortal();
                draw(snake1); // Vẽ rắn
                drawSideBar();
                countDown();
                //draw(screen1, object["portal"], { 10,10 }, 0, true, false);
                // wsprintf(&screen1.characters[index(31, 0)], "FRAME: %d", frameN);
                WriteConsoleOutputCharacterW(buffer, screen1.characters, width * height, { 0, 0 }, &BytesWritten);
                WriteConsoleOutputAttribute(buffer, screen1.color, width * height, { 0, 0 }, &BytesWritten);
            }
            break;
        case inLoad:
            if (accumulator > 120ms * (1.0 / snake1.speed))
                accumulator -= chrono::duration_cast<chrono::nanoseconds>(120ms * (1.0 / snake1.speed));
            SetConsoleActiveScreenBuffer(old);
            if (accumulator1 > timestep)
            {
                frameN++;
                accumulator1 -= timestep;
                clear(screen2);
                drawLoadMenu();
                countDown();
                WriteConsoleOutputCharacterW(old, screen2.characters, width * height * 2, { 0, 0 }, &BytesWritten);
                WriteConsoleOutputAttribute(old, screen2.color, width * height * 2, { 0, 0 }, &BytesWritten);
            }
            break;
        }
        
    }
    
    writeSaveFile();
    SetConsoleActiveScreenBuffer(old); // Trả lại buffer
    return 0;
}