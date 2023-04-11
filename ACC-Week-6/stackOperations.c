#include <stdio.h>
#include <string.h>
int main(){
	
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	char ch[1000];
	scanf("\n%s", ch);
	int ind = 0;
	int st[1000];
	for(int i = 0; i < n; i++)
		st[i] = -1;

	int top = -1;

	for(int i = 0; i < strlen(ch); i++){
		if (ch[i] == 'S'){
			top++;
			st[top] = a[ind];
			ind++;
		}
		else{
			
			st[top] = -1;
			top--;

		}
		
	}
	int flag = 0;
	for(int i = 0; i < n; i++){
		if (st[i] == -1){
			continue;
		}
		printf("%d ", st[i]);
		flag = 1;
	}
	if (flag== 0){
		printf("Stack Underflow");
	}

}
