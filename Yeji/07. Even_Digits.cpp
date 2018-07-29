#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define CASE1 1
#define CASE2 2

bool isAllEvenDigits(long long number) {
	string temp = to_string(number);
	for (long long i = 0; i < temp.length(); i++)
		if ((temp[i] - '0') % 2 == 1)		// 하나라도 홀수
			return false;

	return true;
}

long long buttonPush(const long long number) {
	string temp = to_string(number);
	string result = to_string(number);
	int last_index = temp.length() - 1;

	for (int i = 0; i < temp.length(); i++) {
		short first_odd_digit = temp[i] - '0';
		if (first_odd_digit % 2 == 1) {
			if (i != last_index) {
				short next_digit = temp[i + 1] - '0';
				short flag = CASE1;
				if (first_odd_digit != 9) {
					string remain = temp.substr(i + 1);
					for (int j = 0; j < remain.length(); j++) {
						if (remain[j] - '0' < 4) {
							flag = CASE2;
							break;
						}
						else if (remain[j] - '0' > 4) {
							flag = CASE1;
							break;
						}
					}
				}
				else 
					flag = CASE2;

				if (flag == CASE1) {
					result[i] = (first_odd_digit + 1) + '0';
					for (int j = i + 1; j < temp.length(); j++)
						result[j] = 0 + '0';
				}

				else if (flag == CASE2) {
					result[i] = (first_odd_digit - 1) + '0';
					for (int j = i + 1; j < temp.length(); j++)
						result[j] = 8 + '0';
				}

				return llabs(atoll(result.c_str()) - number);
			}
			else
				return 1;	// 홀수가 마지막 한 자리 밖에 없다면 '-'를 한 번 누르면 됨.
		}
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("large_input.txt");
	fout.open("large_output.txt");

	int T = 0, count = 0;
	fin >> T;

	while (T > 0) {
		T--; ++count;
		long long N = 0;
		fin >> N;

		if (isAllEvenDigits(N))
			fout << "Case #" << count << ": " << 0 << endl;
		else
			fout << "Case #" << count << ": " << buttonPush(N) << endl;
	}

	return 0;
}