#include "lib.h"

/************************************************************************************************/
/* Description : Exemple d'utilisation de tube nommée						*/
/************************************************************************************************/
int main(/*int argc, char *argv[]*/){
	
	char string[SIZE]; 
	int temp;
	
	
	printf("Voulez-vous :\n");
	printf("1) Créer le tube nommée\n");
	printf("2) Lire dans un tube nommée déjà existant\n");
	scanf("%d",&temp);
	

//-------------------------------------------côté ecriture/serveur-------------------------------------------	
	//si on créer/écrit dans le tube :
	if(temp==1){
	
		printf("Création du tube nommée : pid : %d\n", getpid());
		printf("%s\n",nameTube( getpid()));
		//on créer le tube
		createTube( nameTube( getpid()) );
		
		printf("Veuillez écrire une chaine de caractère dans ce tube (taille max :%d) :\n",SIZE);
		scanf("%s",string);
		//on écrit dans le tube :
		int valwrite = writeTube( nameTube( getpid()), string, SIZE); //SIZE*sizeof(char)
		
			/*printf("Veuillez écrire une chaine de caractère dans ce tube (taille max :%d) :\n",SIZE);
			scanf("%s",string);
			valwrite = writeTube( nameTube( getpid()), string, SIZE);*/
		
		printf("Appuyer sur une touche pour fermer le tube\n");
		scanf("%d",&temp);
		
		//on ferme la sortie écriture du tube
		close(valwrite);
		
		
//-------------------------------------------côté lecture/client-------------------------------------------	
	}
	//si on lit dans le tube déjà existant :
	else{
		printf("saisir le pid :\n");
		scanf("%d",&temp);
		
		//on lit dans le tube :
		int valread = readTube( nameTube(temp), string, SIZE);
		printf("Valeur dans le tube : %s \n", string);
		
			/*sleep(5);
			
			valread = readTube( nameTube(temp), string, SIZE);
			printf("Valeur dans le tube : %s \n", string);*/
		
		printf("Appuyer sur une touche pour fermer le tube\n");
		scanf("%d",&temp);
		
		//on ferme la sortie lecture du tube
		close(valread);
	}
	return 0;
}
