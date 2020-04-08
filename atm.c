#include "atm.h"

unsigned int get_money(unsigned short int amount)
{
  unsigned int result = 0;
  denom notes = denominations;

  if (amount > 31999)
  {
    return result;
  }

  for (short int i = 0; i < 8; i++)
  {
    result <<= 4;
    result |= amount / notes[i];
    amount %= notes[i];
  };

  return result;
}
