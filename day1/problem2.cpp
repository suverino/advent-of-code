#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

struct Timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took " << ms << "ms" << std::endl;
	}
};

class Window {
	public:
		Window() {
			measure_ = 0;
			count_ = 0;
		}

		void addToMeasure(int value) {
			measure_ += value;
			incCount();
		}

		void copy(Window& other) {
			measure_ = other.measure_;
			count_ = other.count_;
		}

		void reset() {
			measure_ = 0;
			count_ = 0;
		}

		void print() {
			std::cout << "measure: " << measure_ << std::endl;
			std::cout << "count: " << count_ << std::endl;
		}

		int getMeasure() {
			return measure_;
		}

		int getCount() {
			return count_;
		}

		bool operator>(Window& other) {
			if (measure_ > other.measure_) {
				return true;
			}
			return false;
		}
		
	private:
		int measure_;
		int count_;

		void incCount() {
			count_++;
		}
};

int main() {
	Timer timer;
	int sol = 0;
	int current;
	Window prevWindow;
	Window currWindow;
	Window nextWindow;

	std::ifstream myFile;
	myFile.open("day1/input.txt");
	if (myFile.is_open()) {
		myFile >> current;
		prevWindow.addToMeasure(current);
		myFile >> current;
		prevWindow.addToMeasure(current);
		currWindow.addToMeasure(current);
		myFile >> current;
		prevWindow.addToMeasure(current);
		currWindow.addToMeasure(current);
		nextWindow.addToMeasure(current);
		myFile >> current;
		while (myFile) {
			currWindow.addToMeasure(current);
			nextWindow.addToMeasure(current);
			if(currWindow > prevWindow) {
				sol++;
			}
			prevWindow.copy(currWindow);
			currWindow.copy(nextWindow);
			nextWindow.reset();
			nextWindow.addToMeasure(current);
			myFile >> current;
		}
	}
	std::cout << "sol: " << sol << std::endl;
	myFile.close();
}
