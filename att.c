#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<pwd.h>
#include<dirent.h>
#include<time.h>
#include<string.h>
#define _GNU_SOURCE
void ListFile(char * dirname){

	 struct stat StatusBuffer;
	 char pathname[100] = {0};
	strcat(pathname,"./");
	if(strcmp(dirname,".")==!0)
	strcat(pathname,dirname);
	DIR * dir = opendir(pathname);


	 if (stat(dirname,&StatusBuffer)==-1)
	 {
	 perror("stat()");
	 exit(1);
	 }
	 
	 
	 if (S_ISREG(StatusBuffer.st_mode))
		{
		printf("%s esr un fichier regulier \n",dirname);
		}
		else if (S_ISDIR(StatusBuffer.st_mode))
		{
		char cwd[40] ={0} ;
		getcwd(cwd,40);
		
		if(strcmp(dirname,".") == 0){
		printf("\n%s est un repartoire\n",cwd);
		printf("le contenu de %s :\n",cwd);
		}
		else
		{
		printf("\n%s est un repartoire\n",dirname);
		printf("le contenu de %s :\n",dirname);
		}
		goto rep;
		} 
		
		
		
	 
	 
	 
	 			printf("Nom du fichier :%s\n ",dirname);
	  			printf("\n Les droits d'acces de ce fichier en mode symbolique sont : \n ");
			        printf("-");
				printf("%c",StatusBuffer.st_mode & S_IRUSR ? 'r' : '-');
				printf("%c",StatusBuffer.st_mode & S_IWUSR ? 'w' : '-');
				printf("%c",StatusBuffer.st_mode & S_IXUSR ? 'x' : '-');
				printf("%c",StatusBuffer.st_mode & S_IRGRP ? 'r' : '-');
				printf("%c",StatusBuffer.st_mode & S_IWGRP ? 'w' : '-');
				printf("%c",StatusBuffer.st_mode & S_IXGRP ? 'x' : '-');
				printf("%c",StatusBuffer.st_mode & S_IROTH ? 'r' : '-');
				printf("%c",StatusBuffer.st_mode & S_IWOTH ? 'w' : '-');
				printf("%c",StatusBuffer.st_mode & S_IXOTH ? 'x' : '-');
				printf("\nOwner : %s \n",getpwuid(StatusBuffer.st_uid)->pw_name);
				printf("group  : %s \n",getpwuid(StatusBuffer.st_gid)->pw_name);
				printf("link file %ld  \n",StatusBuffer.st_nlink );
				printf("Taille  :  %ld\n",StatusBuffer.st_size);
 				printf("Dernier accès au fichier : %s", ctime(&StatusBuffer.st_atime));
 				printf("Dernière modification du fichier:  %s", ctime(&StatusBuffer.st_mtime));
				printf("dernier modification de inode number(status)  : %s \n", ctime(&StatusBuffer.st_ctime));
	 
	 goto fin;
	 
	 rep:
	if (dir == NULL )
	exit(1);
		
	struct dirent * f = readdir(dir);
            
	  			while(f != NULL)
	  			{
	  			if (strcmp(f->d_name,".")!= 0 && strcmp(f->d_name,"..")!= 0){
	  			stat(f->d_name,&StatusBuffer);

				printf("\n Les droits d'acces de ce fichier en mode symbolique sont : \n ");
	  			if (f->d_type ==DT_DIR)
	  			{
	  				 printf("%s est un repartoire \n",f->d_name);
						printf("d");
						}
	  		 	else{
	  		 		  printf("%s est un fichier \n",f->d_name);
	  											printf("-");}
				printf("%c",StatusBuffer.st_mode & S_IRUSR ? 'r' : '-');
				printf("%c",StatusBuffer.st_mode & S_IWUSR ? 'w' : '-');
				printf("%c",StatusBuffer.st_mode & S_IXUSR ? 'x' : '-');
				printf("%c",StatusBuffer.st_mode & S_IRGRP ? 'r' : '-');
				printf("%c",StatusBuffer.st_mode & S_IWGRP ? 'w' : '-');
				printf("%c",StatusBuffer.st_mode & S_IXGRP ? 'x' : '-');
				printf("%c",StatusBuffer.st_mode & S_IROTH ? 'r' : '-');
				printf("%c",StatusBuffer.st_mode & S_IWOTH ? 'w' : '-');
				printf("%c",StatusBuffer.st_mode & S_IXOTH ? 'x' : '-');
				printf("c\nOwner : %s \n",getpwuid(StatusBuffer.st_uid)->pw_name);
				printf("group  : %s \n",getpwuid(StatusBuffer.st_gid)->pw_name);
				printf("link file %ld  \n",StatusBuffer.st_nlink );
				printf("Taille  :  %ld\n",StatusBuffer.st_size);
 				printf("Dernier accès au fichier : %s", ctime(&StatusBuffer.st_atime));
 				printf("Dernière modification du fichier:  %s", ctime(&StatusBuffer.st_mtime));
				printf("dernier modification de inode number(status)  : %s \n", ctime(&StatusBuffer.st_ctime));
				printf("\n \n \n");              
               }
               		f = readdir(dir);
                              }
               closedir(dir);

	 	fin:
	 	printf("\n");
	 	
	 }

int main (int argc , char *  argv[]){




if (argc < 1)
{
perror("lack of arguments");
exit(1);
}
if ( strcmp(argv[1],"-l")==0)
{
	for (int i = 2 ; i < argc ; i++)
	{
		ListFile(argv[i]);
	}
}
else
{
for (int i = 1 ; i < argc ; i++ ){
       struct stat StatusBuffer;


	 if (stat(argv[i],&StatusBuffer)==-1)
	 {
	 perror("stat()");
	 exit(1);
	 }
	 
	char pathname[100] = {0};
	strcat(pathname,"./");
	strcat(pathname,argv[i]);

	 
	 if (S_ISREG(StatusBuffer.st_mode))
		
		printf("\n \n %s est un fichier regulier \n",argv[i]);
		
		else if (S_ISDIR(StatusBuffer.st_mode))
		{
		char cwd[40] ={0} ;
		
		if(strcmp(argv[i],".")==0){
		getcwd(cwd,40);
		printf("\n%s est un repartoire\n",cwd);
		printf("le contenu de %s :\n",cwd);
		}
		else
		{
		printf("\n%s est un repartoire\n",argv[i]);
		printf("le contenu de %s :\n",argv[i]);
		}
			DIR * dir = opendir(pathname);
        if (dir == NULL )
	 exit(1);
		
	struct dirent * f = readdir(dir);
            
	  			while(f != NULL)
	  			{
	  			if (strcmp(f->d_name,".")!= 0 && strcmp(f->d_name,"..")!= 0){
	  			stat(f->d_name,&StatusBuffer);

	  			if (f->d_type ==DT_DIR)
	  			
	  				 printf("%s est un repartoire \n",f->d_name);
						
						
	  		 	else
	  		 		  printf("%s est un fichier \n",f->d_name);
	  			
             			  }
               		f = readdir(dir);
                              }
              			 closedir(dir);
		 } 
	 
}
}

return EXIT_SUCCESS;
}
