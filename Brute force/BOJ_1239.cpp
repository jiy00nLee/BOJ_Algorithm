#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int>v;
	int n,cnt=0,max=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	//���� �������� ����
	sort(v.begin(), v.end());
	do {
		cnt = 0;
		vector<int>t;
		for (int i = 0; i < n; i++) {
			t.push_back(v[i]);
		}
		//�迭 �����ϱ� 
		for (int i = 0; i < n; i++) {
			t.push_back(v[i]);
		}
		for (int i = 0; i < n; i++) {//�Է� ���� ���̸�ŭ �ݺ���
			int tmp = 0;
			for (int j = i; j < t.size(); j++) {//��ü �迭 �ݺ���
				tmp += t[j];
				if (tmp == 50) {//50 �� ��� ī����
					cnt++;
					break;
				}
				else if (tmp > 50) {	//50�̻��̸� break
					break;
				}
			}
		}
		t.clear();
		if (max < cnt) {
			max = cnt;
		}
	} while (next_permutation(v.begin(), v.end()));//���� ���� �̵�
	cout << max/2 << '\n';
	return 0;
}