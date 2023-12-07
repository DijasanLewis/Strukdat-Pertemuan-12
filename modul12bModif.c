/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 12 bagian 1b:
    Modifikasilah file modul12a.c, modul12b.c, modul12c.c, dan modul12d.c
    supaya dapat juga mengakomodasi pengurutan data menurun (descending).
*/

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
        printf("%d ", data[i]);
    puts("");
}

//Menukar data a dan b, a: data 1, b: data 2
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Selection Sort Ascending, data: array data, size: ukuran array, mode: pengurutan 1.menaik/2. menurun
void SelectionSort(int data[], int size, int mode){
    //Ascending
    if(mode==1){
        for(int step = 0; step<size-1; step++){
            int min_idx = step; //min_idx menyimpan indeks data yg minimum
            for(int i = step+1; i<size; i++){
                if(data[i]<data[min_idx])
                    min_idx = i; //tukar min_idx jika data ke i lebih kecil
            }
            swap(&data[min_idx], &data[step]); //tukar data ke-step dgn data terkecil yg ditemukan
        }
    }
    //Descending
    else if(mode==2){
        for(int step = 0; step<size-1; step++){
            int max_idx = step; //max_idx menyimpan indeks data yg maksimum
            for(int i = step+1; i<size; i++){
                if(data[i]>data[max_idx])
                    max_idx = i; //tukar max_idx jika data ke i lebih besar
            }
            swap(&data[max_idx], &data[step]); //tukar data ke-step dgn data terbesar yg ditemukan
        }
    }
}

void main(){
    system("cls");
    int data[MAX]; //array data
    int size; //ukuran array yg digunakan
    int Pilihan; //mode pengurutan, menaik/menurun
    puts("=== PROGRAM SELECTION SORT ===\n");
    IsiData(data, &size);
    puts("\nPilih pengurutan: ");
    puts("1. Menaik (Ascending)");
    puts("2. Menurun (Descending)");
    printf("Pilihan : ");
    scanf("%d", &Pilihan);
    printf("\nData sebelum diurutkan: ");
    TampilkanData(data, size);
    SelectionSort(data, size, Pilihan);
    printf("Data setelah diurutkan: ");
    TampilkanData(data, size);
}