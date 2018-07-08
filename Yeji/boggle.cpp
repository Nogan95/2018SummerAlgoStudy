#include <iostream>
#include <string>
#include <assert.h>
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

char board[5][5] = 
{ {'A','B','C','D','E'},
{'F','G','H','I','J'},
{'K','L','M','N','O'},
{'P','Q','R','S','T'},
{'U','V','W','X','Y'} };

bool hasWord(int y, int x, string word) {
	if (board[y][x] != word[0]) return false;
	if (word.length() == 1) return true;

	for (int i = 1; i < word.length(); ++i) {
		// (y, x)
	}
}

void print(string line) {
	FOR(i, 5) {
		FOR(j, 5) {
			if (hasWord(i, j, line)) {
				cout << line << " YES" << endl;
				return;
			}
		}
	}

	cout << line << " NO" << endl;
}

int main() {
	int C = 0, N = 0;
	string line;
	cin >> C;
	assert(C > 0 && C <= 50);
	cin.ignore(10, '\n');

	FOR(i, C) {
		/*FOR(j, 5) {
			getline(cin, line);
			FOR(k, 5)
				board[j][k] = line[k];
		}*/

		cin >> N;
		assert(N > 0 && N <= 10);

		cin.ignore(10, '\n');

		FOR(j, N) {
			getline(cin, line);
			print(line);
		}
	}

	return 0;
}
