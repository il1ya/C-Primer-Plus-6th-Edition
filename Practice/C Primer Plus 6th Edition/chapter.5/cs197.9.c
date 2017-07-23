/* Напишите программу, которая запрашивает у пользователя ввод значения температуры по Фаренгейту. 
Программа должна считывать значение температуры как число типа double и передавать его в виде аргумента пользовательской функции по имени Temperatures ().
Эта функция должна вычислять эквивалентные значения температуры 110 Цельсию и по Кельвину и отображать на экране все три значения температуры 
с точностью до двух позиций справа от десятичной точки. 
Функция должна идентифицировать каждое значение символом соответствующей температурной шкалы. 
Вот формула перевода температуры по Фаренгейту в температуру по Цельсию:

Температура по Цельсию = 5.0 / 9.0 х ( температура п о Фаренгейту - 32.0)

В шкале Кельвина, которая обычно применяется в науке, О представляет абсолютный нуль, т.е. минимальный предел возможных температур. 
Формула перевода температуры по Цельсию в температуру по Фаренгейту имеет вид:

Температура по Кельвину = температура по Цельсию + 273. 16

Функция Temperatures () должна использовать const для создания символических представлений трех констант, которые участвуют в преобразованиях. 
Чтобы предоставить пользователю возможность многократного ввода значений температуры, в функции main () должен быть организован цикл
который завершается при вводе символа q или другого нечислового значения. 
Воспользуйтесь тем фактом, что функция scanf () возвращает количество прочитанных ею элементов, 
поэтому она возвратит 1, если прочитает число, но не будет возвращать 1, когда пользователь введет q. 
Операция == выполняет проверку на равенство, так что ее можно применять для сравнения возвращаемого значения scanf () с 1 */
#include <stdio.h>
void Temperatures (void); //прототип функции в стандарте ISO/ANSI C
int main (void)
{
	Temperatures();
	return 0;
}

void Temperatures (void) // начало определения функции
{
	double Fahrenheit;
	double Celsiusformula;
	double ThetemperatureinKelvin;
	printf("Enter temperature Fahrenheit: ");
	while (Fahrenheit > 0)
	{
		scanf("%lf", &Fahrenheit);
		Celsiusformula = 5.0 / 9.0 * (Fahrenheit - 32);
		ThetemperatureinKelvin = Fahrenheit + 273.16;
		printf("your T %.f, %.2fC, %.2fK\r\n",Fahrenheit, Celsiusformula, ThetemperatureinKelvin);
	}
	printf("Done!");
}