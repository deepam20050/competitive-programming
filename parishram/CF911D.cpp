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

const int N = 1505;

int arr[N];

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
  }
  int curr = 0;
  FOR(i, 1, n + 1) {
    FOR(j, i + 1, n + 1) {
      curr ^= arr[i] > arr[j];
    }
  }
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    int l, r;
    scanf("%d %d", &l, &r);
    curr ^= (r - l + 1 >> 1) & 1;
    curr ? puts("odd") : puts("even");
  }
  return 0;
}
