typedef struct mat{
	double mult;
	double** mat;
	int taille;
	int n;
	int m;
}Matrice;

typedef Matrice* Element;
typedef struct cellule{
	Element e;
	struct cellule * suivant;
}Cellule;

typedef Cellule * Pile;

int est_vide(Pile p);
Pile pile_vide();
Pile empiler(Pile p , Element e);
Pile depiler(Pile p);
Element sommet(Pile p);


double ** construire_co_facteur(double **matrice,int del_line,int del_col,int n,int m,double **co_fac); 

void echanger(double* a,double* b);

void copier(double **mat ,int n,int m,double** copie);

void produit(double ** mat1,double ** mat2 ,int n,int m,int k,double** mat_result);

void produit_scalaire(double** mat,int n,int m,double scalaire);

void construire_co_matrice(double** mat,int n,double *** comatrice_uncalculed,double ** co_fac);

void produit_vecteur(double ** mat1,double * vecteur ,int n,int m,double* vecteur_result);

void det(Pile p,Pile q,double *somme);

void transposer(double** mat,int n);

void transpose(double ** mat,int n,int m,double ** transposed);

int inverse(double ** mat,int n, double ** inverse);

typedef struct systeme_lineaire{
	Matrice B;
	Matrice R;
	double* CTb;
	double* CTr;
	double* b;
	int * vect_choix_base;
	double* z;
	int * positions_base;
	int * positions_hors_base;
	int * base_finale;
	int * iterations;
	
}SL;

void Split(double ** A , int n, int m ,double ** B , double ** R , double * CT,double *CTb,double * CTr,int * choix_base_depart,int * positions_base,int * positions_hb);

int simplex(SL sys);
int est_positif(double * vecteur, int n);
int changement_de_variables(SL sys);
int min(double * vector,int n);

int min_rapport_dual(SL sys,int index);
int min_rapport(SL sys, int index);
void echanger_int(int *i1,int *i2);

int contain(int * tab , int i , int taille);

