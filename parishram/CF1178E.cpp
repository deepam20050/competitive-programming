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

string s;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  string t, mid;
  int l = 0, r = sz(s) - 1;
  while (l < r) {
    if (r - l + 1 <= 3) {
      mid += s[l];
      break;
    }
    FOR(i, 0, 3) {
      char x = i + 'a';
      if ((x == s[l] || x == s[l + 1]) && (x == s[r] || x == s[r - 1])) {
        t += string(1, x);
        break;
      }
    }
    l += 2;
    r -= 2;
  }
  string rev = t;
  reverse(all(rev));
  cout << t + mid + rev << '\n';
  return 0;
}
