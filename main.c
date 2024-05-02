#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct date {
     int j;
     int m;
     int a;
 }date;

 typedef struct info_p {
    char nom[30];
    char CIN[10];
    date D ;
    char pays[30];
 }info_p;

typedef struct produit{
    char designation[30];
    float prix;
  }produit;

typedef struct ligne_de_commande {
     produit prod;
     int qnt;

   }ligne_c;

typedef struct commande {
    int num;
    date D;
    int h;
    info_p client;
    int nl;
    ligne_c ligne[20];
    int mt;
}commande;

typedef struct caisse {
    int num;
    info_p respo;
    int nc;
    commande com[20];
}caisse;

 typedef struct str_market {
      caisse  caisse[10];
      int cpt;
 }str_market;

 date saisir_date(){
  date a;
  printf("saisir la date : (j/m/a) ");
  scanf("%d %d %d", &a.j, &a.m, &a.a);

  return a;

 }

 info_p saisir_prso(){
   info_p p;

   printf("saisir le nom : \n");
   scanf("%s",p.nom);
   printf("saisir le CIN : \n");
   scanf("%s",p.CIN);
   printf("saisir la date de naissace:");
   p.D= saisir_date();
   printf("saisir le pays d'origne ");
   scanf("%s",p.pays);

   return p;
 }

 produit saisir_produit(){
    produit p;
    printf("saisir une designation ;");
    scanf("%s",p.designation);
    printf("saisir le prix de produit :");
    scanf("%f",&p.prix);

    return p;
 }
ligne_c saisir_ligne(){
  ligne_c l;
  printf("saisir le produit :");
  l.prod= saisir_produit();
  printf("saisir la quantite de la commande :");
  scanf("%d",&l.qnt);

  return l;
}

commande saisir_commande(){
   commande a;

   printf(" saisir le numero de la commande :");
   scanf("%d",&a.num);

   printf(" saisir la date :");
   a.D= saisir_date();
   printf(" saisir l'heure de la commande :");
   scanf("%d",&a.h);
   printf(" saisir les information de le clients  :");
   a.client= saisir_prso();
   printf(" saisir le nombre de ligne de commandes  :");
   scanf("%d",&a.nl);
   printf(" saisir les lignes de commades  :");
   for( int i=0; i<a.nl; i++){
    a.ligne[i]=saisir_ligne();
   }

   printf(" saisir le montant de la commande :");
   scanf("%f",&a.mt);

   return a;

}

caisse saisir_caisse(){
 caisse c;

 printf(" saisir le numero de la commande :");
   scanf("%d",&c.num);
   printf(" saisir les information de le responsable :");
   c.respo= saisir_prso();
   printf(" saisir le nombres  de  commande :");
   scanf("%d",&c.nc);

   for(int i=0; i<c.nc; i++){
    c.com[i]= saisir_commande();
   }

   return c;
}

 // n : le nombre de commande a saisir dans com[]
void saisir_str( str_market* s , int n){
  int i;
    if( s->cpt+n< 10 ){

        for(i=s->cpt; i< s->cpt+n; i++){
            s->caisse[i]= saisir_caisse();
        }

        s->cpt+=n;
    }else  printf( " l'espace est insuffisants ");

}


// AFFICHAGE :
void affiche_date (date d){
    printf("------------------------------------------------------- \n");
printf("la date est :( %d / %d / %d) ",d.j, d.m, d.a);
}

void affiche_peso(info_p p){
    printf(" le nom est : %s  ",p.nom);
     printf("le CIN : %s  ",p.CIN);
     printf(" la date de naissace est : ");
     affiche_date(p.D);
      printf(" le pays d'origine: %s ", p.pays);
}

void affiche_produit(produit p){
  printf(" le designation est : %s", p.designation);
   printf(" le prix se produit est : %f ",&p.prix);
}

void affiche_ligne(ligne_c l){
    printf(" les information de clients : ");
    affiche_produit(l.prod);
     printf("la quantite commande est : %d  ", l.qnt);

    }

