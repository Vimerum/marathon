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
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

map<string, int> cid; // cidades
map<string, int> sec; // sistemas economicos
map<int, ll> value; // cidade para valor
map<int, int> citec; // cidade para sistema economico 
map<int, vector<int>> viz; //sist economicos para cidades

struct node {
	ll v, q;
	bool operator < (const node &a) const {
		if(a.v != v) return v < a.v;
		else return q > a.q;
	}
};

const int N = 1e3+5;
node dp[N][N];
int endup;

node solve(int cup, int cdown) {
	node &r = dp[cup][cdown];
	if(cup == endup) return r = node({0, 0});
	if(r.v != -1) return r;
	
	node ans({0, INF});
	if (viz[citec[cup]][cdown]) {
		node at = solve(cup+1,cdown+1);
		at.v += value[cup] + value[cdown];
		at.q += 1;
		ans = max(at,ans);
	}
	/*for(int next:viz[citec[cup]]) {
		if(next >= cdown) {
			node at = solve(cup+1, next+1);
			at.v += value[cup] + value[next];
			at.q += 1;
			ans = max(at, ans);
		}
	}*/
	node t = solve(cup+1, cdown);

	return r = max(ans, t);
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int tc;
	cin >>tc;
	while(tc--) {
		int n; 
		cin >>n;

		//ZERANDO
		memset(dp, -1LL, sizeof dp);
		cid.clear();
		sec.clear();
		value.clear();
		citec.clear();
		viz.clear();

		int contc = 1, contse = 1;
		for(int i = 0; i < n; i++) {
			string a, b; ll v;
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
			string a, b; ll v;
			cin >>a >>b >>v;
			if(cid[a] == 0) cid[a] = contc++;
			if(sec[b] == 0) sec[b] = contse++;
			value[cid[a]] = v;
			citec[cid[a]] = sec[b];
			viz[sec[b]].pb(cid[a]);
		}
		
		solve(1, endup);

		cout <<dp[1][endup].v <<' ' <<dp[1][endup].q <<endl;
/*
		for(int i = 1; i < endup; i++) {
			for(int j = endup; j < contc; j++) {
				cout <<dp[i][j].v <<"->" <<dp[i][j].q <<"  ";
			}
			cout <<endl;
		}
*/
	}
	
    return 0;
}

