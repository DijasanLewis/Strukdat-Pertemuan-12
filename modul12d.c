#include <stdio.h>
#define MAX 100 //ukuran maks array

//Mengisi Array, data=array, size=ukuran array (reference)
void IsiData(int data[], int *size){
    //Input Ukuran Array
    printf("Masukan ukuran array (max 100): ");
    scanf("%d", size);
    //Input data dalam array
    for(int i=0; i<*size; i++){
        printf("Masukan data %d : ", i+1);
        scanf("%d", &data[i]); //ingat, variabel input (bahkan elemen array) harus diberi tanda &
    }
}

//Menampilkan array, data=array, size=ukuran array
void TampilkanData(int data[], int size){
    for(int i=0;i<size;i++)
        printf("%d\n", data[i]);
}

//Menukar data, a=data 1, b=data 2
void swap(int *a, int *b){
    int temp = *a; //memasukan a dalam variabel sementara
    *a = *b;
    *b = temp;
}

//Bubble sort Asc Optimal, arr=array, n=ukuran array
void BubbleSort(int arr[], int n){
    for(int i=0; i<n-1;i++) //iterasi pengecekan/langkah sebanyak (banyak data -1)
        for(int j=0;j<n-i-1;j++) //iterasi penukaran akan berkurang seiring i/langkah bertambah (optimal, karena data yg terbesar sudah terurut di array belakang)
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void main(){
    system("cls");
    int data[MAX]; //array data
    int size; //ukuran array yg dipakai
    IsiData(data, &size);
    BubbleSort(data, size);
    puts("\nData setelah diurutkan: ");
    TampilkanData(data, size);
}