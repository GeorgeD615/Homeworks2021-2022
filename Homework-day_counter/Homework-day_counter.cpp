#include <iostream>

int main()
{
    int d1, m1, y1, d2, m2, y2, C = 0;
    std::cout << "Input d1:";
    std::cin >> d1;
    std::cout << "Input m1:";
    std::cin >> m1;
    std::cout << "Input y1:";
    std::cin >> y1;
    std::cout << "start: " << d1 << "." << m1 << "." << y1 << std::endl;
    std::cout << "Input d2:";
    std::cin >> d2;
    std::cout << "Input m2:";
    std::cin >> m2;
    std::cout << "Input y2:";
    std::cin >> y2;
    std::cout << "finish: " << d2 << "." << m2 << "." << y2 << std::endl;
    //подсчёт дней во всех полных годах
    for (int i = y1 + 1; i < y2; ++i) {
        if (((i % 4 == 0) & (i % 100 != 0)) || (i % 400 == 0)) {
            C += 366;
        }
        else {
            C += 365;
        }
    }
    //подсчёт дней в первом (неполном) годе
    switch (m1) {
    case(1):
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0)) {
            C += 335;
        }
        else {
            C += 334;
        }
        break;
        C += 31 - d1;
    case(2):
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0)) {
            C += 29 - d1;
        }
        else {
            C += 28 - d1;
        }
        C += 306;
        break;
    case(3):
        C += 275;
        C += 31 - d1;
        break;
    case(4):
        C += 245;
        C += 30 - d1;
        break;
    case(5):
        C += 214;
        C += 31 - d1;
        break;
    case(6):
        C += 184;
        C += 30 - d1;
        break;
    case(7):
        C += 153;
        C += 31 - d1;
        break;
    case(8):
        C += 122;
        C += 31 - d1;
        break;
    case(9):
        C += 92;
        C += 30 - d1;
        break;
    case(10):
        C += 61;
        C += 31 - d1;
        break;
    case(11):
        C += 31;
        C += 30 - d1;
        break;
    case(12):
        C += 31 - d1;
        break;
    }
    //подсчёт дней в последнем (неполном) годе
    switch (m2) {
    case(1):
        C += d2;
        break;
    case(2):
        C += 31;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    case(3):
        C += 59;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    case(4):
        C += 90;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    case(5):
        C += 120;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    case(6):
        C += 151;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    case(7):
        C += 181;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    case(8):
        C += 212;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    case(9):
        C += 243;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    case(10):
        C += 273;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    case(11):
        C += 304;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    case(12):
        C += 334;
        C += d2;
        if (((y1 % 4 == 0) & (y1 % 100 != 0)) || (y1 % 400 == 0))
            C += 1;
        break;
    }
    std::cout << "Days: " << C;
}
