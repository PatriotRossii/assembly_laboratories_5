#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

extern "C" int IntegerShift_(unsigned int a, unsigned int count, unsigned int* a_shl, unsigned int* a_shr);

static void PrintResult(
	const char* msg,
	int rc, unsigned int a, unsigned int count,
	unsigned int a_shl, unsigned int a_shr
) {
	cout << msg << '\n';

	bitset<32> a_bs(a);
	bitset<32> a_shl_bs(a_shl);
	bitset<32> a_shr_bs(a_shr);
	const int w = 10;

	cout << "count = " << setw(w) << count << '\n';
	cout << "a = " << setw(w) << a << " (0b" << a_bs << ")" << '\n';

	if (rc == 0)
		cout << "Invalid shift count" << '\n';
	else {
		cout << "shl = " << setw(w) << a_shl << " (0b" << a_shl_bs << ")" << '\n';
		cout << "shr = " << setw(w) << a_shr << " (0b" << a_shr_bs << ")" << '\n';
	}
	cout << '\n';
}

int main() {
	{
		unsigned int a = 3119, count = 6, a_shl, a_shr;
		int rc = IntegerShift_(a, count, &a_shl, &a_shr);
		PrintResult("Пример 1", rc, a, count, a_shl, a_shr);
	}
	{
		unsigned int a = 0x00800080, count = 4, a_shl, a_shr;
		int rc = IntegerShift_(a, count, &a_shl, &a_shr);
		PrintResult("Пример 2", rc, a, count, a_shl, a_shr);
	}
	{
		unsigned int a = 0x80000001, count = 31, a_shl, a_shr;
		int rc = IntegerShift_(a, count, &a_shl, &a_shr);
		PrintResult("Пример 3", rc, a, count, a_shl, a_shr);
	}
	{
		unsigned int a = 0x55555555, count = 32, a_shl, a_shr;
		int rc = IntegerShift_(a, count, &a_shl, &a_shr);
		PrintResult("Пример 4", rc, a, count, a_shl, a_shr);
	}
}