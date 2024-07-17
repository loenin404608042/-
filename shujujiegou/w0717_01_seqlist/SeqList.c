#include <stdio.h>
#include <stdlib.h>

//代码：顺序表的实现
//时间：2024-7-17

typedef int E; // E为int别名

//创建顺序表List结构体
struct List{
	E* array; //指针定义array数组
	int capacity;//List的容量
	int size;//元素个数
};

typedef struct List* ArrayList; //将struct List* 换别名为ArrayList

//初始化List结构体
_Bool init_List(ArrayList list) {
	list->array = malloc(sizeof(E) * 10); //手动申请内存空间
	if (list->array == NULL) {
		return 0;
	}
	list->capacity = 10;
	list->size = 0;
	return 1;
}

//插入操作
_Bool insert_List(ArrayList list, E element, int index) {
	//判断index是否合法
	if (index <= 0 || index > list->size + 1) {
		return 0;
	}  
	//扩容
	if (list->size == list->capacity) {
		int newCapacity = list->capacity + (list->capacity >> 1); //>>1 等于 / 2
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
//删除操作
_Bool delete_List(ArrayList list, int index) {
	//判断index是否合法
	if (index <= 0 || index > list->size) {
		return 0;
	}

	for (int i = index; i < list->size; ++i) {
		list->array[i] = list->array[i + 1];
	}
	list->size--;
	return 1;
}

//获取线性表长度
int size_List(ArrayList list) {
	return list->size;
}

//按位置获取元素
E* get_Element(ArrayList list, int index) {
	if (index<1 || index > list->size) {
		return NULL;
	}
	return &list->array[index - 1];
}
 // 查找指定元素的位置
int find_Element(ArrayList list, E element) {
	for (int i = 0; i < list->size; ++i){
		if (element == list->array[i]) {
			return i + 1;
		}
	}
	return -1;
}
//打印调试
void print_List(ArrayList list) {
	for (int i = 0; i < list->size; ++i) {
		printf("%d ", list->array[i]);
	}
}
int main() {
	struct List list; //创建结构体变量
	if (init_List(&list)) {
		//printf("创建成功！\n");
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
		printf("创建失败！");
	}
	return 0;
}