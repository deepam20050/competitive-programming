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

const int M = 505;

pii edges[M];
int n, m;
int sum[M];

int ask (const string &s) {
  cout << "? " << s << endl;
  int x; cin >> x;
  return x;
}

void test_case() {
  cin >> n >> m;
  string s(m, '0');
  for (int i = 0; i < m; ++i) {
    s[i] = '1';
    edges[i] = {ask(s), i};
    s[i] = '0';
  }
  sort(edges, edges + m);
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    auto [len, idx] = edges[i];
    s[idx] = '1';
    sum[i + 1] = ask(s);
    if (sum[i + 1] == sum[i] + len) {
      ans += len;
    }
  }
  cout << "! " << ans << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}