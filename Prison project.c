#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void add();
void search();
void view();
void edit();
void delete_data();
void login();


struct data{

char pris_name[20];
char pris_id[10];
char pris_age[10];
char pris_gender[10];
char pris_hght[10];
char pris_wght[10];
char pris_eyeclr[10];
char pris_hairclr[10];
char pris_crime[20];
char pris_court[20];
char pris_lawyer[20];
char pris_punishs[10];
char pris_punishend[10];
char pris_relate[20];
char pris_bldtyp[10];	
}p;


int main(void){
	int ch;
	login();
	
	while (1){
		printf("\n\t*************************************************\n\n");
		printf("\t*\tWELCOME TO PRISON MANAGEMENT SYSTEM\t*\n\n");
		printf("\t*************************************************\n");
		printf("\n\n\t\tMAIN MENU:-");
		printf("\n\tAdd Prisoner Record-------(1)");
		printf("\n\tSearch Prisoner Record----(2)");
		printf("\n\tView Prisoner Record------(3)");
		printf("\n\tEdit Prisoner Record----(4)");
		printf("\n\tDelete Prisoner Record------(5)");
		printf("\n\tExit System---------------(6)");
		printf("\n\n\tEnter Choice:");
		
		scanf("%i",&ch);
		
		switch (ch){
			case 1:
				add();
				break;
			case 2:
				search();
				break;
			case 3:
				view();
				break;
			case 4:
				edit();
				break;
			case 5:
				delete_data();
				break;
			case 6:
				system("cls");
				printf("\n\n\tYou Have Exited The System.Good Luck.");
				getch();
				exit(0);
				
			default:
				printf("\n\n\tEnter The Correct Choice.\n\n\tPress Any Key To Continue.");
				getch();
				break;
		}
		
		system("cls");
	}
}

void login(){
	
	int tries=0,trials=0;			
	char user_n[100],gaps=' ';
	char password[20];
	char pass[20]="pass";
	char user[100]="user";
	
	do{
		printf("\n\t==========LOGIN==========");
		
		printf("\n\n\tEnter Username: ");
		scanf("%s",user_n);
		printf("\n\n\tEnter Password: ");
		
		while(tries<10){
			password[tries]=getch();
			gaps=password[tries];
			
			if (gaps==13){
				break;
			}
			else{
				printf("*");
				tries++;
			}
		}
		password[tries]='\0';
		
		tries=0;
		
			if(strcmp(user_n,"user")==0 && strcmp(password,"pass")==0){
				
				printf("\n\n\tLogin Successful.....Welcome To Prison Management System.");
				printf("\n\tPress ANY key to proceed.....");
				
				getch();
				break;
			}
			else{
				
				printf("\n\n\tLogin Unsuccessful......Try Again.");
				trials++;
				getch();
			}
	}while(trials<=2);
	
	if(trials>2){
		
		printf("\nYou have entered the wrong Username,or Password,or both consecutively!!");
		getch();
	}
	system("cls");
	
}		


