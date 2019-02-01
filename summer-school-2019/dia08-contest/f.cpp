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

map<string, int> cid; // cidades
map<string, int> sec; // sistemas economicos
map<int, int> value; // cidade para valor
map<int, int> citec; // cidade para sistema economico 
map<int, vector<int>> viz; //sist economicos para cidades

const int N = 1e3+5;
int ansV = 0, ansP = INF;
int dp[N][N];
int dp2[N][N];
int endup;
int cont;

int solve(int cup, int cdown) {
	int &r = dp[cup][cdown];
	if(cup == endup) return r = 0;
	if(r != -1) return r;
	
	int ans = 0;
	for(int next:viz[citec[cup]]) {
		if(next >= cdown) {
			int at = solve(cup+1, next+1) + value[cup] + value[next];
			ans = max(at, ans);
		}
	}
	int t = solve(cup+1, cdown);

	return r = max(ans, t);
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int tc;
	cin >>tc;
	while(tc--) {
		int n; 
		
		cin >>n;
		cont = 0;
		memset(dp, -1, sizeof dp);
		memset(dp, INF, sizeof dp);

		int contc = 1, contse = 1;
		for(int i = 0; i < n; i++) {
			string a, b; int v;
			cin >>a >>b >>v;
			if(cid[a] == 0) cid[a] = contc++;
			if(sec[b] == 0) sec[b] = contse++;
			value[cid[a]] = v;
			citec[cid[a]] = sec[b];
			viz[sec[b]].pb(cid[a]);
		}
		endup = contc;
		cin >>n;
		for(int i = 0; i < n; i++) {
			string a, b; int v;
			cin >>a >>b >>v;
			if(cid[a] == 0) cid[a] = contc++;
			if(sec[b] == 0) sec[b] = contse++;
			value[cid[a]] = v;
			citec[cid[a]] = sec[b];
			viz[sec[b]].pb(cid[a]);
		}
		
		cout <<solve(1, endup)<<' ' <<endl;

		for(int i = 1; i < endup; i++) {
			cout <<i <<"-> ";
			for(int j = endup; j < contc; j++) {
				cout <<dp[i][j] <<' ';
			}
			cout<<endl;
		}
	}
	
    return 0;
}

