#include <bits/stdc++.h>
using namespace std;

bool primeNumber(int n){
	if(n<1) return false;
	for(int i=2;i<n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	if(primeNumber(n)) cout<< "Prime number!!!\n";
	else cout<< "Not prime number!!!\n";

	return 0;
}

//Time complexity O(n)

