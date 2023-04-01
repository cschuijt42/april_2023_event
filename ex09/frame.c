// ft_split

#include <stdlib.h>

static void	free_array(char **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static unsigned int	count_strings(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static char	*allocate_substring(char const *s, char c)
{
	int		len;
	char	*str;
	int		i;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**fill_array(char const *s, char **array, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			array[i] = allocate_substring(s, c);
			if (array[i] == NULL)
			{
				free_array(array);
				return (NULL);
			}
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = calloc(sizeof(char *), (count_strings(s, c) + 1));
	if (!array)
		return (NULL);
	return (fill_array(s, array, c));
}


// Actual program

#include <string.h>
#include <stdio.h>

void print_frame_border(size_t max_len) {
	size_t i = 0;
	while (i < max_len + 4) {
		printf("*");
		i++;
	}
	printf("\n");
}

void make_frame(char *str) {
	char **array = ft_split(str, ' ');

	if (!array)
		exit(1);

	size_t len;
	size_t max_len = 0;
	int    i       = 0;

	while (array[i]) {
		len = strlen(array[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}

	print_frame_border(max_len);
	
	size_t extra_space = 0;
	i = 0;
	while (array[i]) {
		printf("* %s", array[i]);

		extra_space = max_len - strlen(array[i]);
		while (extra_space) {
			printf(" ");
			extra_space--;
		}

		printf(" *\n");

		i++;
	}

	print_frame_border(max_len);
}

int main(int ac, char **av) {
	if (ac == 1)
		return (1);

	int i = 1;
	while (i < ac)
	{
		make_frame(av[i]);
		i++;
	}

	return (0);
}
