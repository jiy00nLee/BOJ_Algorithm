#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define MAX 128	

int N;
int board[MAX][MAX];
int answer[2];
//üũ�ϴ� �Լ�
bool checkFunction(int x, int y, int size) {
	int value = board[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (board[i][j] != value) return false;
		}
	}
	return true;
}

//������ �Լ�
void divideFunction(int x, int y, int size) {
	
	//1�ΰ�쿡�� �����Ų��
	if (size == 1) {
		answer[board[y][x]]++;
		return;
	}
	//üũ�ؼ� ��� ���ٸ� �׳� ���� ��Ű��
	if (checkFunction(x, y, size)) {
		answer[board[y][x]]++;
		return;
	}
	//�ٸ���쿡�� ���� ������.
	else {
		int nSize = size / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				int sx = x +(nSize*j);
				int sy = y + (nSize*i);
				divideFunction(sx, sy, nSize);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	divideFunction(0, 0, N);
	cout << answer[0] << '\n';
	cout << answer[1] << '\n';

	return 0;
}