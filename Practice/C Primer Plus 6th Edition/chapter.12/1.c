1. Какие классы хранения создают переменные, локальные по отношению к функции, которая их содержит?
1. Автоматический класс хранения, регистровый класс хранения и статический класс хранения без связывания.

2. Какие классы хранения создают переменные, которые сохраняются на протяжении выполнения содержащей их программы?
2. Статический класс хранения без связывания, статический класс хранения с внутренним связыванием и статический класс хранения с внешним связыванием.

3. Какой класс хранения создает переменные, которые могут использоваться в нескольких файлах? Только в одном файле?
3. Статический класс хранения с внешним связыванием. Статический класс хранения с внутренним связыванием.

4. Какой вид связывания имеют переменные с областью видимости в пределах блока?
4. Они не имеют связывания.

5. Для чего испольауется ключевое слово extern?
5. Ключевое слово extern используется в объявлениях для указания переменной или функции, которая объявлена в каком-то другом месте.

6. Взгляните на следующий фрагмент кода:
int * pl = (int *) malloc(lOO * sizeof(int));
Чем от него отличается показанный ниже оператор в смысле конечного результата?
int * pl = (int *) calloc(lOO, sizeof(int));
6. Оба оператора вьделяют память под массив из 100 значений int. 
Оператор, в котором используется calloc(), дополнительно устанавливает каждый элемент в О.

7. Каким функциям известна каждая переменная в следующем коде? Если ли в коде ошибки?

/* файл 1 */
	int daisy;
	int main(void)
	{
		int lily;
		...;
	}

	int petal()
	{
	extern int daisy, lily;
	}

/* файл 2 */
extern int daisy;
static int lily;
	int rose;
	int stem()
	{
		int rose;
		..;
	}
void root()
	{
		...;
	}
Переменная daisy известна функции main() по умолчанию, а функциям petal(), stem() и root() — благодаря объявлению extern. 
Объявление extern int daisy; во втором файле делает переменную daisy известной всем функциям в этом файле. 
Первая переменная lily является локальной для функции main(). 
Ссылка на переменную lily в функции petal() — ошибка, поскольку ни один из файлов не содержит объявления внешней переменной lily. 
Существует внешняя статическая переменная lily, но она известна только функциям из второго файла. 
Первая внешняя переменная rose известна функции root(), но функция stem() заменяет ее собственной локальной переменной rose.

8. Что выведет следующая программа?
#include <stdio.h>
char color = 'В';

void first(void);
void second(void);

int main(void)
{
extern char color;
printf("color в main() равно %c\n", color);

first();
printf("color в main () равно %c\n", color);

second();
printf("color в main() равно %c\n", color);
return 0;
}
void first(void)
	{
		char color;
		color = 'R';
		printf("color в first () равно %c\n", color);
	}
void second(void)
{
	color = 'G';
	printf("color в second() равно %c\n", color),
}

Вывод будет следующим:
color в main() равно В
color в first() равно R
color в main() равно В
color в second() равно G
color в main() равно G
Функция first() не использует глобальную переменную color, но ее использует функция second().

9. Файл начинается со следующих объявлений:
static int plink;
int value_ct(const int arr[] , int value, int n);
а. Что говорят эти объявления о намерениях программиста?
Они говорят о том, что программа будет использовать переменную plink, которая локальна для файла, содержащего функцию. Первый аргумент функции
value_ct() - это указатель на целочисленное значение, которое, по всей видимости, является первым элементом массива, состоящего из n членов. 
В данном случае важно отметить, что программа не сможет применять указатель arr для изменения значений в исходном массиве.

б. Увеличит ли защиту значений в вызывающей программе замена объявлений int и int n объявлениями const int и const int n?
Нет. Аргументы value и n уже являются копиями исходных данных, поэтому функция никак не может изменять соответствующие значения в вызывающей программе. 
Эти объявления предотвращают изменение значений value и n внутри самой функции. 
Например, функция не могла бы использовать выражение n++, если бы объявление n было снабжено const.