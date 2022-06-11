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

const int N = 205;

bool used[N];

void test_case() {
  int n; cin >> n;
  memset(used, 0, sizeof used);
  string s; cin >> s;
  vector < int > p(n);
  for (auto &e : p) {
    cin >> e;
    --e;
  }
  lli ans = 1;
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      string t;
      int j = i;
      for (; !used[j]; j = p[j]) {
        t += s[j];
        used[j] = 1;
      }
      lli c = (t + t).find(t, 1);
      ans = lcm(ans, c);
    }
  }
  cout << ans << '\n';
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