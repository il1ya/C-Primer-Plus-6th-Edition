// Листинг 10.5. Программа designate.c
// designate.c -- использование назначенных инициализаторов
#include <stdio.h>
#define MONTHS 12
int main(void)
{
/*если за назначенным инициализатором находится код с дальнейшими значениями, как в последовательности 
[4] = 31, 30, 31, эти значения используются для инициализации последующих элементов. 
То есть после инициализации days[4] значением 31 этот код инициализирует days[5] = 30 и days [6] = 31 значениями.*/
	int days[MONTHS] = { 31, 28, [4] = 31, 30, 31, [1] = 29 };
	for(int i = 0; i < MONTHS; i++)
		printf("%2d %d\r\n", i, days[i]);
	return 0;
}