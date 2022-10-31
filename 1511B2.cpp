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
template < class T > using min_heap = priority_queue < T, vector < T >, greater < T > >;
template < class T > using max_heap = priority_queue < T >;

const int N = 2e5 + 5;

vector < int > pos[N];
vector < int > places[N];
int ans[N];
int n, k;

void test_case() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    pos[i].clear();
    ans[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    pos[x].emplace_back(i);
  }
  function < bool (int) > f = [&] (int x) {
    if (x * 1ll * k > n) {
      return false;
    }
    min_heap < pii > pq;
    for (int i = 0; i < k; ++i) {
      places[i].clear();
      pq.emplace(0, i);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < min(sz(pos[i]), k); ++j) {
        auto [c, idx] = pq.top();
        pq.pop();
        places[idx].emplace_back(pos[i][j]);
        pq.emplace(c + 1, idx);
      }
    }
    return pq.top().first >= x;
  };
  int l = 1, r = N;
  for (int i = 0; i < 20; ++i) {
    int midx = l + r >> 1;
    if (f(midx)) {
      l = midx;
    } else {
      r = midx;
    }
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < l; ++j) {
      ans[places[i][j]] = i + 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
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
