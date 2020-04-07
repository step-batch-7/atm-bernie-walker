unsigned int get_money(unsigned short int amount)
{
  int result = 0x00000000;
  int denom[] = {2000, 500, 100, 50, 20, 10, 5, 1};

  if (amount > 31999)
  {
    return result;
  }

  for (int i = 0; i < 8; i++)
  {
    result = result << 4;
    result = result | (amount / denom[i]);
    amount = amount % denom[i];
  };

  return result;
}