void add(){
	
	system("cls");
	FILE*fp;

	char pris_id[10];
	char ans='Y';
	char first_name[20];
	int choice;
	
	
	printf("\n\t*************************\n\n");
	printf("\t*\tADD RECORD\t*\n\n");
	printf("\t*************************\n");
	printf("\n\n\tEnter The First Name Of The Prisoner: ");
	fflush(stdin);
	gets(first_name);
	
	fp=fopen("filename","ab+");
	
	if (fp==NULL){
		
		fp=fopen("filename","wb+");
		
		if (fp==NULL){
			printf("\nError In The System.\nPress Any Key To Exit.");
			getch();
			return;
		}
	}
	
	while (ans=='y' || ans=='Y'){
		
		choice=0;
		fflush(stdin);

		printf("\n\tEnter Prisoner's ID: ");
		scanf("%s",pris_id);
		
		rewind (fp);
		
		while (fread (&p,sizeof(p),1,fp) == 1){
			
			if (strcmp(p.pris_id,pris_id) == 0){
				printf("\n\n\tThe Record Already Exists In The Database.\n");
				choice=1;
			}
		}
		
		if (choice==0){
			strcpy(p.pris_id,pris_id);
			
			printf("\n\tEnter the prisoner's name: ");
			fflush(stdin);
			gets(p.pris_name);
			
			printf("\n\tEnter age: ");
			gets(p.pris_age);
			fflush(stdin);
			
			printf("\n\tEnter gender: ");
			gets(p.pris_gender);
			fflush(stdin);
			
			printf("\n\tEnter height(feet and inches): ");
			gets(p.pris_hght);
			fflush(stdin);
			
			printf("\n\tEnter weight(kg): ");
			gets(p.pris_wght);
			fflush(stdin);
			
			printf("\n\tEnter eye colour: ");
			gets(p.pris_eyeclr);
			fflush(stdin);
			
			printf("\n\tEnter hair colour: ");
			gets(p.pris_hairclr);
			fflush(stdin);
			
			printf("\n\tEnter blood-type: ");
			gets(p.pris_bldtyp);
			fflush(stdin);
			
			printf("\n\tEnter crime: ");
			gets(p.pris_crime);
			fflush(stdin);
			
			printf("\n\tEnter court: ");
			gets(p.pris_court);
			fflush(stdin);
			
			printf("\n\tEnter lawyer: ");
			gets(p.pris_lawyer);
			fflush(stdin);
			
			printf("\n\tEnter the starting date of punishment: ");
			gets(p.pris_punishs);
			fflush(stdin);
			
			printf("\n\tEnter the ending date of punishment: ");
			gets(p.pris_punishend);
			fflush(stdin);
			
			printf("\n\tEnter any relative (only one)(with phone no.): ");
			gets(p.pris_relate);
			fflush(stdin);
			
			fwrite ( &p, sizeof(p), 1,fp );
			printf("\n\tPrisoner's Record Has Been Added.\n");
		}
		printf("\n\tDo you wish to add another record?[Y/N]: ");
		fflush(stdin);
		ans = getch();
	}
	fclose (fp);
	printf("\nPress Any Key To Exit.....");
	getch();
}


void search( ){
	system("cls");
    FILE *fp;
    
    int character;
    char pris_id[20],choice,first_name[20];

    printf("\n\n\t\t****************************\n");
    printf("\t\t* SEARCH RECORD *");
    printf("\n\t\t****************************\n\n");

 do{
 	
 		printf("\n\tENTER THE PRISONER NAME TO BE SEARCHED:");
        fflush(stdin);
        gets(first_name);

        fp = fopen ( "filename", "rb" ) ;

    		printf("\n\tEnter The Prisoner's ID: ");
            gets(pris_id);
            
            system("cls");
            printf("\n\tPrisoner's Record is: ");
	
          	if(strcmpi(p.pris_id,pris_id)==0){
               
                printf("\n\tPrsioner's name: %s",p.pris_name);
                printf("\n\tPrsioner's ID: %s\n",p.pris_id);
                printf("\n\tPrsioner's Age: %s",p.pris_age);
                printf("\n\tPrsioner's Gender: %s",p.pris_gender);
                printf("\n\tPrsioner's Height: %s",p.pris_hght);
                printf("\n\tPrsioner's Weight: %s",p.pris_wght);
				printf("\n\tPrsioner's Eyecolour: %s",p.pris_eyeclr);
                printf("\n\tPrsioner's Haircolour: %s",p.pris_hairclr);
                printf("\n\tPrsioner's Court: %s",p.pris_court);
                printf("\n\tPrsioner's Crime: %s",p.pris_crime);
                printf("\n\tPrsioner's Lawyer: %s",p.pris_lawyer);
                printf("\n\tPrsioner's Starting Date Of Punishment: %s",p.pris_punishs);
                printf("\n\tPrsioner's Ending Date Of Punishment: %s",p.pris_punishend);
                printf("\n\tPrsioner's Relative (with phone number): %s",p.pris_relate);
                printf("\n\tPrsioner's Bloodtype is: %s\n",p.pris_bldtyp);
                }
           
           printf("\n\n\tContinue viewing?...[Y/N]: ");
           fflush(stdin);
           scanf("%c",&choice);

 }while(choice=='y'||choice=='Y');
 
   fclose(fp);
   
	getch();
    return ;
getch();

}


