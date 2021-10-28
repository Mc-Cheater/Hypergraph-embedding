
typedef struct edge{
char** Items;
double Weight;
int support;
int taille;
double sct;
}Edge;


typedef struct node{
	char * Item;
	double degree;
	int support;
}Node;


typedef struct hypergraph   {
	
	Node * Nodes;
	Edge * Edges;
	int n;
	int m;
	//double * weights;
	
	
	
	
}Hypergraph;





typedef struct hypergraph_calculs{

double ** LaPlacien;
double ** Incidence;
double ** Adjacence;
double ** LaPlacien_plus;
double **  De; // Edges Degree
//les 4 matricces précédentes sont en réalités des int mais pour des soucis de programmation je les déclare en double
double ** W; //  weights
double ** Dv;// Vertex degree
double ** dist;
double ** Sct;
}Matrices;

typedef struct random_walk{

double ** Prob;// matrice de probabilite de transition



}Rw;

typedef struct subedges {
	int* Sub_edges;
	double Sub_Sct;
	
}Subedge;

void Construct_hypergraph(Hypergraph *H,char * dataset_path);

void Calculate (Matrices* M,Hypergraph H);
void Calculate_prob(Matrices M , Rw* Probs);



typedef struct more_calculs {
}More_matrices;

int Node_compare(Node n1,Node n2);


void product_vect_vect(double * vect1,double *vect2,int n,int m ,double **matrix);

int contient(Hypergraph h,Node n);
void ajout(Hypergraph h,Node n);
void tri (char** tab,int n);
void echange_str(char** str1,char** str2);
int contient_e(Hypergraph h,Edge e);
int Edge_compare(Edge e1,Edge e2);
void ajout_e(Hypergraph h,Edge e);
void construct_subedges(Hypergraph H, Matrices Ma,Subedge* Sub,double threshold);


