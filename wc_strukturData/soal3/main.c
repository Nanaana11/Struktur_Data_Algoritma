#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//node simpan mahasiswa
typedef struct Mahasiswa {
    char nama[50];
    char peran[50];
    struct Mahasiswa* next;
} Mahasiswa;

//pointer ke head linked list
Mahasiswa* head = NULL;

//tambah mahasiswa
void tambahMahasiswa(char* nama, char* peran) {
    Mahasiswa* newNode = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(newNode->nama, nama);
    strcpy(newNode->peran, peran);
    newNode->next = head;
    head = newNode;
    printf("Mahasiswa %s dengan peran %s telah ditambahkan.\n", nama, peran);
}

//show daftar mahasiswa
void tampilkanMahasiswa() {
    if (head == NULL) {
        printf("Tidak ada mahasiswa yang terdaftar.\n");
        return;
    }
    Mahasiswa* temp = head;
    printf("\nDaftar Mahasiswa yang Mengikuti Lomba:\n");
    while (temp != NULL) {
        printf("Nama: %s, Peran: %s\n", temp->nama, temp->peran);
        temp = temp->next;
    }
}

//ubah peran mahasiswa
void ubahPeran(char* nama, char* peranBaru) {
    Mahasiswa* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->nama, nama) == 0) {
            strcpy(temp->peran, peranBaru);
            printf("Peran mahasiswa %s telah diubah menjadi %s.\n", nama, peranBaru);
            return;
        }
        temp = temp->next;
    }
    printf("Mahasiswa dengan nama %s tidak ditemukan.\n", nama);
}

//hapus mahasiswa
void hapusMahasiswa(char* nama) {
    Mahasiswa* temp = head;
    Mahasiswa* prev = NULL;

    while (temp != NULL && strcmp(temp->nama, nama) == 0) {
        head = temp->next;
        free(temp);
        printf("Mahasiswa %s telah dihapus.\n", nama);
        return;
    }

    while (temp != NULL && strcmp(temp->nama, nama) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Mahasiswa dengan nama %s tidak ditemukan.\n", nama);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Mahasiswa %s telah dihapus.\n", nama);
}

int main() {
    int pilihan;
    char nama[50];
    char peran[50];

    do {
        printf("\nMenu:\n");
        printf("1. Daftar Mahasiswa\n");
        printf("2. Tambah Mahasiswa\n");
        printf("3. Ubah Peran Mahasiswa\n");
        printf("4. Hapus Mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                tampilkanMahasiswa();
                break;
            case 2:
                printf("Masukkan nama mahasiswa: ");
                fgets(nama, 50, stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Masukkan peran mahasiswa: ");
                fgets(peran, 50, stdin);
                peran[strcspn(peran, "\n")] = 0;
                tambahMahasiswa(nama, peran);
                break;
            case 3:
                printf("Masukkan nama mahasiswa yang ingin diubah perannya: ");
                fgets(nama, 50, stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Masukkan peran baru: ");
                fgets(peran, 50, stdin);
                peran[strcspn(peran, "\n")] = 0;
                ubahPeran(nama, peran);
                break;
            case 4:
                printf("Masukkan nama mahasiswa yang ingin dihapus: ");
                fgets(nama, 50, stdin);
                nama[strcspn(nama, "\n")] = 0;
                hapusMahasiswa(nama);
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid, coba lagi.\n");
        }
    } while (pilihan != 5);

    return 0;
}
