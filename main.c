#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "product.frht"

struct Product {
    int id;
    char name[20];
    float price;
    int stock;
};

void menu();
void addProducts();
void updateProducts();
void showProducts();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    while(1) {
        printf("\n-------- Urun Yonetimi -----\n");
        printf("1. Urun Ekleme\n");
        printf("2. Stok Guncelleme\n");
        printf("3. Urunleri Goster\n");
        printf("4. Cikis\n");
        printf("Secim yapiniz: ");

        if(scanf("%d", &choice) != 1) {
            printf("Hatali giris! Lutfen bir sayi giriniz.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                addProducts();
                break;
            case 2:
                updateProducts();
                break;
            case 3:
                showProducts();
                break;
            case 4:
                printf("Programdan cikiliyor...\n");
                exit(0);
            default:
                printf("Hatali islem sectiniz!\n");
        }
    }
}

void addProducts() {
    struct Product p;
    FILE *file = fopen(FILE_NAME, "ab");

    if(file == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    printf("Urun ID: ");
    scanf("%d", &p.id);
    printf("Urun adi: ");
    while(getchar() != '\n');
    scanf("%19s", p.name);
    printf("Urun fiyati: ");
    scanf("%f", &p.price);
    printf("Urun miktari: ");
    scanf("%d", &p.stock);

    fwrite(&p, sizeof(struct Product), 1, file);
    fclose(file);
    printf("Urun basariyla eklendi.\n");
}

void updateProducts() {
    struct Product p;
    int id, newStock = 0;
    int found = 0;

    FILE *file = fopen(FILE_NAME, "rb+");
    if(file == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    printf("Guncellemek istenen urun ID giriniz: ");
    scanf("%d", &id);

    while(fread(&p, sizeof(struct Product), 1, file) == 1) {
        if(p.id == id) {
            printf("Mevcut stok: %d\n", p.stock);
            printf("Yeni stok miktari: ");
            scanf("%d", &newStock);

            p.stock = newStock;
            fseek(file, -sizeof(struct Product), SEEK_CUR);
            fwrite(&p, sizeof(struct Product), 1, file);
            found = 1;
            break;
        }
    }

    fclose(file);

    if(found) {
        printf("Stok basariyla guncellendi!\n");
    } else {
        printf("Urun bulunamadi!\n");
    }
}

void showProducts() {
    struct Product p;
    FILE *file = fopen(FILE_NAME, "rb");

    if(file == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    printf("\n----- Urun Listesi -----\n");
    printf("ID\tAd\t\tFiyat\tStok\n");
    printf("--------------------------------\n");

    while(fread(&p, sizeof(struct Product), 1, file) == 1) {
        printf("%d\t%s\t%.2f\t%d\n", p.id, p.name, p.price, p.stock);
    }

    fclose(file);
}







