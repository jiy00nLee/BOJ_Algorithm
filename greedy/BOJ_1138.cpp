#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAX 11
int arr[MAX],n,per[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<int>v;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];		//arr �� ū ���� ���� �迭
		v.push_back(i);		//������ ����ϱ� ���� ���� �迭
	}
	queue<int>q;
	do{
		for (int i = 0; i < v.size(); i++) {
			int cnt = 0;
			for (int j = 0; j <i; j++) {	//���� i��° ����� ���ʿ� �ڱ⺸�� ū ����� ������� üũ�ϴ� �ݺ���
				if (v[j] > v[i]) {
					cnt++;
				}
			}
			if (arr[v[i]] == cnt)	//����ϰ��ִ� ��� ���� ��ġ�ϴٸ�
				q.push(v[i]);
			else {
				while (!q.empty())
					q.pop();
				break;
			}
		}
		if (q.size() == n)
			break;
	} while (next_permutation(v.begin(),v.end()));

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		cout << num << ' ';
	}cout << '\n';
	return 0;
}