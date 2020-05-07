#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 33
int N;
int board[MAX][MAX];
long long dp[3][MAX][MAX];	//0 ���� //1 ���� // 2 �밢��


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
	dp[0][0][1] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//���η� �̵��ϴ� ��� ���� ��ǥ���� ���� �밢���� 0�� �ƴϿ��ߵȴ�.
			if (board[i][j + 1] == 0&&(dp[0][i][j]!=0||dp[2][i][j]!=0)) {
				dp[0][i][j + 1] += (dp[0][i][j] + dp[2][i][j]);
			}
			//���η� �̵��ϴ� ���
			if (board[i + 1][j] == 0&&(dp[1][i][j]!=0||dp[2][i][j]!=0)) {
				dp[1][i+1][j] += (dp[1][i][j] + dp[2][i][j]);
			}
			//�밢������ �̵��ϴ� ���
			if ((board[i + 1][j + 1] == 0&&board[i+1][j]==0&&board[i][j+1]==0 )&& (dp[0][i][j] != 0 ||dp[1][i][j]!=0|| dp[2][i][j] != 0)) {
				dp[2][i + 1][j+1] += (dp[0][i][j]+dp[1][i][j] + dp[2][i][j]);
			}
		}
	}

	cout << dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1] << '\n';
	
	return 0;
}