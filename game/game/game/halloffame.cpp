#include <iostream>
#include "settings.h"
#include "start&menu.h"
#include "startgame.h"
#include <vector>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;


    Player(const string& n, int s) : name(n), score(s) {}
};
vector<Player> scoreboard;

int generateRandomScore(int min, int max) {
    return std::rand() % (max - min + 1) + min;
}
void addScore(const string& playerName, int playerScore) {
    
    auto it = find_if(scoreboard.begin(), scoreboard.end(), [&](const Player& p) {
        return p.name == playerName; 
        });

    if (it != scoreboard.end()) {
        
        it->score = playerScore;
    }
    else {
        scoreboard.emplace_back(playerName, playerScore);
    }

    
    sort(scoreboard.begin(), scoreboard.end(), [](const Player& a, const Player& b) {
        return a.score > b.score; 
        });
}

void displayScoreboard() {
    system("cls");
    setConsoleFont24();
    cout << tabs() << "    HALL OF FAME:\n";
    cout << tabs() << "====================\n";
    for (const auto& player : scoreboard) {
        cout << "\t\t\t\t   " << player.name << ": " << player.score << " points\n";
    }
    cout << tabs() << "====================\n";
    cin.get();
    welcome();
}

void exampleUsage() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(std::time(nullptr)));

    addScore("Walter White      ", generateRandomScore(10, 700));
    addScore("JoJi              ", generateRandomScore(10, 700));
    addScore("Ben Tennison      ", generateRandomScore(10, 700));
    addScore("Barack Obama      ", generateRandomScore(10, 700)); // Update score for Player1
    addScore("Bin Laden         ", generateRandomScore(10, 700));
    addScore("Raphael Hapon     ", generateRandomScore(10, 700));
    addScore("Brainard Izon     ", generateRandomScore(10, 700));
    addScore("Decalay Cedric    ", generateRandomScore(10, 700));
    addScore("Eric Dnggn        ", generateRandomScore(10, 700));
    addScore("Euland Borres     ", generateRandomScore(10, 700));
    addScore("Bontito           ", generateRandomScore(10, 700));
    addScore("Green Lantern     ", generateRandomScore(10, 700));
    addScore("Sabanal           ", generateRandomScore(10, 700));
    addScore("BlacK Goku        ", generateRandomScore(10, 700));
    addScore("Joseph Joestar    ", generateRandomScore(10, 700));
    addScore("Dio Brando        ", generateRandomScore(10, 700));
    addScore("Dexter Morgan     ", generateRandomScore(10, 700));
    addScore("Zach Hamilton     ", generateRandomScore(10, 700));
    addScore("Cedric Vicera     ", generateRandomScore(10, 700));
    addScore("MarkJhon Estopacia", generateRandomScore(10, 700));
    addScore("P Diddy           ", generateRandomScore(10, 700));
    addScore("Wayne Thomson     ", generateRandomScore(10, 700));
    addScore("Saul Goodman      ", generateRandomScore(10, 700));
    addScore("Jefrey Dahmer     ", generateRandomScore(10, 700));
    addScore("Jonny Goodness    ", generateRandomScore(10, 700));
    addScore("Ty$ign            ", generateRandomScore(10, 700));
    addScore("Vince Cortez      ", generateRandomScore(10, 700));
    displayScoreboard();
}