#include <stdio.h>

int isPrime(int const num);

int main() {
  for(int i = 0; i < 100; i++)
    if (isPrime(i))
      printf("Число - %d - простое\n", i, isPrime(i));
  return 0;
}

int isPrime(int const num) {
  if (num <= 3)
    return num > 1;
  else if(num % 2 == 0 || num % 3 == 0)
    return 0;
  else {
    for(int i = 5; i * i <= num; i += 6) 
      if(num % i == 0 || num % (i + 2) == 0)
	return 0;
    return 1;
  }
}
