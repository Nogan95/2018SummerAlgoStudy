#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

bool digits[10];
string number;

bool isFinished() {
	int firstFalseIndex = -1;
	for (int i = 0; i < 10; i++)
		if (digits[i] == false) {
			firstFalseIndex = i;
			break;
		}

	return (firstFalseIndex == -1);
}

string counting_sheep(int current_mult) {
	string temp = number;
	temp = to_string(current_mult * atoll(number.c_str()));
	for (int i = 0; i < temp.length(); i++) {
		int index = temp[i] - '0';
		digits[index] = true;
	}
	
	if (isFinished()) return temp;
	
	return counting_sheep(current_mult + 1);
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("large_input.txt");
	fout.open("large_output.txt");

	int T = 0, count = 0;

	fin >> T;
	while (T > 0) {
		T--;
		number = "";
		fin >> number;

		for (int i = 0; i < 10; i++)
			digits[i] = false;

		if (atoi(number.c_str()) == 2 * atoi(number.c_str())) {
			fout << "Case #" << ++count << ": " << "INSOMNIA" << endl;
			continue;
		}

		fout << "Case #" << ++count << ": " << counting_sheep(1) << endl;
	}

	fin.close();

	return 0;
}