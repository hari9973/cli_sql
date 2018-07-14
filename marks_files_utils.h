#include "functionheaders.h"

typedef struct info {
	int rollno;
	char *number;
	char *Address;
	char *city;
	char *pincode;
	struct student *par;
};

struct student{
	char *name;
	int roll;
	int m1;
	int m2;
	int m3;
	int m4;
	float avg;
	float cgpa;
	struct info *pair;
};

struct student **s = NULL;
int count = 0;
int limit = 5;


struct student * create_student(){
	struct student *temp = (struct student*)malloc(sizeof(struct student));
	temp->name = NULL;
	temp->roll = 0;
	temp->m1 = 0;
	temp->m2 = 0;
	temp->m3 = 0;
	temp->m4 = 0;
	temp->avg = 0;
	temp->cgpa = 0;
	temp->pair = NULL;
	return temp;
}


struct student* store_student(char *str){
	int count = 0, ch;
	struct student *newnode = create_student();
	char arr1[20];
	int comma = 0;
	newnode->name = (char*)malloc(sizeof(char) * 20);
	for (int i = 0; str[i] != '\n'; i++){
		if (str[i] == ','){
			if (comma != 1)
				ch = convert_char_to_int(arr1, count);
			if (comma == 0)
				newnode->roll = ch;
			if (comma == 1){
				newnode->name[count] = '\0';
			}
			if (comma == 2)
				newnode->m1 = ch;
			if (comma == 3)
				newnode->m2 = ch;
			if (comma == 4)
				newnode->m3 = ch;
			comma += 1;
			count = 0;
		}
		else {
			arr1[count] = str[i];
			if (comma == 1)
				newnode->name[count] = str[i];
			count++;
		}
	}
	ch = convert_char_to_int(arr1, count);
	if (comma == 5)
		newnode->m4 = ch;
	return newnode;
}

