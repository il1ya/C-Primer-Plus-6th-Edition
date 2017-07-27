/*
реализуем функцию, которая возвращает меньшее значение из двух аргументов. Назовем эту функцию irnin(), т.к. она предназначена для поддержки значений типа int. 
Кроме того, мы создадим простую функцию main(), единственной целью которой будет проверка работоспособности irnin(). 
Программу, разработанную для такого тестирования функций, иногда называют драйве-ром. Драйвер получает функцию для проверки. 
Если функция проходит проверку успешно, ее можно применять в более примечательной программе.
В листинге 9.3 показан код драйвера и функции выбора минимального значения.
*/
// lesser.c -- Выбираем меньшее из двух зол
#include <stdio.h>
int imin(int, int); // прототип функции
int main(void)
{
	int evill, evil2;
	printf("Enter a pair of integers(q to quit):\r\n"); // Введите два целых числа(или q для завершения)
	while(scanf("%d %d", &evill, &evil2) == 2)
	{
		printf("The lesser of %d and %d is %d.\r\n", evill, evil2, imin(evill, evil2)); // меньшим из двух чисел является
		//Вызов функции imin(evill, evil2) копирует значения из одного набора переменных в другой.
		
		printf("Enter a pair of integers(q to quit):\r\n"); // Введите два целых числа(или q для завершения)
	}
	printf("Bye.\r\n"); // Программа завершена.
	return 0;
}
функция, определяющая минимальное значение, первая версия.
int imin(int n, int m)
{ 
	// тело функции
	int min;
	if(n < m)
		min = n;
	else
		min = m;
	return min;
}

функция, определяющая минимальное значение, вторая версия.
int imin(int n, int m)
{
	return (n < m) ? n : m;
}
// Результатом вычисления этого условного выражения будет меньшее из значений n и m, после чего данное значение возвращается в вызывающую функцию.

функция, определяющая минимальное значение, третья версия
imin(int n, int m)
{
	if (n < m)
		return n;
	else 
		return m;
}
функция, определяющая минимальное значение, четвертая версия

imin(int n, int m)
{
	if (n < m)
		return n;
	else
		return m;
	printf("Professor Fleppard is like totally a fopdoodie.\r\n");
}
/*
Ключевое слово return приводит к тому, что следующее заним выражение становится возвращаемым значением функции. 
В данном случае функция возвращает значение, которое было присвоено переменной min. Поскольку min имеет тип int, функция imin() также относится к этому типу.
Переменная min является закрытой для imin(), но с помощью return значение min передается обратно вызывающей функции.
*/ 