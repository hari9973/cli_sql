#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "marks_files_utils.h"
#include "info_files_utils.h"
#include "query_files_utils.h"

char * read(){
	char *temp = NULL, ch;
	int count = 0, t = 2;
	temp = (char*)malloc(sizeof(char)*t);
	while ((ch = getchar()) != '\n' || count == 0){
		if (ch != '\n'){
			temp[count] = ch;
			count++;
			if (count == t){
				t += 2;
				temp = (char*)realloc(temp, sizeof(char)*t);
			}
		}
	}
	temp[count] = '\0';
	return temp;
}

int convert_char_to_int(char *arr, int count){
	int t = 1;
	int ans = 0;
	for (int i = count - 1; i >= 0; i--){
		ans += (t*(arr[i] - '0'));
		t = t * 10;
	}
	return ans;
}

int main(){
	s = (struct student **)malloc(sizeof(struct student *)*limit);//student marks array of pointers
	I = (struct info **)malloc(sizeof(struct info *)*limit1);     //info array of pointers
	struct item **hashtable;
	int hashsize = 10;
	hashtable = (item**)malloc(sizeof(item)*hashsize);
	for (int i = 0; i < hashsize; i++)
		hashtable[i] = NULL;
	int ch, ch1, ch2, t = 0, t1 = 0;
	int input_string_size = 5, input_string_cur = 0;
	char **input_strings = (char **)malloc(sizeof(char*)*input_string_size);
	struct info *y1, *e1;
	struct student *e, *y;
	char *q;
	FILE *p;
	int flag = 0;
	while (1){
		printf("\n1.load \n");
		printf("\n2.load new file\n");
		printf("\n3.show\n");
		printf("\n4.print merged file\n");
		printf("\n5.compute Average\n");
		printf("\n6.compute CGPA\n");
		printf("\n7.query\n");
		printf("\n8.load\n");
		printf("\n9.exit\n");
		printf("\nenter your choice:-");
		scanf("%d", &ch);
		system("cls");
		if (ch == 1){
			printf("\n1.Marks file\n");
			printf("\n2.Info file\n");
			scanf("%d", &ch1);
			system("cls");
			if (ch1 == 1){
				t = 1;
				printf("\nenter the marks file name:-");
				input_strings[input_string_cur] = read();
				Read_file_student(input_strings[input_string_cur]);
				input_string_cur++;
				if (input_string_cur == input_string_size){
					input_string_size += 1;
					input_strings = (char**)realloc(input_strings, sizeof(char*)*input_string_size);
				}
			}
			else if (ch1 == 2){
				t1 = 1;
				printf("\nenter the Info file name:-");
				input_strings[input_string_cur] = read();
				Read_file_info(input_strings[input_string_cur]);
				input_string_cur++;
				if (input_string_cur == input_string_size){
					input_string_size += 1;
					input_strings = (char**)realloc(input_strings, sizeof(char*)*input_string_size);
				}
			}
		}
		else if (ch == 2){
			printf("\n1.Marks file\n");
			printf("\n2.Info file\n");
			printf("\nenter your choice:-");
			scanf("%d", &ch1);
			system("cls");
			if (ch1 == 1){
				printf("\nenter the marks file name:-");
				input_strings[input_string_cur] = read();
				Read_file_student(input_strings[input_string_cur]);
				input_string_cur++;
				if (input_string_cur == input_string_size){
					input_string_size += 1;
					input_strings = (char**)realloc(input_strings, sizeof(char*)*input_string_size);
				}
			}
			if (ch1 == 2){
				printf("\nenter the Info file name:-");
				input_strings[input_string_cur] = read();
				Read_file_info(input_strings[input_string_cur]);
				input_string_cur++;
				if (input_string_cur == input_string_size){
					input_string_size += 1;
					input_strings = (char**)realloc(input_strings, sizeof(char*)*input_string_size);
				}
			}
		}
		else if (ch == 3){
			printf("\n1.print student file\n");
			printf("\n2.print info file\n");
			printf("\nenter your choice:-");
			scanf("%d", &ch2);
			system("cls");
			if (ch2 == 1){
				if (t == 1)
					printing_student(flag);
				else printf("\nfile not loaded\n");
			}
			if (ch2 == 2){
				if (t1 == 1)
					printing_info();
				else printf("\nfile not loaded\n");
			}
		}
		else if (ch == 4){
			printf("\n1.inner join\n");
			printf("\n2.rigth join\n");
			printf("\n3.left join");
			printf("\nenter your choice:-");
			scanf("%d", &ch1);
			system("cls");
			pairing_student_and_info();
			if (ch1 == 2 && t == 1 && t1 == 1){
				Merge_print_right(flag);
			}
			if (ch1 == 1 && t == 1 && t1 == 1){
				Merge_print_inner(flag);
			}
			if (ch1 == 3 && t == 1 && t1 == 1)
				merge_print_left(flag);
		}
		else if (ch == 5){
			if (t == 1){
				compute_Avg();
				flag = 1;
			}
			else printf("\nfile not loaded\n");
		}
		else if (ch == 6){
			if (t == 1){
				compute_Cgpa();
				flag = 2;
			}
		}
		else if (ch == 7){
			printf("\n1.simple query type:-(attribute [operator symbol] value)\n");
			printf("\teg:-m1 lt 20\n");
			printf("\n2.complex query type:-(select att1,..,attn from [first_loaded_file_name] [where condition_without_space])\n");
			printf("\teg:-select m1,address from marks1 where m3>50\n");
			printf("\nenter your choice:-");
			scanf("%d", &ch2);
			pairing_student_and_info();
			printf("enter the quary\n");
			q = read();
			if (ch2 == 2){
				int r = query_validate(q, hashtable, hashsize);
				if (r == 1){
					int index_t2 = hash_code("t2", hashsize);
					strcat(hashtable[index_t2]->name, ".txt");
					int file_check = check_availability_file(hashtable[index_t2]->name, input_strings, input_string_cur);
					if (file_check == 1 && t == 1 && t1 == 1){
						process_query(hashtable, hashsize, input_strings, flag);
					}
					else printf("\n file not available\n");
				}
				else
					printf("\nentered string is not in standerd format\n");
				for (int i = 0; i < hashsize; i++){
					if (hashtable[i] != NULL)
						hashtable[i] = NULL;
				}
			}
			if (ch2 == 1){
				query_process(q, flag);
			}
		}
		else if (ch == 8){
			printf("\nenter new file name\n");
			char *input = read();
			p = fopen(input, "w");
			fprintf(p, "ROLL No,NAME,M1,M2,M3,M4,AVG,CGPA\n");
			for (int i = 0; i < count1; i++){
				fprintf(p, "%d", s[i]->roll);
				fprintf(p, ",");
				fprintf(p, s[i]->name);
				fprintf(p, ",");
				fprintf(p, "%d", s[i]->m1);
				fprintf(p, ",");
				fprintf(p, "%d", s[i]->m2);
				fprintf(p, ",");
				fprintf(p, "%d", s[i]->m3);
				fprintf(p, ",");
				fprintf(p, "%d", s[i]->m4);
				fprintf(p, ",");
				fprintf(p, "%f", s[i]->avg);
				fprintf(p, ",");
				fprintf(p, "%f", s[i]->cgpa);
				fprintf(p, "\n");
			}
		}
		else if (ch == 9){
			for (int i = 0; i < count; i++)
				free(s[i]);
			free(s);
			for (int i = 0; i < count1; i++)
				free(I[i]);
			free(I);
			for (int i = 0; i < hashsize; i++)
				free(hashtable[i]);
			free(hashtable);
			for (int i = 0; i < input_string_cur; i++)
				free(input_strings[i]);
			free(input_strings);
			exit(0);
		}
	}
	return 0;
}