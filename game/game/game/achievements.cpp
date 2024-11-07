#include <iostream>
#include "startgame.h"
#include "settings.h"
#include "start&menu.h" 
#include "achievements.h"

using namespace std;

bool achievements[5] = { false, false, false, false, false };


void displayAchievements() {
    system("cls");
    setConsoleFont24();
    string difficultyNames[] = { "\t\t\tCertified DiDDler: \n\t\t\t  COMPLETE TUTORIAL\t\t\t\t", "\t\t\tEasy A$$ Pie: \n\t\t\t  REACH 60+ SCORE IN EASY\t\t\t", "\t\t\tRight In The Middle: \n\t\t\t  SCORE EXACT 210 IN MEDIUM\t\t\t", "\t\t\tPlay hard to get: \n\t\t\t  NO POWER-UP SCORE >= 560 IN HARD\t\t", "\t\t\tScorched Earth: \n\t\t\t  NO POWER-UP, 7 STREAK IN HELL \t\t" };

    cout << tabs() << "\tAchievements:\n\n\n";
    for (int i = 0; i < 5; ++i) {
        cout << difficultyNames[i] << ": ";
        if (achievements[i]) {
            cout << "Done\n\n";
        }
        else {
            cout << "Not Done\n\n";
        }
    }
    cin.get();
    welcome();
}