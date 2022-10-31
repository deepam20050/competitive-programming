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

const int N = 2005;

vector < pii > edges;
vector < int > s[2];
int dist[N];
int n;

void read (int node) {
  printf("? %d\n", node);
  fflush(stdout);
  FOR(i, 1, n + 1) {
    scanf("%d", dist + i);
  }
}

int main () {
  scanf("%d", &n);
  read(1);
  FOR(i, 2, n + 1) {
    s[dist[i] & 1].eb(i);
  }
  if (sz(s[0]) > sz(s[1])) swap(s[0], s[1]);
  FOR(i, 1, n + 1) {
    if (dist[i] == 1) {
      edges.eb(1, i);
    }
  }
  for (auto &node : s[0]) {
    read(node);
    FOR(i, 1, n + 1) {
      if (dist[i] == 1) {
        int a = node;
        int b = i;
        if (a > b) swap(a, b);
        edges.eb(a, b);
      }
    }
  }
  sort(all(edges));
  edges.erase(unique(all(edges)), edges.end());
  printf("!\n");
  for (auto &[a, b] : edges) {
    printf("%d %d\n", a, b);
  }
  return 0;
}
