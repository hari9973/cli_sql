struct item{
	char *name;
	char *key;
	struct item *next;
};

void print_query(struct student *s, int f){
	if (f == 0)
		printf("%d\t%s\t%d\t%d\t%d\t%d\n", s->roll, s->name, s->m1, s->m2, s->m3, s->m4);
	if (f == 1)
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%.2f\n", s->roll, s->name, s->m1, s->m2, s->m3, s->m4, s->avg);
	if (f == 2)
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%.2f\t%.2f\n", s->roll, s->name, s->m1, s->m2, s->m3, s->m4, s->avg, s->cgpa);
}

void less_than(char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		printf("roll numbers less than %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->roll < val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m1") == 0){
		printf("m1 marks less than %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m1 < val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m2") == 0){
		printf("m2 marks less than %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m2 < val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m3") == 0){
		printf("m3 marks less than %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m3 < val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m4") == 0){
		printf("m4 marks less than %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m4 < val)
				print_query(s[i], f);
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			printf("avg marks less than %.2f\n", val);
			for (int i = 0; i < count; i++)
				if (s[i]->avg < val)
					print_query(s[i], f);
		}
		else printf("\navg not evaluated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 2){
			printf("cgpa less than %.2f\n", val);
			for (int i = 0; i < count; i++)
				if (s[i]->cgpa < val)
					print_query(s[i], f);
		}
		else printf("\ncgpa not evaluated\n");
	}
}

void equal_to(char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		printf("roll numbers equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->roll == val){
				print_query(s[i], f);
			}
	}
	if (strcmp(att, "m1") == 0){
		printf("m1 marks equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m1 == val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m2") == 0){
		printf("m2 marks equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m2 == val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m3") == 0){
		printf("m3 marks equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m3 == val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m4") == 0){
		printf("m4 marks equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m4 == val)
				print_query(s[i], f);
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			printf("avg marks equal to %.2f\n", val);
			for (int i = 0; i < count; i++)
				if (s[i]->avg == val)
					print_query(s[i], f);
		}
		else printf("\navg not evaluated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 2){
			printf("cgpa equal to %.2f\n", val);
			for (int i = 0; i < count; i++)
				if (s[i]->cgpa == val)
					print_query(s[i], f);
		}
		else printf("\ncgpa not evaluated\n");
	}
}

void greater_than(char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		printf("roll numbers greater than %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->roll > val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m1") == 0){
		printf("m1 greater than %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m1 > val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m2") == 0){
		printf("m2 greater than %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m2 > val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m3") == 0){
		printf("m3 greater than %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m3 > val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m4") == 0){
		printf("m4 greater than %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m4 > val)
				print_query(s[i], f);
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			printf("avg greater than %.2f\n", val);
			for (int i = 0; i < count; i++)
				if (s[i]->avg > val)
					print_query(s[i], f);
		}
		else printf("\navg not evaluated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 2){
			printf("cgpa greater than %.2f\n", val);
			for (int i = 0; i < count; i++)
				if (s[i]->cgpa > val)
					print_query(s[i], f);
		}
		else printf("\ncgpa not evaluated\n");
	}
}

void less_than_equal(char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		printf("roll numbers less than or equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->roll <= val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m1") == 0){
		printf("m1 less than or equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m1 <= val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m2") == 0){
		printf("m2 less than or equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m2 <= val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m3") == 0){
		printf("m3 less than or equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m3 <= val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m4") == 0){
		printf("m4 less than or equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m4 <= val)
				print_query(s[i], f);
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			printf("avg less than or equal to %.2f\n", val);
			for (int i = 0; i < count; i++)
				if (s[i]->avg <= val)
					print_query(s[i], f);
		}
		else printf("\navg not evaluated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 2){
			printf("cgpa less than or equal to %.2f\n", val);
			for (int i = 0; i < count; i++)
				if (s[i]->cgpa <= val)
					print_query(s[i], f);
		}
		else printf("\ncgpa not evaluated\n");
	}
}

