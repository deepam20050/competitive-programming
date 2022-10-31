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
using pii = pair<int, int>;

const int N = 2e5 + 5;

int depth[N];
vector<pii> edges;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  FOR(i, 2, k + 2) {
    edges.eb(1, i);
    depth[i] = depth[1] + 1;
  }
  FOR(i, k + 2, n + 1) {
    edges.eb(i - k, i);
    depth[i] = depth[i - k] + 1;
  }
  printf("%d\n", depth[n] + depth[n - 1]);
  for (auto &[a, b] : edges) {
    printf("%d %d\n", a, b);
  }
  return 0;
}
