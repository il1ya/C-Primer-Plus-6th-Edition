/*Теперь модифицируйте программу из упражнения 5, чтобы она вычисляла сумму
квадратов целых чисел. (Или, если вам как больше нравится, программа должна
вычислять сумму, которую вы получите, если в первый день вам заплатят $1, во
второй день — $4, в третий день — $9 и т.д.) В языке С отсутствует функция возведения
в квадрат, но, как вы знаете, квадрат числа n равен n*n. */
#include <stdio.h>
int main (void)
{
	int count, sum, bb;
	count = 0;
	printf("\r\nEnter days: ");
	scanf("%d", &sum);
	while (count < 20)
	{	
		bb = count * count++;
		printf("%2d$\r\n", bb);
	}
	printf("end!");
	return 0;
}