#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <iomanip>

using namespace std;

void Radix(int c[15]) {

	int proc = 10; int full = 1, x = 1, xx = 0;

	while (x != 0) {

		int s = 14;
		while (s != 0) {
			for (int i = 0; i < s; i++) {
				if (c[i] % proc / full > c[i + 1] % proc / full) {
					swap(c[i], c[i + 1]);
					xx++;
				}
			}
			s--;
		}

		proc = proc * 10;
		full = full * 10;

		if (xx == 0) {
			x = 0;
		}
		else {
			xx = 0;
		}
	}

	int num = 0;
	for (int i = 0; i < 15; i++) {
		cout << c[i] << " ";
		num++;
		if (num == 5) {
			cout << "\n";
			num = 0;
		}
	}

}



int main() {
	int a[15]{};

	srand(time(NULL));
	for (int i = 0; i < 15; i++) {
		a[i] = 200 + rand() % 101;
	}

	Radix(a);
	system("PAUSE");
	return 0;
}