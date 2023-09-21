#include <stdio.h>
#include <string.h>
struct tache {
    int id ;
    char titre[50];
    char description [50];
    char deadline[50];
    int status;
};

struct tache Global[100] ;
int count = 0;
void ajouterTache ()
{
    struct tache tache_1;
    

        printf("Ajouter une nouvelle tache \n");
        printf(" un identifiant unique:");
        scanf("%d",&tache_1.id);
        printf("un titre:");
        scanf("%s",&tache_1.titre);
        printf("\n une description:");
        scanf("%s",&tache_1.description);
        printf("un deadline :");
        scanf("%s",&tache_1.deadline);
        printf("un statut: \n");
        printf("1: si a raaliser \n    2: si en cours de realisation\n  3: si finalisee ");
        scanf("%d",&tache_1.status);
        if (tache_1.status == 1){
            printf("a raaliser \n");
        }
        else if (tache_1.status ==2)
        {
            printf("en cours de realisation \n");

        }
        else 
        {
            printf("finalisee  \n");
        }
       
        Global[count] = tache_1;
        count ++;

}
void nouvelleTache ()
{
    int flag =1 ;

            while (flag == 1)
            {
                printf("Taper 1 pour continuer et 0 pour quitter : ");
                scanf("%d", &flag);

                if (flag == 1)
                {
                    ajouterTache();
                    count++;
                }
            }

}
void AfficherTache ()
{
        printf("Liste de toutes les taches :\n");
                for (int i = 0; i < count; i++) 
                {
                    printf("Tache %d :\n", i + 1);
                    printf("ID : %d\n", Global[i].id);
                    printf("Titre : %s\n", Global[i].titre);
                    printf("Description : %s\n", Global[i].description);
                    printf("Deadline : %s\n", Global[i].deadline);
                    printf("Status : %d\n", Global[i].status);
                 } 

}

int main()
{
    int i;
    int choix;
    do {
    printf("=============================================================== \n");
    printf("Menu d'applications \n");
    printf("=============================================================== \n");
    printf("[1]- Ajouter une nouvelle tache \n");
    printf("[2]- Ajouter plusieurs nouvelles taches \n");
    printf("[3]- Afficher la liste de toutes les taches \n");
    printf("[4]- Modifier une tache \n");
    printf("[5]- Supprimer une tache \n");
    printf("[6]- Rechercher une tache \n");
    printf("[7]- Aficher les Statistiques \n");
    printf("[8]- Exit \n");
    printf("=============================================================== \n");
    printf("choisi entre [1-8] :");
    scanf("%d",&choix);
    switch (choix) {
        case 1: 
            ajouterTache();
            break; 
        case 2: 
            nouvelleTache();
            break; 
        case 3: 
            AfficherTache();
            break; 
        
       
    }

    }while (choix != 8);
    
}
