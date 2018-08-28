#include <stdio.h>
#include <string.h>


// Fill in the blanks to the program prints "hello"
//void fnc1(/*blank1*/)
//{
//	/*blank2*/
//}

//int main()
//{
//	char * str; 
//	fnc1(/*blank3*/);
//	printf("%s", str);
//	return 0;
//}


// Following does not work because the original ptr does not change
void fnc0(char * & s)
{
	s = "hello\n";
}

void fnc1(char * & s)
{
	s = "hello\n";
}


void fnc2(char ** s)
{
	*(s) = "hello\n";
}

void fnc3(char * & s)
{
	s = new char[7]();
	memcpy(s, "hello\n", 7);
}

int main()
{
	// Impl1 str1 points to a string literal in readonly section
	char * str1; 
	fnc1(str1);
	printf("%s", str1);
	printf("%c\n", str1[4]);

	// Impl2 str2 points to a string literal in readonly section, C style when could not pass by ref
	char * str2; 
	fnc2(&str2);
	printf("%s", str2);
	printf("%c\n", str2[4]);

	//Impl3 str3 points to heap memory
	char * str3; 
	fnc3(str3);
	printf("%s", str3);
	printf("%c\n", str3[4]);
	//
	return 0;
}