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

const int N = 1e5 + 5;

int arr[N];
int n;

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
  }
  if (n == 1) {
    printf("1 1\n0\n1 1\n0\n\n1 1\n%d", -arr[1]);
  } else {
    printf("1 1\n%d\n1 %d\n0 ", -arr[1], n);
    FOR(i, 2, n + 1) {
      printf("%lld%c", -n * 1ll * arr[i], " \n"[i == n]);
    }
    printf("2 %d\n", n);
    FOR(i, 2, n + 1) {
      printf("%lld%c", (n - 1) * 1ll * arr[i], " \n"[i == n]);
    }
  }
  return 0;
}
