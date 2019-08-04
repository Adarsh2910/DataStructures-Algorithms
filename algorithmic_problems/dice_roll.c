/**
 * Dice Throw DP-30
 *
 * @author Adarsh Bhalotia
 */

#include<stdio.h>
#include<string.h>

int table[10][100];

int getSumWays2(int n, int m, int x) {
	if(n==0)
		return x==0;

	int res = 0;

	if(table[n][x]==0) {
		for(int i=1;i<=m;i++)
			table[n][x]+= getSumWays2(n-1,m,x-i);
	}

	return table[n][x];
}

int main() {
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	int count=getSumWays2(n,m,x);
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= x ;j++){
			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
	printf("%d",count);
	return 0;
}
