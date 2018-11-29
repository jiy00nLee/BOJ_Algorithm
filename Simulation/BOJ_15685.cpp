#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 101
typedef pair<int, pair<int,pair<int,int>>>piiii;//dir ,g , x, y
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
bool map[MAX][MAX];
bool visited[MAX][MAX];
int cnt;
enum {
	east = 0, north, west, south
};
int dirCalc(int num) {
	switch(num){
	case east:
		return north;
		break;
	case south:
		return east;
		break;
	case west:
		return south;
		break;
	case north:
		return west;
		break;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int>v[20];
	piiii go[20];
	for (int i = 0; i < n; i++) {
		int x,y,d,g;
		cin >> x >> y >> d >> g;
		go[i].first = d;
		go[i].second.first = g;
		go[i].second.second.first = x;
		go[i].second.second.second = y;
	}
	//�巡�︶�� �ݺ��� ����
	for (int i = 0; i < n; i++) {
		v[i].push_back(go[i].first);
		int len = go[i].second.first;
		//�� �巡�︶�� 0������� len-1������� üũ�Ѵ�.
		for (int j = 0; j < len; j++) {
			int size = v[i].size();
			for (int k = size - 1; k >= 0; k--) {	//��ġ�� �����Ѵ�.
				int dir = dirCalc(v[i][k]);
				v[i].push_back(dir);
			}
		}
	}
	//�� �巡�︶�� �̵��� �ʿ� üũ
	for (int i = 0; i < n; i++) {
		int startX = go[i].second.second.first;
		int startY = go[i].second.second.second;
		map[startX][startY] = true;
		for (int j = 0; j < v[i].size(); j++) {
			startX +=  dx[v[i][j]];
			startY += dy[v[i][j]];
			map[startX][startY] = true;
		}
	}

	//�ʿ� ��� �簢���� Ž���Ѵ�.
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (map[i][j]) {
				bool check1 = (map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]);
				bool check2 = (!visited[i][j] || !visited[i + 1][j] || !visited[i][j + 1] || !visited[i + 1][j + 1]);
				if (check1&&check2) {
					visited[i][j] = true; visited[i + 1][j] = true; visited[i][j + 1] = true; visited[i + 1][j + 1] = true;
					cnt++;
				}
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}