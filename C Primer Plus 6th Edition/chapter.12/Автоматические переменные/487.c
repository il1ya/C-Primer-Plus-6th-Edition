/*Что, если вы объявите во внутреннем блоке переменную, которая имеет такое же имя, как переменная во внешнем блоке? 
Тогда имя, определенное внутри блока, соответствует переменной, которая применяется в этом блоке. 
Мы говорим, что имя скрывает внешнее определение. 
Однако когда поток управления покидает внутренний блок, внешняя переменная возвращается в область видимости. 
Эти и другие аспекты проиллюстрированы в листинге 12.1.*/
// Листинг 12.1. Программа hiding.c
// hiding.c -- переменные в блоках
#include <stdio.h>

int main(void)
{
	// определяем переменные внутри блока. Автоматические переменные
	int x = 30; // исходная переменная x

	printf("x in outer block: %d at %p\r\n", x, &x); // во внутреннем блоке: по адресу
	{
		int x = 77; // новая переменная x, скрывающая первую x
		printf("x in outer block: %d at %p\r\n", x, &x);
	}

	printf("x in outer block: %d at %p\r\n", x, &x);

	while(x++ < 33) // исходная переменная x
	{
		int x = 100; // новая переменная x, скрывающая первую x
		x++;
		printf("x in outer block: %d at %p\r\n", x, &x);
	}

	printf("x in outer block: %d at %p\r\n", x, &x);

	return 0;
}

/*Первым делом программа создаст переменную х со значением 30, как показывает первый оператор printf(). 
Затем она определяет новую переменпую х со значением 77, о чем сообщает второй оператор printf(). 
Это новая переменная, скрывающая первую переменную х, значение и адрес которой снова выводятся третьим оператором printf(). 
Данный оператор находится после первого внутреннего блока и отображает первоначальное значение х, демонстрируя тем самым, что эта переменная никуда не исчезала и не изменялась.
Вероятно, наиболее интригующей частью программы является цикл while. 
В условии проверки цикла while задействована исходная переменная х: 
while(х++ < 33)
Однако внутри цикла программа видит третью переменную х, т.е. ту, которая определена в рамках блока цикла while. 
Таким образом, когда в теле цикла используется выражение х++, в нем участвует новая переменная х, значение которой инкрементируется до 101 и затем отображается. 
По завершении каждой итерации цикла эта новая переменная х исчезает.
Далее в условии проверки цикла применяется и инкрементируется исходная переменная х, снова происходит вход в блок цикла, и опять создается новая переменная х. 
В этом примере переменная х создается и уничтожается три раза.
Обратите внимание, что для прекращения выполнения цикл должен инкрементировать х в условии проверки, 
т.к. инкрементирование х в теле цикла приводит к увеличению значения другой переменной х, а не той, которая задействована в условии проверки.
Хотя применяемый конкретный компилятор не использует повторно ячейку памяти переменной х внутреннего блока для версии х на цикла while, некоторые компиляторы делают это.
Назначение этого примера вовсе не в том, чтобы поощрять написание кода в таком стиле. 
Он служит лишь иллюстрацией того, что происходит, когда вы определяете переменные внутри блока. 
(Учитывая многообразие имен, доступных благодаря правилам именования С, выбор имени, отличающегося от х, не должен вызывать особые затруднения.)*/