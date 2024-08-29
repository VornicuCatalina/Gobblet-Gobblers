#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <cstring>
#include <stack>
using namespace std;
struct matstiv
{
    int lin;
    int col;
    stack<int> s;
} s[10];

struct jucator
{
    int mic, mediu, mare;
    char imgmare[30], imgmedie[30], imgmica[30];
} juc1,juc2;

struct
{
    int patrat, juc1, juc2;
} ultimamiscare;

int see=0,culoare=15,magie=15, tr=0,pag=0;
bool finish,baku,start;
void exit(int length,int height);
void bak();
void options(int length);
void background(int length,int height);
void play();
void functions(int length,int height);
void initialisation();
void message();
void instructions(int x);
void games(int x);
int joc();
void initializare(int x, int y);
void click(int l,int h,int &element);
void mutareundo(int l,int h,int &element);
void afisareelement(int l, int h, int &e, int ok1);
void piesafolosita(int &k);
void mutarepatrat(int l, int h, int x, int y,int &patrat);
void redeseneaza(int l, int h);
void afisaremutare(int &element,int l,int h,int x,int y);
void numarpiese(int x, int y, int ok);
int castigator(int n);
void mutare(int l,int h,int &element);
void alegeloc(int l, int h);
void alegepiesa(int l, int h, int caz);

int ok=1,verif=3;
char nume1[10],nume2[10];
short int matrice[4][4], iesire, ok1, element,player=0,verif1=0,cnt,vf,calculator,piesarea;
int pctx=0,pcty=0,pct=0,var=0,var1=0,patrat=0;
bool finish1;

int main(void)
{
    strcpy(nume1,"0");
    strcpy(nume2,"0");
    initialisation();
    return 0;
}

void exit(int length,int height)///c
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if (x>=length&&y>=height&&x<=length+200&&y<=height+60)
            finish=true;
    }
}

void bak()///c
{
    int x,y,length=getmaxx();
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if (x>=25&&y>=25&&x<=195&&y<=60)
            baku=true;
        if (x>=length-330&&y>=35&&x<=length&&y<=70&&pag==1)
            start=true;
    }
}

int joc()///e
{
    s[1].lin=1,s[1].col=1, s[2].lin=1,s[2].col=2,s[3].lin=1,s[3].col=3,s[4].lin=2,s[4].col=1,s[5].lin=2,s[5].col=2,s[6].lin=2,s[6].col=3,s[7].lin=3,s[7].col=1,s[8].lin=3,s[8].col=2,s[9].lin=3,s[9].col=3;
    juc1.mare=juc1.mic=juc1.mediu=juc2.mic=juc2.mediu=juc2.mare=2;
    matrice[s[9].lin][s[9].col]=matrice[s[8].lin][s[8].col]=matrice[s[7].lin][s[7].col]=matrice[s[6].lin][s[6].col]=matrice[s[5].lin][s[5].col]=matrice[s[4].lin][s[4].col]=matrice[s[3].lin][s[3].col]=matrice[s[2].lin][s[2].col]=matrice[s[1].lin][s[1].col]=0;
    player=0,pag=1;
    for(int i=1; i<=9; i++)
        s[i].s.push(0);
    int x,y,element=0;
    x=getmaxx(),y=getmaxy();
    if(nume1[0]=='0'||nume1[0]==32)
        strcpy(nume1,"PLAYER 1  ");
    if(nume2[0]=='0'||nume2[0]==32)
        strcpy(nume2,"PLAYER 2  ");
    if(calculator>0)
    {
        strcpy(nume1,"YOU       ");
        strcpy(nume2,"PC        ");
    }
    initializare(x,y);
    setcolor(BLACK);
    setbkcolor(WHITE);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    outtextxy(110,45,"BACK");
    setcolor(BLUE);
    outtextxy(200,y-50,nume1);
    setcolor(BLACK);
    outtextxy(x-170,45,"RESTART");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    ok1=1, iesire=0;
    baku=false;
    do
    {
        do
        {
            if(start)
                goto restart;
            if(baku)
                goto revenire;
            if(!element&&!castigator(3))
                click(x,y,element);
            else
                mutare(x,y,element);
            if(verif1&&!element)
                redeseneaza(x,y);
            if(!element)
                castigator(3);
        }
        while(!finish1);
        if(!start&&!baku)
        {
        if(!calculator)
        {
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            settextstyle(EUROPEAN_FONT,HORIZ_DIR,7);
            readimagefile("pwp.gif",0,y/2-200,x,y/2+200);
            if(castigator(3)==1)
                outtextxy(x/2+45,y/2-20,nume1);
            else
                outtextxy(x/2+45,y/2-20,nume2);
            outtextxy(x/2,y/2+50,"WINS");
        }
        else
        {
            if(castigator(3)==1)
                readimagefile("win.gif",0,y/2-250,x,y/2+250);
            else
                readimagefile("lose.gif",0,y/2-250,x,y/2+250);
        }
        }
        bak();
restart:
        if(start)
        {
            matrice[s[9].lin][s[9].col]=matrice[s[8].lin][s[8].col]=matrice[s[7].lin][s[7].col]=matrice[s[6].lin][s[6].col]=matrice[s[5].lin][s[5].col]=matrice[s[4].lin][s[4].col]=matrice[s[3].lin][s[3].col]=matrice[s[2].lin][s[2].col]=matrice[s[1].lin][s[1].col]=0;
            player=0;
            for(int i=1; i<=9; i++)
                s[i].s.push(0);
            start=false;
            juc1.mare=juc1.mediu=juc1.mic=juc2.mare=juc2.mediu=juc2.mic=2,finish1=false,initializare(x,y);
            settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
            outtextxy(110,45,"BACK");
            setcolor(BLUE);
            outtextxy(200,y-50,nume1);
            setcolor(BLACK);
            outtextxy(x-170,45,"RESTART");
            settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
        }
    }
    while(!baku);
revenire:
    finish1=false;
    if(calculator>0)
    {
        strcpy(nume1,"PLAYER 1  ");
        strcpy(nume2,"PLAYER 2  ");
    }
    pag=0,calculator=0;
    play();
}

