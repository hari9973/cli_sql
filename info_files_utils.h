
struct info **I = NULL;
int count1 = 0;
int limit1 = 5;

void append_info(struct info *t){
	for (int i = 0; i < count1; i++){
		if (I[i]->rollno == t->rollno)
			return;
	}
	if (count1 == limit1){
		(limit1) += 20;
		I = (struct info **)realloc(I, sizeof(struct info*)*(limit1));
	}
	I[count1] = t;
	(count1)++;
}

struct info* create_info(){
	struct info *temp = (struct info*)malloc(sizeof(struct info));
	temp->rollno = 0;
	temp->Address = NULL;
	temp->city = NULL;
	temp->number = NULL;
	temp->pincode = NULL;
	temp->par = NULL;
	return temp;
}

struct info* store_info(char *str){
	int count = 0, ch, comma = 0;
	struct info *newnode = create_info();
	char arr[10];
	char *arr1 = (char *)malloc(sizeof(char) * 20);
	char *arr2 = (char *)malloc(sizeof(char) * 20);
	char *arr3 = (char *)malloc(sizeof(char) * 20);
	char *arr4 = (char *)malloc(sizeof(char) * 20);
	for (int i = 0; str[i] != '\n'; i++){
		if (str[i] == ','){
			if (comma == 0){
				ch = convert_char_to_int(arr, count);
				newnode->rollno = ch;
			}
			if (comma == 1){
				arr1[count] = '\0';
				newnode->number = arr1;
			}
			if (comma == 2){
				arr2[count] = '\0';
				newnode->Address = arr2;
			}
			if (comma == 3){
				arr3[count] = '\0';
				newnode->city = arr3;
			}
			if (comma == 4){
				arr4[count] = '\0';
				newnode->pincode = arr4;
			}
			count = 0;
			comma++;
		}
		else{
			if (comma == 0){
				arr[count] = str[i];
				count++;
			}
			if (comma == 1){
				arr1[count] = str[i];
				count++;
			}
			if (comma == 2){
				arr2[count] = str[i];
				count++;
			}
			if (comma == 3){
				arr3[count] = str[i];
				count++;
			}
			if (comma == 4){
				arr4[count] = str[i];
				count++;
			}
		}
	}
	if (comma == 4){
		arr4[count] = '\0';
		newnode->pincode = arr4;
	}
	return newnode;
}

void Read_file_info(char *str){
	FILE *ptr;
	struct info *p;
	ptr = fopen(str, "r");
	if (ptr != NULL){
		char *c = (char*)malloc(sizeof(char) * 200);
		fgets(c, 200, ptr);
		while (!feof(ptr)){
			fgets(c, 200, ptr);
			p = store_info(c);
			append_info(p);
		}
		fclose(ptr);
	}
	else printf("\nfile not found\n");
}

void printing_info(){
	for (int i = 0; i < count1; i++){
		printf("\n\n\t\t%10d\t%10s\t%10s%10s%10s\n", I[i]->rollno, I[i]->number, I[i]->Address, I[i]->city, I[i]->pincode);
	}
}

void pairing_student_and_info(){
	for (int i = 0; i < count; i++){
		for (int j = 0; j < count1; j++){
			if (s[i]->roll == I[j]->rollno){
				s[i]->pair = I[j];
				I[j]->par = s[i];
			}
		}
	}
}

void merge_print_left(int f){
	for (int i = 0; i < count1; i++){
		if (I[i]->par != NULL){
			if (f == 0){
				printf("\n%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n", I[i]->rollno, I[i]->number, I[i]->Address, I[i]->city, I[i]->pincode, I[i]->par->name, I[i]->par->m1, I[i]->par->m2, I[i]->par->m3, I[i]->par->m4);
			}
			if (f == 1){
				printf("\n%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", I[i]->rollno, I[i]->number, I[i]->Address, I[i]->city, I[i]->pincode, I[i]->par->name, I[i]->par->m1, I[i]->par->m2, I[i]->par->m3, I[i]->par->m4, I[i]->par->avg);
			}
			if (f == 2){
				printf("\n%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\t%.2f\n", I[i]->rollno, I[i]->number, I[i]->Address, I[i]->city, I[i]->pincode, I[i]->par->name, I[i]->par->m1, I[i]->par->m2, I[i]->par->m3, I[i]->par->m4, I[i]->par->avg, I[i]->par->cgpa);
			}
		}
		if (I[i]->par == NULL){
			if (f == 0){
				printf("\n%d\t%s\t%s\t%s\t%s\n", I[i]->rollno, I[i]->number, I[i]->Address, I[i]->city, I[i]->pincode);
			}
		}
	}
}

void print_info(char *str, info *t, int f){
	if (strcmp(str, "rollno") == 0)
		printf("\t%d", t->rollno);
	if (strcmp(str, "number") == 0)
		printf("\t%s", t->number);
	if (strcmp(str, "address") == 0)
		printf("\t%s", t->Address);
	if (strcmp(str, "city") == 0)
		printf("\t%s", t->city);
	if (strcmp(str, "pincode") == 0)
		printf("\t%s", t->pincode);
	if (t->par != NULL){
		if (strcmp(str, "rollno") == 0)
			printf("\t%d", t->par->roll);
		if (strcmp(str, "name") == 0)
			printf("\t%s", t->par->name);
		if (strcmp(str, "m1") == 0)
			printf("\t%d", t->par->m1);
		if (strcmp(str, "m2") == 0)
			printf("\t%d", t->par->m2);
		if (strcmp(str, "m3") == 0)
			printf("\t%d", t->par->m3);
		if (strcmp(str, "m4") == 0)
			printf("\t%d", t->par->m4);
		if (strcmp(str, "avg") == 0)
			if (f == 1 || f == 2)
				printf("\t%f", t->par->avg);
		if (strcmp(str, "cgpa") == 0)
			if (f == 1 || f == 2)
				printf("\t%f", t->par->cgpa);
	}
}

void print_greater_info(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "rollno") == 0){
		for (int i = 0; i < count; i++){
			if (I[i]->rollno > val){
				for (int j = 0; j < count1; j++){
					print_info(arr[j], I[i], f);
				}
				printf("\n");
			}
		}
	}
}

void print_lessthan_info(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "rollno") == 0){
		for (int i = 0; i < count; i++){
			if (I[i]->rollno < val){
				for (int j = 0; j < count1; j++){
					print_info(arr[j], I[i], f);
				}
				printf("\n");
			}
		}
	}
}

void print_lessthanequal_info(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "rollno") == 0){
		for (int i = 0; i < count; i++){
			if (I[i]->rollno <= val){
				for (int j = 0; j < count1; j++){
					print_info(arr[j], I[i], f);
				}
				printf("\n");
			}
		}
	}
}

void print_greaterthanequal_info(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "rollno") == 0){
		for (int i = 0; i < count; i++){
			if (I[i]->rollno >= val){
				for (int j = 0; j < count1; j++){
					print_info(arr[j], I[i], f);
				}
				printf("\n");
			}
		}
	}
}

void print_notequal_info(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "rollno") == 0){
		for (int i = 0; i < count; i++){
			if (I[i]->rollno != val){
				for (int j = 0; j < count1; j++){
					print_info(arr[j], I[i], f);
				}
				printf("\n");
			}
		}
	}
}

void print_equal_info(char **arr, int count1, char *att, float val, int f){
	if (strcmp(att, "rollno") == 0){
		for (int i = 0; i < count; i++){
			if (I[i]->rollno == val){
				for (int j = 0; j < count1; j++){
					print_info(arr[j], I[i], f);
				}
				printf("\n");
			}
		}
	}
}