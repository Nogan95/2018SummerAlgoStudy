#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<char>> board;
int W, H;

void roll_back(int y, int x, int type) {
	switch (type)
	{
	case 1:
		board[y][x] = board[y][x + 1] = board[y + 1][x + 1] = '.'; break;
	case 2:
		board[y][x] = board[y + 1][x] = board[y + 1][x + 1] = '.'; break;
	case 3:
		board[y][x] = board[y + 1][x] = board[y + 1][x - 1] = '.'; break;
	case 4:
		board[y][x] = board[y][x + 1] = board[y + 1][x] = '.'; break;
	default:
		break;
	}
}

bool cover(int y, int x, int type) {
	switch (type)
	{
	case 1:
		if (x == W - 1) return false;
		if (board[y][x + 1] == '.' && board[y + 1][x + 1] == '.') {
			board[y][x] = board[y][x + 1] = board[y + 1][x + 1] = '#';
			return true;
		}
		break;
	case 2:
		if (x == W - 1) return false;
		if (board[y + 1][x] == '.' && board[y + 1][x + 1] == '.') {
			board[y][x] = board[y + 1][x] = board[y + 1][x + 1] = '#';
			return true;
		}
		break;
	case 3:
		if (x == 0) return false;
		if (board[y + 1][x] == '.' && board[y + 1][x - 1] == '.') {
			board[y][x] = board[y + 1][x] = board[y + 1][x - 1] = '#';
			return true;
		}
		break;
	case 4:
		if (x == W - 1) return false;
		if (board[y][x + 1] == '.' && board[y + 1][x] == '.') {
			board[y][x] = board[y][x + 1] = board[y + 1][x] = '#';
			return true;
		}
		break;
	default: break;
	}

	return false;
}

// 1: ㄱ, 2: ㄴ, 3: ┘, 4: ┌
int boardCover() {
	int y = -1, x = -1;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			if (board[i][j] == '.') {
				y = i; x = j; break;
			}
		if (y != -1) break;
	}

	if (y == -1) return 1;		// 모든 칸이 채워져 있음.
	if (y == H - 1) return 0;	// 마지막 열에 빈 칸이 있음.

	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (cover(y, x, i + 1)) {
			ret += boardCover();
			roll_back(y, x, i + 1);
		}
	}

	return ret;
}

int main() {
	int C = 0;
	cin >> C;

	while (C > 0) {
		C--;

		// initialization
		H = W = 0;
		board.clear();

		cin >> H >> W;

		for (int i = 0; i < H; i++) {
			vector<char> line;
			char ch;
			for (int j = 0; j < W; j++) {
				cin >> ch;
				line.push_back(ch);
			}
			board.push_back(line);
		}

		int dot_count = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (board[i][j] == '.')
					dot_count++;

		if (dot_count % 3 != 0 || dot_count == 0)
			cout << 0 << endl;
		else
			cout << boardCover() << endl;
	}

	return 0;
}