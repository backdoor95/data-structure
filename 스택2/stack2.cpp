#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct CheckValid
{
	int cnt;
	bool TrueAndFalse;
}CI;
CI Pare(char* s)
{
	CI p;
	p.cnt = 0;
	int type1_1 = 0, type1_2 = 0;
	int type2_1 = 0, type2_2 = 0;
	int type3_1 = 0, type3_2 = 0;
	int i = 0;
	bool flag = 0;
	while (s[i])
	{
		switch (s[i])
		{
		case '(':
			type1_1++;
			p.cnt++;
			i++;
			break;
		case ')':
			type1_2++;
			p.cnt++;
			i++;
			break;
		case '{':
			type2_1++;
			p.cnt++;
			i++;
			break;
		case '}':
			type2_2++;
			p.cnt++;
			i++;
			break;
		case '[':
			type3_1++;
			p.cnt++;
			i++;
			break;
		case ']':
			type3_2++;
			p.cnt++;
			i++;
			break;
		default:
			i++;
			break;
		}
	}
	if ((type1_1 == type1_2) && (type2_1 == type2_2) && (type3_1 == type3_2))
		p.TrueAndFalse = true;
	else
		p.TrueAndFalse = false;
	return p;
	
}
int main() {

	char str[1001];
	int n;
	CI k;
	gets_s(str, 1001);
	//gets(str);
	k=Pare(str);

	if (k.TrueAndFalse)
		printf("OK_%d", k.cnt);
	else
		printf("Wrong_%d", k.cnt);

	return 0;
}