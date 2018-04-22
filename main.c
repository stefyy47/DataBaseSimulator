#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct angajat
{
    int id_angajat;
    int id_banca;
    int rang_angajat;
    int salariu_angajat;
    char nume_angajat[16];
    char prenume_angajat[32];
    char telefon_angajat[10];
};
struct client
{
    int id_client;
    int tip_credit;
    char nume_client[16];
    char prenume_client[32];
    char telefon_client[10];
    char email_client[20];

};
struct banca
{
    char adresa_banca[20];
    int credit_banca;
    int zi_lucratoare:1;
    int id_banca;
};
union bancomat
{
    char adresa_bancomat[20];
    unsigned int camera_de_luat_vederi:1;
    int credit_bancomat;


};
struct credit
{
    int tip_credit;
    int valoare_credit;
    int durata_credit;
    int dobanda_credit;

} c[3];


int cmp(const void *a,const void *b)
{
    int x;
    struct angajat *A=(struct angajat*)a;
    struct angajat *B=(struct angajat*)b;
    x=strcmp(A->nume_angajat,B->nume_angajat);
    if(x==0)
    return strcmp(A->prenume_angajat,B->prenume_angajat);
    else return x;
}
int cmp1(const void *a,const void *b)
{
    int x;
    struct client *A=(struct client*)a;
    struct client *B=(struct client*)b;
    x=strcmp(A->nume_client,B->nume_client);
    if(x==0)
    return strcmp(A->prenume_client,B->prenume_client);
    else return x;
}
enum rang
{
    ingrijitor=0,
    paznic,
    consilier_clienti,
    analist_credite,
    director_adjunct,
    director
};


