#ifndef HEADER_H
#define HEADER_H
#include <stdlib.h>

#define UKURAN 9 // Ukuran papan Sudoku 9x9

// Fungsi untuk menampilkan papan
void tampilkanpapan(int board[UKURAN][UKURAN]);

// Fungsi untuk memvalidasi apakah angka bisa ditempatkan
int pengecekanangka(int board[UKURAN][UKURAN], int row, int col, int num);

// Fungsi untuk mencoba melakukan move
int pengisiansudoku(int board[UKURAN][UKURAN], int solution[UKURAN][UKURAN], int row, int col, int num);
// fungsi tingkat kesulitan
void tingkatkesulitan(int board[UKURAN][UKURAN], int difficulty);

// fungsi jika semua kolom sudah terisi
int sudokuselesai(int board[UKURAN][UKURAN]);

#endif
