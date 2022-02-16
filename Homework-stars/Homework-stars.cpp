#include <iostream>

void ex1();
void ex2();
void ex3();
void ex4();

int main()
{
	ex1();
	ex2();
	ex3();
	ex4();
}

void ex1() {
	int n;
	std::cout << "Input n:";
	do {
		std::cin >> n;
	} while (n < 0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void ex2() {
	int n;
	std::cout << "Input n:";
	do {
		std::cin >> n;
	} while (n < 0);

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n + 1 - i; ++j) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void ex3() {
	int n;
	std::cout << "Input n:";
	do {
		std::cin >> n;
	} while (n < 0);

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			std::cout << " ";
		}
		for (int k = 1; k <= i; ++k) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void ex4() {
	int n;
	std::cout << "Input n:";
	do {
		std::cin >> n;
	} while (n < 0);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			std::cout << " ";
		}
		for (int k = 0; k < (i + 1) * 2 - 1; ++k) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < i + 2; ++j) {
			std::cout << " ";
		}
		for (int k = 0; k < (2 * n - 1) - 2 * (i + 1); ++k) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}
