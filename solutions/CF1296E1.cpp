// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 250;

char s[N];
bool used[N];
int color[N];
vector < int > g[N];

void dfs (int u, int c) {
  used[u] = 1;
  color[u] = c;
  for (auto &to : g[u]) {
    if (!used[to]) dfs(to, c ^ 1);
    if (color[to] == c) {
      puts("NO");
      exit(0);
    }
  }
}

int main () {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  FOR(i, 0, n) FOR(j, i + 1, n) {
    if (s[i] > s[j]) {
      g[i].eb(j);
      g[j].eb(i);
    }
  }
  memset(color, -1, sizeof color);
  FOR(i, 0, n) if (color[i] == -1) {
    dfs(i, 0);
  }
  puts("YES");
  FOR(i, 0, n) printf("%d", color[i]);
  return 0;
}