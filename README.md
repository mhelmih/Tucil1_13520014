# Tugas Kecil I IF2211 Strategi Algoritma
> Sebuah program untuk menyelesaikan permainan *Word Search Puzzle* menggunakan algoritma *brute force*.

## Daftar Isi
* [Informasi Umum](#informasi-umum)
* [Setup](#setup)
* [Struktur File](#struktur-file)
* [Penggunaan](#penggunaan)

## Informasi Umum
Program ini dibuat untuk memenuhi tugas Mata Kuliah IF2211 Strategi Algoritma

*Program Studi Teknik Informatika* <br />
*Sekolah Teknik Elektro dan Informatika* <br />
*Institut Teknologi Bandung* <br />

*Semester II Tahun 2021/2022*

Secara umum program ini meminta input puzzle dalam bentuk matriks persegi atau persegi panjang dan sejumlah pola kata. Kemudian program akan mencari pola-pola kata tersebut pada puzzle dengan menggunakan algoritma *brute force*.

## Setup
- Persyaratan dasar
    - Install code editor [VSCode](https://code.visualstudio.com/download).
    - Unduh repository ini dalam bentuk zip, kemudian ekstrak.
- Cara Eksekusi Program
    - Buka terminal pada VSCode, kemudian arahkan ke folder bin pada repository yang sudah diunduh.
    - Run program dengan command di bawah ini.
```
$ .\main
```

## Struktur File
- **bin**
File eksekusi
- **doc**
Laporan pengerjaan tugas.
- **header**
Seluruh file header untuk berbagai *abstract data type*.
- **src**
Seluruh file program serta program utama yakni *main.c*.
- **test**
Berisi file berekstensi *.txt* sebagai penyimpan puzzle.

## Penggunaan
1. Eksekusi program main.
2. Masukkan nama file.
3. Tidak lama setelahnya akan muncul hasil penyelesaian dari puzzle.
4. Jika ingin memasukkan puzzle baru, buatlah file dengan esktensi .txt pada folder test. Kemudian tulis puzzle dalam format sebagai berikut.
```
<puzzle baris ke-1>
<puzzle baris ke-2>
...
<puzzle baris ke-n>

<pola ke-1>
<pola ke-2>
...
<pola ke-n>
```
Contoh
```
W C R K D A P
L Q U R H F U
R U O Y E K Z
G W E A E P Z
S E A R C H L
X I U V M O E
M Y T G W B L

WORD
SEARCH
PUZZLE
```

## Author
Dibuat oleh [Muhammad Helmi Hibatullah](https://github.com/mhelmih) - 13520014
