#include <bits/stdc++.h>

long bigmodBinaryExponentiationRecursive(long a,long b,int m){

	if(b == 0) return 1 % M; 

	long ans=binaryExponentiationRecursive(a,b/2,m);

	ans = ans * ans % m;
	if(b % 2) ans = ans * a % m;

	return ans;
}

int main(){
	long a,b,m;

	std::cin>>a>>b>>m;

	long result1=bigmodBinaryExponentiationRecursive(long a,long b,long m);
	std::cout<< result1 << '\n';

	return 0;
}