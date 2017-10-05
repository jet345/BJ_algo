#include <iostream>
#include <math.h>
using namespace std;
int err[10] = { 0, };
int channel;
int err_count;

bool possible(int ch) {
	if (err[ch % 10]) return false;
	else return true;
}

int calc_num(int channel_f) {
	int result = channel_f;
	if (channel_f == 0) channel_f = 600000; result = 0;
	
	int tmp_result = 0;//자리수
	while (channel_f > 0) {
		if (!possible(channel_f)) {
			//맨마지막 자리가 
			//고장난 버튼이 포함된 채널인경우
			int div = (channel_f % 10);
			if (channel_f == 600000) div = 0; channel_f = 0;
			for (int i = 1; i < 10; i++) {
				int index = abs(div - i);
				if (!err[index]) {
					if(index > div) result += (index - div)*(pow(10, tmp_result));
					else result -= (div -index )*(pow(10, tmp_result));
					break; 
				}
			}
		}
		tmp_result++;
		if(channel_f!=0)channel_f /= 10;
	}
	if(channel > result)	result = channel - result;
	else result = result - channel;
	result += tmp_result;
	int plus_minus = abs(100 - channel);

	if (plus_minus < result) result = plus_minus;
	

	return result;
}


int main() {
	int tmp;
	int result;
	cin >> channel;
	cin >> err_count;

	while (err_count--) {
		cin >> tmp;
		err[tmp] = 1;
	}
	if (channel == 100)
		cout << "0";
	else {
		result = calc_num(channel);
		cout << result;
	}
}
