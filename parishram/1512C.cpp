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
  int a, b; cin >> a >> b;
  string s; cin >> s;
  int n = sz(s);
  for (int i = 0; i < n - i - 1; ++i) {
    char x = '?';
    if (s[i] != '?') {
      x = s[i];
    }
    if (s[n - i - 1] != '?') {
      x = s[n - i - 1];
    }
    s[i] = s[n - i - 1] = '?';
  }
  a -= count(all(s), '0');
  b -= count(all(s), '1');
  if (a < 0 || b < 0) {
    cout << "-1\n";
    return;
  }
  int yet = count(all(s), '?');
  for (int i = 0; i <= yet; ++i) {
    int j = yet - i;
    if (a - i == 0 && b - j == 0) {
      for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
          if (a) {
            s[i] = s[n - i - 1] = '0';
            a -= i == n - i - 1 ? 1 : 2;
          } else if (b) {
            s[i] = s[n - i - 1] = '1';
            b -= i == n - i - 1 ? 1 : 2;
          } else {
            cout << -1 << '\n';
            return;
          }
        }
      }
      cout << s << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}