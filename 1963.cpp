#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int prime[10000] = { 0, };
int isvisit[10000] = { 0, };
int dist[10000] = { 0, };
vector<int> ans;
queue<int> q;

int IsPrimeNumber(int n)
{
	int i = 0;
	int last = n / 2;
	if (n <= 1)//소수는 1보다 큰 자연수여야 함
	{
		return 0;
	}

	for (i = 2; i <= last; i++)
	{
		if ((n%i) == 0)	return 0;
	}
	return 1;
}
void init_prime() {
	int i = 0;
	for (i = 1000; i <= 9999; i++)	
		if (IsPrimeNumber(i))	prime[i] = 1;	
}

void change_one(int input) {
	for (int i = 0; i <= 9; i++) {
		int t = input % 10;
		int base = input - t;
		int temp = base + (i * pow(10, 0));
		if (prime[temp]== 1 && isvisit[temp]==0) {
			q.push(temp);
			isvisit[temp] = 1;
			dist[temp] = dist[input] + 1;
		}
	}
	for (int i = 0; i <= 9; i++) {
		int t = input / 10;
		t = t % 10;
		int base = input - (t * 10);
		int temp = base + (i * pow(10, 1));
		if (prime[temp] == 1 && isvisit[temp] == 0) {
			q.push(temp);
			isvisit[temp] = 1;
			dist[temp] = dist[input] + 1;
		}
	}
	for (int i = 0; i <= 9; i++) {
		int t = input / 100;
		t = t % 10;
		int base = input - (t * 100);
		int temp = base + (i * pow(10, 2));
		if (prime[temp] == 1 && isvisit[temp] == 0) {
			q.push(temp);
			isvisit[temp] = 1;
			dist[temp] = dist[input] + 1;
		}
	}
	for (int i = 1; i <= 9; i++) {
		int t = input / 1000;
		int base = input - (t * 1000);
		int temp = base + (i * pow(10, 3));
		if (temp <= 9999) {
			if (prime[temp] == 1 && isvisit[temp] == 0) {
				q.push(temp);
				isvisit[temp] = 1;
				dist[temp] = dist[input] + 1;
			}
		}
	}
}

int main(void)
{
	int N;
	int start, dest;
	int answer=-1;
	init_prime();

	cin >> N;


	while (N > 0) {
		cin >> start >> dest;
		q.push(start);
		isvisit[start] = 1;
		dist[start] = 0;
		while (!q.empty()) {
			int first = q.front();
			if (first == dest)
				answer = dist[first];
			change_one(first);
			q.pop();
		}
		ans.push_back(answer);
		for (int i = 0; i < 10000; i++) { dist[i] = 0; isvisit[i] = 0; }
		answer = -1;
		N--;		
	}
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == -1) cout << "Impossible" << endl;
		else cout << ans[i] << endl;
	}


	return 0;
}
