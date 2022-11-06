#include <fstream>
#include <string.h>

using namespace std;

struct abonents
{
	int id;
	char name[11];
	char rank[11];
};

struct messages
{
	abonents * sender;
	char time[30];
	char text[31];
	bool flag;
};

int main()
{
	FILE * fp_in = fopen("input.txt", "r");
	FILE * fp_out = fopen("output.txt", "w");
	
	abonents * people[100000];
	people[0] = (abonents*)malloc(sizeof(abonents));
	messages * mes[100000];
	mes[0] = (messages*)malloc(sizeof(messages));
	mes[0]->flag = 0;

	char c;
	int i = 0, temp = 0, j = 0, id_num = 1;
	bool flag_id = 0, flag_text = 0, flag_time = 0, flag_sender = 0, flag_chek = 0;

	while ((c = fgetc(fp_in)) != EOF)
	{
		if (isalnum(c) != 0 || (ispunct(c) != 0 && temp > 1) || (c == ' ' && temp > 1))
		{
			if (flag_id == 0)
			{
				flag_text = 0;
				flag_id = 1;
				people[j]->id = id_num;
				id_num++;
			}
			if (temp == 0)
			{
				people[j]->rank[i] = c;
				people[j]->rank[i + 1] = 0;
			}
			else if (temp == 1)
			{
				people[j]->name[i] = c;
				people[j]->name[i + 1] = 0;
			}
			else if (temp == 2)
			{
				if (flag_sender == 0)
				{
					mes[j]->sender = people[j];
					flag_sender = 1;
				}
				if (c != '(' && c != ')')
				mes[j]->time[i - 1] = c;
				mes[j]->time[i] = 0;
			}
			else if (temp == 3)
			{
				mes[j]->text[i] = c;
				mes[j]->text[i + 1] = 0;
			}
			i++;
		}
		else
		{
			if (c == '\n')
			{
				if (flag_time == 0 && flag_text != 1)
				{
					mes[j]->time[i - 1] = 0;
					flag_time = 1;
				}
				else if (flag_text == 0 && flag_time == 1)
				{
					flag_text = 1;
					temp++;
				}
			}
			i = 0;
			
			if (flag_text != 1)	temp++;
			if (temp == 4)
			{
				temp = 0;
				j++;
				flag_id = 0;
				flag_time = 0;
				flag_sender = 0;
				people[j] = (abonents*)malloc(sizeof(abonents));
				mes[j] = (messages*)malloc(sizeof(messages));
				mes[j]->flag = 0;
			}
		}
	}
	bool flag_hold = 0;
	for (i = 0; i <= j; i++)
	{
		for (int k = i + 1; k <= j; k++)
		{
			flag_chek = (strcmp(mes[i]->sender->name, mes[k]->sender->name) || strcmp(mes[i]->sender->rank, mes[k]->sender->rank));
			if (flag_chek == 0)
			{
				mes[k]->flag = 1;
				mes[k]->sender = mes[i]->sender;
				flag_hold = 1;
			}
			if (flag_hold == 1)
			{
				if (k == j) break;
				people[k + 1]->id -= 1;
			}
		}
		flag_hold = 0;
	}

	fprintf(fp_out, "<abonents>\n");
	for (i = 0; i <= j; i++)
	{
		if (mes[i]->flag == 0)
			fprintf(fp_out, "\t<abonent>\n\t\t<id>%d</id>\n\t\t<rank>%s</rank>\n\t\t<name>%s</name>\n\t</abonent>\n", mes[i]->sender->id, mes[i]->sender->rank, mes[i]->sender->name);
	}
	fprintf(fp_out, "</abonents>\n<messages>\n");
	for (i = 0; i <= j; i++)
	{
		fprintf(fp_out, "\t<message>\n\t\t<sender>%d</sender>\n\t\t<time>%s</time>\n\t\t<text>%s</text>\n\t</message>\n", mes[i]->sender->id, mes[i]->time, mes[i]->text);
	}
	fprintf(fp_out, "</messages>");

	return 0;
}