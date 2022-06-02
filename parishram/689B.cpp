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

int to[N];
int dist[N];
bool used[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  memset(to, -1, sizeof to);
  FOR(i, 1, n + 1) {
    int x; cin >> x;
    to[i] = x;
  }
  queue < int > q;
  q.em(1);
  used[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u + 1 <= n && !used[u + 1]) {
      q.em(u + 1);
      used[u + 1] = 1;
      dist[u + 1] = dist[u] + 1;
    }
    if (u - 1 >= 1 && !used[u - 1]) {
      q.em(u - 1);
      used[u - 1] = 1;
      dist[u - 1] = dist[u] + 1;
    }
    if (to[u] != -1 && !used[to[u]]) {
      q.em(to[u]);
      used[to[u]] = 1;
      dist[to[u]] = dist[u] + 1;
    }
  }
  FOR(i, 1, n + 1) {
    cout << dist[i] << " ";
  }
  return 0;
}