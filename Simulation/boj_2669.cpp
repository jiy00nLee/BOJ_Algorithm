/*
�Է��� �� ���̸�, �� ���� ���簢���� ��ġ�� ��Ÿ���� �� ���� ������ �־�����. ù ��°�� �� ��°�� ������ �簢���� ���� �Ʒ� �������� x��ǥ, y��ǥ�̰� �� ��°�� �� ��°�� ������ �簢���� ������ �� �������� x��ǥ, y��ǥ�̴�. ��� x��ǥ�� y��ǥ�� 1�̻��̰� 100������ �����̴�.
1 2 4 4   x1 y1 x2 y2
2 3 5 7
3 1 6 5
7 3 8 6
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 102
bool board[MAX][MAX];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int answer = 0;
	for (int t = 0;t < 4;t++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1;i < y2;i++) {
			for (int j = x1;j < x2;j++) {
				if (!board[i][j]) {
					answer++;
					board[i][j] = true;
				}
			}
		}
	}
	cout << answer << '\n';
	
	

	return 0;
}