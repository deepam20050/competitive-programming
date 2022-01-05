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

const int N = 1e6 + 5;

lli sum[N];
int a, b, c, d;

int main () {
  scanf("%d %d %d %d", &a, &b, &c, &d);
  FOR(x, a, b + 1) {
    ++sum[x + b];
    --sum[x + c + 1];
  }
  FOR(i, 1, N) sum[i] += sum[i - 1];
  FOR(i, 1, N) sum[i] += sum[i - 1];
  lli ans = 0;
  FOR(z, c, d + 1) {
    ans += sum[N - 1] - sum[z];
  }
  printf("%lld\n", ans);
  return 0;
}
