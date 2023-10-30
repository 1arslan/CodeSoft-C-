#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int secret_number = std::rand() % 100 + 1;
    int Guess;
    int attempts = 0;
    cout << "Welcome to the Guess the Number Game!" <<endl;

    do {
        cout << "Guess the secret number (between 1 and 100): ";
        cin >> Guess;
        attempts++;

        if (Guess < secret_number) {
            cout << "Too low! Try again." <<endl;
        } 
        else if (Guess > secret_number) {
            cout << "Too high! Try again." << endl;
        } 
        else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." <<endl;
        }
    } while (Guess != secret_number);

    return 0;
}
