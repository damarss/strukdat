#include <stdio.h>

struct data_tanggal
{
    int tanggal;
    int bulan;
    int tahun;
} today = {28, 7, 1998};

int main() {
    printf("%d - %d - %d", today.tanggal, today.bulan, today.tahun);

    return 0;
}
