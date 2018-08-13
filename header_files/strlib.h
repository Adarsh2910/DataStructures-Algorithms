/*
 * strlib.h - Implementation of C string manipulation functions (string.h)
 * Date: 27-July-2018
 *
 * Created By: Adarsh Bhalotia
 */

#include<stdlib.h>

int length(char *string)
{
	int count = 0;

	while(*string != '\0')
	{
		count++;
		string++;
	}
	return count;
}

void copy(char *dest,char *source)
{

	while(*source != '\0') 
	{
		*dest = *source;
		dest++;
		source++;	
	}
}

char* concat(char *a, char *b) 
{
	int lenA = length(a);
	int lenB = length(b);

	char *ab;	
	ab = (char*) malloc(lenA+lenB * sizeof(char));

	copy(ab, a);
	copy(&ab[lenA], b);
	
	return ab;
}

int compare(char *a, char *b)
{
	while(*a != '\0' && *b != '\0')
	{
		if(*a != *b)
			return 0;
		else 
		{
			a++;
			b++;
		}
	}

	if(*a == '\0' && *b == '\0')
	{
		return 1;	
	}
	else
       	{
		return 0;
	}

}

