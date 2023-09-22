#include <stdio.h>
#include <string.h>
struct tache {
     int id ;
    char titre[50];
    char description [50];
    char deadline[50];
    char status[100];
};

struct tache Global[100] ;
int count = 0;
void ajouterTache ()
{
    int choix_status;
    struct tache tache_1;
    

        printf("Ajouter une nouvelle tache \n");
        tache_1.id = count;
        // printf("un identifiant unique:");
        // scanf("%d",&tache_1.id);
        printf("un titre:");
        scanf("%s",&tache_1.titre);
        printf("une description:");
        scanf("%s",&tache_1.description);
        printf("un deadline :");
        scanf("%s",&tache_1.deadline);
        printf("un statut: \n");
        printf("[1] si a realiser \n");
        printf("[2] si en cours de realisation \n");
        printf("[3] si finalisee \n");
        printf("Taper votre choix  [1-3]:");
        scanf("%d",&choix_status);
        if (choix_status == 1){
            strcpy(tache_1.status, "a realiser"); 
        }
        else if (choix_status ==2)
        {
             strcpy(tache_1.status, "en cours de realisation"); 

        }
        else if(choix_status ==3)
        {
             strcpy(tache_1.status,"finalisee"); 
        }

       Global[count] = tache_1;
        count++;

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
                   
                }
            }

}
void Aficher_par_order()
{
    int i;
    int j;

    for(i = 0; i < count - 1; i++) {
    for (j = i + 1; j < count; j++) {
        if (strcmp(Global[i].titre, Global[j].titre) > 0) {
            struct tache swap = Global[i];
            Global[i] = Global[j];
            Global[j] = swap;
        }
    }
}

       printf("%s",Global[i].titre);
}
void AfficherTache()
    {
        int n;
        printf("Liste de toutes les taches \n");
             for (int i = 0; i < count; i++) 
                {
                    printf("ID : %d\n",Global[i].id+1);
                    printf("Titre : %s\n", Global[i].titre);
                    printf("Description : %s\n", Global[i].description);
                    printf("Deadline : %s\n", Global[i].deadline);
                    printf("Status : %s\n", Global[i].status);
                } 

        //         printf("Choisi comment vous avez lister votre tache :\n");
        //         printf("[1]- Trier les taches par ordre alphabetique \n");
        //         printf("[2]- Trier les taches par deadline \n");
        //         printf("[3]- Afficher les taches dont le deadline est dans 3 jours ou moins \n");
        //         printf("taper votre choix : ");
        //         scanf ("%d",&n);
        //       if(n ==1)
        //     {
        //         Aficher_par_order();
        //    }
            
                

}

void Modifier_une_tache(){
    int choix;
    char nvstatus[100];
    int id;
    printf (" Taper[1] pour Modifier la description \n : Taper[2] pour Modifier le statut :\n  Taper[3] pour modifie le deadline :\n");
    scanf ("%d",&choix);
    // modifier la description
    if (choix == 1)
    {
       printf("enter votre id: \n");
       scanf ("%d",&Global[count].id); 
        for(int i =0; i< count ;i++)
        {
            
            if (Global[i].id == Global[count].id)
            {
                printf(" la nouvelle  description est :");
                scanf("%s", &Global[count].description);
                strcpy(Global[i].description, Global[count].description);
            }
        }
    }
// modifier le Statut :
            
            if (choix == 2)
            {
                printf("enter votre  id  pour modifier le status: \n");
                scanf ("%d",&id); 
                for(int i=0; i< count ;i++)
                {
                    if (Global[i].id == id)
                    {
                        printf("votre id trouver par succes");
                       printf("enter votre  id  pour modifier le status: \n");
                        scanf ("%s",&nvstatus);  

                        strcpy(Global[i].status, nvstatus);
                    }
                    else 
                    {
                         printf("votre id trouver pas , entrer un nouvelle id "); 

                    }   
                }
                
            }
}
void supp ()
{
    
}
int main(){
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
        switch (choix){
            case 1:{
                ajouterTache();
                break; 
            }
            case 2:{
                nouvelleTache();
                break; 
            }   
            case 3:{
                AfficherTache();
                break; 
            }
            case 4:{
                Modifier_une_tache();
                break;
            }
        }
    }while (choix != 8);
}
