
#include <stdio.h>
#include <iostream>
#define IN 1 /* внутри слова */

#define OUT 0 /* вне слова */


/*Упражнение 1.13.Напишите программу, печатающую гистограммы
длин вводимых слов.Гистограмму легко рисовать горизонтальными полосами.
Рисование вертикальными полосами - более трудная задача.*/
using namespace std;
// пункт первый нужно составить план и вообще научиться состовлять последовательность написания
int main() {
	int sim, slova, temp,state;
	sim = slova = temp = 0;
	state = 0;
	int agge[12] = { 0 };
	while ((temp = getchar()) != EOF) {
		if (temp == '`') {
			if (state == IN) {
				for (int i = 0; i < 12; i++)
				{
					if (sim == i) ++agge[i];
				}
				sim = 0;
			}
			break;
		}
			if (temp != ' ' && temp != '\t' && temp != '\n')sim++;
		if (temp == ' ' || temp == '\t' || temp == '\n') {
			state = OUT;
			
		}
		else if (state == OUT){
			state = IN;
			slova++;

		}
		
		if (sim >0 && state == OUT)
		{   
			for (int i = 0; i < 12; i++)
			{
				if (sim == i) ++agge[i];
			}
			sim = 0;
		}
		
		
		




		



	}
	/*for (int i = 0; i < 12;i++)
		printf("%d\n", agge[i]);
		cout << "sim " << sim << endl;;*/
	cout << "slova " << slova << endl;


	for (int i = 0; i < 12;i++) {
		printf("bukb: %d slov:  ",i);
		printf("%d  ",agge[i]);
		int j = agge[i];
			while (j>0 ) {
				putchar('@');
				putchar('@');
				j--;
			}
		printf("\n");
	}

	return 0;
}