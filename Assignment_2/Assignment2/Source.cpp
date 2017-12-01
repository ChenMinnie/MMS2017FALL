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
	
		printf("open file error!!\n"); //檔案沒開啟 
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
	fclose(fp);//關閉檔案 
	system("PAUSE");
	return 0;
}
