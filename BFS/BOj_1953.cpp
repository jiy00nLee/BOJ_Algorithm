#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;
bool visited[101];		//�湮�ߴ��� ���ߴ��� üũ�ϴ� ����
set<int>blue, white;	//set�����̳ʷ� blue�� , white�� �з�
vector<int>v[101];		// �Ⱦ��ϴ� ��� �ִ� ����
int n;					
void bfs() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {	//��� �л����� üũ�ϱ� ���� �ݺ���
		q.push(i);
		while (!q.empty()) {
			int currentNode = q.front();	
			q.pop();
			if (!visited[currentNode]) {	//�湮���� �ʾҴٸ�
				visited[currentNode] = true;
				if (blue.count(currentNode) == 0 && white.count(currentNode) == 0) {//�ƹ����� �ȵ������� blue�� �ְ�
					blue.insert(currentNode);
				}
				for (int i = 0; i < v[currentNode].size(); i++) {
					int nextNode = v[currentNode][i];

					if (!visited[nextNode]) {	//������尡 �湮 ���� �����
						if (blue.count(currentNode) != 0) {	//blue�� ���� ��尡 ��������� white�� ������带 �ִ´�.
							white.insert(nextNode);
						}
						else if (white.count(currentNode) != 0) {//white�� ���� ��尡 ��������� blue�� ������带 �ִ´�.
							blue.insert(nextNode);
						}
						q.push(nextNode);
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 1; j <= num; j++) {
			int a;
			cin >> a;
			v[i].push_back(a); v[a].push_back(i);
		}
	}
	bfs();
		set<int>::iterator itr;
	cout << blue.size() << '\n';
	for (itr = blue.begin(); itr != blue.end(); ++itr) {
		cout << *itr << ' ';
	}cout << '\n';
	cout << white.size() << '\n';
	for (itr = white.begin(); itr != white.end(); ++itr) {
		cout << *itr << ' ';
	}cout << '\n';
	return 0;
}