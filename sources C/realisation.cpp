#include"modele.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"real.cpp"







int Node_compare(Node n1,Node n2){
return strcmp(n1.Item,n2.Item);
}
int contient(Hypergraph h , Node n){
	if(h.n==0)return -1;
	for(int i=0;i<h.n;i++){
		if (Node_compare(n,h.Nodes[i])==0) return i;
	}
	return -1;
}


void ajout(Hypergraph *h, Node n){
	h->n++;
//	printf("wuttutu");
	printf("%d",h->n);
	h->Nodes=(Node*)realloc(h->Nodes,h->n*sizeof(Node));
//	printf("wutatata");
	h->Nodes[h->n-1]=n;
//	printf("wuttitiitit");
	h->Nodes[h->n-1].support=1;
//	printf("wutaa");
}

void tri (char** tab,int n){
	for (int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			printf("%s\n%s\n",tab[i],tab[j]);
			if(strcmp(tab[i],tab[j])>0){
				echange_str(&tab[i],&tab[j]);
				printf("%s\n%s\n",tab[i],tab[j]);
			}
			
		}
	}
	
	
	
}

int Edge_compare(Edge e1,Edge e2){
	if (e1.taille!=e2.taille)return -1;
	for (int i=0 ;i<e1.taille;i++){
		if(strcmp(e1.Items[i],e2.Items[i])!=0) return -1;
		
	}
	return 1;
}
int contient_e(Hypergraph h,Edge e){
	if(h.m==0) return -1;
	
	
	for (int i=0 ;i<h.m;i++){
		if(Edge_compare(h.Edges[i],e)==1) return i;
	}
	
	return -1;
	
	
	
	
	
	
}












void echange_str(char** str1,char** str2){
	char* temp1=(char*)malloc(strlen(*str1)*sizeof(char)+sizeof(char));
	char* temp2=(char*)malloc(strlen(*str2)*sizeof(char)+sizeof(char));
	
	printf("%s\n%s\n",*str1,*str2);
	
	strcpy(temp1,*str1);
	strcpy(temp2,*str2);
	printf("tout va bien");
	*str1=(char*)malloc(strlen(temp2)*sizeof(char)+sizeof(char));
	*str2=(char*)malloc(strlen(temp1)*sizeof(char)+sizeof(char));
	
	strcpy(*str1,temp2);
	strcpy(*str2,temp1);
	printf("%s\n%s\n",*str1,*str2);
	free(temp1);
	free(temp2);
	
}
void ajout_e(Hypergraph* h,Edge e){
	int m=h->m+1;
	h->Edges=(Edge*)realloc(h->Edges,sizeof(Edge)*m);
	h->Edges[m-1]=e;
	h->m=m;	
}


void Construct_hypergraph(Hypergraph *H,char * dataset_path){
	FILE* f=fopen(dataset_path,"rt");
	printf("fichier ouvert");
	Edge e;
	e.support=1;
	e.taille=0;
	
	Node n;
	int e_iterator=0;
	int index_node;
	//char[200] edgee;
	char* truc=(char*)malloc(200*sizeof(char));
	char* item=(char*)malloc(100*sizeof(char));
	
	while(fgets(truc,200,f)){
	printf("fichier lu");	
	int iterator=0;		
	e.Items=NULL;
	do{int i=-1;
	int it=0;
		iterator++;
		e_iterator++;
		if(iterator<=1){
		
		item=strtok(truc," ");}
		while(item[it]!='\0'){
			it++;
			if(item[it]=='\n') item[it]='\0';
		}
//		}printf("omg");
		printf("alloc ok");
		e.Items=(char**)realloc(e.Items,iterator*sizeof(char*));
//		printf("allocation reussie");printf("alloc ok");
		printf("alloc ok");
        e.Items[iterator-1]=(char*)malloc(strlen(item)*sizeof(char)+sizeof(char));
        printf("alloc ok");
		strcpy(e.Items[iterator-1],item);
		printf("copy ok");
//		printf("allocation  vraiment reussie");
		n.Item=(char*)malloc(strlen(item)*sizeof(char)+sizeof(char));
		strcpy(n.Item,item);
		i=contient(*H,n);
//		printf("allocation  vraiment vraiment reussie");
		if(i==-1){
//			printf("normalement on est ici");
			ajout(H,n);
//			printf("ajout reussi");
		}else{
			H->Nodes[i].support=H->Nodes[i].support+1;
		}
//		printf("ajout effectue");
			
		
		
		
		
		
	}while(item=strtok(NULL," "));
//printf("%d\n",iterator);
tri(e.Items,iterator);
e.taille=iterator;
//printf("mourra l 4");
int m=contient_e(*H,e);
//printf("voici le m\t %d\n",m);
Edge* notfree=(Edge*)malloc(sizeof(Edge));
notfree->support=e.support;
notfree->taille=e.taille;
notfree->Items=(char**)malloc(iterator*sizeof(char*));
for(int iterable=0;iterable<e.taille;iterable++)
{notfree->Items[iterable]=(char*)malloc(strlen(e.Items[iterable])*sizeof(char)+sizeof(char));
strcpy(notfree->Items[iterable],e.Items[iterable]);
}

if(m==-1) ajout_e(H,*notfree);
else{
	H->Edges[m].support++;
}
for(int i=0;i<e.taille;i++)
free(e.Items[i]);
free(e.Items);
e.taille=0;
	//e_iterator=0;
}
fclose(f);






}



