//
//  main.c
//  Graphe
//
//  Created by Elham Amin Mansour on 23.04.18.
//  Copyright © 2018 Elham Amin Mansour. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (a<=b?a:b)
FILE *fichier ;

typedef struct aeroport{
    char nom[200];
    char cap[20];
    char pays[20];
    
}aeroport;


aeroport list[200];

int volMat[200][200];
int volList[200][200];



void lire(){
    fichier = fopen("/Users/elhamaminmansour/Desktop/unige/semestre2/structuredeDonnees/tp4/Graphe/Graphe/aeroports_TP4.txt","r");
    char ligne[50];
    fgets(ligne,200,fichier);
    int i = 0;
    while(fgets(ligne,200,fichier) != NULL){
 
        int j1 = 0;
        int j = 0;
        
       
        while(ligne[j] != ' '){
            list[i].nom[j1] = ligne[j];
            j1++;
            j++;
        }
        list[i].nom [j1] = '\0';
       
     
        int j2 = 0;
        j++;
        
        while(ligne[j] != ' '){
            list[i].cap[j2] = ligne[j];
            j2++;
            j++;
        }
        list[i].cap[j2] = '\0';
        j++;
        int j3 = 0;
        
        while(ligne[j] != '\r'){
            list[i].pays[j3] = ligne[j];
            j3++;
            j++;
        }
        list[i].pays[j3] = '\0';
        
        
        i++;
    }
    
    for (i = 0;i < 8;i++)
       printf("%s %s %s \n",list[i].pays, list[i].cap,list[i].nom);
    
    printf("%s",list[7].pays);
     printf("%s",list[7].cap);
     printf("%s",list[7].nom);
}

void remplirVolMat(){
    for(int i = 0; i < 8;i++)
        for(int j = 0; j < 8;j++)
            volMat[i][j] = 0;
    volMat[0][1] = 1;  volMat[0][3] = 1;   volMat[0][4] = 1;  volMat[0][6] = 1;
    volMat[1][4] = 1;
    volMat[2][4] = 1;   volMat[2][7] = 1;
    volMat[3][0] = 1;  volMat[3][4] = 1;   volMat[3][5] = 1;
    volMat[4][0] = 1;  volMat[4][1] = 1;   volMat[4][3] = 1;   volMat[4][7] = 1;
    volMat[5][0] = 1;  volMat[5][4] = 1;   volMat[5][3] = 1;
    volMat[6][7] = 1;
    volMat[7][0] = 1;  volMat[7][3] = 1;   volMat[7][4] = 1;
    
    

}

void remplirVolList(){
    volList[0][0] = 1; volList[0][1] = 3; volList[0][2] = 4; volList[0][3] =  6;
    volList[1][0] = 4;
    volList[2][0] = 4; volList[2][1] = 7;
    volList[3][0] = 0;  volList[3][1] = 4;   volList[3][2] = 5;
    volList[4][1] = 1;   volList[4][2] = 3; volList[4][3] = 4;   volList[4][4] = 7;
    volList[5][0] = 0;  volList[5][1] = 4;   volList[5][2] = 3;
    volList[6][0] = 7;
    volList[7][0] = 0;  volList[7][1] = 3;   volList[7][2] = 4;
    
}


int nombreVol(int n1, int chemin,int n2){
    int res[200][200];
    
    for(int i = 0;i < 8; i++)
        for(int j = 0; j < 8 ; j++)
            res[i][j] = volMat[i][j];
    
    
    for(int p = 2; p <= chemin;p++)
        for(int i = 0;i < 8; i++)
            for(int j = 0; j < 8 ; j++)
                for(int k = 0; k < 8; k++)
                    res[i][j] = res[i][j] + volMat[i][k] * res[k][j];
    
    return res[n1][n2];
                
    
}

int inS[20],low[20],num[20],count[20],marque[20];
int nomConnexe,lev = 0;
void dfs(int u){
    marque[u] = 1;
    inS[u] = 1;
    num[u] = lev;
    lev++;
    for (int v = 0 ; v < 8;v++){
        if(volMat[u][v] == 1 && marque[v] == 0)
                dfs(v);
        if(inS[v] == 1 && volMat[u][v] == 1)
            low[u] = min(low[u],low[v]);
        
    }
    if(low[u] == num[u])
        inS[u] = 0;
}

int appDfs(){
    for(int u = 0; u < 8; u++)
        if(marque[u] == 0)
            dfs(u);
            
     

    for(int i = 0; i < 8; i++)
            count[low[i]] = 1;
    
    for(int i = 0; i < 8; i++){
        if(count[i] == 1)
            nomConnexe++;
    }
    return nomConnexe;
    
}

int main(int argc, const char * argv[]) {
   
    lire();
    remplirVolMat();
    remplirVolList();
    printf("%s %d","nombre de chemin avec cette longueur: ",nombreVol(3,2,0));
    printf("%s %d ","nombre de connexe: ",appDfs());

    return 0;
}
