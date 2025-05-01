#include <stdio.h>
/***Упражнение 1.18**. Напишите программу, которая будет в каждой
вводимой строке заменять стоящие подряд символы пробелов и табуляций
на один пробел и удалять пустые строки.*/
int main() 	
{	
	int temp=0;
	char flag = 0;
	char flag_strok = 0;
	while ((temp = getchar()) != EOF) {
			if (temp == '\n') {
					if (flag_strok == 1) {
						putchar('\n');
						flag_strok = 0;
					}
				flag = 0;
			}
		
			else if (temp == ' ' || temp == '\t') {
					if (flag == 1) ;
				else {
						if (flag_strok == 1) {
							putchar(' ');
							flag = 1;
						}
			}
					
			

		}
		else { putchar(temp);
		flag_strok = 1;
		flag = 0;
		}

	}

	return 0;
}