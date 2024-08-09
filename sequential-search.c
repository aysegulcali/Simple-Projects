#include <stdio.h>

/* Ardışık arama fonksiyonu */
void ardisik_arama(int dizi[], int boyut, int aranan)
{
    int i = 0;
    while (i < boyut)
    {
        if (dizi[i] == aranan)
        {
            printf("%d sayısı, dizinin %d. konumunda.\n", aranan, i);
            break;
        }
        i++;
    }

    if (i == boyut)
    {
        printf("%d sayısı dizide bulunamadı.\n", aranan);
    }
}

int main()
{
    int aranan1, aranan2;
    int dizi[] = {10, 14, 11, 26, 16};

    // dizinin eleman sayısı tespit edilecek
    int boyut = sizeof(dizi) / sizeof(int);
    printf("Aranan 1 = ");
    scanf("%d", &aranan1);
    printf("Aranan 2 = ");
    scanf("%d", &aranan2);

    ardisik_arama(dizi, boyut, aranan1);
    ardisik_arama(dizi, boyut, aranan2);

    return 0;
}
