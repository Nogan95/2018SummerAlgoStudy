#include <iostream>
#include <assert.h>

using namespace std;

bool relation[10][10];

int nC_2(const int n) {
	return n * (n - 1) * 0.5;
}

int factorial(int n) {
	int result = 1;
	while (n > 0) {
		result *= n;
		n--;
	}
	return result;
}

int picnic(bool taken[10], int N) {
	int firstFree = -1;
	for (int i = 0; i < N; ++i)
		if (!taken[i]) {
			firstFree = i;
			break;
		}

	if (firstFree == -1) {
		return 1;
	}
	int result = 0;

	for (int partner = firstFree + 1; partner < N; ++partner)
		if (!taken[partner] && relation[firstFree][partner]) {
			taken[firstFree] = taken[partner] = true;
			result += picnic(taken, N);
			taken[firstFree] = taken[partner] = false;
		}

	return result;
}

int main() {
	int C = 0, N = 0, M = 0, first = 0, second = 0;

	cin >> C;
	assert(C > 0 && C <= 50);

	while (C > 0) {
		C--;
		bool member[10] = { false };
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				relation[i][j] = false;

		cin >> N >> M;
		assert(N > 1 && N <= 10);
		assert(M >= 0 && M <= N * (N - 1) * 0.5);

		for (int i = 0; i < M; i++) {
			cin >> first >> second;
			relation[first][second] = true;
			relation[second][first] = true;
		}

		if (M == 0 || N % 2 != 0) {
			cout << 0 << endl; // 쌍이 0이거나 사람이 홀수면 쌍을 이룰 수 없음
			continue;
		}

		if (M == N * (N - 1) / 2) {		// 모든 경우 짝이라면 공식으로 계산
			int residue = N;
			int result = 1;
			while (residue > 0) {
				result *= nC_2(residue);
				residue -= 2;
			}
			cout << result / factorial(N * 0.5) << endl;
			continue;
		}

		cout << picnic(member, N) << endl;
	}

	return 0;
}