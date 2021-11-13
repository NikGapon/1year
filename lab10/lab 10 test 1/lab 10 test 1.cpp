// lab 10 test 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>



// индексы входа и выхода
struct Position {
	int i, j;
};
char filename[] = "D:\\Yandex_luc\\vus\\1\\1year\\TEMP\\10lab.txt";
// Уровень игры
struct Level {
	int map[10][10]; // карта уровня
// 0 – воздух
// 1 – земля
	int n; // количество строк
	int m; // количество столбцов
	struct Position entry; // вход
	struct Position exit; // выход
};



int loadLevel(struct Level* level) {
	FILE* fin = fopen(filename, "rt");

	if (fin == NULL) {
		printf("File %s is not opened", filename);
		return 0;
	}

	fscanf(fin, "%d", &level->n);
	fscanf(fin, "%d", &level->m);

	for (int i = 0; i < level->n; i++) {
		for (int j = 0; j < level->m; j++) {
			fscanf(fin, "%d", &level->map[i][j]);
		}
	}

	fscanf(fin, "%d", &level->entry.i);
	fscanf(fin, "%d", &level->entry.j);

	fscanf(fin, "%d", &level->exit.i);
	fscanf(fin, "%d", &level->exit.j);

	fclose(fin);
	return 1;
}

void addColumn(struct Level * level, int indexCol) {
	for (int i = level->n - 1; i >= 0; i--) {
		if (level->map[i][indexCol] == 0) {
			level->map[i][indexCol] = 1;
			break;
		}
	}
}

void printLevel(struct Level* level) {

	for (int i = 0; i < level->n; i++) {
		for (int j = 0; j < level->m; j++) {
			printf("%5d ", level->map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Entry i = %d; j = %d\n", level->entry.i, level->entry.j);
	printf("Exit i = %d; j = %d\n\n", level->exit.i, level->exit.j);
}




void main()
{
	struct Level g;
	int k = -2;
	do
	{
		if (k == 0) {
			loadLevel(&g);
		}
		if (k == 1) {
			int j;
			printf("\n Input j > "); 
			scanf("%d", &j); 
			addColumn(&g, j);
		}
		if (k == 2) {
		}
		printLevel(&g);
		printf("\n\n\n"); 
		printf("Please select action:\n"); 
		printf("0: Reload file\n"); 
		printf("1: addInColumn\n"); 
		printf("2: deleteMaxColumn\n"); 
		printf("3: \n"); 
		printf("\n-1: Exit\n");
		// Добавление элементов в самую низкую горку // Удаление элементов из заданной горки // Сохранение состояния уровня 
		scanf("%d", &k);
	} while (k != -1);

	
	
	{
		int x;
		scanf("%d", &x);
	}
}