#include <iostream>

int main()
{
	long double x;
	std::cout << "Input x: ";
	std::cin >> x;
	unsigned long long j = 2 * 3;
	int n;
	std::cout << "Input n: ";
	std::cin >> n;
	long double a = -((x*x*x)/(j));
	for (int i = 2; i <= n+1; ++i) {
		x += a;
		j *= (4*i*i+2*i);
		a *= (x * x) /j;
		std::cout << j << std::endl;
	}
	std::cout << "sin(x)="<< x << std::endl;
}

