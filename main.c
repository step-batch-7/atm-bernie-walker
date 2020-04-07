#include <stdio.h>
#include "atm.h"

void print_denoms(unsigned int denom_marker)
{
  int denoms[] = {2000, 500, 100, 50, 20, 10, 5, 1};

  for (int i = 0; i < 8; i++)
  {
    unsigned int denom_count = (denom_marker & 0xf0000000) >> 28;
    printf("%u notes of %u\n", denom_count, denoms[i]);
    denom_marker = denom_marker << 4;
  }
}

int main(void)
{
  unsigned short int amounts[] = {1, 10, 39, 589, 2590, 31999};

  for (int i = 0; i < 6; i++)
  {
    printf("Amount ==> %u\n\n", amounts[i]);
    print_denoms(get_money(amounts[i]));
    printf("\n");
  }

  return 0;
}
