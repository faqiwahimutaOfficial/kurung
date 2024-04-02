#include <stdio.h>
#include <string.h>

struct TumpukanKurung
{
    int atas;
    char item[100];
};

// Fungsi untuk mengecek apakah tumpukan kosong
int kosong(struct TumpukanKurung *tumpukan)
{
    return (tumpukan->atas == -1);
}

// Fungsi untuk menambahkan elemen ke tumpukan
void push(struct TumpukanKurung *tumpukan, char item)
{
    tumpukan->item[++tumpukan->atas] = item;
}

// Fungsi untuk menghapus elemen dari tumpukan
char pop(struct TumpukanKurung *tumpukan)
{
    if (!kosong(tumpukan))
        return tumpukan->item[tumpukan->atas--];
    return '$';
}

// Fungsi untuk memeriksa apakah tumpukan sesuai
int cocok(char karakter1, char karakter2)
{
    return (karakter1 == '(' && karakter2 == ')') ||
           (karakter1 == '{' && karakter2 == '}') ||
           (karakter1 == '[' && karakter2 == ']');
}

// Fungsi untuk mengecek apakah urutan kurung di dalam inputan seimbang
int seimbang(char *inputan)
{
    struct TumpukanKurung tumpukan;
    tumpukan.atas = -1;

    // Iterasi melalui setiap karakter dalam inputan
    for (int i = 0; inputan[i] != '\0'; i++)
    {
        // Jika karakter adalah kurung buka, dorong ke tumpukan
        if (inputan[i] == '(' || inputan[i] == '{' || inputan[i] == '[')
        {
             push(&tumpukan, inputan[i]);
        }
        // Jika karakter adalah kurung tutup, periksa kecocokannya dengan tumpukan
        else if (inputan[i] == ')' || inputan[i] == '}' || inputan[i] == ']')
        {
            // Jika tumpukan kosong atau kurung tidak cocok, kembalikan 0
            if (kosong(&tumpukan) || !cocok(tumpukan.item[tumpukan.atas], inputan[i]))
                return 0;
            // Jika cocok, ambil kurung dari tumpukan
            pop(&tumpukan);
        }
    }

    // Jika tumpukan kosong, berarti urutan kurung seimbang
    return kosong(&tumpukan);
}

int main()
{
    char inputan[100];
    printf("Masukkan Input : ");
    scanf("%s", inputan);

    if (seimbang(inputan))
        printf("Hasil output : YES\n");
    else
        printf("Hasil output : NO\n");

    return 0;
}
