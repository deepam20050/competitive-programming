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

int b[N], pref[N], suff[N];

void test_case() {
  int n; cin >> n;
  lli s = 0;
  for (int i = 1; i <= n + 2; ++i) {
    cin >> b[i];
    pref[i] = max(pref[i - 1], b[i]); 
    s += b[i];
  }
  suff[n + 3] = 0;
  for (int i = n + 2; i >= 1; --i) {
    suff[i] = max(suff[i + 1], b[i]);
  }
  vector < int > a;
  for (int i = 1; i <= n + 2; ++i) {
    if (!((s - b[i]) & 1)) {
      lli val = s - b[i] >> 1ll;
      debug(s, val);
      if (pref[i - 1] == val || suff[i + 1] == val) {
        for (int j = 1; j <= n + 2; ++j) {
          if (j != i) {
            a.emplace_back(b[j]);
          } 
        }
        break;
      } else {
        continue;
      }
    }
  }
  if (sz(a) <= 1) {
    cout << "-1\n";
    return;
  }
  sort(all(a));
  a.pop_back();
  for (auto &e : a) {
    cout << e << " ";
  }
  cout << '\n';
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