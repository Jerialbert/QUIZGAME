#include "start&menu.h"
#include "settings.h"
#include "startgame.h"  
#include "achievements.h"
#include "halloffame.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>
#include <queue> 


using namespace std;



vector<bool> powerUpUsed(7, false);



struct Feedback {
    vector<string> correctWords;
    vector<string> correctAudioFiles;
    vector<string> incorrectWords;
    vector<string> incorrectAudioFiles;
};

Feedback feedbacks[5] = {
    
    {
        {"Sana All!", "daddy chill!", "Keep going!", "HE HE HE HA!", "AMAZING!", "Fantastic!", "You're getting it!"},
        {"sanaall.wav", "daddychill.wav", "rizz.wav", "hehe.wav", "amazing.wav", "yehey.wav", "romantic.wav"},
        {"Almost there!", "Try a little harder!", "BABABOY!", "Not quite, keep trying!", "Almost got it!", "Give it another shot!", "BAKA!(VV)"},
        {"fart.wav", "vine.wav", "baboy.way", "angry.wav", "womp.wav", "damnson.wav", "baka.wav"}
    },
    
    {
        {"Nice job!", "Great effort!", "You're improving!", "Keep it up!", "Well done!", "Solid performance!", "Good work!"},
        {"sanaall.wav", "daddychill.wav", "rizz.wav", "hehe.wav", "amazing.wav", "yehey.wav", "romantic.wav"},
        {"Not quite, give it another shot!", "Almost got it!", "Don't worry, try again!", "You're close!", "Keep practicing!", "Almost there!", "You'll nail it soon!"},
        {"fart.wav", "vine.wav", "baboy.way", "angry.wav", "womp.wav", "damnson.wav", "baka.wav"}
    },
    
    {
        {"Awesome work!", "Superb!", "Fantastic effort!", "Excellent!", "Impressive!", "Remarkable!", "Top-notch!"},
        {"sanaall.wav", "daddychill.wav", "rizz.wav", "hehe.wav", "amazing.wav", "yehey.wav", "romantic.wav"},
        {"So close!", "Almost had it!", "Keep pushing!", "Nearly there!", "Don't stop now!", "One more try!", "You got this!"},
        {"fart.wav", "vine.wav", "baboy.way", "angry.wav", "womp.wav", "damnson.wav", "baka.wav"}
    },
    
    {
        {"Incredible!", "You're a pro!", "Exceptional!", "Outstanding!", "Phenomenal!", "Masterful!", "Unstoppable!"},
        {"sanaall.wav", "daddychill.wav", "rizz.wav", "hehe.wav", "amazing.wav", "yehey.wav", "romantic.wav"},
        {"Not far off!", "You're nearly there!", "Don't stop now!", "Almost an expert!", "So close to perfection!", "Keep going!", "You'll master it soon!"},
        {"fart.wav", "vine.wav", "baboy.way", "angry.wav", "womp.wav", "damnson.wav", "baka.wav"}
    },
    
    {
        {"Unbelievable!", "Legendary!", "Perfect!", "Flawless!", "Unmatched!", "Incredible mastery!", "You're a legend!"},
        {"sanaall.wav", "daddychill.wav", "rizz.wav", "hehe.wav", "amazing.wav", "yehey.wav", "romantic.wav"},
        {"Close but not enough!", "Almost a legend!", "Try one more time!", "Not quite legendary yet!", "You're almost there!", "One more step to greatness!", "Keep striving!"},
        {"fart.wav", "vine.wav", "baboy.way", "angry.wav", "womp.wav", "damnson.wav", "baka.wav"}
    }
};


