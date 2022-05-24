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

const int N = 1e5 + 5;

tuple < int, int, int > arr[N];

int main () {
  int n; scanf("%d", &n);
  FOR(i, 0, n) {
    auto &[x, y, idx] = arr[i];
    scanf("%d %d", &x, &y);
    idx = i;
  }
  sort(arr, arr + n);
  FOR(z, 0, n) {
    auto [x1, y1, i] = arr[z];
    auto [x2, y2, j] = arr[z + 1];
    auto [x3, y3, k] = arr[z + 2];
    lli area = x1 * 1ll * (y2 - y3) + x2 * 1ll * (y3 - y1) + x3 * 1ll * (y1 - y2);
    if (area != 0) {
      printf("%d %d %d\n", i + 1, j + 1, k + 1);
      exit(0);
    } 
  }
  return 0;
}