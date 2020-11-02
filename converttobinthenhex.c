#include "converttobinthenhex.h"

char hexreturn(uint32_t num)
{
//printf("%" PRIu32 "\n",num);

int rem=1;
long binary=0;
int temp=1;
int binaryarray[32];
int i=0;

while(i<32)
{
    binaryarray[i] = num%2;
    num = num/2;
    i++;

}

int binaryarraycopy[32];

for(int b=31,sr=0; b>=0; b--,sr++)
{
binaryarraycopy[sr]=binaryarray[b];
}

for(int bflip=0; bflip<32; bflip++)
{
binaryarray[bflip]=binaryarraycopy[bflip];
}


for (int i=0; i< 32; i++)                        
{                                               
//printf("%d", binaryarray[i]);
//printf("%d\n", i);

}
//printf("%d", binary);


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
//printf("%s", xstr);

return string;

}