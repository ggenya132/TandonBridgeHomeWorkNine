#include <iostream>
using namespace std;
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int amountOfPositiveNumbers = 0;
    for (int i = 0; i < arrSize; i++) {
        int currentElement = arr[i];
        if (currentElement > 0) {
            amountOfPositiveNumbers++;
        }
    }
    int currentIndexOfNewArray = 0;
    // I have to initialize dynamically allocated heap memory as a pointer..
    int* newArray = new int[amountOfPositiveNumbers];
    for (int i = 0; i < arrSize; i++) {
        int currentElement = arr[i];
        if (currentElement > 0) {
            newArray[currentIndexOfNewArray] = currentElement;
            currentIndexOfNewArray++;
        }
    }
    outPosArrSize = amountOfPositiveNumbers;
    return newArray;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSize) {
    int amountOfPositiveNumbers = 0;
    for (int i = 0; i < arrSize; i++) {
        int currentElement = arr[i];
        if (currentElement > 0) {
            amountOfPositiveNumbers++;
        }
    }
    int currentIndexOfNewArray = 0;
    // I have to initialize dynamically allocated heap memory as a pointer..
    int* newArray = new int[amountOfPositiveNumbers];
    for (int i = 0; i < arrSize; i++) {
        int currentElement = arr[i];
        if (currentElement > 0) {
            newArray[currentIndexOfNewArray] = currentElement;
            currentIndexOfNewArray++;
        }
    }
    *outPosArrSize = amountOfPositiveNumbers;
    return newArray;
}
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int amountOfPositiveNumbers = 0;
    for (int i = 0; i < arrSize; i++) {
        int currentElement = arr[i];
        if (currentElement > 0) {
            amountOfPositiveNumbers++;
        }
    }
    int currentIndexOfNewArray = 0;
    // I have to initialize dynamically allocated heap memory as a pointer..
    int* newArray = new int[amountOfPositiveNumbers];
    for (int i = 0; i < arrSize; i++) {
        int currentElement = arr[i];
        if (currentElement > 0) {
            newArray[currentIndexOfNewArray] = currentElement;
            currentIndexOfNewArray++;
        }
    }
    outPosArr = newArray;
    outPosArrSize = amountOfPositiveNumbers;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr,
                 int* outPosArrSizePtr) {
    int amountOfPositiveNumbers = 0;
    for (int i = 0; i < arrSize; i++) {
        int currentElement = arr[i];
        if (currentElement > 0) {
            amountOfPositiveNumbers++;
        }
    }
    int currentIndexOfNewArray = 0;
    // I have to initialize dynamically allocated heap memory as a pointer..
    int* newArray = new int[amountOfPositiveNumbers];
    for (int i = 0; i < arrSize; i++) {
        int currentElement = arr[i];
        if (currentElement > 0) {
            newArray[currentIndexOfNewArray] = currentElement;
            currentIndexOfNewArray++;
        }
    }
    *outPosArrPtr = newArray;
    *outPosArrSizePtr = amountOfPositiveNumbers;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, -1, -3, 0, 6, 4};
    int arrSize = 6;

    cout << "Testing getPosNums1:" << endl;
    int outSize1 = 0;
    int* posArr1 = getPosNums1(arr, arrSize, outSize1);
    cout << "Positive numbers: ";
    printArray(posArr1, outSize1);
    cout << "Size: " << outSize1 << endl;
    delete[] posArr1;  // Free dynamically allocated memory

    cout << "\nTesting getPosNums2:" << endl;
    int outSize2 = 0;
    int* posArr2 = getPosNums2(arr, arrSize, &outSize2);
    cout << "Positive numbers: ";
    printArray(posArr2, outSize2);
    cout << "Size: " << outSize2 << endl;
    delete[] posArr2;  // Free dynamically allocated memory

    cout << "\nTesting getPosNums3:" << endl;
    int* posArr3 = nullptr;
    int outSize3 = 0;
    getPosNums3(arr, arrSize, posArr3, outSize3);
    cout << "Positive numbers: ";
    printArray(posArr3, outSize3);
    cout << "Size: " << outSize3 << endl;
    delete[] posArr3;  // Free dynamically allocated memory

    cout << "\nTesting getPosNums4:" << endl;
    int* posArr4 = nullptr;
    int outSize4 = 0;
    getPosNums4(arr, arrSize, &posArr4, &outSize4);
    cout << "Positive numbers: ";
    printArray(posArr4, outSize4);
    cout << "Size: " << outSize4 << endl;
    delete[] posArr4;  // Free dynamically allocated memory

    return 0;
}