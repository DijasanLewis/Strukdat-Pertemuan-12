/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 12 bagian 1d:
    Modifikasilah file modul12a.c, modul12b.c, modul12c.c, dan modul12d.c
    supaya dapat juga mengakomodasi pengurutan data menurun (descending).
*/

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
        printf("%d ", data[i]);
    puts("");
}

//Menukar data, a=data 1, b=data 2
void swap(int *a, int *b){
    int temp = *a; //memasukan a dalam variabel sementara
    *a = *b;
    *b = temp;
}

//Bubble sort Asc Optimal, arr=array, n=ukuran array, mode= 1.menaik/2.menurun
void BubbleSort(int arr[], int n, int mode){
    //ASCENDING
    if(mode==1){
    for(int i=0; i<n-1;i++) //iterasi pengecekan/langkah sebanyak (banyak data -1)
        for(int j=0;j<n-i-1;j++) //iterasi penukaran akan berkurang seiring i/langkah bertambah (optimal, karena data yg terbesar sudah terurut di array belakang)
            //core
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
    //DESCENDING
    else if(mode==2){
    for(int i=0; i<n-1;i++) //iterasi pengecekan/langkah sebanyak (banyak data -1)
        for(int j=0;j<n-i-1;j++) //iterasi penukaran akan berkurang seiring i/langkah bertambah (optimal, karena data yg terkecil sudah terurut di array belakang)
            //core
            if(arr[j]<arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
}

void main(){
    system("cls");
    int data[MAX]; //array data
    int size; //ukuran array yg digunakan
    int Pilihan; //mode pengurutan, menaik/menurun
    puts("=== PROGRAM BUBBLE SORT ===\n");
    IsiData(data, &size);
    puts("\nPilih pengurutan: ");
    puts("1. Menaik (Ascending)");
    puts("2. Menurun (Descending)");
    printf("Pilihan : ");
    scanf("%d", &Pilihan);
    printf("\nData sebelum diurutkan: ");
    TampilkanData(data, size);
    BubbleSort(data, size, Pilihan);
    printf("Data setelah diurutkan: ");
    TampilkanData(data, size);
}