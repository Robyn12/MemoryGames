#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
void printArray_(int *a, int len) {
    for (int i = 0; i < len; i++) printf("%d", a[i]);
    printf("\n");
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

#define printArray(arr) printArray_((arr), sizeof(arr)/sizeof(arr[0]))
#define checkMatch(arr,barr,n) checkMatch_((arr),(barr),(n), sizeof(arr)/sizeof(arr[0]))

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

int main () {
	int a = 1;
	ClearScreen();
	while (a == 1) 
	{
		mainLoop();
		printf(" Wanna try again?\n 1. = Go again\n 2. = Quit\n ");
		scanf ("%d", &a);
	}
	return 0;
}
void mainLoop ()
{
	
	int n, answer, result;
	float seconds;
	unsigned int microseconds;
	printf (" How long integer string you want?\n ");
	scanf ("%d", &n);
	printf (" How fast (in seconds) ?\n ");
	scanf ("%f", &seconds);
	microseconds = seconds * 1000000.0;
	printf (" %d\n", microseconds);
	int myArray[n];
	int myAnswer[n];
	for (int i = 0; i < n; i++) {
		unsigned long seed = mix(clock(), time(NULL), getpid());
		srand( seed );
		myArray[i] = rand() % 10;
	}
	myArray[n] = '\0';
	for (int i = 0; i < n; i++) {
		ClearScreen();
		printf (" %d\n", myArray[i]);
		usleep(microseconds);
		ClearScreen();
		usleep(microseconds/2);
	}
	ClearScreen();
	printf (" Give me the answer:\n ");
	scanf ("%d", &answer);
	printf ("\n");
	
	for (int i = 0; i < n; i++) {
		myAnswer[n-(i+1)] = answer % 10;
		answer /= 10;
	}
	myAnswer[n] = '\0';
	int res = checkMatch(myAnswer, myArray, n);
	if (res > 0) {
		printf (" Wrong, the right answer is:\n ");
		printArray(myArray);
		printf (" And you Answered:\n ");
		printArray(myAnswer);
	} else {
		printf (" Correct the Answer is:\n ");
		printArray(myArray);
	}

}
void ClearScreen()
{
	int n;
	for (n = 0; n < 10; n++)
		printf ("\n\n\n\n\n\n\n\n");
}

