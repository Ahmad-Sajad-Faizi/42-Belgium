int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}
#include <stdio.h>

int main(void)
{
	char *test1 = "hello";
	char *test2 = "";
	char *test3 = "A";
	char *test4 = "This is a long text.";

	printf("Length of \"%s\" = %d\n", test1, ft_strlen(test1));
    printf("Length of \"%s\" = %d\n", test2, ft_strlen(test2));
	printf("Length of \"%s\" = %d\n", test3, ft_strlen(test3));
    printf("Length of \"%s\" = %d\n", test4, ft_strlen(test4));
    return (0);
}
