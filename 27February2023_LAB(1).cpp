//Double Linked List & Queue

//1. Push Head, Mid, and Tail
//2. Pop Head, Mid, and Tail
//3. Search
//4. Queue & Priority Queue

//Keuntungan dari si Double Linked List
//1. Akses data yang kita simpan lebih cepat
//2. Lebih mudah hapus nodenya

//Kelemahan:
//1. Lebih ribet / kompleks
//2. Lebih banyak makan memori

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
	char NIM[15];
	char nama[25];
	int umur;
	
	struct Mahasiswa *next, *prev;
} *head = NULL, *tail = NULL, *curr = NULL;

// Push Head
void push_head (char NIM[], char nama[], int umur){
	curr = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
	strcpy(curr->NIM, NIM);
	strcpy(curr->nama, nama);
	curr->umur = umur;
	
	curr->next = NULL;
	curr->prev = NULL;
	
//	Head
	if (head == NULL){
		head = tail = curr;
	}
	else {
		curr->next = head;
		head->prev = curr;
		head = curr;
	}
	
	head->prev = NULL;
}

// Push Tail
void push_tail (char NIM[], char nama[], int umur){
	curr = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
	strcpy(curr->NIM, NIM);
	strcpy(curr->nama, nama);
	curr->umur = umur;
	
	curr->next = NULL;
	curr->prev = NULL;
	
//	Tail
	if (head == NULL){
		head = tail = curr;
	}
	else {
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
	
	tail->next = NULL;
}

// Push Mid
void push_mid (char NIM[], char nama[], int umur){
	curr = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
	strcpy(curr->NIM, NIM);
	strcpy(curr->nama, nama);
	curr->umur = umur;
	
	curr->next = NULL;
	curr->prev = NULL;
	
//	Mid
//	strcmp bakal return > 0 kalau str yang pertama valuenya lebih besar
//	strcmp bakal return < 0 kalau str yang pertama valuenya lebih kecil

	if (head == NULL){
		head = tail = curr;
	}
	else if (strcmp (head->NIM, curr->NIM) < 0){
		push_head(NIM, nama, umur);
	}
	else if (strcmp (tail->NIM, curr->NIM) > 0){
		push_tail(NIM, nama, umur);
	}
	else {
		struct Mahasiswa *pos = head;
		
		while (strcmp(pos->next->NIM, curr->NIM) > 0){
			pos = pos->next;
		}
		
		curr->next = pos->next;
		pos->next->prev = curr;
		pos->next = curr;
		curr->prev = pos;
	}
	
}

//Pop Head
void pop_head(){
	if (head == NULL){
		return;
	}
	if (head == tail){
		free(head);
		head = tail = NULL;
	}
	else {
		curr = head;
		head = head->next;
		free(curr);
		head->prev = NULL;
	}
}



//Pop Tail
void pop_tail(){
	if (head == NULL){
		return;
	}
	if (head == tail){
		free(head);
		head = tail = NULL;
	}
	else {
		curr = tail;
		tail = tail->prev;
		free(curr);
		tail->next = NULL;
	}
}

//Pop Mid
void pop_mid(char NIM[]){
	if (head == NULL){
		return;
	}
	else if (strcmp(head->NIM, NIM) == 0){
		pop_head();
	}
	else if (strcmp(tail->NIM, NIM) == 0){
		pop_tail();
	}
	else {
		curr = head;
		while (curr->next != NULL && strcmp(curr->next->NIM, NIM) != 0){
			curr = curr->next;
		}
		
		if (curr->next == NULL){
			return;
		}
		
		struct Mahasiswa *del = curr->next;
		curr->next = del->next;
		del->next->prev = curr;
		free(del);
	}
}

void search(char NIM[]){
	curr = head;
	while (curr->next != NULL && strcmp(curr->next->NIM, NIM) != 0){
		curr = curr->next;
	}
	
	if (curr->next = NULL){
		printf ("Data Not Found!\n");
	}
	else {
		printf ("\n Data Found! [%s] \n", curr->NIM);
		printf ("Nama: %s\n", curr->nama);
		printf ("Umur: %d\n", curr->umur);
	}
}

void view(){
	curr = head;
	if (curr == NULL)	{
		return;
	}
	while (curr != NULL){
		printf ("%s - %s - %d \n", curr->NIM, curr->nama, curr->umur);
		curr = curr->next;
	}
}

int main (){
	
//	push_head("2602072533", "Grace", 18);
//	push_head("2602097675", "Viola", 17);
//	push_head("2602115690", "Tania", 19);
//	push_head("2602086495", "Sherly", 18);

	push_mid("2602072533", "Grace", 18);
	push_mid("2602097675", "Viola", 17);
	push_mid("2602115690", "Tania", 19);
	push_mid("2602086495", "Sherly", 18);

//	push_tail("2602072533", "Grace", 18);
//	push_tail("2602097675", "Viola", 17);
//	push_tail("2602115690", "Tania", 19);
//	push_tail("2602086495", "Sherly", 18);

//	view();
//	pop_head();
//	pop_tail();
//	pop_mid("2602097675");
	view();

	search("2602097675");
	
	return 0;
}
