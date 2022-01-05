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

priority_queue < pii, vector < pii >, greater < pii > > pq;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a != m * b) {
      cout << "NO\n";
      continue;
    }
    while (!pq.empty()) pq.pop();
    vector < string > ans(n, string(m, '0'));
    FOR(i, 0, m) {
      pq.emplace(0, i);
    }
    FOR(i, 0, n) {
      FOR(j, 0, a) {
        auto [cnt, col] = pq.top();
        pq.pop();
        ans[i][col] = '1';
        pq.emplace(cnt + 1, col);
      }
    }
    cout << "YES\n";
    for (auto &s : ans) cout << s << '\n';
  }
  return 0;
}