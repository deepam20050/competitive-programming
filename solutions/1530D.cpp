#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

int used[N];
int deg[N];
int ans[N];
int a[N];
set < int > st;

void dfs (int u) {
  used[u] = 1;
  if (!used[a[u]]) {
    ans[u] = a[u];
    st.erase(a[u]);
    dfs(a[u]);
  } else if (used[a[u]] == 1 && st.find(a[u]) != st.end()) {
    ans[u] = a[u];
    st.erase(a[u]);
  }
  used[u] = 2;
}

void solveTestCase () {
  int n; scanf("%d", &n);
  FOR(i, 0, n) {
    deg[i] = 0;
    used[i] = 0;
    ans[i] = -1;
    st.em(i);
  }
  FOR(i, 0, n) {
    scanf("%d", a + i);
    --a[i];
    ++deg[a[i]];
  }
  FOR(i, 0, n) {
    if (deg[i] == 0) {
      dfs(i);
    }
  }
  FOR(i, 0, n) {
    if (!used[i]) {
      dfs(i);
    }
  }
  int k = 0;
  FOR(i, 0, n) k += ans[i] == a[i];
  printf("%d\n", k);
  int z = 0;
  FOR(i, 0, n) {
    if (ans[i] == -1) {
      if (*st.rbegin() == i) {
        ans[i] = *st.begin();
        st.erase(st.begin());
      } else {
        ans[i] = *st.rbegin();
        auto it = st.end();
        --it;
        st.erase(it);
      }
    }
    printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
  }
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}