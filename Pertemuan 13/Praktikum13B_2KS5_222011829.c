#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100

struct mhsw {
    int nim;
    char nama[50];
    int nilai;
};

typedef struct mhsw data;

void input_data(data mahasiswa[], int *size) {
    int n;
    printf("Jumlah mahasiswa: ");
    scanf("%d", &n);
    printf("Input data: \n");
    for (int i = *size; i < *size + n; i++) {
        printf("Mahasiswa[%d]\n", i);
        printf("    NIM  : ");
        scanf("%d", &mahasiswa[i].nim);
        getchar();
        printf("    Nama : ");
        scanf("%[^\n]", &mahasiswa[i].nama);
        printf("    Nilai: ");
        scanf("%d", &mahasiswa[i].nilai);
    }
    *size += n;
}

void tampil_data(data mahasiswa[], int size) {
    if (size == 0) {
        printf("Tidak ada data untuk ditampilkan\n");
        return;
    }
    printf("%40s\n", "Data Mahasiswa");
    printf("=====================================================================\n");
    printf("%-10s| %-49s| Nilai\n", "NIM", "Nama");
    printf("=====================================================================\n");
    for (int i = 0; i < size; i++) {
        printf("%-10d| %-49s| %d\n", mahasiswa[i].nim, mahasiswa[i].nama, mahasiswa[i].nilai);
    }
}

void tampil_data_search(data mahasiswa[], int size, int M) {
    printf("Data Mahasiswa yang Dicari: \n");
    printf("=====================================================================\n");
    printf("%-10s| %-49s| Nilai\n", "NIM", "Nama");
    printf("=====================================================================\n");
    printf("%-10d| %-49s| %d\n", mahasiswa[M].nim, mahasiswa[M].nama, mahasiswa[M].nilai);
}

void swap(data *mahasiswa1, data *mahasiswa2) {
    data temp;
    temp.nim = (*mahasiswa1).nim;
    temp.nilai = (*mahasiswa1).nilai;
    strcpy(temp.nama, (*mahasiswa1).nama);
    (*mahasiswa1).nim = (*mahasiswa2).nim;
    (*mahasiswa1).nilai = (*mahasiswa2).nilai;
    strcpy((*mahasiswa1).nama, (*mahasiswa2).nama);
    (*mahasiswa2).nim = temp.nim;
    (*mahasiswa2).nilai = temp.nilai;
    strcpy((*mahasiswa2).nama, temp.nama);
}

void pengurutan(char urut) {
    printf("Pilihan pengurutan ");
    switch (urut)
    {
    case 'N':
        printf("Naik\n");
        break;
    case 'T':
        printf("Turun\n");
        break;
    default:
        printf("Salah\n");
        return;
        break;
    }
}

void selection_sort(data mahasiswa[], int size, char urut, int dasar){
    for(int step = 0; step < size - 1; step++){
        int min_max_idx = step;
        for(int i = step +1;i<size;i++) {
            switch (urut)
            {
            case 'N':
                if (dasar == 1) { //berdasarkan nim
                    if(mahasiswa[i].nim<mahasiswa[min_max_idx].nim)
                        min_max_idx = i;
                } else if (dasar == 2) { //berdasarkan nama
                    if(strcmp(mahasiswa[i].nama, mahasiswa[min_max_idx].nama) < 0)
                        min_max_idx = i;
                } else if (dasar == 3) { //berdasarkan nilai
                    if(mahasiswa[i].nilai<mahasiswa[min_max_idx].nilai)
                        min_max_idx = i;
                } else {
                    printf("Salah input pilihan\n");
                }
                break;
            case 'T':
                if (dasar == 1) { //berdasarkan nim
                    if(mahasiswa[i].nim>mahasiswa[min_max_idx].nim)
                        min_max_idx = i;
                } else if (dasar == 2) { //berdasarkan nama
                    if(strcmp(mahasiswa[i].nama, mahasiswa[min_max_idx].nama) > 0)
                        min_max_idx = i;
                } else if (dasar == 3) { //berdasarkan nilai
                    if(mahasiswa[i].nilai>mahasiswa[min_max_idx].nilai)
                        min_max_idx = i;
                }
                break;
            default:
                break;
            } 
        }
        swap(&mahasiswa[min_max_idx],&mahasiswa[step]);
    }
}

