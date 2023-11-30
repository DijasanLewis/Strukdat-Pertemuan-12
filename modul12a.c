#include <stdio.h>
#define MAX 100 //ukuran max array

//mengisi data, data = array data, size = ukuran array
void IsiData(int data[], int *size){
    printf("Masukan ukuran array (max 100): ");
    scanf("%d", size);
    for(int i = 0; i<*size;i++){
        printf("Masukan data ke-%d :", i+1); //i+1 karena indeks dimulai dari 0
        scanf("%d", &data[i]);
    }
}

//Tampilkan data, data = array data, size = ukuran array
void TampilData(int data[], int size){
    for (int i=0;i<size;i++)
        printf("%d\n");
}

//Insertion Sort, arr = array, n = ukuran array 
void InsertionSort(int arr[], int n){
    int i, key, j; //i dan j untuk iterasi, key untuk variabel penyimpanan sementara
    for(i=1; i<n; i++){
        key = arr[i]; //key dimulai dari indeks 1
        j = i-1; //yg mau dibandingkan dimulai dari angka sebelum key
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j]; //data dimajukan ke depan
            j=j-1; //indeksnya mundur
        }
        arr[j+1] = key; //nilai yg ditukar adalah j+1!
    }
}

void main(){
    int data[MAX]; //inisialisasi array data
    int size; //ukuran array yg dipakai
    IsiData(data, &size);
    InsertionSort(data, size);
    puts("Data setelah diurutkan:");
    TampilData(data, size);
}