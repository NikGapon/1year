#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>


#define MAX_WORDS 10000
#define MAX_LEN 25

struct Dictionary {
	char words[MAX_WORDS][MAX_LEN];
	int cnt_words;
};

struct Dictionary * create();
void destroy(struct Dictionary * dict);
void addWord(struct Dictionary * dict, char * word);
int contains(struct Dictionary * dict, char * word);


struct Dictionary * create()
{
	struct Dictionary * dict = (struct Dictionary *)
		malloc(sizeof(struct Dictionary));
	dict->cnt_words = 0;
	return dict;
}

void destroy(struct Dictionary * dict) {
	free(dict);
}



void addWord(struct Dictionary * dict, char * word)
{
	if (dict->cnt_words >= MAX_WORDS) {
		return; // ??????? ??????????!
	}

	int dif;
	int i = dict->cnt_words;
	while ((i > 0) && (strcmp(word, dict->words[i - 1]) < 0)) {
		strncpy(dict->words[i], dict->words[i - 1], MAX_LEN - 1);
		i--;
	}
	strncpy(dict->words[i], word, MAX_LEN - 1);
	++dict->cnt_words;
}


int contains(struct Dictionary * dict, char * word)
{
	int left = 0;
	int right = dict->cnt_words - 1;

	while (left <= right) {
		int middle = (left + right) / 2;

		int dif = strcmp(dict->words[middle], word);
		if (dif == 0) {
			return 1;
		}
		if (dif < 0) {
			left = middle + 1;
		}
		if (dif > 0) {
			right = middle - 1;
		}
	}
	return 0;
}









int loadDictionary(struct Dictionary * dict,
	const char * filename) {
	// ??????? ????
	FILE * fin;
	char s[MAX_LEN];

	fin = fopen(filename, "rt");
	if (fin == NULL)
	{
		return 0;
	}
	// ? ????? ??? ???? ?????
	while (!feof(fin)) {
		// ????????? ??????
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			if (s[strlen(s) - 1] == '\n')
				s[strlen(s) - 1] = '\0';
			if (!contains(dict, s)) {
				addWord(dict, s);
			}
		}
	}
	// ??????? ????
	fclose(fin);
	return 1;
}


int convertTextToHtml(
	struct Dictionary * dict,
	const char * text_in_filename,
	const char * text_out_filename)
{
	char s[MAX_LEN];

	// ??????? ?????
	FILE *fin = fopen(text_in_filename, "rt");
	if (fin == NULL)
	{
		return 0;
	}

	FILE *fout = fopen(text_out_filename, "wt");
	if (fout == NULL)
	{
		fclose(fin);
		return 0;
	}
	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html>");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta http - equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" />");
	fprintf(fout, "<title>HTML Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");



	char ch;
	int is_letter = 0;
	char word[81];
	int word_len = 0;

	while ((ch = getc(fin)) != EOF) {
		if (isalpha((unsigned char)ch)) {
			if (!is_letter) {
				word_len = 0;
			}
			is_letter = 1;
			word[word_len++] = ch;
		}
		else { // 	if (!isalpha(ch)) {


			if (is_letter) {
				word[word_len] = '\0';
				if (contains(dict, word))
					fprintf(fout, "<b>%s</b> ", word);
				else
					fprintf(fout, "%s", word);
			}
			is_letter = 0;
			fprintf(fout, "%c", ch);
			if (ch == '\n')
				fprintf(fout, "<br>");
		}

	} // while ((ch = getc(fin)) != EOF)
	fclose(fin);

	fprintf(fout, "</body>");
	fprintf(fout, "</html>");
	fclose(fout);
	return 1;
} //  convertTextToHtml- ?????!!!




