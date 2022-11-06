#include <fstream>

using namespace std;

ifstream fin("INPUT.TXT");
ofstream fout("OUTPUT.TXT");

struct abonents
{
	int id;
	char name[11], rank[11];
};

struct message
{
	abonents * ptr;
	int sender;
	char time[17];
	char text[31];
	bool flag;
};

int main()
{
	FILE * fp = fopen("INPUT.TXT", "r");
	char str[10000], c;
	int i = 0, j, k = 0, q = 0, hold, temp = 0;
	bool flag_id = 0, flag_name = 0, flag_rank = 0, flag_sender = 0, flag_time = 0, flag_text = 0;
	abonents * people[100000];
	people[k] = (abonents*)malloc(sizeof(abonents));
	message * messages[100000];
	messages[q] = (message*)malloc(sizeof(message));
	message * hold_struct;

	while ((c = fgetc(fp)) != EOF)
	{
		str[i] = c;
		i++;
	}
	str[i] = 0;
	i = 0;

	//fout << str << '\n';

	while (str[i] != 0)
	{
		if (str[i] == '<')
		{
			if (str[i + 1] == 'i' && str[i + 2] == 'd'&& str[i + 3] == '>')
			{
				people[k]->id = (int)str[i + 4] - 48;
				flag_id = 1;
				i += 10;
			}
			else if (str[i + 1] == 'r' && str[i + 2] == 'a'&& str[i + 3] == 'n' && str[i + 4] == 'k'&& str[i + 5] == '>')
			{
				j = 0;
				i += 6;
				while (str[i] != '<')
				{
					people[k]->rank[j] = str[i];
					i++;
					j++;
				}
				people[k]->rank[j] = 0;
				i += 7;
				flag_rank = 1;
			}
			else if (str[i + 1] == 'n' && str[i + 2] == 'a'&& str[i + 3] == 'm' && str[i + 4] == 'e'&& str[i + 5] == '>')
			{
				j = 0;
				i += 6;
				while (str[i] != '<')
				{
					people[k]->name[j] = str[i];
					i++;
					j++;
				}
				people[k]->name[j] = 0;
				i += 7;
				flag_name = 1;
			}
			else if (str[i + 1] == 's' && str[i + 2] == 'e'&& str[i + 3] == 'n' && str[i + 4] == 'd'&& str[i + 5] == 'e' && str[i + 6] == 'r' && str[i + 7] == '>')
			{
				messages[q]->sender = (int)str[i + 8] - 48;
				flag_sender = 1;
				i += 18;
				k = 0;
				while (people[k])
				{
					if (messages[q]->sender == people[k]->id)
					{
						messages[q]->ptr = people[k];
						break;
					}
					k++;
				}
			}
			else if (str[i + 1] == 't' && str[i + 2] == 'i'&& str[i + 3] == 'm' && str[i + 4] == 'e'&& str[i + 5] == '>')
			{
				j = 0;
				i += 6;
				while (str[i] != '<')
				{
					messages[q]->time[j] = str[i];
					i++;
					j++;
				}
				messages[q]->time[j] = 0;
				i += 7;
				flag_time = 1;
			}
			else if (str[i + 1] == 't' && str[i + 2] == 'e'&& str[i + 3] == 'x' && str[i + 4] == 't'&& str[i + 5] == '>')
			{
				j = 0;
				i += 6;
				while (str[i] != '<')
				{
					messages[q]->text[j] = str[i];
					i++;
					j++;
				}
				messages[q]->text[j] = 0;
				i += 7;
				flag_text = 1;
			}

		}
		i++;
		if (flag_id == 1 && flag_name == 1 && flag_rank == 1)
		{
			k++;
			people[k] = (abonents*)malloc(sizeof(abonents));
			flag_id = 0;
			flag_name = 0;
			flag_rank = 0;
		}
		else if (flag_sender == 1 && flag_time == 1 && flag_text == 1)
		{
			messages[q]->flag = 0;
			q++;
			temp++;
			messages[q] = (message*)malloc(sizeof(message));
			flag_sender = 0;
			flag_time = 0;
			flag_text = 0;
		}
	}
	/*k = 2;
	fout << people[k]->id << ' ' << people[k]->name << ' ' << people[k]->rank << '\n';
	q = 0;
	fout << messages[q]->sender << ' ' << messages[q]->time << ' ' << messages[q]->text;*/
	k = 0;
	while (k < temp)
	{
		hold_struct = messages[k];
		q = k + 1;
		while (q < temp)
		{
			hold = strcmp(messages[k]->time, messages[q]->time);
			if (hold > 0 && messages[q]->flag == 0)
			{
				hold_struct = messages[q];
				messages[q] = messages[k];
				messages[k] = hold_struct;
			}
			q++;
		}
		hold_struct->flag = 1;
		fout << hold_struct->ptr->rank << ' ' << hold_struct->ptr->name << ' ' << hold_struct->time << ":\n" << hold_struct->text << "\n\n";

		k++;
	}

	return 0;
}