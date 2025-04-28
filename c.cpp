
#include <stdio.h>
#include <iostream>
//нужно напечатать содержимае ввода перемещать на каждую строку новое слово
int main() {
	
	int temp,sim, stroka, slova, flag;// переменные  флаг для слежки
	sim = stroka = slova = flag = 0;
	while ((temp = getchar()) != EOF) {
		if (temp == '\n')stroka++;
				if (temp == ' '||temp=='\n'||temp=='\t')
				{ 
					flag = 1;
					putchar('\n');
				}
		if (flag == 1)
		{
			slova++;
			flag = 0;
		}
		if (temp == '0')
					break;
				putchar(temp);

				sim++;
				
		}			
	printf("%d\t%d\t%d", sim, stroka, slova);
	
}