void view(){
	
	system("cls");
	FILE*fp;
	
	char first_name[100];
	
	printf("\n\n\t\t****************************\n");
    printf("\t\t* VIEW RECORD *");
    printf("\n\t\t****************************\n\n");
    
    fp=fopen ("filename","rb");
    rewind (fp);
    
    while ((fread(&p,sizeof(p),1,fp))==1){
    	
    	printf("\n\n\tPress the SPACE key to load other prisoners'\n");
    	printf("\n\tPrisoner's Name: %s",p.pris_name);
    	printf("\n\tPrisoner's ID: %s",p.pris_id);
        printf("\n\tPrisoner's Age: %s",p.pris_age);
        printf("\n\tPrisoner's Gender: %s",p.pris_gender);
        printf("\n\tPrisoner's Height: %s",p.pris_hght);
        printf("\n\tPrisoner's Weight: %s",p.pris_wght);
		printf("\n\tPrisoner's Eyecolour: %s",p.pris_eyeclr);
        printf("\n\tPrisoner's Haircolour:%s",p.pris_hairclr);
        printf("\n\tPrisoner's Crime: %s",p.pris_crime);
        printf("\n\tPrisoner's: Court: %s",p.pris_court);
        printf("\n\tPrisoner's Lawyer: %s",p.pris_lawyer);
        printf("\n\tPrisoner's Starting Date Of Punishment: %s",p.pris_punishs);
        printf("\n\tPrisoner's Ending Date Of Punishment: %s",p.pris_punishend);
        printf("\n\tPrisoner's Relative (phone-number): %s",p.pris_relate);
        printf("\n\tPrisoner's Bloodtype: %s\n\n",p.pris_bldtyp);
        getch();
	}
	
	fclose(fp);
	getch();
}


