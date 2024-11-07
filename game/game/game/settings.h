#pragma once

#include <string>
using namespace std;

void setDynamicConsoleWindowSize();
void setDynamicConsoleFontSize();
void setCursorPosition(int x, int y);
void setConsoleTextColor(int color);
wstring to_wstring(const string& str);
void setConsoleFont24();
void setConsoleFont6();
void setFullScreen();
string tabs();