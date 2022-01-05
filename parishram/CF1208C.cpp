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

int main () {
  int n;
  scanf("%d", &n);
  vector < vector < int > > grid(n, vector < int > (n));
  int val = 0;
  FOR(i, 0, n / 2) {
    FOR(j, 0, n / 2) {
      grid[i][j] = 4 * val + 1;
      grid[i][j + n / 2] = 4 * val + 2;
      grid[i + n / 2][j] = 4 * val + 3;
      grid[i + n / 2][j + n / 2] = 4 * val;
      ++val;
    }
  }
  FOR(i, 0, n) FOR(j, 0, n) printf("%d%c", grid[i][j], " \n"[j == n - 1]);
  return 0;
}
