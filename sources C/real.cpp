#include"Struc.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>
double ** construire_co_facteur(double **matrice,int del_line,int del_col,int n,int m,double **co_fac){
	for(int i=0 ;i <n;i++){
		for(int j=0;j<m;j++){
		if (i<del_line && j<del_col)
		co_fac[i][j]=matrice[i][j];
		else
		if(i<del_line && j> del_col)
		co_fac[i][j-1]=matrice[i][j];
		else 
		if(i>del_line && j<del_col)
		co_fac[i-1][j]=matrice[i][j];
		else 
		if(i>del_line && j>del_col)
		co_fac[i-1][j-1]=matrice[i][j];
	}
	}
//p.empiler(p,co_fac,n-1,m-1,matrice[del_line][del_col]);
return co_fac;
}



int est_vide(Pile p){
	return p==NULL;
	
}
Pile pile_vide(){
	return NULL;
	
}
Pile empiler(Pile p , Element e){
	
	Pile q=(Pile)malloc(sizeof(Cellule));
	q->e=e;
	q->suivant=p;
	p=q;
	return p;
	
	
	
	
}
Pile depiler(Pile p){
	if(est_vide(p))printf("erreur desempilage impossible car pile vide");
	else
	{Pile q=p;
p=p->suivant;
free(q);

return p;
		
		
	}
}
Element sommet(Pile p){
	if(est_vide(p))printf("erreur somme nexiste pas car pile vide");
	else
		return p->e;
	
}



void echanger(double* a,double* b){
	double temp=*a;
	*a=*b;
	*b=temp;
	
	
}

void copier(double **mat ,int n,int m,double** copie){
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
//	printf("un element sera copie");
	copie[i][j]=mat[i][j];
}
	
	
}
void produit(double ** mat1,double ** mat2 ,int n,int m,int k,double** mat_result){
	double somme;
	for(int i=0;i<n;i++){
		
		for(int j=0;j<k;j++){
		somme=0.0;
		for(int z=0;z<m;z++){
		
		somme+=mat1[i][z]*mat2[z][j];
		}
		mat_result[i][j]=somme;
	}}
	
	
	
	
	
}
void produit_scalaire(double** mat,int n,int m,double scalaire){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
	mat[i][j]*=scalaire;
	}
}
void construire_co_matrice(double** mat,int n/*,int del_line,int del_colonne*/,double *** comatrice_uncalculed,double ** co_fac){
for(int i=0;i<n;i++){
	
	for(int j=0;j<n;j++){
	//	printf("debut");
//		getchar();
		construire_co_facteur(mat,i,j,n,n,co_fac);
	//	getchar();
	//	printf("putin");
	//	getchar();
		copier(co_fac,n-1,n-1,comatrice_uncalculed[i*n+j]);
	//	printf("une construction de co_facteur a eu lieu ainsi qu'une copie en comatrice");
		//getchar();
		
		
	}
	
	
	
}}




















void det(Pile p,Pile q,double *somme){
	while(sommet(p)->taille>2){
	while(!est_vide(p)){
		for(int i=0;i<sommet(p)->taille;i++){
			Matrice* truc=(Matrice*)malloc(sizeof(Matrice));
			truc->taille=sommet(p)->taille-1;
			truc->mat=(double**)malloc((sommet(p)->taille-1)*sizeof(double*));
			for (int k=0;k<sommet(p)->taille-1;k++)
				truc->mat[k]=(double*)malloc((sommet(p)->taille-1)*sizeof(double));
			truc->mat=construire_co_facteur(sommet(p)->mat,0,i,sommet(p)->taille,sommet(p)->taille,truc->mat);
			truc->mult=pow(-1,i+2)*sommet(p)->mult*sommet(p)->mat[0][i];
			if(truc->mult!=0)
			q=empiler(q,truc);
			
		}
		p=depiler(p);
		
		
		
	}
	//echanger(p,q);
	//Pile temp=p;
	p=q;
	//q=temp;
	
	q=pile_vide();
	}
	while(!est_vide(p)){//printf("on est la");
//	if(sommet(p)->taille==1){*somme+=sommet(p)->mult*sommet(p)->mat[0][0];
//	}
//	else
		//{
		*somme+=sommet(p)->mult*(sommet(p)->mat[0][0]*sommet(p)->mat[1][1]-sommet(p)->mat[0][1]*sommet(p)->mat[1][0]);
		//}
		p=depiler(p);
	}
	
} 




