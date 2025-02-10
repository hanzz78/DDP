#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

///////baruuuuuu

void tingkatkesulitan(int papan[UKURAN][UKURAN], int difficulty) {
    // Papan Sudoku yang sudah terisi dengan solusi
    int solution[UKURAN][UKURAN] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}};

    // Tentukan jumlah sel yang terisi berdasarkan tingkat kesulitan
    int selterisi;
    switch (difficulty) {
    case 1: // Mudah
        selterisi = 69;
        break;
    case 2: // Menengah
        selterisi = 20;
        break;
    case 3: // Sulit
        selterisi = 10;
        break;
    default:
        selterisi = 30; // Default ke Mudah
        break;
    }

    // Salin papan solusi ke papan game
    for (int i = 0; i < UKURAN; i++) {
        for (int j = 0; j < UKURAN; j++) {
            papan[i][j] = solution[i][j];
        }
    }

    // Kosongkan beberapa sel sesuai dengan tingkat kesulitan
    int penghapusansel = UKURAN * UKURAN - selterisi;

    // Buat daftar semua koordinat
    int indices[UKURAN * UKURAN];
    for (int i = 0; i < UKURAN * UKURAN; i++) {
        indices[i] = i;
    }

    // Acak daftar indeks koordinat
    srand(time(NULL)); // Seed untuk random
    for (int i = UKURAN * UKURAN - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    // Hapus sel berdasarkan indeks yang diacak
    for (int k = 0; k < penghapusansel; k++) {
        int row = indices[k] / UKURAN; // Baris dari indeks
        int col = indices[k] % UKURAN; // Kolom dari indeks
        papan[row][col] = 0;
    }
}
// Fungsi untuk mencetak papan Sudoku
void tampilkanpapan(int papan[UKURAN][UKURAN])
{
    printf("\n    1 2 3   4 5 6   7 8 9\n");
    printf("  +-------+-------+-------+\n");
    for (int i = 0; i < UKURAN; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("  +-------+-------+-------+\n");
        }
        printf("%d | ", i + 1); // Menampilkan nomor baris
        for (int j = 0; j < UKURAN; j++)
        {
            if (papan[i][j] == 0)
            {
                printf(". "); // Menampilkan titik jika sel kosong
            }
            else
            {
                printf("%d ", papan[i][j]);
            }
            if ((j + 1) % 3 == 0 && j != UKURAN - 1)
            {
                printf("| "); // Menambahkan pembatas antar kotak
            }
        }
        printf("|\n");
    }
    printf("  +-------+-------+-------+\n");
}

// Fungsi untuk memvalidasi apakah angka dapat ditempatkan pada baris, kolom, dan kotak kecil
int pengecekanangka(int papan[UKURAN][UKURAN], int row, int col, int num)
{
    for (int i = 0; i < UKURAN; i++)
    {
        if(papan[row][i]==num)
        {
            printf("angka yang anda masukan pada titik (%d,%d) tidak valid karena angka sudah berada pada baris %d. \n", row+1, col+1, row+1);
            return 0;  //jika angka yang dimasukan sudah ada dalam baris yang sama 
        }
        if(papan[i][col]==num)
        {
            printf("angka yang anda masukan pada titik (%d, %d) tidak valid karena angka sudah berada pada kolom %d. \n", row+1, col+1, col+1);
            return 0; // jika angka yang dimasukan sudah ada dalam kolom yang sama
        }
    }
    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (papan[boxStartRow + i][boxStartCol + j] == num)
            {
                printf("angka yang anda masukan pada titik (%d,%d) tidak valid karena angka sudah terdapat dalam kolom 3x3 yang sama. \n", row+1, col+1);
                return 0; // Jika angka ada di kotak kecil 3x3, move tidak valid
            }
        }
    }
    return 1; // Angka bisa ditempatkan
}

//fungsi ketika angka yang sudah dimasukan ada di dalam baris yang sama 

// Fungsi untuk mencoba melakukan move
int pengisiansudoku(int papan[UKURAN][UKURAN], int solution[UKURAN][UKURAN], int row, int col, int num)
{

    if (num > 9)
    {
        printf("angka yang dimasukan tidak valid!! \n");
        return 0; // jika angka yang dimasukan lebih dari 9, tidak valid
    }
    if (papan[row][col] != 0)
    {
        printf("Sel sudah terisi! Coba tempatkan angka lain.\n");
        return 0; // Jika sel sudah terisi
    }

    if (pengecekanangka(papan, row, col, num))
    {
        papan[row][col] = num; // Tempatkan angka jika valid
        return 1;
    }
    else{
        return 0;
    }
        
    

}

int sudokuselesai(int papan[UKURAN][UKURAN])
{
    for (int i = 0; i < UKURAN; i++)
    {
        for (int j = 0; j < UKURAN; j++)
        {
            if (papan[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