void imagini()
{
    if(var==0)
    {
        strcpy(juc1.imgmare,"portocaliu.mare.gif");
        strcpy(juc1.imgmedie,"portocaliu.mediu.gif");
        strcpy(juc1.imgmica,"portocaliu.mic.gif");
        strcpy(juc2.imgmare,"albastru.mare.gif");
        strcpy(juc2.imgmedie,"albastru.mediu.gif");
        strcpy(juc2.imgmica,"albastru.mic.gif");
    }
    else if(var==1)
    {
        strcpy(juc1.imgmare,"portocaliu_xmas_mare.gif");
        strcpy(juc1.imgmedie,"portocaliu_xmas_mediu.gif");
        strcpy(juc1.imgmica,"portocaliu_xmas_mic.gif");
        strcpy(juc2.imgmare,"albastru_xmas_mare.gif");
        strcpy(juc2.imgmedie,"albastru_xmas_mediu.gif");
        strcpy(juc2.imgmica,"albastru_xmas_mic.gif");
    }
    else if(var==2)
    {
        strcpy(juc1.imgmare,"portocaliu_summer_mare.gif");
        strcpy(juc1.imgmedie,"portocaliu_summer_mediu.gif");
        strcpy(juc1.imgmica,"portocaliu_summer_mic.gif");
        strcpy(juc2.imgmare,"albastru_summer_mare.gif");
        strcpy(juc2.imgmedie,"albastru_summer_mediu.gif");
        strcpy(juc2.imgmica,"albastru_summer_mic.gif");
    }
    else if(var==3)
    {
        strcpy(juc1.imgmare,"portocaliu_old_mare.gif");
        strcpy(juc1.imgmedie,"portocaliu_old_mediu.gif");
        strcpy(juc1.imgmica,"portocaliu_old_mic.gif");
        strcpy(juc2.imgmare,"albastru_old_mare.gif");
        strcpy(juc2.imgmedie,"albastru_old_mediu.gif");
        strcpy(juc2.imgmica,"albastru_old_mic.gif");
    }

}

void initializare(int x, int y)
{
    imagini();
    setcolor(BLACK);
    setbkcolor(WHITE);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    outtextxy(110,50,"BACK");

    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    readimagefile("Fundal1.jpg",0,0,1280,700);
    readimagefile("Titlu.jpg",x-785,0,x-480,95);
    readimagefile("Tabla.gif",x/3-210,y/2-195,x/2+410,670);
    readimagefile(juc1.imgmare,x-185,55,x-105,250);
    readimagefile(juc1.imgmedie,x-175,300,x-115,440);
    readimagefile(juc1.imgmica,x-165,490,x-125,570);
    setbkcolor(WHITE);
    setcolor(BLACK);

    readimagefile(juc2.imgmare,x-1185,55,x-1105,250);
    readimagefile(juc2.imgmedie,x-1175,300,x-1115,440);
    readimagefile(juc2.imgmica,x-1165,490,x-1125,570);
    numarpiese(x,y,5);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
    outtextxy(1010,650,"UNDO");
}

void click(int l,int h,int &element)///e
{
    int x,y;
    if(player==1&&calculator>0)
    {
        element=0;
        pctx=x,pcty=y;
        alegeloc(l,h);
        verif1=0;
    }

    else if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if (x>=25&&y>=25&&x<=195&&y<=60)
            baku=true;
        if (x>=l-330&&y>=35&&x<=l&&y<=70&&pag==1)
            start=true;
        if(baku||start)
        {
            finish1=true;
        }
        else
            {
        if (x>=l-185&&x<=l-105&&player==1&&!calculator)///piesele din dreapta
        {
            if(y>=50&&y<=290&&juc1.mare>0)
                element=3;
            if(y>=300&&y<=440&&juc1.mediu>0)
                element=2;
            if(y>=470&&y<=590&&juc1.mic>0)
                element=1;
            ultimamiscare.juc2=element;
        }

        else if (x>=l-1185&&x<=l-1105&&player==0)///piesele din stanga
        {
            if(y>=50&&y<=290&&juc2.mare>0)
                element=-3;
            if(y>=300&&y<=440&&juc2.mediu>0)
                element=-2;
            if(y>=470&&y<=590&&juc2.mic>0)
                element=-1;
            ultimamiscare.juc1=element;
        }
        else if(x>=l/3-210&&y>=h/2-200&&x<=l/2+410&&y<=600)///click pe patrate
        {
            mutarepatrat(l,h,x,y,patrat);
            if(piesarea==patrat) click(l,h,element);
            else if(((player==1&&matrice[s[patrat].lin][s[patrat].col]>0)||(player==0&&matrice[s[patrat].lin][s[patrat].col]<0))&&s[patrat].s.top()!=NULL)
            {
                element=matrice[s[patrat].lin][s[patrat].col];

                //cnt=s[patrat].s.top()
                vf=patrat;
                ultimamiscare.patrat=patrat;
                piesarea=patrat;
                verif1=1;
                pctx=x,pcty=y;
                player++;
            }
        }
        else click(l,h,element);
    }
    }


}

