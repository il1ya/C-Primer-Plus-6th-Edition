#include <stdio.h>
/* Напишите программу, которая читает число с плавающей запятой и выводит его сначала в десятичной, а затем в экспоненциальной форме.
Предусмотрите вывод в следующих форматах(количество цифр показателя степени в вашей системе может быть другим).
а. Вводом является 21.3 или 2.1е+001.
б. Вводом является +21.290 или 2.129Е+001. */
int main (void)
{
	float a;
	float b;
	printf("Enter ur number\r\n");
	scanf("%f%f", &a, &b);
	printf("Ur number is\r\n%.1f\r\n%.3e\r\n", a, b);
	printf("Enter ur number\r\n");
	scanf("%f%f", &a, &b);
	printf("Ur number is\r\n%+.3f\r\n%.3E\r\n", a, b);
	return 0;
}