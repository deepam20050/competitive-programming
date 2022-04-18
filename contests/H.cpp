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

int main () {
  int p[] = {500, 4, 3, 2, 10000};
  int f[] = {10, 200, 40, 50, 30};
  FOR(i, 0, 5) {
    cout << double(p[i] * f[i]) << " ";
  }
  cout << '\n';
  int perm[] = {0, 1, 2, 3, 4};
  int curr = 2e9;
  vector < int > v(5);
  do {
    int x = f[perm[0]] + p[perm[0]];
    int mx = x;
    FOR(i, 1, 5) {
      x += f[perm[i - 1]] + f[perm[i]] + p[perm[i]];
      mx = max(mx, x);
    }
    if (mx < curr) {
      FOR(i, 0, 5) {
        v[i] = perm[i];
        cout << perm[i] << " ";
      }
      cout << '\n';
      curr = mx;
    }
  } while (next_permutation(perm, perm + 5));
  for (auto &e : v) {
    cout << e << " ";
  }
  puts("");
  return 0;
}
