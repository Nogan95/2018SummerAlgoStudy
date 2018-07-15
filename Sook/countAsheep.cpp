#include <iostream>
#include <cstring>

using namespace std;
unsigned int N;
int cS[1000000];
int countT = 1;
int sheep[10];
int countS = 0;			//10개가 전부 나왔는지.
int c = 2;
int j = 1;

int countSheep(unsigned int Num) {		//10까지만 하면 될듯?
	unsigned int Copy;
	Copy = Num;
	int oneN;
	if (j != 101) {
		j++;
	}
	else {
		return -1;
	}

	if (Num == 0) {
		return -1;
	}

	while (Copy != 0)
	{
		oneN = Copy % 10;
		if (sheep[oneN] == -1) {
			sheep[oneN] = oneN;
			countS++;
		}
		Copy /= 10;
	}

	if (countS == 10) {
		return Num;
	}
	else {
		countSheep(j*N);
		/*
		if (c == 2) {
			for (j; j < 100; j++) {
				c = 1;
				countSheep(j * Num);
			}
			if (countS != 10) {
				return -1;
			}
		}
		*/
	}
}

char* printOut(unsigned int Num) {
	char* out = "";
	unsigned int solve;
	
	solve = countSheep(Num);

	if (solve == -1) {
		cout << "Case #" << countT << ": INSOMNIA" << endl;
	}
	else {
		cout << "Case #" << countT << ": " << solve << endl;
	}

	countT++;
	return out;
}
int main() {
	unsigned int T;
	
	
	cin >> T;
	if (T < 1 || T > 100) {
		return -1;
	}

	for (unsigned int i = 0; i < T; T++) {
		cin >> N;								//
		memset(cS, -1, sizeof(cS));
		memset(sheep, -1, sizeof(sheep));
		printOut(N);
	}
	return 0;
}