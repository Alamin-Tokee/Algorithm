#include <bits/stdc++.h>
using namespace std;

int countFactorialDigit(int n){
	if(n<0) return 0;

	if(n<=1) return 1;

	double d=0;
	for(int i=2;i<=n;i++){
		d+=log10(i);
	}
	return floor(d)+1;
}

int main(){
	int n;
	cin>>n;

	cout<<countFactorialDigit(n)<<'\n';

	return 0;
}