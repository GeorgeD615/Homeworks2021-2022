#include <iostream>

int main()
{
    const int ROWS = 2, COLS = 3;
    int Arr[ROWS][COLS];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            Arr[i][j] = rand();
        }
    }
    std::cout << "Array:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << Arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "Array:";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << Arr[i][j] << " ";
        }
    }
    int ArrT[COLS][ROWS];
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            ArrT[i][j] = Arr[j][i];
        }
    }
    std::cout << std::endl;
    std::cout << "ArrayTrans:" << std::endl;
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            std::cout << ArrT[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "ArrayTrans:";
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            std::cout << ArrT[i][j] << " ";
        }
    }
}