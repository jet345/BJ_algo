#include <iostream>
using namespace std;

int main() {
	int num = 15 * 28 * 19;
	int i = 1;
	int E, S, M;

	cin >> E >> S >> M;
	if (E == 15) E = 0;
	if (S == 28) S = 0;
	if (M == 19) M = 0;

	while (i <= num) {
		int a = i % 15;
		int b = i % 28;
		int c = i % 19;
		if (a == E && b == S & c == M) {
			printf("%d", i);
			i = num + 1;
		}			
		i++;
	}
	
}