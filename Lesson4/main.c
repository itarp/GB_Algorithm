#include <stdio.h>
#include <string.h>

void decToBin(unsigned int dec, char *strBin);
double toPower(double num, int pow);
double toPower2(double num, int pow);
int routes(int x, int y, int field[][5]);

int main() {
  // Задание 1
  printf("----------- Task 1 ------------\n");
  char bin[33] = "";
  unsigned int dec = 0xf0f0f0f0;
  decToBin(dec, bin);
  printf("dec %u -> bin %s\n", dec, bin);

  // Задание 2
  printf("----------- Task 2 ------------\n");
  printf("%f\n", toPower(3., 3));

  // Задание 3
  printf("----------- Task 3 ------------\n");  
  printf("%f\n", toPower2(3., 3));

  // Задание 4
  printf("----------- Task 4 ------------\n");
  const int sizeX = 5;
  const int sizeY = 5;
  int playField[5][5] = {
    0,0,0,1,0,
    0,1,0,0,0,
    0,0,0,1,0,
    0,0,0,0,0,
    0,0,1,0,0
  };
    
  for (int y = 0; y < sizeY; ++y) {
    for(int x = 0; x < sizeX; ++x)
      printf("%5d", routes(x, y, playField));
    printf("\n");
    }
  
  return 0;
}

void decToBin(unsigned int dec, char *strBin) {
  if(dec){
    decToBin(dec >> 1, strBin);
    strcat(strBin, (dec & 1)==0 ? "0" : "1");
    //      printf ("%d", dec & 1);
  }
}

double toPower(double num, int pow){
  if(pow == 0)
    return 1;
  if(pow > 0)
    return toPower(num, pow - 1) * num;
  return toPower(1 / num, -pow);
}

double toPower2(double num, int pow) {
  if(pow == 0)
    return 1;
  if(pow % 2)
    return num * toPower2(num, pow - 1);
  if(pow > 0)
    return toPower2((num * num), (pow / 2));
  return toPower2(1 / num, -pow);
}

int routes(int x, int y, int field[][5]){
  if(field[y][x] == 1)
    return 0;
  if (x == 0 && y == 0) 
    return 0;
  else if (x == 0){
    if (routes(x, y - 1, field) == 0 && y != 1)
      return 0;
    return 1;
  }
  else if (y == 0){
    if (routes(x - 1, y, field) == 0 && x != 1)
	return 0;
    return 1;
  }
  return routes(x, y - 1, field) + routes(x - 1, y, field);
}
