#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

using namespace std;
char b[111];
int s;
int main() {
	int num;
	int num_save;
	int x;
	scanf("%d", &num);
	num_save = num;
	while (num--) {
		scanf("%s", b);
		if (!strcmp(b, "add")) {
			scanf("%d", &x);
			s = (s | (1 << x));
		}
		else if (!strcmp(b, "remove")) {
			scanf("%d", &x);
			s = (s & ~(1 << x));
		}
		else if (!strcmp(b, "check")) {
			scanf("%d", &x);
			int result = s & (1 << x);
			if(result==0) printf("0\n");
			else printf("1\n");			
		}
		else if (!strcmp(b, "toggle")) {
			scanf("%d", &x);
			s = s ^ (1 << x);
		}
		else if (!strcmp(b, "all")) {
			s = (1 << num_save) - 1;
		}
		else if (!strcmp(b, "empty")) {
			s = 0;
		}
	}

}