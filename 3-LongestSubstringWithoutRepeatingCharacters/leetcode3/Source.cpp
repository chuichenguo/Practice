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
            //如果下一個要加入的字母在子字串都沒有 才可以加入
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
