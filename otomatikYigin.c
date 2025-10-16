#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// otomatik yigin

 struct Node{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *top = NULL; // yiginin en ustu top

void yazdir();
void push(int veri);
void pop();


int main()
{
   srand(time(NULL));
   printf("\n------ Otomatik Stack islemleri -----\n");

   for(int i=1;i<=15;i++){
     int islem = rand() %2;
     int veri = rand() %100;

     printf("\n%d. Adim ",i);
     if(islem == 0){
        printf("islem: Push -> ");
        push(veri);
     }else{
       printf("islem: Pop -> ");
       pop();
     }
       yazdir();
   }
    printf("islemler tamamlandi!\n");
    yazdir();

    return 0;
}
void yazdir(){
  Node *temp = top; //
  printf("Yigin ustten alta: ");

  while(temp != NULL){
    printf("%d->",temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
  }
void push(int veri){
   Node *yeni = (Node*)malloc(sizeof(Node));
   yeni->data = veri;
   yeni->next = top;
   top = yeni;
   printf("Eklendi:%d\n",veri);

}
void pop(){
  if(top == NULL){
     printf("Yigin bos cikarilacak eleman yok.\n");
     return;
  }
   Node *temp = top;
   printf("Cikarildi: %d\n",temp->data);
   top = top->next;
   free(temp);
}


