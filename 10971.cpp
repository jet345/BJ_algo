#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> d; //0~N-1
int W[10][10];
vector<int> result;

int main() {
	int N,temp;//2~10
	int sum=0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			W[i][j] = temp;
		}
		d.push_back(i);
	}

	do {
		bool ok = true;
		for (int i = 0; i < N-1; i++) {
			if (W[d[i]][d[i + 1]] == 0) {//갈수없는 길이라면
				ok = false;
				i = N; //for문 break
			}
			else {//갈수있는 길 일 때
				sum += W[d[i]][d[i + 1]];
			}
		}
		if (ok && W[d[N - 1]][d[0]] != 0) {
			sum += W[d[N - 1]][d[0]];
			result.push_back(sum);
		}
		sum = 0;

	} 
	//자동 순열 생성 0부터 N-1까지 가능한 모든 순서를 만들어준다.
	while (next_permutation(d.begin(),d.end()));

	sort(result.begin(), result.end());

	cout << result[0];
}