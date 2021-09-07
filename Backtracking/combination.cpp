 int number[20];
 int n,k;
 
 void combination(int at,int last){
 	if(at==k+1){
 		for(int i=1;i<=k;i++)
 			printf("%d ",number[i]);
 		printf("\n");
 		return;
 	}

 	for(int i=last+1;i<=n-k+at;i++){
 		number[at]=i;
 		combination(at+1,i);
 	}
 }