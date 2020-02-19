#include <iostream>
#include<string.h>
#include<stdint-gcc.h>
#include <bits/stdc++.h>

using namespace std;

char key[10][5] = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};


void display(int number[], int curr_digit, char output[], int n)
{

	int i;
	if (curr_digit == n)
	{
		printf("%s\n", output);
		return ;
	}

	for (i=0; i<strlen(key[number[curr_digit]]); i++)
	{
		output[curr_digit] = key[number[curr_digit]][i];
		display(number, curr_digit+1, output, n);
		if (number[curr_digit] == 0 || number[curr_digit] == 1)
			return;
	}
}


int main()
{

	int n, j=0;
    cin >> n;
    int number[n];
    char result[n];
    for(int i=0;i<n;++i)
        cin >> number[i];

	display(number, 0, result, n);
	return 0;
}