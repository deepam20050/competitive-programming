// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

vector < int > g[N];
int deg[N];
vector < int > nodes;
int n;
set < int > st;
int done;
queue < int > q;

void solve () {
  while (!q.empty()) q.pop();
  FOR(i, 1, n + 1) {
    deg[i] = 0;
    g[i].clear();
  } 
  st.clear();
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    int k;
    scanf("%d", &k);
    deg[i] = k;
    if (!deg[i]) {
      st.insert(i);
    }
    while (k--) {
      int x;
      scanf("%d", &x);
      g[x].eb(i);
    }
  }
  int ans = 0;
  int p = -1;
  FOR(iter, 0, n) {
    if (st.empty()) {
      puts("-1");
      return;
    }
    auto it = st.lower_bound(p);
    if (it == st.end()) {
      ++ans;
      it = st.begin();
    }
    int u = *it;
    st.erase(u);
    for (auto &to : g[u]) {
      --deg[to];
      if (!deg[to]) {
        st.insert(to);
      }
    }
    p = u;
  }
  printf("%d\n", ans + 1);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
