#include <stdio.h>
#include <stdlib.h>
/***Упражнение 1.17**. Напишите программу печати всех вводимых строк, содержащих более 80 символов.*/
int main() {
	int sim = 0;
	char array[1000];
	int temp;
	int i;
	int j = 0;
	while ((temp = getchar()) != EOF)//
	{
		array[sim] = temp;
		sim++;
	}
	printf("vivod strok > 80 simvolov\n");
	for (i = 0;i <= sim;i++) {
		if (array[i] == '\n') {
			if (i - j > 80) {
				
				for (int b = 0; b < i - j; b++)putchar(array[j + b]);

				j = i ;
			}
			else { j = i ; }
		}
	}
	return 0;
}