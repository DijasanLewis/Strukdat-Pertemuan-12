#include <stdio.h>
#define MAX 100 //ukuran max array

//mengisi data, data = array data, size = ukuran array
void IsiData(int data[], int *size){
    printf("Input Jumlah Data =  ");
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
    int data[MAX]; //inisialisasi array data
    int size; //ukuran array yg dipakai
    int metode; //Metode Sorting
    int Pilihan; //mode pengurutan, menaik/menurun
    puts("=== PROGRAM SORTING SORT ===\n");
    IsiData(data, &size);
    //Menu Sorting
    puts("\nMetode Sorting yanag Tersedia:");
    puts("1. Insertion Sort");
    puts("2. Selection Sort");
    puts("3. Merge Sort");
    puts("4. Bubble Sort");
    printf("Pilih Metode Sorting: ");
    scanf("%d", &metode);
    //Memilih mode urutan
    puts("\nPilih pengurutan: ");
    puts("1. Menaik (Ascending)");
    puts("2. Menurun (Descending)");
    printf("Pilih Pengurutan: ");
    scanf("%d", &Pilihan);

    printf("\nData sebelum diurutkan: ");
    TampilData(data, size);
    printf("Menjalankan sorting dengan metode");
    //Pengurutan data
    switch (metode)
    {
    case 1:
        InsertionSort(data, size, Pilihan);
        break;
    case 2:
        SelectionSort(data, size, Pilihan);
        break;
    case 3:
        MergeSort(data, 0, size-1, Pilihan); //indeks kiri = 0, kanan = ukuran array -1
        break;
    case 4:
        BubbleSort(data, size, Pilihan);
        break;
    default:
        puts("ERROR! Pilihan tidak valid!");
        return;
    }
    printf("Data setelah diurutkan: ");
    TampilData(data, size);
}