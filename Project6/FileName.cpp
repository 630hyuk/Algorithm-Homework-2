#include<iostream>
#include<string>
using namespace std;

bool Requirements(string s) {
    if (s.length() > 10) {
        return false;
    }
    for (char c : s) {
        if (c != 'I' && c != 'V' && c != 'X') {
            return false;
        }
    }
    return true;
}

int romannum(string s) {
    int res = 0;
    size_t found_IIV = s.find("IIV");
    while (found_IIV != string::npos) {
        res += 3;
        s.erase(found_IIV, 3);
        found_IIV = s.find("IIV");
    }
    size_t found_IIX = s.find("IIX");
    while (found_IIX != string::npos) {
        res += 8;
        s.erase(found_IIX, 3);
        found_IIX = s.find("IIX");
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'I') {
            if (i + 1 < s.size() && s[i + 1] == 'V') {
                res += 4; // for 'IV'
                i++;
            }
            else if (i + 1 < s.size() && s[i + 1] == 'X') {
                res += 9; // for 'IX'
                i++;
            }
            else {
                res += 1;
            }
        }
        else if (s[i] == 'V') {
            res += 5;
        }
        else if (s[i] == 'X') {
            res += 10;
        }
    }
    return res;
}

int main() {
    string input;
    cin >> input;
    if (!Requirements(input)) {
        cout << "문자 입력 최대 길이를 10 초과, I, V, X 이외의 문자열 입력" << endl;
        return 1;
    }
    cout << romannum(input);
    return 0;
}
