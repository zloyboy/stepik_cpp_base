#include <iostream>
using namespace std;

/*void strcat(char *to, const char *from)
{
	if (*to) while(*++to);
	while(*to++ = *from++);
}*/


unsigned strlen(const char *str)
{
	unsigned len = 0;
	while(*str++) len++;
	return len;
}

bool strequal(const char *str1, const char *str2, unsigned size)
{
	for(int i=0; i<size; i++)
		if (*str1++ != *str2++) return false;
	return true;
}

int strstr(const char *text, const char *pattern)
{
	if (*text==0)
	{
		if (*pattern==0) return 0;
		else return -1;
	}
	if (*pattern==0) return 0;

	int textlen = strlen(text);
	int pattlen = strlen(pattern);
	if (textlen < pattlen) return -1;

	for(int i=0; i<(textlen - pattlen + 1); i++)
	{
		if (strequal(text++, pattern, pattlen)) return i;
	}

	return -1;
}

int main()
{
	/*char str1[21] = "0123456789";
	char str2[] = "qwertyuiop";
	strcat(str1, str2);
	cout << str1 << " len:" << strlen(str1) << endl;*/

	//cout << strequal("qwerty", "qwerti", 6) << endl;
		
struct test{
    int ret_value;
    const char *text;
    const char *pattern;
};
test tests[] = {
        {0, "", ""}, //0
        {0, "a", ""}, //1
        {0, "a", "a"}, //2
        {-1, "a", "b"}, //3
        {0, "aa", ""}, //4
        {0, "aa", "a"}, //5
        {0, "ab", "a"}, //6
        {1, "ba", "a"}, //7
        {-1, "bb", "a"}, //8
        {0, "aaa", ""}, //9
        {0, "aaa", "a"}, //10
        {1, "abc", "b"}, //11
        {2, "abc", "c"}, //12
        {-1, "abc", "d"}, //13
        {-1, "a", "aa"}, //14
        {-1, "a", "ba"}, //15
        {-1, "a", "ab"}, //16
        {-1, "a", "bb"}, //17
        {-1, "a", "aaa"}, //18
        {-1, "aa", "aaa"}, //19
        {0, "aaa", "aaa"}, //20
        {0, "aaab", "aaa"}, //21
        {1, "baaa", "aaa"}, //22
        {1, "baaaa", "aaa"}, //23
        {1, "baaab", "aaa"}, //24
        {-1, "abd", "abc"}, //25
        {2, "ababc", "abc"}, //26
        {3, "abdabc", "abc"}, //27
        {-1, "", "a"}, //28
        {2, "asasaf", "asaf"}, //29
        {2, "ababac", "abac"} //30
};
for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
    int ret = strstr(tests[i].text, tests[i].pattern);
    (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
     cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
}

//cout << strstr("hell_hello", "hello") << endl;

return 0;
}
