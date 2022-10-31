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

int a[N];
vector < int > where[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  FOR(i, 1, n + 1) {
    cin >> a[i];
    where[a[i]].eb(i);
  }
  if (where[q].empty()) {
    if (where[0].empty()) {
      cout << "NO\n";
      exit(0);
    }
    int x = where[0].back();
    where[0].pop_back();
    a[x] = q;
    where[q].eb(x);
  }
  set < int > visited;
  FOR(i, 1, q + 1) {
    if (where[i].empty()) continue;
    auto it = visited.ub(where[i][0]);
    if (it != visited.end() && *it < where[i].back()) {
      cout << "NO\n";
      exit(0);
    }
    for (auto j : where[i]) {
      visited.em(j);
    }
  }
  cout << "YES\n";
  FOR(i, 1, n + 1) {
    if (a[i] == 0) {
      if (i > 1) {
        a[i] = a[i - 1];
      } else {
        int j = i;
        while (a[j] == 0) {
          ++j;
        }
        a[i] = a[j];
      }
    }
    cout << a[i] << " ";
  }
  return 0;
}