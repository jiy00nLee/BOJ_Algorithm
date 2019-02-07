#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		int n,ans=0;
		cin >> n;
		vector<ll>v;
		queue<int>q;	// a <b 1 // a>b 2
		for (int i = 0; i < n; i++) {
			ll num;
			cin >> num;
			v.push_back(num);
		}
		int leftCnt = 0, rightCnt = 0;
		//���� ���� ���ؼ� �ε�ȣ ���� ť�� �־����ϴ�. <�� 1�� >�� 2��  
		for (int i = 1; i < v.size(); i++) {
			if (v[i - 1] < v[i])
				q.push(1);
			else if (v[i - 1] > v[i])
				q.push(2);
		}
		int prevD = q.front();	// ������ ������ Ȯ���ϱ����� ���� �ϳ� �����ϴ�.
		if (prevD == 1) rightCnt++;
		else leftCnt++;
		q.pop();
		while (!q.empty()) {
			int curD = q.front();
			q.pop();
			if (prevD == 2 && curD == 1) {//�ٽ� ��� �� ���� ã�ƾߵǴ� ����� ����ϰ� ī��Ʈ�� �ʱ�ȭ���ش�.
				ans += leftCnt * rightCnt;
				leftCnt = 0;
				rightCnt = 1;
			}
			else {
				if (curD == 1) rightCnt++;
				else leftCnt++;
			}
			prevD = curD;
		}
		ans += leftCnt * rightCnt;	//�׳� ������ ��쵵 �����Ƿ� ī��Ʈ�ߴ� ������ ����ؼ� ������� �����ش�.
		cout <<'#'<<tc<<' '<< ans << '\n';
	}
	return 0;
}