void append_student(struct student *t){
	int ch;
	for (int i = 0; i < count; i++){
		if (s[i]->roll == t->roll){
			printf("\nduplicate found \n");
			printf("actual:-%d,%s,%d,%d,%d,%d\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4);
			printf("duplicate:-%d,%s,%d,%d,%d,%d\n", t->roll, t->name, t->m1, t->m2, t->m3, t->m4);
			printf("1.update\n");
			printf("2.drop\n");
			scanf("%d", &ch);
			system("cls");
			if (ch == 1){
				s[i] = t;
				return;
			}
			else return;
		}
	}
	if (count == limit){
		(limit) += 20;
		s = (struct student **)realloc(s, sizeof(struct student*)*(limit));
	}
	s[count] = t;
	(count)++;
}

void Read_file_student(char *str){
	FILE *ptr;
	struct student *p;
	ptr = fopen(str, "r");
	if (ptr != NULL){
		char *c = (char *)malloc(sizeof(char) * 200);
		fgets(c, 200, ptr);
		while (!feof(ptr)){
			fgets(c, 200, ptr);
			p = store_student(c);
			append_student(p);
		}
		fclose(ptr);
	}
	else printf("\nfile not found\n");
}

void printing_student(int f){
	if (f == 0){
		printf("       ROLL     Name        M1        m2         m3        m4\n");
		printf("       _______________________________________________________\n");
	}
	if (f == 1){
		printf("       ROLL     Name        M1        m2         m3        m4        AVG\n");
		printf("       __________________________________________________________________\n");
	}
	if (f == 2){
		printf("       ROLL     Name        M1        m2         m3        m4        AVG        CGPA\n");
		printf("       _______________________________________________________________________________\n");
	}
	for (int i = 0; i < count; i++){
		if (f == 0)
			printf("%10d%10s%10d%10d%10d%10d\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4);
		if (f == 1)
			printf("%10d%10s%10d%10d%10d%10d%10.2f\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4, s[i]->avg);
		if (f == 2)
			printf("%10d%10s%10d%10d%10d%10d%10.2f%10.2f\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4, s[i]->avg, s[i]->cgpa);
	}
}

void compute_Avg(){
	float av = 0;
	for (int i = 0; i < count; i++){
		av += (s[i]->m1 + s[i]->m2 + s[i]->m3 + s[i]->m4);
		av /= 4;
		s[i]->avg = av;
		av = 0;
	}
}

int grade(int mar){
	if (mar == 100)
		return 10;
	else
		return (mar / 10) + 1;
}

void compute_Cgpa(){
	int m1, m2, m3, m4, cgpa;
	for (int i = 0; i < count; i++){
		m1 = grade(s[i]->m1);
		m2 = grade(s[i]->m2);
		m3 = grade(s[i]->m3);
		m4 = grade(s[i]->m4);
		cgpa = m1 + m2 + m3 + m4;
		cgpa /= 4;
		s[i]->cgpa = cgpa;
		cgpa = 0;
	}
}

void Merge_print_right(int f){
	for (int i = 0; i < count; i++){
		if (s[i]->pair != NULL){
			if (f == 0){
				printf("\n\t%d\t%s\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4, s[i]->pair->number, s[i]->pair->Address, s[i]->pair->city, s[i]->pair->pincode);
			}
			if (f == 1){
				printf("\n\t%d\t%s\t%d\t%d\t%d\t%d\t%.2f\t%s\t%s\t%s\t%s\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4, s[i]->avg, s[i]->pair->number, s[i]->pair->Address, s[i]->pair->city, s[i]->pair->pincode);
			}
			if (f == 2){
				printf("\n\t%d\t%s\t%d\t%d\t%d\t%d\t%.2f\t%.2f\t%s\t%s\t%s\t%s\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4, s[i]->avg, s[i]->cgpa, s[i]->pair->number, s[i]->pair->Address, s[i]->pair->city, s[i]->pair->pincode);
			}
		}
		if (s[i]->pair == NULL){
			if (f == 0){
				printf("\n\t%d\t%s\t%d\t%d\t%d\t%d\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4);
			}
			if (f == 1){
				printf("\n\t%d\t%s\t%d\t%d\t%d\t%d\t%.2f\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4, s[i]->avg);
			}
			if (f == 2){
				printf("\n\t%d\t%s\t%d\t%d\t%d\t%d\t%.2f\t%.2f\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4, s[i]->avg, s[i]->cgpa);
			}
		}
	}
}

void Merge_print_inner(int f){
	for (int i = 0; i < count; i++){
		if (s[i]->pair != NULL){
			if (f == 0){
				printf("\n\t%d\t%s\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4, s[i]->pair->number, s[i]->pair->Address, s[i]->pair->city, s[i]->pair->pincode);
			}
			if (f == 1){
				printf("\n\t%d\t%s\t%d\t%d\t%d\t%d\t%.2f\t%s\t%s\t%s\t%s\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4, s[i]->avg, s[i]->pair->number, s[i]->pair->Address, s[i]->pair->city, s[i]->pair->pincode);
			}
			if (f == 2){
				printf("\n\t%d\t%s\t%d\t%d\t%d\t%d\t%.2f\t%.2f\t%s\t%s\t%s\t%s\n", s[i]->roll, s[i]->name, s[i]->m1, s[i]->m2, s[i]->m3, s[i]->m4, s[i]->avg, s[i]->cgpa, s[i]->pair->number, s[i]->pair->Address, s[i]->pair->city, s[i]->pair->pincode);
			}
		}
	}
}

void print(char *str, student *t, int f){
	if (strcmp(str, "roll") == 0)
		printf("\t%d", t->roll);
	if (strcmp(str, "name") == 0)
		printf("\t%s", t->name);
	if (strcmp(str, "m1") == 0)
		printf("\t%d", t->m1);
	if (strcmp(str, "m2") == 0)
		printf("\t%d", t->m2);
	if (strcmp(str, "m3") == 0)
		printf("\t%d", t->m3);
	if (strcmp(str, "m4") == 0)
		printf("\t%d", t->m4);
	if (strcmp(str, "avg") == 0)
		if (f == 1 || f == 2)
			printf("\t%f", t->avg);
	if (strcmp(str, "cgpa") == 0)
		if (f == 1 || f == 2)
			printf("\t%f", t->cgpa);
	if (t->pair != NULL){
		if (strcmp(str, "rollno") == 0)
			printf("\t%d", t->pair->rollno);
		if (strcmp(str, "number") == 0)
			printf("\t%s", t->pair->number);
		if (strcmp(str, "address") == 0)
			printf("\t%s", t->pair->Address);
		if (strcmp(str, "city") == 0)
			printf("\t%s", t->pair->city);
		if (strcmp(str, "pincode") == 0)
			printf("\t%s", t->pair->pincode);
	}
}

void print_greater_student(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->roll > val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m1") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m1 > val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m2") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m2 > val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m3") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m3 > val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m4") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m4 > val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->avg > val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\navg not calculated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->cgpa > val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\ncgpa not calculated\n");
	}
}

void print_lessthan_student(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->roll < val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m1") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m1 < val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m2") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m2 < val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m3") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m3 < val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m4") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m4 < val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->avg < val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\navg not calculated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->cgpa < val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\ncgpa not calculated\n");
	}
}

void print_lessthanequal_student(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->roll <= val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m1") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m1 <= val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m2") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m2 <= val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m3") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m3 <= val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m4") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m4 <= val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->avg <= val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\navg not calculated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->cgpa <= val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\ncgpa not calculated\n");
	}
}

void print_greaterthanequal_student(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->roll >= val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m1") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m1 >= val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m2") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m2 >= val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m3") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m3 >= val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m4") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m4 >= val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->avg >= val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\navg not calculated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->cgpa >= val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\ncgpa not calculated\n");
	}
}

void print_notequal_student(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->roll != val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m1") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m1 != val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m2") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m2 != val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m3") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m3 != val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m4") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m4 != val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->avg != val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\navg not calculated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->cgpa != val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\ncgpa not calculated\n");
	}
}

void print_equal_student(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->roll == val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m1") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m1 == val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m2") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m2 == val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m3") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m3 == val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "m4") == 0){
		for (int i = 0; i < count; i++){
			if (s[i]->m4 == val){
				for (int j = 0; j < count1; j++){
					print(arr[j], s[i], f);
				}
				printf("\n");
			}
		}
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->avg == val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\navg not calculated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 1 || f == 2){
			for (int i = 0; i < count; i++){
				if (s[i]->cgpa == val){
					for (int j = 0; j < count1; j++){
						print(arr[j], s[i], f);
					}
					printf("\n");
				}
			}
		}
		else printf("\ncgpa not calculated\n");
	}
}