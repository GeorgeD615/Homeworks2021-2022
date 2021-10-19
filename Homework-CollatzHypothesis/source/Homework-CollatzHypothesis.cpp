#include <iostream>

int main()
{
    int n;
    do {
        std::cout << "Input n:";
        std::cin >> n;
    } while (n < 1);
    while (n != 1) {
        std::cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            ++n;
        }
    }
    std::cout << 1;
}