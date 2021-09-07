 int used[20],number[20];

 void permutation(int at,int n){
 	if(at==n+1){
 		for(int i=1;i<=n;i++)
 			printf("%d ",number[i]);
 		printf("\n");
 		return;
 	}

 	for(int i=1;i<=n;i++){
 		if(!used[i]){
 			used[i]=1;
 			number[i]=i;
 			permutation(at+1,n);
 			used[i]=0;
 		}
 	}
 }