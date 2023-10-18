#include <iostream>
#include <string>
using namespace std;

// Structure for car information
struct Cars {
    string company[9] = { "Maruti Suzuki", "Volkswagen", "BMW", "Audi", "KIA", "Tesla", "Mercedes", "Mahindra", "TATA" };
    string model[9] = { "800", "2020", "Q7", "R8", "Saltos", "S-Series", "Benz", "Thar", "Nano" };
    string color[9] = { "Yellow", "Black", "Red", "Brown", "Blue", "Silver", "Black", "Grey", "Red" };
    string max_speed[9] = { "80 Km/h", "200 Km/h", "300 Km/h", "250 Km/h", "320 Km/h", "400 Km/h", "200 Km/h", "250 Km/h", "280 Km/h" };
    int price[9] = { 10000, 20000, 50000, 40000, 50000, 50000, 20000, 20000, 20000 };
} car;

// Structure for lease information
struct Lease_info {
    string Name;
    string Natio_ID;
    int payment_acc;
} lease;

// Function to clear the screen
void clearScreen() {
    cout << "\033[2J\033[1;1H";  // ANSI escape code to clear the screen
}

// First output: Display car menu
void Menu() {
    int num = 1;
    for (int i = 0; i < 9; ++i) {
        cout << "\t\t\tEnter " << num << " - To Select " << car.company[i] << endl;
        num++;
    }
}

// Second output: Display car details
void Details(int Choice) {
    cout << "\n\n\n\t\t\t-----------------------------\n";
    cout << "\t\t\tYou Have Selected - " << car.company[Choice - 1] << endl;
    cout << "\t\t\t-----------------------------\n\n\n";
    cout << "\t\t\tModel: " << car.model[Choice - 1] << endl;
    cout << "\t\t\tColor: " << car.color[Choice - 1] << endl;
    cout << "\t\t\tMaximum Speed: " << car.max_speed[Choice - 1] << endl;
    cout << "\t\t\tPrice: " << car.price[Choice - 1] << endl;
}

// Check lease credit and handle user input
void user_input(int theChoice) {
    int j = theChoice - 1;

    cout << "\t\t\t----------------------------------------\n";
    cout << "\t\t\tPlease Provide Your Personal Details:\n";
    cout << "\t\t\t----------------------------------------\n\n";
    cout << "\nNOTE: PROVIDE FIRST NAME ONLY, DO NOT ENTER SPACE WHILE PROVIDING NAME.\n";
    cout << "PAYMENT WON'T PROCEED IF THE GIVEN AMOUNT IS LESS THAN THE RATE OF THE CAR.\n\n\n\n";
    cout << "\t\t\tEnter Your Name: ";
    cin.ignore();
    getline(cin, lease.Name);
    cout << "\t\t\tEnter Your National ID: ";
    getline(cin, lease.Natio_ID);
    cout << "\t\t\tPayment Amount: ";
    cin >> lease.payment_acc;

    if (lease.payment_acc >= car.price[j]) {
        cout << "\n\n\n\t\t\tProcess has been done successfully!!" << endl;
    } else {
        cout << "\n\n\n\t\t\tNot Available" << endl;
    }
}

int main() {
    string decide = "yes";

    clearScreen();

    cout << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\tSIMPLE CAR RENTAL SYSTEM\n";
    cout << "\t\t\tWelcome to Our Company, Choose from the menu:\n";
    cout << "\t\t\t----------------------------------------------\n";

    while (decide != "exit") {
        Menu();
        cout << "\n\n\n\t\t\tYour Choice: ";
        int theChoice;
        cin >> theChoice;

        if (theChoice >= 1 && theChoice <= 9) {
            Details(theChoice);
            cout << "\n\n\n\t\t\tAre You Sure you want to rent this Car? (yes/no/exit): ";
            cin >> decide;

            if (decide == "yes") {
                user_input(theChoice);
                cout << "\n\n\t\t\tDo you want to continue? (yes/no): ";
                cin >> decide;

                if (decide == "no") {
                    clearScreen();
                    break;
                }
                clearScreen();
            } else if (decide == "exit") {
                clearScreen();
                break;
            }
        } else {
            cout << "\n\n\n\t\t\tInvalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}