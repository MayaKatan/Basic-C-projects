#include <stdio.h>
#include <string.h>
#include "data.h"

/*my_strcmp*/
int my_strcmp (const char *string1, const char *string2) {
    int i = 0;
    while (string1[i] != '\0' || string2[i] != '\0') {
        if (string1[i] != string2[i]) {
        	return string1[i]-string2[i];
        }
        i++;
    }
    return 0;
}

/*my_strncmp*/
int my_strncmp(const char *string1, const char *string2, size_t n) {
    int i = 0;
    while (string1[i] != '\0' || string2[i] != '\0' && i <= n) {
        if (string1[i] != string2[i]) {
            return string1[i] - string2[i];
        }
        i++;
    }
    return string1[i] - string2[i];
}

/*my_strchr*/
int my_strchr(const char *string1, char c) {
    int i = 0;
    while (string1[i] != '\0') {
        if (string1[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}

/*main*/
int main() {
	char string1[SIZE];
	char string2[SIZE];
	char c;
	int num;
	int select;
	int result;
	printf("Please select a function from the following options: \n");
	printf("(1) For my_strcmp\n");
	printf("(2) For my_strncmp\n");
	printf("(3) For my_strchr\n");
	scanf("%d", &select);
	printf("The function you select is: %d\n",select);

	if(select == 1){
		printf("Please enter first string: ");
		scanf("%s",string1);
		printf("Please enter second string: ");
		scanf("%s",string2);
		result = my_strcmp(string1,string2);
		printf("If the value isn't 0 - the strings are different.\npositive value - the first string is greater.\nnegative value - the second string is greater.\n");
		printf("The result of the function implementation: %d\n",result);
	}
	else if(select == 2){
		printf("Please enter first string: ");
		scanf("%s",string1);
		printf("Please enter second string: ");
		scanf("%s",string2);
		printf("Please enter the number of characters to compare: ");
		scanf("%d", &num);
		result = my_strncmp(string1,string2,num);
		printf("If the value isn't 0 - the strings are different.\npositive value - the first string is greater up to %d characters.\nnegative value - the second string is greater up to %d characters.\n", num,num);
		printf("The result of the function implementation: %d\n",result);
	}
	else{
		printf("Please enter your string: ");
		scanf("%s",string1);
		printf("Please enter your char: ");
		scanf(" %c",&c);
		result = my_strchr(string1,c);
		printf("The result of the function implementation: %d\n",result);
	}
	return 0;
}
