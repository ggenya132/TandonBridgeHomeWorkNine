#include <iostream>
using namespace std;
bool isOdd(int num) { return num % 2 == 1; }
void oddsKeepEvensFlip(int arr[], int arrSize) {
    int numberOfEvens = 0;
    int numberOfOdds = 0;
    for (int i = 0; i < arrSize; i++) {
        if (isOdd(arr[i])) {
            numberOfOdds++;
        } else {
            numberOfEvens++;
        }
    }
    int evens[numberOfEvens];
    int odds[numberOfOdds];
    int indexOfOdd = 0;
    int indexOfEven = 0;
    for (int i = 0; i < arrSize; i++) {
        if (isOdd(arr[i])) {
            odds[indexOfOdd] = arr[i];
            indexOfOdd++;
        } else {
            evens[indexOfEven] = arr[i];
            indexOfEven++;
        }
    }
    for (int i = 0; i < numberOfOdds; i++) {
        arr[i] = odds[i];
    }
    int reverseIndex = numberOfEvens - 1;
    for (int i = numberOfOdds; i < arrSize; i++) {
        arr[i] = evens[reverseIndex];
        reverseIndex--;
    }
}
int main() {
    int arr[] = {5, 2, 11, 7, 6, 4};
    oddsKeepEvensFlip(arr, 6);
    for (auto i : arr) {
        cout << i << endl;
    }
}