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

const int N = 2e5 + 5;

bool used[N];
int n;

inline int prev (int x) {
  --x;
  return x == -1 ? n - 1 : x;
}

inline int frnt (int x) {
  ++x;
  return x == n ? 0 : x;
}

void test_case() {
  cin >> n;
  string s; cin >> s;
  int c = count(all(s), '1');
  if (!c || (c & 1)) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  fill(used, used + n, 0);
  vector < int > even;
  int root = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      root = i;
    }
  }
  debug(root);
  used[root] = 1;
  for (int i : even) {
    if (used[i]) continue;
    used[i] = 1;
    cout << root + 1 << " " << i + 1 << '\n';
    int b = prev(i);
    int f = frnt(i);
    if (!used[b]) {
      used[b] = 1;
      cout << i + 1 << " " << b + 1 << '\n';
    } else if (!used[f]) {
      used[f] = 1;
      cout << i + 1 << " " << f + 1 << '\n';
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      cout << root + 1 << " " << i + 1 << '\n';
    }
  }
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