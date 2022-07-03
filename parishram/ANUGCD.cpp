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

const int N = 1e5 + 2;
const int SQRTN = 320;

struct Query {
  int idx, l, r, lb, rb, g;
};

Query Q[N];
int a[N];
pii ans[N];

void add_element (int i, int g) {
  if ()
}

void remove_element (int i, int g) {

}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < nq; ++i) {
    int g, x, y; cin >> g >> x >> y;
    Q[i] = {i, x, y, x / SQRTN, y / SQRTN, g};
  }
  sort(Q, Q + nq, [&] (const Query &a, const Query &b) {
    if (a.lb != b.lb) {
      return a.lb < b.lb;
    }
    return a.lb & 1 ? a.r < b.r : a.r > b.r;
  });
  for (int i = 0, L = 1, R = 0; i < nq; ++i) {
    while (R < Q[i].r) add_element(++R);
    while (L > Q[i].l) add_element(--L);
    while (R > Q[i].r) remove_element(R--);
    while (L < Q[i].l) remove_element(L++);
    ans[Q[i].idx] = {};
  }
  for (int i = 0; i < nq; ++i) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }
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