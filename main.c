#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int papan[UKURAN][UKURAN];
    int lives = 10;
    int row, col, num, moveResult;
    int difficulty;

    // Pilih tingkat kesulitan
    printf("Pilih tingkat kesulitan:\n1. Mudah\n2. Menengah\n3. Sulit\nPilih (1-3): ");
    scanf("%d", &difficulty);

    tingkatkesulitan(papan, difficulty); // Atur papan berdasarkan kesulitan
    system("cls");
    printf("Selamat datang di Sudoku!\n");
    printf("Tebak angka yang hilang. Anda memiliki %d nyawa.\n", lives);

    while (lives > 0)
    {
        tampilkanpapan(papan);

        printf("Masukkan baris (1-9), kolom (1-9), dan angka (1-9) (misal: 1 2 5): ");
        scanf("%d %d %d", &row, &col, &num);

        row--;
        col--; // Mengurangi 1 agar sesuai dengan indeks array (0-8)

        moveResult = pengisiansudoku(papan, papan, row, col, num);

        if (moveResult == 0)
        {
            lives--; // Jika move salah, kehilangan 1 nyawa
            printf("Nyawa Anda tersisa %d\n", lives);
        }

        if (lives == 0)
        {
            printf("Game Over! Anda kehabisan nyawa.\n");
            printf("Press any key to exit...\n");

            // Bersihkan buffer input
            while (getchar() != '\n')
                ;      // Membersihkan buffer dari input sebelumnya
            getchar(); // Menunggu input dari pengguna

            break; // Keluar dari game setelah pemain menang
        }
        if (sudokuselesai(papan))
        {
            printf("Selamat, Anda menang! yeayyy dapet IPK 4\n");
            printf("Press any key to exit...\n");

            // Bersihkan buffer input
            while (getchar() != '\n')
                ;      // Membersihkan buffer dari input sebelumnya
            getchar(); // Menunggu input dari pengguna

            break; // Keluar dari game setelah pemain menang
        }
    }

    return 0;
}
