#include <stdio.h>
#include <stdlib.h>

//���룺˳����ʵ��
//ʱ�䣺2024-7-17

typedef int E; // EΪint����

//����˳���List�ṹ��
struct List{
	E* array; //ָ�붨��array����
	int capacity;//List������
	int size;//Ԫ�ظ���
};

typedef struct List* ArrayList; //��struct List* ������ΪArrayList

//��ʼ��List�ṹ��
_Bool init_List(ArrayList list) {
	list->array = malloc(sizeof(E) * 10); //�ֶ������ڴ�ռ�
	if (list->array == NULL) {
		return 0;
	}
	list->capacity = 10;
	list->size = 0;
	return 1;
}

//�������
_Bool insert_List(ArrayList list, E element, int index) {
	//�ж�index�Ƿ�Ϸ�
	if (index <= 0 || index > list->size + 1) {
		return 0;
	}  
	//����
	if (list->size == list->capacity) {
		int newCapacity = list->capacity + (list->capacity >> 1); //>>1 ���� / 2
		E* newArray = realloc(list->array, newCapacity * sizeof(E));	
		if (newArray == NULL) {
			return 0;
		}
	    list->array = newArray;
		list->capacity = newCapacity;
		printf("newCapacity:%d\n", newCapacity);
	}

	for (int i = list->size; i > index - 1; --i) {
		list->array[i] = list->array[i - 1];
	}
	list->array[index - 1] = element;
	list->size++;
	return 1;
}
//ɾ������
_Bool delete_List(ArrayList list, int index) {
	//�ж�index�Ƿ�Ϸ�
	if (index <= 0 || index > list->size) {
		return 0;
	}

	for (int i = index; i < list->size; ++i) {
		list->array[i] = list->array[i + 1];
	}
	list->size--;
	return 1;
}

//��ȡ���Ա���
int size_List(ArrayList list) {
	return list->size;
}

//��λ�û�ȡԪ��
E* get_Element(ArrayList list, int index) {
	if (index<1 || index > list->size) {
		return NULL;
	}
	return &list->array[index - 1];
}
 // ����ָ��Ԫ�ص�λ��
int find_Element(ArrayList list, E element) {
	for (int i = 0; i < list->size; ++i){
		if (element == list->array[i]) {
			return i + 1;
		}
	}
	return -1;
}
//��ӡ����
void print_List(ArrayList list) {
	for (int i = 0; i < list->size; ++i) {
		printf("%d ", list->array[i]);
	}
}
int main() {
	struct List list; //�����ṹ�����
	if (init_List(&list)) {
		//printf("�����ɹ���\n");
		for (int i = 0; i < 10; ++i) {
			insert_List(&list, i, i+1);
			print_List(&list);
			printf("\n");
		}
		//delete_List(&list, 10);
		//print_List(&list);
		printf("size:%d\n", size_List(&list));
		printf("get_Element:%d\n", *get_Element(&list,2));
		printf("find_Element:%d\n", find_Element(&list,5));
	}
	else {
		printf("����ʧ�ܣ�");
	}
	return 0;
}