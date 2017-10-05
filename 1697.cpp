//QUEUE ��� ����
//���ٲ���
//BFS����
/*
			X
		/   |   \
		X-1  X+1  2X
�̹� �����Դ� ���� �����ϰ� ã�´�
*/
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int isvisit[100001] = { 0, };
int dist[100001] = { 0, };
int que_val;

void isvalid(int i) {
	if  (i <= 100000 && i >= 0) { //�湮�����ʾҴٸ�
		if (isvisit[i] == 0) {
			q.push(i);
			isvisit[i] = 1;
			dist[i] = dist[que_val] + 1;
		}
	}
}

int main() {
	int subin;
	int dest;
	int ans;
	cin >> subin >> dest;

	q.push(subin);
	isvisit[subin] = 1;
	dist[subin] = 0;

	while (!q.empty()) { //queue�� ��� ���� ����������
		que_val = q.front(); //�� �� ��ġ

		if (que_val == dest) {
			ans = dist[dest];
			break;
		}

		q.pop();
		isvalid(que_val - 1);
		isvalid(que_val + 1);
		isvalid(que_val * 2);
	}

	cout << ans;
}