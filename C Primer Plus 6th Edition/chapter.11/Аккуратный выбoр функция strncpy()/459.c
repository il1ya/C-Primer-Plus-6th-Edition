/*Функции strcpy() присуща та же проблема, что и strcat() — ни одна из них не проверяет, умещается ли на самом деле исходная строка в целевую строку. 
Более безопасный способ копирования строк предусматривает применение функции strncpy().
Эта функция принимает третий аргумент, в котором указывается максимальное количество копируемых символов. 
В листинге 11.27 приведена переписанная версия кода из листинга 11.25, в которой вместо strcpy() используется strncpy(). 
Чтобы показать, что происходит в случае, когда размер исходной строки слишком велик, для целевых строк в коде выбран небольшой размер (семь элементов, шесть символов).*/
// Листинг 11.27. Программа copy3.c

// copy3.c -- демонстрация использования strncpy()

#include <stdio.h>
#include <string.h> // объявление strncpy()
#define SIZE 40
#define TARGSIZE 7
#define LIM 5
char *s_gets(char *st, int n);
int main(void)
{
	char qwords[LIM][TARGSIZE];
	char temp[SIZE];
	int i = 0;
	printf("Enter %d words beginning with q:\r\n", LIM); // Введите слов, которые начинаются с буквы
	while(i < LIM && s_gets(temp, SIZE))
	{
		if(temp[0] != 'q')
			printf("%s doesn't begin with q!\r\n", temp); // не начинается с буквы
		else
		{
			strncpy(qwords[i], temp, TARGSIZE - 1);
			qwords[i][TARGSIZE - 1] = '\0';
			i++;
		}
	}
	puts("Here are the words accepted:"); // Список принятых слов
	for(i = 0; i < LIM; i++)
		puts(qwords[i]);
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

/*Вызов функции strncpy(target, source, n) копирует вплоть до n символов либо до появления нулевого символа (в зависимости от того, что произойдет раньше)
из source в target. Следовательно, если количество символов в source меньше n, копируется вся строка, включая нуллевой символ. 
Эта функция никогда не копирует более n символов, так что если данный лимит исчерпан до достижения конца исходной строки, то нулевой символ не добавляется. 
Таким образом, финальный результат может содержать, а может и не содержать нулевой символ. 
По этой причине значение n в программе выбрано на единцу меньше размера целевого массива, а последний элемент массива установлен в нулевой символ:
strncpy(qwords[i], temp, TARGSIZE - 1);
qwords[i][TARGSIZE - 1] = '\0';
Это обеспечивает сохранение строки. Если исходная строка в действительности умещается в целевую строку, то скопированный вместе с ней нулевой символ 
помечает настоящий конец строки. Если исходная строка в целевую не умещается, то конец строки помечается последним нулевым символом.*/