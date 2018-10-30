#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
#define MAX 100001
bool visited[MAX];
int a, b, n, m,ans;
typedef pair<int, int>pii;	// ī��Ʈ , ��ġ
bool rangeCheck(int pos) {
	return (pos >= 0 && pos < MAX) ? true : false;	
}
void bfs() {
	priority_queue<pii,vector<pii>,greater<pii>> pq;		
	pq.push(make_pair(0, n));
	while (!pq.empty()) {
		int currentPos = pq.top().second;
		int currentCnt = pq.top().first;
		if (currentPos == m) {
			ans = currentCnt;
			break;
		}
		pq.pop();
		if (!visited[currentPos]) {
			visited[currentPos] = true;
			int nextPos = currentPos;
			if (rangeCheck(nextPos+1)&&!visited[nextPos + 1]) {		// +1 �̵�
				pq.push(make_pair(currentCnt+1,nextPos+1));
			}if (rangeCheck(nextPos-1)&&!visited[nextPos - 1]) {	// -1 �̵�
				pq.push(make_pair(currentCnt + 1, nextPos - 1));

			}if (rangeCheck(nextPos+a)&&!visited[nextPos + a]) {	// +a �̵�
				pq.push(make_pair(currentCnt + 1, nextPos + a));

			}if (rangeCheck(nextPos+b)&&!visited[nextPos + b]) {	// +b �̵�
				pq.push(make_pair(currentCnt +1, nextPos + b));

			}if (rangeCheck(nextPos-a)&&!visited[nextPos - a]) {	// -a �̵�
				pq.push(make_pair(currentCnt + 1, nextPos - a));

			}if (rangeCheck(nextPos - b) && !visited[nextPos - b]) {	// -b �̵�
				pq.push(make_pair(currentCnt + 1, nextPos -b));

			}if (rangeCheck(nextPos*a) && !visited[nextPos*a]) {	// ������ǥ*a �̵�
				pq.push(make_pair(currentCnt +1, nextPos *a));

			}if (rangeCheck(nextPos*b) && !visited[nextPos*b]) {	//������ǥ*b �̵�
				pq.push(make_pair(currentCnt +1, nextPos *b));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> n >> m;
	bfs();
	cout << ans << '\n';
	return 0;
}