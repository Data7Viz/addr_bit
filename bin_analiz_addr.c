#include <stdio.h>
#define RAZR 12           //колличество разрядов выводим на печать
#define GEL "\033[1;33m"
#define GRIN "\033[1;32m"
#define ROZ "\033[1;35m"
#define SIN "\033[1;34m"
#define RES "\033[0m"
void hex_dec_nom_raz()
{
        printf("\n\n");
        int dec = 1; // строка десятичное представление двоичного числа dec
        for (int i = 0; i <= RAZR; i ++)
        {
                printf(GRIN "%8d" RES , dec);
                dec = dec << 1;
        }
        printf("\n\n");

        for (int i = 0; i <= RAZR; i ++) //строка смещение в кэш номер индекса
        {
                printf(ROZ "%8d" RES ,1 << (i % 6));
        }
        printf("\n\n");

        for (int j = 0; j <= RAZR; j ++) // строка номер разряда бита
        {
                printf(SIN  "%8d" RES , j);
        }
        printf("\n\n");
}

int bin_addr (unsigned long addr) //функция двоичного вида адреса
{
        int bin, offset_kech, offset_page, mask = 63;
        for (int i = 0; i <= RAZR; i ++)
        {
                bin = (addr >> i) & 1; 
		if (bin == 1) 
		{ 
			printf(GEL "%8d" RES, bin); 
		}
		else 
		{ 
			printf("%8d", bin); 
		} 
        }
	offset_kech = addr & mask;
	offset_page = (mask << 6) & addr;
	printf("\nСмещение в КЭШ %d Смещение в странице %d\n", offset_kech, offset_page);
        printf("\n\n");
        return 0;
}
int main ()
{
        unsigned long addr_mem;
        hex_dec_nom_raz ();
        while (1)
        {
                if (scanf("%li", &addr_mem) == 1)
                {
                        bin_addr (addr_mem);
                }
                else
		{
                        break;
                }
        }
        return 0;
}

