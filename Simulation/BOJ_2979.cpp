#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int pay[4],cnt=0;
	pay[0] = 0;
	//Ʈ�� ���� ���� ��� 
	for (int i = 1; i <= 3; i++) {
		cin >> pay[i];
	}
	pii car[3];
	//�� Ʈ�� �����ð� ��� �ð�
	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		car[i].first = start;
		car[i].second = end;
	}
	int total = 0;
	//�ݺ����� ���ؼ� �ð��� ����
	for (int i = 1; i <= 100; i++) {
		//�� Ʈ���� ��߽ð��� �����ð��� ��ġ �� ��� ī��Ʈ ���ش�.
		if (car[0].first == i)
			cnt++;
		else if (car[0].second == i)
			cnt--;
		if (car[1].first == i)
			cnt++;
		else if (car[1].second == i)
			cnt--;
		if (car[2].first == i)
			cnt++;
		else if (car[2].second == i)
			cnt--;
		//���� Ʈ���� ���� ���� ����� �����ش�.
		total += pay[cnt] * cnt;
	}
	cout << total<<'\n';
	return 0;
}