void alegeloc(int l, int h)///c
{
    delay(500);
    int locliber[4]= {0,0,0,0},adversar[4]= {0,0,0,0}, i,j,val=0;
    patrat=0;
    int vx=0,vy=0,vx1=0,vy1=0;
    if(calculator==2)
    {
        locliber[3]=locliber[2]=locliber[1]=locliber[4]=adversar[1]=adversar[2]=adversar[3]=adversar[4]=0;
        for(i=1; i<=3; i++)
        {
            if(matrice[i][i]>0)adversar[1]++; //col principala
            if(matrice[i][i]<=0&&matrice[i][i]!=-3)vx=i;
            if(matrice[i][4-i]>0)adversar[2]++; //col secundara
            if(matrice[i][4-i]<=0&&matrice[i][4-i]!=3) vy=i;
        }
        if(adversar[1]==2&&vx)
            locliber[1]=(vx-1)*3+vx;
        if(adversar[2]==2&&vy)
            locliber[2]=(vy-1)*3+4-vy;
        vx=0,vy=0;
        for(i=1; i<=3; i++)
        {
            vx=0,vy=0,vx1=0,vy1=0,adversar[3]=0,adversar[4]=0;
            for(j=1; j<=3; j++)
            {
                if(matrice[i][j]>0)adversar[3]++; //linie
                if(matrice[i][j]<=0&&matrice[i][j]!=-3)vx=i,vy=j;
                if(matrice[j][i]>0)adversar[4]++; //coloana
                if(matrice[j][i]<=0&&matrice[j][i]!=-3)vx1=j,vy1=i;
            }
            if(adversar[3]==2&&vx)
                locliber[3]=(vx-1)*3+vy;
            if(adversar[4]==2&&vx1)
                locliber[4]=(vx1-1)*3+vy1;
        }
        for(int k=1; k<=4; k++)
            if(locliber[k]) patrat=locliber[k];
        if(patrat)
            val=-s[patrat].s.top()+1,alegepiesa(l,h,val);
    }
    if(!patrat)
    {
        vx=0,vy=0,vx1=0,vy1=0;
        locliber[3]=locliber[2]=locliber[1]=locliber[4]=adversar[1]=adversar[2]=adversar[3]=adversar[4]=0;
        for(i=1; i<=3; i++)
        {
            if(matrice[i][i]<0)adversar[1]++; //col principala
            if(matrice[i][i]==0)vx=i;
            if(matrice[i][4-i]<0)adversar[2]++; //col secundara
            if(matrice[i][4-i]==0) vy=i;
        }
        if(adversar[1]==2&&vx)
            locliber[1]=(vx-1)*3+vx;
        if(adversar[2]==2&&vy)
            locliber[2]=(vy-1)*3+4-vy;
        vx=0,vy=0;
        for(i=1; i<=3; i++)
        {
            vx=0,vy=0,vx1=0,vy1=0,adversar[3]=0,adversar[4]=0;
            for(j=1; j<=3; j++)
            {
                if(matrice[i][j]<0)adversar[3]++; //linie
                if(matrice[i][j]==0)vx=i,vy=j;
                if(matrice[j][i]<0)adversar[4]++; //coloana
                if(matrice[j][i]==0)vx1=j,vy1=i;
            }
            if(adversar[3]==2&&vx)
                locliber[3]=(vx-1)*3+vy;
            if(adversar[4]==2&&vx1)
                locliber[4]=(vx1-1)*3+vy1;
        }
        for(int k=1; k<=4; k++)
            if(locliber[k]) patrat=locliber[k];
        if(patrat)
            alegepiesa(l,h,4);
    }
    ok=0;
    int k=0;
    while(patrat==0&&!k)
    {
        ok=rand()%9;
        ok++;
        if(matrice[s[ok].lin][s[ok].col]!=-3&&matrice[s[ok].lin][s[ok].col]<=0)
        {
            patrat=ok;
            k=-s[patrat].s.top()+1;
        }
        if((k==3&&juc1.mare>0)||(k==2&&juc1.mediu>0)||(k==1&&juc1.mic>0))
            alegepiesa(l,h,0);
        else if(k)
            alegepiesa(l,h,k);
    }
}

void alegepiesa(int l, int h, int caz)///c
{
    int i=1;
    if(caz==0)
    {
        if(matrice[s[patrat].lin][s[patrat].col]<=0)
            element=-matrice[s[patrat].lin][s[patrat].col]+1;
        int k=element;
        afisaremutare(k,l,h,0,0);
    }
    else if(caz==4)
    {
        if(juc1.mare>0)element=3;
        else if(juc1.mediu>0) element=2;
        else if(juc1.mic>0) element=1;
        if(element)
        {
            int k=element;
            afisaremutare(k,l,h,0,0);
        }
        while(element==0)
        {
            if(matrice[s[i].lin][s[i].col]>0)
            {
                element=s[i].s.top();
                s[i].s.pop();
                matrice[s[i].lin][s[i].col]=s[i].s.top();
                redeseneaza(l,h);
            }
            else i++;
        }
    }
    else
    {
        if(juc1.mic>0&&caz==1)element=1;
        else if(juc1.mediu>0&&caz<=2) element=2;
        else if(juc1.mare>0&&caz<=3) element=3;
        if(element)
        {
            int k=element;
            afisaremutare(k,l,h,0,0);
        }
        while(element==0)
        {
            if(s[i].s.top()>0&&s[i].s.top()>=caz)
            {
                element=s[i].s.top();
                s[i].s.pop();
                matrice[s[i].lin][s[i].col]=s[i].s.top();
                s[patrat].s.push(element);
                redeseneaza(l,h);
            }
            else i++;
        }
    }
}

