/*
****************************************************************
****************************************************************
-> Coded by Stavros Chryselis				   
-> Visit my github for more solved problems over multiple sites 
-> https://github.com/StavrosChryselis			  
-> Feel free to email me at stavrikios@gmail.com	
****************************************************************
****************************************************************
*/

//This code is writtent like this due to byte limit of source code :P

#define s(v) scanf("%d",&v);
main(t,n,i,j){s(t)while(t--){s(n)int a[100][100];for(i=0;i<n;i++){for(j=0;j<=i;j++)s(a[i][j]) }for(i=n-2;i>=0;i--){for(j=0;j<=i;j++)a[i][j]+=a[i+1][j+1]>a[i+1][j]?a[i+1][j+1]:a[i+1][j];}printf("%d\n",a[0][0]);}} 
