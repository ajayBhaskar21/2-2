#include <stdio.h>


int main(){

	int n;
	scanf("%d", &n);

	int a[1000];
	int z = 0;
	int t;
	while(n--){
		scanf("%d", &t);
		int t1;
		for(int i = 0; i < t; i++){
			scanf("%d", &t1);
			a[z++] = t1;

		}
		
	}
	for(int i = 0; i < z; i++)
		printf("%d ", a[i]);
	


}