void mutarepatrat(int l, int h, int x, int y,int &patrat)///pentru mutare din patrat si pentru afisarea mutarii in patrat
{///e
    if(x>=l-1050&&y>=340&&x<=l-900&&y<=440)patrat=1;///patratul 1
    if(x>=l-890&&y>=250&&x<=l-740&&y<=350)patrat=2;///patratul 2
    if(x>=l-720&&y>=160&&x<=l-570&&y<=260)patrat=3;///patratul 3
    if(x>=l-920&&y>=450&&x<=l-730&&y<=570)patrat=4;///patratul 4
    if(x>=l-730&&y>=340&&x<=l-560&&y<=450)patrat=5;///patratul 5
    if(x>=l-550&&y>=240&&x<=l-390&&y<=350)patrat=6;///patratul 6
    if(x>=l-730&&y>=560&&x<=l-560&&y<=660)patrat=7;///patratul 7
    if(x>=l-550&&y>=450&&x<=l-370&&y<=580)patrat=8;///patratul 8
    if(x>=l-390&&y>=340&&x<=l-230&&y<=460)patrat=9;///patratul 9

}
void afisaremutare(int &element, int l, int h, int x, int y)///e
{
    int element1=element,k=0;
    if(element<0)
        element=-1*element;
    if(!calculator||(x&&y))
    {
        mutarepatrat(l,h,x,y,patrat);
        if(patrat!=0)
            if(s[patrat].s.top()>=element||s[patrat].s.top()<=-element)mutare(l,h,element1);///!!
            else
            {
                s[patrat].s.push(element1);
                matrice[s[patrat].lin][s[patrat].col]=element1,k++;
            }
    }
    else if(calculator&&patrat&&!(s[patrat].s.top()>=element||s[patrat].s.top()<=-element))
    {
        s[patrat].s.push(element1), matrice[s[patrat].lin][s[patrat].col]=element1,k++;
    }
    element=element1;
    if(k!=0)
    {
        int l=getmaxx(),h=getmaxy();
        if(pctx>=l/3-210&&pcty>=h/2-200&&pctx<=l/2+410&&pcty<=600)
        {
            s[vf].s.pop();
            if(s[vf].s.top()!=NULL)
                matrice[s[vf].lin][s[vf].col]=s[vf].s.top();
            else
                matrice[s[vf].lin][s[vf].col]=0;
        }
        afisareelement(l,h,element,patrat);
        vf=0;
    }
    else
        mutare(l,h,element);

    ultimamiscare.patrat=ultimamiscare.juc1=ultimamiscare.juc2=piesarea=0;
}

void mutareundo(int l, int h, int &element)///e
{

    if(element!=0)
    {
        if(ultimamiscare.patrat!=0)///daca a luat piesa din patrat
        {
            int k=ultimamiscare.patrat;
                matrice[s[k].lin][s[k].col]=element, s[k].s.push(element);///sa pun 0 la baza stivelor ca sa puna in patrat 0;
            piesarea=ultimamiscare.patrat;
            ultimamiscare.patrat=0;
            element=0;
           verif1=0;
            click(l,h,element);

        }
        else if(ultimamiscare.juc1!=0||ultimamiscare.juc2!=0) /// daca a luat piesa din stanga sau dreapta (cele nefolosite inca)
        {
            if(ultimamiscare.juc1==1) juc1.mic++,ultimamiscare.juc1;
            if(ultimamiscare.juc1==2) juc1.mediu++,ultimamiscare.juc1;
            if(ultimamiscare.juc1==3) juc1.mare++,ultimamiscare.juc1;
            if(ultimamiscare.juc2==-1) juc2.mic++,ultimamiscare.juc2;
            if(ultimamiscare.juc2==-2) juc2.mediu++,ultimamiscare.juc2;
            if(ultimamiscare.juc2==-3) juc2.mare++,ultimamiscare.juc2;
           // verif1=0;
            click(l,h,element);

        }
        else click(l,h,element);
    }
}

void redeseneaza(int l, int h)///e
{
    int i,j,k;
    ok1=1,pct=1;
    initializare(l,h);
    setcolor(BLACK);
    setbkcolor(WHITE);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    outtextxy(110,45,"BACK");
    outtextxy(l-170,45,"RESTART");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);

    verif1=0;
    i=matrice[1][1],afisareelement(l,h,i,ok1);
    i=matrice[1][2],afisareelement(l,h,i,++ok1);
    i=matrice[1][3],afisareelement(l,h,i,++ok1);
    i=matrice[2][1],afisareelement(l,h,i,++ok1);
    i=matrice[2][2],afisareelement(l,h,i,++ok1);
    i=matrice[2][3],afisareelement(l,h,i,++ok1);
    i=matrice[3][1],afisareelement(l,h,i,++ok1);
    i=matrice[3][2],afisareelement(l,h,i,++ok1);
    i=matrice[3][3],afisareelement(l,h,i,++ok1);
    pct=0;
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0,h-90,400,h-10);
    if(player==1)
    {
        setcolor(LIGHTRED);
        outtextxy(200,h-50,nume2);
    }
    else
    {
        setcolor(BLUE);
        outtextxy(200,h-50,nume1);
    }
    setcolor(BLACK);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
}

