//Flobert JOHNSON 1BTS SNIR
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int recherche_et_modifie_caractere(char *c,char mot[],char mot2[]);

int error=0;
char lettreentre=0;
char newlettre[15]="";
int nombre_de_coup=6,nbrEssai=0,maxFaute=6;
char mot[15]="";
char tab[15]="";
char tab2[15]="";
char mot2[15]="";
int i=0,j=0,l=0,p=0;


int main () {
        printf("Bienvenue dans le jeu du pendu\n\n");

        FILE *fichier = NULL;                                                                                   //Pour identifier que fichier est un fichier
        fichier = fopen("C:\\Users\\johns\\Videos\\mini_projet\\mousseau\\Mots.txt", "r");     //Pour ouvrir un fichier


        if (fichier == NULL) {
            printf("impossible d'ouvrir le fichier");                        //Affiche un message si le fichier n'est trouve
            return 0;
        } else
            srand(time(NULL));                                          //Initialisation de temps a 0

        j = rand() % 80;                                                             //Nombre aleatoire pour choisir un fichier

        for (i = 0; i < j; i++) {
            fgets(mot, 80, fichier);                                      //Choisit un mot dans le fichier parmis les 80 mots
        }
    for (i = 0; i < strlen(mot); i++) {
        tab[i]=mot[i];                                                                  //Initialisation avec un autre tableau
    }
        //printf("%s", tab);                                                      //Affiche le mot correct

        strcpy(mot2, mot);                                                              //Permet de copier le contenu du caractere de mot dans mot2

        for (i = 0; i < strlen(mot) - 1; i++) {
            mot[i] = '-';                                                               //Pour cacher le mots en signe'-'
        }
    printf("Vous pouvez faire %d fautes",nombre_de_coup);
    printf("\nMot cache\n");
    printf("%s\n", mot);
    printf("Saisir une lettre : ");
    scanf("%s", &lettreentre);
    if (recherche_et_modifie_caractere(&lettreentre, mot, mot2) !=0){
        nombre_de_coup != 0;
    }
    else{
        nombre_de_coup--;
        error=1;
        printf("\nFaux\n");
        printf("il vous reste %d coups\n", nombre_de_coup);
        newlettre[l]=lettreentre;                                                      //Affiche un message pour dire que les lettres faux utilise
        l++;                                                                           //Incrementation de l
    }

        while (nombre_de_coup != 0) {
            if (recherche_et_modifie_caractere(&lettreentre, mot, mot2) !=0) {
                printf("\nCorrect\n");
                printf("il vous reste %d coups\n", nombre_de_coup);
            }
                printf("\nMot cache\n");
                printf("%s\n", mot);                                                //Mot cache en signe '-'
                printf("Saisir une lettre sauf %s : ", newlettre);
                scanf("%s", &lettreentre);                                          //Lettre ecrite par le joueur
                if(tab2[p]==lettreentre){
                    printf("DEJA ESSAYE, IMBECILE !!!");
                }
                tab2[p]=lettreentre;
                p++;

            while (!(getc(stdin) == '\n'));
            recherche_et_modifie_caractere(&lettreentre, mot, mot2);

            nbrEssai++;                                                                 //Incrementation du nombre d'essai
            printf("%s\n", mot);                                                //Affiche le signe'-' par rapport aux nombres lettre du mot aleatoire

            if (recherche_et_modifie_caractere(&lettreentre, mot, mot2) < 1) {              //Si la valeur retourne est 0
                nombre_de_coup--;                                                           //Decrementation du nombre de coup
                error++;
                /*if (tab2[l] == lettreentre) {
                    printf("DEJA ESSAYE, IMBECILE !!!");
                }*/
                printf("\nFaux\n");
                printf("il vous reste %d coups\n", nombre_de_coup);
                newlettre[l]=lettreentre;                                                   //Stocke la mauvaise lettre ecrite dans le tableau newlettre
                l++;                                                                        //Incrementation de l
            }
            else if (strcmp(mot2, mot) == 0) {
                printf("\nGAGNE!!!\n");                                              //Affiche message si gagne
                printf("Le mot a trouver etait : %s",tab);                           //Affiche message si gagne
                printf("Etat du mot trouve : %s",mot);                               //Affiche message si gagne
                printf("Nombre d'essais : %d \n",nbrEssai);                          //Affiche message si gagne
                printf("Vous avez fait %d fautes\n",maxFaute-nombre_de_coup);        //Affiche message si gagne
                return 0;
            }

            if (error == 1) {
                printf("| \n");
                printf("| \n");
                printf("| \n");
                printf("| \n");
                printf("| \n");
                printf("_______");
            }
            if (error == 2) {
                printf("___________________\n");
                printf("|                 | \n");
                printf("|                 | \n");
                printf("| \n");
                printf("| \n");
                printf("| \n");
                printf("| \n");
                printf("_______\n");
            }
            if (error == 3) {
                printf("___________________\n");
                printf("|                 | \n");
                printf("|                 | \n");
                printf("|                 O \n");
                printf("| \n");
                printf("| \n");
                printf("| \n");
                printf("_______\n");
            }
            if (error == 4) {
                printf("___________________\n");
                printf("|                 | \n");
                printf("|                 | \n");
                printf("|                 O \n");
                printf("|                 | \n");
                printf("| \n");
                printf("| \n");
                printf("_______\n");
            }
            if (error == 5) {
                printf("___________________\n");
                printf("|                 | \n");
                printf("|                 | \n");
                printf("|                 O \n");
                printf("|                /|\\ \n");
                printf("| \n");
                printf("| \n");
                printf("_______\n");
            }
            if (error == 6) {
                printf("___________________\n");
                printf("|                 | \n");
                printf("|                 | \n");
                printf("|                 O \n");
                printf("|                /|\\ \n");
                printf("|                / \\\n");
                printf("| \n");
                printf("_______\n");
            }

            /*for (l = 0; l < 10; l++) {
                tab2[l]=newlettre[l];                                                              //Initialisation avec un autre tableau
            }*/

        }
        printf("\nPERDU!!!\n");                                             //Affiche message si perdu
    printf("\nLe mot a trouver etait : %s",tab);                            //Affiche message si perdu
    printf("Etat du mot trouve : %s",mot);                                  //Affiche message si perdu
    printf("Nombre d'essais : %d \n",nbrEssai);                             //Affiche message si perdu
    printf("Vous avez fait %d fautes\n",maxFaute-nombre_de_coup);           //Affiche message si perdu
        return 0;
    }
int recherche_et_modifie_caractere(char *c,char mot[],char mot2[])                  //verifie la lettre ecrite par le joueur
{
    int j=0;
    int i =0;

    while(mot2[j] != '\0')                                                  //Tant que le mot aleatoire n'est pas null
    {
        if(mot2[j] == *c)                                                   //Verifie si le mot aleatoire contient la lettre ecrite par le joueur
        {
            mot[j]=*c;                                                      //Si le mot contient la lettre, la lettre sera stocke dans le tableau mot
            i++;                                                            //Incrementation de i
        }
            j++;                                                            //Incrementation de j
    }
        return i;                                                           //Retourne la valeur si 0 mauvaise lettre sinon bonne lettre
}