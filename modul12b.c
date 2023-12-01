#include <stdio.h>
#define MAX 100 //ukuran maks array

//Isi Data, data: array data, size: ukuran array, by reference
void IsiData(int data[], int *size){
    printf("Masukan ukuran array (max 100): ");
    scanf("%d", size); //gk pakai & karena by reference
    for(int i=0; i<*size; i++){ //gunakan *size untuk mengakses nilai size
        printf("Masukan data %d : ", i+1); //i+1 karena indeks mulai dari 0
        scanf("%d", &data[i]);
    }
}

//Menampilkan data, data: array data, size: ukuran array
void TampilkanData(int data[], int size){
    for(int i=0; i<size; i++)
        printf("%d\n", data[i]);
}

//Menukar data a dan b, a: data 1, b: data 2
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Selection Sort Ascending, data: array data, size: ukuran array
void SelectionSort(int data[], int size){
    for(int step = 0; step<size-1; step++){
        int min_idx = step; //min_idx menyimpan indeks data yg minimum
        for(int i = step+1; i<size; i++){
            if(data[i]<data[min_idx])
                min_idx = i; //tukar min_idx jika data ke i lebih kecil
        }
        swap(&data[min_idx], &data[step]); //tukar data ke-step dgn data terkecil yg ditemukan
    }
}

void main(){
    int data[MAX]; //array data
    int size; //ukuran array yg digunakan
    IsiData(data, &size);
    SelectionSort(data, size);
    puts("\nData setelah diurutkan:");
    TampilkanData(data, size);
}