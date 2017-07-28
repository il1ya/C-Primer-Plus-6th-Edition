// Листинг 10.4 Программа day_mon2.c
// day_mon2.c -- предоставление компилятору возможности подсчета элементов
#include <stdio.h>
int main(void)
{
	const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 };
/* Когда вы применяете для инициализации массива пустые квадратные скобки,компилятор подсчитывает количество элементов в списке и 
устанавливает размер массива в полученное число. */
	for(int index = 0; index < sizeof days / sizeof days[0]; index++)
/*		Операция sizeof выдает размер в байтах следующего за ней объекта или типа. 
		Таким образом, sizeof days — это размер в байтах всего массива, а sizeof days[О] — размер в байтах одного элемента. 
		Разделив размер всего массива на размер одного элемента, мы получаем количество элементов в массиве.*/
		printf("Months %2d It has %d day (days).\r\n", index + 1, days[index]);
	return 0;
}