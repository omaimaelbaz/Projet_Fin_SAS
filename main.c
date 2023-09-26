#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date
{
    int jour;
    int mois;
    int annee;
};

struct tache
{
    int id;
    char titre[50];
    char description[50];
    struct date deadline;
    char status[50];
};

struct tache Taskes[100];
int count_task = 0;

void ajouterTache()
{
    int choix_status;
    struct tache tache_1;
    tache_1.id = count_task + 1;

    printf("Ajouter une nouvelle tache \n");

    printf("Titre : ");
    scanf("%s", tache_1.titre);

    printf("Description : ");
    scanf("%s", tache_1.description);

    printf("Deadline jj-mm-aaaa : ");
    scanf("%02d-%02d-%04d", &(tache_1.deadline.jour), &(tache_1.deadline.mois), &(tache_1.deadline.annee));

    printf("Statut : \n");
    printf("=========================================================================\n");
    printf("[1] : à réaliser  \t [2] : en cours de réalisation   \t [3]: finalisée\n");
    printf("=========================================================================== \n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix_status);

    if (choix_status == 1)
    {
        strcpy(tache_1.status, "a realiser");
    }
    else if (choix_status == 2)
    {
        strcpy(tache_1.status, "en cours de realisation");
    }
    else if (choix_status == 3)
    {
        strcpy(tache_1.status, "finalisee");
    }
    else
    {
        printf("Choix invalide !! \n");
        return;
    }

    Taskes[count_task] = tache_1;
    count_task++;
}
void plusieursTache()
{
    int flag = 1;

    while (flag == 1)
    {
        printf("Taper 1 pour continuer et 0 pour quitter : ");
        scanf("%d", &flag);

        if (flag == 1)
        {
            ajouterTache();
        }
    }
}
void Help_afiche(int index)
{
      printf("%d     \t%s        \t%s        \t %02d-%02d-%04d         \t%s       \n",
               Taskes[index].id, Taskes[index].titre, Taskes[index].description, Taskes[index].deadline.jour,
               Taskes[index].deadline.mois, Taskes[index].deadline.annee, Taskes[index].status);

}

void afficherTache()
{
    for (int i = 0; i < count_task; i++)
    {
        printf("==================================================================================================== \n");
        Help_afiche(i);
    }
}


struct tache temp;

void Tri_par_order()
{
    for (int i = 0; i < count_task -1; i++)
    {
        for (int j = i + 1; j < count_task; j++)
        {
            if (strcmp(Taskes[i].titre, Taskes[j].titre) > 0)
            {
                temp = Taskes[i];
                Taskes[i] = Taskes[j];
                Taskes[j] = temp;
            }
        }
    }
}

void Tri_par_deadline()
{
  
    for (int i = 0; i < count_task - 1; i++)
    {
        for (int j = i + 1; j < count_task; j++)
        {
            if (Taskes[i].deadline.annee > Taskes[j].deadline.annee ||
                (Taskes[i].deadline.annee == Taskes[j].deadline.annee &&
                 (Taskes[i].deadline.mois > Taskes[j].deadline.mois ||
                  (Taskes[i].deadline.mois == Taskes[j].deadline.mois &&
                   Taskes[i].deadline.jour > Taskes[j].deadline.jour))))
            {
                temp = Taskes[i];
                Taskes[i] = Taskes[j];
                Taskes[j] = temp;
            }
        }
    }
}


int recherche_id()
{
    int id_search;
    printf("Entrez votre ID : ");
    scanf("%d", &id_search);

    for (int i = 0; i < count_task; i++)
    {
        if (id_search == Taskes[i].id)
        {
            afficherTache(Taskes[i]);
            return i;
        }
    }

    // Si la tache existe pas
    printf("Tache avec l'ID %d non trouve.\n", id_search);
    return -1;
}

void rechecher_titre()
{
    char titre_search[50];
    printf("Enter votre titre :");
    scanf("%s", &titre_search);
    for (int i = 0; i < count_task; i++)
    {
        if (strcmp(titre_search, Taskes[i].titre) == 0)
        {
            afficherTache(Taskes[i]);
    
        }
    }
    
}
void modifierTache()
{
    int choix;
    int index = recherche_id();

    printf(" choisi de modifier qoui :");
    printf("==================================================================================================== \n");
    printf("[1]-Modifier la description    \t [2]- Modifier le statut  \t [3]-Modifier le deadline");
    printf("'==================================================================================================== \n");
    printf("Taper votre choix");
    scanf("%d", &choix);

    if (choix == 1)
    {
        printf("enter la nouvelle description :");
        scanf("%s", &Taskes[index].description);
    }
    else if (choix == 2)

    {
        int choix_status;
        printf("enter le nouvelle statuts :");
        printf("Statut : \n");
        printf("=========================================================================\n");
        printf("[1] :realiser  \t [2] :en cours de ralisation   \t [3]: finalisee");
        printf("\n=========================================================================== \n");
        printf("enter votre choix :");
        scanf("%d", &choix_status);
        if (choix_status == 1)
        {
            strcpy(Taskes[index].status, "a realiser");
        }
        else if (choix_status == 2)
        {
            strcpy(Taskes[index].status, "en cours de realisation");
        }
        else if (choix_status == 3)
        {
            strcpy(Taskes[index].status, "finalisee");
        }
        else
        {
            printf("choix invalid !! \n");
        }
    }
    else
    {
        printf("enter le nouveaux  deadline :");
        scanf("%02d-%02d-%04d", &Taskes[index].deadline.jour, &Taskes[index].deadline.mois, &Taskes[index].deadline.annee);
    }
}
void supprimerTache()
{
    int index = recherche_id();
    for (int i = 0; i < count_task; i++)

    {
        Taskes[index] = Taskes[index + 1];
    }
    count_task--;
}  


void  RechercherTache()
{
    int choix;
    printf("choiser comment vous avez rechercher votre Tacher \n");
    printf("================================================================================= \n");
    printf("[1]- Rechercher la tache par son ID  \t   [2]-Rechercher la tache par son Titre");
    printf("================================================================================ \n");
    scanf("%d", &choix);
    if (choix == 1)
    {
        if (recherche_id() == -1){
             printf("N\'est pas trovee");
        }

           
            
        int  index = recherche_id ();
        return Taskes[index];

    }
    else if (choix == 2)
    {
        rechecher_titre();
    }
    else
    {
        printf("choix invalid \n");
    }
}

// statistique
void toatal_Taches()
{
    printf("\nTotal est :%d\n", count_task);
}
void complete_incompete_task()
{
    int complete_task = 0;
    for (int i = 0; i < count_task; i++)
    {
        if (strcmp(Taskes[i].status, "finalisee") == 0)
        {
            complete_task++;
        }
    }
    printf("\nnombre Task complete est : %d \n", complete_task);
    printf("\nnombre Task incomplete est : %d \n", count_task - complete_task);
}
void statistiqueTache()
{
    int choix;
    printf(" --------------------Statistique ------------------------------\n");
    printf("====================================================");
    printf("\n[1] - aficher le nombre total des  taches    \t  \n[2] -aficher le nombre de tache  et incomplete \t  \n");
    printf("===================================================");
    printf("taper votre choix [1-2] :");
    scanf("%d", &choix);
    if (choix == 1)
    {
        toatal_Taches();
    }
    else if (choix == 2)
    {
        complete_incompete_task();
    }
}


int main()
{
    int choix = 0;
    while (choix != 8)
    {
        printf("===============================================================\n");
        printf("Menu d'applications \n");
        printf("=============================================================== \n");
        printf("[1]- Ajouter une nouvelle tache \n");
        printf("[2]- Ajouter plusieurs nouvelles taches \n");
        printf("[3]- Afficher la liste de toutes les taches \n");
        printf("[4]- Modifier une tache \n");
        printf("[5]- Supprimer une tache \n");
        printf("[6]- Rechercher une tache \n");
        printf("[7]- Afficher les Statistiques \n");
        printf("[8]- Exit \n");
        printf("=============================================================== \n");
        printf("Choisissez une option (1-8) : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouterTache();
            break;
        case 2:
            plusieursTache();
            break;
        case 3:
            afficherTache();
            int Tri_choix;
            printf("Choisissez comment vous voulez trier vos taches :\n");
            printf("[1] - Trier vos taches par ordre alphabétique \n[2] - Trier vos taches par deadline\n --> ");
            scanf("%d", &Tri_choix);

            if (Tri_choix == 1)
            {
                Tri_par_order();
                afficherTache();
            }
            else if (Tri_choix == 2)
            {
                Tri_par_deadline();
                afficherTache();
            }
            else
            {
                printf("Choix invalide ");
            }
            break;
        case 4:
            modifierTache();
            break;
        case 5:
            supprimerTache();
            break;
        case 6:
            RechercherTache();
            break;
        case 7:
            statistiqueTache();
            break;

        case 8:
            printf("Merci d'utiliser l'application de gestion de taches. Au revoir !\n");
            break;
        default:
            printf("Option invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}
