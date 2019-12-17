#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

void viderBuffer()
{
    //cette fonction permet de vider le buffer
    int c = 0;
    while (c != '\n' && c != EOF)
    {
            c = getchar();
    }
}

void transition()
{
    system("pause");
    system("cls");
}

void presentation()
{
    printf("\nBonjour je m'appelle Searchbot\n");
    transition();
    printf("\nMon but est de trouver un nombre entier positif que vous aurez choisir\n");
    transition();
    printf("\nSi mon nombre est inférieur  au votre, taper '+' \n");
    transition();
    printf("\ns'il est plus grand taper '-' \n");
    transition();
    printf("\net '=' si j'ai trouver\n");
    transition();
}

void pmdichotomie()
/*Cette fonction joue au jeu du plus ou moins
au lieu de faire devenir un nombre à l'utilisateur
c'est elle qui devine le nombre de l'utilisateur
pour se faire elle determine une borne sup et une borne inf
puis faire  des porpositions pas dichotomie selon ces bornes*/
{
    const int CSTE = 1000000;  //constante qui doit être superieure au nombre choisir
                //pour que le programme fonctionne correctement
                //dans le cas sans intervalle
    char reponse, trouve;
    int incorrect = 1, error, inf, sup, proposition;
    //dialogue introductif
    presentation();
    //demande de la preference
    printf("\nVoulez-vous me donner un intervalle ou chercher le nombre\n");
    printf("Tapez 'O' ou 'o' pour oui...\n");
    reponse = getchar();//choix du mode de jeu, avec intervalle ou sans intervalle
    if(reponse != '\n')
        viderBuffer();
    transition();
    if(toupper(reponse) == 'O') //parametrage pour un jeu avec intervalle
    {
        while (incorrect)
        {
            printf("\nDonner la borne inferieure\n"); //saisie de la bonne inf
            //on s'assure que la valeur entree est correcte
            error = scanf("%d", &inf);
            if(error == 0)
            {
                printf("un nombre s'il vous plait\n");
                viderBuffer();
            }
            else if(inf < 0)
                printf("un entier positif s'il vous plait\n");
            else
                incorrect = 0;
            transition();
        }

        incorrect = 1;
        while(incorrect)
        {
            printf("\nDonner la borne superieure\n");    //saisie de la borne sup
            //on s'assure que la valeur entree est correcte
            error = scanf("%d", &sup);
            if(error == 0)
            {
                printf("un nombre s'il vous plait\n");
                viderBuffer();
            }
            else if(sup <= inf)
                printf("un entier strictement plus grand que la borne inferieure s'il vous plait\n");
            else
                incorrect = 0;
            transition();
        }


        proposition = (inf + sup)/2 ;   //initialisation de la 1ere proposition
    }
    else   //parametrage pour un jeu sans intervalle
    {
        proposition = 50;    //initialisation de la 1ere proposition
        inf = 0;    //initialisation de la borne inf
        sup = CSTE;  //initialisation de la borne sup
    }

    trouve = '-';

    printf("\nc'est partir, voici ma premiere proposition\n");   //debut du jeu
    transition();

    while(trouve != '=')
    {
        printf("%d\n", proposition); //affichage de la proposition
        trouve = getchar();    //recuperation de la reponse de l'utilisateur
        viderBuffer();
        if(trouve != '-' && trouve != '+' && trouve  != '=')   //on s'assure que l'utilisateur a faire unensaisie correcte
        {
            transition();
            printf("\nAh ah tu te moque de moi\n");
            printf("j'arrete");
            break;
        }

        if(trouve == '-')
            sup = proposition;
        else if(trouve == '+')
        {
            if(sup != CSTE)
                inf = proposition;
        }
        proposition = (inf + sup)/2;
        system("cls");
    }
    printf("Hourra j'ai trouver");
}




int main()
{
    pmdichotomie();
    return 0;
}
