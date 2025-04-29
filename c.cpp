#include <stdio.h>
/** Упражнение 1.15 * *.Перепишите программу преобразования 
температур, выделив само преобразование в отдельную функцию.*/
float Transform(float c) {
	return c * 1.8 + 32;
}
int main() {

	for (float max = 150, min = -50, C_celsies = -50;  max > min ;C_celsies +=20,min+=20) {
		printf("C: %5.1f\t F: %.1f\n", min, Transform(C_celsies));
	}
	return 0;
}