unsigned char reverse_bits(unsigned char octet)
{
    int i;
    unsigned char res;
    
    i = 8;
    res = 0;
    while (i--)
    {
        res = (res << 1) | (octet & 1);
        octet >>= 1;
    }
    return (res);
}
