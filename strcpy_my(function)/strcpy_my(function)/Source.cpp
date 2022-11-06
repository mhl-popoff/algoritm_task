#include <iostream>
char * strcpy_my(char * d, char * s)
{
	*d = *s;
	if (*s == 0)
		return 0;
	strcpy_my(d + 1, s + 1);
	return d;
}

int strcmp_my(char * s1, char * s2)
{
	if (*s1 > *s2) return 1;
	if (*s1 < *s2) return -1;
	if (*s1 == 0) return 0;
	return strcmp_my(s1 + 1, s2 + 1);
}

char * strncpy_my(char * d, char * s, int n)
{
	*d = *s;
	if (n == 0 || *s == 0)
	{
		*d = 0;
		return d;
	}
	strncpy_my(d + 1, s + 1, n - 1);
	return d;
}

int strncmp_r(char * s1, char * s2, int n)
{
	if (n == 0) return 0;
	if (*s1 < *s2) return -1;
	if (*s1 > *s2) return 1;
	if (*s1 == 0 && *s2 == 0) return 0;
	return strncmp_r(s1 + 1, s2 + 1, n - 1);
}

char * strstr_r(char * haystack, char * needle)
{
	if (*haystack == 0) return NULL;
	if (strncmp_r(haystack, needle, strlen(needle)) == 0)
		return haystack;
	return strstr_r(haystack + 1, needle);
}

int main()
{
	char str_d[5], str_s[] = {"ABCD"};
	int flag; 
	
	strcpy_my(str_d, str_s);
	
	str_d[3] = 'A';
	flag = strcmp_my(str_d, str_s);
	
	strncpy_my(str_d, str_s, 1);
	str_d[0] = 'B';
	//str_d[1] = 'D';

	flag = strncmp_r(str_d, str_s, 3);

	char * a = strstr_r(str_s, str_d);

	return 0;
}