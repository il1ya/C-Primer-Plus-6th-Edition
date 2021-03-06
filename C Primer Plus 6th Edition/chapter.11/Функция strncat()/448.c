/*Функция strcat() не проверяет, умещается ли вторая строка в первый массив. 
Если вы не выделите достаточного пространства для первого массива, то столкнетесь с проблемой переполнения соседних ячеек памяти избыточными символами.

Конечно, можно заранее проверить длину с помощью strlen(), как показано в листинге 11.15. 
Обратите внимание, что эта функция добавляет 1 к общей длине, резервируя место для нулевого символа. 
В качестве альтернативы можно воспользоваться функцией strncat(), которая принимает второй аргумент, указывающий максимальное количество добавляемых символов. 
Например, вызов strncat(bugs, addon, 13) добавляет содержимое строки addon к bugs, останавливаясь после прохода 13 дополнительных
символов или при обнаружении нулевого символа, в зависимости от того, что случится раньше. 
Следовательно, учитывая нулевой символ (который добавляется в любом случае), массив bugs должен иметь размер, достаточный для хранения исходной
строки (без нулевого символа), максимум 13 дополнительных символов и завершающего нулевого символа. 
В листинге 11.19 эта информация применяется для вычисления значения переменной available, которая служит максимальным разрешенным количеством дополнительных символов.*/
// Листинг 11.19. Программа join_chk.c 
// join_chk.c -- объединяет две строки, предварительно проверив размер
#include <stdio.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13
char *s_gets(char *st, int n);
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes."; // пахнет как старые валенки
	char bug[BUGSIZE];
	int available;

	puts("What is your favorite flower?"); // Какой у вас любимый цветок?
	s_gets(flower, SIZE);
	if((strlen(addon) + strlen(flower) + 1) <= SIZE)
		strcat(flower, addon);
	puts(flower);
	puts("What is your favorite bug?"); // Какое у вас любимое насекомое?
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
	strncat(bug, addon, available);
	puts(bug);
	return 0;
}
char *s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] == '\0';
		else // требуется наличие words[i] == '\0'
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
/*Вы уже могли заметить, что функция strcat(), как и gets(), может приводить к переполнению буфера. Почему же тогда в стандарте C11 не отказались от strcat(),
а лишь предложили функцию strncat()? Одной из причин может быть то, что функция gets() подвергает программу опасности со стороны тех, кто ее использует, 
в то время как strcat() подвергает программу опасности вследствие невнимательности программиста. 
Будущее поведение того или иного пользователя предвидеть невозможно, но можно контролировать то, что происходит внутри программы. 
Философия доверия программисту, принятая в С, возлагает на вас ответственность за определение ситуаций, в которых функция strcat() может применяться безопасным образом.*/