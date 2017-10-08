#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int n = 1; ; n++) {
		system("./acm"), system("./j");
		if (system("diff j.out j.diff"))
			puts("WA"), exit(0);
		else
			cout << n << "AC" << endl;
	}
}
 
