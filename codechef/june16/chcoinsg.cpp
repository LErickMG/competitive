#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n;
	s(t);
	while (t--){
		s(n);
		if (n%6 == 0)
			printf("Misha\n");
		else
			printf("Chef\n");
	}
	return 0;
}