void playFeedbackSound(int difficulty, bool isCorrect, int index) {
    string audioFile = isCorrect ? feedbacks[difficulty].correctAudioFiles[index]
        : feedbacks[difficulty].incorrectAudioFiles[index];
    wstring wideAudioFile(audioFile.begin(), audioFile.end());
    PlaySound(wideAudioFile.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}

string getFeedbackText(int difficulty, bool isCorrect, int index) {
    return isCorrect ? feedbacks[difficulty].correctWords[index]
        : feedbacks[difficulty].incorrectWords[index];
}

void showPopUpText(const string& message, bool correct) {
    if (correct) {
        setConsoleTextColor(10);  
        cout << "\n" << message << endl;
    }
    else {
        setConsoleTextColor(12); 
        cout << "\n" << message << endl;
    }
    setConsoleTextColor(7);  
    this_thread::sleep_for(chrono::seconds(2));  
}

void pop() {
    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.pop();
    myQueue.pop();
}

class Question {
public:
    std::string text; 
    std::vector<std::string> options; 
    int correctAnswerIndex; 

   
    Question(string qText,vector<std::string> opts, int correctIndex)
        : text(qText), options(opts), correctAnswerIndex(correctIndex) {}
};


const string POWER_UPS[3] = {
    "Power-Up 1: DIO's ZA WARUDO\n   [ Pauses the time for 5 seconds ]",
    "Power-Up 2: Mangekyō Sharingan\n   [ Tricks the program that you have already answered correctly ]",
    "Power-Up 3: Tori Tori no Mi, Model: Phoenix\n   [ Revive's the streak if answered wrong ]"
};


int selectPowerUp() {
    setConsoleFont24();
    int selectedPowerUp = 0;
    bool choosing = true;
    system("cls");

    while (choosing) {
        system("cls");
        cout << "Select a Power-Up:\n\n";
        cout << POWER_UPS[selectedPowerUp] << "\n\n";
        cout << "Press 'A' to go left, 'D' to go right, or 'Enter' to select.\n";

        char key = _getch();
        if (key == 'a' || key == 'A') {
            selectedPowerUp = (selectedPowerUp - 1 + 3) % 3;  
            PlaySound(TEXT("up.wav"), NULL, SND_FILENAME | SND_ASYNC);

        }
        else if (key == 'd' || key == 'D') {
            selectedPowerUp = (selectedPowerUp + 1) % 3;  
            PlaySound(TEXT("down.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (key == '\r') {  
            choosing = false;
        }
    }

    return selectedPowerUp;
}

void showRules()
{
    system("cls"); 
    setConsoleFont24();
    cout << "\n========= Press any key to continue ========= \n" << endl;
    cin.get();
    cout << "Game Rules:\n" << endl;
    cout << "1. You will be presented with a series of quiz questions." << endl;
    cout << "2. Each question will have multiple-choice answers." << endl;
    cout << "3. Select the correct answer to score points." << endl;
    cout << "4. The game will end after a fixed number of questions." << endl;
    cout << "5. The difficulty level affects the number of questions and their difficulty." << endl;
    cout << "6. Have fun and try to get the highest score!" << endl;

    cout << "\nPress any key to continue to difficulty selection..." << endl;
    cin.get(); 
    showDifficultyMenu(); 
}

void showDifficultyMenu() 
{

    bool isSelecting = true;
    int selectedDifficulty = 2;
    while (isSelecting) {
        system("cls"); 
        setConsoleFont6();

        if (selectedDifficulty == 0)
        {
            PlaySound(TEXT("tutorial.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setConsoleTextColor(9);
            
        }
        else if (selectedDifficulty == 1)
        {
            PlaySound(TEXT("easy.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setConsoleTextColor(12);
        }
        else if (selectedDifficulty == 2)
        {
            PlaySound(TEXT("medium.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setConsoleTextColor(8);
        }
        else if (selectedDifficulty == 3)
        {
            PlaySound(TEXT("hard.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setConsoleTextColor(6);
        }
        else if (selectedDifficulty == 4)
        {
            PlaySound(TEXT("hell.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setConsoleTextColor(4);
        }
        cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t███████╗███████╗██╗     ███████╗ ██████╗████████╗    ██████╗ ██╗███████╗███████╗██╗ ██████╗██╗   ██╗██╗  ████████╗██╗   ██╗ " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t██╔════╝██╔════╝██║     ██╔════╝██╔════╝╚══██╔══╝    ██╔══██╗██║██╔════╝██╔════╝██║██╔════╝██║   ██║██║  ╚══██╔══╝╚██╗ ██╔╝ " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t███████╗█████╗  ██║     █████╗  ██║        ██║       ██║  ██║██║█████╗  █████╗  ██║██║     ██║   ██║██║     ██║    ╚████╔╝  " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t╚════██║██╔══╝  ██║     ██╔══╝  ██║        ██║       ██║  ██║██║██╔══╝  ██╔══╝  ██║██║     ██║   ██║██║     ██║     ╚██╔╝   " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t███████║███████╗███████╗███████╗╚██████╗   ██║       ██████╔╝██║██║     ██║     ██║╚██████╗╚██████╔╝███████╗██║      ██║    " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t╚══════╝╚══════╝╚══════╝╚══════╝ ╚═════╝   ╚═╝       ╚═════╝ ╚═╝╚═╝     ╚═╝     ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝      ╚═╝    " << endl;
        cout << "\n\n\n\n\n\n" << endl;

        
        setConsoleTextColor(9);
        cout << (selectedDifficulty == 0 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ") << "" << endl; 
        cout << (selectedDifficulty == 0 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███   ▀███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ") << "" << endl; 
        cout << (selectedDifficulty == 0 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ") << "           ░▀█▀░█░█░▀█▀░█▀█░█▀▄░▀█▀░█▀█░█░░" << endl;
        cout << (selectedDifficulty == 0 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ") << "           ░░█░░█░█░░█░░█░█░█▀▄░░█░░█▀█░█░░" << endl;
        cout << (selectedDifficulty == 0 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ") << "           ░░▀░░▀▀▀░░▀░░▀▀▀░▀░▀░▀▀▀░▀░▀░▀▀▀" << endl;
        cout << (selectedDifficulty == 0 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ") << "" << endl; 
        cout << (selectedDifficulty == 0 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ") << "" << endl; 
        cout << (selectedDifficulty == 0 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ") << "" << endl << "\n\n\n";

        setConsoleTextColor(12);
        cout << (selectedDifficulty == 1 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t\t\t" << endl;
        cout << (selectedDifficulty == 1 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███   ▀███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ════════      ╔══╗        ╔══════╗  ╚╗       ╔╝ " << endl;
        cout << (selectedDifficulty == 1 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ║            ╔╝  ╚╗      ╔╝      ╚╗  ╚╗     ╔╝  " << endl;
        cout << (selectedDifficulty == 1 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ║           ╔╝    ╚╗     ║            ╚╗   ╔╝   " << endl;
        cout << (selectedDifficulty == 1 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ║═══════   ╔╝══════╝╗    ╚══════╗      ╚╗ ╔╝    " << endl;
        cout << (selectedDifficulty == 1 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ║          ║        ║           ║       ╚╔╝     " << endl;
        cout << (selectedDifficulty == 1 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ║          ║        ║    ║      ╚╗       ║      " << endl;
        cout << (selectedDifficulty == 1 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ════════   ╚════════╝     ╚══════╝       ║      " << endl << "\n\n\n";

        setConsoleTextColor(8);
        cout << (selectedDifficulty == 2 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ██████   ██████ ██████████ ██████████   █████ █████  █████ ██████   ██████ " << endl;
        cout << (selectedDifficulty == 2 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ██████▀███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ░░██████ ██████ ░░███░░░░░█░░███░░░░███ ░░███ ░░███  ░░███ ░░██████ ██████  " << endl;
        cout << (selectedDifficulty == 2 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ░███░█████░███  ░███  █ ░  ░███   ░░███ ░███  ░███   ░███  ░███░█████░███  " << endl;
        cout << (selectedDifficulty == 2 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ░███░░███ ░███  ░██████    ░███    ░███ ░███  ░███   ░███  ░███░░███ ░███  " << endl;
        cout << (selectedDifficulty == 2 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ░███ ░░░  ░███  ░███░░█    ░███    ░███ ░███  ░███   ░███  ░███ ░░░  ░███  " << endl;
        cout << (selectedDifficulty == 2 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ░███      ░███  ░███ ░   █ ░███    ███  ░███  ░███   ░███  ░███      ░███  " << endl;
        cout << (selectedDifficulty == 2 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         █████     █████ ██████████ ██████████   █████ ░░████████   █████     █████ " << endl;
        cout << (selectedDifficulty == 2 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ░░░░░     ░░░░░ ░░░░░░░░░░ ░░░░░░░░░░   ░░░░░   ░░░░░░░░   ░░░░░     ░░░░░  " << endl;
        cout << (selectedDifficulty == 2 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t" << endl << "\n\n\n";

        setConsoleTextColor(6);
        cout << (selectedDifficulty == 3 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t            ▄█    █▄       ▄████████    ▄████████ ████████▄  " << endl;
        cout << (selectedDifficulty == 3 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ██████▀███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t          ███    ███     ███    ███   ███    ███ ███   ▀███ " << endl;
        cout << (selectedDifficulty == 3 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t          ███    ███     ███    ███   ███    ███ ███    ███ " << endl;
        cout << (selectedDifficulty == 3 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ▄███▄▄▄▄███▄▄   ███    ███  ▄███▄▄▄▄██▀ ███    ███ " << endl;
        cout << (selectedDifficulty == 3 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ▀▀███▀▀▀▀███▀  ▀███████████ ▀▀███▀▀▀▀▀   ███    ███ " << endl;
        cout << (selectedDifficulty == 3 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t          ███    ███     ███    ███ ▀███████████ ███    ███ " << endl;
        cout << (selectedDifficulty == 3 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t          ███    ███     ███    ███   ███    ███ ███   ▄███ " << endl;
        cout << (selectedDifficulty == 3 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t          ███    █▀      ███    █▀    ███    ███ ████████▀  " << endl;
        cout << (selectedDifficulty == 3 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t                                      ███    ███            " << endl << "\n\n\n";;

        setConsoleTextColor(4);
        cout << (selectedDifficulty == 4 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ██░ ██ ▓█████  ██▓     ██▓     " << endl;
        cout << (selectedDifficulty == 4 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ██████▀███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    " << endl;
        cout << (selectedDifficulty == 4 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ▒██▀▀██░▒███   ▒██░    ▒██░    " << endl;
        cout << (selectedDifficulty == 4 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    " << endl;
        cout << (selectedDifficulty == 4 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t        ░▓█▒░██▓░▒████▒░██████▒░██████▒" << endl;
        cout << (selectedDifficulty == 4 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░" << endl;
        cout << (selectedDifficulty == 4 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░" << endl;
        cout << (selectedDifficulty == 4 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ░  ░░ ░   ░     ░ ░     ░ ░   " << endl;
        cout << (selectedDifficulty == 4 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         ░  ░  ░   ░  ░    ░  ░    ░  ░" << endl << "\n\n\n\n\n\n\n\n\n\n";;

        setConsoleTextColor(7);
        cout << (selectedDifficulty == 5 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▄  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t   ███████████    █████████     █████████  █████   ████ " << endl;
        cout << (selectedDifficulty == 5 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ██████▀███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t  ░░███░░░░░███  ███░░░░░███   ███░░░░░███░░███   ███░ " << endl;
        cout << (selectedDifficulty == 5 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t   ░███    ░███ ░███    ░███  ███     ░░░  ░███  ███   " << endl;
        cout << (selectedDifficulty == 5 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t   ░██████████  ░███████████ ░███          ░███████    " << endl;
        cout << (selectedDifficulty == 5 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t   ░███░░░░░███ ░███░░░░░███ ░███          ░███░░███   " << endl;
        cout << (selectedDifficulty == 5 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t   ░███    ░███ ░███    ░███ ░░███     ███ ░███ ░░███  " << endl;
        cout << (selectedDifficulty == 5 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t   ███████████  █████   █████ ░░█████████  █████ ░░████" << endl;
        cout << (selectedDifficulty == 5 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ███    ███ " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t  ░░░░░░░░░░░  ░░░░░   ░░░░░   ░░░░░░░░░  ░░░░░   ░░░░ " << endl;
        cout << (selectedDifficulty == 5 ? "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ████████▀  " : "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ") << "\t         " << endl << "\n\n\n";;



        
    char key = _getch();

    switch (key) {
    case 'w': case 'W': 
        selectedDifficulty = (selectedDifficulty - 1 + 6) % 6;
        break;
    case 's': case 'S': 
        selectedDifficulty = (selectedDifficulty + 1) % 6;
        break;
    case '\r': 
        if (selectedDifficulty < 5) {
            handleDifficultySelection(playerName, selectedDifficulty);           
        }
        else if (selectedDifficulty == 5) {
            isSelecting = false;
        }
        break;
    }
        }
    }

void displayQuestion(Question& question, int selectedOption, int score, int streak, int timeLeft, bool isPaused) {
    setConsoleFont24();
    cout << "Score: " << score << " | Streak: " << streak << endl;
    cout << "Question: " << question.text << endl;

  
    for (int i = 0; i < question.options.size(); i++) {
        if (i == selectedOption) {
            cout << "> " << question.options[i] << " <\n";  
        }
        else {
            cout << "  " << question.options[i] << "\n";
        }
    }

    
    if (isPaused) {
        cout << "\n** THE WORLD  Time is paused! **\n";
    }
}

int Quiz(vector<Question>& questions, int selectedPowerUp, int difficulty) {
    int score = 0;
    int streak = 0;
    int lastStreak = 0; 
    int timeLimit = 10;
    vector<bool> askedQuestions(questions.size(), false);
    bool isPaused = false;
    int pauseDuration = 5;
    auto pauseStartTime = chrono::steady_clock::now();


    for (int i = 0; i < 7; i++) {
        if (selectedPowerUp == i) {
            powerUpUsed[i] = true;
        }
    }

    int questionsAsked = 0;
    int questionIndex = 0; 

    while (questionsAsked < 7) {
        
        int selectedQuestionIndex;
        if (difficulty == 0) {
            selectedQuestionIndex = questionIndex++;
        }
        else {
            
            selectedQuestionIndex = rand() % questions.size();
            if (askedQuestions[selectedQuestionIndex]) continue;
        }
        askedQuestions[selectedQuestionIndex] = true;

        Question& question = questions[selectedQuestionIndex];
        int selectedOption = 0;
        bool answered = false;
        int timeLeft = timeLimit;

        auto startTime = chrono::steady_clock::now();

        
        if (difficulty == 0 && selectedQuestionIndex == 0) {
            PlaySound(TEXT("0.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (difficulty == 0 && selectedQuestionIndex == 1) {
            PlaySound(TEXT("1.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (difficulty == 0 && selectedQuestionIndex == 2) {
            PlaySound(TEXT("2.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (difficulty == 0 && selectedQuestionIndex == 3) {
            PlaySound(TEXT("3.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (difficulty == 0 && selectedQuestionIndex == 4) {
            PlaySound(TEXT("4.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (difficulty == 0 && selectedQuestionIndex == 5) {
            PlaySound(TEXT("5.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        if (difficulty == 0 && selectedQuestionIndex == 6) {
            PlaySound(TEXT("6.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }

        while (!answered) {
            auto currentTime = chrono::steady_clock::now();
            auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime).count();

            if (!isPaused) {
                timeLeft = timeLimit - elapsedTime;
                if (timeLeft <= 0) {
                    cout << "\nTime's up!\n";
                    _getch();
                    answered = true;
                    lastStreak = streak;
                    streak = 0;
                    break;
                }
            }

            
            system("cls");
            displayQuestion(question, selectedOption, score, streak, timeLeft, isPaused);
            cout << "\nTime Remaining: " << timeLeft << " seconds left\n";

            if (_kbhit()) {
                char key = _getch();
                switch (key) {
                case 'w': case 'W':
                    selectedOption = (selectedOption - 1 + 4) % 4;
                    if(difficulty > 0)
                    {PlaySound(TEXT("up.wav"), NULL, SND_FILENAME | SND_ASYNC);}
                    
                    break;
                case 's': case 'S':
                    selectedOption = (selectedOption + 1) % 4;
                    if (difficulty > 0)
                    {PlaySound(TEXT("down.wav"), NULL, SND_FILENAME | SND_ASYNC);}                    
                    break;
                case '1':
                    if (selectedPowerUp == 0 && powerUpUsed[0]) {
                        PlaySound(TEXT("world.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        isPaused = true;
                        pauseStartTime = chrono::steady_clock::now();
                        powerUpUsed[0] = false;
                    }
                    break;
                case '2':
                    if (selectedPowerUp == 1 && powerUpUsed[1]) {
                        selectedOption = question.correctAnswerIndex;
                        PlaySound(TEXT("sharingan.wav"), NULL, SND_FILENAME | SND_SYNC);
                        cout << "\nItachi's left Mangekyō Sharingan activated! You Got The Right Answer.\n";
                        score += (5 + streak * 5) * (difficulty + 1); 
                        lastStreak = ++streak;
                        int correctIndex = rand() % feedbacks[difficulty].correctWords.size();
                        cout << feedbacks[difficulty].correctWords[correctIndex] << endl;
                        PlaySound(wstring(feedbacks[difficulty].correctAudioFiles[correctIndex].begin(),
                            feedbacks[difficulty].correctAudioFiles[correctIndex].end()).c_str(), NULL, SND_FILENAME | SND_ASYNC);
                        _getch();
                        powerUpUsed[1] = false;
                        answered = true;
                    }
                    break;
                case '3':
                    if (selectedPowerUp == 2 && powerUpUsed[2]) {
                        streak = lastStreak;
                        PlaySound(TEXT("haki.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        cout << "\nStreak restored to " << streak << ".\n";
                        _getch();
                        powerUpUsed[2] = false;
                        startTime = chrono::steady_clock::now(); 
                    }
                    break;
                case '\r':
                    if (selectedOption == question.correctAnswerIndex) {
                        PlaySound(TEXT("Powerup3.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        cout << "\nCorrect!\n";
                        score += (5 + streak * 5) * (difficulty + 1); 
                        lastStreak = ++streak;
                        int correctIndex = rand() % feedbacks[difficulty].correctWords.size();
                        cout << feedbacks[difficulty].correctWords[correctIndex] << endl;
                        PlaySound(wstring(feedbacks[difficulty].correctAudioFiles[correctIndex].begin(),
                            feedbacks[difficulty].correctAudioFiles[correctIndex].end()).c_str(), NULL, SND_FILENAME | SND_ASYNC);
                        pop();
                    }
                    else {
                        cout << "\nIncorrect.\n";
                        lastStreak = streak;
                        PlaySound(TEXT("Hit_Hurt27.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        streak = 0;
                        int incorrectIndex = rand() % feedbacks[difficulty].incorrectWords.size();
                        cout << feedbacks[difficulty].incorrectWords[incorrectIndex] << endl;
                        PlaySound(wstring(feedbacks[difficulty].incorrectAudioFiles[incorrectIndex].begin(),
                            feedbacks[difficulty].incorrectAudioFiles[incorrectIndex].end()).c_str(), NULL, SND_FILENAME | SND_ASYNC);
                        pop();
                    }
                    cin.get();
                    answered = true;
                    break;
                }
            }

            if (isPaused) {
                auto pauseElapsed = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - pauseStartTime).count();
                if (pauseElapsed >= pauseDuration) {
                    isPaused = false;
                    startTime = chrono::steady_clock::now() - chrono::seconds(timeLimit - timeLeft);
                }
            }
            this_thread::sleep_for(chrono::milliseconds(50));
        }
        questionsAsked++;
    }

    return score;
}


vector<Question> getQuestions(int difficulty) {
    vector<Question> questions;

    if (difficulty == 0)
    {
        setConsoleTextColor(9);
        questions.push_back({ "\n\n\tWelcome to the Game Tutorial! First, let's learn how to navigate:\n\n\t- Press 'W' to move up\n\t- Press 'S' to move down\n\t- Press ENTER to select your answer\n\n\tPick Answer 'A' to continue\n\n\n\n\n\n\n\n\n\n", {"A", "B", "C", "D"}, 0 });
        questions.push_back({ "\n\n\tLet's talk about Power-Ups:\n\n\t- Each power-up has a unique effect.\n\t- To activate, use:\n\t  '1' for ZA WARUDO (Pauses the timer for a short duration)\n\t  '2' for MANGEKYO SHARINGAN (Reveals the answer)\n\t  '3' for Tori Tori no Mi (Restores your streak)\n\n\tPick Answer 'A' if you understand.\n\n\n\n\n\n\n\n\n\n", {"A", "B", "C", "D"}, 0 });
        questions.push_back({ "\n\n\tEach Power-Up can only be used once, so choose wisely!\n\n\t- Using a Power-Up at the right moment can boost your score.\n\t- Remember: they won't be replenished until the game restarts.\n\n\tPick Answer 'A' if you understand.\n\n\n\n\n\n\n\n\n\n", {"A", "B", "C", "D"}, 0 });
        questions.push_back({ "\n\n\tGame Difficulty:\n\n\t- The game has multiple levels of difficulty: Easy, Medium, Hard, and Hell.\n\t- The harder the difficulty, the more points you can earn per question!\n\n\tPick Answer 'A' if you understand.\n\n\n\n\n\n\n\n\n\n", {"A", "B", "C", "D"}, 0 });
        questions.push_back({ "\n\n\tScoring & Streaks:\n\n\t- Answering correctly earns you points.\n\t- Consecutive correct answers increase your streak, giving you bonus points.\n\t- If you get a question wrong, your streak resets.\n\n\tPick Answer 'A' if you understand.\n\n\n\n\n\n\n\n\n\n", {"A","B", "C", "D"}, 0 });
        questions.push_back({ "\n\n\tHall of Fame:\n\n\t- Your final score will be recorded in the Hall of Fame after each game.\n\t- Aim for high scores to achieve 'Done' status on harder difficulties!\n\n\tPick Answer 'A' if you understand.\n\n\n\n\n\n\n\n\n\n", {"A", "B", "C", "D"}, 0 });
        questions.push_back({ "\n\n\tRemember your timer!\n\n\t- Once you ran out of time where the last pointer is pointed will be your answer \n\t'but cant be recorded'.\n\t- Good luck and have fun!\n\n\tPick Answer 'A' to start the game!\n\n\n\n\n\n\n\n\n\n", {"A", "B", "C", "D"}, 0 });
    }


    else if (difficulty == 1)
    {
        setConsoleTextColor(12);
        questions.push_back({ "\n\n\tWhat is the primary advantage of using a linked list over an array?\n\n\n\n\n\n\n\n\n\n\n", {"Faster access time", "Dynamic size allocation", "Better memory utilization", "Easier sorting"}, 1 });
        questions.push_back({ "\n\n\tIn a singly linked list, which pointer is used to traverse the list?\n\n\n\n\n\n\n\n\n\n", {"Previous pointer", "Next pointer", "Head pointer", "Tail pointer"}, 2 });
        questions.push_back({ "\n\n\tWhat is the primary operation that defines a stack??\n\n\n\n\n\n\n\n\n\n", {"FIFO (First In, First Out)", "LIFO (Last In, First Out)", "Random access", "Sorted order"}, 1 });
        questions.push_back({ "\n\n\tWhich of the following operations is NOT typically associated with a stack?\n\n\n\n\n\n\n\n\n\n", {"Push", "Pop", "Enqueue", "Peek"}, 2 });
        questions.push_back({ "\n\n\tWhat is the main characteristic of a queue?\n\n\n\n\n\n\n\n\n\n", {"Last In, First Out", "First In, Last Out", "First In, First Out", "Random order"}, 2 });
        questions.push_back({ "\n\n\tWhich operation is used to add an element to a queue?\n\n\n\n\n\n\n\n\n\n", {"Push", "Pop", "Enqueue", "Dequeue"}, 2 });
        questions.push_back({ "\n\n\tIn a binary search tree, for any given node, \n\tthe left subtree contains nodes with values that are:\n\n\n\n\n\n\n\n\n\n", {"Greater than the node’s value", "Equal to the node’s value", "Less than the node’s value", "Less than the node’s value"}, 2 });
    }

    else if (difficulty == 2)
    {
        setConsoleTextColor(8);
        questions.push_back({ "\n\n\tWhich of the following is true about a doubly linked list?\n\n\n\n\n\n\n\n\n\n\n", {"It has only one pointer for each node.", "It can be traversed in both directions.", "It requires more memory than a singly linked list but is faster for certain operations.", "Both B and C."}, 3 });
        questions.push_back({ "\n\n\tWhat is the time complexity of inserting a new node at the \n\tbeginning of a singly linked list?\n\n\n\n\n\n\n\n\n\n\n", {"O(1)", "O(n)", "O(log n)", "O(n^2)"}, 0 });
        questions.push_back({ "\n\n\tWhich of the following applications is a typical use case for \n\ta stack?\n\n\n\n\n\n\n\n\n\n\n", {"Undo functionality in text editors", "Managing resources in a web server", "Implementing a priority queue", "Storing a list of items"}, 0 });
        questions.push_back({ "\n\n\tIn a stack implemented using an array, what happens if you try \n\tto push an element onto a full stack?\n\n\n\n\n\n\n\n\n\n\n", {"The stack expands automatically", "The program crashes", "An error is raised (stack overflow).", "The oldest element is removed."}, 2 });
        questions.push_back({ "\n\n\tWhat is the time complexity of the dequeue operation in a queue \n\timplemented with a linked list?\n\n\n\n\n\n\n\n\n\n\n", {"O(1)", "O(n)", "O(log n)", "O(n^2)"}, 0 });
        questions.push_back({ "\n\n\tWhich of the following statements is true regarding a circular \n\tqueue?\n\n\n\n\n\n\n\n\n\n\n", {"It uses more memory than a linear queue.", "It can prevent the wastage of space that can occur in a linear queue.", "It is implemented using a linked list only.", "It does not support dynamic size changes."}, 1 });
        questions.push_back({ "\n\n\tWhat is the worst-case time complexity for searching in a binary \n\tsearch tree (BST) that is unbalanced?\n\n\n\n\n\n\n\n\n\n\n", {"O(log n)", "O(n)", "O(n log n)", "O(1)"}, 1 });
    }

    else if (difficulty == 3)
    {
        setConsoleTextColor(6);
        questions.push_back({ "\n\n\t01100001 01101110 01110011 01110111 01100101 01110010 00100000 01101001 \n\t01110011 00100000 01000010\n\n\n\n\n\n\n\n\n\n\n", {"01100001", "01000010", "01100011", "01100100"}, 1 });
        questions.push_back({ "\n\n\tIn a doubly linked list, if you want to reverse the list in place, \n\twhat is the minimum number \n\tof pointer changes required for each node?\n\n\n\n\n\n\n\n\n\n\n", {"A) 1", "B) 2", "C) 3", "D) 4"}, 2 });
        questions.push_back({ "\n\n\tWhich of the following is true about stack-based recursion in C++?\n\n\n\n\n\n\n\n\n\n\n", {"A) Recursion always increases the memory usage linearly with the input size.", "B) Recursion depth is limited by the stack size in the system memory.", "C) Recursion is always faster than iteration.", "D) Recursion is always memory efficient compared to an iterative approach."}, 1 });
        questions.push_back({ "\n\n\tIf a queue is implemented using two stacks, what is the time complexity of an enqueuen\n\t operation if both stacks are initially empty?\n\n\n\n\n\n\n\n\n\n\n", {"A) O(1)", "B) O(log n)", "C) O(n)", "D) O(n^2)"}, 0 });
        questions.push_back({ "\n\n\tWhich of the following properties is unique to a queue data structure \n\tcompared to a stack?\n\n\n\n\n\n\n\n\n\n\n", {"A) Elements are inserted at one end and removed from the other.", "B) It supports Last In, First Out (LIFO) order.", "C) It only allows operations from the front of the structure.", "D) Elements are always removed in the same order they were added."}, 0 });
        questions.push_back({ "\n\n\tIn a binary search tree, which traversal method results in nodes being \n\tprocessed in non-decreasing order?\n\n\n\n\n\n\n\n\n\n\n", {"A) Pre-order traversal", "B) Post-order traversal", "C) Level-order traversal", "D) In-order traversal"}, 3 });
        questions.push_back({ "\n\n\tWhat is the minimum height of a binary search tree with 31 nodes?\n\n\n\n\n\n\n\n\n\n\n", {"A) 4", "B) 5", "C) 6", "D) 7"}, 1 });
    }

    else if (difficulty == 4)
    {
        setConsoleTextColor(4);
        questions.push_back({ "\n\nWhat will happen if the following C++ function is called with a nullptr \nargument for `node`?\n\n\t\n\tvoid remove(Node* node) {\n\t\tif (node->prev != nullptr)\n\t\t\tnode->prev->next = node->next;\n\t\tif (node->next != nullptr)\n\t\t\tnode->next->prev = node->prev;\n\t\tdelete node;\n\t}\n\n\n\n\n\n\n", {"A) It will delete the node without any issue.", "B) It will cause a segmentation fault.", "C) It will do nothing and return a nullptr.", "D) It will throw an exception."}, 1 });
        questions.push_back({ "\n\nIn the following stack implementation, what is the effect of calling push() \nwhen the stack is already full?\n\n\tclass Stack {\n\t\tint top;\n\t\tint capacity;\n\t\tint* array;\n\t\tpublic:\n\t\t\tStack(int size) {\n\t\t\t\tcapacity = size;\n\t\t\t\ttop = -1;\n\t\t\t\tarray = new int[size];\n\t\t\t}\n\t\t\tvoid push(int x) {\n\t\t\t\tarray[++top] = x; // Potential stack overflow\n\t\t\t}\n\t};\n\n\n\n", {"A) The last element is replaced by the new element.", "B) An error occurs, and the program crashes.", "C) The stack automatically expands.", "D) The new element is discarded silently."}, 1 });
        questions.push_back({ "\n\nWhat is the time complexity of the following enqueue function in a circular \nqueue implementation?\n\n\tbool enqueue(int item) {\n\t\tif (size == capacity) return false; // Queue is full\n\t\trear = (rear + 1) % capacity;\n\t\tarray[rear] = item;\n\t\tsize++;\n\t\treturn true;\n\t}\n\n\n\n\n\n\n", {"A) O(1)", "B) O(n)", "C) O(log n)", "D) O(n^2)"}, 0 });
        questions.push_back({ "\n\nGiven the following insert function for a binary search tree, what happens if \nthe tree is unbalanced and contains only left children?\n\n\tBSTNode* insert(BSTNode* node, int key) {\n\t\tif (node == nullptr) {\n\t\t\tBSTNode* newNode = new BSTNode();\n\t\t\tnewNode->key = key;\n\t\t\tnewNode->left = newNode->right = nullptr;\n\t\t\treturn newNode;\n\t\t}\n\t\tif (key < node->key)\n\t\t\tnode->left = insert(node->left, key);\n\t\telse\n\t\t\tnode->right = insert(node->right, key);\n\t\treturn node;\n\t}\n\n\n", {"A) The tree will remain balanced.", "B) The height of the tree will be O(n).", "C) The insert operation will be O(log n).", "D) The insert function will fail."}, 1 });
        questions.push_back({ "\n\nIn the following code for a doubly linked list, what is the impact of deleting \nthe last node?\n\n\tvoid remove(DListNode* node) {\n\t\tif (node->prev != nullptr)\n\t\t\tnode->prev->next = node->next;\n\t\tif (node->next != nullptr)\n\t\t\tnode->next->prev = node->prev;\n\t\tdelete node;\n\t}\n\n\n\n\n\n\n", {"A) It causes memory leak as the previous node is not updated.", "B) It sets the previous node's next pointer to nullptr.", "C) It will throw an error if the node is the last node.", "D) It does nothing."}, 1 });
        questions.push_back({ "\n\nWhat will be the output of the following in-order traversal function if the tree \nhas nodes with keys 30, 20, and 10?\n\n\n\tvoid inOrder(BSTNode* root) {\n\t\tif (root != nullptr) {\n\t\t\tinOrder(root->left);\n\t\t\tstd::cout << root->key << \" \";\n\t\t\tinOrder(root->right);\n\t\t}\n\t}\n\n\n\n\n\n\n", {"A) 30 20 10", "B) 10 20 30", "C) 20 10 30", "D) 30 10 20"}, 1 });
        questions.push_back({ "\n\nIn the following C++ code, which will lead to undefined behavior if called?\n\n\tclass Stack {\n\t\tint* arr;\n\t\tint top;\n\t\tint capacity;\n\t\tpublic:\n\t\t\tStack(int size) {\n\t\t\t\tarr = new int[size];\n\t\t\t\ttop = -1;\n\t\t\t\tcapacity = size;\n\t\t\t}\n\t\t\tvoid pop() {\n\t\t\t\tif (top < 0) return; // Potential undefined behavior\n\t\t\t\ttop--;\n\t\t\t}\n\t};\n\n\n\n", {"A) If pop is called on an empty stack.", "B) If push is called on a full stack.", "C) If capacity is set to zero.", "D) All of the above."}, 0 });

    }
    

    return questions;
}

void handleDifficultySelection(const string& playerName, int difficulty) {
   
    int scoreThresholds[] = { 0, 60, 210, 560, 700 }; 

    
    vector<Question> questions = getQuestions(difficulty);

    
    int selectedPowerUp = selectPowerUp();

 
    int score = Quiz(questions, selectedPowerUp, difficulty);

    cout << "\nFinal Score: " << score << endl;

   

    if (score >= scoreThresholds[difficulty])
    {
        if (difficulty == 0 || difficulty == 1)
        {
            achievements[difficulty] = true;
        }
        else if (difficulty == 2)
        {
            if (score == scoreThresholds[difficulty])
            {
                achievements[difficulty] = true;
            }
            else
            {
                achievements[difficulty] = false;
            }
        }
        else if (difficulty == 3)
        {
            if (powerUpUsed[0] == true || powerUpUsed[1] == true || powerUpUsed[2] == true && score >= scoreThresholds[difficulty])
            {
                achievements[difficulty] = true;
            }
            else
            {
                achievements[difficulty] = false;
            }

        }
        else if (difficulty == 4)
        {
            if (powerUpUsed[0] == true || powerUpUsed[1] == true || powerUpUsed[2] == true && score >= scoreThresholds[difficulty])
            {
                achievements[difficulty] = true;
            }
            else
            {
                achievements[difficulty] = false;
            }
        }
    }


    addScore(playerName, score);

    cin.get();
}



