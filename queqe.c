#include<stdio.h>
#define max 2

int arr[max];

int first=0,last=0;

int isFull(){
    if(last == max){
        return 1;
    }else{
        return 0;
    } 

}
int isEmpty(){
    if(first == last){
        first =0;
        last = 0;
        return 1;
    }else{
        return 0;
    }
}
int enqueqe(int x){
    if(!isFull()){
        arr[last++] = x;
    }else{
        printf("Queue Full\n");
    }
}
int dqueqe(){
    if(!isEmpty()){
        return arr[first++];
    }else{
        printf("Queue Empty\n");
    }
}

void printqueue(){
    for(int i = first;i<last;i++){
        printf("%d\n",arr[i]);
    }
}

int main(){
dqueqe();
printf("%d %d\n",first,last);
enqueqe(10);
enqueqe(12);
printf("%d %d\n",first,last);
enqueqe(20);
printf("%d %d\n",first,last);
printf("%d \n",dqueqe());
printf("%d %d\n",first,last);
printf("%d \n",dqueqe());
printf("%d %d\n",first,last);
dqueqe();
printf("%d %d\n",first,last);
}