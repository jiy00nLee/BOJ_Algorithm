	#include<iostream>
	#include<queue>
	#include<set>
	#include<vector>
	#include<string.h>
	using namespace std;
	#define INF numeric_limits<int>::max()
	bool calcNum[10];
	vector<int>possibleNum;
	int n;
	typedef pair<long, long>pll;
	//���޹��� �Ű����� num�� Ȱ��ȭ�� ��ư���� �̷���� �ִٸ� true �ƴϸ� false
	bool check(int num) {
		while (num !=0) {
			if (calcNum[num % 10] == false)
				return false;
			else
				num /= 10;
		}
		return true;
	}
	//�Ű����� �ڸ��� Ȯ���ϴ� �Լ� == ���ڸ� ��� ���ؼ� ���� ��ư Ƚ��
	int countFunc(int num) {
		int res = 0;
		while (num != 0) {
			num /= 10;
			res++;
		}
		return res;
	}
	int bfs(int n) {
		priority_queue<pll>pq;		//����  , ��ư ���� Ƚ��
		set<int>s;					//�湮�ߴ��� üũ�ϱ� ���� ����
		int res = INF;
		for (int i = 0; i < possibleNum.size(); i++) {
			pq.push(make_pair(possibleNum[i],countFunc(possibleNum[i])));	//����, ���� ��ư���� Ƚ���� �ʱ�ȭ
			s.insert(possibleNum[i]);	
		}
		while (!pq.empty()) {
			long long curNum = pq.top().first;		//����ִ� ���� (���)
			long long btnCnt = pq.top().second;	//��ư ���� Ƚ��
			long long divNum = n / curNum;			//���� �� 
			if (n%curNum == 0 && check(divNum)) {	//���� ���� ��ư���� ���� �� �ְ� ������
				int value=0,curNumCnt = 0,divNumCnt=0;
				value = countFunc(divNum);			//���� �� ��ư Ƚ���� üũ
				if (res > value + btnCnt + 2)		//2�� ���ϴ� ������ +,= ��ư�� �������̴�.
					res = value + btnCnt + 2;		//�ּҰ����� ������Ʈ
			}
			pq.pop();
			for (int i = 0; i < possibleNum.size(); i++) {// ����鳢�� ���ϴ� ����
				long long nextNum = curNum * possibleNum[i];
				if (s.count(nextNum) == 0&&nextNum<=n) {//�湮�ߴ��� üũ, �Է¹��� ���ں��� �۰ų� ������
					long long nextOperCnt = btnCnt + 1 + countFunc(possibleNum[i]);	//������� ���� ��ưȽ�� + *��ư + ���Ҽ��� ��ưȽ��
					pq.push(make_pair(nextNum,nextOperCnt));
					s.insert(nextNum);
				}
			}
		
		}
		s.clear();
		if (res == INF) return -1;
		else return res;
	}
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int testCase;
		cin >> testCase;
		for(int tc=1;tc<=testCase;tc++){
			memset(calcNum, 0, sizeof(calcNum));
			possibleNum.clear();
			for (int i = 0; i < 10; i++) {
				cin >> calcNum[i];
			}
			cin >> n;
			if (check(n)) {//���ϱ� ������ �ʿ���� �ѹ濡
				cout <<"#"<<tc<<' '<<countFunc(n) + 1 << '\n';
			}
			else {
				for (int i = 1; i <= n/2; i++) {	//���ϱ� ������ ����ϹǷ� �ݸ� Ž��
					if (n%i == 0 && check(i)) {		// i�� ����̰� ��ư�� ���� Ȱ��ȭ �Ǿ��ִٸ�
						possibleNum.push_back(i);
					}
				}
				cout << "#" << tc << ' ' << bfs(n) << '\n';
			}
		}
		return 0;
	}