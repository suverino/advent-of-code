#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <bitset>

#define NUMBITS 5

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
	std::string cursor;
	unsigned long sol = 0;
	myFile.open("day3/input.txt");
	if (myFile.is_open()) {
		myFile >> cursor;
		int size = cursor.size();
		std::vector<int> common;
		std::vector<std::string> list;
		for (int i = 0; i < size; i++) {
			common.push_back(0);
		}
		while (myFile) {
			int i = 0;
			for (char& c : cursor) {
				if (c == 48) {
					common[i]--;
				} else {
					common[i]++;
				}
				i++;
			}
			myFile >> cursor;
		}
		std::string gamma = "";
		std::string epsilon = "";
		for (int i = 0; i < size; i++) {
			if (common[i] > 0) {
				gamma += "1";
				epsilon += "0";
			} else {
				gamma += "0";
				epsilon += "1";
			}
		}
		sol = std::bitset<NUMBITS>(gamma).to_ulong() * std::bitset<NUMBITS>(epsilon).to_ulong();
		std::cout << "sol: " << sol << std::endl;
	}
	myFile.close();
}