void edit(){

    system("cls");
    FILE *fp;
    
    int num,count=0;
    char pris_id[20],choice,first_name[15];

    printf("\n\t*************************\n\n");
	printf("\t*\tEDIT RECORD\t*\n\n");
	printf("\t*************************\n");
	
	  do
    {

        printf("\n\tEnter The Name Of The Prisoner To Be Edited: ");
        fflush(stdin);
        gets(first_name);

        printf("\n\tENTER Prisoner's' ID:");
    	gets(pris_id);
    	
        fp = fopen( "filename" , "rb+");
        
        while ( fread ( &p, sizeof (p), 1, fp ) == 1 )
        {

            if(strcmp(p.pris_id,pris_id)==0){
            	
            	printf("\n\tPrsioner's name: %s",p.pris_name);
                printf("\n\tPrsioner's ID: %s\n",p.pris_id);
                printf("\n\tPrsioner's Age: %s",p.pris_age);
                printf("\n\tPrsioner's Gender: %s",p.pris_gender);
                printf("\n\tPrsioner's Height: %s",p.pris_hght);
                printf("\n\tPrsioner's Weight: %s",p.pris_wght);
				printf("\n\tPrsioner's Eyecolour: %s",p.pris_eyeclr);
                printf("\n\tPrsioner's Haircolour: %s",p.pris_hairclr);
                printf("\n\tPrsioner's Court: %s",p.pris_court);
                printf("\n\tPrsioner's Crime: %s",p.pris_crime);
                printf("\n\tPrsioner's Lawyer: %s",p.pris_lawyer);
                printf("\n\tPrsioner's Starting Date Of Punishment: %s",p.pris_punishs);
                printf("\n\tPrsioner's Ending Date Of Punishment: %s",p.pris_punishend);
                printf("\n\tPrsioner's Relative (with phone number): %s",p.pris_relate);
                printf("\n\tPrsioner's Bloodtype is: %s\n",p.pris_bldtyp);
                
                 printf("\n\n\tSelect The Data To Be Edited: ");
                 
                printf("\n\tPrsioner's Name------(1)");
                printf("\n\tPrsioner's ID------(2)");
                printf("\n\tPrsioner's Age------(3)");
                printf("\n\tPrsioner's Gender------(4)");
                printf("\n\tPrsioner's Height------(5)");
                printf("\n\tPrsioner's Weight-------(6)");
				printf("\n\tPrsioner's Eyecolour------(7)");
                printf("\n\tPrsioner's Haircolour------(8)");
                printf("\n\tPrsioner's Court-------(9)");
                printf("\n\tPrsioner's Crime------(10)");
                printf("\n\tPrsioner's Lawyer------(11)");
                printf("\n\tPrsioner's Starting Date Of Punishment------(12)");
                printf("\n\tPrsioner's Ending Date Of Punishment------(13)");
                printf("\n\tPrsioner's Relative (with phone number)------(14)");
                printf("\n\tPrsioner's Bloodtype------(15)");
                printf("\n\tGo To Main Menu------(16)");
                
             do{

                    printf("\n\tEnter Your Choice: ");
                    fflush(stdin);
                    scanf("%i",&num);
                    fflush(stdin);

                    switch(num){

                    case 1:
                        printf("\n\tEnter The New Information:\n\tName: ");
                        gets(p.pris_name);
                        break;
						
				  	case 2:
                        printf("\n\tEnter The New Information:\n\tID: ");
                        gets(p.pris_id);
                        break;   
						     
                	case 3:
                        printf("\n\tEnter The New Information:\n\tAge: ");
                        gets(p.pris_age);
                        break;   
                        
                	case 4:
                        printf("\n\tEnter The New Information:\n\tGender: ");
                        gets(p.pris_gender);
                        break;   
                
                	case 5:
                        printf("\n\tEnter The New Information:\n\tHeight: ");
                        gets(p.pris_hght);
                        break;   
                        
                	case 6:
                        printf("\n\tEnter The New Information:\n\tWeight: ");
                        gets(p.pris_wght);
                        break;   
                        
                	case 7:
                        printf("\n\tEnter The New Information:\n\tEyecolour: ");
                        gets(p.pris_eyeclr);
                        break;   
                        
                	case 8:
                        printf("\n\tEnter The New Information:\n\tHaircolour: ");
                        gets(p.pris_hairclr);
                        break;   
                        
                	case 9:
                        printf("\n\tEnter The New Information:\n\tCourt: ");
                        gets(p.pris_court);
                        break;   
                        
                	case 10:
                        printf("\n\tEnter The New Information:\n\tCrime: ");
                        gets(p.pris_crime);
                        break;   
                        
                	case 11:
                        printf("\n\tEnter The New Information:\n\tLaywer: ");
                        gets(p.pris_lawyer);
                        break;   
                        
                	case 12:
                        printf("\n\tEnter The New Information:\n\tStarting Date Of Punishment: ");
                        gets(p.pris_punishs);
                        break;   
                        
                	case 13:
                        printf("\n\tEnter The New Information:\n\tEnding Date Of Punishment: ");
                        gets(p.pris_punishend);
                        break;   
                        
                	case 14:
                        printf("\n\tEnter The New Information:\n\tRelative (with phone number):");
                        gets(p.pris_relate);
                        break;   
                        
                	case 15:
                        printf("\n\tEnter The New Information:\n\tBloodtype: ");
                        gets(p.pris_bldtyp);
                        break;   
                        
                	case 16:
                        printf("\n\tGo To Main Menu...");
                        getch();
                        return;
                        break;
						
				 	default:
                        printf("\nError!Enter Valid Information...");
                        break;   
                    }
						
			    } while (num<1 || num>20);
			    
			    fseek(fp,-sizeof(p),SEEK_CUR);

                fwrite(&p,sizeof(p),1,fp);

                fseek(fp,-sizeof(p),SEEK_CUR);

                fread(&p,sizeof(p),1,fp);

                choice=5;
            

                break;
                
        	}
        }
        
		if(choice==5){

            system("cls");

            printf("\n\tEditing Complete...\n");
            printf("--------------------\n");
            
            printf("The Edited, new record is :\n");
            printf("--------------------\n");
        
        	printf("\n\tPrsioner's name: %s",p.pris_name);
            printf("\n\tPrsioner's ID: %s\n",p.pris_id);
            printf("\n\tPrsioner's Age: %s",p.pris_age);
            printf("\n\tPrsioner's Gender: %s",p.pris_gender);
            printf("\n\tPrsioner's Height: %s",p.pris_hght);
            printf("\n\tPrsioner's Weight: %s",p.pris_wght);
			printf("\n\tPrsioner's Eyecolour: %s",p.pris_eyeclr);
            printf("\n\tPrsioner's Haircolour: %s",p.pris_hairclr);
            printf("\n\tPrsioner's Court: %s",p.pris_court);
        	printf("\n\tPrsioner's Crime: %s",p.pris_crime);
            printf("\n\tPrsioner's Lawyer: %s",p.pris_lawyer);
            printf("\n\tPrsioner's Starting Date Of Punishment: %s",p.pris_punishs);
            printf("\n\tPrsioner's Ending Date Of Punishment: %s",p.pris_punishend);
            printf("\n\tPrsioner's Relative (with phone number): %s",p.pris_relate);
            printf("\n\tPrsioner's Bloodtype is: %s\n",p.pris_bldtyp);

			fclose(fp);

            printf("\n\nContinue Editing?.....(Y/N)");
            scanf("%c",&choice);
            count++;
        }
        
	else
        {

            printf("\nThe Mentioned Record Does Not Exist:\n");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
        	scanf("%c",&choice);

        }
        
    } while (choice== 'y' || choice== 'Y');
    
    fclose (fp);
    printf("\n\tPress Space To Exit Editing Menu.");
    getch();

}


