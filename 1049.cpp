#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int adj[51][2];

/* Dev-C++ is not familiar with me.*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	int guitarline_set = 10000, guitarline_one = 10000;
	for(int i = 0 ; i < m ;++i) {
		cin >> adj[i][0] >> adj[i][1];
		guitarline_set = min(guitarline_set, adj[i][0]);
		guitarline_one = min(guitarline_one, adj[i][1]);
	}
	int cand = 0, ret = 0;
	if(guitarline_set > guitarline_one * 6) {
		cout << guitarline_one * n << endl;
		return 0;
	}
	ret += (n / 6) * guitarline_set;
	ret += (n % 6) * guitarline_one;
	
	cand += ((n / 6) + 1) * guitarline_set;
	
	cout << min(ret, cand) << endl;
	return 0;
}
