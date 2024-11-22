#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<string.h>
#


include"rlutil.h"


typedef struct date
{
    int day,month,year;
}date;

typedef struct plane
{
    char ID[10] ;
    char state ;
    date fabrication ;
    int max_pass ;
    int assured_pass ;
    char company[10] ;

}plane;

struct nodeo
{
    plane pln ;
    struct nodeo* next ;
};
typedef struct nodeo node ;



//#-------------Remplissage---------------#

void Remplissage(int N)
{
    FILE*planes_file;
    plane x,y;
    char c[20],s[20],idf[20];
    char oui;
    bool condition;
    int i=0,j,ajoute;   /* <i> y7sb ch7al kayn mn avion*/
    planes_file = fopen("planes_file.txt","a");
    /*hna f le cas ida makach le fihcier bah ycreeh
    sinon le mod "r" ykfi mais lazm ycon y existe bah maysrawch des prblms*/
    fclose(planes_file);

    planes_file = fopen("planes_file.txt","r");
    while (fgets(s,100,planes_file)!=NULL)
    {
        i++;
    }
    fclose(planes_file);

    if ((N+i)>20)   /*ida l9a les avion m3a N > 20 */
    {

        if ((20-i)==0)  /*ida kan le fichier complet*/
        {
            cls();
            locate(15,10);  printf("����������������������������������������������������������������������������������������Ŀ");
            locate(15,11);  printf("�                                                                                        �");
            locate(15,12);  printf("�   ******* L'AEROPORT EST COMPLET, VOUS NE POUVES PAS AJOUTE UN AUTRE AVION ********    �");
            locate(15,13);  printf("�                                                                                        �");
            locate(15,14);  printf("������������������������������������������������������������������������������������������");

            locate(30,16); printf("Mais vous pouvez remplacer les avions decole de Lufthansa");

            getch(); locate(24,18);
        }
        else
        {
            /* hna drt suggestion ida 7ab y3mr le fichier 7tan le maximum*/



            cls();

            locate(15,7);   printf("��������������������������������������������������������������������������������������Ŀ");
            locate(15,8);   printf("�                                                                                      �");
            locate(15,9);   printf("�                                                                                      �");
            locate(15,10);  printf("�                                                                                      �");
            locate(15,11);  printf("�                                                                                      �");
            locate(15,12);  printf("�                                                                                      �");
            locate(15,13);  printf("�                                                                                      �");
            locate(15,14);  printf("�                                                                                      �");
            locate(15,15);  printf("�                                                                                      �");
            locate(15,16);  printf("�                                                                                      �");
            locate(15,17);  printf("�                                                                                      �");
            locate(15,18);  printf("�                                                                                      �");
            locate(15,19);  printf("�                                                                                      �");
            locate(15,20);  printf("����������������������������������������������������������������������������������������");
            locate(40,14);  printf("          /          /");
            locate(22,11);
            printf("IL RESTE %d PLACE SUR L'AEROPORT, VOUS VOULEZ AJOUTE CET NOMBRE DES AVIONS ?",20-i);

            setColor(10);
            locate(40,14); printf("Oui(O)");
            setColor(12);
            locate(53,14); printf("Non(N)");
            setColor(11);
            locate(66,14);printf("Autre Nemuro (A)");
            setColor(15);

            do
            {

                setColor(15);
                locate(55,17); printf("��>");
                locate(59,17);   oui = getchar();
                if (oui == 'O' || oui == 'o')
                {
                    N = 20-i;     /*hadi trd l N(nemero nta3 ch7al mn avion tzid) may5alinach njozu 20(max avions)*/
                    break;        /*    w haka tjouz direct le line 95        */
                }
                else if (oui == 'N' || oui == 'n') /*sinon y5ayer huwa nemuro li ysa3du ida 7ab*/
                {

                    cls();
                    locate(40,13); printf("----Aurevoir !----");
                    break;
                }

                else if (oui == 'A' || oui == 'a')
                {
                    cls();
                    do
                    {

                        setColor(15);
                        locate(45,14);
                        printf("VOTRE NEMURO : ");
                        locate(60,14);
                        setColor(11);
                        scanf("%d",&ajoute);
                        locate(60,14);printf("                        ");

                    } while (ajoute>20-i); /*lazm ycon <= nemero dyal suggestion*/
                    N = ajoute;
                    break;
                }

                else
                {
                    locate(55,17); printf("                                     ");
                }



            }while (1);    /* hadi wli fo9ha yt3awdu 7tan yd5l oui wla non*/
        }
    }

    if ((N+i) <= 20)
    {
        for (int k = 1; k <= N; k++)
        {

            cls();


    setColor(15);
    locate(25,3);  printf("��������������������������������������������������������������������Ŀ");
    locate(25,4);  printf("�                                                                    �");
    locate(25,5);  printf("�        �����������������>                <���������������ĳ        �");

    setColor(11);locate(55,5);printf("AVION N %d",i+k);
    setColor(15);
    locate(25,6);  printf("�                                                                    �");
    locate(25,7);  printf("��������������������������������������������������������������������ĳ");
    locate(25,8);  printf("�                                                                    �");
    locate(25,9);  printf("�      ��>   ID :                                                    �");
    locate(25,10); printf("�                                                                    �");
    locate(25,11); printf("�      ��>   ETAT :                                                  �");
    locate(25,12); printf("�                                                                    �");
    locate(25,13); printf("�      ��>   DATE DE FABRICATION :    jour / mois / annee            �");
    locate(25,14); printf("�                                                                    �");
    locate(25,15); printf("�      ��>   NOMBRE MAXIMAL DE VOYAGEURS :                           �");
    locate(25,16); printf("�                                                                    �");
    locate(25,17); printf("�      ��>   NOMBRE DE VOLS :                                        �");
    locate(25,18); printf("�                                                                    �");
    locate(25,19); printf("�      ��>   COMPAIGNIE A.A. :                                       �");
    locate(25,20); printf("�                                                                    �");
    locate(25,21); printf("����������������������������������������������������������������������");

    locate(30,23); printf(" NOTES : ");

            /* had la boucle tft7 le fichier ba3d ma ta9ra l' IDF
            ida l9atu fl le fichier ra7 t9lk 3awd da5l
            ida mal9atuch ra7 tsauvgardih m3a li kayn
            w fl 5atra jaya IDF hada yd5l fl7sab*/

            locate(43,23);
            printf("L'identifiant de l'avion");

            IDF :
            j = 0;
            do
            {

                if (j > 0)
                {
                    locate(47,26);
                    setColor(12);
                    printf("��>Entree un unique ID<��");
                }

                setColor(11);
                locate(44,9);
                printf("                                          ");
                locate(44,9);
                scanf("%s",s);
                condition = false;
                fopen("planes_file.txt","r");
                while (!feof(planes_file) && condition == false)
                {
                    fscanf(planes_file,"%s %c %d %d %d %d %d %s",y.ID,&y.state,&y.fabrication.day,&y.fabrication.month,&y.fabrication.year,&y.max_pass,&y.assured_pass,y.company);

                    if (strcmp(y.ID,s)==0)
                    {
                        condition = true; /* ida l9atu f le fichier*/
                    }
                }
                fclose(planes_file);
                j = 1;
            } while (condition == true); /*ida kant true tsma aw kayn twli t3awd domondi wa7d jdid*/

            locate(47,26); printf("                          ");
            strcpy(x.ID,s);


             //-------Etat-------//


            j = 0;
            locate(43,23);
            setColor(15);
            printf("'A': Atterit , 'M': Maintenance , 'D': Decolle");
            do
            {
                if (j>0)
                {
                    locate(50,26);
                    setColor(12);
                    printf("��>Invalid Etat<��");

                }
                setColor(11);
                locate(46,11);
                printf("                                          ");
                locate(46,11);
                scanf("%s",&x.state);
                j = 1;
            } while (x.state != 'D' && x.state != 'A' && x.state != 'M'); /*hna ida l9at caractere 5laf t3awd*/

            locate(50,26);
            printf("                                                                      ");
            locate(43,23);
            printf("                                                                      ");

            //-------Date de Fabrication-------//
//-----------------------------------------------------------------\\

            locate(43,23);
            setColor(15);
            printf("Les dates incorrectes sera refuse !");
            // jour --------------------------------------------
            setColor(11);
            j = 0;
            do
            {
                 if (j > 0)
                {
                    locate(50,26);
                    setColor(12);
                    printf("��>Date Impossible<��");
                }
                locate(62,13);
                printf("     ");
                locate(63,13);
                setColor(11);
                scanf("%d",&x.fabrication.day);
                j = 1;
            } while (x.fabrication.day<1 || x.fabrication.day>31);

            locate(50,26);
            printf("                             ");

            // mois --------------------------------------------------
            j = 0;
            Mois :
            setColor(11);
            do
            {
                if (j > 0)
                {
                    locate(50,26);
                    setColor(12);
                    printf("��>Date Impossible<��");
                }
                locate(69,13);
                printf("     ");
                locate(71,13);
                setColor(11);
                scanf("%d",&x.fabrication.month);
                j = 1;
            } while (x.fabrication.month<1 || x.fabrication.month>12);

            // Pour fevrier ---------------------------------------------------------------

            while (x.fabrication.day>29 || x.fabrication.month<1 || x.fabrication.month>12)
            {

                locate(50,26);
                setColor(12);
                printf("��>Date Impossible<��");

                setColor(11);
                if (x.fabrication.month == 2)
                {

                    locate(69,13);
                    printf("     ");
                    locate(71,13);
                    scanf("%d",&x.fabrication.month);
                }
                else if (x.fabrication.day == 30 && x.fabrication.month != 2 && x.fabrication.month >= 1 && x.fabrication.month <= 12)
                {
                    goto Annee; // Parceque 30 est entre 29 et 31. pour cela j'ai utilise la fonction goto

                }

                // Pour les mois qui ont 30 jours -------------------------------------------------

                else if (x.fabrication.day>30 || x.fabrication.month<1 || x.fabrication.month>12)
                {
                        // le mois faut = 1 || 3 || 5 || 7 || 8 || 10 || 12
                        if (x.fabrication.month == 4 || x.fabrication.month == 6 || x.fabrication.month == 9 || x.fabrication.month == 11)
                        /* l'utilisateur peu aussi ecrit 30 comme une mois
                        pour cela, soit on utlilise dans if les mois (1,3,5,7,8,10,12) ou la fonction goto*/
                        {

                            locate(69,13);
                            printf("     ");
                            locate(71,13);
                            scanf("%d",&x.fabrication.month);
                        }
                        else if (x.fabrication.month>=1 && x.fabrication.month<=12)

                            goto Annee; // Sinon le programme sera bloque

                        else
                            goto Mois;  // ( Lire bien la ligne 279)

                }
            }


            Annee:
            locate(50,26);
            printf("                             ");
            j = 0;
            do
            {
                if (j > 0)
                {
                    locate(50,26);
                    setColor(12);
                    printf("��>Date Impossible<��");

                }
                locate(76,13);
                printf("             ");
                locate(77,13);
                setColor(11);
                scanf("%d",&x.fabrication.year);
                j=1;
            } while (x.fabrication.year<1903 || x.fabrication.year>2022);

            locate(50,26);
            printf("                             ");

            //---------------------------------------------------//
            // 'annee bissextile' <=> 'fevrier = 29 jours'
            //---------------------------------------------------//

            /* -- comment savoir si une annee est bissextile ou pas ? --
            --> chaque 4 ans, il y a une annee bissextile
            je ne sais pas est-ce-que ca venu par hasard ou non, mais :
            -- annee bissextile % 4 = 0,  (cet possibilite est 1/4) --
            -> est donc le calcul est facile-------------------------*/

            /*cet instruction travail quand l'annee n'est pas bissextile
            par exemple 29 / 2 / 2022 une date qui n'existe pas, car 2022 mod 4 != 0*/

            if (x.fabrication.month == 2 && x.fabrication.day == 29 && x.fabrication.year % 4 != 0)
            {
                while (x.fabrication.year<1903 || x.fabrication.year>2022 || x.fabrication.year % 4 != 0)
                {

                    locate(50,26);
                    setColor(12);
                    printf("��>Date Impossible<��");
                    locate(76,13);
                    printf("              ");
                    locate(77,13);
                    setColor(11);
                    scanf("%d",&x.fabrication.year);
                }

            }
            locate(48,26);
            printf("                                                              ");
            locate(43,23);
            printf("                                                              ");

            //-------Nombre Maximal de Voyageurs-------//
            setColor(15);
            locate(43,23);
            printf("Airbus A380 est le grand avion sur le moment,");
            locate(57,24);
            printf("il a 615 place.");
            setColor(11);
            j = 0;
             do
            {

                if (j > 0 )
                {
                    if (x.max_pass == 0)
                    {
                        locate(50,26);
                        setColor(12);
                        printf("��>Qui vole l'avion !!<��");
                    }
                    else
                    {
                        locate(50,26);
                        setColor(12);
                        printf("��>Lire bien la note !<��");
                    }
                }
                locate(69,15);
                printf("                ");
                locate(69,15);
                setColor(11);
                scanf("%d",&x.max_pass);
                j = 1;
            } while (x.max_pass<1 || x.max_pass>615);

            locate(43,23);
            printf("                                                                ");
            locate(50,26);
            printf("                                           ");
            locate(50,24);
            printf("                                           ");

            //-------Nombre de Vols-------//


            locate(43,23);
            setColor(15);
            printf(" Nombre de vols assures pour cet avion");
            locate(56,17);
            printf("                 ");
            locate(56,17);
            setColor(11);
            scanf("%d",&x.assured_pass);
            locate(43,23);
            printf("                                              ");

            //-------Compagnie Aerienne-------//

            locate(43,23);
            setColor(15);
            printf(" Compagnie aerienne d'affiliation de cet avion");
            locate(57,19);
            setColor(11);
            scanf("%s",s);
            strcpy(x.company,s);


             //-------Le Remplissage sur le fichier-------//

            fopen("planes_file.txt","a");
            if (i+k == 1)
            {
                fprintf(planes_file,"%s %c %d %d %d %d %d %s",x.ID,x.state,x.fabrication.day,x.fabrication.month,x.fabrication.year,x.max_pass,x.assured_pass,x.company);
            }
            else
                fprintf(planes_file,"\n%s %c %d %d %d %d %d %s",x.ID,x.state,x.fabrication.day,x.fabrication.month,x.fabrication.year,x.max_pass,x.assured_pass,x.company);

            fclose(planes_file);


        }
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------

void present()
{
    plane P ;

    char s[20];

    int i=0,j;
    int found = 0 ;

    FILE *planes_file ;


    cls();

    //dessin des bordures AKA Ui

    setColor(15);
    gotoxy(25,3);  printf("|��������������������������������������������������������������������|");
    gotoxy(25,4);  printf("�                                                                    �");
    gotoxy(25,5);  printf("���������������������>>                      <<������������������������");

    setColor(11);gotoxy(49,5);printf("VERIFICATION D'AVION");
    setColor(15);
    gotoxy(25,6);  printf("|                                                                    |");
    gotoxy(25,7);  printf("|��������������������������������������������������������������������|");
    gotoxy(25,8);  printf("|                                                                    |");
    gotoxy(25,9);  printf("|                                                                    |");
    gotoxy(25,10); printf("|                                                                    |");
    gotoxy(25,11); printf("|                                                                    |");
    gotoxy(25,12); printf("|                                                                    |");
    gotoxy(25,13); printf("|                                                                    |");
    gotoxy(25,14); printf("|                     -->   ID :                                     |");
    gotoxy(25,15); printf("|                                                                    |");
    gotoxy(25,16); printf("|                                                                    |");
    gotoxy(25,17); printf("|                                                                    |");
    gotoxy(25,18); printf("|                                                                    |");
    gotoxy(25,19); printf("|                                                                    |");
    gotoxy(25,20); printf("|                                                                    |");
    gotoxy(25,21); printf("|��������������������������������������������������������������������|");



    setColor(11);
    gotoxy(59,14);
    printf("                                 ");
    gotoxy(63,14);
    scanf("%s",s); //scan du identificateur

    planes_file = fopen("planes_file.txt","r");
    hidecursor();

    //rechercher d'avion et indiquer ca presence

    while (fscanf(planes_file,"%s %c %d %d %d %d %d %[^\n]%*c",&P.ID ,&P.state ,&P.fabrication.year ,
    &P.fabrication.month ,&P.fabrication.day ,&P.max_pass ,&P.assured_pass ,&P.company)!=EOF && found==0)
    {

        if (strcmp(P.ID,s)==0)
        {
            if (P.state != 'D')
            {
                cls();
                locate(35,14);
                setColor(BLACK);
                setBackgroundColor(LIGHTCYAN);
                hidecursor();
                printf("YOUR PLANE HAS THE ID OF '%s' , WE FOUND IT SIR !",P.ID);
                msleep(3000);
                cls();
                found = 1 ;
            }

        }

    }
    cls();
    if(found == 0)
    {

        gotoxy(46,14);
        setColor(BLACK);
        setBackgroundColor(LIGHTRED);
        printf("  sorry we didn't find it !!  ");
        msleep(3000);
        cls();
    }


    fclose(planes_file);

}



//---------------------------------------------------------------------------------------------------------------------------------------------------
node *ToLinkedList(int graphics)
{

/*
evolution de la linked :

oldest�planes -> NULL
oldest�planes -> assured_pass SUP 109 -> NULL
oldest�planes -> assured_pass SUP 109 -> air�france�planes -> NULL
rest�of�planes -> oldest�planes -> assured_pass SUP 109 -> air�france -> NULL

*/


    //chercher l'avion plus anciennce
    plane P , G;
    hidecursor();
    date oldest ;
    FILE *planes_file ;
    planes_file = fopen("planes_file.txt","r");
;

    fscanf(planes_file,"%s %c %d %d %d %d %d %[^\n]%*c",&P.ID ,&P.state ,&P.fabrication.year ,    &P.fabrication.month ,&P.fabrication.day ,&P.max_pass ,&P.assured_pass ,&P.company);

    oldest = P.fabrication ;

    while(fscanf(planes_file,"%s %c %d %d %d %d %d %[^\n]%*c",&P.ID ,&P.state ,&P.fabrication.year ,
    &P.fabrication.month ,&P.fabrication.day ,&P.max_pass ,&P.assured_pass ,&P.company)!=EOF)
    {

        if (P.fabrication.year < oldest.year)
        {
            oldest = P.fabrication ;
        }
        else if(P.fabrication.year == oldest.year)
            {
                if (P.fabrication.month < oldest.month)
                {
                    oldest = P.fabrication ;
                }

                else if (P.fabrication.month == oldest.month)
                    {
                        if (P.fabrication.day <= oldest.day)
                        {
                            oldest = P.fabrication ;

                        }
                    }

            }

    }


    fclose(planes_file);
    planes_file = fopen("planes_file.txt","r");

    //les trois premier insertions sont de method FIFO

    node *header , *nd ;
    header = NULL ;
    int i = 0;

    /*------1--------*/
    //inserer les avions plus ancienne

    while (fscanf(planes_file,"%s %c %d %d %d %d %d %[^\n]%*c",&P.ID ,&P.state ,&P.fabrication.year,
    &P.fabrication.month ,&P.fabrication.day ,&P.max_pass ,&P.assured_pass ,&P.company)!=EOF)
    {
        if(P.fabrication.year == oldest.year && P.fabrication.month == oldest.month && P.fabrication.day == oldest.day )
        {
            //insertion du premier element
            if (i == 0)
            {
                nd = NULL ;
                header = malloc(sizeof(node));
                header->pln = P ;
                header->next = nd ;
                nd = header ;
                i += 1 ;
            }
            nd->next = malloc(sizeof(node)) ;
            nd = nd->next ;
            nd->pln = P ;
            nd->next = NULL ;

        }
    }

    fclose(planes_file);
    planes_file = fopen("planes_file.txt","r");



    /*-------2-----*/
    //ajouter les avions avec max passangers superieur de 109

    while(fscanf(planes_file,"%s %c %d %d %d %d %d %[^\n]%*c",&P.ID ,&P.state ,&P.fabrication.year ,
    &P.fabrication.month ,&P.fabrication.day ,&P.max_pass ,&P.assured_pass ,&P.company)!=EOF)
    {
        if (strcmp(P.company ,"air france") !=0 && P.assured_pass > 109 && P.fabrication.year != oldest.year && P.fabrication.month != oldest.month && P.fabrication.day != oldest.day)
        {
            nd->next = malloc(sizeof(node)) ;
            nd = nd->next ;
            nd->pln = P ;
            nd->next = NULL ;

        }
    }
    fclose(planes_file);
    planes_file = fopen("planes_file.txt","r");

    /*------3--------*/
    //ajouter les avions de "air france"

    while (fscanf(planes_file,"%s %c %d %d %d %d %d %[^\n]%*c",&P.ID ,&P.state ,&P.fabrication.year ,
    &P.fabrication.month ,&P.fabrication.day ,&P.max_pass ,&P.assured_pass ,&P.company)!=EOF)
    {
        if (strcmp(P.company ,"air france")==0 && P.fabrication.year != oldest.year && P.fabrication.month != oldest.month && P.fabrication.day != oldest.day)
        {
            nd->next = malloc(sizeof(node)) ;
            nd = nd->next ;
            nd->pln = P ;
            nd->next = NULL ;
        }

    }

    fclose(planes_file);
    planes_file = fopen("planes_file.txt","r");
    /*------4--------*/
    //les dernier avions a ajouter sont le rest des avions
    //et pout ceci on vas utiliser la method "LAST IN FIRST OUT"

    node *inter ;

    while(fscanf(planes_file,"%s %c %d %d %d %d %d %[^\n]%*c",&P.ID ,&P.state ,&P.fabrication.year ,
    &P.fabrication.month ,&P.fabrication.day ,&P.max_pass ,&P.assured_pass ,&P.company)!=EOF)
    {
        if (P.assured_pass < 110 && strcmp(P.company ,"air france") !=0 && P.fabrication.year != oldest.year && P.fabrication.month != oldest.month && P.fabrication.day != oldest.day)
        {
            inter = malloc(sizeof(node)) ;
            inter->pln = P ;
            inter->next = header ;
            header = inter ;
        }
    }

    fclose(planes_file);

    nd = header;

    if(graphics==1) //si la fonction sera utiliser par une autre fonciton on doit entrer 0 comme indicateur de ne pas
                     //utiliser l'interface graphique
    {

        locate(35,12);
        printf("  HEY THRE ! | planes are ordered by company like :");
        locate(3,15);
        setBackgroundColor(WHITE);
        setColor(BLACK);
        while(nd != NULL)
        {
            printf("%s-> ",nd->pln.company);
            nd = nd->next ;
        }
        resetColor();
        msleep(2000);
        cls();
        nd = header ;


        printf("�����������������������������������������������������������������������������������������������������������������������\n");
        setColor(LIGHTCYAN);
        printf("ID         |state| year  |     month       |        day      |    passangers    |      pass    |    company   \n");
        setColor(WHITE);
        printf("�����������������������������������������������������������������������������������������������������������������������\n\n");

        while(nd != NULL)
        {
            setColor(GREEN);
            printf("%s      |  %c  |%5d  |%10d       |%10d       |%10d        |%10d       |   %s \n",nd->pln.ID ,nd->pln.state ,nd->pln.fabrication.year , nd->pln.fabrication.month , nd->pln.fabrication.day ,nd->pln.max_pass , nd->pln.assured_pass ,nd->pln.company );
            printf("������������������������������������������������������������������������������������������������������������������������\n");
            setColor(WHITE);
            nd = nd->next ;
        }

    }

    return header ;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------

void scinder(node**decolle,node**atterrit,node**maintenance)
{
    *decolle=NULL;
    *atterrit=NULL;
    *maintenance=NULL;
    node*p,*J,*l;
    l=ToLinkedList(0);
    // scinder vas inserer les tetes des listes dans un vecteur des tetes qui est un var globale
    p=l;
    while(p!=NULL){
        if(p->pln.state=='D'){
            J=malloc(sizeof(node));
            J->pln=p->pln;
            J->next=*decolle;
            *decolle=J;
        }
        p=p->next;
    }
    p=l;
    while(p!=NULL){
        if(p->pln.state=='A'){
            J=malloc(sizeof(node));
            J->pln=p->pln;
            J->next=*atterrit;
            *atterrit=J;
        }
        p=p->next;
    }
    p=l;
    while(p!=NULL){
        if(p->pln.state=='M'){
            J=malloc(sizeof(node));
            J->pln=p->pln;
            J->next=*maintenance;
            *maintenance=J;
        }
        p=p->next;
    }



}
void afiche(node *nd){
 while(nd!= NULL){
     printf("%s      |  %c  |%5d  |%10d       |%10d       |%10d        |%10d       |   %s \n",nd->pln.ID ,nd->pln.state ,nd->pln.fabrication.year , nd->pln.fabrication.month , nd->pln.fabrication.day ,nd->pln.max_pass , nd->pln.assured_pass ,nd->pln.company );
     nd = nd->next;
 }
 }

//---------------------------------------------------------------------------------------------------------------------------------------------------
void ToFile()  // la fonction ToFile pour transformer les 3 listes  3 fichier .l'entree est le tableau des tetes  puis afficher.
{
    node*decolle1;
    node*atterrit1;
    node*maintenance1;
    scinder(&decolle1,&atterrit1,&maintenance1) ;

    plane pln;
    FILE *decolle , *atterrie , *maintenance ;


    decolle = fopen("decolle.txt","w");
    atterrie = fopen("atterrie.txt","w");
    maintenance = fopen("maintenance.txt","w");

    while (decolle1 != NULL || atterrit1 != NULL || maintenance1 != NULL) //si les listes ne sont pas vides avec un ou entre eux
    {
        if (decolle1 != NULL) // si la liste n'est pas vide ecrire dans le fichier puis avancer la tete pour recuperer  les information de l'avion suivant
        {
            fprintf(decolle ,"%s %c %d %d %d %d %d %s\n", decolle1->pln.ID , decolle1->pln.state , decolle1->pln.fabrication.year ,
            decolle1->pln.fabrication.month , decolle1->pln.fabrication.day , decolle1->pln.max_pass , decolle1->pln.assured_pass ,decolle1->pln.company) ;
            decolle1=decolle1->next;

        }
        if (atterrit1 != NULL)
        {
            fprintf(atterrie ,"%s %c %d %d %d %d %d %s\n", atterrit1->pln.ID , atterrit1->pln.state , atterrit1->pln.fabrication.year ,
            atterrit1->pln.fabrication.month , atterrit1->pln.fabrication.day , atterrit1->pln.max_pass , atterrit1->pln.assured_pass ,atterrit1->pln.company) ;
            atterrit1=atterrit1->next;
        }
        if (maintenance1 != NULL)
        {
            fprintf(maintenance ,"%s %c %d %d %d %d %d %s\n", maintenance1->pln.ID , maintenance1->pln.state , maintenance1->pln.fabrication.year ,
            maintenance1->pln.fabrication.month , maintenance1->pln.fabrication.day , maintenance1->pln.max_pass , maintenance1->pln.assured_pass ,maintenance1->pln.company) ;
            maintenance1=maintenance1->next;
        }


    }
    fclose(decolle);//fermer les fichiers
    fclose(atterrie);
    fclose(maintenance);

    	cls();// effacer l'ecrant puis afichier les fichier dans l'order D A M
        decolle = fopen("decolle.txt","r");
        printf("�����������������������������������������������������������������������������������������������������������������������\n");
        setColor(BLUE);
        printf("ID         |state| year  |     month       |        day      |    passangers    |      pass    |    company   \n");
        setColor(WHITE);
        printf("�����������������������������������������������������������������������������������������������������������������������\n");
        while (fscanf(decolle,"%s %c %d %d %d %d %d %[^\n]%*c \n",pln.ID ,&pln.state ,&pln.fabrication.year ,
            &pln.fabrication.month ,&pln.fabrication.day ,&pln.max_pass ,&pln.assured_pass ,pln.company)!=EOF)
        {
            setColor(GREEN);
            printf("%s      |  %c  |%5d  |%10d       |%10d       |%10d        |%10d       |   %s \n",pln.ID ,pln.state ,pln.fabrication.year , pln.fabrication.month , pln.fabrication.day ,pln.max_pass , pln.assured_pass ,pln.company );
            printf("������������������������������������������������������������������������������������������������������������������������\n");
            setColor(WHITE);

        }
        fclose(decolle);
        atterrie = fopen("atterrie.txt","r");
        printf("�����������������������������������������������������������������������������������������������������������������������\n");
        setColor(BLUE);
        printf("ID         |state| year  |     month       |        day      |    passangers    |      pass    |    company   \n");
        setColor(WHITE);
        printf("�����������������������������������������������������������������������������������������������������������������������\n");
        while (fscanf(atterrie,"%s %c %d %d %d %d %d %[^\n]%*c \n",pln.ID ,&pln.state ,&pln.fabrication.year ,
            &pln.fabrication.month ,&pln.fabrication.day ,&pln.max_pass ,&pln.assured_pass ,pln.company)!=EOF)
        {
            setColor(GREEN);
            printf("%s      |  %c  |%5d  |%10d       |%10d       |%10d        |%10d       |   %s \n",pln.ID ,pln.state ,pln.fabrication.year , pln.fabrication.month , pln.fabrication.day ,pln.max_pass , pln.assured_pass ,pln.company );
            printf("������������������������������������������������������������������������������������������������������������������������\n");
            setColor(WHITE);

        }
        fclose(atterrie);
        maintenance = fopen("maintenance.txt","r");
        printf("�����������������������������������������������������������������������������������������������������������������������\n");
        setColor(BLUE);
        printf("ID         |state| year  |     month       |        day      |    passangers    |      pass    |    company   \n");
        setColor(WHITE);
        printf("�����������������������������������������������������������������������������������������������������������������������\n");
        while (fscanf(maintenance,"%s %c %d %d %d %d %d %[^\n]%*c \n",pln.ID ,&pln.state ,&pln.fabrication.year ,
            &pln.fabrication.month ,&pln.fabrication.day ,&pln.max_pass ,&pln.assured_pass ,pln.company)!=EOF)
        {
            setColor(GREEN);
            printf("%s      |  %c  |%5d  |%10d       |%10d       |%10d        |%10d       |   %s \n",pln.ID ,pln.state ,pln.fabrication.year , pln.fabrication.month , pln.fabrication.day ,pln.max_pass , pln.assured_pass ,pln.company );
            printf("������������������������������������������������������������������������������������������������������������������������\n");
            setColor(WHITE);

        }
        fclose(maintenance);
}


//---------------------------------------------------------------------------------------------------------------------------------------------------

void planesmax100(){
    node*decolle1;
    node*atterrit1;
    node*maintenance1;
    scinder(&decolle1,&atterrit1,&maintenance1) ;
    node*nd = atterrit1; //attacher nd a la tete du list qui contien les avions atterris
    printf("�����������������������������������������������������������������������������������������������������������������������\n");
    setColor(BLUE);
    printf("ID         |state| year  |     month       |        day      |    passangers    |      pass    |    company   \n");
    setColor(WHITE);
    printf("�����������������������������������������������������������������������������������������������������������������������\n");
    while(nd!=NULL){ // traverse jusqu'a la fin de la liste chainee
        if(nd->pln.max_pass<=100     )
        {
            setColor(GREEN);
            printf("%s      |  %c  |%5d  |%10d       |%10d       |%10d        |%10d       |   %s \n",nd->pln.ID ,nd->pln.state ,nd->pln.fabrication.year , nd->pln.fabrication.month , nd->pln.fabrication.day ,nd->pln.max_pass , nd->pln.assured_pass ,nd->pln.company );
            printf("������������������������������������������������������������������������������������������������������������������������\n");
            setColor(WHITE);

        }
        nd = nd->next; //incrementation
    }

}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void planesbeforejuin2018(){
	node* nd = ToLinkedList(0); // attacher nd a la tete du list qui contien tout les avions

    printf("�����������������������������������������������������������������������������������������������������������������������\n");
    setColor(LIGHTCYAN);
    printf("ID         |state| year  |     month       |        day      |    passangers    |      pass    |    company   \n");
    setColor(WHITE);
    printf("�����������������������������������������������������������������������������������������������������������������������\n\n");

	while(nd!=NULL){ // traverse jusqu'a la fin de la liste chainee
		if(nd->pln.fabrication.year<=2018 && nd->pln.fabrication.month<=6)
        {
            setColor(GREEN);
            printf("%s      |  %c  |%5d  |%10d       |%10d       |%10d        |%10d       |   %s \n",nd->pln.ID ,nd->pln.state ,nd->pln.fabrication.year , nd->pln.fabrication.month , nd->pln.fabrication.day ,nd->pln.max_pass , nd->pln.assured_pass ,nd->pln.company );
            printf("������������������������������������������������������������������������������������������������������������������������\n");
            setColor(WHITE);


		}
        nd = nd->next; //incrementation

	}
}



//---------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------Sup--------------------------//

node *Sup (node *L)
{
    node *Q , *P;

    if (L != NULL)
    {
        P = L;
        /* ------CAS 1------- (ida kant Lufthansa f debut )
        Lazem la tete tkun m3a avion 5laf */

        while (strcmp(P->pln.company,"Lufthansa") == 0 || P == NULL)
        {
            L = P->next;
            free(P);
            P = L;
        }

        /* ------CAS 2------- (ida kant Lufthansa machi f debut )*/

        Q = L;
        while (P != NULL)
        {
            if (strcmp(P->pln.company,"Lufthansa") == 0)
            {
                Q->next = P->next;
                free(P);
                P = Q->next;
            }
            else
            {
                Q = P;
                P = P->next;
            }
        }
    }

    else
        printf("La liste est vide ! \n");

    return L;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------


typedef struct task
{
    char fun[30];
}task;

task ligne[6];
int j,i,N;
char k;
node*head[3];

int main()
{

    node*zed;
    zed=ToLinkedList(0);
    node*decolle1;
    node*atterrit1;
    node*maintenance1;
    scinder(&decolle1,&atterrit1,&maintenance1) ;;

        head[0] = Sup (head[0]);

        hidecursor();

        strcpy(ligne[0].fun,"AJOUTER DES AVIONS");
        strcpy(ligne[1].fun,"VERIFIER LA PRESENCE");
        strcpy(ligne[2].fun,"DISPLAY BY ROAF METHOD");
        strcpy(ligne[3].fun,"AFFICHER BY DAME");
        strcpy(ligne[4].fun,"AFFICHER AVANT 06/2018");
        strcpy(ligne[5].fun,"AFFICHER ATTERIT (AU PLUS 100)");


        start :
        i = 0;
        j = 0;
        setBackgroundColor(0);
        setColor(15);
        cls();
        locate(25,3);  printf("��������������������������������������������������������������������Ŀ");
        locate(25,4);  printf("�                                                                    �");
        locate(25,5);  printf("�       �����������������> POWERED BY IONSI <���������������ĳ       �");
        locate(25,6);  printf("�                                                                    �");
        locate(25,7);  printf("��������������������������������������������������������������������ĳ");
        locate(25,8);  printf("�                                                                    �");
        locate(25,9);  printf("�                                                                    �");
        locate(25,10); printf("�            AJOUTER DES AVIONS                                      �");
        locate(25,11); printf("�                                                                    �");
        locate(25,12); printf("�            VERIFIER LA PRESENCE                                    �");
        locate(25,13); printf("�                                                                    �");
        locate(25,14); printf("�            DISPLAY BY ROAF METHOD                                  �");
        locate(25,15); printf("�                                                                    �");
        locate(25,16); printf("�            AFFICHER BY DAME                                        �");
        locate(25,17); printf("�                                                                    �");
        locate(25,18); printf("�            AFFICHER AVANT 06/2018                                  �");
        locate(25,19); printf("�                                                                    �");
        locate(25,20); printf("�            AFFICHER ATTERIT (AU PLUS 100)                          �");
        locate(25,21); printf("�                                                                    �");
        locate(25,22); printf("����������������������������������������������������������������������");

        //-----------------------------------------------------------------------------------------------\\

        setBackgroundColor(15);
        setColor(0);
        locate(35,10);
        printf(" > %s ",ligne[0].fun);



        while(1)
        {



            k=getkey();


            if(k==KEY_DOWN)
            {

                if(i+10 != 20)
                {

                    setBackgroundColor(15);
                    setColor(0);
                    locate(35,10+i+2);
                    printf(" > %s ",ligne[(j%5)+1].fun);


                    setBackgroundColor(0);
                    setColor(15);
                    locate(34,10+i);
                    printf("                                            ");


                    locate(37,10+i);
                    printf("%s",ligne[(j%5)].fun);
                    i = i+2;
                    j++;

                }
                else
                {

                    setBackgroundColor(0);
                    setColor(15);
                    locate(34,20);
                    printf("                                            ");
                    locate(37,10+i);
                    printf("%s",ligne[5].fun);

                    setBackgroundColor(15);
                    setColor(0);
                    locate(35,10);
                    printf(" > %s ",ligne[0].fun);

                    i = 0;
                    j=0;
                }

            }


            else if(k==KEY_UP)
            {
                if(i != 0)
                {

                    setBackgroundColor(15);
                    setColor(0);
                    locate(35,10+i-2);
                    printf(" > %s ",ligne[(j%6)-1].fun);


                    setBackgroundColor(0);
                    setColor(15);
                    locate(34,10+i);
                    printf("                                            ");


                    locate(37,10+i);
                    printf("%s",ligne[(j%6)].fun);
                    i = i-2;
                    j--;


                }
                else
                {

                    setBackgroundColor(0);
                    setColor(15);
                    locate(34,10);
                    printf("                                            ");
                    locate(37,10);
                    printf("%s",ligne[0].fun);

                    setBackgroundColor(15);
                    setColor(0);
                    locate(35,20);
                    printf(" > %s ",ligne[5].fun);

                    i = 10;
                    j=5;
                }


            }
            else if(k==KEY_ENTER)
                {
                    switch (j)
                    {
                    case 0:
                        cls();
                        setBackgroundColor(0);
                        setColor(15);

                        do{
                        printf("//--Donnez le nombre des avions : ");
                        scanf("%d",&N);
                        } while (N>20 || N<1);
                        Remplissage(N);
                        cls();


                        j = 0 ;

                        break;

                    case 1:
                        cls();
                        present();
                        j = -1 ;
                        break;

                    case 2:
                        cls();
                        ToLinkedList(1);
                        j = -1 ;
                        break;

                    case 3:
                        cls();
                        ToFile();
                        j = -1 ;
                        break;

                    case 4:
                        cls();
                        planesbeforejuin2018();
                        j = -1 ;
                        break;

                    case 5:
                        cls();
                        planesmax100();
                        j = -1 ;
                        break;



                    default:
                        break;
                    }
                getkey();
                goto start;


            }
        }
}
