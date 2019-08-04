/*
 * Cyclic Trouble
 * Author: Adarsh

	Input:
	2 4
	>>>v
	<^<<
	abcd
	efgh
	3
	abcdhgf
	bcddhgf(100)
	hello

	Output:
	YES (1,1)
	YES (1,2)
	NO
	
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* find_start_point(char *letters[], char string, int row, int col);
int find_path(char *letters[], char *directions[], char input_string[], int i, int j, int rows, int cols);
int check_for_closing(char input_string[], int k);

int main() 
{
	// Below implementation is in C

	int r,c,n;
	scanf("%d%d",&r,&c);

	char *directions[c];
	char *letters[c];
	
	for(int i=0; i<r; i++) 
	{
		directions[i] =(char*) malloc(c);	
		scanf("%s",directions[i]);
	}

	for(int i=0; i<r; i++)
	{
		letters[i] = (char*) malloc(c);
		scanf("%s",letters[i]);
	}


	scanf("%d",&n);
	
	while(n--)
	{
		char input_string[2000];
		scanf("%s", input_string);

		int *start_point = find_start_point(letters ,input_string[0], r, c);

		if(start_point == NULL)
			printf("NO\n");
		else
		{
			int i = start_point[0];
			int j = start_point[1];

			free(start_point);

			int res = find_path(letters, directions, input_string, i, j, r-1, c-1);

			if(res==1)
				printf("YES (%d,%d)\n",i+1,j+1);
			else
				printf("NO\n");
		}	
	}	

}

int find_path(char *letters[], char *directions[], char input_string[], int i, int j, int rows, int cols) 
{
	int row_index = i;
	int col_index = j;
	int k = 0;

	int length = strlen(input_string);

	while(1)
	{
		char direction = directions[row_index][col_index];
		char letter = letters[row_index][col_index];
		
		if(input_string[k] == '(')
		{
			int res = check_for_closing(input_string, k);

			if(res == -1)
			{
				return 0;
			}
		}

		if(letter != input_string[k] || input_string[k] == '0')
			return 0;

		switch(direction)
		{	
			case '>':
				if(col_index <= cols)
					col_index++;
				break;
			case '<':
				if(col_index <= cols)
					col_index--;
				break;
			case 'v':
				if(row_index <= rows)
					row_index++;
				break;
			case '^':
				if(row_index <= rows)
					row_index--;
				break;
			case '('|')'|'0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9':
				break;

		}
		if(k == length-1)
			return 1;

		k++;
	}
}

int check_for_closing(char string, int k)
{
	//Implement stack
	stack<char> s;
		
	int i = k;

	int brace_flag = 0;

	while(string[i] != '\0')
	{
		if(s.size() == 1)
			brace_flag = 1;
			
		if(string[i] == '(')
		{
			if(brace_flag == 0)
				s.push(string[i]);
			else
				break;
		}
		if(string[i] == ')')
			s.pop();

		i++;
	}

	if(s.size() == 0)
		return 1;
	else
		return 0;

		
}

int* find_start_point(char *letters[], char string, int row, int cols)
{
	int found = 0;
	int *o;
	o = (int*) malloc(2 * sizeof(int));
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(letters[i][j] == string)
			{
				o[0] = i;
				o[1] = j;
				found = 1;
			}
		}
	}

	if(found == 1)
		return o;
	else 
		return NULL;
}
