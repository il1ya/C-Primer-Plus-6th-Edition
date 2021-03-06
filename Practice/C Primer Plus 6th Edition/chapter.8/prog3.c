/*
Напишите программу, которая читает ввод как поток символов, пока не встретит EOF. 
Программа должна сообщать количество прописных букв количество строчных букв и количество остальных символов во входных данных. 
Можете предполагать, что числовые значения для строчных букв являются последовательными, и то же самое справедливо для прописных букв. 
Либо для большей переносимости можете использовать подходящие классификационные фучкции из библиотеки ctуре.h.
*/
#include <stdio.h>
#include <ctype.h> // для isupper and islower
int main(void)
{
	char ch; // прочитанный символ
	int n_chars = 0; // символы
	int n_lines = 0; // строки
	int n_other = 0; // другое
	printf("Enter characters\r\n");
	while((ch = getchar()) != EOF && ch != '#')
	{
		if(isupper(ch)) // Символ верхнего регистра
			n_lines++; // считать строки
		else if(islower(ch)) // Символ нижнего регистра
			n_chars++; // считать символы
		else
			n_other++; // считать другое
	}
	printf("\r\nlines = %d| characters = %d| other = %d", n_lines, n_chars, n_other);
	return 0;
}