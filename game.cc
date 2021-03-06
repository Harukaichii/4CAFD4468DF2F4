#include "game.h"
#include "player.h"
#include <iostream>
#include <iomanip>
using namespace std;

// initialize two players
// more constructor for differnnt mode in command line
Game::Game() :
    playerOne{new Player(this)}, 
    playerTwo{new Player(this)}, 
    currentPlayer{playerOne.get()} {}

// player's operation
// do not need to check, call currentPlayer's method directly
void Game::setLevel(int level) {
    currentPlayer->setLevel(level);
    print();
}

void Game::move(string type, int step) {
    currentPlayer->move(type, step);
    print();
}

void Game::rotate(bool counter, int step) {
    currentPlayer->rotate(counter, step);
    print();
}

// later, clear row
void Game::drop() {
    currentPlayer->drop();
    print();
}

bool Game::gameOver() {
    return isOver;
}

void Game::setGameOver() {
    isOver = true;
}

// next player's turn
void Game::turnOver() {
    if (currentPlayer == playerOne.get()) {
        currentPlayer = playerTwo.get();
    } else {
        currentPlayer = playerOne.get();
    }
}

// finish later
void Game::specialAction() {}

// finish later
void Game::print() {
    // print level
    cout << "Level:";
    cout << setw(5) << playerOne->getLevel();
    cout  << setw(7) << " ";
    cout << "Level:";
    cout << setw(5) << playerTwo->getLevel();
    cout << endl;
    // print score
    cout << "Score:";
    cout << setw(5) << playerOne->getCurrentScore();
    cout  << setw(7) << " ";
    cout << "Score:";
    cout << setw(5) << playerTwo->getCurrentScore();
    cout << endl;
    // print dash
    cout << "-----------";
    cout << setw(7) << " ";
    cout << "-----------";
    cout << endl;
    // print grid
    for (int i = 0; i < 18; i++) {
        cout << playerOne->getGridRow(i);
        cout << setw(7) << " ";
        cout << playerTwo->getGridRow(i);
        cout << endl;
    }
    // print dash
    cout << "-----------";
    cout  << setw(7) << " ";
    cout << "-----------";
    cout << endl;
    // print next
    cout << "Next:";
    cout << setw(6) << " ";
    cout << setw(7) << " ";
    cout << "Next:";
    cout << setw(6) << " " << endl;
    cout << this->getNextBlockFirstRow(playerOne->getNextBlock());
    cout << setw(7) << " ";
    cout << this->getNextBlockFirstRow(playerTwo->getNextBlock());
    cout << endl;
    cout << this->getNextBlockSecondRow(playerOne->getNextBlock());
    cout << setw(7) << " ";
    cout << this->getNextBlockSecondRow(playerTwo->getNextBlock());
    cout << endl;
}

// helper, modify later
string Game::getNextBlockFirstRow(string type) {
    if (type == "I") {
        return "           ";
    } else if (type == "J") {
        return "J          ";
    } else if (type == "L") {
        return "  L        ";
    } else if (type == "O") {
        return "OO         ";
    } else if (type == "S") {
        return " SS        ";
    } else if (type == "Z") {
        return "ZZ         ";
    }
    return "TTT        ";
}

string Game::getNextBlockSecondRow(string type) {
    if (type == "I") {
        return "IIII       ";
    } else if (type == "J") {
        return "JJJ        ";
    } else if (type == "L") {
        return "LLL        ";
    } else if (type == "O") {
        return "OO         ";
    } else if (type == "S") {
        return "SS         ";
    } else if (type == "Z") {
        return " ZZ        ";
    }
    return " T         ";
}
