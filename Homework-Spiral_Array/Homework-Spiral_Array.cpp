#include <iostream>

int main()
{
    int r, c, k = 0;
    std::cout << "Input rows: ";
    std::cin >> r;
    std::cout << "Input cols: ";
    std::cin >> c;
    int** arr = new int* [r];
    for (int i = 0; i < r; ++i) {
        arr[i] = new int[c];
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            arr[i][j] = 0;
        }
    }

    int rdown = r, rup = 0, cright = c, cleft = 0;
    while (true) {
        for (int i = cleft; i < cright-1; ++i) {
            arr[rup][i] = ++k;
        }
        cright--;
        if (arr[rup + 1][cright] != 0) {
            break;
        }

        for (int i = rup; i < rdown-1; ++i) {
            arr[i][cright] = ++k;
        }
        rdown--;
        if (arr[rdown][cright - 1] != 0) {
            break;
        }

        for (int i = cright; i > cleft; --i) {
            arr[rdown][i] = ++k;
        }
        cleft++;
        if (arr[rdown - 1][cleft] != 0) {
            break;
        }
        for (int i = rdown; i > rup; --i) {
            arr[i][cleft-1] = ++k;
        }
        rup++;
        if (arr[rup][cleft + 1] != 0) {
            break;
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (arr[i][j] == 0) {
                arr[i][j] == ++k;
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < r; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}
