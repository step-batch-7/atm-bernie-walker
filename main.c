#include <stdio.h>
#include "atm.h"

#define hex_msb 0xf0000000

void print_denoms(unsigned int denom_marker)
{
  denom notes = denominations;

  for (int i = 0; i < 8; i++)
  {
    unsigned int denom_count = (denom_marker & hex_msb) >> 28;
    printf("%u notes of %u\n", denom_count, notes[i]);
    denom_marker = denom_marker << 4;
  }
}

int main(void)
{
  unsigned short int amounts[] = {1, 10, 39, 589, 2590, 31999};

  for (int i = 0; i < 6; i++)
  {
    printf("Amount ==> %hu\n\n", amounts[i]);
    print_denoms(get_money(amounts[i]));
    printf("\n");
  }

  return 0;
}
