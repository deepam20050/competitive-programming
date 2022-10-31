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

using lli = int64_t;
using pii = pair < int, int >;

const int N = 51;

string s[N];
int n, m;

void test_case() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int j = 0; j < m; ++j) {
    for (int i = n - 1; i >= 0; --i) {
      int k = i;
      while (k + 1 < n && s[k][j] == '*' && s[k + 1][j] == '.') {
        swap(s[k][j], s[k + 1][j]);
        ++k;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << s[i] << '\n';
  }
  cout << '\n';
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