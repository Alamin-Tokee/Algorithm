#include <bits/stdc++.h>

long bigmodBinaryExponentiationRecursive(long a,long b,int m){

	if(b == 0) return 1 % m; 

	long ans=binaryExponentiationRecursive(a,b/2,m);

	ans = ans * ans % m;
	if(b % 2) ans = ans * a % m;

	return ans;
}
long bigmodBinaryExponentiationIterative(long a,long b,long m){
	a = a % m;
	long ans = 1;
	while(b > 0){
		if(b & 1)
			ans=ans * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}

int main(){
	long a,b,m;

	std::cin>>a>>b>>m;

	long result1=bigmodBinaryExponentiationRecursive(long a,long b,long m);
	long result2=bigmodBinaryExponentiationIterative(long a,long b,long m);

	std::cout<< result1 << " " << result2 << '\n';

	return 0;
}