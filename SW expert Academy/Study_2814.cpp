#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;
#define MAX 11
bool visited[MAX];
typedef pair<int, int>pii;
int maxDist;
void dfs(int startNode,vector<int>edge[MAX],int dist) {
	visited[startNode] = true;
	if (maxDist < dist)//Ž���� ��ΰ� ���� ��ٸ� ������Ʈ ���ش�.
		maxDist = dist;
	for (int i = 0; i < edge[startNode].size(); i++) {//����Ǿ� �ִ� ������ dfs�� Ž���� �Ѵ�.
		int nextNode = edge[startNode][i];	//���� ��� 
		int nextDist = dist + 1;			
		if (!visited[nextNode]) {
			dfs(nextNode, edge, nextDist);	//���� ��� Ž��
			visited[nextNode] = false;		//���� ��带 �湮�� �����Ѵ�. 
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		int n, m;
		vector<int>edge[MAX];	//���� ���� ����
		int res = 0;
		maxDist = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);	//�������̹Ƿ� �������� ����
			edge[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) { //������ġ�� n�� Ȯ���Ѵ�.
			memset(visited, false, sizeof(visited));
			dfs(i,edge,1);
			if (res < maxDist)
				res = maxDist;
		}
		cout <<'#'<<tc<<' '<<res << '\n';
	}

	return 0;
}