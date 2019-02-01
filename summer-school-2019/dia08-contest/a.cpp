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

int toint(string s) {
	int num = 0;
	int dec = 1;
	for(int i = s.size()-1; i >= 0; i--) {
		num += (s[i]-'0')*dec;
		dec *= 10;
	}
	return num;
}

vector<int> convert(string s) {
	vector<int> v;
	string num = "";
	int neg = 1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ' ') {
			v.pb(toint(num)*neg);
			num = "";
			neg = 1;
		}
		else if(s[i] == '-') 
			neg = -1;
		else {
			num += s[i];
		}
	}
	v.pb(toint(num)*neg);
	return v;
}

int main(){
    ios_base::sync_with_stdio(false);
	string s;
	while(getline(cin,s)) {
		vector<int> v = convert(s);
		int sum = 0, maior = 0;
		for(int i = 0; i < v.size(); i++) {
			sum += v[i];
			if(sum < 0) sum = 0;
			if(sum > maior) maior = sum;
		}
		cout <<maior <<endl;
	}
    return 0;
}

