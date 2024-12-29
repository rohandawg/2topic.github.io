#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int PRIME = 101;

void rabinKarp(string text, string pattern, int q = PRIME) {
    int n = text.size();
    int m = pattern.size();
    int h = 1;
    int p = 0, t = 0;
    vector<int> result;

    for (int i = 0; i < m - 1; ++i) {
        h = (h * 256) % q;
    }

    for (int i = 0; i < m; ++i) {
        p = (256 * p + pattern[i]) % q;
        t = (256 * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; ++i) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i);
            }
        }
        if (i < n - m) {
            t = (256 * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) {
                t += q;
            }
        }
    }

    if (result.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at index: ";
        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    rabinKarp(text, pattern);

    return 0;
}
