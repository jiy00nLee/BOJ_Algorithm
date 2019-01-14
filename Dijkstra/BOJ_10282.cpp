#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAX 10001
bool visited[MAX];
int valueSave[MAX];
int n, d, c,cnt;
typedef pair<int, int>pii;		//�ð� ,���� ���
void initFunction() {
	memset(visited, false, sizeof(visited));
	memset(valueSave, 0, sizeof(valueSave));
	cnt = 0;
}
/*
�⺻ ����
�ð� ª�� ������ ť���� ������ ��ǻ�� �湮�� �����ϴٸ� 
��ǻ�� ���� ī��Ʈ �ϰ� �ִ� �ð����� �湮 �Ѱ��̹Ƿ� 
�迭�� ��ǻ�͹�ȣ �ε����� �ִ� �ð��� �����Ѵ�.
������ �迭�� ����ִ� �ð��� �ִ밪�� ����Ѵ�.

*/
void bfs(int startNode, vector<pii>edge[MAX]) {
	priority_queue<pii,vector<pii>,greater<pii>>pq;//�ð�,���� ���
	pq.push(make_pair(0,startNode));
	while (!pq.empty()) {
		int curSecond = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (!visited[curNode]) {
			visited[curNode] = true;
			cnt++;	//������ ��ǻ�� ī��Ʈ
			valueSave[curNode] = curSecond;	//������ ��ǻ�� �ð��� ����
			for (int i = 0; i < edge[curNode].size(); i++) {
				int nextNode = edge[curNode][i].second;
				if (!visited[nextNode]) {
					int nextSecond = curSecond + edge[curNode][i].first;
					pq.push(make_pair(nextSecond, nextNode));
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		vector<pii> edge[MAX];
		initFunction();
		int a, b, s;
		
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			edge[b].push_back(make_pair(s, a));
		}
		bfs(c,edge);
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (res < valueSave[i])
				res = valueSave[i];
		}
		cout <<cnt<<' '<<res << '\n';
	}
	return 0;
}