void main() {
	long t0, t1, t2;
	t0 = clock();
	printf("t0 = %f sec \n", t0 / (float)CLOCKS_PER_SEC);

	struct Dictionary* dict = create();
	loadDictionary(dict, "dict1.txt");

	t1 = clock();
	printf("t1 = %f sec \n", t1 / (float)CLOCKS_PER_SEC);

	convertTextToHtml(dict,
		"Alice.txt",
		"Alice_out_sort_dict11.html");

	destroy(dict);

	t2 = clock();
	printf("t2 = %f sec \n",
		t2 / (float)CLOCKS_PER_SEC);

	printf("Run time = t2 - t0 = %f sec \n",
		(t2 - t0) / (float)CLOCKS_PER_SEC);
	////-------------------------------------------
	t0 = clock();
	printf("t0 = %f sec \n", t0 / (float)CLOCKS_PER_SEC);

	dict = create();
	loadDictionary(dict, "dict12.txt");

	t1 = clock();
	printf("t1 = %f sec \n", t1 / (float)CLOCKS_PER_SEC);

	convertTextToHtml(dict,
		"Alice.txt",
		"Alice_out_sort_dict12.html");

	destroy(dict);

	t2 = clock();
	printf("t2 = %f sec \n",
		t2 / (float)CLOCKS_PER_SEC);

	printf("Run time = t2 - t0 = %f sec \n",
		(t2 - t0) / (float)CLOCKS_PER_SEC);
	////-------------------------------------------
	t0 = clock();
	printf("t0 = %f sec \n", t0 / (float)CLOCKS_PER_SEC);

	dict = create();
	loadDictionary(dict, "dict2.txt");

	t1 = clock();
	printf("t1 = %f sec \n", t1 / (float)CLOCKS_PER_SEC);

	convertTextToHtml(dict,
		"Alice.txt",
		"Alice_out_sort_dict21.html");

	destroy(dict);

	t2 = clock();
	printf("t2 = %f sec \n",
		t2 / (float)CLOCKS_PER_SEC);

	printf("Run time = t2 - t0 = %f sec \n",
		(t2 - t0) / (float)CLOCKS_PER_SEC);
	////-------------------------------------------
	t0 = clock();
	printf("t0 = %f sec \n", t0 / (float)CLOCKS_PER_SEC);

	dict = create();
	loadDictionary(dict, "dict22.txt");

	t1 = clock();
	printf("t1 = %f sec \n", t1 / (float)CLOCKS_PER_SEC);

	convertTextToHtml(dict,
		"Alice.txt",
		"Alice_out_sort_dict22.html");

	destroy(dict);

	t2 = clock();
	printf("t2 = %f sec \n",
		t2 / (float)CLOCKS_PER_SEC);

	printf("Run time = t2 - t0 = %f sec \n",
		(t2 - t0) / (float)CLOCKS_PER_SEC);
	//-------------------------------------------
	t0 = clock();
	printf("t0 = %f sec \n", t0 / (float)CLOCKS_PER_SEC);

	dict = create();
	loadDictionary(dict, "dict31.txt");

	t1 = clock();
	printf("t1 = %f sec \n", t1 / (float)CLOCKS_PER_SEC);

	convertTextToHtml(dict,
		"Alice.txt",
		"Alice_out_sort_dict31.html");

	destroy(dict);

	t2 = clock();
	printf("t2 = %f sec \n",
		t2 / (float)CLOCKS_PER_SEC);

	printf("Run time = t2 - t0 = %f sec \n",
		(t2 - t0) / (float)CLOCKS_PER_SEC);
	//-------------------------------------------
	t0 = clock();
	printf("t0 = %f sec \n", t0 / (float)CLOCKS_PER_SEC);

	dict = create();
	loadDictionary(dict, "dict32.txt");

	t1 = clock();
	printf("t1 = %f sec \n", t1 / (float)CLOCKS_PER_SEC);

	convertTextToHtml(dict,
		"Alice.txt",
		"Alice_out_sort_dict32.html");

	destroy(dict);

	t2 = clock();
	printf("t2 = %f sec \n",
		t2 / (float)CLOCKS_PER_SEC);

	printf("Run time = t2 - t0 = %f sec \n",
		(t2 - t0) / (float)CLOCKS_PER_SEC);
	{
		int x;
		scanf("%d", &x);
	}
}







