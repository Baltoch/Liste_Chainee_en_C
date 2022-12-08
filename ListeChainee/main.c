#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
{
    int content;
    struct maillon *suiv;
}maillon;

void AjoutEnFin(maillon **ancre,  int element)
{
    if(*ancre == NULL)
    {
        *ancre = malloc(sizeof(maillon));
        maillon *here = *ancre;
        here->suiv = NULL;
        here->content = element;
    }
    else
    {
        maillon *here = *ancre;
        while(here->suiv != NULL)
        {
            here = here->suiv;
        }
        here->suiv = malloc(sizeof(maillon));
        here = here->suiv;
        here->suiv = NULL;
        here->content = element;
    }
}

void SupprimeDernier(maillon **ancre)
{
    if(*ancre == NULL)
    {
        printf("Erreur: La liste est vide\n");
    }
    else
    {
        maillon *here = *ancre;
        if(here->suiv == NULL)
        {
            free(*ancre);
            *ancre = NULL;
        }
        while(here->suiv->suiv != NULL)
        {
            here = here->suiv;
        }
        free(here->suiv);
        here->suiv = NULL;
    }
}

void AjoutDebut(maillon **ancre, int element)
{
    if(*ancre == NULL)
    {
        *ancre = malloc(sizeof(maillon));
        if(*ancre == NULL)
        {
            printf("Erreur d\'alloc\n");
        }
        maillon *here = *ancre;
        here->suiv = NULL;
        here->content = element;
    }
    else
    {
        maillon *here = NULL;
        here = malloc(sizeof(maillon));
        here->suiv = *ancre;
        *ancre = here;
        here->content = element;
    }
}

void SupprimePremier(maillon **ancre)
{
    if(*ancre == NULL)
    {
        printf("Erreur: La liste est vide\n");
    }
    else if((*ancre)->suiv == NULL)
    {
        free(*ancre);
        *ancre = NULL;
    }
    else
    {
        maillon *here = *ancre;
        here = here->suiv;
        free(*ancre);
        *ancre = here;
    }
}

void AjoutRang(maillon **ancre, int rang, int element)
{
    if(*ancre == NULL && rang == 0)
    {
        *ancre = malloc(sizeof(maillon));
        maillon *here = *ancre;
        here->suiv = NULL;
    }
    else if(*ancre != NULL)
    {
        if(rang == 0)
        {
            maillon *here = NULL;
            here = malloc(sizeof(maillon));
            here->suiv = *ancre;
            *ancre = here;
            here->content = element;
        }
        else
        {
            int i = 0;
            maillon *here = *ancre;
            while(here != NULL)
            {
                i++;
                if(i == rang)
                {
                    maillon *new = NULL;
                    new = malloc(sizeof(maillon));
                    new->suiv = here->suiv;
                    here->suiv = new;
                    new->content = element;
                }
                here = here->suiv;
            }
            if(i < rang)
            {
                printf("Erreur le rang demande est trop grand\n");
            }
        }
    }
}

void SupprimeRang(maillon **ancre, int rang)
{
    if(*ancre == NULL)
    {
        printf("Erreur: La liste est vide\n");
    }
    else if(rang == 0)
    {
        SupprimePremier(ancre);
    }
    else
    {
        maillon *here = *ancre;
        int i = 0;
        while(here->suiv != NULL)
        {
            i++;
            if(i == rang)
            {
                maillon *temp = here->suiv;
                here->suiv = temp->suiv;
                free(temp);
            }
            here = here->suiv;
        }
    }
}

void AffichageListe(maillon *ancre)
{
    while(ancre != NULL)
    {
        printf("%d", ancre->content);
        ancre = ancre->suiv;
    }
}

int main() {
    int choix;
    int element;
    int rang;
    maillon *ancre = NULL;
    do {
        printf("Menu:\n");
        printf("1. Ajouter a la fin de la liste\n");
        printf("2. Supprimer a la fin de la liste\n");
        printf("3. Ajouter en debut de liste\n");
        printf("4. Supprimer le premier element\n");
        printf("5. Ajouter a un rang\n");
        printf("6. Supprimer a un rang\n");
        printf("7. Quitter\n");
        printf("Entrer l\'entier correspondant a votre choix:\n");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                printf("Entrer l\'entier a ajouter:\n");
                scanf("%d", &element);
                AjoutEnFin(&ancre, element);
                break;
            case 2:
                SupprimeDernier(&ancre);
                break;
            case 3:
                printf("Entrer l\'entier a ajouter:\n");
                scanf("%d", &element);
                AjoutDebut(&ancre, element);
                break;
            case 4:
                SupprimePremier(&ancre);
                break;
            case 5:
                printf("Entrer le rang:\n");
                scanf("%d", &rang);
                printf("Entrer l\'entier a ajouter:\n");
                scanf("%d", &element);
                AjoutRang(&ancre, rang, element);
            case 6:
                printf("Entrer le rang:\n");
                scanf("%d", &rang);
                SupprimeRang(&ancre, rang);
                break;
            default:
                choix = 7;
                printf("Erreur\n");
                break;
        }
        AffichageListe(ancre);
    } while(choix != 7);
    return 0;
}
