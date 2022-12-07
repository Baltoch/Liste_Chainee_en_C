#include <stdio.h>
#include <stdlib.h>

#define NBCLIENT 2

//On souhaite gérer une liste chaînée quelconque de clients avec des structures de type t_client.
//Pour information, un des champs de la structure du client de type t_client est un int nommé « age »,
//un autre qui permet le chaînage est un t_client * nommé « suiv ».
typedef struct client
{
    int age;
    struct client *suiv;
}t_client;

// Ecrire et commenter les 3 sous-programmes suivants qui seront appelés du main() :
//- « alloue_client » qui réalise l’allocation dynamique de l’espace mémoire nécessaire à un
//        nouveau client et saisit son age à blinder avec une valeur positive. (2 points)
void alloue_client(t_client **client)
{
    int age;
    *client = (t_client*)malloc(sizeof(t_client));
    do {
        printf("Entrez l\'age:\n");
        scanf("%d", &age);
    } while(age < 0 || age > 130);
}

//- « ajout_client » qui réalise l’ajout en tête d’un nouveau client dans la liste chaînée des clients.
//(2 points)
void ajout_client(t_client **ancre)
{
    if(*ancre == NULL)
    {
        alloue_client(ancre);
        (*ancre)->suiv = NULL;
    }
    else
    {
        t_client *client = NULL;
        alloue_client(&client);
        client->suiv = *ancre;
        *ancre = client;
    }
}

//- « compte_age » qui reçoit l’ancre d’une liste chaînée quelconque de clients et compte le
//        nombre de clients dans la liste qui ont entre 20 et 40 ans, bornes comprises. (2 points)
int compte_age(t_client *ancre)
{
    int compteur = 0;
    t_client *here = ancre;
    while(here != NULL)
    {
        if(here->age >= 20 && here->age <= 40)
        {
            compteur++;
        }
        here = here->suiv;
    }
    return compteur;
}

// Ecrire et commenter le main() qui appelle les 3 sous-programmes précédents et affiche le nombre
//de clients dans la tranche d’âge [20,40]. Pas de boucle demandée. (2 point)
int main() {
    int compteur = 0;
    t_client *ancre;
    for (int i = 0; i < NBCLIENT; i++) ajout_client(&ancre);
    compteur = compte_age(ancre);
    printf("%d clients entre 20 et 40 ans\n", compteur);
    return 0;
}
