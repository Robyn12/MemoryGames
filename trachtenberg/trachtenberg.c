/* compile with gcc trachtenberg.c -o trachtenberg -lm */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

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
	
	
	int n,n2, answer, result;
	printf (" How long is bigger integer?\n ");
	scanf ("%d", &n);
	printf (" How big is smaller integer?\n ");
	scanf ("%d", &n2);
	unsigned long seed = mix(clock(), time(NULL), getpid());
	srand( seed );
	int luku1, luku2;
	luku1 = rand() % (int)pow((double)10, (double)n);
	luku2 = rand() % (int)pow((double)10, (double)n2);
	if (luku2 > luku1) {
		int tmp = luku1;
		luku1 = luku2;
		luku2 = tmp;
	}
	result = luku1*luku2;
	ClearScreen();
	time_t start = time(0);
	printf (" %d x %d = ",luku1,luku2);
	scanf ("%d", &answer);
	printf ("\n");
	double seconds = difftime( time(0), start);
	printf(" Answering took you %.0f seconds\n", seconds);
	if (result != answer) {
		printf(" Right answer is: %d\n", result);
		printf (" And you Answered: %d\n", answer);
	} else {
		printf (" Correct the Answer is:\n %d\n", result);
	}
	
}
void ClearScreen()
{
	int n;
	for (n = 0; n < 10; n++)
		printf ("\n\n\n\n\n\n\n\n");
}

