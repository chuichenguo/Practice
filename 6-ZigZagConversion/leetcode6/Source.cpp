#include <iostream>
#include <string>
#include <vector>
using namespace std;
string convert(string s, int numRows) {
    vector<string> ZigZag;
    string result;
    //push_back string
    for (int i = 0;i < numRows;i++) {
        ZigZag.push_back("");
    }
    int row = 0;
    int upOrDown = 0;
    for (int i = 0;i < s.size();i++) {
        if (row >= ZigZag.size()) {
            row--;
        }
        ZigZag[row].push_back(s[i]);
        if (row == 0) {
            row++;
            upOrDown = 0;
        }
        else if (row == numRows - 1) {
            row--;
            upOrDown = 1;
        }
        else if (upOrDown == 0) {
            row++;
        }
        else {
            row--;
        }
    }
    for (int i = 0;i < ZigZag.size();i++) {
        for (int j = 0;j < ZigZag[i].size();j++) {
            result.push_back(ZigZag[i][j]);
        }
    }
    return result;
}
int main() {
    cout << convert("AB", 1) << endl;
}