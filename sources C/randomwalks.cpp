#include<time.h>
#include"realisation.cpp"


char* voisin(Edge e,Node n){
	if(!edge_contain_v(e,n)) {
		printf("attention erreur");
		exit(0);
	}
	if(strcmp(n.Item,e.Items[0])==0) 
	return e.Items[1];
	else if(strcmp(n.Item,e.Items[1])==0)
return e.Items[0];
else {printf("attention autre erreur");
exit(0);
}	
	
	
}

void Construire_tables_de_transitions(Hypergraph H, char ***transitions,int *tab_tableau_size){
	
	
	
	
	
	
	
	
	
	int nombre_de_voisins=0;
	int tableau_size=0;
	int compteur=0;
	for(int i=0;i<H.n;i++){
		
		nombre_de_voisins=0;
		tableau_size=0;
		for(int j=0;j<H.m;j++){
			
		if(edge_contain_v(H.Edges[j],H.Nodes[i])){
		
			nombre_de_voisins++;
			tableau_size+=H.Edges[j].support;
	}
		}
		
		tab_tableau_size[i]=tableau_size;
		
		transitions[i]=(char**)malloc(tableau_size*sizeof(char*));
		for(int j=0;j<tableau_size;j++){
			transitions[i][j]=(char*)malloc(30*sizeof(char));
		} 
		compteur=0;
		for(int j=0;j<H.m;j++){
			
		if(edge_contain_v(H.Edges[j],H.Nodes[i])){
		
		int temporary=H.Edges[j].support;
		
		while(temporary>0){
		strcpy(transitions[i][compteur++],voisin(H.Edges[j],H.Nodes[i]));	
			temporary--;
			
			
		}
	}
		
		}
		
		
		
		
		
		
		
		
		
		
	}
	
	
	for(int i=0;i<H.n;i++){
		for(int j=0;j<tab_tableau_size[i];j++){
			
			printf("%s \t",transitions[i][j]);
			
			
			
		}
		printf("\n\n\n\n");
	}
	
	
}

int index_of_node(char** Nodes,char * Node,int n){
for(int i=0;i<n;i++){
	if(strcmp(Node,Nodes[i])==0){
		return i;
	}
}
printf("fatal error");
exit(0);
return -1;	
}