void greater_than_equal(char *att, float val, int f){
	if (strcmp(att, "roll") == 0){
		printf("roll number greater than or equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->roll >= val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m1") == 0){
		printf("m1 greater than or equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m1 >= val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m2") == 0){
		printf("m2 greater than or equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m2 >= val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m3") == 0){
		printf("m3 greater than or equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m3 >= val)
				print_query(s[i], f);
	}
	if (strcmp(att, "m4") == 0){
		printf("m4 greater than or equal to %f\n", val);
		for (int i = 0; i < count; i++)
			if (s[i]->m4 >= val)
				print_query(s[i], f);
	}
	if (strcmp(att, "avg") == 0){
		if (f == 1 || f == 2){
			printf("avg greater than or equal to %.2f\n", val);
			for (int i = 0; i < count; i++)
				if (s[i]->avg >= val)
					print_query(s[i], f);
		}
		else printf("\navg not evaluated\n");
	}
	if (strcmp(att, "cgpa") == 0){
		if (f == 2){
			printf("cgpa greater than or equal to %.2f\n", val);
			for (int i = 0; i < count; i++)
				if (s[i]->cgpa >= val)
					print_query(s[i], f);
		}
		else printf("\ncgpa not evaluated\n");
	}
}

void query_process(char *str, int f){
	char *att, *op, *v;
	int space = 0, count = 0;
	char a[10];
	att = (char*)malloc(sizeof(char) * 10);
	op = (char*)malloc(sizeof(char) * 10);
	v = (char*)malloc(sizeof(char) * 10);
	for (int i = 0; str[i] != '\0'; i++){
		if (str[i] == ' '){
			if (space == 0)
				att[count] = '\0';
			if (space == 1)
				op[count] = '\0';
			if (space == 2)
				v[count] = '\0';
			count = 0;
			space++;
		}
		else{
			if (space == 0){
				att[count] = str[i];
				count++;
			}
			else if (space == 1){
				op[count] = str[i];
				count++;
			}
			else if (space == 2){
				v[count] = str[i];
				count++;
			}
		}
	}
	int valu, val2, point = 0;
	float ans, f1, f2, rem = 1;
	v[count] = '\0';
	count = 0;
	for (int i = 0; v[i] != '\0'; i++){
		if (v[i] == '.'){
			a[count] = '\0';
			valu = convert_char_to_int(a, count);
			count = 0;
			point = 1;
		}
		else{
			a[count] = v[i];
			count++;
		}
	}
	a[count] = '\0';
	if (point == 1){
		val2 = convert_char_to_int(a, count);
		while (count > 0){
			rem = rem * 10;
			count--;
		}
		f1 = val2;
		f1 /= rem;
		f2 = valu;
		ans = f1 + f2;
	}
	else{
		valu = convert_char_to_int(a, count);
		ans = valu;
	}
	if (strcmp(op, "LT") == 0 || strcmp(op, "lt") == 0)
		less_than(att, ans, f);
	if (strcmp(op, "EQ") == 0 || strcmp(op, "eq") == 0)
		equal_to(att, ans, f);
	if (strcmp(op, "GT") == 0 || strcmp(op, "gt") == 0)
		greater_than(att, ans, f);
	if (strcmp(op, "LE") == 0 || strcmp(op, "le") == 0)
		less_than_equal(att, ans, f);
	if (strcmp(op, "GE") == 0 || strcmp(op, "ge") == 0)
		greater_than_equal(att, ans, f);
}

int check_condition(char *s){
	char arr[10];
	int cur = 0;
	int count = 0;
	for (int i = 0; s[i] != '\0'; i++){
		if (s[i] == ' '){
			arr[count] = '\0';
			if (cur == 1){
				if ((strcmp(&arr[0], ">") != 0) || (strcmp(&arr[0], "<") != 0) || (strcmp(&arr[0], "<=") != 0) || (strcmp(&arr[0], ">=") != 0) || (strcmp(&arr[0], "<>") != 0) || (strcmp(&arr[0], "=") == 0))
					return 0;
			}
		}
		else{
			arr[count] = s[i];
			count++;
		}
	}
	return 1;
}

struct item * create(){
	item *temp = (item*)malloc(sizeof(item));
	temp->name = NULL;
	temp->key = NULL;
	temp->next = NULL;
	return temp;
}

int hash_code(char *k, int hashsize){
	int ans = 0;
	for (int i = 0; k[i] != '\0'; i++){
		ans += k[i];
	}
	return ans % hashsize;
}

void insert(item **hashtable, int hashsize, item *t){
	int hashindex = hash_code(t->key, hashsize);
	int c;
	if (hashtable[hashindex] == NULL){
		hashtable[hashindex] = t;
	}
	else{
		item *temp = hashtable[hashindex];
		item *pre = NULL;
		while (temp->next != NULL){
			if (strcmp(temp->key, t->key) == 0){
				system("cls");
				printf("\nduplicate found\n");
				printf("\n1.update\n");
				printf("\n2.drop\n");
				scanf_s("%d", &c);
				if (c == 1){
					t->next = temp->next;
					temp->next = NULL;
					pre->next = t;
					free(temp);
				}
			}
			pre = temp;
			temp = temp->next;
		}
		if (strcmp(temp->key, t->key) == 0){
			system("cls");
			printf("\nduplicate found\n");
			printf("\n1.update\n");
			printf("\n2.drop\n");
			scanf_s("%d", &c);
			if (c == 1){
				if (pre == NULL){
					free(hashtable[hashindex]);
					hashtable[hashindex] = t;
				}
				else{
					t->next = temp->next;
					temp->next = NULL;
					pre->next = t;
					free(temp);
				}
			}
		}
	}

}

void search(item **hashtable, int hashsize, char *k){
	int index = hash_code(k, hashsize);
	item *t = hashtable[index];
	while (t->next != NULL){
		if (strcmp(t->key, k) == 0){
			printf("name found:-%s\n", t->name);
			break;
		}
		t = t->next;
	}
	if (strcmp(t->key, k) == 0)
		printf("name found:-%s\n", t->name);
}

int query_validate(char *str, item **hashtable, int hashsize){
	int count = 0, cur = 0;
	int k, i;
	char *keywords[6] = { { "select" }, { "t1" }, { "from" }, { "t2" }, { "where" }, { "t3" } };
	char arr[20];
	for (int i = 0; str[i] != '\0'; i++){
		if (str[i] == ' '){
			arr[count] = '\0';
			if (keywords[cur] != "t1"&&keywords[cur] != "t2"&&keywords[cur] != "t3"){
				if (strcmp(keywords[cur], &arr[0]) != 0){
					return 0;
				}
			}
			else{
				for (int i = 0; i < 6; i++){
					if (keywords[i] != "t1"&&keywords[i] != "t2"&&keywords[i] != "t3"){
						if (strcmp(&arr[0], keywords[i]) == 0){
							return 0;
						}
					}
				}
				item *t = create();
				t->name = (char *)malloc(sizeof(char)*count);
				for (int j = 0; j <= count; j++)
					t->name[j] = arr[j];
				t->key = (char *)malloc(sizeof(char) * 10);
				for (k = 0; keywords[cur][k] != '\0'; k++)
					t->key[k] = keywords[cur][k];
				t->key[k] = '\0';
				insert(hashtable, hashsize, t);
			}
			cur++;
			count = 0;
		}
		else{
			arr[count] = str[i];
			count++;
		}
	}
	arr[count] = '\0';
	if (keywords[cur] != "t1"&&keywords[cur] != "t2"&&keywords[cur] != "t3"){
		if (strcmp(keywords[cur], &arr[0]) != 0){
			return 0;
		}
	}
	else{
		for (int i = 0; i < 6; i++){
			if (keywords[i] != "t1"&&keywords[i] != "t2"&&keywords[i] != "t3"&&keywords[i] != "t4"){
				if (strcmp(&arr[0], keywords[i]) == 0){
					return 0;
				}
			}
		}
		item *t = create();
		t->name = (char *)malloc(sizeof(char)*count);
		for (int j = 0; j <= count; j++)
			t->name[j] = arr[j];
		t->key = (char *)malloc(sizeof(char) * 10);
		for (i = 0; keywords[cur][i] != '\0'; i++)
			t->key[i] = keywords[cur][i];
		t->key[i] = '\0';
		insert(hashtable, hashsize, t);
	}
	return 1;
}

int check_availability_file(char *str, char **input_strings, int count){
	for (int i = 0; i < count; i++){
		if (strcmp(str, input_strings[i]) == 0)
			return 1;
	}
	return 0;
}

void process_query(item **hashtable, int hashsize, char **input, int flag){
	int index_t1 = hash_code("t1", hashsize);
	int cou = 0, limit = 10;
	int index = 0;
	char **arr = (char**)malloc(sizeof(char*)*limit);
	for (int i = 0; i < limit; i++)
		arr[i] = (char*)malloc(sizeof(char) * 10);
	for (int i = 0; hashtable[index_t1]->name[i] != '\0'; i++){
		if (hashtable[index_t1]->name[i] == ','){
			arr[cou][index] = '\0';
			cou++;
			index = 0;
		}
		else{
			arr[cou][index] = hashtable[index_t1]->name[i];
			index++;
		}
	}
	arr[cou][index] = '\0';
	cou++;
	int index_t3 = hash_code("t3", hashsize);
	char att[10], op[5], num[15];
	int	c = 0;
	for (int i = 0; hashtable[index_t3]->name[i] != '\0'; i++){
		if (hashtable[index_t3]->name[i] == '>' || hashtable[index_t3]->name[i] == '<' || hashtable[index_t3]->name[i] == '!' || hashtable[index_t3]->name[i] == '='){
			att[c] = '\0';
			c = 0;
			op[c] = hashtable[index_t3]->name[i];
			c++;
			if (hashtable[index_t3]->name[i + 1] == '='){
				op[c] = hashtable[index_t3]->name[i + 1];
				c++;
				op[c] = '\0';
				c = 0;
				for (int k = i + 2; hashtable[index_t3]->name[k] != '\0'; i++){
					num[c] = hashtable[index_t3]->name[k];
					c++;
				}
			}
			else {
				op[c] = '\0';
				c = 0;
				for (int k = i + 1; hashtable[index_t3]->name[k] != '\0'; k++){
					num[c] = hashtable[index_t3]->name[k];
					c++;
				}
			}
			num[c] = '\0';
			break;
		}
		else {
			att[c] = hashtable[index_t3]->name[i];
			c++;
		}
	}
	int valu, val2, point = 0;
	float ans, f1, f2, rem = 1;
	int count = 0;
	char a[10];
	for (int i = 0; num[i] != '\0'; i++){
		if (num[i] == '.'){
			a[count] = '\0';
			valu = convert_char_to_int(a, count);
			count = 0;
			point = 1;
		}
		else{
			a[count] = num[i];
			count++;
		}
	}
	a[count] = '\0';
	if (point == 1){
		val2 = convert_char_to_int(a, count);
		while (count > 0){
			rem = rem * 10;
			count--;
		}
		f1 = val2;
		f1 /= rem;
		f2 = valu;
		ans = f1 + f2;
	}
	else{
		valu = convert_char_to_int(a, count);
		ans = valu;
	}
	if (strcmp(op, ">") == 0){
		if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[0]) == 0)
			print_greater_student(arr, cou, att, ans, flag);
		else if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[1]) == 0)
			print_greater_info(arr, cou, att, ans, flag);
		else printf("\nentered file does not exists\n");
	}
	if (strcmp(op, "<") == 0){
		if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[0]) == 0)
			print_lessthan_student(arr, cou, att, ans, flag);
		else if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[1]) == 0)
			print_lessthan_info(arr, cou, att, ans, flag);
		else printf("\nentered file does not exists\n");
	}
	if (strcmp(op, "<=") == 0){
		if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[0]) == 0)
			print_lessthanequal_student(arr, cou, att, ans, flag);
		else if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[1]) == 0)
			print_lessthanequal_info(arr, cou, att, ans, flag);
		else printf("\nentered file does not exists\n");
	}
	if (strcmp(op, ">=") == 0){
		if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[0]) == 0)
			print_greaterthanequal_student(arr, cou, att, ans, flag);
		else if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[1]) == 0)
			print_greaterthanequal_info(arr, cou, att, ans, flag);
		else printf("\nentered file does not exists\n");
	}
	if (strcmp(op, "!=") == 0){
		if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[0]) == 0)
			print_notequal_student(arr, cou, att, ans, flag);
		if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[1]) == 0)
			print_notequal_info(arr, cou, att, ans, flag);
		printf("\nentered file does not exists\n");
	}
	if (strcmp(op, "=") == 0){
		if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[0]) == 0)
			print_equal_student(arr, cou, att, ans, flag);
		else if (strcmp(hashtable[hash_code("t2", hashsize)]->name, input[1]) == 0)
			print_equal_info(arr, cou, att, ans, flag);
		else printf("\nentered file does not exists\n");
	}
}