void afisareelement(int l, int h, int &element, int patrat)/// dupa reinitializare  e
{
    if(!verif1)
    {
        if(patrat==1) ///patratul 1 x-1050,340,x-900,440
        {
            if(element==3) readimagefile(juc1.imgmare,l-1000,230,l-920,420);
            if(element==2)readimagefile(juc1.imgmedie,l-990,275,l-930,420);
            if(element==1)readimagefile(juc1.imgmica,l-980,335,l-940,420);
            if(element==-3)readimagefile(juc2.imgmare,l-1000,230,l-920,420);
            if(element==-2)readimagefile(juc2.imgmedie,l-990,275,l-930,420);
            if(element==-1)readimagefile(juc2.imgmica,l-980,335,l-940,420);
        }

        else if(patrat==2)///patratul 2 g
        {
            if(element==3) readimagefile(juc1.imgmare,l-840,140,l-765,325);
            if(element==2)readimagefile(juc1.imgmedie,l-830,190,l-770,325);
            if(element==1)readimagefile(juc1.imgmica,l-820,240,l-780,325);
            if(element==-3)readimagefile(juc2.imgmare,l-840,140,l-765,325);
            if(element==-2)readimagefile(juc2.imgmedie,l-830,190,l-770,325);
            if(element==-1)readimagefile(juc2.imgmica,l-820,240,l-780,325);
        }

        else if(patrat==3)///patratul 3
        {
            if(element==3) readimagefile(juc1.imgmare,l-680,70,l-605,245);
            if(element==2)readimagefile(juc1.imgmedie,l-670,115,l-615,245);
            if(element==1)readimagefile(juc1.imgmica,l-660,165,l-620,245);
            if(element==-3)readimagefile(juc2.imgmare,l-680,70,l-610,245);
            if(element==-2)readimagefile(juc2.imgmedie,l-670,115,l-620,245);
            if(element==-1)readimagefile(juc2.imgmica,l-660,160,l-620,245);
        }


        if(patrat==4)///patratul 4
        {
            if(element==3) readimagefile(juc1.imgmare,l-880,340,l-795,545);
            if(element==2)readimagefile(juc1.imgmedie,l-870,395,l-805,545);
            if(element==1)readimagefile(juc1.imgmica,l-860,455,l-815,545);
            if(element==-3)readimagefile(juc2.imgmare,l-880,340,l-795,545);
            if(element==-2)readimagefile(juc2.imgmedie,l-870,395,l-805,545);
            if(element==-1)readimagefile(juc2.imgmica,l-860,455,l-815,545);
        }

        else if(patrat==5)///patratul 5
        {
            if(element==3) readimagefile(juc1.imgmare,l-680,245,l-600,435);
            if(element==2)readimagefile(juc1.imgmedie,l-670,300,l-610,435);
            if(element==1)readimagefile(juc1.imgmica,l-662,350,l-620,435);
            if(element==-3)readimagefile(juc2.imgmare,l-680,245,l-600,435);
            if(element==-2)readimagefile(juc2.imgmedie,l-670,300,l-610,435);
            if(element==-1)readimagefile(juc2.imgmica,l-662,350,l-620,435);
        }

        if(patrat==6)///patratul 6
        {
            if(element==3) readimagefile(juc1.imgmare,l-510,145,l-435,325);
            if(element==2)readimagefile(juc1.imgmedie,l-500,190,l-445,325);
            if(element==1)readimagefile(juc1.imgmica,l-490,240,l-450,325);
            if(element==-3)readimagefile(juc2.imgmare,l-510,145,l-435,325);
            if(element==-2)readimagefile(juc2.imgmedie,l-500,190,l-445,325);
            if(element==-1)readimagefile(juc2.imgmica,l-490,240,l-450,325);
        }

        if(patrat==7)///patratul 7
        {
            if(element==3) readimagefile(juc1.imgmare,l-685,450,l-600,650);
            if(element==2)readimagefile(juc1.imgmedie,l-675,500,l-615,650);
            if(element==1)readimagefile(juc1.imgmica,l-665,560,l-621,650);
            if(element==-3)readimagefile(juc2.imgmare,l-685,450,l-600,650);
            if(element==-2)readimagefile(juc2.imgmedie,l-675,500,l-615,650);
            if(element==-1)readimagefile(juc2.imgmica,l-665,560,l-621,650);
        }

        if(patrat==8)///patratul 8
        {
            if(element==3) readimagefile(juc1.imgmare,l-498,347,l-415,545);
            if(element==2)readimagefile(juc1.imgmedie,l-485,400,l-425,545);
            if(element==1)readimagefile(juc1.imgmica,l-475,456,l-433,545);
            if(element==-3)readimagefile(juc2.imgmare,l-498,347,l-415,545);
            if(element==-2)readimagefile(juc2.imgmedie,l-485,400,l-425,545);
            if(element==-1)readimagefile(juc2.imgmica,l-475,456,l-433,545);
        }

        if(patrat==9)///patratul 9
        {
            if(element==3) readimagefile(juc1.imgmare,l-337,235,l-260,425);
            if(element==2)readimagefile(juc1.imgmedie,l-330,290,l-270,425);
            if(element==1)readimagefile(juc1.imgmica,l-320,340,l-280,425);
            if(element==-3)readimagefile(juc2.imgmare,l-337,235,l-260,425);
            if(element==-2)readimagefile(juc2.imgmedie,l-330,290,l-270,425);
            if(element==-1)readimagefile(juc2.imgmica,l-320,340,l-280,425);
        }
    }
    if(patrat==1||patrat==2||patrat==3||patrat==4||patrat==5||patrat==6||patrat==7||patrat==8||patrat==9)
    {
        int x=getmaxx(),y=getmaxy();
        piesafolosita(element);
        settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
        numarpiese(x,y,player);
        element=0,player=(++player)%2;
        if(pct==0)
        {
            settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
            setfillstyle(SOLID_FILL, WHITE);
            bar(0,h-90,400,h-10);
            if(player==1)
            {
                setcolor(LIGHTRED);
                outtextxy(200,h-50,nume2);
            }
            else
            {
                setcolor(BLUE);
                outtextxy(200,h-50,nume1);
            }
            setcolor(BLACK);
            settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
        }
    }
}

