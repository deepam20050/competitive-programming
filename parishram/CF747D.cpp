#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

int a[N];
vector < pii > v;
int n, k;

int main () {
	scanf("%d %d", &n, &k);
	FOR(i, 1, n + 1) {
		scanf("%d", a + i);
	}
	int start = -1;
	FOR(i, 1, n + 1) {
		if (a[i] < 0) {
			start = i;
			break;
		}
	}
	if (start == -1) {
		puts("0");
		return 0;
	}
	int last = -1;
	int ans = 0;
	FOR(i, start, n + 1) {
		if (a[i] < 0) {
			--k;
			last = i + 1;
		} else {
			if (i == n) {
				ans += 1;
				v.eb(-1, n - last + 1);
			} else if (a[i + 1] < 0) {
				ans += 2;
				v.eb(-2, i - last + 1);
			}
		}
	}
	if (k < 0) {
		puts("-1");
		return 0;
	}
	sort(all(v));
	for (auto [x, y] : v) {
		if (y <= k) {
			ans += x;
			k -= y;
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}
