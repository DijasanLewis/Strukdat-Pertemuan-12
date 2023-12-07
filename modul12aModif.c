/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 12 bagian 1a:
    Modifikasilah file modul12a.c, modul12b.c, modul12c.c, dan modul12d.c
    supaya dapat juga mengakomodasi pengurutan data menurun (descending).
*/

#include <stdio.h>
#define MAX 100 //ukuran max array

//mengisi data, data = array data, size = ukuran array
void IsiData(int data[], int *size){
    printf("Masukan ukuran array (max 100): ");
    scanf("%d", size);
    for(int i = 0; i<*size;i++){
        printf("Masukan data ke-%d : ", i+1); //i+1 karena indeks dimulai dari 0
        scanf("%d", &data[i]);
    }
}

//Tampilkan data, data = array data, size = ukuran array
void TampilData(int data[], int size){
    for (int i=0;i<size;i++)
        printf("%d ", data[i]);
    puts("");
}

//Insertion Sort Asc, arr = array, n = ukuran array , mode=pengurutan 1.menaik/2.menurun
void InsertionSort(int arr[], int n, int mode){
    int i, key, j; //i dan j untuk iterasi, key untuk variabel penyimpanan sementara
    //Ascending
    if (mode==1){
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
    //DESCENDING
    else if (mode==2){
        for(i=1; i<n; i++){
            key = arr[i]; //key dimulai dari indeks 1
            j = i-1; //yg mau dibandingkan dimulai dari angka sebelum key
            while (j>=0 && arr[j]<key){
                arr[j+1]=arr[j]; //data dimajukan ke depan
                j=j-1; //indeksnya mundur
            }
            arr[j+1] = key; //nilai yg ditukar adalah j+1!
        }
    }

}

void main(){
    system("cls");
    int data[MAX]; //inisialisasi array data
    int size; //ukuran array yg dipakai
    int Pilihan; //mode pengurutan, menaik/menurun
    puts("=== PROGRAM INSERTION SORT ===\n");
    IsiData(data, &size);
    puts("\nPilih pengurutan: ");
    puts("1. Menaik (Ascending)");
    puts("2. Menurun (Descending)");
    printf("Pilihan : ");
    scanf("%d", &Pilihan);
    printf("\nData sebelum diurutkan: ");
    TampilData(data, size);
    InsertionSort(data, size, Pilihan);
    printf("Data setelah diurutkan: ");
    TampilData(data, size);
}