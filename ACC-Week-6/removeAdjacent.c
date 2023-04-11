#include <stdio.h>
#include <string.h>

int main(){
	
	char ch[1000];
	scanf("%s", ch);

	char st[strlen(ch)];
	for(int i = 0; i < strlen(ch); i++)
		st[i] = '0';
	int top = -1;
	
	top++;
	st[top] = ch[0];
	for(int i = 1; i < strlen(ch); i++){

		if(ch[i] != st[top]){
			top++;
			st[top] = ch[i];

		}
		else{
			st[top] = '0';
			top--;

		}

	}
	int flag = 0;
	for(int i = 0; i < strlen(ch); i++){
		if(st[i] == '0')
			continue;
		printf("%c<->", st[i]);
		flag = 1;
	}
	if(flag == 1)
		printf("NULL");
	else
		printf("List is Empty");
}
