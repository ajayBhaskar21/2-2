

//  Construct a DFA which accepts all the strings
//  which ends with '00' or '11'.


//
//                                     [0]
//                          ------------------------
//		               [0]  |   [0]        [0]     ^   
//       ----->> (q0) --->(q1) ---> ((q3))-----    ^
//                |    [0] ^|       |  ^      |    ^
//            [1] |    ----||[1]    |  |-------    ^
//                |   |     |       |              ^
//                > (q2) <---       |            ((q4))------
//                   | ^            |              ^ ^      | [1]
//                   | |------------               | ^-------
//                   |       [1]                   |
//                   >-----------------------------
//                                  [1]
//
//				where, ()   indicate states
//       			   []   indicate input transitions
//       			   >>   initial state
//       			   (()) indicate final states
//


#include <stdio.h>
#include <string.h>

int main(){
	
	char ch[100];
	
	printf("Enter a string with 0's and 1's: ");
	scanf("%s", ch);

	int j = 0;
	for (int i = 0; i < strlen(ch); i++){
		if (j == 0){
			if (ch[i] == '0')
				j = 1;
			else
				j = 2;
		}
		else if (j == 1){
			if (ch[i] == '0')
				j = 3;
			else
				j = 2;
		}
		else if (j == 2){
			if (ch[i] == '0')
				j = 1;
			else
				j = 4;
		}
		else if (j == 3){
			if (ch[i] == '0')
				j = 3;
			else
				j = 2;
		}
		else if (j == 4){
			if (ch[i] == '0')
				j = 1;
			else
				j = 4;
		} 
	}
	
	if (j == 3 || j == 4){
		printf("Given string is accepted because it ends with '00' or '11'.");
	}
	else
		printf("Given string is rejected because it does not ends with '00' or '11'.");


}
