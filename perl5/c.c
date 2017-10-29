#include <stdio.h>
int main()
{
 char c[30];
	sprintf(c,"%*d",7,0);

	printf("%s\n",c);



	return 0;
}
