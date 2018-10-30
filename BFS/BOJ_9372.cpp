#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
#define MAX 1001
bool visited[MAX];	//�湮 �ߴ��� üũ
int bfs(vector<int>v[MAX]) {
	memset(visited, false, sizeof(visited));
	queue<int>q;
	q.push(1);
	int ans = 0;
	while (!q.empty()) {
		int currentNode = q.front();	
		q.pop();
		if (!visited[currentNode]) {	//�湮�ߴ��� üũ
			visited[currentNode] = true;
			ans++;
			for (int i = 0; i < v[currentNode].size(); i++) {	//���� ��忡�� ����Ǿ��ִ� ��� ������.
				int nextNode = v[currentNode][i];
				if (!visited[nextNode])	//����� ��尡 �湮 ���� ����̸� q�� ����ִ´�.
					q.push(nextNode);
			}
		}
	}
	return ans-1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n, m;
		cin >> n >> m;
		vector<int>v[MAX];
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b); v[b].push_back(a);
		}
		int ans=bfs(v);
		cout << ans << '\n';
	}
	return 0;
}