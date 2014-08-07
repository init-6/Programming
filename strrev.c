#include <stdio.h>
#include <string.h>

void reverse(char* str){
	char* temp = str; // use this temp for calculating string length and make sure to escape only the last null char
	int l = 0;
	while((*temp)!='\0'){
		l++;
		temp++;
	}
	int start = 0, end = l-1; // Escaping the last null character, set the indices to front and back;
	//str--; We dont need these anymore;
	//str--;

	//printf("Char: %c ",*str);

	while(start < end){ // Always use indices when comparing. You were using pointers, not a good idea.
		//Swap the chars
		char t_var = str[start];
		str[start] = str[end];
		str[end] = t_var;

		//printf("Char: %c ",*str);
		//printf("Char: %c \n",*temp);
		start++;
		end--;
	}

}

int main(){
	char name[10];
	fgets(name, 10, stdin);
	// Caution : You have fed one "newline" here!!! Please read on..
	/*
	   Using fgets is a good idea. For one reason, it automatically null terminates the string.
	   So far so good. But, where is the null terminator placed? :)
	   Just after the new line you entered. Do we really need the newline character? Or we entered
	   it in the blink of an eye without realizing we are creating a cute but dangerous bug?

Fix : Either do str-- twice as you did to move two characters back - one for '\0' and one for '\n';
Else, after getting the input, replace the newline character with '\0';
Example : If input is "hello", fgets actually does this :
name[0] = 'h'; name[1] = 'e'; name[2] = 'l'; name[3] = 'l'; name[4] = 'o'; name[5] = '\0';
(The above is what we expected!)
But we actually entered "hello\n' which translates to :
name[0] = 'h'; name[1] = 'e'; name[2] = 'l'; name[3] = 'l'; name[4] = 'o'; name[5] = '\n'; name[6] = '\0';
Cute bug, isn't it? :)
Replace name[5] = '\n' with '\0'; You need strlen function for this (which you are anyway coding to find last null char).
The correct array now looks like : 
name[0] = 'h'; name[1] = 'e'; name[2] = 'l'; name[3] = 'l'; name[4] = 'o'; name[5] = '\0'; name[6] = '\0';
	 */
	int len = strlen(name); // Gives the length of the string before null character;
	name[len-1] = '\0'; // Fix for replacing the newline we entered by a null. Note that this is another null we are manually adding.
	printf("Name: %s\n", name);
	reverse(name);
	printf("Reversed Name: %s\n", name);


	// Happy coding. This is a very interesting bug, the newline bug.

	return 0;
}

