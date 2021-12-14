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

struct Position {
	int x;
	int y;
	int aim;

	Position() {
		x = 0;
		y = 0;
		aim = 0;
	}

};

int main() {
	Timer timer;
	Position pos;
	std::string dir;
	int dist;
	std::ifstream myFile;
	myFile.open("day2/input.txt");
	if (myFile.is_open()) {
		myFile >> dir;
		myFile >> dist;
		while (myFile) {
			if (dir == "forward") {
					pos.x += dist;
					pos.y += dist * pos.aim;
			}
			if (dir == "up") {
					pos.aim -= dist;
			}
			if (dir == "down") {
					pos.aim += dist;
			}
			myFile >> dir;
			myFile >> dist;
		}
	}
	std::cout << "X: " << pos.x << std::endl;
	std::cout << "Y: " << pos.y << std::endl;
	std::cout << "Final: " << pos.x * pos.y << std::endl;
	myFile.close();
}
