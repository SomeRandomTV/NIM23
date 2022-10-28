#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

class NimGame{    
public:
    NimGame();                                  
    void setPlayerName(string playerName);        
    void setPlayerMove(int playerSticks);      
    void setSticks(int amtSticks);         
    string getName();                       
    int getPlayerSticks();                  
    int getTotalSticks();                   
    void whoWon(string name, bool player);
    void PlayAgain(char continue);
    void Print();



private:
    string name;
    int sticks;
    int totalSticksRemaing;
    bool gameWinner;
  

};

bool gameEnd = false;

NimGame::NimGame() {                                // Default Constructor
    name = "NoName";
    sticks = -1;
    totalSticksRemaing = -1;
    gameWinner = false;
}

void NimGame::setPlayerName(string playerName) {
    name = playerName;
}

void NimGame::setSticks(int amtSticks) {
    totalSticksRemaing = amtSticks;
}
void NimGame::setPlayerMove(int playerSticks) {
    totalSticksRemaing -= playerSticks;
}

string NimGame::getName() {
    return name;
}

int NimGame::getTotalSticks() {
    return totalSticksRemaing;
}

int NimGame::getPlayerSticks() {
    return sticks;
}

void NimGame::whoWon(string name, bool player) {

    if ((totalSticksRemaing <= 0) && (player)) {
        cout << name << " Won\n";
        gameEnd = true;
        
  
    }
    else if ((totalSticksRemaing <= 0) && (player == false)) {
        cout << name << " Won\n";
        gameEnd = true;
       
    }
}



void NimGame::Print() {
    cout << "There are: " << totalSticksRemaing << " remaining\n";
}




int main() {
    NimGame Game;
    NimGame player1;
    NimGame player2;

    int sticksTaken;
    bool playerWon;
    char userInput;
    userInput = 'y';

    cout << "Welcome to!\n";
    Sleep(2000);
   
    cout << R"(


        NN     NN IIIIII MM       MM   
        NNNN   NN   II   MMMM   MMMM  
        NN NN  NN   II   MM MM MM MM  
        NN  NN NN   II   MM  MMM  MM  
        NN   NNNN IIIIII MM       MM  


        )" << endl;


    string playerOneName;
    cout << "What is your name: ";
    cin >> playerOneName;
    player1.setPlayerName(playerOneName);

    string playerTwoName;
    cout << "What is your name: ";
    cin >> playerTwoName;
    player2.setPlayerName(playerTwoName);

    int totalSticks;
    cout << "How many sticks do you want: ";
    cin >> totalSticks;
    Game.setSticks(totalSticks);

    while (userInput == 'y') {
        cout << playerOneName << " it is your turn. How many sticks you want: ";
        cin >> sticksTaken;
        Game.setPlayerMove(sticksTaken);
        Game.getTotalSticks();
        Game.Print();
        playerWon = true;
        Game.whoWon(playerOneName, playerWon);
        


        cout << playerTwoName << " it is your turn. How many sticks you want: ";
        cin >> sticksTaken;
        Game.setPlayerMove(sticksTaken);
        Game.getTotalSticks();
        Game.Print();
        playerWon = false;
        Game.whoWon(playerTwoName, playerWon);

        if (gameEnd) {
            cout << "Would you like to play again y/n: ";
            cin >> userInput;
            
        }
        else {
            pass;
            //exit(3);
        }

    }   

    
}
