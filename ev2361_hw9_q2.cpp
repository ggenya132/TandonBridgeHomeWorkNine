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
void mapStringToLetterFrequency(string userInput, int letterFrequency[]) {
    for (int i = 0; i < userInput.size(); i++) {
        char currentChar = userInput[i];

        int index = charToIndex(currentChar);
        if (index != -1) {
            letterFrequency[index] = letterFrequency[index] + 1;
        }
    }
}
bool isAnagram(int letterFrequencyOne[], int letterFrequencyTwo[]) {
    const int LENGTH_OF_ARRAYS = 26;
    for (int i = 0; i < LENGTH_OF_ARRAYS; i++) {
        if (letterFrequencyOne[i] != letterFrequencyTwo[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    string userInputOne, userInputTwo;
    cout << "Please enter the first line of text:" << endl;

    getline(cin, userInputOne);

    cout << "Please enter the second line of text:" << endl;
    getline(cin, userInputTwo);

    int indexOfLetterFrequencyInputOne[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                                              0, 0, 0, 0, 0, 0, 0, 0, 0,
                                              0, 0, 0, 0, 0, 0, 0, 0};

    int indexOfLetterFrequencyInputTwo[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                                              0, 0, 0, 0, 0, 0, 0, 0, 0,
                                              0, 0, 0, 0, 0, 0, 0, 0};
    mapStringToLetterFrequency(userInputOne, indexOfLetterFrequencyInputOne);
    mapStringToLetterFrequency(userInputTwo, indexOfLetterFrequencyInputTwo);
    bool inputsAreAnagrams = isAnagram(indexOfLetterFrequencyInputOne,
                                       indexOfLetterFrequencyInputTwo);
    string isAnagramsOutput = inputsAreAnagrams ? "true" : "false";
    cout << "Are the inputs anagrams? " << endl << isAnagramsOutput;
}