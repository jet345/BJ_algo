//QUEUE 사용 문제
//숨바꼭질
//BFS문제
/*
			X
		/   |   \
		X-1  X+1  2X
이미 지나왔던 길은 제외하고 찾는다
*/
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int isvisit[100001] = { 0, };
int dist[100001] = { 0, };
int que_val;

void isvalid(int i) {
	if  (i <= 100000 && i >= 0) { //방문하지않았다면
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

	while (!q.empty()) { //queue가 비어 있지 않을때까지
		que_val = q.front(); //맨 앞 위치

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