int binary_search(data mahasiswa[], int size, int dasar){
    int L = 0;
    int H = size-1;
    int M = -1;
    int index = -1;
    int nim, nilai;
    char nama[50];
    switch (dasar) 
    {
        case 1: //cari nim
            printf("NIM yang ingin dicari: ");
            scanf("%d", &nim);
            getchar();
            selection_sort(mahasiswa, size, 'N', 1);
            break;
        case 2: //cari nama
            printf("Nama yang ingin dicari: ");
            scanf("%[^\n]", &nama);
            getchar();
            selection_sort(mahasiswa, size, 'N', 2);
            break;
        case 3: //cari nilai
            printf("Nilai yang ingin dicari: ");
            scanf("%d", &nilai);
            getchar();
            selection_sort(mahasiswa, size, 'N', 3);
            break;
        default:
            break;
    }
    while(L<=H){
        M = (L+H)/2;
        switch (dasar)
        {
        case 1: //cari nim
            if(mahasiswa[M].nim == nim)
                return M;
            else{
                if(mahasiswa[M].nim < nim) L = M + 1;
                else H = M - 1;
            }
            break;
        case 2: //cari nama
            if(strcmp(mahasiswa[M].nama, nama) == 0)
                return M;
            else{
                if(strcmp(mahasiswa[M].nama, nama) < 0) L = M + 1;
                else H = M - 1;
            }
            break;
        case 3: //cari nilai
            if(mahasiswa[M].nilai == nilai)
                return M;
            else{
                if(mahasiswa[M].nilai < nilai) L = M + 1;
                else H = M - 1;
            }
            break;
        default:
            break;
        }
    }
    return -1;
}

void main() {
    int size = 0;
    data mahasiswa[MAX];
    int pilih2 = 0;
    int pilih3 = 0;
    int M;
    char urut;
    printf("[]================================[]\n");
    printf("||  Program Input Data Mahasiswa  ||\n");
    printf("[]================================[]\n");
    int pilih = 0;
    do {
        printf("\nMenu: \n"
        "   1. Input data mahasiswa\n"
        "   2. Tampil data mahasiswa\n"
        "   3. Cari data mahasiswa\n"
        "   4. Urutkan Data Mahasiswa\n"
        "   5. Keluar Program\n");
        printf("\nPilihan Anda (1/2/3/4/5): ");
        scanf("%d", &pilih);
        system("cls");
        switch (pilih)
        {
        case 1:
            input_data(mahasiswa, &size);
            break;
        case 2:
            tampil_data(mahasiswa, size);
            break;
        case 3:
            printf("Cari data berdasarkan: \n"
                "1. NIM\n"
                "2. Nama\n"
                "3. Nilai\n");
            printf("\nPilihan Anda (1/2/3): ");
            scanf("%d", &pilih3);
            getchar();
            if (pilih3 != 1 && pilih3 != 2 && pilih3 != 3) {
                printf("Salah Input\n");
                break;
            }
            printf("Data otomatis diurutkan menaik\n");
            M = binary_search(mahasiswa, size, pilih3);
            if (M != -1)
                tampil_data_search(mahasiswa, size, M);
            else
                printf("Data yang dicari tidak ada\n");
            break;
        case 4:
            printf("Pilihan Pengurutan: \n"
                "   1. Berdasarkan NIM\n"
                "   2. Berdasarkan Nama\n"
                "   3. Berdasarkan Nilai\n");
            printf("\nPilihan Anda (1/2/3): ");
            scanf("%d", &pilih2);
            if (pilih2 != 1 && pilih2 != 2 && pilih2 != 3) {
                printf("Salah Input\n");
                break;
            }
            getchar();
            printf("Opsi pengurutan Naik/Turun (N/T): ");
            scanf("%c", &urut);
            urut = toupper(urut);
            if (urut != 'N' && urut != 'T') {
                printf("Salah Input\n");
                break;
            }
            printf("Menjalankan sorting mahasiswa dengan metode selection sort\n");
            pengurutan(urut);
            selection_sort(mahasiswa, size, urut, pilih2);
            printf("Data telah diurutkan");
            break;
        case 5:
            printf("Terima kasih telah menggunakan program ini\n");
            break;
        default:
            printf("Salah input pilihan, silakan pilih kembali\n");
            break;
        }
    } while (pilih != 5);
}