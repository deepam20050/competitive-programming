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

const int N = 1e6 + 5;

int lst[N];

int main () {
  int n;
  scanf("%d", &n);
  lli sum = 0;
  FOR(i, 1, n + 1) {
    int x;
    scanf("%d", &x);
    sum += (i - lst[x]) * 2ll * (n - i + 1) - 1ll;
    lst[x] = i;
  }
  printf("%.6lf\n", 1.0 * sum / (n * 1ll * n));
  return 0;
}