void transposer(double** mat,int n){
	for(int i=0;i<n;i++)
	for(int j=0;j<i;j++)
	echanger(&mat[i][j],&mat[j][i]);
}

void produit_vecteur(double ** mat1,double * vecteur ,int n,int m ,double * vecteur_result){


for(int i=0;i<m;i++)
vecteur_result[i]=0;

for(int i=0;i<n;i++){
	for (int j=0;j<m;j++)
	vecteur_result[i]+=mat1[i][j]*vecteur[j];
}



}

void produit_vecteur2(double ** mat1,double * vecteur ,int n,int m ,double * vecteur_result){


for(int i=0;i<m;i++)
vecteur_result[i]=0;

for(int i=0;i<m;i++){
	for (int j=0;j<n;j++)
	vecteur_result[i]+=mat1[j][i]*vecteur[j];
}



}












int inverse(double ** mat , int n , double ** inverse){
	if (n==2){
		double det_1=mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
		if (det_1==0){
			printf("matrice non inversible verifier le rang du SL");
			
return -1000;	}
	inverse[0][0]=(1/det_1)*mat[1][1];
	inverse[0][1]=-1*(1/det_1)*mat[0][1];
	inverse[1][0]=-1*(1/det_1)*mat[1][0];
	inverse[1][1]=(1/det_1)*mat[0][0];
	
	
	}
	else{
	
	Pile p=pile_vide();
	Element e=(Element)malloc(sizeof(Matrice));
	
	e->taille=n;
	e->mat=mat;
	e->mult=1;
	p=empiler(p,e);
	Pile q=pile_vide();
	double *dete=(double*)malloc(sizeof(double));
	*dete=0.0;
	det(p,q,dete);
	if (*dete==0) return -1000;

double** co_facteur=(double **)malloc((n-1)*sizeof(double*));
for(int i=0;i<n-1;i++)
co_facteur[i]=(double*)malloc((n-1)*sizeof(double));


double ***co_mat_Base=(double***)malloc(pow(n,2)*sizeof(double**));
	for(int i=0;i<pow(n,2);i++){
	
	co_mat_Base[i]=(double**)malloc((n-1)*sizeof(double*));
	for(int j=0;j<(n-1);j++)
	co_mat_Base[i][j]=(double*)malloc((n-1)*sizeof(double));
}




construire_co_matrice(mat,n,co_mat_Base,co_facteur);

	for(int i=0;i<n;i++)
	{for(int j=0;j<n;j++){
	
	
	p=NULL;q=NULL;double* det_co=(double*)malloc(sizeof(double));
	*det_co=0;
	Matrice* util=(Element)malloc(sizeof(Matrice));
	util->taille=n-1;
	util->mult=pow(-1,i+j+2);
	util->mat=co_mat_Base[i*n+j];
	p=empiler(p,util);
//	printf("wtf1");
	det(p,q,det_co);
//	printf("wtf2");
	inverse[i][j]=*det_co/(*dete);
//	printf("wtf3");
	}}
//	printf("svp expliquez vous");
	transposer(inverse,n);
}
return 1;

}

void afficher_mat(double ** mat,int n ,int m){
	for(int i=0;i<n;i++)
	{for(int j=0;j<m;j++){
		printf("%lf\t",mat[i][j]);
	}printf("\n");
	}
}

void copie_colonne(double**A,double**B,int i,int j,int n){
	for(int k=0;k<n;k++)
	B[k][j]=A[k][i];
}