void delete_data(){
	
	system("cls");
	
	FILE *fp,*filetemporary;
	struct data p;
	char first_name[100],ans='Y',pris_id[20];
	int choice,verify;
	int x=0;
	
	printf("\n\t*************************\n\n");
	printf("\t*\tDELETE RECORD\t*\n\n");
	printf("\t*************************\n");
	
	while (ans=='y' || ans=='Y'){
		
		printf("\n\tEnter the name of the prisoner to be deleted: ");
		fflush(stdin);
		gets(first_name);
		
		fp=fopen ("filename","rb");
		
		if(fp==NULL){
			
			printf("\n\tThe entered file does not exist in the database....");
			printf("\n\tPress SPACE to return to main menu.");
			getch;
			return;
			
		}
		filetemporary=fopen("temp","wb");
		
		if (filetemporary==NULL){
			
			printf("\n\tError in the system.....");
			printf("\n\n\tPress any key to go to main menu.");
			getch();
			return;
		}
		
		printf("\n\tEnter the ID of the prisoner record to be deleted.");
		fflush(stdin);
		gets(pris_id);
		
		while(fread(&p,sizeof(p),1,fp)==1){
            if(strcmp(p.pris_id,pris_id)!=0){
            	
                fwrite(&p,sizeof(p),1,filetemporary);
                
			}
        }
        fclose(filetemporary);
        fclose(fp);
        remove("filename");
        rename("temp","filename");
        printf("\n\tDeleting process successful");
        getch();
        
        printf("\n\tDelete another record?.....(Y/N): ");
        fflush(stdin);
        scanf("%c",&ans);
        
	}
	
	printf("\n\n\tPress SPACE to exit...");
	getch();

}
