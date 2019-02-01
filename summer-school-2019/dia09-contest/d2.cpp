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
const int T = 105;
char mat[T][T];
int n;


int solve(int x, int y, bitset<T> hori, bitset<T> vert) {
	if(y == n) { y = 0; x++; hori >>= 1;} 
	if(x == n) return 0;


	if(mat[x][y] == 'X') { hori.set(x,false); vert.set(y,false); }

	int ans = solve(x, y+1, hori, vert);
	if(mat[x][y] == '.' and hori[x] == false and vert[y] == false) 
		ans = max(ans, solve(x, y+1, (hori.set(x,true)), (vert.set(y,true)) >> 1) + 1);
	return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	while(cin >> n) {
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> mat[i][j];
		bitset<T> hori;
		bitset<T> vert;
		cout << solve(0,0,hori,vert) << endl;
	}
    return 0;
}

