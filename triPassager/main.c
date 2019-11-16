// comment passer une fonction comme parametre a une fonction
//comment lire la fin d'un fichier
//ESSAYER DE SUPPRIMER

//  main.c
//  triPassager
//
//  Created by Elham Amin Mansour on 08.04.18.
//  Copyright © 2018 Elham Amin Mansour. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
FILE *fichier ;


typedef struct passager{
    char nom[20];
    char prenom[20];
    int age;
    int ID;
    int numSiege;
}passager;

passager list[100];

typedef struct noeud{
    passager passager;
    struct noeud  *right;
    struct noeud  *left;
}noeud;

void lire(){
     fichier = fopen("/Users/elhamaminmansour/Desktop/unige/semestre2/structuredeDonnees/tp3/triPassager/triPassager/TP3.passagers.txt","r");
    char ligne[50];
    fgets(ligne,200,fichier);
    int i = 0;
    while(i < 7){
            fgets(ligne,200,fichier);
    
            //printf("%s", ligne);

    
        
            int j1 = 0;
            int j = 0;
            char IDtemp[50];
            //for (int k = 0; k < 50; k++)
             //   IDtemp[k] = '';
            ///////////////////////////////////
            while(ligne[j] != '\t'){
                    IDtemp[j1] = ligne[j];
                j1++;
                    j++;
            }
            IDtemp[j] = '\0';
            list[i].ID = atoi(IDtemp);
            //printf("%d", list[i].ID);
            ////////////////////////////////////
            j++;
        
            int j2 = 0;
            while(ligne[j] != '\t'){
            list[i].nom[j2] = ligne[j];
            j2++;
            j++;
            }
            list[i].nom[j2] = '\0';
            //////////////////////////////
            j++;
        
            int j3 = 0;
            while(ligne[j] != '\t'){
            list[i].prenom[j3] = ligne[j];
            j3++;
            j++;
        }
            list[i].prenom[j2] = '\0';
            //////////////////////////
            j++;
            char agetemp[20];
            int j4 = 0;
            while(ligne[j] != '\t'){
                agetemp[j4] = ligne[j];
                j4++;
                j++;
            }
            agetemp[j] = '\0';
            list[i].age = atoi(agetemp);
            //////////////////////////
            j++;
            char numSiegetemp[20];
            int j5 = 0;
            while(ligne[j] != '\t'){
                numSiegetemp[j5] = ligne[j];
                j5++;
                j++;
            }
            numSiegetemp[j] = '\0';
            list[i].numSiege = atoi(numSiegetemp);
        
        
            printf("%d \n",list[i].ID);
          printf("%s %s",list[i].nom, " ");
          printf("%s %s",list[i].prenom," ");
            printf("%d %s",list[i].age, " ");
            printf("%d %s",list[i].numSiege," ");
          
          
          
        
        
            i++;
    }
}

noeud* insererSiege(int i, noeud *pere){
   
   if(pere == NULL){
       // printf("%d \n",  &pere);
        pere = malloc(sizeof(noeud));
        //printf("%d \n",  &pere);
        pere->passager = list[i];
       // printf("%d \n", &pere);
        
        pere->left = NULL;
        pere->right = NULL;
   }
  else{
        //printf("%d",pere->passager.numSiege);
    if(pere->passager.numSiege > list[i].numSiege)
        pere->left = insererSiege(i,pere->left);
    else
        pere->right = insererSiege(i,pere->right);
  } 
    return pere;
}

void parcourArbreSiege(noeud *pere){
    if(pere->left != NULL)
        parcourArbreSiege(pere->left);
    
    printf("%d %s", pere->passager.numSiege," ");
    
    if(pere->right != NULL)
        parcourArbreSiege(pere->right);
        
}


noeud* insererAge(int i, noeud *pere){
    
    if(pere == NULL){
        // printf("%d \n",  &pere);
        pere = malloc(sizeof(noeud));
        //printf("%d \n",  &pere);
        pere->passager = list[i];
        // printf("%d \n", &pere);
        
        pere->left = NULL;
        pere->right = NULL;
    }
    else{
        //printf("%d",pere->passager.numSiege);
        if(pere->passager.age > list[i].age)
            pere->left = insererAge(i,pere->left);
        else
        pere->right = insererAge(i,pere->right);
    }
    return pere;
}


void parcourArbreAge(noeud *pere){
    
    if(pere->left != NULL)
        parcourArbreAge(pere->left);
     printf("%d %s", pere->passager.age," ");
   
    
    if(pere->right != NULL)
        parcourArbreAge(pere->right);
    
}



int main(int argc, const char * argv[]) {
    lire();
    printf("%d",list[1].age);
    noeud *arbreSiege;
    
    arbreSiege = NULL;
    for(int i = 0; i < 39; i++){
        //printf("%d %s" ,list[i].numSiege," ");
        arbreSiege = insererSiege(i, arbreSiege);
        //printf("%d",arbreSiege->passager.numSiege);
    }
    parcourArbreSiege(arbreSiege);
    
    noeud *arbreAge;
    printf("\n" );
    arbreAge = NULL;
    for(int i = 0; i < 39; i++){
        //printf("%d %s \n" ,list[i].age," ");
        arbreAge = insererAge(i, arbreAge);
        //printf("%d",arbreSiege->passager.numSiege);
    }
        parcourArbreAge(arbreAge);
        

    
    return 0;
}