void Generate_Random_Walks(Hypergraph H,char *** Transition_table,int Walk_length,int number_of_walks,int *tab_size,FILE *f,FILE *g,int p, int q ){
	char** vecteurs=(char**)malloc(H.n*sizeof(char*));
	for(int i=0;i<H.n;i++)
	vecteurs[i]=(char*)malloc((H.n*2+10)*sizeof(char));
//	for(int i=0;i<H.n;i++);
//	vecteurs[i]="";
	
	for(int i=0;i<H.n;i++){
		for(int j=0;j<H.n;j++){//printf("please marche");
			if(j==i) {
				if(j==H.n-1) strcat(vecteurs[i],"1,");
			else strcat(vecteurs[i],"1 ");
		}
			else {if(j==H.n-1) strcat(vecteurs[i],"1,");
			else
			strcat(vecteurs[i],"0 ");
		}}
		strcat(vecteurs[i],"\0");
	}
	
//	printf("please marche ");
//	getchar();
	int yy=0;
	
long long  timer=0;
	int current;
	char** Nodes =(char**)malloc(H.n*sizeof(char*));
	for(int i=0;i<H.n;i++)
	Nodes[i]=(char*)malloc(30*sizeof(char));
	for(int i=0;i<H.n;i++){
		strcpy(Nodes[i],H.Nodes[i].Item);
	}
	long long ziterator=0;
	int iterator=0;
	int iterator2=0;
	int old=0;
	int var_temp=0;
	char * buffer2=(char*)malloc(5*sizeof(char));
	char * buffer=(char*)malloc(5*sizeof(char));
	char*temporary=(char*)malloc(30*sizeof(char));
	char*** Walks=(char***)malloc(H.n*number_of_walks*sizeof(char**));
	for(int i=0;i<H.n*number_of_walks;i++)
	Walks[i]=(char**)malloc(Walk_length*sizeof(char*));
	for(int i=0;i<H.n*number_of_walks;i++)
	for(int j=0;j<Walk_length;j++)
	Walks[i][j]=(char*)malloc(30*sizeof(char));
	int voyant=0;
	long long zerator=1;
	
	for(int i=0;i<number_of_walks;i++){
	
	for(int j=0;j<H.n;j++){
		/*(i+1)*(j+1)+i+2+j)*/
		//if(j>=1)old=j-1;
		current=j;
		
		for(int k=0;k<Walk_length;k++){
		//if(k>=1)old
		zerator++;
		srand(time(&timer)+zerator);	
			if(p==q || k==0){
			
			strcpy(temporary,Transition_table[current][(rand()%(tab_size[current]))]);
			strcpy(Walks[/*i*j+j*/iterator][k],temporary);
		//var_temp=old;
		old=current;
		
			current=index_of_node(Nodes,temporary,H.n);
		
		}
		else if(p>q)
		{for(int iy=0;iy<p/**tab_size[current]*/;iy++)
			{ziterator++;
			srand(timer+zerator+ziterator+100);
			strcpy(temporary,Transition_table[current][(rand()%(tab_size[current]))]);
			voyant=0;
			if(strcmp(temporary,H.Nodes[old].Item)==0){strcpy(Walks[/*i*j+j*/iterator][k],temporary);
			old=current;
			current=index_of_node(Nodes,temporary,H.n);
			voyant=1;//printf("plza");
			break;
			}//if(voyant==0)printf("je dois atteindre ca au moins une fois");
		}if(voyant==0){//printf("plzn");
		
			strcpy(Walks[/*i*j+j*/iterator][k],temporary);
	old=current;
			current=index_of_node(Nodes,temporary,H.n);
	//	old=current;
	}voyant=0;
			
		}else if(p<q)
		{for(int iy=0;iy<q/**tab_size[current]*/;iy++)
			{
			
			strcpy(temporary,Transition_table[current][(rand()%(tab_size[current]))]);
			
			if(strcmp(temporary,H.Nodes[old].Item)!=0){strcpy(Walks[/*i*j+j*/iterator][k],temporary);
			old=current;
			current=index_of_node(Nodes,temporary,H.n);
			voyant=1;
			//old=current;
			}
		}if(voyant==0){
		
			strcpy(Walks[/*i*j+j*/iterator][k],temporary);
		old=current;
			current=index_of_node(Nodes,temporary,H.n);
		//old=current;
	}voyant=0;
			
		}
		
			
			
			
			
			
		}
		
		
		
		
	iterator++;}
	
}
	
	
	printf("ici pas de soucis");
	for (int i=0;i<number_of_walks;i++){
		for(int j=0;j<H.n;j++){
			for(int ee=0;ee<Walk_length;ee++){
			
				//			srand(time(&timer)+i*j+j);
			
				//		yy=rand()%Walk_length;	
				sprintf(buffer2,"%d",j);
				fputs(buffer2,f);				
			buffer2[2]='\0';
			fputs(",",f);
				//fputs(vecteurs[j],f);
				//fputs("\n",f);
			//	fputs(vecteurs[index_of_node(Nodes,Walks[i*j+j][yy],H.n)],g);
			sprintf(buffer,"%d",index_of_node(Nodes,Walks[/*i*j+j*/iterator2][ee],H.n));
			buffer[2]='\0';
			fputs(buffer,f);
				fputs("\n",f);
		//	for(int k=0;k<Walk_length;k++){
				
				
			//	printf("%s\t",Walks[i*j+j][k]);
				
			
				
		//	}
			}iterator2++;//printf("\n");
		}//printf("\n\n\n");
	}
	
	
	
	char* abass=(char*)malloc(30*sizeof(char));
	
	for(int ij=0;ij<H.n;ij++){
		strcpy(abass,H.Nodes[ij].Item);
		fputs(abass,g);
		fputs("\n",g);
	}
	
	
	
	
	
	
	
	
	
	
	
}
