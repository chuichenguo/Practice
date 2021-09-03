#include <string>
#include <iostream>
using namespace std;
int myAtoi(string s) {
	long long int result = 0;
	int isNegative = 1;

	//check negative
	int k = s.find_first_not_of(' ');
	//if input is ""
	if (k < 0) {
		k = 0;
	}
	if (s[k] == '-') {
		isNegative = -1;
		k++;
	}
	else if (s[k] == '+') {
		k++;
	}

	for (int i = k;i < s.length();i++) {

		if (s[i] - '0' <= 9 && s[i] - '0' >= 0) {
			result *= 10;
			result += (s[i] - '0');
			if (result * isNegative >= INT_MAX) {
				return INT_MAX;
			}
			else if (result * isNegative <= INT_MIN) {
				return INT_MIN;
			}
		}
		else if (s[i] - '0' > 9 || s[i] - '0' < 0) {
			break;
		}
		
	}
	
	return result * isNegative;
}
int main() {
	cout << myAtoi("+1") << endl;
}