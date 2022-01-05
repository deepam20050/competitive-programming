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

const int N = 4e5 + 5;

int d[N];
lli B[N], C[N];

lli sum (int x) {
  return x * 1ll * (x + 1) >> 1ll;
}

int main () {
  int n;
  lli x;
  scanf("%d %lld", &n, &x);
  FOR(i, 0, n) scanf("%d", d + i), d[n + i] = d[i];
  lli ans = 0;
  n += n;
  FOR(i, 0, n) {
    B[i + 1] = B[i] + d[i];
    C[i + 1] = C[i] + sum(d[i]);
  }
  FOR(i, 0, n) {
    if (B[i + 1] >= x) {
      int z = upper_bound(B, B + n + 1, B[i + 1] - x) - B;
      lli cnt = C[i + 1] - C[z];
      lli days = B[i + 1] - B[z];
      int left = x - days;
      cnt += sum(d[z - 1]);
      cnt -= sum(d[z - 1] - left);
      ans = max(ans, cnt);
    }
  }
  printf("%lld\n", ans);
  return 0;
}