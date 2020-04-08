#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int board[42][42];
int sticker[101][4][11][11];
int N, M, K;

//90�� ȸ�� ��ƼĿ�� ���Ѵ�.
void rotate(int y,int x,int index,int deg) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			sticker[index][deg][i][j] = sticker[index][deg - 1][x - j - 1][i];
		}
	}
}
//��ƼĿ�� ���ϼ� �ִ��� üũ�Ѵ�.
bool attachCheck(int y, int x, int rt, int st,int r,int c) {
	for (int i = y,ti=0; i < y+r; i++,ti++) {
		for (int j = x,tj=0; j < x+c; j++,tj++) {
			if (board[i][j] == 1 && sticker[st][rt][ti][tj] == 1) return false;
		}
	}
	return true;
}
//��ƼĿ�� ���δ�.
void attach(int y, int x, int rt, int st,int r,int c) {
	for (int i = y,ti=0; i < y + r; i++,ti++) {
		for (int j = x,tj=0; j < x + c; j++,tj++) {
			if (board[i][j] == 0 && sticker[st][rt][ti][tj] == 1) board[i][j] = 1;
		}
	}
}
int solve() {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) answer++;
		}
	}
	return answer;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int st = 0; st < K; st++) {
		int r, c;
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[st][0][i][j];
			}
		}

		for (int i = 1; i < 4; i++) {
			swap(r, c);
			rotate(r,c,st,i);
		}


		bool pass = true;
		
		for (int rt = 0; pass&&rt < 4; rt++) {
			swap(r, c);
			//��ƼĿ�� �ٿ�����.
			for (int i = 0; pass&&i < N; i++) {
				for (int j = 0; pass&&j < M; j++) {
					//������ �ʰ��ϴ��� üũ �Ѵ�.
					if ((N - i) < r || (M - j) < c) continue;

					//���� ��ǥ�� ��ƼĿ�� ���� �� �ִ��� Ȯ��
					if (attachCheck(i, j, rt, st, r, c) == true) {
						attach(i, j, rt, st, r, c);
						pass = false;
						break;
					}
				}
			}
		}
	}

	cout << solve() << '\n';

	return 0;
}