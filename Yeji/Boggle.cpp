#include <iostream>
#include <string>
#include <assert.h>
#define FOR(i, n) for(int i = 0; i < n; ++i)

char board[5][5];
const int dx[8] = { -1,-1,-1,0,0,1,1,1 };
const int dy[8] = { -1,0,1,-1,1,-1,0,1 };

using namespace std;

bool inRange(int y, int x) {
	return (0 <= x && x < 5 && 0 <= y && y < 5);
}

bool hasWord(int y, int x, const string& word) {
	if (!inRange(y, x)) return false;
	if (board[y][x] != word[0]) return false;
	if (word.length() == 1) return true;

	FOR(i, 8) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (hasWord(nextY, nextX, word.substr(1))) return true;
	}

	return false;
}

void print(const string& line) {
	FOR(k, line.length()) {
		bool flag = false;
		FOR(i, 5) {
			FOR(j, 5) {
				if (board[i][j] == line[k]) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) {
			cout << line << " NO" << endl;
			return;
		}
	}

	FOR(i, 5) {
		FOR(j, 5) {
			if (board[i][j] == line[0])
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
		FOR(j, 5) {
			getline(cin, line);
			FOR(k, 5)
				board[j][k] = line[k];
		}

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