void affiche_commande(commande c){
  printf(" le numero de la commande est : %d  \n ", c.num);
   printf(" la date est :  ");
   affiche_date(c.D);
   printf("l'heure de la commandes est : %d \n", c.h);
   printf(" les information de client: \n");
   affiche_peso(c.client);
    printf(" le nombre de ligne de commandes est : %d \n", c.nl);

     printf("les lignes de commandes : \n");

     for(int i=0; i< c.nl; i++){
        printf("le ligne de commande %d: ", i+1);
         affiche_ligne(c.ligne[i]);
         printf(" \n");
     }
  printf(" le montant de la commande est: %d ", c.mt);

}

 void affiche_caisse(caisse c){
     printf(" le numero de la caisse est : %d \n", c.num);
     printf(" les information sue le responsable : \n");
     affiche_peso(c.respo);
     printf("le nombre de commande est : %d",c.nc);
     printf("la liste des commandes est : \n");

     for(int i=0; i< c.nc; i++){
        affiche_commande(c.com[i]);
         printf(" \n");
     }


 }

void affiche_str(str_market s){


    // Q5:
    int recherche(str_market s, int n){
       int pos=-1;
       for(int i=0; i<s.cpt; i++){
        if(s.caisse[i].num == n){
            pos= i;
        }
       }
       return pos;
    }

    // n: le numero de la caisse
    // x: le nombre de commande a modifier

    void modifier(str_market *s, int n ,int x){
      int i;
      i= recherche(*s, n);
         if(i!= -1){
            for(int j=0;j<x;j++){
              s->caisse[i].com[j]= saisir_commande();
            }
            s->caisse[i].nc=n;
          }else
               printf(" la caisse n'existe pas ");
    }



// Q6:
void affiche_commande_cin(caisse l, char c[]){
          int i;
          for(i=0; i< l.nc ;i++){
            if(strcmp(l.com[i].client.CIN,c)== 0){
                affiche_commande(l.com[i]);
                printf("\n");
            }
          }
      }

     void affiche_par_cin(str_market s, char c[]){
         printf("l'historique des commandes de clients de cin :(%d)est : \n" );
        for(int i=0;i<s.cpt;i++){
            affiche_commande_cin(s.caisse[i],c);
             printf("\n");
        }
     }
    int i ;
    for(i=0; i<s.cpt; i++){
        affiche_caisse(s.caisse[i]);

    }
}

// Q7:

float chiffre_affaire_produit( str_market s, char produit[]) {
    float chiffre_affaire = 0;
    for (int i = 0; i < s.cpt; i++) {
        for (int j = 0; j < s.caisse[i].nc; j++) {
            for (int k = 0; k < s.caisse[i].com[j].nl; k++) {
                if (strcmp(s.caisse[i].com[j].ligne[k].prod.designation, produit) == 0) {
                    chiffre_affaire += s.caisse[i].com[j].ligne[k].prod.prix *
                                       s.caisse[i].com[j].ligne[k].qnt;
                }
            }
        }
    }
    return chiffre_affaire;
}

// Q8:
void supprimer_caisse_min_ventes(str_market *supermarche) {
    int index_caisse_min_ventes = -1;
    float min_ventes = FLT_MAX;
    for (int i = 0; i < supermarche->nombre_caisse; i++) {
        float total_ventes = 0;
        for (int j = 0; j < supermarche->caisses[i].nombre_commande; j++) {
            total_ventes += supermarche->caisses[i].liste_commande[j].montant_commande;
        }
        if (total_ventes < min_ventes) {
            min_ventes = total_ventes;
            index_caisse_min_ventes = i;
        }
    }

    if (index_caisse_min_ventes != -1) {
        for (int i = index_caisse_min_ventes; i < supermarche->nombre_caisse - 1; i++) {
            supermarche->caisses[i] = supermarche->caisses[i + 1];
        }
        supermarche->nombre_caisse--;
        printf("La caisse avec le minimum de ventes a �t� supprim�e avec succ�s.\n");
    } else {
        printf("Aucune caisse trouv�e pour la suppression.\n");
    }
}




int main()
{

    return 0;
}
