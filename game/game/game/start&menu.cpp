#include "start&menu.h"
#include "startgame.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

void setConsoleTextColor(int color);

string playerName;

string playerregister()
{
    setConsoleFont24();
    cout << "\n\t\t   this has sound so dont mute (==3 \n\t\t   W to Move Up S to Move Down \n\t\t    Press Enter To continue: ";
    _getch();
    system("cls");
    cout << "Enter player name: ";
    cin >> playerName;

    return welcome();
}


string welcome()
{
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    CONSOLE_FONT_INFOEX fontInfo = { 0 };
    fontInfo.cbSize = sizeof(fontInfo);
    fontInfo.nFont = 0;
    fontInfo.dwFontSize.X = 0;
    fontInfo.dwFontSize.Y = 6;     fontInfo.FontFamily = FF_DONTCARE;
    fontInfo.FontWeight = FW_NORMAL;
    wcscpy_s(fontInfo.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
    setConsoleTextColor(10);
    PlaySound(TEXT("welcome.wav"), NULL, SND_FILENAME | SND_ASYNC);   
    return R"(




























                                                                                                                                 ▄█     █▄     ▄████████  ▄█        ▄████████  ▄██████▄    ▄▄▄▄███▄▄▄▄      ▄████████          ███      ▄██████▄  
                                                                                                                                ███     ███   ███    ███ ███       ███    ███ ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███      ▀█████████▄ ███    ███ 
                                                                                                                                ███     ███   ███    █▀  ███       ███    █▀  ███    ███ ███   ███   ███   ███    █▀          ▀███▀▀██ ███    ███ 
                                                                                                                                ███     ███  ▄███▄▄▄     ███       ███        ███    ███ ███   ███   ███  ▄███▄▄▄              ███   ▀ ███    ███ 
                                                                                                                                ███     ███ ▀▀███▀▀▀     ███       ███        ███    ███ ███   ███   ███ ▀▀███▀▀▀              ███     ███    ███ 
                                                                                                                                ███     ███   ███    █▄  ███       ███    █▄  ███    ███ ███   ███   ███   ███    █▄           ███     ███    ███ 
                                                                                                                                ███ ▄█▄ ███   ███    ███ ███▌    ▄ ███    ███ ███    ███ ███   ███   ███   ███    ███          ███     ███    ███ 
                                                                                                                                 ▀███▀███▀    ██████████ █████▄▄██ ████████▀   ▀██████▀   ▀█   ███   █▀    ██████████         ▄████▀    ▀██████▀  
                                                                                                                                                         ▀                                                                                        
                                                                                                                                     ████████▄   ███    █▄   ▄█   ▄███████▄       ████████▄   ███    █▄     ▄████████    ▄████████     ███        
                                                                                                                                     ███    ███  ███    ███ ███  ██▀     ▄██      ███    ███  ███    ███   ███    ███   ███    ███ ▀█████████▄    
                                                                                                                                     ███    ███  ███    ███ ███▌       ▄███▀      ███    ███  ███    ███   ███    █▀    ███    █▀     ▀███▀▀██    
                                                                                                                                     ███    ███  ███    ███ ███▌  ▀█▀▄███▀▄▄      ███    ███  ███    ███  ▄███▄▄▄       ███            ███   ▀    
                                                                                                                                     ███    ███  ███    ███ ███▌   ▄███▀   ▀      ███    ███  ███    ███ ▀▀███▀▀▀     ▀███████████     ███        
                                                                                                                                     ███    ███  ███    ███ ███  ▄███▀            ███    ███  ███    ███   ███    █▄           ███     ███        
                                                                                                                                     ███  ▀ ███  ███    ███ ███  ███▄     ▄█      ███  ▀ ███  ███    ███   ███    ███    ▄█    ███     ███        
                                                                                                                                      ▀██████▀▄█ ████████▀  █▀    ▀████████▀       ▀██████▀▄█ ████████▀    ██████████  ▄████████▀     ▄████▀                                                                               
  






                                                                                                                                                                               _              _                    _   _              
                                                                                                                                          _ __ _ _ ___ ______  __ _ _ _ _  _  | |_____ _  _  | |_ ___   __ ___ _ _| |_(_)_ _ _  _ ___ 
                                                                                                                                         | '_ \ '_/ -_|_-<_-< / _` | ' \ || | | / / -_) || | |  _/ _ \ / _/ _ \ ' \  _| | ' \ || / -_)
                                                                                                                                         | .__/_| \___/__/__/ \__,_|_||_\_, | |_\_\___|\_, |  \__\___/ \__\___/_||_\__|_|_||_\_,_\___|
                                                                                                                                         |_|                            |__/           |__/  

 


 )";
}




void displayMenu(int selectedOption) 
{

    system("cls");     setConsoleTextColor(10);

    if (selectedOption == 0)
    {
        PlaySound(TEXT("start.wav"), NULL, SND_FILENAME | SND_ASYNC);

    }
    else if (selectedOption == 1)
    {
        PlaySound(TEXT("halloffame.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    else if (selectedOption == 2)
    {
        PlaySound(TEXT("credits.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    else if (selectedOption == 3)
    {
        PlaySound(TEXT("achievements.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    else if (selectedOption == 4)
    {
        PlaySound(TEXT("exit.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t███╗   ███╗ █████╗ ██╗███╗   ██╗    ███╗   ███╗███████╗███╗   ██╗██╗   ██╗ " << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t████╗ ████║██╔══██╗██║████╗  ██║    ████╗ ████║██╔════╝████╗  ██║██║   ██║ " << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t██╔████╔██║███████║██║██╔██╗ ██║    ██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║ " << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t██║╚██╔╝██║██╔══██║██║██║╚██╗██║    ██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║ " << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t██║ ╚═╝ ██║██║  ██║██║██║ ╚████║    ██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝ " << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t╚═╝     ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝    ╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ " << endl;
    cout << "\n\n\n\n\n\n" << endl;



        

    cout << (selectedOption == 0 ? "\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t  █████████  ███████████   █████████   ███████████   ███████████      █████████    █████████   ██████   ██████ ██████████" << endl;
    cout << (selectedOption == 0 ? "\t\t\t\t\t\t\t\t\t\t\t ███   ▀███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ███░░░░░███░█░░░███░░░█  ███░░░░░███ ░░███░░░░░███ ░█░░░███░░░█     ███░░░░░███  ███░░░░░███ ░░██████ ██████ ░░███░░░░░█" << endl;
    cout << (selectedOption == 0 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░███    ░░░ ░   ░███  ░  ░███    ░███  ░███    ░███ ░   ░███  ░     ███     ░░░  ░███    ░███  ░███░█████░███  ░███  █ ░ " << endl;
    cout << (selectedOption == 0 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░░█████████     ░███     ░███████████  ░██████████      ░███       ░███          ░███████████  ░███░░███ ░███  ░██████   " << endl;
    cout << (selectedOption == 0 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░░░░░░░░███    ░███     ░███░░░░░███  ░███░░░░░███     ░███       ░███    █████ ░███░░░░░███  ░███ ░░░  ░███  ░███░░█   " << endl;
    cout << (selectedOption == 0 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ███    ░███    ░███     ░███    ░███  ░███    ░███     ░███       ░░███  ░░███  ░███    ░███  ░███      ░███  ░███ ░   █" << endl;
    cout << (selectedOption == 0 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░░█████████     █████    █████   █████ █████   █████    █████       ░░█████████  █████   █████ █████     █████ ██████████" << endl;
    cout << (selectedOption == 0 ? "\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░░░░░░░░░     ░░░░░    ░░░░░   ░░░░░ ░░░░░   ░░░░░    ░░░░░         ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░     ░░░░░ ░░░░░░░░░░ " << endl << "\n\n\n";


    cout << (selectedOption == 1 ? "\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t █████   █████   █████████   █████       █████             ███████    ███████████    ███████████   █████████   ██████   ██████ ██████████" << endl;
    cout << (selectedOption == 1 ? "\t\t\t\t\t\t\t\t\t\t\t ███   ▀███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░░███   ░░███   ███░░░░░███ ░░███       ░░███            ███░░░░░███ ░░███░░░░░░█   ░░███░░░░░░█  ███░░░░░███ ░░██████ ██████ ░░███░░░░░█" << endl;
    cout << (selectedOption == 1 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███    ░███  ░███    ░███  ░███        ░███           ███     ░░███ ░███   █ ░     ░███   █ ░  ░███    ░███  ░███░█████░███  ░███  █ ░ " << endl;
    cout << (selectedOption == 1 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███████████  ░███████████  ░███        ░███          ░███      ░███ ░███████       ░███████    ░███████████  ░███░░███ ░███  ░██████   " << endl;
    cout << (selectedOption == 1 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███░░░░░███  ░███░░░░░███  ░███        ░███          ░███      ░███ ░███░░░█       ░███░░░█    ░███░░░░░███  ░███ ░░░  ░███  ░███░░█   " << endl;
    cout << (selectedOption == 1 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███    ░███  ░███    ░███  ░███      █ ░███      █   ░░███     ███  ░███  ░        ░███  ░     ░███    ░███  ░███      ░███  ░███ ░   █" << endl;
    cout << (selectedOption == 1 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t █████   █████ █████   █████ ███████████ ███████████    ░░░███████░   █████          █████       █████   █████ █████     █████ ██████████" << endl;
    cout << (selectedOption == 1 ? "\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░░░░░   ░░░░░ ░░░░░   ░░░░░ ░░░░░░░░░░░ ░░░░░░░░░░░       ░░░░░░░    ░░░░░          ░░░░░       ░░░░░   ░░░░░ ░░░░░     ░░░░░ ░░░░░░░░░░ " << endl << "\n\n\n";


    cout << (selectedOption == 2 ? "\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t   █████████  ███████████   ██████████ ██████████   █████ ███████████  █████████ " << endl;
    cout << (selectedOption == 2 ? "\t\t\t\t\t\t\t\t\t\t\t ███   ▀███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t  ███░░░░░███░░███░░░░░███ ░░███░░░░░█░░███░░░░███ ░░███ ░█░░░███░░░█ ███░░░░░███" << endl;
    cout << (selectedOption == 2 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ███     ░░░  ░███    ░███  ░███  █ ░  ░███   ░░███ ░███ ░   ░███  ░ ░███    ░░░ " << endl;
    cout << (selectedOption == 2 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░███          ░██████████   ░██████    ░███    ░███ ░███     ░███    ░░█████████ " << endl;
    cout << (selectedOption == 2 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░███          ░███░░░░░███  ░███░░█    ░███    ░███ ░███     ░███     ░░░░░░░░███" << endl;
    cout << (selectedOption == 2 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░░███     ███ ░███    ░███  ░███ ░   █ ░███    ███  ░███     ░███     ███    ░███" << endl;
    cout << (selectedOption == 2 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░░█████████  █████   █████ ██████████ ██████████   █████    █████   ░░█████████ " << endl;
    cout << (selectedOption == 2 ? "\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t  ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░░░░░░ ░░░░░░░░░░   ░░░░░    ░░░░░     ░░░░░░░░░  " << endl << "\n\n\n";


    cout << (selectedOption == 3 ? "\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t   █████████     █████████  █████   █████ █████ ██████████ █████   █████ ██████████ ██████   ██████ ██████████ ██████   █████ ███████████  █████████ " << endl;
    cout << (selectedOption == 3 ? "\t\t\t\t\t\t\t\t\t\t\t ███   ▀███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t  ███░░░░░███   ███░░░░░███░░███   ░░███ ░░███ ░░███░░░░░█░░███   ░░███ ░░███░░░░░█░░██████ ██████ ░░███░░░░░█░░██████ ░░███ ░█░░░███░░░█ ███░░░░░███" << endl;
    cout << (selectedOption == 3 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███    ░███  ███     ░░░  ░███    ░███  ░███  ░███  █ ░  ░███    ░███  ░███  █ ░  ░███░█████░███  ░███  █ ░  ░███░███ ░███ ░   ░███  ░ ░███    ░░░ " << endl;
    cout << (selectedOption == 3 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███████████ ░███          ░███████████  ░███  ░██████    ░███    ░███  ░██████    ░███░░███ ░███  ░██████    ░███░░███░███     ░███    ░░█████████ " << endl;
    cout << (selectedOption == 3 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███░░░░░███ ░███          ░███░░░░░███  ░███  ░███░░█    ░░███   ███   ░███░░█    ░███ ░░░  ░███  ░███░░█    ░███ ░░██████     ░███     ░░░░░░░░███" << endl;
    cout << (selectedOption == 3 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███    ░███ ░░███     ███ ░███    ░███  ░███  ░███ ░   █  ░░░█████░    ░███ ░   █ ░███      ░███  ░███ ░   █ ░███  ░░█████     ░███     ███    ░███" << endl;
    cout << (selectedOption == 3 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t █████   █████ ░░█████████  █████   █████ █████ ██████████    ░░███      ██████████ █████     █████ ██████████ █████  ░░█████    █████   ░░█████████ " << endl;
    cout << (selectedOption == 3 ? "\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░░░░░   ░░░░░   ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░ ░░░░░░░░░░      ░░░      ░░░░░░░░░░ ░░░░░     ░░░░░ ░░░░░░░░░░ ░░░░░    ░░░░░    ░░░░░     ░░░░░░░░░ " << endl << "\n\n\n";;


    cout << (selectedOption == 4 ? "\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ██████████ █████ █████ █████ ███████████" << endl;
    cout << (selectedOption == 4 ? "\t\t\t\t\t\t\t\t\t\t\t ███   ▀███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░░███░░░░░█░░███ ░░███ ░░███ ░█░░░███░░░█" << endl;
    cout << (selectedOption == 4 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███  █ ░  ░░███ ███   ░███ ░   ░███  ░ " << endl;
    cout << (selectedOption == 4 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░██████     ░░█████    ░███     ░███    " << endl;
    cout << (selectedOption == 4 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███░░█      ███░███   ░███     ░███    " << endl;
    cout << (selectedOption == 4 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ░███ ░   █  ███ ░░███  ░███     ░███    " << endl;
    cout << (selectedOption == 4 ? "\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t ██████████ █████ █████ █████    █████   " << endl;
    cout << (selectedOption == 4 ? "\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t░░░░░░░░░░ ░░░░░ ░░░░░ ░░░░░    ░░░░░   " << endl << "\n\n\n";;



}




                                                                                                                


