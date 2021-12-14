#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>

struct Timer {
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	Timer() {
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took " << ms << "ms" << std::endl;
	}
};

int main() {
	Timer timer;
	std::ifstream myFile;
	myFile.open("day3/input.txt");
	if (myFile.is_open()) {
		while (myFile) {
		}
	}
	myFile.close();
}
