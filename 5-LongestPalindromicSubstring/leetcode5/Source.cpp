#include <string>
#include <iostream>
using namespace std;
string longestPalindrome(string s) {
    if (s.size() < 2) {
        return s;
    }
    int maxLength = 0;
    int startIndex = 0;
    int i = 0;
    while (i < s.size()) {
        int right = i;
        int left = i;
        while (right < s.size() && s[right + 1] == s[right]) {
            right++;
        }
        i = right + 1;
        while (right < s.size() && left > 0 && s[right + 1] == s[left - 1]) {
            right++;
            left--;
        }
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
            startIndex = left;
        }
    }
    return s.substr(startIndex, maxLength);
}
int main() {
    cout << longestPalindrome("bbab") << endl;
}