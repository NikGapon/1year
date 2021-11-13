// lab11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>



#include <Windows.h>
char filename1[] = "D:\\Yandex_luc\\vus\\1\\1year\\TEMP\\11.1lab.txt";
char filename[] = "D:\\Yandex_luc\\vus\\1\\1year\\TEMP\\11lab.txt";
void main()
{
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


   
    FILE* fin;
    FILE* nofin;
    fin = fopen(filename, "rt");
    nofin = fopen(filename1, "wt");
    char s[80];
    int i = 0;
    while (!feof(fin)) {
        //fscanf(fin, "%s", s);
        if (fgets(s, 80 - 1, fin) != NULL) {
            for (int i = 0; s[i] != '\0'; i++) {
                s[i] = toupper(s[i]);
            }
            fprintf(nofin, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    printf("%s", s);
    fclose(fin);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