enum zile
{
    luni=1,
    marti,
    miercuri,
    joi,
    vineri,
    sambata,
    duminica
};
void banci(struct banca *a,union bancomat *c)
{
    fflush(stdin);
    printf("Introduceti adresa bancii\n");
    fgets(a->adresa_banca,20,stdin);
    strcpy(c->adresa_bancomat,a->adresa_banca);
    fflush(stdin);
    printf("Introduceti monetarul bancii\n");
    scanf("%d",&a->credit_banca);

}
void citire_client(struct client *a,int b)
{

    fflush(stdin);
    printf("Introduceti numele clientului(maxim 16 caractere)\n");
    fgets(a->nume_client,16,stdin);
    fflush(stdin);
    printf("Introduceti prenumele clientului(maxim 32 caractere\n");
    fgets(a->prenume_client,32,stdin);
    fflush(stdin);
    printf("Introduceti numarul de telefon al clientului(maxim 10 caractere)\n");
    fgets(a->telefon_client,10,stdin);
    fflush(stdin);
    printf("Introduceti email-ul clientului(maxim 20 caractere)\n");
    fgets(a->email_client,20,stdin);
    fflush(stdin);
    if(b==0)
        a->tip_credit=0;
    if(b==1)
        a->tip_credit=1;
    if(b==2)
        a->tip_credit=2;
}
void citire_angajat(int x,struct angajat *a)
{
    a->id_angajat=x;
    fflush(stdin);
    printf("Introduceti numele angajatului cu numarul %d (maxim 16 caractere)\n",x);
    fgets(a->nume_angajat,16,stdin);
    fflush(stdin);
    printf("Introduceti prenumele angajatului cu numarul %d (maxim 32 caractere)\n",x);
    fgets(a->prenume_angajat,32,stdin);
    fflush(stdin);
    printf("Introduceti telefonul angajatului cu numarul %d (maxim 10 caractere)\n",x);
    fgets(a->telefon_angajat,10,stdin);
    fflush(stdin);
}
void salariu(int a,struct angajat *b)
{
    if(a==0)
    {
        b->salariu_angajat=800;
        b->rang_angajat=a;
    }
    if(a==1)
    {
        b->salariu_angajat=1000;
        b->rang_angajat=a;
    }
    if(a==2)
    {
        b->salariu_angajat=1600;
        b->rang_angajat=a;
    }
    if(a==3)
    {
        b->salariu_angajat=2000;
        b->rang_angajat=a;
    }
    if(a==4)
    {
        b->salariu_angajat=3000;
        b->rang_angajat=a;
    }
    if(a==5)
    {
        b->salariu_angajat=4000;
        b->rang_angajat=a;
    }
}
int main()
{
   time_t mytime;
    mytime = time(NULL);
    printf("Data actuala: %s", ctime(&mytime));
    void(*o)(struct client *,int)=citire_client;
    char l[40];
    fflush(stdin);
    printf("Introduceti numele bancii\n");
    fgets(l,40,stdin);
    fflush(stdin);
    printf("Acum gestionati baza de date a bancii cu numele:%s",l);
    c[0].tip_credit=0;
    c[0].valoare_credit=2000;
    c[0].durata_credit=3;
    c[0].dobanda_credit=1;
    c[1].tip_credit=1;
    c[1].valoare_credit=4000;
    c[1].durata_credit=6;
    c[1].dobanda_credit=2;
    c[2].tip_credit=2;
    c[2].valoare_credit=6000;
    c[2].durata_credit=12;
    c[2].dobanda_credit=3;
    enum rang a;
    enum zile b;
    int n,i,x,j=0,m,k3,k4;
    struct angajat *p,*u;
    struct client *p1,*u1;
    union bancomat k;
    struct banca *k1,*k2;

    printf("Introduceti numarul de angajati\n");
    scanf("%d",&n);
    printf("Introduceti numarul de clienti\n");
    scanf("%d",&m);
    p=(struct angajat *) malloc (n*sizeof(struct angajat));
    p1=(struct client *) malloc (m*sizeof(struct client));
    u=p;
    u1=p1;
    a=ingrijitor;
    b=luni;
    for(i=0; i<n; i++)
    {
        if(a==ingrijitor)
            j=j+100;
        citire_angajat(i+1,p);
        p->id_banca=j;
        salariu(a,*&p);


        p++;
        a++;
    }
    p=u;
    qsort(p,n,sizeof(struct angajat),cmp);
    for(i=0;i<m;i++)
     {printf("Introduceti tipul de credit al clientului(intre 0 si 2)\n");
      scanf("%d",&x);
      o(*&p1,x); //x este intre 0-2 si reprezinta tipul de credit al clientului
      p1->id_client=i+1;
      p1++;
     }
     p1=u1;
     qsort(p1,m,sizeof(struct client),cmp1);
     printf("Introduceti numarul de sucursale ale bancii %s\n",l);
    scanf("%d",&i);
    k1=(struct banca *) malloc (i*sizeof(struct banca));
    k2=k1; k3=k4=i;
    x=100;
    for(j=0; j<i; j++)
    {
        banci(*&k1,&k);
        k1->id_banca=x;
        k1++;
        x+=100;
    }
    x=100;
    k1=k2;
    j=i;
    p=u;
    p1=u1;
    if(k3>0)
    printf("Creditul bancii curente este de:%d\n",k1->credit_banca);
    k3--;
    for(i=0;i<n;i++)
    {
        if(i%5==0 && i>0 && k3>0)
        {
         k1++;
         k3--;
         printf("Creditul bancii curente este de:%d\n",k1->credit_banca);
        }
        printf("Nume angajat:%s\n",p->nume_angajat);
        printf("Prenume angajat:%s\n",p->prenume_angajat);
        printf("ID angajat:%d\n",p->id_angajat);
        printf("Angajatul lucreaza la banca cu id-ul:%d de la adresa:%s\n",p->id_banca,k1->adresa_banca);
        if(p->rang_angajat==0)
        printf("Angajatul lucreaza ca ingrijitor\n");
        if(p->rang_angajat==1)
        printf("Angajatul lucreaza ca paznic\n");
        if(p->rang_angajat==2)
        printf("Angajatul lucreaza ca si consilier de clienti\n");
        if(p->rang_angajat==3)
        printf("Angajatul lucreaza ca analist de credite\n");
        if(p->rang_angajat==4)
        printf("Angajatul lucreaza ca director adjunct\n");
        if(p->rang_angajat==5)
        printf("Angajatul lucreaza ca director\n");
        printf("Salariul angajatului este de %d de lei\n",p->salariu_angajat);
        printf("Telefonul angajatului este:%s\n",p->telefon_angajat);
        p++;

    }
    k1=k2;
    k4--;
    for(i=0; i<m; i++)
    {
        printf("Numele clientului cu numarul %d este:%s\n",i+1,p1->nume_client);
        printf("Prenumele clientului cu numarul %d este:%s\n",i+1,p1->prenume_client);
        printf("Id-ul clientului cu numarul %d este:%d\n",i+1,p1->id_client);
        printf("Telefonul clientului cu numarul %d este:%s\n",i+1,p1->telefon_client);
        printf("Email-ul clientului cu numarul %d este:%s\n",i+1,p1->email_client);
        if(p1->tip_credit==0)
        printf("Creditul dorit de clientul cu numarul %d este de:%d de lei",i+1,c[0].valoare_credit);
        if(p1->tip_credit==1)
        printf("Creditul dorit de clientul cu numarul %d este de:%d de lei",i+1,c[1].valoare_credit);
        if(p1->tip_credit==2)
        printf("Creditul dorit de clientul cu numarul %d este de:%d de lei",i+1,c[2].valoare_credit);
        if(p1->tip_credit==c[0].tip_credit)
        {
            if(k1->credit_banca>c[0].valoare_credit)
                k1->credit_banca-=c[0].valoare_credit;
            else if(j>0 && k4>0)
            {
                k4--;
                k1++;
                j--;
            }
            else
            {
                printf("Creditul din banca este insuficient pentru client,prin urmare clientul nu poate lua creditul de %d lei pe care si-l doreste\n",c[0].valoare_credit);
                break;
            }
        }
        if(p1->tip_credit==c[1].tip_credit)
        {
            if(k1->credit_banca>c[1].valoare_credit)
                k1->credit_banca-=c[1].valoare_credit;

            else if(j>0 && k4>0)
            {
                k4--;
                k1++;
                j--;
            }

            else
            {
                printf("Creditul din banca este insuficient pentru client,prin urmare clientul nu poate lua creditul de %d lei pe care si-l doreste\n",c[1].valoare_credit);
                break;
            }
        }
        if(p1->tip_credit==c[2].tip_credit)
        {
            if(k1->credit_banca>c[2].valoare_credit)
                k1->credit_banca-=c[2].valoare_credit;
            else if(j>0 && k4>0)
            {
                k4--;
                k1++;
                j--;
            }
            else
            {
                printf("Creditul din banca este insuficient pentru client,prin urmare clientul nu poate lua creditul de %d lei pe care si-l doreste\n",c[2].valoare_credit);
                break;
            }
        }
    }
   system("pause");
    return 0;
}
