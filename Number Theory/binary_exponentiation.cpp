#include <bits/stdc++.h>

long binaryExponentiationRecursive(long a,long b){

	if(b==0) return 1;

	long ans=binaryExponentiationRecursive(a,b/2);

	if(b%2){
		ans*ans*a;
	}else{
		ans*ans;
	}

	return ans;
}

int main(){
	long a,b;

	std::cin>>a>>b;

	long result=binaryExponentiationRecursive(long a,long b);

	std::cout<< result << '\n';
}