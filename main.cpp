#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdio>

using namespace std;

void clean_stream() {
	while(fgetc(stdin) != '\n');
}

bool check(char str[],char str1[]) {
	int k=0;
	bool test=false;
	for(int i=0; str[i]!='\0'; i++) {
		if(str[i]==str1[k])
			for(int j=0,t=i; str1[j]!='\0'; j++,t++) {
				if(str[t]!=str1[j]) {
					test=false;
					break;
				} else {
					test=true;
				}
			}
		k=0;
		if(test==true)
			return test;
	}
	return test;
}
bool simple_print(char str[], char str1[]) {
	return strcmp(str,str1);
}

bool check_polind(char str[]) {
	int i,length;

	length=strlen(str);

	for (i=0; i<length; i++)
		if (str[i]!=str[(length-1)-i]) return 0;
	return 1;
}

void check_str() {
	char str[100];
	int i=0;
	printf("plz enter symbol \n");
	char c=getchar();
	clean_stream();
	printf("plz enter string \n");
	fgets(str,100,stdin);
	char *str1=strtok(str," ,.-");
	while(str1!=NULL) {
		if(str1[strlen(str1)-1]==c)
			i++;
		str1=strtok(NULL," ,.-");
	}
	printf("%d\n",i);
}

void file1() {
	FILE *fl=fopen("text.txt","w+");
	char c;
	int i=0;
	printf("please enter string \n");
	while((c=fgetc(stdin))!='\n') {
		fprintf(fl,"%c",c);
		i++;
	}
	fflush(stdin);
	printf("%s%d\n","size: ",i);
	fclose(fl);
}
void file2(char str[],char str1[]) {
	printf("input string \n");
	FILE *fp = fopen("text.txt", "r");
	fgets(str,100,fp);
	fclose(fp);
	printf("\n");
	fgets(str1,100,stdin);
	bool result=simple_print(str1,str);
	if(result!=true)
		printf("ravni \n");
	else
		printf("ne ravni \n");
	bool x=check(str,str1);
	if(x==true)
		printf("vhodit \n");
	else
		printf("ne vhodit \n");
}

void print_menu() {
	printf("choise operation \n");
	printf("a: save string to file \n");
	printf("b: comparison strings \n");
	printf("c: polindroms \n");
	printf("d: seach last simbol in words \n");
	printf("e: exit \n");
}

int main() {
	char str[100];
	char str1[100];
	char *strp;
	char choice;
	while(true) {
		print_menu();
		choice=getchar();
		clean_stream();
		switch(choice) {
			case 'a':
				file1();
				break;
			case 'b':
				file2(str,str1);
				break;
			case 'c':
				strp=strtok (str," ,.-");
				while(strp!=NULL) {
					if(check_polind(strp)==true)
						printf("\n polind: %s",strp);
					strp=strtok(NULL," ,.-");
				}
				printf("\n");
				break;
			case 'd':
				check_str();
				break;
			case 'e':
				return 0;
		}
	}

	return 0;
}
