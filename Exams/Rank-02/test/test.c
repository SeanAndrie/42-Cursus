#include <unistd.h>

void    print_bits(unsigned char octet)
{
    char bit;
    int i = 8;

    while (i--)
    {
        bit = ((octet >> i) & 1) + '0';
        write(1, &bit, 1);
    }
}

unsigned char swap_bits(unsigned char octet)
{
    return ((octet >> 4 ) | (octet << 4));
}

unsigned char reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char res = 0;

    while (i--)
    {
        res = (res << 1) | (octet & 1);
        octet >>= 1;
    }
    return (res);
}

int main(void)
{
    print_bits(reverse_bits(2));
    write(1, "\n", 1);
    print_bits(swap_bits(2));
    return (0);
}
