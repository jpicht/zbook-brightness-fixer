#include <iostream>
#include <fstream>
#include <sstream>

namespace brightness {
	int get();
	int max();
	void set(int);
	void reset();
}

void syntax();
void set(char*);

int main(int argc, char** argv) noexcept {
	switch (argc) {
		case 1:
			std::cout << brightness::get() << std::endl;
		break;
		case 2:
			set(argv[1]);
		break;
		default:
			syntax();
		break;
	}
	return 0;
}

void set(char* value) {
	std::string valueStr(value);
	if (valueStr.compare("reset") == 0) {
		brightness::reset();
		return;
	} else if ( valueStr.compare("max") == 0 ) {
		brightness::set(brightness::max());
		return;
	}

	std::stringstream converter;
	converter << value;
	int arg_value;
	converter >> arg_value;

	converter << arg_value;
	std::string tester = converter.str();

	if (tester.compare(value) != 0) {
		exit(2);
		return;
	}

	brightness::set(arg_value);
}

void syntax() {}

namespace brightness {
	const std::string brightnessFileName = "/sys/class/backlight/intel_backlight/brightness";
	const std::string maxBrightnessFileName = "/sys/class/backlight/intel_backlight/max_brightness";

	int get() {
		std::ifstream bf(brightnessFileName);
		int current;
	       	bf >> current;
		bf.close();
		return current;
	}

	int max() {
		std::ifstream bf(maxBrightnessFileName);
		int current;
	       	bf >> current;
		bf.close();
		return current;
	}

	void reset() {
		int current = get();
		set(0);
		set(current);
	}

	void set(int newValue) {
		std::ofstream bf(brightnessFileName);
		if (!bf.is_open()) {
			std::cerr << "cannot open '" << brightnessFileName << "' for writing." << std::endl;
			exit(1);
			return;
		}
		bf << newValue;
		bf.close();
	}
};
