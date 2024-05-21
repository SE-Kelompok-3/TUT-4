// Hashing and Hash Tables

// Collision Handing
// -> Open Addressing
// -> Close Addressing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
#define LENGTH 100

struct Stuff {
	char name[LENGTH];
	int quantity; 
} *bucket[SIZE];

int count = 0;

struct Stuff* newNode(char name[LENGTH], int quantity){
	struct Stuff* node = (struct Stuff*) malloc(sizeof(struct Stuff));
	
	strcpy(node->name, name);
	node->quantity = quantity;
	
	return node;
};

int hash(char name[LENGTH]){
	int key = 0;
	int len = strlen(name);
	
	for (int i = 0; i < len; i++){
		key += name[i];
	}
	
	return key % SIZE;
}

void insert (char name[LENGTH], int quantity){
	int hashkey = hash(name);
	int pos = hashkey;
	
//	Semua Laci Penuh
	if (count == SIZE){
		printf ("Bucket Overload!");
		return;
	}
	
//	Collision handling
	while (bucket[pos] != NULL){
		pos = (pos + 1) % SIZE;
	}
	
//	Laci kosong
	bucket[pos] = newNode(name, quantity);
	count++;
}

void view (){
	for (int i = 0; i < SIZE; i++){
		if (bucket[i]){
			printf ("%s : %d. Hashkey : %d\n", bucket[i]->name, bucket[i]->quantity, hash(bucket[i]->name));
		}
		else {
			printf ("-\n");
		}
	}
}

void removes (char name[LENGTH]){
	for (int i = 0; i < SIZE; i++){
		if (bucket[i] != NULL){
			if (strcmp(bucket[i]->name, name) == 0){
				free(bucket[i]);
				bucket[i] = NULL;
				return;
			}
		}
	}
}

struct Stuff* search (char name[LENGTH]){
	int hashkey = hash(name);
	int pos = hashkey;
	
	do {
		if (bucket[pos] && strcmp(bucket[pos]->name, name) == 0){
			return bucket[pos];
		}
		
		pos = (pos + 1) % SIZE;
	} while (pos != hashkey);
	
	return NULL;
}

int main (){
	
	insert("biola", 20);
	insert("guitar", 16);
	insert("drum", 13);
	insert("piano", 1);
	
	view();
	
	printf ("================\n");
	removes ("biola");
	
	view();
	
	printf ("================\n");
	if (search ("piano")){
		printf ("Found!\n");
	}
	else {
		printf ("Not Found!\n");
	}
	
	return 0;
}
