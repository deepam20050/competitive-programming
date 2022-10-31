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

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;

set < int > g[N];
int group[N];
vector < int > gg[N];

void rekt () {
  puts("-1");
  exit(0);
}

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  FOR(i, 0, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].em(b);
    g[b].em(a);
  }
  memset(group, -1, sizeof group);
  FOR(gc, 0, 3) {
    int fst = 1;
    while (fst <= n && group[fst] != -1) ++fst;
    if (fst == n + 1) rekt();
    group[fst] = gc;
    FOR(i, 1, n + 1) {
      if (i != fst && group[i] == -1 && g[fst].find(i) == g[fst].end()) {
        group[i] = gc;
      }
    }
  }
  FOR(i, 1, n + 1) {
    if (group[i] == -1) rekt();
    else gg[group[i]].eb(i);
  }
  int cnt = 0;
  FOR(i, 0, 3) FOR(j, i + 1, 3) for (auto &u : gg[i]) for (auto &to : gg[j]) {
    if (g[u].find(to) == g[u].end()) rekt();
    ++cnt;
  }
  if (cnt != m) rekt();
  FOR(i, 1, n + 1) {
    printf("%d ", group[i] + 1);
  }
  return 0;
}
