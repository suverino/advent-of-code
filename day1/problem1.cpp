#include <iostream>
#include <fstream>

int main() {
	int sol = 0;
	int current;
	int prev;
	std::ifstream myFile;
	myFile.open("day1/input.txt");
	if (myFile.is_open()) {
		myFile >> prev;
		while (myFile) {
			myFile >> current;
			if (current > prev) sol++;
			prev = current;
		}
	}
	std::cout << "sol: " << sol << std::endl;
	myFile.close();
}
