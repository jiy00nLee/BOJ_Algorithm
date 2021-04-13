#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
#define MAX 17
/*
5 5 1
1 1 1 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/
int board[MAX][MAX];
int N, M, D;

bool archers[MAX];
int answer;


void print() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << ' ';
		}cout << '\n';
	}
}

//�Ʒ��� �̵���Ű�� �Լ�
void downMove() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) {
				int next_y = i + 1;
				if (board[next_y][j] == 2) {
					board[i][j] = 0;
				}
				else {
					board[i][j] = 0;
					board[next_y][j] = 1;
				}
			}
		}
	}
}

//���� ���� �Լ�
int gameStart() {
	int tmpBoard[MAX][MAX];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			tmpBoard[i][j] = board[i][j];
		}
	}
	int kill = 0;
	int archersPos[3];
	int index = 0;
	for (int i = 0; i < 3; i++) archersPos[i] = -1;
	//�ü� ��ǥ �����ϰ�
	for (int i = 0; i < M; i++) {
		if (archers[i] == true) {
			archersPos[index] = i;
			index++;
		}
	}
	bool usedArchers[3];
	vector<pair<int,pair<int,pair<int,int>>>> deletePos;	//�Ÿ�, ��ó�ε���, x,y
	//���� ���ؾߵǴµ� N����ŭ�� �����
	for(int turn = 0; turn < N ; turn++){
		for (int i = 0; i < 3; i++) usedArchers[i] = false;
		deletePos.clear();
		//���� ��������.
		for (int y = N-1; y >= (N-1) - D; y--) {
			for (int x = 0; x < M; x++) {
				if (board[y][x] == 1) {//�� �߰��߾�
					//�ü����� ��ǥ������ ��
					int ay = N;
					for (int a = 0; a < 3; a++) {
						int ax = archersPos[a];
						int dist = (abs(y - ay) + abs(x - ax));
						//�� �ִ°ɷ�?
						if (dist <= D) {
							deletePos.push_back({ dist,{a,{x,y}}});
						}
					}
				}
			}
		}
		sort(deletePos.begin(), deletePos.end());
		//���� �����Ѵ�.
		int cnt = 0;
		for (int i = 0; i < deletePos.size(); i++) {
			if (!usedArchers[deletePos[i].second.first]) {
				usedArchers[deletePos[i].second.first] = true;
				int dx = deletePos[i].second.second.first;
				int dy = deletePos[i].second.second.second;
				if (board[dy][dx] == 1) kill++;
				board[dy][dx] = 0;
				cnt++;
				if (cnt == 3) break;
			}
		}
		//�� �̵�
		downMove();
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = tmpBoard[i][j];
		}
	}
	
	return kill;
}
//�ü� �ڸ� ����
void dfs(int x, int cnt) {
	if (cnt == 3) {
		//�ü� 3���� ����������
		//���ӽ���
		answer = max(answer,gameStart());
		return;
	}
	if (x == M) return;
	//���� ��ǥ ����
	archers[x] = true;
	dfs(x + 1, cnt + 1);
	archers[x] = false;
	
	//���� ��ǥ �뼱��
	dfs(x + 1, cnt);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		board[N][i] = 2;
	}
	
	//dfs�� �ü� �ڸ��� ��������
	dfs(0, 0);
	cout << answer << '\n';
	return 0;
}