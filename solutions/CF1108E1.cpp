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

const int N = 305;

int arr[N], tmp[N], l[N], r[N];

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
  }
  FOR(i, 0, m) {
    scanf("%d %d", l + i, r + i);
  }
  int mx = *max_element(arr + 1, arr + n + 1) - *min_element(arr + 1, arr + n + 1);
  int req = -2e9;
  FOR(i, 1, n + 1) {
    FOR(j, 1, n + 1) tmp[j] = arr[j];
    FOR(j, 0, m) {
      if (!(l[j] <= i && i <= r[j])) {
        FOR(k, l[j], r[j] + 1) --tmp[k];
      }
    }
    int res = *max_element(tmp + 1, tmp + n + 1) - *min_element(tmp + 1, tmp + n + 1);
    if (mx < res) {
      mx = res;
      req = i;
    }
  }
  printf("%d\n", mx);
  vector < int > ans;
  if (req == (int)-2e9) {
    puts("0");
    return 0;
  }
  FOR(i, 0, m) {
    if (!(l[i] <= req && req <= r[i])) {
      ans.eb(i + 1);
    }
  }
  printf("%d\n", sz(ans));
  for (auto &e : ans) printf("%d ", e);
  return 0;
}
