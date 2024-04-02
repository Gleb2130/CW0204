#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int* arr;
	size_t size;
	size_t cop;
}Vec;

void constructor(Vec* obj,const size_t size) {
	obj->size = size;
	obj->cop = size + 1;
	obj->arr = (int*)malloc(obj->cop * sizeof(int));
}

void destructor(Vec* obj) {
	free(obj->arr);
}

void push_back(Vec* obj, int number) {
	if (obj->cop > obj->size) {
		obj->arr[obj->size] = number;
	}
	else {
		obj->cop += 2;
		int* temp = (int*)malloc(obj->cop * sizeof(int));
		for (size_t i = 0; i < obj->size; i++)
		{
			temp[i] = obj->arr[i];
		}
		free(obj->arr);
		obj->arr = temp;
		obj->arr[obj->size] = number;
	}
	obj->size++;
}

void print(Vec obj) {
	for (size_t i = 0; i < obj.size; i++)
	{
		printf("%d ", obj.arr[i]);
	}
	printf("\n");;
}

Vec intersection(Vec obj1, Vec obj2) {
	Vec result;
	constructor(&result, 0);

	for (size_t obj1_index = 0; obj1_index < obj1.size; obj1_index++)
	{
		for (size_t obj2_index = 0; obj2_index < obj2.size; obj2_index++)
		{
			if (obj1.arr[obj1_index] == obj2.arr[obj2_index]) {
				short flag = 1;
				for (size_t res_index = 0; res_index < result.size; res_index++)
				{
					if (obj1.arr[obj1_index] == result.arr[res_index]) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					push_back(&result, obj1.arr[obj1_index]);
					break;
				}
			}
		}
	}
	return result;
}

Vec association(Vec obj1, Vec obj2) {
	Vec result;
	constructor(&result, 0);

	for (size_t obj1_index = 0; obj1_index < obj1.size; obj1_index++)
	{
		short flag = 1;
		for (size_t res_index = 0; res_index < result.size; res_index++)
		{
			if (obj1.arr[obj1_index] == result.arr[res_index]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			push_back(&result, obj1.arr[obj1_index]);
		}
	}

	for (size_t obj2_index = 0; obj2_index < obj2.size; obj2_index++)
	{
		short flag = 1;
		for (size_t res_index = 0; res_index < result.size; res_index++)
		{
			if (obj2.arr[obj2_index] == result.arr[res_index]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			push_back(&result, obj2.arr[obj2_index]);
		}
	}
	return result;
}

int main() {
	srand(time(NULL));

	Vec mnoz1 = { NULL},  mnoz2 = { NULL};

	constructor(&mnoz1, 0);
	constructor(&mnoz2,0);

	push_back(&mnoz1, rand()%10);
	push_back(&mnoz1, rand()%10);
	push_back(&mnoz1, rand()%10);

	push_back(&mnoz2, rand()%10);
	push_back(&mnoz2, rand()%10);
	push_back(&mnoz2, rand()%10);

	print(mnoz1);
	print(mnoz2);

	Vec intersection_res = intersection(mnoz1, mnoz2);
	Vec association_res = association(mnoz1, mnoz2);
	print(intersection_res);
	print(association_res);
	destructor(&mnoz1);
	destructor(&mnoz2);
}