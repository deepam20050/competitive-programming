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

int ask (int x, int y) {
  cout << "? " << x << " " << y << endl;
  int z;
  cin >> z;
  return z;
}

void test_case() {
  int n; cin >> n;
  int pos = 1;
  vector < int > ans(n + 1);
  for (int i = 2; i <= n; ++i) {
    int x = ask(i, pos);
    int y = ask(pos, i);
    if (y > x) {
      ans[pos] = y;
      pos = i;
    } else {
      ans[i] = x;
    }
  }
  ans[pos] = n;
  cout << "!";
  for (int i = 1; i <= n; ++i) {
    cout << " " << ans[i];
  }
  cout << endl;
}

int main() {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}
