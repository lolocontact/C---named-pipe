#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/shm.h>
#include <errno.h>  
#include <errno.h>
#include <signal.h>

#define SIZE 1000
#define MSIZE 64
#define MaxUsers 100

#define CHECK(sts,msg) if ((sts) == -1 )  { perror(msg);_exit(-1);}

/************************************************************************************************/
/*Fonction : createTube										*/
/* Description : Créer un tube nommé avec les droits UNIX definie dans la variable FIFO_MODE	*/
/************************************************************************************************/
void createTube( char * name );

/************************************************************************************************/
/*Fonction : readTube										*/
/* Description : ouvre un tube en read only (côté client), lit dans le tube, puis le clot	*/
/************************************************************************************************/
int readTube(char * name, char * msg, int size /*MSIZE*/);

/************************************************************************************************/
/*Fonction : writeTube										*/
/* Description : ouvre un tube en write only (côté serveur), écrit dedans, puis clot		*/
/************************************************************************************************/
int writeTube(char * name, char * msg, int size);

/************************************************************************************************/
/*Fonction : nameTube										*/
/* Description : prends un pid (int) et retourne un string sous la forme "/tmp/<pid>.fifo"	*/
/************************************************************************************************/
char * nameTube( int pid );

//int close(int descripteur);
