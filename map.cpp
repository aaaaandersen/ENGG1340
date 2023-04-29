#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string map_array[18];

// TO OPEN THE MAP
void openmap1(){
   int i=0;
   ifstream abc;
   abc.open ("map1.txt");
   string line;
   while(getline (abc,line))
   {
      map_array[i]=line;
      i++;
   }

abc.close();
//P IS POISON
//M IS MONSTER
//? IS UNKNOWN
//W IS WEAPON
map_array[1][20]='P';
map_array[1][28]='M';
map_array[4][11]='P';
map_array[8][28]='M';
map_array[12][7]='?';
map_array[14][31]='M';
map_array[17][21]='W';
}
//TO PRINT THE MAP
void show_map(){
       for (int i=0;
       i<18;
       i++)
       {
         cout<<map_array[i]<<endl;

       }
}

void openmap2(){
   int i=0;
   ifstream abc;
   abc.open ("map2.txt");
   string line;
   while(getline (abc,line))
   {
      map_array[i]=line;
      i++;
   }

abc.close();

map_array[2][19]='?';
map_array[2][21]='M';
map_array[6][8]='?';
map_array[6][20]='P';
map_array[8][5]='?';
map_array[11][19]='M';
map_array[11][34]='?';
map_array[12][34]='M';
map_array[16][12]='W';
map_array[16][23]='P';
map_array[16][34]='W';
}

void openmap3(){
   int i=0;
   ifstream abc;
   abc.open ("map3.txt");
   string line;
   while(getline (abc,line))
   {
      map_array[i]=line;
      i++;
   }

abc.close();

map_array[5][27]='?';
map_array[6][29]='M';
map_array[8][10]='W';
map_array[8][33]='W';
map_array[11][3]='P';
map_array[14][2]='?';
map_array[14][29]='M';
map_array[14][35]='?';
map_array[16][0]='P';
map_array[17][29]='M';
map_array[18][29]='P';
}

void openmap4(){
   int i=0;
   ifstream abc;
   abc.open ("map4.txt");
   string line;
   while(getline (abc,line))
   {
      map_array[i]=line;
      i++;
   }

abc.close();

map_array[2][29]='W';
map_array[4][34]='W';
map_array[6][2]='P';
map_array[6][3]='?';
map_array[7][2]='?';
map_array[7][3]='M';
map_array[12][18]='M';
map_array[12][25]='M';
map_array[14][19]='P';
map_array[17][2O]='?';
map_array[17][23]='W';
}

void openmap5(){
   int i=0;
   ifstream abc;
   abc.open ("map5.txt");
   string line;
   while(getline (abc,line))
   {
      map_array[i]=line;
      i++;
   }

abc.close();

map_array[2][10]='P';
map_array[2][11]='M';
map_array[5][19]='?';
map_array[8][16]='W';
map_array[10][9]='?';
map_array[10][20]='M';
map_array[10][28]='?';
map_array[12][24]='?';
map_array[13][6]='?';
map_array[13][14]='M';
map_array[14][27]='W';
map_array[15][11]='P';
map_array[15][12]='?';
map_array[15][3O]='?';
map_array[16][11]='P';
map_array[16][12]='W';
}

int main(){

   openmap1();
   show_map();

   }