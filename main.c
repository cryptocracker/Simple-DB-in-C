#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
	FILE *fp, *ft;
	char another, choice;
	struct emp
	{
		char name[40];
		int age;
		float bs;
	};
struct emp e;
char empname[40];
long int recsize;

fp = fopen ("EMP.DAT", "rb+");

if(fp==NULL){
	fp = fopen("EMP.DAT", "wb+");

	if(fp==NULL){
		puts("Cannot open database file");
		exit(1);
	}
}

recsize = sizeof(e);

while(1){
	system("cls");


	printf("\n1. Add Records");
	printf("\n2. List Records");
	printf("\n3. Modify Records");
	printf("\n4. Delete Records");
	printf("\n0. EXIT");
	printf("\nYour Choice");

	fflush(stdin);
	choice=getche();
	switch(choice){
		case '1':
			fseek(fp, 0, SEEK_END);
			another='Y';
			while(another=='Y'){
				printf("\nEnter name, age and basic salary\n");
				scanf("%s%d%f", e.name, &e.age, &e.bs);
				fwrite(&e, recsize, 1, fp);
				printf("\nAdd another record (Y/N)\n");
				fflush(stdin);
				another=getche();
			}
			break;

		case '2':
			rewind(fp);
			while(fread(&e, recsize, 1, fp) == 1)
				printf("\n%s %d %f\n", e.name, e.age, e.bs);

			break;

		case '3' :
	 	another = 'Y' ;
		while ( another == 'Y' ){
		printf ( "\nEnter name of employee to modify\n" ) ;
		scanf ( "%s", empname ) ;
		rewind ( fp ) ;
		while ( fread ( &e, recsize, 1, fp ) == 1 ) 
			{
			 if ( strcmp ( e.name, empname ) == 0 )
			 {
				 printf ( "\nEnter new name, age & bs\n" ) ;
				 scanf ( "%s %d %f", e.name, &e.age,
				 &e.bs ) ;
				 fseek ( fp, - recsize, SEEK_CUR ) ;
				 fwrite ( &e, recsize, 1, fp ) ;
				 break ;
			 }
			 }
			 printf ( "\nModify another Record (Y/N)\n " ) ;
			 fflush ( stdin ) ;
			 another = getche( ) ;
			 }
			 break ;

			 case '4' :
				 another = 'Y' ;
				 while ( another == 'Y' )
				 {
					 printf ( "\nEnter name of employee to delete\n" ) ;
					 scanf ( "%s", empname ) ;
					 ft = fopen ( "TEMP.DAT", "wb" ) ;
					 rewind ( fp ) ;
					 while ( fread ( &e, recsize, 1, fp ) == 1 )
					 {
					 if ( strcmp ( e.name, empname ) != 0 )
					 fwrite ( &e, recsize, 1, ft ) ;
					 }
					 fclose ( fp ) ;
					 fclose ( ft ) ; 
					 remove ( "EMP.DAT" ) ;
					 rename ( "TEMP.DAT", "EMP.DAT" ) ;
					 fp = fopen ( "EMP.DAT", "rb+" ) ;
					 printf ( "Delete another Record (Y/N) " ) ;
					 fflush ( stdin ) ;
					 another = getche( ) ;
				 }
				 break ;
 
			 case '0' :
				 fclose ( fp ) ;
				 exit(0) ;
				}

}

}