int edge_contain_v(Edge e,Node n){
	for (int i=0;i<e.taille;i++){
		if (strcmp(n.Item,e.Items[i])==0) return 1;
	}
	return 0;
}
void Calculate (Matrices* M,Hypergraph H){
	M->Incidence=(double**)malloc(H.n*sizeof(double*));
	for (int i=0;i<H.n;i++){
		M->Incidence[i]=(double*)malloc(H.m*sizeof(double));
	}
for(int i=0;i<H.n;i++){
	for (int j=0;j<H.m;j++){
		if(edge_contain_v(H.Edges[j],H.Nodes[i]))
		M->Incidence[i][j]=1;
		else M->Incidence[i][j]=0;
	}
}

M->W=(double**)malloc(H.m*sizeof(double*));
for(int i=0;i<H.m;i++)
M->W[i]=(double*)malloc(H.m*sizeof(double));
int lignes=0;
for(int i=0;i<H.m;i++)lignes+=H.Edges[i].support;
for(int i=0;i<H.m;i++){
	for(int j=0;j<H.m;j++){
		if(i==j)M->W[i][j]=((double)(H.Edges[i].support))/(double)lignes;
		else M->W[i][j]=0;
	}
}









M->De=(double**)malloc(H.m*sizeof(double*));
for(int i=0;i<H.m;i++)
M->De[i]=(double*)malloc(H.m*sizeof(double));

double **De_1=(double**)malloc(H.m*sizeof(double*));
for(int i=0;i<H.m;i++)
De_1[i]=(double*)malloc(H.m*sizeof(double));








//int lignes=0;
//for(int i=0;i<H.m;i++)lignes+=H.Edges[i].support;
for(int i=0;i<H.m;i++){
	for(int j=0;j<H.m;j++){
		if(i==j)M->De[i][j]=(double)(H.Edges[i].taille);
		else M->De[i][j]=0;
	}
}



M->Dv=(double**)malloc(H.n*sizeof(double*));
for(int i=0;i<H.n;i++)M->Dv[i]=(double*)malloc(H.n*sizeof(double));


M->LaPlacien=(double**)malloc(H.n*sizeof(double*));
for(int i=0;i<H.n;i++) M->LaPlacien[i]=(double*)malloc(H.n*sizeof(double));



double dvv=0;
for(int i=0;i<H.n;i++){
	for(int j=0;j<H.m;j++){
	if(edge_contain_v(H.Edges[j],H.Nodes[i]))
	dvv+=H.Edges[j].support;
	
	}
	M->Dv[i][i]=dvv/(double)lignes;
	dvv=0;
}

for(int i=0;i<H.n;i++){
	for(int j=0;j<H.n;j++){
	if(i!=j)M->Dv[i][j]=0;
	}}



//inverse(M->De,H.m,De_1);
for(int i=0;i<H.m;i++){
	for(int j=0;j<H.m;j++){
		if(i==j)De_1[i][j]=((double)1)/((double)M->De[i][j]);
		else De_1[i][j]=0;
	}
}

//printf("jusque la ok");
//getchar();




double**	T_Incidence=(double**)malloc(H.m*sizeof(double*));
	for (int i=0;i<H.m;i++){
		T_Incidence[i]=(double*)malloc(H.n*sizeof(double));
	}
//transposer(M->Incidence,H.n);
//copier(M->Incidence,H.n,H.n,T_incidence);
//transposer(M->Incidence,H.n);
transpose(M->Incidence,H.n,H.m,T_Incidence);

double **result_1=(double**)malloc(H.n*sizeof(double*));
	for (int i=0;i<H.n;i++){
		result_1[i]=(double*)malloc(H.m*sizeof(double));
	}

produit(M->Incidence,M->W,H.n,H.m,H.m,result_1);

double **result_2=(double**)malloc(H.m*sizeof(double*));
	for (int i=0;i<H.m;i++){
		result_2[i]=(double*)malloc(H.n*sizeof(double));
	}
produit(De_1,T_Incidence,H.m,H.m,H.n,result_2);
double **result_3=(double**)malloc(H.n*sizeof(double*));
	for (int i=0;i<H.n;i++){
		result_3[i]=(double*)malloc(H.n*sizeof(double));
	}


produit(result_1,result_2,H.n,H.m,H.n,result_3);

for(int i=0;i<H.n;i++){
	for(int j=0;j<H.n;j++){
		M->LaPlacien[i][j]=M->Dv[i][j]-result_3[i][j];
	}
}

double ** resultat_=(double**)malloc(H.n*sizeof(double*));
for(int i=0;i<H.n;i++)
resultat_[i]=(double*)malloc(H.n*sizeof(double));
for(int i=0;i<H.n;i++)
{for(int j=0;j<H.n;j++)
resultat_[i][j]=M->LaPlacien[i][j]-(double)1/(double)H.n;
}

double ** resultat_inv=(double**)malloc(H.n*sizeof(double*));
for(int i=0;i<H.n;i++)
resultat_inv[i]=(double*)malloc(H.n*sizeof(double));



//printf("jusque la ok");
//getchar();
inverse(resultat_,H.n,resultat_inv);

//printf("jusque la ok");
//getchar();
M->LaPlacien_plus=(double**)malloc(H.n*sizeof(double*));
for(int i=0;i<H.n;i++) M->LaPlacien_plus[i]=(double*)malloc(H.n*sizeof(double));

for(int i=0;i<H.n;i++)
{for(int j=0;j<H.n;j++)
M->LaPlacien_plus[i][j]=resultat_inv[i][j]+((double)1)/((double)H.n);
}
M->dist=(double**)malloc(H.n*sizeof(double*));
for(int i=0;i<H.n;i++) M->dist[i]=(double*)malloc(H.n*sizeof(double));

for(int i=0;i<H.n;i++){
	for(int j=0;j<H.n;j++)
	M->dist[i][j]=M->LaPlacien_plus[i][i]+M->LaPlacien_plus[j][j]-2*M->LaPlacien_plus[i][j];
}

double trace=0;


for(int i=0;i<H.n;i++){
//	for(int j=0;j<H.n;j++){
		
		trace+=M->Dv[i][i];
//	}
}


for(int i=0;i<H.n;i++){
	for(int j=0;j<H.n;j++)
	M->dist[i][j]=M->dist[i][j]*trace;
}


double max=0;
for(int i=0;i<H.n;i++){
	for(int j=0;j<H.n;j++){
	
	if(max < M->dist[i][j]) max=M->dist[i][j];
}}
M->Sct=(double**)malloc(H.n*sizeof(double*));
for(int i=0;i<H.n;i++) M->Sct[i]=(double*)malloc(H.n*sizeof(double));

for(int i=0;i<H.n;i++){
	for(int j=0;j<H.n;j++)
	M->Sct[i][j]=((double)1) - M->dist[i][j]/max;
}

Subedge* su;
construct_subedges(H,*M,su,0.6);




}


