#include "Menu.h"
#include <conio.h> // for _getch()
#include <iostream>
#include <limits> // For std::numeric_limits

using namespace std;

extern int menuChoice = 0; //extern example to share data with menu and gameSource

void clearInputBuffer() {
    if (cin.fail()) {
        cin.clear(); // Clear any error flags
    }
    // Use a loop to discard any remaining characters in the input buffer
    while (cin.peek() != '\n' && cin.peek() != EOF) {
        cin.get();
    }

    if (cin.peek() == '\n') {
        cin.get(); // Remove the newline character from the buffer
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Unix/Linux
#endif
}


void Menu::run()
{
    bool valid = false;
    int choice;
    do { //do while
        clearScreen();
        cout << "Start Screen:" << endl;
        cout << "1. Play Space Invaders" << endl;
        cout << "2. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            menuChoice = 1;
            valid = true;
            clearScreen();
            break;
        case 2:
            menuChoice = 2;
            valid = true;
            clearScreen();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        if (!valid) {
            cout << "Press any key to continue..." << endl;
            _getch(); // wait for user to press any key
        }
    } while (!valid);

}

void Menu::gameOver() {
    clearScreen();

    bool valid = false;
    cout << "GAME OVER" << endl;
    cout << "TRY AGAIN?" << endl;
    cout << "1. YES" << endl;
    cout << "2. NO" << endl;
    cout << "Select your choice.";

    while (!valid) {
        if (GetKeyState('1') & 0x8000) {
            menuChoice = 1;
            valid = true;
            clearScreen();
        }
        if (GetKeyState('2') & 0x8000) {
            exit(0);
        }
    }

    cout << "Press any key to continue..." << endl;
    _getch(); // wait for user to press any key
}