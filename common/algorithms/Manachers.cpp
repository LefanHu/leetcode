/*
Taken from cp-algorithms.com as is.
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(const string& s) {
    string transformed{};
    for (auto& c : s) {
        transformed.push_back('#');
        transformed.push_back(c);
    }
    // cout << transformed << endl;
    return manacher_odd(transformed + '#');
}

int main() {
    string s = "abcbcba";
    // cout << s << endl;
    vector<int> p = manacher(s);
    for (auto& n : p) {
        cout << n;
    }
    cout << endl;
    return 0;
}