void Split(double ** A , int n, int m ,double ** B , double ** R , double * CT,double *CTb,double * CTr,int * choix_base_depart,int * positions_base,int * positions_hb){
int compt1=0;
int compt2=0;



for(int i=0;i<m;i++){
	if(choix_base_depart[i]==1){
		//printf("base");
	copie_colonne(A,B,i,compt1,n);
	positions_base[compt1]=i;
	CTb[compt1++]=CT[i];
	}else {
		//printf("hors_base");
		copie_colonne(A,R,i,compt2,n);
positions_hb[compt2]=i;
CTr[compt2++]=CT[i];
	}
}


}
int est_positif(double * vecteur, int n){
	for (int i=0;i<n;i++)
	if(vecteur[i]<0) return 0;
	return 1;
}

int simplex(SL sys){
int ite=0;
printf("please\n");

afficher_mat(sys.B.mat,sys.B.n,sys.B.n);
afficher_mat(sys.R.mat,sys.R.n,sys.R.m);

printf("pleaseok\n");
for(int i=0;i<sys.B.n;i++)
printf("%lf\n",sys.b[i]);
printf("please not ok");
for(int i=0;i<sys.B.n;i++)
printf("%lf\n",sys.CTb[i]);
for(int i=0;i<sys.R.m;i++)
printf("%lf\n",sys.CTr[i]);
printf("%lf\n",sys.z[0]);

printf("please");


while(!est_positif(sys.CTr,sys.R.m)||!est_positif(sys.b,sys.B.n)|| ite==0){

if(ite>=1){
	printf("pleaseif");
if(changement_de_variables(sys)==-1000)
return -1000;
}
printf("pleasenotif");
ite++;

afficher_mat(sys.B.mat,sys.B.n,sys.B.n);
afficher_mat(sys.R.mat,sys.R.n,sys.R.m);
for(int i=0;i<sys.B.n;i++)
printf("%lf\n",sys.b[i]);
for(int i=0;i<sys.B.n;i++)
printf("%lf\n",sys.CTb[i]);
for(int i=0;i<sys.R.m;i++)
printf("%lf\n",sys.CTr[i]);
printf("%lf\n",sys.z[0]);



int dim=sys.B.n;
int dim2=sys.R.m;
double ** inversed=(double**)malloc(dim*sizeof(double*));
	for (int i=0;i<dim;i++)
	inversed[i]=(double*)malloc(dim*sizeof(double));	

double ** result_b=(double**)malloc(dim*sizeof(double*));
	for (int i=0;i<dim;i++)
	result_b[i]=(double*)malloc(dim*sizeof(double));

double ** result_hb=(double**)malloc(dim*sizeof(double*));
	for (int i=0;i<dim;i++)
	result_hb[i]=(double*)malloc(dim2*sizeof(double));



double * b_final=(double*)malloc(dim*sizeof(double));


//printf("debug1");
//getchar();
if(inverse(sys.B.mat,dim,inversed)==-1000){
	printf("pleaseplease");
	return -2000;
}
//printf("debug2");
produit(inversed,sys.B.mat,sys.B.n,sys.B.n,sys.B.n,result_b);

//printf("debug2");
copier(result_b,sys.B.n,sys.B.n,sys.B.mat);
//printf("debug2");
produit(inversed,sys.R.mat,dim,dim,dim2,result_hb);
//printf("debug2");
copier(result_hb,dim,dim2,sys.R.mat);
//printf("debug2");
produit_vecteur(inversed,sys.b,dim,dim,b_final);
//printf("debug3");
double * temp=(double* )malloc(dim2*sizeof(double));
produit_vecteur2(result_hb,sys.CTb,dim,dim2,temp);
//printf("debug4");

for(int i=0;i<dim2;i++)
sys.CTr[i]=sys.CTr[i]-temp[i];


//printf("debug3");
for(int i=0;i<dim;i++){
	sys.z[0]-=sys.CTb[i]*b_final[i];
}


//printf("debug4");

for(int i=0;i<dim;i++)
sys.CTb[i]=0;

for(int i=0;i<dim;i++)
sys.b[i]=b_final[i];


//changement_de_variables(sys);



afficher_mat(sys.B.mat,sys.B.n,sys.B.n);
printf("\n\n");
afficher_mat(sys.R.mat,sys.R.n,sys.R.m);
printf("\n\n");

for(int i=0;i<sys.B.n;i++)
printf("%lf\n",sys.b[i]);
printf("\n\n");
for(int i=0;i<sys.B.n;i++)
printf("%lf\n",sys.CTb[i]);
printf("\n\n");
for(int i=0;i<sys.R.m;i++)
printf("%lf\n",sys.CTr[i]);
printf("\n\n");
printf("%lf\n",sys.z[0]);





}
sys.iterations[0]=ite;
for(int i=0;i<sys.B.m+sys.R.m;i++){
	if(contain(sys.positions_base,i,sys.B.n)==1) sys.base_finale[i]=1;
	else sys.base_finale[i]=0;
}
return 1;
}



