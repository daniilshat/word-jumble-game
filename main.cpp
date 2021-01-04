/*
 * A simple logic game from "Beginning C++ Through Game Programming" by Michael Dawson.
 * In the future I plan to upgrade the game code, add more words, work with the database and GUI
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    enum fields {
        WORD,
        HINT,
        NUM_FIELDS
    };
    const int NUM_WORDS = 5;
    //declaring a multidimensional array with game data
    const string WORDS[NUM_WORDS][NUM_FIELDS] = {
            { "python", "'Snake' programming language." },
            { "earth", "Our planet." },
            { "russia", "Vodka, balalaika, caviar, bears." },
            { "hurricane", "Katrina, Camille, Mitch." },
            { "ocean", "Atlantic, Pacific, Indian."}
};

//choosing a random word from an array
srand(static_cast<unsigned int>(time(0)));
int choice = (rand() % NUM_WORDS);
string theWord = WORDS[choice][WORD]; //hidden word
string theHint = WORDS[choice][HINT]; //hint

string jumble = theWord; //mixed version of the word
int length = jumble.size();
//word shuffle loop
for  (int i = 0; i < length; ++i) {
    int index1 = (rand() % length);
    int index2 = (rand() % length);
    char temp = jumble[index1];
    jumble[index1] = jumble[index2];
    jumble[index2] = temp;
}

//invite the user to the game
cout << "\t\t***Welcome to WORD JUMBLE game!***\n\n";
cout << "Unscramble the letters to make a word.\n";
cout << "Enter 'hint' for a hint.\n";
cout << "Enter 'quit' to quit the game.\n\n";
cout << "The jumble is: " << jumble;
string guess;
cout << "\n\nYour guess: ";
cin >> guess;

//main game loop
while ((guess != theWord) && (guess != "quit")) {
    if (guess == "hint") {
        cout << theHint;
    }
    else {
        cout << "Sorry, that's not it.";
    }
    cout << "\n\nYour guess: ";
    cin >> guess;
}

if (guess == theWord) {
    cout << "\nThat's it! You guessed it!\n";
}
cout << "\nThanks for playing.\n";

return 0;
}