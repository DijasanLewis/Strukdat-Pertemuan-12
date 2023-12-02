/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 12 bagian 3:
    Buat program untuk input dan pengurutan data students berisi int nim, char
    nama[50], int nilai dengan struktur array. Pengurutan bisa berdasarkan nim,
    nama, atau nilai terserah pada pilihan pengguna.
*/

#include <stdio.h>
#include <string.h>
#define MAX 100 //ukuran max array

//Deklarasi struktur data mahasiswa
struct Data
{
    int nim;
    char nama[50];
    int nilai;
};


//Mengisi Array Data, Data: Array, Size: Ukuran Array
void IsiData(struct Data data[], int *size){
    printf("Banyak Mahasiswa (max 100): ");
    scanf("%d", size);
    puts("");
        for(int i = 0;i<*size;i++){
            printf("MAHASISWA %d\n", i+1);
            printf("NIM : ");
            scanf("%d", &data[i].nim); 
            printf("NAMA : ");
            scanf(" %[^\n]", &data[i].nama); 
            printf("NILAI : ");
            scanf("%d", &data[i].nilai);
            puts("");
        }
}

//Menampilkan data, data: array, size: ukuran array
void TampilkanData(struct Data data[], int size){
    for(int i=0;i<size;i++){
            printf("MAHASISWA %d\n", i+1);
            printf("NIM  : %d\n", data[i].nim);
            printf("NAMA : %s\n", data[i].nama);
            printf("NILAI : %d\n", data[i].nilai);
            puts("");
        }
    puts("");
}

