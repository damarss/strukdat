#include <stdio.h>
#define N 30
int QUEUE[N], QUEUE2[N], rear, front;

void enqueue(int *no_antrean, int *waktu_antrean) {
    if (rear == N-1) {
        printf("Antrean telah penuh\n");
        printf("====================================\n\n");
        return;
    } else {
        printf("Nomor antrean sudah berhasil terambil\n");
    }
    if (front == -1) {
        front = 0;
        *waktu_antrean = 0;
    } else {
        *waktu_antrean += 15;
    }
    rear++;
    (*no_antrean)++;
    printf("Nomor antrean Anda = %d\n", *no_antrean);
    printf("====================================\n\n");
    QUEUE[rear] = *no_antrean;
    QUEUE2[rear] = *waktu_antrean;
}

void display(int antrean[]) {
    if (rear == -1) {
        printf("Antrean kosong \n");
        printf("====================================\n\n");
    } else {
        for (int i = 1; i <= rear; i++) {
            printf("%d ", antrean[i]);
        }
        printf("\n");
        printf("====================================\n\n");
    }
}

void displayWaktuPasien(int antrean[]) {
    if (rear == -1) {
        printf("Antrean kosong \n");
        printf("====================================\n\n");
    } else {
        int i = 1;
        int d = i+1;
        for (int i = 1; i <= rear; i++) {
            printf("Pasien %d = %d \n", d, antrean[i]);
            d++;
        }
        printf("\n");
    }
}

int main() {
    rear = -1;
    front = -1;
    int no_antre = 0;
	int waktu_antre, pilih;

    while (pilih != 4) {
        printf("Program Antrean Pasien Klinik\n");
        printf("====================================\n");
        printf("Silakan pilih menu berikut: \n");
        printf("1. Ambil nomor antrean\n");
        printf("2. Lihat antrean yang tersisa\n");
        printf("3. Lihat perkiraan waktu antre\n");
        printf("4. Keluar \n");
        printf("------------------------------------\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                system("cls");
                enqueue(&no_antre, &waktu_antre);
                break;
            case 2:
                system("cls");
                printf("Daftar Antrian Pasien Saat Ini: ");
                display(QUEUE);
                break;
            case 3:
                system("cls");
                printf("Estimasi waktu tunggu antrean tiap pasien (dalam menit): \n");
                displayWaktuPasien(QUEUE2);
                printf("Estimasi waktu Anda: %d menit\n", waktu_antre);
                printf("====================================\n\n");
                break;
            case 4:
                system("cls");
                printf("Terima kasih dan sampai jumpa kembali\n");
                break;
            default:
                system("cls");
                printf("Maaf, Anda salah input pilihan! Silakan isi pilihan yang tersedia!\n");
                printf("====================================\n\n");
        }
    }

    return 0;
}
