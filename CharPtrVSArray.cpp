#include <stdio.h>
#include <iostream>
using namespace std;

void fnk1(char s[])
{
    s[0]  = 's';
}

int main()
{
    // array is always passed by pointer
    // fnk1(char []) is by default converted to fnk1(char * )
    // when fnk1 is called, fnk1(s) -> fnk1(&s) === fnk1(&s[0])
	char s1[] = "test";
	fnk1(s1);
	// print sest instead of test, because arrays are passed in by pointer
	printf("\n%s", s1);
	// the following 4 lines prints the same 
	printf("\n%p", s1); 
	printf("\n%p", (char*)s1);
	printf("\n%p", &s1); 
	printf("\n%p", &s1[0]); 
	
	//when char * points to char array, the ptr can have the same syntax as char[]
	cout<<"\n-----------------------"<<endl;
	char * s2  = s1;
	// cout prints char * as string
	cout<<"\n"<<s2;
	s2[0] = 't';
	printf("\n%s", s2);
	//passing in s2 is the same as passing in s1
	fnk1(s2);
	printf("\n%s", s2);
	
	// when assigning to char * a string, a strng literal is created in readonly section
	cout<<"\n-----------------------"<<endl;
	// add const to avoid warning because prt points to a readonly section
	char * s3 = "literal";
	printf("\n%s", s3);
	// folloing line is invalid because s2 points to a readonly secion, declare as char const * to avoid warning
    // s3[0] = 't';
    s3 = s2; 
    s3[0] = 'a'; // would be invalid if declared as char const * 
    printf("\n%s", s3);
    cout<<"\n-----------------------"<<endl;
	return 0;
}
