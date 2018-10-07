/* compile with gcc alphabet.c -o alphabet -lm */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
 


char alphabet[6][5] = {
			{'a','b','c','d','e'},
			{'f','g','h','i','j'},
			{'k','l','m','n','o'},
			{'p','q','r','s','t'},
			{'u','v','w','x','y'},
			{'z'}
			};
char alphabetString[27] = { '-', 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}
int checkMatch_(int *a,int *b,int n, int len) {
        int count = 0;
        for (int i = 0; i < len; i++) {
                if (a[i] == b[i]) {
                        count++;
                }
        }
        if (count == n) {
                return 0;
        }
        else {
                return 1;
        }

}
#define checkMatch(arr,barr,n) checkMatch_((arr),(barr),(n), sizeof(arr)/sizeof(arr[0]))

int main () {
	mainLoop();
	return 0;
}
void showAlphabet()
{
	int d;
	ClearScreen();
	printf ("---------------------------------------------------------\n");
	printf ("\t  |\t");
	for (int cell = 1; cell < 6; cell++)
		printf("%d\t",cell);
	printf("|\n");
	for (int i = 0; i < 6; i++) {
		printf("\t%d |\t",i);
		for (int i2 = 0; i2 < 5; i2++) {
			printf("%c\t", alphabet[i][i2]);
		}
		printf("|\n");
	}
	printf ("---------------------------------------------------------\n");
	printf (" Give integer and go to Menu\n ");
	scanf("%d",&d);
}
void guessAlphabet() {
	char c;
	int d;
	unsigned long seed = mix(clock(), time(NULL), getpid());
	srand( seed );
	int luku = rand() % 26;
	luku++;
	printf(" Guess the character matching the number: %d\n ", luku);
	scanf(" %c", &c);
	printf("\n");
	if (c == alphabetString[luku])
		printf(" Correct\n");
	else {
		printf(" Wrong answer, because %c = ", alphabetString[luku]);
		printf(" %d\n", luku);
	}
	printf (" Give 1 and go to Menu\n");
	printf (" Or give 2 and go again.\n ");
	scanf("%d",&d);
	if (d == 2)
		guessAlphabet();
	
}
void guessRunning() {
	int d,i;
	unsigned long seed = mix(clock(), time(NULL), getpid());
	srand( seed );
	int luku = rand() % 26;
        luku++;
	printf(" Guess the running number of character %c\n ",alphabetString[luku]);
	scanf("%d", &i);
	printf("\n");
	if (luku == i)
		printf(" Correct!\n");
	else {
		printf(" Wrong answer, running number of %c", alphabetString[luku]);
		printf(" is %d\n", luku);
	}
	printf (" Give 1 and go to Menu\n");
        printf (" Or give 2 and go again.\n ");
        scanf("%d",&d);
        if (d == 2)
                guessAlphabet();
}
void guessMultiple() {
	int d, length, choice;
	printf(" How long sequence do you want?\n ");
	scanf("%d", &length);
	printf("\n");
	printf(" Do you want to guess running numbers (1) or characters (2)?\n ");
	scanf("%d", &choice);
	if (choice == 1)
		guessMultipleRunning(length);
	if (choice == 2)
		guessMultipleChar(length);
        printf (" Give (1) and go to Menu\n");
	printf (" Or give (2) and go again\n ");
        scanf("%d",&d);
	if (d == 2)
		guessMultiple();
}
void guessMultipleRunning(int len) {
	unsigned long seed = mix(clock(), time(NULL), getpid());
        srand( seed );
	int arr[len], answer[len];
	printf(" Here is your characters write numbers one at time.\n ");
	for (int i = 0; i < len; i++){
		int tmp = rand() % 26;
		tmp++;
		arr[i] = tmp;
	}
	for (int i = 0; i < len; i++)
		printf("%c ", alphabetString[arr[i]]);
	printf("\n");
	for (int i = 0; i < len; i++) {
		printf(" ");
		scanf("%d", &answer[i]);
	}
	int res = checkMatch(arr, answer, len);
	if (res > 0) {
		printf(" Wrong answer!, the correct answer is:\n ");
		for (int i = 0; i < len; i++)
			printf(" %d", arr[i]);
		printf("\n");
	} else
		printf(" Correct\n");

}
void guessMultipleChar(int len) {
        unsigned long seed = mix(clock(), time(NULL), getpid());
        srand( seed );
	int arr[len];
	char carr[len];
	printf(" Here is your running numbers write characters without spaces.\n ");
        for (int i = 0; i < len; i++)
                arr[i] = rand() % 26;
	for (int i = 0; i < len; i++)
		printf("%d ",arr[i]);
	printf("\n ");
	scanf("%s", &carr);
	int res = 1;
	for (int i = 0; i < len; i++){
		if (carr[i] != alphabetString[arr[i]])
			res = 0;
	}
	if (res == 1) 
		printf(" Correct!\n");
	if (res == 0) {
		printf(" Wrong!\n");
		printf(" Correct answer is:");
		for (int i = 0; i < len; i++)
			printf("%c", alphabetString[arr[i]]);
		printf("\n");
	}
}
void mainLoop ()
{
	while(1) {
		int choice;
		ClearScreen();
        	printf(" Main menu:\n");
        	printf(" 1. Show alphabet\n");
        	printf(" 2. Guess alphabet\n");
        	printf(" 3. Guess running number\n");
        	printf(" 4. Guess running number of multiple characters\n");
		printf(" 5. Quit\n ");
		scanf("%d", &choice);
		switch(choice) {
			case 1 :
				showAlphabet();
				continue;
			case 2 :
				guessAlphabet();
				continue;
			case 3 :
				guessRunning();
				continue;
			case 4 :
				guessMultiple();
				continue;
			case 5 :
				return;
		}
	}
}
void ClearScreen()
{
	int n;
	for (n = 0; n < 10; n++)
		printf ("\n\n\n\n\n\n\n\n");
}

