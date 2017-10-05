#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> lotto;
vector <int> sel;
vector<vector<int>> ans;
vector<int> tmp;
int N = 1;

void lotto_select() {
	do {
		for (int i = 0; i < N; i++) {
			if (sel[i]==0) {
				tmp.push_back(lotto[i]);
			}
		}
		ans.push_back(tmp);
		tmp.clear();
	} while (next_permutation(sel.begin(), sel.end()));	
}


int main() {

	int tmp;
	while (true) {
		cin >> N;
		if (N == 0) break;
		
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			lotto.push_back(tmp);
			sel.push_back(0);
		}
		//1이 기본적으로 6개, 차이만큼 0집어넣음
		for (int j = 0; j < N-6; j++) {
			sel[j] = 1;
		}
		sort(sel.begin(), sel.end());
		lotto_select();
		ans.push_back({-5,-1,-1,-1,-1,-1}); //구분
		sel.clear();
		lotto.clear();
	}

	for (int i = 0; i < ans.size()-1; i++) {
		if (ans[i][0] == -5) { cout << endl; i++; }
		for (int j = 0; j < 6; j++) {			
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}