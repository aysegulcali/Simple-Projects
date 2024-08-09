#include <stdio.h>

/* Ardışık arama fonksiyonu */
void ardisik_arama(int dizi[], int boyut, int aranan)
{
    printf("\nArdışık arama yapılıyor...\n");
    int i, karsilastirma_sayisi = 0;

    for (i = 0; i < boyut; i++)
    {
        karsilastirma_sayisi++;
        if(dizi[i] == aranan)
        {
            printf("%d sayısı dizinin %d. konumundadır.\n", aranan, i+1);
            break;
        }
    }

    if(i == boyut)
    {
        printf("%d sayısı dizide bulunamadı.\n", aranan);
    }
    printf("Ardışık arama ile %d adet karşılaştırma yapıldı.\n\n", karsilastirma_sayisi);
}


/* İkili arama fonksiyonu */
void ikili_arama(int dizi[], int boyut, int aranan)
{
    printf("İkili arama yapılıyor...\n");
    int i, ilk, son, orta, karsilastirma_sayisi = 0;
    ilk = 0;
    son = boyut - 1;
    orta = (ilk + son) / 2;

    while (ilk <= son)
    {
        karsilastirma_sayisi++;
        printf("İlk: %d. eleman, Orta: %d. eleman, Son: %d. eleman\n", ilk + 1, orta + 1, son + 1);

        if(aranan > dizi[orta])
        {
            ilk = orta + 1;
        }
        else if(aranan == dizi[orta])
        {
            printf("%d sayısı dizinin %d. konumundadır.\n", aranan, orta + 1);
            break;
        }
        else
        {
            son = orta - 1;

            orta = ( ilk + son) / 2;
        }
    }
    if(ilk > son)
    {
        printf("%d sayısı dizide bulunamadı.\n", aranan);
    }
    printf("İkili arama ile %d adet karşılaştırma yapıldı.\n", karsilastirma_sayisi);
}


int main()
{
    int aranan1;
    int dizi[] = { 2, 6, 9, 12, 14, 20, 25 };

    // Dizinin eleman sayısı tespit ediliyor
    int boyut = sizeof(dizi) / sizeof(int);

    // Kullanıcı değer giriyor
    printf("\nAramak istediğiniz sayıyı girin; ");
    scanf("%d", &aranan1);

    //Ardışık arama yapılıyor
    ardisik_arama(dizi, boyut, aranan1);

    // İkili arama yapılıyor
    ikili_arama(dizi, boyut, aranan1);

    return 0;
}
