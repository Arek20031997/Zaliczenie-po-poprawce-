#include <stdio.h>
#include <stdlib.h>

int main() {
    int wodaWZbiorniku = 0;
    int dodanaWoda;
    int odjetaWoda;
    int wybor;
    float opadNaMetr;
    int maxPojemnosc = 10000;
    int powierzchniaDachu = 100;

    FILE *plik;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Podaj ilosc wody w zbiorniku (manualny odczyt)\n");
        printf("2. Pokaz aktualna ilosc wody w zbiorniku\n");
        printf("3. Dodaj wode na podstawie opadow\n");
        printf("4. Ile wody potrzebujesz pobrac?\n");
        printf("5. Zapisz biezaca ilosc wody do pliku\n");
        printf("6. Zakoncz program\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                printf("Ile wody jest w zbiorniku? (litry): ");
                if (scanf("%d", &dodanaWoda) != 1 || dodanaWoda < 0 || dodanaWoda > maxPojemnosc) {
                    printf("Nieprawidlowa wartosc. Podaj dodatnia liczbe nie przekraczajaca pojemnosci zbiornika.\n");
                    while (getchar() != '\n');
                    continue;
                }

                wodaWZbiorniku = dodanaWoda;
                printf("Aktualna ilosc w zbiorniku: %d litrow\n", wodaWZbiorniku);
                break;

            case 2:
                printf("Aktualna ilosc wody w zbiorniku: %d litrow\n", wodaWZbiorniku);
                break;

            case 3:
                printf("Ile wody spadlo na metr kwadratowy (litry/m2): ");
                if (scanf("%f", &opadNaMetr) != 1 || opadNaMetr < 0) {
                    printf("Nieprawidlowa wartosc. Podaj dodatnia liczbe.\n");
                    while (getchar() != '\n');
                    continue;
                }

                dodanaWoda = (int)(opadNaMetr * powierzchniaDachu );

                if (wodaWZbiorniku + dodanaWoda > maxPojemnosc) {
                    printf("Przekroczono maksymalna pojemnosc zbiornika!\n Czesc wody spadla na ziemie.\n Oproznij zbiornik!!!\n", maxPojemnosc);
                } else {
                    wodaWZbiorniku += dodanaWoda;
                    printf("Dodano %d litrow wody na podstawie opadow.\n Aktualna ilosc w zbiorniku: %d litrow\n", dodanaWoda, wodaWZbiorniku);
                }
                break;

            case 4:
                printf("Ile litrow wody potrzebujesz pobrac? ");
                if (scanf("%d", &odjetaWoda) != 1 || odjetaWoda < 0 || odjetaWoda > wodaWZbiorniku) {
                    printf("Nieprawidlowa wartosc. Podaj dodatnia liczbe nie wieksza od aktualnej ilosci wody w zbiorniku.\n");
                    while (getchar() != '\n');
                    continue;
                }

                wodaWZbiorniku -= odjetaWoda;
                printf("Odjeto %d litrow wody z zbiornika.\nAktualna ilosc wody w zbiorniku: %d litrow\n", odjetaWoda, wodaWZbiorniku);
                break;

            case 5:
                plik = fopen("ilosc_wody.txt", "a");
                if (plik == NULL) {
                    printf("Nie mozna otworzyc pliku.\n");
                    exit(EXIT_FAILURE);
                }
                fprintf(plik, "Ilosc wody w zbiorniku %d litrow\n", wodaWZbiorniku); // Dodaj znak nowej linii po każdym zapisie
                fclose(plik);
                printf("Biezaca ilosc wody zostala zapisana do pliku 'ilosc_wody.txt'.\n");
                break;

            case 6:
                printf("Koniec programu.\n");
                return 0;

            default:
                printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
                break;
        }
    }

    return 0;
}