int contain_int(int * tab,int n, int element){
	if(n==0) return 0;
for(int i=0;i<n;i++)if(tab[i]==element) return 1;
return 0;
}
void construire_mat(int ** mat,int n){
		
		for (int i=0;i<n;i++){
		int x=1;
		for (int j=0;j<(int)pow(2,n);j++){
		if	((j%((int)(pow(2,n))/(int)(pow(2,i+1))))==0) x=(x+1)%2;
			mat[j][i]=x;
			
			
		}
	}
	
}



void construct_subedges(Hypergraph H, Matrices Ma,Subedge* Sub,double threshold){
	//printf("debug1");
	int important_edges=0;
	

	
	for(int i=0;i<H.n-1;i++){
		for(int j=i+1;j<H.n;j++){
		if(Ma.Sct[i][j]>threshold)
		important_edges++;	
			printf("ok");
		
		
		
		}
	}
	printf("important_edges : %d",important_edges);
	
	
	
	Sub=(Subedge*)malloc(important_edges*sizeof(Subedge));
	int compteur=0;
	int taille=2;
	
	
	printf("debug1");
	for(int i=0;i<H.n-1;i++){
		for(int j=i+1;j<H.n;j++){
		if(Ma.Sct[i][j]>threshold){
		Sub[compteur].Sub_edges=(int*)malloc(taille*sizeof(int));
		Sub[compteur].Sub_edges[0]=i;
		Sub[compteur].Sub_edges[1]=j;
		Sub[compteur++].Sub_Sct=Ma.Sct[i][j];		
		}
	}}
	
	printf("debug1");
	/*
	taille=3;
	int important_edges_k_sup_2=0;
	
	
	while(taille<important_edges){
		
		for(int i=)
		
		
		
		
		
		
		
		
		
	}*/
	
	
	for(int i=0;i<important_edges;i++){
		printf("\n le edge %s %s  a comme sct %lf \n",H.Nodes[Sub[i].Sub_edges[0]].Item,H.Nodes[Sub[i].Sub_edges[1]].Item,Sub[i].Sub_Sct);
	}
	
	
	
	int* tableau=NULL;
	int compteur2=0;
	for(int i=0;i<important_edges;i++){
		if((contain_int(tableau,compteur2,Sub[i].Sub_edges[0]))==0){
			compteur2++;
			tableau=(int*)realloc(tableau,compteur2*sizeof(int));
			tableau[compteur2-1]=Sub[i].Sub_edges[0];
		}
		if((contain_int(tableau,compteur2,Sub[i].Sub_edges[1]))==0){
		compteur2++;
			tableau=(int*)realloc(tableau,compteur2*sizeof(int));
			tableau[compteur2-1]=Sub[i].Sub_edges[1];
		
		
		}
	}
/*	for(int i=0;i<compteur2;i++){
		printf("\n%d\n",tableau[i]);
	}
	int tt=3;
	while(tt<compteur2){
		int* indices=(int *)malloc(tt*sizeof(tt));
		for(int i=0;i<tt;i++) indices[i]=i;
		printf("\nle edge");
		for(int i=0;i<tt;i++){
			printf(" %s \t",H.Nodes[tableau[i]].Item);
		}
		printf(" a pour sct");
		double x=0;
		
		
		
		
		
	}
	
	
*/printf("ici svp 1");
int ** matrice_choix=(int **)malloc(((int)pow(2,compteur2))*sizeof(int*));
for(int i=0;i<((int)pow(2,compteur2));i++)
matrice_choix[i]=(int*)malloc(compteur2*sizeof(int));
printf("ici svp 1");
construire_mat(matrice_choix,compteur2);
printf("ici svp 1");
int k=3;
int somme;
int somme2;
int compteurn;
double x;
int moy=0;
int * indexnodes=(int*)malloc(2*sizeof(int));
int compteurnodes;
//printf("ici svp 2");
while(k<compteur2){
	if(k==4) break;
int ** matrice_choix_temp=(int **)malloc(((int)pow(2,k))*sizeof(int*));
for(int i=0;i<((int)pow(2,k));i++)
matrice_choix_temp[i]=(int*)malloc(k*sizeof(int));
construire_mat(matrice_choix_temp,k);
//printf("ici svp 2");
int* indexes=(int*)malloc(k*sizeof(int));
//printf("ici svp 2");
somme=0;
compteurn=0;
somme2=0;
compteurnodes=0;
//printf("ici svp 2");
for(int i=0;i<(int)(pow(2,compteur2));i++)
	{for(int j=0;j<compteur2;j++){
	somme+=matrice_choix[i][j];
	
	}
//	printf("ici svp 3");
	if(somme==k){
		for(int j=0;j<compteur2;j++){
			if (matrice_choix[i][j]==1){
				indexes[compteurn++]=j;
			}
		}
		compteurn=0;
		
		for(int l=0;l<(int)pow(2,k);l++){
			for(int f=0;f<k;f++){
				
			if(matrice_choix_temp[l][f]==1)	somme2++;
			}
		if(somme2==2){
			for(int f=0;f<k;f++){
				if(matrice_choix_temp[l][f]==1) indexnodes[compteurnodes++]=f;
			}
			
			
		}somme2=0;
		compteurnodes=0;
		x+=Ma.Sct[tableau[indexes[indexnodes[0]]]][tableau[indexes[indexnodes[1]]]];
//		printf("ici svp 4");
		moy++;
		
		
		}
		printf("le edge : \t");
		for(int h=0;h<k;h++){
			printf("%s\t",H.Nodes[indexes[h]].Item);
		}
		printf("a pour Sct %lf \n",x/moy);
		x=0;moy=0;
	}somme=0;
	}k++;printf("ici svp 5");
	
}

	
}

















