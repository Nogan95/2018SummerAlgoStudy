// Project2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include <iostream>

using namespace std;

int C, n, m, f1, f2;
bool fr[10][10];							//친구 관계를 나타내는 2차원 배열

int count(bool student[10]) {
	int countN = 0, flag = -1;
	for (int i = 0; i < n; i++) {
		if (!student[i]) {					//짝이없다면
			flag = i;
			break;
		}
	}
	if (flag == -1)							//짝이 있다면
		return 1;
	for (int i = flag + 1; i < n; i++) {
		if (!student[i] && fr[flag][i]) {	//짝이없고 & 친구일 경우
			student[flag] = true;
			student[i] = true;
			countN += count(student);		//재귀
			student[flag] = false;
			student[i] = false;
		}
	}
	/*
	cout << endl << countN << endl;
	*/
	return countN;
}

int main()
{
	int countN = 0;
	bool flag = true;
	bool stu[10];								//짝이 되었는지 나타내는 배열
	cin >> C;									//몇가지 테스트케이스인지 C

	for (int i = 0; i < C; i++) {				//테케 i번째
		cin >> n >> m;							//학생 수 n과 친구의경우 m을 C for문만큼

		for (int h = 0; h < 10; h++) {			//2차원 배열 초기화
			for (int j = 0; j < 10; j++)
				fr[h][j] = false;
			stu[h] = false;						//stu 배열 초기화
		}

		for (int j = 0; j < m; j++) {			//2차원 배열 값 삽입
			cin >> f1 >> f2;
			fr[f1][f2] = true;					//2차원 배열에 친구 쌍 넣기까지 m for문 만큼
			fr[f2][f1] = true;
		}
		/*
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		for (int x = 0; x < n; x++) {
			for (int j = 0; j < n; j++) {
				cout << fr[x][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
		*/
		countN = count(stu);
		cout << countN << endl;

		/*
		for (int j = 0; j < n; j++) {			//count확인 및 출력


		for (int k = j + 1; k < n; k++) {
		if (fr[j][k] == false)							//친구가 아니면 패스.
		continue;
		if (stu[j] == true || stu[k] == true)			//이미 짝있으면 패스.
		continue;
		stu[j] = true;
		stu[k] = true;
		}

		for (int a = 0; a < n; a++) {		//count 올리기.
		flag = true;
		for (int b = a; b < n; b++) {
		if (stu[b] == false) {
		flag = false;
		break;
		}
		}
		if (flag) {
		count++;
		for (int c = 0; c < n; c++)
		cout << stu[c] << "  ";
		cout << endl;
		}
		}
		}
		*/

	}


	return 0;
}