#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdbool.h>

#define MAXCHAR 100000

using namespace std;


int main(int argc, char *argv[]) {

    // system("gunzip geoip.csv.tz");

    int ip0;
    int ip1;
    int ip2;
    int ip3;

    // On récupére l'adresse IP selon le format %d.%d.%d.%d
    sscanf(argv[1], "%d.%d.%d.%d", &ip0, &ip1, &ip2, &ip3);

    int ipDecimal = ip3 + (ip2 * 256) + (ip1 * 256 * 256) + (ip0 * 256 * 256 * 256);

    printf("%d \n", ipDecimal);

    FILE *fp;
    char row[MAXCHAR];
    char *token;

    // On va ouvrir le fichier csv en readable
    fp = fopen("geoip.csv","r");

    char *minRange;
    char *maxRange;
    char *pays;

    while (feof(fp) != true) {
        // On lit toutes les lignes du csv 
        fgets(row, MAXCHAR, fp);
        // printf("Row: %s \n", row);

        token = strtok(row, ",");

        int i = 0;
        // Tant qu'on a une cellule on va continuer de lire les données
        while(token != NULL) {

            // Cette boucle va nous permettre d'enlever les " dans les données si elles existent. 
            for (int j = 1; j < strlen(token); j++) {
                if (token[j] == '"') {
                    token[j] = token[j+1];
                }
                token[j-1] = token[j];
            }
            
           // printf("Token %s | Index i = %d \n", token, i);

            // On récupére uniquement les trois premières cellules car les autres ne nous intéressent pas. 
            if (i == 0) {
                i++;
                minRange = token;
            } else if (i == 1) {
                i++;
                maxRange = token;
            } else if (i == 2) {
                i++;
                pays = token;
            } else {
                break;
            }

            // On va convertir les plages d'adresses IP en int grâce à la fonction atoi(). 
            int minRangeToInt = atoi(minRange);
            int maxRangeToInt = atoi(maxRange);

            // Si on trouve une adresse IP dans cette plage on va retourner le pays. 
            if (ipDecimal >= minRangeToInt && ipDecimal <= maxRangeToInt) {
                printf("L\'adresse IP vient du pays : %s \n", pays);
                return 0;
            }

            token = strtok(NULL, ",");
        }
    }

    return 0;
}