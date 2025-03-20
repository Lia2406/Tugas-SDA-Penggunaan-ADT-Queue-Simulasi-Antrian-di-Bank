#include <stdio.h>
#include "queue.h"

int main() {
    Queue antrian = createQueue();
    int pilihan;
    int nomorAntrian = 1;

    printf("Program Simulasi Antrian Bank\n");
    printf("============================\n");

    do {
        printf("\nMenu:\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                enqueue(&antrian, nomorAntrian);
                printf("Nomor antrian Anda: %d\n", nomorAntrian);
                nomorAntrian++;
                printf("=============================================================================");
                printf("\nAntrian saat ini:\n");
                displayQueue(antrian);
                break;

            case 2:
                if (isEmptyQueue(antrian)) {
                    printf("Antrian kosong!\n");
                } else {
                    int nomor = dequeue(&antrian);
                    printf("Memproses antrian nomor: %d\n", nomor);
                    printf("=============================================================================");
                    printf("\nAntrian saat ini:\n");
                    displayQueue(antrian);
                }
                break;

            case 3:
                if (isEmptyQueue(antrian)) {
                    printf("Antrian kosong!\n");
                } else {
                    printf("\nAntrian saat ini:\n");
                    displayQueue(antrian);
                }
                break;

            case 4:
                printf("Terima kasih telah menggunakan menggunakan BANK kami!\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);

    destroyQueue(&antrian);
    return 0;
} 
