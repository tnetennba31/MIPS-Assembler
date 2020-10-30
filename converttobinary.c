#include<stdio.h>
#include<string.h>

char hexreturn(unsigned int opcode, unsigned int rs, unsigned int rt, unsigned int rd, unsigned int shamt, unsigned int funct)
{

int binaryarray[32];

int opcodearray[6];
int opcodearraycopy[6];

int rsarray[5];
int rsarraycopy[5];

int rtarray[5];
int rtarraycopy[5];

int rdarray[5];
int rdarraycopy[5];

int shamtarray[5];
int shamtarraycopy[5];

int functarray[6];
int functarraycopy[6];

for (int i=0; i< 6; i++)                        //opcode
{                                               //opcode but it was dec whoops OPCODE and FUNC needs t o converted to string/char input 

    opcodearray[i] = opcode % 2;
    opcode = opcode /2;
}

for(int op=6-1,pe=0; op>=0; op--,pe++)
{
opcodearraycopy[pe]=opcodearray[op];
}

for(int opflip=0; opflip<6; opflip++)
{
opcodearray[opflip]=opcodearraycopy[opflip];
}



for (int i=0; i< 5; i++)                        //rs
{
    rsarray[i] = rs % 2;
    rs = rs /2;
}

for(int rsa=5-1,sr=0; rsa>=0; rsa--,sr++)
{
rsarraycopy[sr]=rsarray[rsa];
}

for(int rsflip=0; rsflip<5; rsflip++)
{
rsarray[rsflip]=rsarraycopy[rsflip];
}




for (int i=0; i< 5; i++)                        //rt
{
    rtarray[i] = rt % 2;
    rt = rt /2;
}

for(int rta=5-1,tr=0; rta>=0; rta--,tr++)
{
rtarraycopy[tr]=rtarray[rta];
}

for(int rtflip=0; rtflip<5; rtflip++)
{
rtarray[rtflip]=rtarraycopy[rtflip];
}





for (int i=0; i< 5; i++)                        //rd
{
    rdarray[i] = rd % 2;
    rd = rd /2;
}

for(int rda=5-1,dr=0; rda>=0; rda--,dr++)
{
rdarraycopy[dr]=rdarray[rda];
}

for(int rdflip=0; rdflip<5; rdflip++)
{
rdarray[rdflip]=rdarraycopy[rdflip];
}





for (int i=0; i< 5; i++)                        //shamt
{
   shamtarray[i] = shamt % 2;
    shamt = shamt /2;
}

for(int shamta=5-1,shamtb=0; shamta>=0; shamta--,shamtb++)
{
shamtarraycopy[shamtb]=shamtarray[shamta];
}

for(int shflip=0; shflip<5; shflip++)
{
shamtarray[shflip]=shamtarraycopy[shflip];

}



for (int i=0; i< 6; i++)                        //funct
{
    functarray[i] = funct % 2;
    funct = funct /2;
}

for(int fu=6-1,uf=0; fu>=0; fu--,uf++)
{
functarraycopy[uf]=functarray[fu];
}

for(int fuflip=0; fuflip<6; fuflip++)
{
functarray[fuflip]=functarraycopy[fuflip];
}





int temp=0;                                     //32bit string
for(int m =0; m<32; m++)
{
    if(m<6)
    {
        binaryarray[m] = opcodearray[m];
    }
    if(m>=6)
    {
        temp = rsarray[m-6];
        binaryarray[m] = temp;
    }
    if(m>=11)
    {   
        temp = rtarray[m-11];
        binaryarray[m] = temp;
    }
    if(m>=16)
    {
        temp = rdarray[m-16];
        binaryarray[m] = temp;
    }
    if(m>=21)
    {
        temp = shamtarray[m-21];
        binaryarray[m] = temp;
    }
    if(m>=26)
    {
        temp = functarray[m-26];
        binaryarray[m] = temp;
    }
}




char hexstring[8];

int newstart;
int temp4=0;
char hex;


int check1=0;
int check2=1;
int check3=2;
int check4=3;
for(int l=0; l<8; l++)
{

    char hex;


    if(binaryarray[check1]==0 && binaryarray[check2]==0 && binaryarray[check3]==0 && binaryarray[check4]==0)
    {
        hex = '0';
    }
    if(binaryarray[check1]==0 && binaryarray[check2]==0 && binaryarray[check3]==0 && binaryarray[check4]==1)
    {
        hex = '1';
    }
    if(binaryarray[check1]==0 && binaryarray[check2]==0 && binaryarray[check3]==1 && binaryarray[check4]==0)
    {
        hex = '2';
    }
    if(binaryarray[check1]==0 && binaryarray[check2]==0 && binaryarray[check3]==1 && binaryarray[check4]==1)
    {
        hex = '3';
    }
    if(binaryarray[check1]==0 && binaryarray[check2]==1 && binaryarray[check3]==0 && binaryarray[check4]==0)
    {
        hex = '4';
    }
    if(binaryarray[check1]==0 && binaryarray[check2]==1 && binaryarray[check3]==0 && binaryarray[check4]==1)
    {
        hex = '5';
    }
    if(binaryarray[check1]==0 && binaryarray[check2]==1 && binaryarray[check3]==1 && binaryarray[check4]==0)
    {
        hex = '6';
    }
    if(binaryarray[check1]==0 && binaryarray[check2]==1 && binaryarray[check3]==1 && binaryarray[check4]==1)
    {
        hex = '7';
    }
    if(binaryarray[check1]==1 && binaryarray[check2]==0 && binaryarray[check3]==0 && binaryarray[check4]==0)
    {
        hex = '8';
    }
    if(binaryarray[check1]==1 && binaryarray[check2]==0 && binaryarray[check3]==0 && binaryarray[check4]==1)
    {
        hex = '9';
    }
    if(binaryarray[check1]==1 && binaryarray[check2]==1 && binaryarray[check3]==1 && binaryarray[check4]==0)
    {
        hex = 'a';
    }
    if(binaryarray[check1]==1 && binaryarray[check2]==0 && binaryarray[check3]==1 && binaryarray[check4]==1)
    {
        hex = 'b';
    }
    if(binaryarray[check1]==1 && binaryarray[check2]==1 && binaryarray[check3]==0 && binaryarray[check4]==0)
    {  hex = 'c';

    }
    if(binaryarray[check1]==1 && binaryarray[check2]==1 && binaryarray[check3]==0 && binaryarray[check4]==1)
    {
        hex = 'd';
    }
    if(binaryarray[check1]==1 && binaryarray[check2]==1 && binaryarray[check3]==1 && binaryarray[check4]==0)
    {
        hex = 'e';
    }
    if(binaryarray[check1]==1 && binaryarray[check2]==1 && binaryarray[check3]==1 && binaryarray[check4]==1)
    {
        hex = 'f';
    }

    check1=check1+4;
    check2=check2+4;
    check3=check3+4;
    check4=check4+4;
    //printf("%c", hex);
    hexstring[l]=hex;
    //printf("\n");

}

for (int f=0; f< 32; f++)
{
    //printf("%s", hexstring[f]);
    //printf("%d", binaryarray[f]);
}
char string[100];
strcpy(string, hexstring);
char xstr[100];
strcpy(xstr, "0x");
strcat(xstr, hexstring);
//printf("%s", xstr);




return xstr;












}