//Merge sort Asc, arr:Array, Indeks: l=kiri, m=tengah, r=kanan, mode=urutan berdasarkan 1.NIM/2.NAMA/3.NILAI, urutan=1.Menaik/2.Menurun
void Merge(struct Data arr[], int l, int m, int r, int mode, int urutan){
    int i, j, k; //Indeks: i array kiri, j array kanan, K: variabel key untuk ditukar
    int n1 = m - l + 1; //ukuran array kiri, +1 karna indeks dimulai dari 0
    int n2 = r - m; //ukuran array kanan
    struct Data L[n1], R[n2]; //n1: array kiri, n2:array kanan
    
    //pengisian array kiri
    for(i=0;i<n1;i++){
        L[i].nim = arr[l+i].nim;
        L[i].nilai = arr[l+i].nilai;
        strcpy(L[i].nama, arr[l+i].nama);
    }
    //pengisian array kanan
    for(j=0;j<n2;j++){
        R[j].nim = arr[m+1+j].nim; //+1 karena indeks m ada di array kiri
        R[j].nilai = arr[m+1+j].nilai;
        strcpy(R[j].nama, arr[m+1+j].nama);
    }
    //reset i daan j
    i=0; j=0;
    k = l; //inisialisasi key untuk merge sort array utama

    //ASCENDING
    if(urutan == 1){
        //Berdasarkan NIM
        if(mode==1){
            while(i<n1 && j<n2){
                //core
                if(L[i].nim <= R[j].nim){
                    arr[k] = L[i];
                    i++;
                }
                else{
                    arr[k] = R[j];
                    j++;
                }
                k++;
                /*  jika NIM elemen ke-i di array L <= array elemen ke-j di array R,
                    masukan elemen i ke array utama indeks ke-k. lalu indeks i di array kiri. 
                    -Dan Sebaliknya-
                    Tiap sekali pengisian array utama, indeks k di array Utama +1.
                */
            }
        }
        //Berdasarkan NAMA
        else if(mode==2){
            while(i<n1 && j<n2){
                //core
                if(strcasecmp(L[i].nama, R[j].nama)<=0){
                    arr[k] = L[i];
                    i++;
                }
                else{
                    arr[k] = R[j];
                    j++;
                }
                k++;
                /*  jika NAMA elemen ke-i di array L <= array elemen ke-j di array R,
                    masukan elemen i ke array utama indeks ke-k. lalu indeks i di array kiri. 
                    -Dan Sebaliknya-
                    Tiap sekali pengisian array utama, indeks k di array Utama +1.
                */
            }
        }
        //Berdasarkan NILAI
        else if(mode==3){
            while(i<n1 && j<n2){
                //core
                if(L[i].nilai <= R[j].nilai){
                    arr[k] = L[i];
                    i++;
                }
                else{
                    arr[k] = R[j];
                    j++;
                }
                k++;
                /*  jika NILAI elemen ke-i di array L <= array elemen ke-j di array R,
                    masukan elemen i ke array utama indeks ke-k. lalu indeks i di array kiri. 
                    -Dan Sebaliknya-
                    Tiap sekali pengisian array utama, indeks k di array Utama +1.
                */
            }
        }
    }
    //DESCENDING
    else if (urutan==2){
        //Berdasarkan NIM
        if(mode==1){
            while(i<n1 && j<n2){
                //core
                if(L[i].nim >= R[j].nim){
                    arr[k] = L[i];
                    i++;
                }
                else{
                    arr[k] = R[j];
                    j++;
                }
                k++;
                /*  jika NIM elemen ke-i di array L >= array elemen ke-j di array R,
                    masukan elemen i ke array utama indeks ke-k. lalu indeks i di array kiri. 
                    -Dan Sebaliknya-
                    Tiap sekali pengisian array utama, indeks k di array Utama +1.
                */
            }
        }
        //Berdasarkan NAMA
        else if(mode==2){
            while(i<n1 && j<n2){
                //core
                if(strcasecmp(L[i].nama, R[j].nama)>=0){
                    arr[k] = L[i];
                    i++;
                }
                else{
                    arr[k] = R[j];
                    j++;
                }
                k++;
                /*  jika NAMA elemen ke-i di array L >= array elemen ke-j di array R,
                    masukan elemen i ke array utama indeks ke-k. lalu indeks i di array kiri. 
                    -Dan Sebaliknya-
                    Tiap sekali pengisian array utama, indeks k di array Utama +1.
                */
            }
        }
        //Berdasarkan NILAI
        else if(mode==3){
            while(i<n1 && j<n2){
                //core
                if(L[i].nilai >= R[j].nilai){
                    arr[k] = L[i];
                    i++;
                }
                else{
                    arr[k] = R[j];
                    j++;
                }
                k++;
                /*  jika NILAI elemen ke-i di array L <= array elemen ke-j di array R,
                    masukan elemen i ke array utama indeks ke-k. lalu indeks i di array kiri. 
                    -Dan Sebaliknya-
                    Tiap sekali pengisian array utama, indeks k di array Utama +1.
                */
            }
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

//Rekursi merge sort, arr:array, Indeks: l=kiri, r=kanan, mode=urutan berdasarkan 1.NIM/2.NAMA/3.NILAI, urutan=1.Menaik/2.Menurun
void MergeSort(struct Data arr[], int l, int r, int mode, int urutan){
    if(l < r){ //kondisi berhenti jika indeks left > right
        int m = l+(r-l)/2; //mengambil indeks tengah = indeks kiri + setengah jarak dari l ke r
        MergeSort(arr, l, m, mode, urutan); //rekursi untuk mergesort bagian kiri sampai tinggal 1 elemen
        MergeSort(arr, m+1, r, mode, urutan); //setelah bagian kiri, rekursi mergesort bagian kanan sampai tinggal 1 elemen
        Merge(arr, l, m, r, mode, urutan); //2 bagian dari hasil rekursi di atas digabungkan dengan merge
    }
}

//Menu Pilihan Pengurutan, mode=urutan berdasarkan 1.NIM/2.NAMA/3.NILAI, urutan=1.Menaik/2.Menurun
void Pilihan(int *mode, int *urutan){
    //Mode pengurutan
    puts("Urutkan Berdasarkan: ");
    puts("1. NIM");
    puts("2. NAMA");
    puts("3. NILAI");
    printf("Pilihan : ");
    scanf("%d", mode);

    //Urutan menaik/menurun
    puts("\nPengurutan: ");
    puts("1. Menaik (Ascending)");
    puts("2. Menurun (Descending)");
    printf("Pilihan : ");
    scanf("%d", urutan);
}

//Menghapus semua data dalam array
void ResetArray(struct Data data[], int size){
    for(int i=0;i<size;i++){
        data[i].nim = NULL;
        data[i].nilai = NULL;
        strcpy(data[i].nama, "");
    }
}

int main(){
    int run = 1; //digunakan untuk pengulangan menu
    struct Data data[MAX]; //array data mahasiswa
    int size; //ukuran array yg digunakan
    int mode, urutan, pilihan; //mode pengurutan, berdasarkan NIM/NAMA/NILAI, menaik/menurun, pilihan=untuk melanjutkan program
    while(run>0){
        system("cls");
        puts("=== PROGRAM DATA MAHASISWA ===\n");
        IsiData(data, &size);
        run = 2;
        while(run==2){
            Pilihan(&mode, &urutan);
            puts("\nData sebelum diurutkan: ");
            TampilkanData(data, size);
            MergeSort(data, 0, size-1, mode, urutan); //indeks kiri = 0, kanan = ukuran array -1
            puts("Data setelah diurutkan: ");
            TampilkanData(data, size);

            //Pilihan lanjut menggunakan program atau keluar
            puts("Selanjutnya apa yang ingin Anda lakukan?");
            puts("1. Mengurutkan dengan urutan lain");
            puts("2. Mereset Array Mahasiswa");
            puts("3. Keluar");
            pilihan = 0;
            while(pilihan<1 || pilihan>3){
                printf("Pilihan Anda: ");
                scanf(" %d", &pilihan);
                if (pilihan == 1){
                    break;
                }
                else if(pilihan == 2){
                    run = 1;
                    break;
                }
                else if(pilihan == 3){
                    system("cls");
                    puts("Terima Kasih Telah Menggunakan Program Ini! (^_^)");
                    run = 0;
                    return;
                }
                else{
                    puts("ERROR! Pilihan tidak valid!\n");
                }
            }
            system("cls");
        }
        ResetArray(data, size);
    }
    return 0;
}