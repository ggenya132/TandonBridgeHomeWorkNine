#include <iostream>
#include <string>

using namespace std;
const char SPACE = ' ';
int charToIndex(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';  // For uppercase letters
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a';  // For lowercase letters
    } else {
        return -1;  // For non-alphabetic characters
    }
}

char indexToChar(int c) { return c + 'a'; }

int main() {
    string userInput;
    cout << "Please enter a line of text:" << endl;

    getline(cin, userInput);

    int numberOfWords = 1;
    bool previousCharIsSpace = false;
    int indexOfLetterFrequency[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < userInput.size(); i++) {
        char currentChar = userInput[i];
        if (currentChar == SPACE) {
            previousCharIsSpace = true;
        } else {
            int index = charToIndex(currentChar);
            if (index != -1) {
                indexOfLetterFrequency[index] =
                    indexOfLetterFrequency[index] + 1;
                if (previousCharIsSpace) {
                    numberOfWords++;
                    previousCharIsSpace = false;
                }
            }
        }
    }

    cout << numberOfWords << "\t" << "words" << endl;

    for (int i = 0; i < 26; i++) {
        int occurences = indexOfLetterFrequency[i];
        if (occurences != 0) {
            cout << occurences << "\t" << indexToChar(i) << endl;
        }
    }
    return 1;
}