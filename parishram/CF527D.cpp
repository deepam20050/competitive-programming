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

pii arr[N];

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d %d", &arr[i].F, &arr[i].S);
  }
  sort(arr, arr + n, [] (const pii &L, const pii &R) {
      return L.F + L.S <= R.F + R.S;
      });
  int last = 0;
  int ans = 1;
  FOR(i, 1, n) {
    if (arr[i].F - arr[last].F >= arr[i].S + arr[last].S) {
      ++ans;
      last = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
