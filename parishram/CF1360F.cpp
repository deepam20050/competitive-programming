#include "bits/stdc++.h"

using namespace std;

const int N = 15;

string s[N];

int n, m;

bool check (string t) {
  for (int i = 1; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < m; ++j) {
      cnt += s[i][j] != t[j];
    }
    if (cnt > 1) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    if (check(s[0])) {
      cout << s[0] << '\n';
    } else {
      string print = "-1";
      for (int i = 0; i < m; ++i) {
        int ori = s[0][i] - 'a';
        for (int j = 0; j < 26; ++j) {
          s[0][i] = j + 'a';
          if (check(s[0])) {
            print = s[0];
          }
        }
        s[0][i] = ori + 'a';
      }
      cout << print << '\n';
    }
  }
  return 0;
}
