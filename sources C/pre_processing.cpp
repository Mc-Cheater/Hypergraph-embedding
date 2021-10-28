#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct patients{
		char* patient=(char*)malloc(5000*sizeof(char));
		int number=1;
	}Patients;
	

contenir(Patients* tab,int count,char*buffer){
	for(int i=0;i<count;i++){
		if(strcmp(tab[i].patient,buffer)==0){
			return i;
		}
	}
	return-1;
}




main(){
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	FILE* f=fopen("lung-cancer.data","r+t");
	FILE* g=fopen("lung_datas_processed_as_hypergraph","w+t");
	FILE* g2=fopen("lung_datas_processed_as_hypergraph","rt");
	FILE* g3=fopen("lung_datas_processed_as_graph","w+t");
	char * ligne=(char*)malloc(500*sizeof(char));
	char* ligne_en_sortie =(char*)malloc(5000*sizeof(char));
	ligne_en_sortie[0]='\0';
	char* mot=(char*)malloc(10*sizeof(char));
	mot[0]='\0';
	char*buffer=(char*)malloc(3*sizeof(char));
	buffer[0]='\0';
	int iterator;int iterer=0;
	
	while(fgets(ligne,499,f)){
		printf("iteration %d\n",++iterer);
		
		strcat(ligne_en_sortie,"cancer_type_");
		iterator=0;
		printf("ligne %d",iterator+1);
		do{
			if(iterator<=0){
				printf("ok %d",iterator);
				mot=strtok(ligne,",");
				strcat(ligne_en_sortie,mot);
				strcat(ligne_en_sortie," ");
			iterator++;
			}
			else{
				printf("ol %d",iterator);
				strcat(ligne_en_sortie,"Symptome_");
			sprintf(buffer,"%d",iterator);
			strcat(ligne_en_sortie,buffer);
			strcat(ligne_en_sortie,"type_");
			strcat(ligne_en_sortie,mot);
			strcat(ligne_en_sortie," ");
			iterator++;
			
			
			}
			
			
			
			
			
		}while(mot=strtok(NULL,","));
		int len=strlen(ligne_en_sortie);
		ligne_en_sortie[len-1]='\0';
		//strcat(ligne_en_sortie,"\n");
		fputs(ligne_en_sortie,g);
		ligne_en_sortie[0]='\0';
		
		
		
		
		
		
		
	}
	fclose(f);
	fclose(g);
Patients *tableau=(Patients*)malloc(100*sizeof(Patients));
for(int o=0;o<100;o++)
{tableau[o].patient=(char*)malloc(5000*sizeof(char));
tableau[o].number=1;
}
int count=1;

char *buffer_2=(char*)malloc(5000*sizeof(char));
fgets(buffer_2,4999,g2);
strcpy(tableau[0].patient,buffer_2);

//tableau[0]=(char*)malloc(5000*sizeof(char));




int i=-1;
while(fgets(buffer_2,4999,g2)){
if(i=contenir(tableau,count,buffer_2)>=0){
printf("\n\n zabi");
	tableau[i].number++;
	
	
	
}
else{printf("\n\n zabi au carre");
///*tableau=(Patients*)*/realloc(tableau,(++count)*sizeof(Patients));
strcpy(tableau[count++].patient,buffer_2);	
	
	
	
}


}
for(int i=0;i<count;i++){
	printf("%s\n,%d\n",tableau[i].patient,tableau[i].number);
}
getchar();

	
	char* item=(char*)malloc(100*sizeof(char));
	char* enregistrement=(char*)malloc(200*sizeof(char));
	char* ind=(char*)malloc(10*sizeof(char));
enregistrement[0]='\0';
for(int i=0;i<count;i++){
	sprintf(ind,"%d",i+1);
	for(int j=0;j<tableau[i].number;j++){
		int iter=0;
		do{
			
		if(iter==0){
		item=strtok(tableau[i].patient," ");
		strcat(enregistrement,"patient_");
		strcat(enregistrement,ind);
		strcat(enregistrement," ");
		strcat(enregistrement,item);
		
		
		fputs(enregistrement,g3);
		int tempor=strlen(enregistrement);
		if(enregistrement[tempor-1]!='\n')
		fputs("\n",g3);
		enregistrement[0]='\0';
		iter++;
	}else{
		strcat(enregistrement,"patient_");
		strcat(enregistrement,ind);
		strcat(enregistrement," ");
		strcat(enregistrement,item);
		fputs(enregistrement,g3);
		int tempor=strlen(enregistrement);
		if(enregistrement[tempor-1]!='\n')
		fputs("\n",g3);
		
		
		enregistrement[0]='\0';
	iter++;}
			
			
			
			
			
		}while(item=strtok(NULL," "));
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
}	
	fclose(g2);
	fclose(g3);
	
	
	
	
	
	
}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

