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

const int N = 2e5 + 5;

vector < int > v;
tuple < int, int, int > arr[N];
int n;
int max_time;
int t[N], a[N];

bool f (int k) {
  v.clear();
  FOR(i, 0, n) {
    if (get<1>(arr[i]) >= k) {
      v.eb(get<2>(arr[i]));
    }
  }
  if (sz(v) < k) {
    v.clear();
    return 0;
  }
  int sum = 0;
  FOR(i, 0, k) {
    sum += t[v[i]];
  }
  v.resize(k);
  return sum <= max_time;
}

int main () {
  scanf("%d %d", &n, &max_time);
  FOR(i, 0, n) {
    scanf("%d %d", a + i, t + i);
    arr[i] = {t[i], a[i], i};
  }
  sort(arr, arr + n);
  int l = 0, r = N, ans = 0;
  FOR(i, 0, 20) {
    int m = l + r >> 1;
    if (f(m)) {
      ans = m;
      l = m; 
    } else {
      r = m;
    }
  }
  printf("%d\n%d\n", ans, sz(v));
  for (auto &e : v) printf("%d ", e + 1);
  return 0;
}
