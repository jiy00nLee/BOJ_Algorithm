#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, C,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> C;

	vector<int>houses;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		houses.push_back(num);
	}

	sort(houses.begin(), houses.end());

	//����
	int left = 1;	//�ּ� ���� ����
	int right = houses[N - 1] - houses[0];	//�ִ� ���� ����
	int d = 0;
	int ans = 0;

	while (left <= right) {
		//����
		int mid = (left + right) / 2;
		int start = houses[0];
		int cnt = 1;
		
		for (int i = 1; i < N; i++) {
			d = houses[i] - start;
			if (mid <= d) {//���� ���ݺ��� ũ�ų� ���ٸ� ������ ��ġ�� �����ϴ�.
				++cnt;
				start = houses[i];
			}
		}

		if (cnt >= C) {
			//�������� ���� ������ -> ���� ������
			ans = mid;
			left = mid + 1;
		}
		else {
			//�����Ⱑ �� ��ġ�Ǿ�� �Ѵ�. -> ���� ���̱�
			right = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}