#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pp(y,x,h) q.push(make_pair(y, make_pair(x, h)))

bool safe(int y, int x, int n, int m) {
	return 0 <= y && y < n && 0 <= x && x < m;
}

bool solve(const vector<vector<int> > & arr, const long long & mid, int n, int m) {
	int dx[] = {0, 0, -1, 1, 0, 0, -2, 2};
	int dy[] = {1, -1, 0, 0, 2, -2, 0, 0};
	vector<vector<vector<int> > > visited(n, vector<vector<int> > (m, vector<int>(2, 0)));
	visited[0][0][0] = 1;
	queue<pair<int, pair<int, int> > > q;
	if(arr[0][0] > mid) return false;
	pp(0,0,0);
	while(!q.empty()) {
		pair<int,pair<int,int> > f = q.front();
		if(f.first == n - 1 && f.second.first == m - 1) {
			return true;
		}
		q.pop();
		for(int i = 0 ; i < 8 ; ++i) {
			int y2 = f.first + dy[i];
			int x2 = f.second.first + dx[i];
			if(safe(y2, x2, n, m)) {
				if(arr[y2][x2] <= mid) {
					if(i >= 4 && f.second.second == 0 && visited[y2][x2][1] == 0) {
						pp(y2, x2, 1);
						visited[y2][x2][1] = 1;
					}
					else if(0 <= i && i < 4 && visited[y2][x2][f.second.second] == 0) {
						pp(y2, x2, f.second.second);
						visited[y2][x2][f.second.second] = 1;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > arr(n, vector<int>(m, 0));

	for(int i = 0 ; i < n ; ++i) {
		for(int j = 0 ; j < m ; ++j) {
			cin >> arr[i][j];
		}
	}

	long long lo = 0LL, hi = 1000000000LL;
	while(lo <= hi) {
		long long mid = (lo + hi) / 2;
		if(solve(arr, mid, n, m)) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << lo << endl;

	return 0;
	
}
