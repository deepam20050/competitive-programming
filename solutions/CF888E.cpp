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

const int N = 40;

int arr[N];
int tmp[N];
int n, m;
vector < int > sums[2];
int ans;

inline int add (int x, int y) {
  return (x + y) % m;
}

void solve (vector < int > &v, int op) {
  int len = sz(v);
  FOR(mask, 0, 1 << len) {
    int sum = 0;
    FOR(i, 0, len) {
      if (mask >> i & 1) {
        sum = add(sum, v[i]);
      }
    }
    sums[op].eb(sum);
  }
  sort(all(sums[op]));
}

int main () {
  scanf("%d %d", &n, &m);
  vector < int > v;
  FOR(i, 1, n / 2 + 1) {
    int x;
    scanf("%d", &x);
    v.eb(x);
  }
  solve(v, 0);
  v.clear();
  FOR(i, n / 2 + 1, n + 1) {
    int x;
    scanf("%d", &x);
    v.eb(x);
  }
  solve(v, 1);
  for (auto &x : sums[0]) {
    int req = m - x;
    int idx = lower_bound(all(sums[1]), req) - sums[1].begin();
    if (idx == sz(sums[1]) || idx == 0) {
      idx = sz(sums[1]) - 1;
    } else {
      --idx;
    }
    ans = max(ans, add(x, sums[1][idx]));
  }
  printf("%d\n", ans);
  return 0;
}
