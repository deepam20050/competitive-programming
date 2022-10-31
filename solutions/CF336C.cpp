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

const int N = 1e5 + 5;

int arr[N];

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d", arr + i);
  }
  for (int i = 29; i >= 0; --i) {
    int total = (1 << 30) - 1;
    vector < int > v;
    FOR(j, 0, n) {
      if (arr[j] >> i & 1) {
        total &= arr[j];
        v.eb(arr[j]);
      }
    }
    if (total % (1 << i) == 0) {
      printf("%d\n", sz(v));
      for (auto &e : v) {
        printf("%d ", e);
      }
      return 0;
    }
  }
  return 0;
}
