#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
#define MAX 102
int R, C,M;
typedef pair<int,pair<int,pair<int, pair<int, int> > > > piiiii;	//r �� c �� s �ӷ� d �̵����� z ũ��
vector<piiiii>shakes; // r ,c , s ,d ,z  �� �� �ӷ� ���� ũ�� ��� ������
int shakes_board[MAX][MAX]; //�ʿ� �� �ִ��� ��� ũ��� ǥ��
int m_xy[5][2] = { {0,0},{0,-1},{0,1},{1,0},{-1,0} };
int ans = 0;

void print() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << shakes_board[i][j] << ' ';
		}cout << '\n';
	}
}

bool range_check(int x, int y) {
	if (x >= 1 && x <= C && y >= 1 && y <= R)	return true;
	else return false;
}

void bfs() {
	queue<piiiii>q;
	//����� ���� �ְ�  �״��� �� �ִ´�.
	q.push(make_pair(0, make_pair(0, make_pair(-1, make_pair(3, 0)))));
	for (int i = 0; i < shakes.size(); i++) {
		int r = shakes[i].first;
		int c = shakes[i].second.first;
		int s = shakes[i].second.second.first;
		int d = shakes[i].second.second.second.first;
		int z = shakes[i].second.second.second.second;
		q.push(make_pair(r, make_pair(c, make_pair(s, make_pair(d, z)))));
	}
	int time = 1;
	vector<piiiii>new_shakes;
	while (!q.empty()) {
		//��� �������
		int c_r = q.front().first;
		int c_c = q.front().second.first;
		int c_s = q.front().second.second.first;
		int c_d = q.front().second.second.second.first;
		int c_z = q.front().second.second.second.second;
		//cout << c_r << ' ' << c_c << ' ' << c_s << ' ' << c_d << ' ' << c_z << '\n';
		q.pop();
		
		//����̸� ���� ���� ��ĭ �̵� ��� ��� 
		if (c_s == -1) {
			//�� ���Ӱ� �����ϰ� 
			for (int i = 0; i < new_shakes.size(); i++) {
				int t_r = new_shakes[i].first;
				int t_c = new_shakes[i].second.first;
				int t_s = new_shakes[i].second.second.first;
				int t_d = new_shakes[i].second.second.second.first;
				int t_z = new_shakes[i].second.second.second.second;

				//��� �����Ҷ� �� �����ϸ� ũ�� ���ؼ� ������ ���� �Ǵ�
				if (shakes_board[t_r][t_c] != 0) { //�浹 �߻�
					if (shakes_board[t_r][t_c] < t_z) {
						shakes_board[t_r][t_c] = t_z;
						q.push(make_pair(t_r, make_pair(t_c, make_pair(t_s, make_pair(t_d, t_z)))));
					}
				}
				else { //���浹
					shakes_board[t_r][t_c] = t_z;
					q.push(make_pair(t_r, make_pair(t_c, make_pair(t_s, make_pair(t_d, t_z)))));
				}
			}
			//cout << "-======================�� \n";
			//print();
			//cout << "-======================�� \n";

			new_shakes.clear();
			//����϶����� ī��Ʈ�ؼ� ���� �����ߴ��� üũ�Ѵ�.

			c_c += 1;
			if (c_c > C) {	//���� ��Ű�� ���ǹ�

				return;
			}
			//������ ��ĭ �̵� �� �� ���� �� �ִ��� üũ�Ѵ�.
			//�� �ִٸ� ���� ������ ���ش�.
			for (int y = 1; y <= R; y++) {
				if (shakes_board[y][c_c]!=0) {
					ans += shakes_board[y][c_c];
					shakes_board[y][c_c] = 0;
					break;
				}
			}
			
			q.push(make_pair(c_r, make_pair(c_c, make_pair(c_s, make_pair(c_d, c_z)))));
		}

		//���� �̵���Ų��
		if (shakes_board[c_r][c_c]==c_z&&c_s!=-1) {	//�Ⱦ������� �����Ѵٸ� ���� ��ǥ �̵� ��Ų��.
			shakes_board[c_r][c_c] = 0;
			//cout << c_r << ' ' << c_c << '\n';
			//��� �̵���Ű�� �Ǵµ� ���������� ���� �ε����� �ݴ�������� �̵��ؾߵ�
			for (int i = 0; i < c_s; i++) {
				int n_r = c_r + m_xy[c_d][1];
				int n_c = c_c + m_xy[c_d][0];
				if (range_check(n_c, n_r)) {//���� ���̶��
					c_r = n_r;
					c_c = n_c;
				}
				else {//���� ���̶��
					switch (c_d) {
					case 1:
						c_d = 2;
						break;
					case 2:
						c_d = 1;
						break;
					case 3:
						c_d = 4;
						break;
					case 4:
						c_d = 3;
						break;
					}

					c_r =c_r+ m_xy[c_d][1];
					c_c =c_c+ m_xy[c_d][0];
				}
			}
			new_shakes.push_back(make_pair(c_r, make_pair(c_c, make_pair(c_s, make_pair(c_d, c_z)))));
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shakes_board[r][c] = z;
		shakes.push_back(make_pair(r, make_pair(c, make_pair(s, make_pair(d, z)))));
	}
	bfs();
	cout << ans << '\n';
	return 0;
}