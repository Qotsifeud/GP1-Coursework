#include "Menu.h"

extern int menuChoice = 0; //extern example to share data with menu and gameSource

void Menu::run() 
{
    bool valid = false;
    do { //do while
        system("cls"); // clear the screen
        cout << "Start Screen:" << endl;
        cout << "1. Play Space Invaders" << endl;
        cout << "2. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            menuChoice = 1;
            valid = true;
            system("cls"); // clear the screen
            break;
        case 2:
            menuChoice = 2;
            valid = true;
            system("cls"); // clear the screen
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

void Menu::gameOver()
{
    bool valid = false;
    do {
        system("cls");
        system("cls");
        cout << "GAME OVER" << endl;
        cout << "TRY AGAIN?" << endl;
        cout << "1. YES" << endl;
        cout << "2. NO" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            menuChoice = 1;
            valid = true;
            system("cls"); // clear the screen
            break;
        case 2:
            menuChoice = 0;
            valid = true;
            system("cls"); // clear the screen
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