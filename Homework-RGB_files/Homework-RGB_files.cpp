#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}
	if (argc > 3) {
		std::ifstream red;
		red.open(argv[1], std::ios_base::binary);
		std::ifstream green;
		green.open(argv[2], std::ios_base::binary);
		std::ifstream blue;
		blue.open(argv[3], std::ios_base::binary);
		int px = 0, buffer = 0;
		if (red.is_open()) {
			red.seekg(10);
			red.read((char*)&px, sizeof(int));
			px += 3;
			red.seekg(px);
			std::cout << "Full red: ";
			for (int i = 0; i < 3; ++i) {
				red.read((char*)&buffer, sizeof(char));
				std::cout << buffer << " ";
			}
			red.close();
		}
		else {
			std::cout << "Can't open file" << std::endl;
		}
		std::cout << std::endl;

		if (green.is_open()) {
			green.seekg(10);
			green.read((char*)&px, sizeof(int));
			px += 3;
			green.seekg(px);
			std::cout << "Full green: ";
			for (int i = 0; i < 3; ++i) {
				green.read((char*)&buffer, sizeof(char));
				std::cout << buffer << " ";
			}
			green.close();
		}
		else {
			std::cout << "Can't open file" << std::endl;
		}
		std::cout << std::endl;

		if (blue.is_open()) {
			blue.seekg(10);
			blue.read((char*)&px, sizeof(int));
			px += 3;
			blue.seekg(px);
			std::cout << "Full blue: ";
			for (int i = 0; i < 3; ++i) {
				blue.read((char*)&buffer, sizeof(char));
				std::cout << buffer << " ";
			}
			blue.close();
		}
		else {
			std::cout << "Can't open file" << std::endl;
		}
	}
	return 0;
}