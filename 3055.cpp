#include <queue>
#include <string>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
vector<string> adj;

/* It was editted by Dev-C++ 5.11. */

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

bool visited[51][51];

int bfs(int r, int c) {
	int date = 0;
	pair<int, int> dest;	// destination
	pair<int, int> source;	// source
	queue<pair<int, int> > water1;	// water in n day
	for(int i = 0; i < r; ++i) {
		for(int j = 0 ; j < c; ++j) {
			if(adj[i][j] == 'S') {
				source.first = i;
				source.second = j;
			}
			else if(adj[i][j] == 'D') {
				dest.first = i;
				dest.second = j;
			}
			else if(adj[i][j] == '*') {
				water1.emplace(i,j);
			}
		}
	}
	queue<pair<int, int> > beaver1;	// beaver in n day
	queue<pair<int, int> > beaver2;	// beaver in (n + 1) day
	queue<pair<int, int> > water2;	// water in (n + 1) day
	beaver1.emplace(source);
	while(!beaver1.empty()) {
		while(!water1.empty()) {
			int y = water1.front().first;
			int x = water1.front().second;
			water1.pop();
			for(int i = 0 ; i < 4; ++i) {
				int y2 = y + dy[i];
				int x2 = x + dx[i];
				if(0 <= y2 && y2 < r && 0 <= x2 && x2 < c && adj[y2][x2] != '*' && adj[y2][x2] != 'X' && adj[y2][x2] != 'D') {
					adj[y2][x2] = '*';
					water2.emplace(y2, x2);
				}
			}
		}
		while(!water2.empty()) {
			water1.push(water2.front());
			water2.pop();
		}
		while(!beaver1.empty()) {
			int y = beaver1.front().first;
			int x = beaver1.front().second;
			beaver1.pop();
			if(y == dest.first && x == dest.second) {
				return date;
			}
			for(int i = 0 ; i < 4; ++i) {
				int y2 = y + dy[i];
				int x2 = x + dx[i];
				if((0 <= y2 && y2 < r && 0 <= x2 && x2 < c && adj[y2][x2] != 'S' && adj[y2][x2] != 'X' && adj[y2][x2] != '*')) {
					if(y2 == dest.first && x2 == dest.second) {
						return date + 1;
					}
					adj[y2][x2] = 'S';
					beaver2.emplace(y2, x2);
				}
			}
		}
		while(!beaver2.empty()) {
			beaver1.emplace(beaver2.front());
			beaver2.pop();
		}
		++date;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int r, c;
	cin >> r >> c;
	adj.resize(r);
	for(int i = 0 ; i < r; ++i)
		cin >> adj[i];
	
	int ret = bfs(r, c);
	if(ret == -1) cout << "KAKTUS" << endl;
	else cout << ret << endl;
	
	return 0;
}
