#include <string>
#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int max = 0;
    string substring;
    for (int i = 0;i < s.size();i++) {
        bool stop = false;
        for (int j = i;j < s.size();j++) {
            substring = substring + s[j];
            //�p�G�U�@�ӭn�[�J���r���b�l�r�곣�S�� �~�i�H�[�J
            for (int k = 0;k < substring.size();k++) {
                //overflow
                if (j + 1 >= s.size()) {
                    if (max < substring.size()) {
                        max = substring.size();
                    }
                    substring.clear();
                    stop = true;
                    break;
                }
                else if (substring[k] != s[j + 1]) {
                    continue;
                }
                else {
                    if (max < substring.size()) {
                        max = substring.size();
                    }
                    substring.clear();
                    stop = true;
                    break;
                }
            }
            if (stop == true) {
                break;
            }
        }
    }
    return max;

}

int main() {
    string s = " ";
    cout << lengthOfLongestSubstring(s) << endl;
}
