#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <ctype.h>

//Assame, that the "asple" is a text apple.
int main() {
	FILE *fp;
	char ch;
	int sound[1000];
	int i = 0;
	if ((fp = fopen("test.txt", "r")) == NULL) {
	
		printf("open file error!!\n"); //�ɮרS�}�� 
	}
	else {

		while ((ch = getc(fp)) != EOF) {
			if (ch == ' ') continue;

			if (ch == '(' || ch == ')' || ch == '-') {



			}
			else {

				ch = ch - '0';
				sound[i] = ch;
				i++;

			}





		}
	}
	fclose(fp);//�����ɮ� 
	system("PAUSE");
	return 0;
}
