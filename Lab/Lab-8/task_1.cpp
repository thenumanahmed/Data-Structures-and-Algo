
#include<iostream>
using namespace std;

int multiply(int a, int n) {
	if (n == 0 || a == 0)
	{
		return 0;
	}
	return a + multiply(a, n - 1);
}

int main() {
	cout << multiply(2,4);
	return 0;
}