void mutare(int l,int h,int &element) ///daca e pe tabla, apeleaza patratele   e
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if(x>=l/3-210&&y>=h/2-200&&x<=l/2+410&&y<=600&&element!=0)
            afisaremutare(element,l,h,x,y),element=0;
        else if(x>=l-325&&y>=615&&x<=l-215&&y<=665) mutareundo(l,h,element),element=0;
        else mutare(l,h,element);
    }
}

void numarpiese(int x, int y,int ok)/// e
{
    settextstyle(BOLD_FONT,HORIZ_DIR,1);

    if(ok==0)
    {
        if(juc2.mic==1) outtextxy(x-1147,y-110,"1");
        if(juc2.mic<=0) outtextxy(x-1147,y-110,"0");
        if(juc2.mediu==1) outtextxy(x-1147,y-240,"1");
        if(juc2.mediu<=0) outtextxy(x-1147,y-240,"0");
        if(juc2.mare==1) outtextxy(x-1147,y-430,"1");
        if(juc2.mare<=0) outtextxy(x-1147,y-430,"0");
    }
    else if(ok==1)
    {
        if(juc1.mic==1) outtextxy(x-145,y-110,"1");
        if(juc1.mic<=0) outtextxy(x-145,y-110,"0");
        if(juc1.mediu==1) outtextxy(x-145,y-240,"1");
        if(juc1.mediu<=0) outtextxy(x-145,y-240,"0");
        if(juc1.mare==1) outtextxy(x-145,y-430,"1");
        if(juc1.mare<=0) outtextxy(x-145,y-430,"0");
    }
    else
    {
        if(juc1.mic==2) outtextxy(x-145,y-110,"2");
        if(juc1.mic==1) outtextxy(x-145,y-110,"1");
        if(juc1.mic<=0) outtextxy(x-145,y-110,"0");
        if(juc1.mediu==2) outtextxy(x-145,y-240,"2");
        if(juc1.mediu==1) outtextxy(x-145,y-240,"1");
        if(juc1.mediu<=0) outtextxy(x-145,y-240,"0");
        if(juc1.mare==2) outtextxy(x-145,y-430,"2");
        if(juc1.mare==1) outtextxy(x-145,y-430,"1");
        if(juc1.mare<=0) outtextxy(x-145,y-430,"0");
        if(juc2.mic==2) outtextxy(x-1147,y-110,"2");
        if(juc2.mic==1) outtextxy(x-1147,y-110,"1");
        if(juc2.mic<=0) outtextxy(x-1147,y-110,"0");
        if(juc1.mediu==2) outtextxy(x-1147,y-240,"2");
        if(juc2.mediu==1) outtextxy(x-1147,y-240,"1");
        if(juc2.mediu<=0) outtextxy(x-1147,y-240,"0");
        if(juc1.mare==2) outtextxy(x-1147,y-430,"2");
        if(juc2.mare==1) outtextxy(x-1147,y-430,"1");
        if(juc2.mare<=0) outtextxy(x-1147,y-430,"0");

    }
}

void piesafolosita(int &element)///e
{
    int l=getmaxx(),h=getmaxy();
    if(!(pctx>=l/3-210&&pcty>=h/2-200&&pctx<=l/2+410&&pcty<=600)&&pct==0)
    {
        if(element==3) juc1.mare--,ultimamiscare.juc1=3;;
        if(element==2)juc1.mediu--,ultimamiscare.juc1=2;;
        if(element==1)juc1.mic--,ultimamiscare.juc1=1;;
        if(element==-3)juc2.mare--,ultimamiscare.juc2=-3;;
        if(element==-2)juc2.mediu--,ultimamiscare.juc2=-2;;
        if(element==-1)juc2.mic--,ultimamiscare.juc2=-1;
    }
    pctx=0,pcty=0; //                 216 149 1049 600
}

