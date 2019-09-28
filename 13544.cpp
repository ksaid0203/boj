#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define endl '\n'

const int MAX_N = 1 << 18;

vector<int> tree[MAX_N];

int solve(int node, int s, int e, int lo, int hi, int k) {
	if(lo >= e || hi <= s) {
		return 0;
	}
	if(lo <= s && e <= hi) {
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	}

	int mid = (s + e) / 2;
	return solve(node * 2, s, mid, lo, hi, k) + solve(node * 2 + 1, mid, e, lo, hi, k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0 ; i < n ; ++i ) {
		int x;
		cin >> x;
		tree[MAX_N/2 + i].push_back(x);
	}

	for(int i = MAX_N / 2 - 1; i > 0 ; --i) {
		vector<int> & c = tree[i], & l = tree[i * 2], & r = tree[i * 2 + 1];
		tree[i].resize(l.size() + r.size());
		for(int j = 0, p = 0, q = 0 ; j < c.size(); j ++) {
			if(q == r.size() || (p < l.size() && l[p] < r[q])) {
				c[j] = l[p++];
			}
			else {
				c[j] = r[q++];
			}
		}
	}

	int m;
	cin >> m;
	int l = 0;
	for(int i = 0 ; i < m ; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		l = solve(1, 0, MAX_N/2, (a^l) - 1, (b^l), c^l);
		cout << l << endl;
	}

	return 0;
}
