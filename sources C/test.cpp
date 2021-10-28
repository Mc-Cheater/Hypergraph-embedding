	
#include"randomwalks.cpp"



 int main(int argc , char** argv=NULL/*,int number_of_walks=3,int p_parameter=1,int q_parameter=1,char* sortie="abass_sortie"*/){

int Walk_length;
int p_parameter;
int q_parameter;
int number_of_walks;
char* sortie=(char*)malloc(100*sizeof(char));
char* input=(char*)malloc(100*sizeof(char));
	if(argc<=1){
		strcpy(input,"Cancers.txt");
	}else{
		strcpy(input,argv[1]);
	}
	
	if(argc<=2)
		Walk_length=3;
		else
		{Walk_length=atoi(argv[2]);
			
		}
		if(argc<=3)
		p_parameter=1;
		else{
			p_parameter=atoi(argv[3]);
		}
		if(argc<=4)
		q_parameter=1;
		else{
			q_parameter=atoi(argv[4]);
		}
		if(argc<=5)
		strcpy(sortie,"training_inputs_dataset_to_MLP_to_encode");		
	else {strcpy(sortie,argv[5]);
	}
	if(argc<=6) number_of_walks=1000;
	else{
		number_of_walks=atoi(argv[6]);
	}
	
	
	
	
	FILE * saver=fopen(sortie,"w+t");
	FILE * saver2=fopen("nodes","w+t");
	FILE *f=fopen("saved_adjacency","w+t");
	FILE *g=fopen("adjacency_to_predict","w+t");
	FILE * generics=fopen("number_of_nodes","w+t");
//	printf("%s",dataset[1]);
//	getchar();
	Hypergraph H;
	H.n=0;
	H.m=0;
	H.Edges=(Edge*)malloc(sizeof(Edge));
	H.Nodes=(Node*)malloc(sizeof(Node));
	Construct_hypergraph(&H,input/*"Cancers.txt"*/);
	
	
	
	
	
	
	char *bufferrr=(char*)malloc(5*sizeof(char));
sprintf(bufferrr,"%d",H.n);
bufferrr[4]='\0';

fputs(bufferrr,generics);
fclose(generics);

char ***	Transitions_table;
Transitions_table=(char***)malloc(H.n*sizeof(char**));
	
int* tab_size =(int*)malloc(H.n*sizeof(int));
	Construire_tables_de_transitions(H,Transitions_table,tab_size);
	
	
	
	
	
//	getchar();
	
	
	
	
	
	
	Generate_Random_Walks(H,Transitions_table,Walk_length,number_of_walks,tab_size,saver,saver2,p_parameter,q_parameter );
	
	
	fclose(saver);
	fclose(saver2);
	
	
	
//	getchar();
//	getchar();
	
	getchar();
	exit(0);
	getchar();
	
	
	
	
	
	
	
	
	
	
	printf("ok");
	printf("%d \n",H.n);
	for (int i=0;i<H.n;i++){
		printf("%s\n %d\n",H.Nodes[i].Item,H.Nodes[i].support);
	}
	printf("voici les edges\n");
	
	char * ecrit_bis=(char*)malloc(200*sizeof(char));
ecrit_bis[0]='\0';
char * buffer_bis=(char*)malloc(10*sizeof(char));
buffer_bis[0]='\0';



	
	
	printf("%d",H.m);
for(int i=0;i<H.m;i++){
	for(int j=0;j<H.Edges[i].taille;j++){
	printf("%s\t",H.Edges[i].Items[j]);
	strcat(ecrit_bis,H.Edges[i].Items[j]);
	strcat(ecrit_bis," ");
	}sprintf(buffer_bis,"%d",H.Edges[i].support);
	strcat(ecrit_bis,buffer_bis);
	strcat(ecrit_bis,"\n");
	fputs(ecrit_bis,g);
	ecrit_bis[0]='\0';
	buffer_bis[0]='\0';
	printf("\n");
}	

for(int i=0;i<H.n;i++) printf("%d\n",H.Nodes[i].support);
	for(int i=0;i<H.m;i++) printf("%d\n",H.Edges[i].support);

printf("\n\n\n\n");
for(int i=0;i<H.m;i++) printf("%d\n",H.Edges[i].taille);



Matrices * Ma=(Matrices*)malloc(sizeof(Matrices));
Calculate(Ma,H);

printf("\n incidence \n");
for(int i=0;i<H.n;i++){
	for(int j=0;j<H.m;j++){
		printf("%lf\t",Ma->Incidence[i][j]);
	}printf("\n");
}

printf("\n degres de vectrices\n");
for(int i=0;i<H.n;i++){
	for(int j=0;j<H.n;j++){
		printf("%lf\t",Ma->Dv[i][j]);
	}printf("\n");
}


printf("\n degres de edges\n");
for(int i=0;i<H.m;i++){
	for(int j=0;j<H.m;j++){
		printf("%lf\t",Ma->De[i][j]);
	}printf("\n");
}

printf("\n poids\n");
for(int i=0;i<H.m;i++){
	for(int j=0;j<H.m;j++){
		printf("%lf\t",Ma->W[i][j]);
	}printf("\n");
}





printf("\n laplacien\n");
for(int i=0;i<H.n;i++){
	for(int j=0;j<H.n;j++){
		printf("%lf\t",Ma->LaPlacien[i][j]);
	}printf("\n");
}



printf("\n laplacien pseudo inverse\n");
for(int i=0;i<H.n;i++){
	for(int j=0;j<H.n;j++){
		printf("%lf\t",Ma->LaPlacien_plus[i][j]);
	}printf("\n");
}












double** truc=(double **)malloc(10*sizeof(double*));
for(int i=0;i<10;i++)truc[i]=(double*)malloc(sizeof(double));
for(int i=0;i<10;i++)
truc[i][0]=1;

double ** truc2=(double**)malloc(sizeof(double*));
truc2[0]=(double*)malloc(10*sizeof(double));
for(int i=0;i<10;i++)
truc2[0][i]=1;

double ** mattt=(double**)malloc(10*sizeof(double*));
for(int i=0;i<10;i++)
mattt[i]=(double*)malloc(10*sizeof(double));

produit(truc,truc2,10,1,10,mattt);


/*
printf("\n\n");
for(int i=0;i<10;i++){
	for(int j=0;j<10;j++){
		printf("%lf\t",mattt[i][j]);
	}printf("\n");
}

*/
printf("\n\n");
for(int i=0;i<H.n;i++){
	for(int j=0;j<H.n;j++){
		printf("%lf\t",Ma->dist[i][j]);
	}printf("\n");
}

printf("\n\n");
char * ecrit=(char*)malloc(200*sizeof(char));
ecrit[0]='\0';
char * buffer=(char*)malloc(10*sizeof(char));
buffer[0]='\0';
for(int i=0;i<H.n;i++){
 	
	for(int j=0;j<H.n;j++){
		printf("%lf\t",Ma->Sct[i][j]);
	if(i<j){
	
	ecrit=strcat(ecrit,H.Nodes[i].Item);
	//ecrit+=H.Nodes[j].Item;
	ecrit=strcat(ecrit," ");
	ecrit=strcat(ecrit,H.Nodes[j].Item);
	ecrit=strcat(ecrit," ");
	sprintf(buffer,"%lf",Ma->Sct[i][j]);
	buffer[4]='\0';
	//ecrit+=buffer;
	ecrit=strcat(ecrit,buffer);
	fputs(ecrit,f);
	fputs("\n",f);
	ecrit[0]='\0';
	buffer[0]='\0';
	}
	}printf("\n"); 
}
fclose(f);
fclose(g);
//exit(0);
//printf("\n%lf",(Ma->Sct[0][1]+Ma->Sct[0][2]+Ma->Sct[1][2])/3);
return 0;
}