int castigator(int n)///c
{
    int i,j,cntp_dp,cntn_dp,cntp_ds,cntn_ds,linie_p,linie_n,coloana_p,coloana_n;
    cntp_dp=cntn_dp=cntp_ds=cntn_ds=linie_p=linie_n=coloana_p=coloana_n=0;
    for(i=1; i<=n; i++)
    {
        if(matrice[i][i]>0)
            cntp_dp++;
        else if(matrice[i][i]<0)
            cntn_dp++;
        if(matrice[i][n-i+1]>0)
            cntp_ds++;
        else if(matrice[i][n-i+1]<0)
            cntn_ds++;
    }
    if(cntp_dp==n||cntp_ds==n)
    {
        finish1=true;
        return 2;
    }
    if(cntn_dp==n||cntn_ds==n)
    {
        finish1=true;
        return 1;
    }
    for(i=1; i<=n; i++)
    {
        linie_p=linie_n=coloana_p=coloana_n=0;
        for(j=1; j<=n; j++)
        {
            if(matrice[i][j]>0)
                linie_p++;
            else if(matrice[i][j]<0)
                linie_n++;
            if(matrice[j][i]>0)
                coloana_p++;
            else if(matrice[j][i]<0)
                coloana_n++;
        }
        if(linie_p==n||coloana_p==n)
        {
            finish1=true;
            return 2;
        }
        if(linie_n==n||coloana_n==n)
        {
            finish1=true;
            return 1;
        }
    }
    return 0;
}

void options(int length)///e
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if (x>=length/2-285&&y>=150&&x<=length/2+285&&y<=200)
            joc();
        if(x>=length/2-285&&y>=250&&x<=length/2+285&&y<=300)
            calculator=1,joc();
        if(x>=length/2-285&&y>=350&&x<=length/2+285&&y<=400)
            calculator=2,joc();
    }
}

void background(int length)///c
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if(x>=length/2-50&&y>=270&&x<=length/2+50&&y<=300)
            culoare=12;//code L.RED
        if(x>=length/2-67&&y>=320&&x<=length/2+67&&y<=350)
            culoare=3; //code CYAN
        if(x>=length/2-83&&y>=370&&x<=length/2+83&&y<=400)
            culoare=2; //code GREEN
        if(x>=length/2-67&&y>=420&&x<=length/2+67&&y<=450)
            culoare=13; //code PINK
        if(x>=length/2-83&&y>=470&&x<=length/2+83&&y<=500)
            culoare=15; //code WHITE

        if(x>=length/4-117&&y>=270&&x<=length/4+117&&y<=300)
            var1=0; //code NORMAL
        if(x>=length/4-117&&y>=320&&x<=length/4+117&&y<=350)
            var1=1; //code WINTER
        if(x>=length/4-117&&y>=370&&x<=length/4+117&&y<=400)
            var1=2; //code SUMMER
        if(x>=length/4-50&&y>=420&&x<=length/4+50&&y<=450)
            var1=3; //code OLD
        int k=0;
        if(x>=length-length/4-150&&y>=270&&x<=length-length/4+150&&y<=300)//code PLAYER1
        {
            strcpy(nume1,"0");
            for(int i=1; i<=9; i++)
                nume1[i]=' ';
            tr=1;
            while(k<=10&&nume1[k-1]!=32)
            {
                nume1[k]=getch();
                k++;
            }
        }
        if(x>=length-length/4-150&&y>=320&&x<=length-length/4+150&&y<=350)//code PLAYER2
        {
            strcpy(nume2,"0");
            for(int i=1; i<=9; i++)
                nume2[i]=' ';
            tr=1;
            while(k<=10&&nume2[k-1]!=32)
            {
                nume2[k]=getch();
                k++;
            }
        }
        if(strcmp(nume1,nume2)==0)
            strcpy(nume2,"0");
    }
}

void play()///c
{
    int x,y;
    x=getmaxx(),y=getmaxy();
    readimagefile("inceput.jpg",0,0,x,y);
    setfillstyle(SOLID_FILL, culoare);
    bar(25,25,x-25,y-25);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,7);
    setcolor(YELLOW);
    setbkcolor(culoare);
    outtextxy(x/2,80,"PLAY MENU");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    setcolor(BLUE);
    outtextxy(x/2,200,"PLAYER VS PLAYER");
    outtextxy(x/2,300,"PLAYER VS PC");
    outtextxy(x/2,400,"CHALLENGE");
    readimagefile("albastru1.gif",0,150,x/2+50,700);
    readimagefile("porto1.gif",x/2-50,150,x-30,700);
    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(110,50,"BACK");
    baku=false;
    do
    {
        bak();
        if(!baku)
            options(x);
    }
    while(!baku);
    initialisation();
}

