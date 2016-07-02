#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

char str[100001];

int sp1(int n){
	int s=1, way1=0, way0=0, i;

	for (i=0; i<n; i++){
		if (s){
			if (str[i] == '0') way1++;
			else way0++;
		} else {
			if (str[i] == '1') way1++;
			else way0++;
		}
		s = (!s);
	}
	s = (way1<=way0) ? 1 : 0; // prefer way1
	for (i=0; i<n; i++){
		if (s) str[i] = '1';
		else str[i] = '0';
		s = (!s);
	}

	return min(way1, way0);
}

int main(){
	int t, i, n, k, j;
	ios_base::sync_with_stdio(0);
	cin >> t;
	int cct, ans, ins, times;
	char s;

	while (t--){
		cin >> n >> k;
		scanf("%s", str);

		if (k==1){
			ans = sp1(n);
			printf("%d\n", ans);
			printf("%s\n", str);
			continue;
		}

		ans = 0;
		s = str[0]; cct=1; k++;
		str[n] = (str[n-1] == '1') ? '0' : '1';  // force last loop
		for (i=1; i<=n; i++){
			if (str[i] != s){
				s = str[i];
				if (cct >= k){
					times = cct/k;
					ans += times;
					if (cct == k)
						ins = k-2;
					else
						ins = k-1; // index wise
					ins = (i-cct)+ins;
					for (j=ins; j<i; j+=k)
						str[j] = s;
				}
				cct = 1;
			} else
				cct++;
		}

		printf("%d\n", ans);
		str[n] = '\0'; // switch it back to end
		printf("%s\n", str);
	}
	return 0;
}