int changement_de_variables(SL sys){
	if(est_positif(sys.b,sys.B.n)){
		int index=min(sys.CTr,sys.R.m);
		int index2=min_rapport(sys,index);
		if(index2==-1000) return -1000;
		for(int i=0;i<sys.B.n;i++){
			echanger(&sys.B.mat[i][index2],&sys.R.mat[i][index]);
		}
		echanger_int(&sys.positions_base[index2],&sys.positions_hors_base[index]);
		echanger(&sys.CTb[index2],&sys.CTr[index]);
	}
	else{
	int index=min(sys.b,sys.B.n);
	int	index2=min_rapport_dual(sys,index);
	if(index2==-1000) return -1000;
			for(int i=0;i<sys.B.n;i++){
			echanger(&sys.B.mat[i][index],&sys.R.mat[i][index2]);
		}
		echanger_int(&sys.positions_base[index],&sys.positions_hors_base[index2]);
		echanger(&sys.CTb[index],&sys.CTr[index2]);
		
		
		
	}
	return 1;
}
 
int min(double * vector,int n){
double	min=vector[0];int k=0;
	for (int i=1;i<n;i++)
	{if (vector[i]<min){
	
	min=vector[i];
	k=i;
	}
	}
return k;
}


int min_rapport(SL sys, int index){
	double min=DBL_MAX;
int index2=-1;
for (int i=0;i<sys.B.n;i++)
{if (sys.R.mat[i][index]>0){
	if(sys.b[i]/sys.R.mat[i][index]<min){
	
	min=sys.b[i]/sys.R.mat[i][index];
index2=i;
}}
	
}
if(index2==-1 ){
printf("le probleme n est pas borne solution a l infini");
return -1000;

}

return index2;
}



int min_rapport_dual(SL sys,int index){
	double min=DBL_MAX;
int index2=-1;
for (int i=0;i<sys.R.m;i++)
{if (sys.R.mat[index][i]<0){
	if(sys.CTr[i]/(-1*sys.R.mat[index][i])<min){
	
	min=sys.b[i]/(-1*sys.R.mat[i][index]);
index2=i;
}}
	
}
if(index2==-1 ){
printf("le probleme n est pas realisable");
return -1000;

}

return index2;






}
void echanger_int(int *i1,int *i2){
	int temp=*i1;
	*i1=*i2;
	*i2=temp;
}
/*
void change_base_depart(SL sys){
	int n= sys.B.m+sys.R.m
}
*/
int contain(int * tab , int i , int taille){
	for (int j=0;j<taille ; j++){
		if (tab[j]==i)return 1;
}
		return 0;
}
void transpose(double ** mat,int n,int m,double ** transposed){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			transposed[j][i]=mat[i][j];
			//1 2 1 3 5                      [0][0] [0][1] [0][2] [1][1]
			//3 4 2 4 6               
			//5 6
			
		}
	}
	
	
	
	
}

