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

string str[N];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  FOR(i, 0, n) {
    cin >> str[i];
  }
  auto f = [] (string ss) -> lli {
    int s = 0, h = 0;
    lli res = 0;
    for (auto e : ss) {
      if (e == 's') ++s;
      else res += s;
    }
    return res;
  };
  sort(str, str + n, [&] (string s, string t) {
      return f(s + t) > f(t + s);
      });
  string s = "";
  FOR(i, 0, n) s += str[i];
  cout << f(s) << '\n';
  return 0;
}