void settings()///c
{
    int x,y;
    x=getmaxx(),y=getmaxy();
revenire:
    magie=culoare,var=var1;
    tr=0;
    setfillstyle(SOLID_FILL, culoare);
    bar(25,25,x-25,y-25);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,7);
    setcolor(RED);
    setbkcolor(culoare);
    outtextxy(x/2-50,80,"SETTINGS");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(110,50,"BACK");
    if(culoare==0)
        setcolor(WHITE);
    else
        setcolor(magie-1);
    setbkcolor(culoare);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,6);
    outtextxy(x/2,175,"TYPES    BK COLORS  NAMES");
    settextstyle(COMPLEX_FONT,HORIZ_DIR,6);
    setcolor(LIGHTRED);
    outtextxy(x/2,300,"L.RED");
    setcolor(CYAN);
    outtextxy(x/2,350,"CYAN");
    setcolor(GREEN);
    outtextxy(x/2,400,"GREEN");
    setcolor(LIGHTMAGENTA);
    outtextxy(x/2,450,"PINK");
    setcolor(WHITE);
    outtextxy(x/2,500,"WHITE");
    setcolor(BLACK);
    if(var==0)
        setcolor(BLUE);
    outtextxy(x/4,300,"NORMAL");
    setcolor(BLACK);
    if(var==1)
        setcolor(BLUE);
    outtextxy(x/4,350,"WINTER");
    setcolor(BLACK);

    if(var==2)

        setcolor(BLUE);
    outtextxy(x/4,400,"SUMMER");
    setcolor(BLACK);

    if(var==3)

        setcolor(BLUE);
    outtextxy(x/4,450,"OLD");
    setcolor(BLACK);

    if(nume1[0]=='0'||nume1[0]==32)
        outtextxy(x-x/4,300,"PLAYER 1  ");
    else
        outtextxy(x-x/4,300,nume1);
    if(nume2[0]=='0'||nume2[0]==32)
        outtextxy(x-x/4,350,"PLAYER 2  ");
    else
        outtextxy(x-x/4,350,nume2);
    baku=false;
    do
    {
        bak();
        if(!baku)
            background(x);
        if(magie!=culoare||tr==1||var1!=var)
            goto revenire;
    }
    while(!baku);
    initialisation();
}

void credits()///c
{
    int x,y;
    x=getmaxx(),y=getmaxy();
    setfillstyle(SOLID_FILL, culoare);
    bar(25,25,x-25,y-25);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,7);
    setcolor(BLUE);
    setbkcolor(culoare);
    outtextxy(x/2-50,80,"CREDITS");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(110,50,"BACK");
    setcolor(BLACK);
    setbkcolor(WHITE);
    readimagefile("prof.jpg",30,90,x-30,410);
    readimagefile("palarie.jpg",30,390,x-30,y-50);
    outtextxy(x/2-25,130,"This project was created by");
    outtextxy(x/2-25,180,"Catalina Vornicu");
    outtextxy(x/2-25,230,"and");
    outtextxy(x/2-25,280,"Elena Opait.");
    readimagefile("soare.gif",30,230,230,400);
    readimagefile("soare.gif",x-230,230,x-30,400);
    outtextxy(x/2-25,380,"We are thankful to our ");
    outtextxy(x/2-25,430,"`Introduction to Programming` professor!");
    outtextxy(x/2-25,580,"Thank you a lot,");
    outtextxy(x/2-25,630,"Lect. Dr. Bogdan Patrut!");
    baku=false;
    do
    {
        bak();
    }
    while(!baku);
    initialisation();
}

void functions(int length,int height)///c
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if (x>=length&&x<=length+200)
        {
            if(y>=height-100&&y<=height-60) //credits
                credits();
            if(y>=height-200&&y<=height-160) //settings
                settings();
            if(y>=height-300&&y<=height-260) //play
                play();
        }
    }
}

void initialisation()///c
{
    /* _select driver and mode*/
    int gdriver = EGA, gmode = EGAHI, errorcode;
    int x,y;
    if(!see)
    {
        /* initialize graphics and local variables */
        initgraph(&gdriver, &gmode, "");


        /* read result of initialization */
        errorcode = graphresult();
        if (errorcode != grOk)     /* an error occurred */
        {
            printf("Graphics error: %s\n", grapherrormsg(errorcode));
            printf("Press any key to halt:");
            getch();
            exit(1);               /* terminate with an error code */
        }
        initwindow(1280,700,"Gobblet gobblers");
        see=1;
    }
    /* window height & width */

    x=getmaxx(),y=getmaxy();
    // readimagefile("C://Proiect//ceva_ok.jpg",0,0,x,y);

    /*opening file*/
    readimagefile("inceput.jpg",0,0,x,y);
    setfillstyle(SOLID_FILL, culoare);
    bar(25,25,x-25,y-25);
    readimagefile("var2.gif",x/2-200,40,x/2+200,y/3);
    readimagefile("albastru.gif",40,y/3+110,500,y/2+y/3+90);
    readimagefile("portocaliu.gif",x-500,y/3+110,x-50,y/3+y/2+90);
    readimagefile("stea1.gif",40,40,400,y/3);
    readimagefile("stea1.gif",x-400,40,x-40,y/3);
   /* readimagefile("flutureroz.gif",40,y-90,90,y-40);
    readimagefile("flutureroz.gif",x-90,y-90,x-40,y-40);
    readimagefile("fluture1.gif",x/2+40,y-90,x/2+120,y-40);*/
   // readimagefile("fluture.gif",x/2-120,y-90,x/2-40,y-40);
   // readimagefile("left.gif",x/2+200,y/3-30,x/2+300,y/3+60);
   // readimagefile("right.gif",x/2-300,y/3-90,x/2-200,y/3+10);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,7);
    setcolor(YELLOW);
    setbkcolor(culoare);
    outtextxy(x/2-10,y/3+50,"PLAY");
    setcolor(RED);
    outtextxy(x/2-10,y/3+150,"SETTINGS");
    setcolor(BLUE);
    outtextxy(x/2-10,y/3+250,"CREDITS");
    setcolor(BROWN);
    outtextxy(x/2-10,y/3+350,"EXIT");

    /*function for exit*/
    do
    {
        exit(x/2-100,y/3+300);
        if(!finish)
            functions(x/2-100,y/3+300);

    }
    while(!finish);

    //getch();
    closegraph();
}
