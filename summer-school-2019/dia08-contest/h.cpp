#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1010;
int n, m, vez;
char mat[T][T];
int vis[T][T];
int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool isIn(int x, int y) {
	return( x >= 0 and x < n and y >= 0 and y < m);
}

struct node { 
	int x,y,p; 

	node (int x, int y, int p) :
		x(x), y(y), p(p) {}
};

node best(const node &x, const node &y) {
	if(x.p > y.p) return x;
	return y;
}

node dfs(int x, int y, int p) {
	vis[x][y] = vez;
	node maxi = node(x,y,p);
	for(int i = 0; i < 4; i++) {
		int xx = x + mov[i][0];
		int yy = y + mov[i][1];
		if(isIn(xx,yy) and mat[xx][yy] == '.' and vis[xx][yy] != vez) 
			maxi = best(maxi, dfs(xx,yy,p+1));
	}
	return maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	node ori = node(0,0,0);
	while(tc--) {
		cin >> m >> n;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				cin >> mat[i][j];
				if(mat[i][j] == '.') ori = node(i,j,0);
			}
		vez++;
		ori = dfs(ori.x, ori.y, 0);
		vez++;
		ori = dfs(ori.x, ori.y, 0);
		cout <<"Maximum rope length is " << ori.p  <<'.' << endl;
	}	
    return 0;
}

