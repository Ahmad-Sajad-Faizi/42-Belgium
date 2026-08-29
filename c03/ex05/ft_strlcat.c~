unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int dest_len;
	unsigned int src_len;
	i = 0;
	j = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	while (j < src_len && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
#include <stdio.h>
int main(void)
{
        char dest1[20] = "Hello";
        char src1[] = " World";
        unsigned int ret1;

        printf("Before: dest = \"%s\"\n", dest1);
        ret1 = ft_strlcat(dest1, src1, 20);
        printf("After:  dest = \"%s\"\n", dest1);
        printf("Return: %u (Expected: 11)\n\n", ret1);

        char dest2[10] = "Hello";
        char src2[] = " World";
        unsigned int ret2;

        printf("Before: dest = \"%s\"\n", dest2);
        ret2 = ft_strlcat(dest2, src2, 8);
        printf("After:  dest = \"%s\"\n", dest2);
        printf("Return: %u (Expected: 11)\n\n", ret2);

        char dest3[10] = "Hello";
        char src3[] = " World";
        unsigned int ret3;

        printf("Before: dest = \"%s\"\n", dest3);
        ret3 = ft_strlcat(dest3, src3, 3);
        printf("After:  dest = \"%s\"\n", dest3);
        printf("Return: %u (Expected: 9)\n\n", ret3);

        char dest4[10] = "Hello";
        char src4[] = " World";
        unsigned int ret4;

        printf("Before: dest = \"%s\"\n", dest4);
        ret4 = ft_strlcat(dest4, src4, 0);
        printf("After:  dest = \"%s\"\n", dest4);
        printf("Return: %u (Expected: 6)\n\n", ret4);

        return (0);
}
