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
char m[T][T];
int n;

void pr () {
	fori(i,0,n) {
		fori(j,0,n) 
			cout << m[i][j];
		cout << endl;
	}
	cout << endl;
}

int setN (int x, int y) {
	m[x][y] = 'R';
	int prox = x;
	for (int i = x+1; i < n; i++) {
		if (m[i][y] == 'X') { 
			prox = i;
			break;
		}
		m[i][y] = '#';
	}
	for (int i = y+1; i < n; i++) {
		if (m[x][i] == 'X') break;
		m[x][i] = '#';
	}

	for (int i = prox; i < n; i++) {
		if (m[i][y] == '.') return i;
	}

	return n;
}

void unset (int x, int y) {
	m[x][y] = '.';
	for (int i = x+1; i < n; i++) {
		if (m[i][y] == 'X') break;
		m[i][y] = '.';
	}
	for (int i = y+1; i < n; i++) {
		if (m[x][i] == 'X') break;
		m[x][i] = '.';
	}
}

int cont, ans;
bool sd = false;

void solve (int x, int y) {
	cout << x << " " << y << endl;
	if (y >= n){
		ans = max(cont, ans);
		return;
	}
	if (x >= n) {
		solve(0,y+1);
		return;
	}

	solve(x+1,y);

	if (m[x][y] == '.')  {
		cont++;
		int prox = setN(x,y);
		solve(prox,y);
		unset(x,y);
		cont--;
	}

	return;
}

/*
int solve (int x, int y) {
	if (y >= n) return 0;
	if (x >= n) return solve(0,y+1);

	if (m[x][y] != '.') return solve(x+1,y);
	int L = solve(x+1,y);

	int a = setN(x,y);
	int R = solve(a,y)+1;
	unset(x,y);

	return max(L,R);
}
*/ 

int main(){
    ios_base::sync_with_stdio(false);
	
	while(cin >> n) {
		fori(i,0,n)
			fori(j,0,n)
				cin >> m[i][j];

		//cout << solve(0,0) << endl;
		cont = 0; ans = 0; sd = false;
		solve(0,0);

		cout << ans << endl;

	}
	
    return 0;
}

