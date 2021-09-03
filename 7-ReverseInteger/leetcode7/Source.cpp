#include <string>
#include <iostream>
using namespace std;
int reverse(int x) {
	bool isNegative = false;
	if (x < 0) {
		isNegative = true;
	}
	string num = to_string(x);
	string result;
	for (int i = num.size() - 1;i >= 0;i--) {
		result.push_back(num[i]);
	}
	long long int reverseNum = stoll(result);
	if (reverseNum > INT_MAX) {
		return 0;
	}
	if (isNegative) {
		reverseNum *= (-1);
	}
	return reverseNum;
}
int main() {
	cout << reverse(-2147483648) << endl;
}