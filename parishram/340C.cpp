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

int arr[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  FOR(i, 1, n + 1) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + n + 1);
  lli num = 0;
  lli denom = n;
  FOR(i, 1, n + 1) {
    lli d = arr[i] * 1ll + ((i - 1) * 2ll * arr[i]);
    lli e = ((n - i) * 2ll * arr[i]);
    num += d - e;
  }
  lli g = __gcd(num, denom);
  if (g != 0) {
    num /= g;
    denom /= g;
  }
  cout << num << " " << denom << '\n';
  return 0;
}