/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 12 bagian 1c:
    Modifikasilah file modul12a.c, modul12b.c, modul12c.c, dan modul12d.c
    supaya dapat juga mengakomodasi pengurutan data menurun (descending).
*/

#include <stdio.h>
#define MAX 100 //ukuran max array

//Mengisi Array Data, Data: Array, Size: Ukuran Array
void IsiData(int data[], int *size){
    printf("Masukan ukuran array (max 100): ");
    scanf("%d", size);
        for(int i = 0;i<*size;i++){
        printf("Masukan data %d : ", i+1);
        scanf("%d", &data[i]); 
    }
}

//Menampilkan data, data: array, size: ukuran array
void TampilkanData(int data[], int size){
    for(int i=0;i<size;i++)
        printf("%d ", data[i]);
    puts("");
}

//Merge sort Asc, arr:Array, Indeks: l=kiri, m=tengah, r=kanan, mode=pengurutan 1.menaik/2.menurun
void Merge(int arr[], int l, int m, int r, int mode){
    int i, j, k; //Indeks: i array kiri, j array kanan, K: variabel key untuk ditukar
    int n1 = m - l + 1; //ukuran array kiri, +1 karna indeks dimulai dari 0
    int n2 = r - m; //ukuran array kanan
    int L[n1], R[n2]; //n1: array kiri, n2:array kanan
    
    //pengisian array kiri
    for(i=0;i<n1;i++)
        L[i] = arr[l+i];
    //pengisian array kanan
    for(j=0;j<n2;j++)
        R[j] = arr[m+1+j]; //+1 karena indeks m ada di array kiri
    //reset i daan j
    i=0; j=0;
    k = l; //inisialisasi key untuk merge sort array utama

    //ASCENDING
    if(mode == 1){
        while(i<n1 && j<n2){
            //core
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
            /*  jika elemen ke-i di array L <= array elemen ke-j di array R,
                masukan elemen i ke array utama indeks ke-k. lalu indeks i di array kiri. 
                -Dan Sebaliknya-
                Tiap sekali pengisian array utama, indeks k di array Utama +1.
            */
        }
    }
    //DESCENDING
    else if (mode==2){
        while(i<n1 && j<n2){
            //core
            if(L[i] >= R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
            /*  jika elemen ke-i di array L >= array elemen ke-j di array R,
                masukan elemen i ke array utama indeks ke-k. lalu indeks i di array kiri. 
                -Dan Sebaliknya-
                Tiap sekali pengisian array utama, indeks k di array Utama +1.
            */
        }
    }

    /*  Setelah itu, ada 3 kondisi dan hanya salah satu yg terjadi.
        1. Array Kiri masih ada sisa
        2. Array Kanan masih ada sisa
        3. Array Kiri dan Kanan Habis
    */

    //Kondisi 1: Array kiri bersisa, masukan semua dalam array utama. Sudah terurut!
    while(i<n1){
        arr[k] = L[i];
        i++;k++;
    }
    //Kondisi 2: Array kanan bersisa, masukan semua dalam array utama. Sudah terurut!
    while(j<n2){
        arr[k] = R[j];
        j++;k++;
    }
}

//Rekursi merge sort, arr:array, Indeks: l=kiri, r=kanan, mode=pengurutan 1.menaik/2.menurun
void MergeSort(int arr[], int l, int r, int mode){
    if(l < r){ //kondisi berhenti jika indeks left > right
        int m = l+(r-l)/2; //mengambil indeks tengah = indeks kiri + setengah jarak dari l ke r
        MergeSort(arr, l, m, mode); //rekursi untuk mergesort bagian kiri sampai tinggal 1 elemen
        MergeSort(arr, m+1, r, mode); //setelah bagian kiri, rekursi mergesort bagian kanan sampai tinggal 1 elemen
        Merge(arr, l, m, r, mode); //2 bagian dari hasil rekursi di atas digabungkan dengan merge
    }
}

int main(){
    system("cls");
    int data[MAX]; //array data
    int size; //ukuran array yg digunakan
    int Pilihan; //mode pengurutan, menaik/menurun
    puts("=== PROGRAM MERGE SORT ===\n");
    IsiData(data, &size);
    puts("\nPilih pengurutan: ");
    puts("1. Menaik (Ascending)");
    puts("2. Menurun (Descending)");
    printf("Pilihan : ");
    scanf("%d", &Pilihan);
    printf("\nData sebelum diurutkan: ");
    TampilkanData(data, size);
    MergeSort(data, 0, size-1, Pilihan); //indeks kiri = 0, kanan = ukuran array -1
    printf("Data setelah diurutkan: ");
    TampilkanData(data, size);
    return 0;
}