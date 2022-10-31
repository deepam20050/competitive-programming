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

const int N = 1e5 + 5;

int cnt[N];
multiset < int, greater < int > > s;

void test_case() {
  int n; cin >> n;
  int cnt2 = 0, cnt4 = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    cnt2 -= cnt[x] / 2;
    cnt4 -= cnt[x] / 4;
    ++cnt[x];
    cnt2 += cnt[x] / 2;
    cnt4 += cnt[x] / 4;
  } 
  int nq; cin >> nq;
  while (nq--) {
    char c; int x; cin >> c >> x;
    cnt2 -= cnt[x] / 2;
    cnt4 -= cnt[x] / 4;
    if (c == '+') {
      ++cnt[x];
    } else {
      --cnt[x];
    }
    cnt2 += cnt[x] / 2;
    cnt4 += cnt[x] / 4;
    cnt4 >= 1 && cnt2 >= 4 ? cout << "YES\n" : cout << "NO\n";
  }
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