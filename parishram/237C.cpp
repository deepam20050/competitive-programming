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

const int N = 1e6 + 5;

int pref[N];
bool p[N];
int a, b, k; 

bool f (int l) {
  FOR(x, a, b - l + 2) {
    int c = pref[x + l - 1] - pref[x - 1];
    if (c < k) return 0;
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  FOR(i, 2, N) {
    for (int j = i + i; j < N; j += i) p[j] = 1;
    pref[i] = pref[i - 1] + !p[i];
  }
  cin >> a >> b >> k;
  int l = 1, r = b - a + 1;
  if (!f(r)) {
    cout << "-1\n";
    exit(0);
  }
  FOR(i, 0, 20) {
    int midx = l + r >> 1;
    if (f(midx)) {
      r = midx;
    } else {
      l = midx;
    }
  }
  cout << r << '\n';
  return 0;
}