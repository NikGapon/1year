// lab11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "dsa.h"


#include <Windows.h>
char filename1[] = "D:\\Yandex_luc\\vus\\1\\1year\\TEMP\\11.1lab.txt";
char filename[] = "D:\\Yandex_luc\\vus\\1\\1year\\TEMP\\11lab.txt";
#define MAX_LEN 80

char fileIn1[] = "D:\\Yandex_luc\\vus\\1\\1year\\TEMP\\in1.txt";
char fileOut1[] = "D:\\Yandex_luc\\vus\\1\\1year\\TEMP\\out1.txt";
int toUpperRus(int c)
{
    int new_c = c;
    if (c >= (int)'а' && c <= (int)'п')
        new_c = 'А' + (c - 'а');
    if (c >= (int)'р' && c <= (int)'я')
        new_c = 'Р' + (c - 'р');
    if (c == (int)'ё')
        new_c = 'Ё';
    return new_c;
}

int toUpperEU(int c)
{
    int new_c = c;
    if (c >= (int)'a' && c <= (int)'z')
        new_c = 'А' + (c - 'а');
    
    return new_c;
}

void main()
{
    //1
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    /*
    char name[12];
    printf("Введите ваше имя:");
    fgets(name, 11, stdin);
    printf("Привествую тебя, %s\n", name);

    {
        int x;
        scanf("%d", &x);
    }*/
    //2
    /*printf("Введите Символ:");
    int ch = getchar();

    for (int c = ch; c <= ch + 19; c++) {
        printf("'%c' (%d)\n", c, c);
    }
    printf("\n\n\n");

    {
        int x;
        scanf("%d", &x);
    }*/

    //4

    /*char s[80];
    printf("ВВедите строку:");
    fgets(s, 79, stdin);

    printf("\nВЫ ввели строку s = \" %s\"", s);
    int cnt = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') cnt++;
    }

    printf("\nВ ней %d пробелов\n", cnt);

    {
        int x;
        scanf("%d", &x);
    }*/

    // 5
    /*SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s[80];
    printf("Введите строку: ");
    fgets(s, 79, stdin);

    printf("\nВы ввели строку s = \"%s\"", s);

    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == ' ') s[i] = '#';
    }

    printf("\nСтрока после обработки = %s\n", s);*/

    //6
    /*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; i < strlen(s); ++i)
	{
		if (isdigit(s[i])) s[i] = '$';
	}

	printf("\nСтрока после обработки =\"%s\"\n", s);

	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; i < strlen(s); ++i)
	{
		if (isDigitMy(s[i])) s[i] = '$';
	}

	printf("\nСтрока после обработки = \"%s\"\n", s);*/

    //7
    //FILE* fin;
    //FILE* nofin;
    //fin = fopen(filename, "rt");
    //nofin = fopen(filename1, "wt");
    //char s[80];
    //int i = 0;
    //while (!feof(fin)) {
    //    //fscanf(fin, "%s", s);
    //    if (fgets(s, 80 - 1, fin) != NULL) {
    //        for (int i = 0; s[i] != '\0'; i++) {
    //            s[i] = toupper(s[i]);
    //        }
    //        fprintf(nofin, "%s", s);
    //        printf(">>%s<<\n", s);
    //    }
    //}
    //printf("%s", s);
    //fclose(fin);
    
    //13
//SetConsoleCP(1251);
//SetConsoleOutputCP(1251);
//char ss[24][80] = {
//"задача 2",
//"Преобразовать файл in2.txt в файл out2.txt",
//"Заменив все большие русские буквы на маленькие",
//"",
//"задача 3",
//"Зашифровать текст записанный латиницей, и находящийся в файле in3.txt",
//"применив шифр Цезаря с ключом 4",
//"Результат сохранить в файл in4.txt",
//"задача 4",
//"Расшифровать текст записанный латиницей,  и находящийся в файле in4.txt",
//"применив шифр Цезаря с ключом 4",
//"Результат сохранить в файл out4.txt",
//"",
//"задача 5",
//"Преобразовать текстовый файл in5.txt",
//"в файл out5.txt, в котором каждое слово выводится на отдельной строке",
//"",
//"Задача 6*",
//"Игра в слова",
//"В файле in6.txt есть строки со словами",
//"в каждой строке ровно одно слово",
//"С консоли вводится комплект букв",
//"Нужно вывести в консоль те слова из файла in6.txt",
//"Которые можно составить из введенных с консоли букв"
//};
//{
//    char fileIn1[] = "D:\\Yandex_luc\\vus\\1\\1year\\TEMP\\11.13.txt";
//    FILE* fout = fopen(fileIn1, "wt");
//    // в цикле для всех строк
//    for (int i = 0; i < 24; i++)
//    {
//        // сохранить строку в выходной файл
//        fprintf(fout, "%s\n", ss[i]);
//        // контрольный вывод в консоль
//        printf(">>%s<<\n", ss[i]);
//    }
//    fclose(fout);
//}
    //14
//SetConsoleCP(1251);
//SetConsoleOutputCP(1251);
//
//char s[MAX_LEN];
//
//FILE* fin = fopen(fileIn1, "rt");
//FILE* fout = fopen(fileOut1, "wt");
//// в цикле для всех строк
//while (!feof(fin)) {
//    // загрузить строку
//    if (fgets(s, MAX_LEN - 1, fin) != NULL) {
//        // обработать загруженную строку
//        for (int i = 0; s[i] != '\0'; i++) {
//            s[i] = toUpperRus(s[i]); 
//        }
//        // сохранить строку в выходной файл
//        fprintf(fout, "%s", s);
//        printf(">>%s<<\n", s);
//    }
//}
//fclose(fin);
//fclose(fout);
    



//SetConsoleCP(1251);
//SetConsoleOutputCP(1251);
//
//char s[MAX_LEN];
//
//FILE* fin = fopen(fileIn1, "rt");
//FILE* fout = fopen(fileOut1, "wt");
//// в цикле для всех строк
//while (!feof(fin)) {
//    // загрузить строку
//    if (fgets(s, MAX_LEN - 1, fin) != NULL) {
//        // обработать загруженную строку
//        for (int i = 0; s[i] != '\0'; i++) {
//            s[i] = toUpperEU(s[i]); 
//        }
//        // сохранить строку в выходной файл
//        fprintf(fout, "%s", s);
//        printf(">>%s<<\n", s);
//    }
//}
//fclose(fin);
//fclose(fout);

{
    int x;
    scanf("%d", &x);
}
}


