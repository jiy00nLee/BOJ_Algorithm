#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<set>
int cnt,n,m;
using namespace std;
typedef pair<int, int> pii;			//x��ǥ y��ǥ
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pii>v,star,dist;
	set<pii>s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		s.insert(make_pair(x,y));
		star.push_back(make_pair(x,y));
	}
	
	pii startPos;
	startPos.first = v[0].first;
	startPos.second = v[0].second;
	//ó�� �־��� ��ǥ�� �� ��ǥ���� �Ÿ��� �����Ѵ�.
	for (int i = 1; i < v.size(); i++) {
		int distPosX,distPosY;
		distPosX = v[i].first - startPos.first;
		distPosY = v[i].second - startPos.second;
		dist.push_back(make_pair(distPosX,distPosY));
	}
	//�Է� ���� �� �������κ��� �� ��ǥ���� ���ڸ��� ���Ҽ� �ִ��� üũ
	for (int i = 0; i < star.size(); i++) {
		int curPosX = star[i].first;
		int curPosY = star[i].second;
		cnt = 0;
		for (int j = 0; j < dist.size(); j++) {
			pii pos;
			pos.first = curPosX + dist[j].first;
			pos.second = curPosY + dist[j].second;
			if (s.count(make_pair(pos.first, pos.second)) == 1) {
				cnt++;	//�Ÿ��� ���� ��ǥ�� �����Ѵٸ� ī��Ʈ
			}
		}
		if (cnt == dist.size()) {		//���� ��ǥ�� ���ڸ��� �����ϴ��� üũ
			cout << ( curPosX- startPos.first)<<' '<<(curPosY- startPos.second)<<'\n';
			break;
		}
	}
	return 0;
}