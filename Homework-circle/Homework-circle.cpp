#include <iostream>

int main()
{
	double r;
	int k = 0, t = 0;
	std::cout << "Input R: ";
	std::cin >> r;
	double x, y;
	for (int i = 0; i < 10000; ++i) {
		x = rand();
		y = rand();
		x = x / 33000.0 * r;
		y = y / 33000.0 * r;
		++t;
		if (x * x + y * y <= (double)r * (double)r) {
			++k;
		}
	}
	std::cout << "pi = " << ((double)k / (double)t)*4 << std::endl;
}
