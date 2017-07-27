/*
В языке С функции разрешено вызывать саму себя. Этот процесс называется рекурсией. Временами рекурсия бывает сложной, но иногда и очень удобной. 
Сложность связана с доведением рекурсии до конца, т.к. функция, которая вызывает сама себя. 
имеет тенденцию делать это бесконечно, если в коде не предусмотрена проверка условия завершения рекурсии.
*/
/*
Пример рекурсии. Функция main() в листинге 9.6 вызывает функцию up_and_down(). 
Назовем это “первым уровнем рекурсии”. Затем функция up_and_down() вызывает саму себя; назовем это “вторым уровнем рекурсии”. 
Второй уровень вызывает третий уровень рекурсии и т.д. В этом примере настроены четыре уровня рекурсии. 
Чтобы посмотреть, что происходит внутри, программа не только отображает значение переменной n, но также и значение &n, 
которое представляет собой адрес ячейки памяти, где хранится переменная n. 
(Операция & более подробно обсуждается позже в главе. Для вывода адресов в printf() применяется спецификатор %р. 
Если ваша система не поддерживает этот формат, попробуйте воспользоваться спецификатором %u или %lu.)
*/
// recur.c -- иллюстрация рекурсии
#include <stdio.h>
void up_and_down(int);
int main(void)
{
	up_and_down(1);
	return 0;
}
void up_and_down(int n)
{
	printf("Level %d: n location %p\r\n", n, &n); // 1
	if(n < 4)
		up_and_down(n+1);
	printf("LEVEL %d: n location %p\r\n", n, &n); // 2
}
/*
Если я нахожу приведенное ниже объяснение слегка запутанным, то представьте, что имеется цепочка вызовов функций, в которой funl() вызывает fun2(),
fun2() вызывает fun3() и fun3() вызывает fun4(). Когда fun4() завершается, управление передается fun3(). 
По завершении fun3() управление передается fun2(). Когда заканчивается fun2(), управление возвращается обратно funl(). 
Рекурсивный случай работает точно так же, за исключением того, что функции funl(), fun2(), fun3() и fun4() являются одной и той же функцией.
*/
/*
Сначала main() вызывает up_and_down() с аргументом 1. 
В результате формальный параметр n функции up_and_down() получает значение 1,  поэтому первый оператор вывода отображает суроку Уровень 1:.
Далее, поскольку n меньше 4, функция up_and_down() (уровень 1)  вызывает функцию up_ and_down() (уровень 2) с фактическим аргументом n +1, или 2. 
Это приводит к тому, что n в вызове уровня 2 присваивается значение 2, так что первый оператор вывода отображает строку Уровень 2 :.
Аналогично, следующие два вызова приводят к выводу Уровень З : и Уровень 4 : .
Когда достигнуг уровень 4, переменная n равна 4, поэтому проверка в if не проходит.
Функция up_and_ down() не вызывается снова. Вместо этого вызов уровня 4 продолжается выполнением второго оператора вывода, который отображает строку УРОВЕНЬ 4
т.к. переменная n имеет значение 4. В этой точке вызов уровня 4 заканчивается, а управление возвращается функции, которая его инициировала (вызов уровня 3).
Последним оператором, выполненным внугри вызова уровня 3, был вызов уровня 4 в операторе if. 
Следовательно, выполнение уровня 3 возобновляется со следующего оператора, которым является второй оператор вывода. 
Это приводит к отображению строки УРОВЕНЬ 3:. Затем уровень 3 завершается, передавая управление уровню 2, который выводит строку УРОВЕНЬ 2 :, и т.д.
*/