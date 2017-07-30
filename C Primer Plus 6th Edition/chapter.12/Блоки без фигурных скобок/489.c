/*Упомянутая ранее возможность стандарта С99 заключается в том, что операторы, которые являются частью цикла или оператора if, 
квалифицируются как блок, даже если фигурные скобки ({}) не указаны. 
Выражаясь более точно, полный цикл — это подблок содержащего его блока, а тело цикла — подблок блока полного цикла. 
Аналогично, оператор if представляет собой блок, а связанный с ним оператор — подблок оператора if.
Описанные правила влияют на то, где вы можете объявлять переменную, и на область видимости этой переменной.
В листинге 12.2 показано, как это работает в цикле for.*/
// Листинг 12.2. Программа forc99.c
// forc99.c -- новые правила для блоков в c99
#include <stdio.h>
int main(void)
{
	int n = 8;

	printf("     Initially, n = %d at %p\r\n", n, &n); // Первоначально n по адресу

	for(int n = 1; n < 3; n++)
		printf("	loop 1: n = %d at %p\r\n", n, &n); // цикл 1: n по адресу

	printf("After loop 1, n = %d at %p\r\n", n, &n); // После цикла 1n по адресу
	
	for(int n = 1; n < 3; n++)
	{
		printf(" loop 2 index n = %d at %p\r\n", n, &n); // индекс цикла 2n по адресу
		int n = 6;
		printf("		loop 2: n = %d at %p\r\n", n, &n); // цикл 2: по адресу
		n++;
	}

	printf("After loop 2, n = %d at %p\r\n", n, &n); // После цикла 2n по адресу

	return 0;
}
/*Переменная n, объявленная в управляющем разделе первого цикла for, имеет область видимости до конца цикла и скрывает исходную переменную n. 
Но после того как управление покидает цикл, исходная переменная n возвращается в область видимости.
Во втором цикле for переменная n, объявленная как индекс цикла, скрывает исходную переменную n. 
Затем переменная n, объявленная внутри тела цикла, скрывает индекс цикла n. 
Как только программа завершит выполнение тела, переменная n, объявленная в теле, исчезает, а в проверке цикла участвует индекс n. 
Когда завершится выполнения всего цикла, в области видимости появляется исходная переменная n.
И снова отметим, что нет никакой нужды многократно применять одного и того же имени для переменной, но вы должны знать, что произойдет, если вы все-таки решите поступить так.*/
