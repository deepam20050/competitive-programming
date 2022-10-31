#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

void test_case() {
  array < int, 2 > c; cin >> c[0] >> c[1];
  string s; cin >> s;
  int n = c[0] + c[1];
  for (int i = 0, j = n - 1; i < n; ++i, --j) {
    if (s[i] == '?' || s[j] == '?') {
      char c = s[i] == '?' ? s[j] : s[i];
      s[i] = s[j] = c;
    } else if (s[i] != s[j]) {
      cout << "-1\n";
      return;
    }
  }
  for (auto &e : s) {
    if (e != '?') {
      --c[e - '0'];
    }
  }
  if (c[0] < 0 || c[1] < 0) {
    cout << "-1\n";
    return;
  }
  if ((n & 1) && s[n >> 1] == '?') {
    int mid = n >> 1;
    if (c[0] % 2) {
      s[mid] = '0';
      --c[0];
    } else if (c[1] % 2) {
      s[mid] = '1';
      --c[1];
    } else {
      cout << "-1\n";
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    int j = n - i - 1;
    if (s[i] == '?') {
      if (c[0] > 0) {
        s[i] = s[j] = '0';
        c[0] -= 2;
      } else if (c[1] > 0) {
        s[i] = s[j] = '1';
        c[1] -= 2;
      }
    }
  }
  int x = count(all(s), '?');
  if (x > 0 || c[0] != 0 || c[1] != 0) {
    cout << "-1\n";
  } else {
    cout << s << '\n';
  }
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}