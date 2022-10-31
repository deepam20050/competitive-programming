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

typedef long long lli;
typedef pair < int, int > pii;

map < int, int > cnt;
multiset < int > st;

void test_case() {
  int nq; cin >> nq;
  while (nq--) {
    int op; cin >> op;
    if (op == 1) {
      int x; cin >> x;
      ++cnt[x];
      st.emplace(x);
    } else if (op == 2) {
      int x, c; cin >> x >> c;
      int d = min(c, cnt[x]);
      cnt[x] -= d;
      while (d--) {
        st.erase(st.lower_bound(x));
      }
    } else {
      cout << *st.rbegin() - *st.begin() << '\n';
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  // cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}