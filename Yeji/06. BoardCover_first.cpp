//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//int W, H;
//
//// 1: ㄱ, 2: ㄴ, 3: ┘, 4: ┌
//int cover(vector<vector<char>> temp, int y, int x, int type) {
//	int ret = 0;
//
//	switch (type)
//	{
//	case 1:
//		if (x == W - 1) return 0;
//		if (temp[y][x + 1] == '.' && temp[y + 1][x + 1] == '.') {
//			temp[y][x] = temp[y][x + 1] = temp[y + 1][x + 1] = '#';
//		}
//		else return 0;
//		break;
//	case 2:
//		if (x == W - 1) return 0;
//		if (temp[y + 1][x] == '.' && temp[y + 1][x + 1] == '.') {
//			temp[y][x] = temp[y + 1][x] = temp[y + 1][x + 1] = '#';
//		}
//		else return 0;
//		break;
//	case 3:
//		if (x == 0) return 0;
//		if (temp[y + 1][x] == '.' && temp[y + 1][x - 1] == '.') {
//			temp[y][x] = temp[y + 1][x] = temp[y + 1][x - 1] = '#';
//		}
//		else return 0;
//		break;
//	case 4:
//		if (x == W - 1) return 0;
//		if (temp[y][x + 1] == '.' && temp[y + 1][x] == '.') {
//			temp[y][x] = temp[y][x + 1] = temp[y + 1][x] = '#';
//		}
//		else return 0;
//		break;
//	default: break;
//	}
//
//	while (temp[y][x] == '#') {
//		if (x != W - 1)
//			x++;
//		else {
//			y++; x = 0;
//			if (y == H) return 1;	// 모든 칸이 채워져 있음.
//		}
//	}
//	if (y == H - 1) return 0;	// 마지막 열에 빈 칸이 있음.
//
//	for (int i = 0; i < 4; i++)
//		ret += cover(temp, y, x, i + 1);
//
//	return ret;
//}
//
//int main() {
//	int C = 0;
//	vector<vector<char>> board;
//	cin >> C;
//
//	while (C > 0) {
//		C--;
//
//		// initialization
//		H = W = 0;
//		board.clear();
//
//		cin >> H >> W;
//
//		for (int i = 0; i < H; i++) {
//			vector<char> line;
//			char ch;
//			for (int j = 0; j < W; j++) {
//				cin >> ch;
//				line.push_back(ch);
//			}
//			board.push_back(line);
//		}
//
//		int dot_count = 0;
//		for (int i = 0; i < H; i++)
//			for (int j = 0; j < W; j++)
//				if (board[i][j] == '.')
//					dot_count++;
//
//		if (dot_count % 3 != 0 || dot_count == 0)
//			cout << 0 << endl;
//		else
//			cout << cover(board, 0, 0, 0) << endl;
//	}
//
//	return 0;
//}