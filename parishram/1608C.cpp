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

const int N = 1e5 + 5;

bool ans[N];
vector < pii > v1, v2;
int n;
int a[N], b[N];

void dfs (int u) {
  ans[u] = 1;
  while (!v1.empty() && v1.back().F > a[u]) {
    int x = v1.back().S;
    v1.pop_back();
    dfs(x);
  }
  while (!v2.empty() && v2.back().F > b[u]) {
    int x = v2.back().S;
    v2.pop_back();
    dfs(x);
  }
}

void solveTestCase () {
  scanf("%d", &n);
  v1.clear(); v2.clear();
  v1.reserve(n); v2.reserve(n);
  FOR(i, 0, n) {
    ans[i] = 0;
    scanf("%d", a + i);
    v1.eb(a[i], i);
  }
  FOR(i, 0, n) {
    scanf("%d", b + i);
    v2.eb(b[i], i);
  }
  sort(all(v1)); sort(all(v2));
  dfs(v1.back().S);
  dfs(v2.back().S);
  FOR(i, 0, n) {
    ans[i] ? printf("1") : printf("0");
  }
  puts("");
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}