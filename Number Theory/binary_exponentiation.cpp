#include <bits/stdc++.h>

long binaryExponentiationRecursive(long a,long b){

	if(b == 0) return 1;

	long ans = binaryExponentiationRecursive(a, b/2);

	if(b % 2){
		ans * ans * a;
	}else{
		ans * ans;
	}

	return ans;
}

long binaryExponentiationIterative(long a,long b){

	long ans = 1;
	while(b > 0){
		if(b & 1)
			ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int main(){
	long a,b;

	std::cin>>a>>b;

	long result1=binaryExponentiationRecursive(long a,long b);
	long result2=binaryExponentiationIterative(long a,long b);

	std::cout<< result1 << " " << result2 << '\n';

	return 0;
}