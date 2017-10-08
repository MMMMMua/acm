#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int n = 1; ; n++) {
		system("./acm"), system("./a");
		if (system("diff a.out b.out"))
			puts("WA"), exit(0);
		else
			cout << n << "AC" << endl;
	}
}
