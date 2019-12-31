#include "fillit.h"

int				global_k;
int				global_j;
int				global_count;

int		verify(char **file)
{
	int			r;
	int			c;
	int			num;
	
	r = 0;
	c = 0;
	num = 0;
	while (r < 4)
	{
		while (file[r][c] != '\0')
		{
			if (file[r][c] != '#' && file[r][c] != '.')
				return (0);
			if (file[r][c++] == '#')
				num++;
		}
		c = 0;
		r++;
	}
	r = 0;
	global_count = -1;
	if (num == 4 && conections_sum(&r, &c, &num, file))
		return (1);
	return (0);
}

void	coord_array(char **figure, t_figure *fig, int *first, int *g_k)
{
	global_j = -1;
	while (*g_k < 4)
	{
		while (figure[*g_k][++global_j] != '\0')
		{
			if (figure[*g_k][global_j] == '#')
			{
				if (++global_count == 0)
				{
					first[0] = (int)global_j;
					first[1] = (int)*g_k;
					fig->x[0] = (int)global_j;
					fig->y[0] = (int)*g_k;
				}
				else
				{
					(global_j < first[0]) ? first[0] = global_j : first[0];
					fig->y[global_count] = (int)*g_k;
					fig->x[global_count] = (int)global_j;
				}
			}
		}
		global_j = -1;
		*g_k += 1;
	}
}

int		tetr_check2(char **figure, t_list **figures, int *fig_num, int *i)
{
	int			*first;
	t_figure	*fig;
	
	global_k = 0;
	fig = (t_figure*)malloc(sizeof(t_figure));
	fig->x = (int*)malloc(sizeof(int) * 4);
	fig->y = (int*)malloc(sizeof(int) * 4);
	first = (int*)malloc(sizeof(int) * 2);
	if (*i == 4)
	{
		figure[5] = NULL;
		if (!(verify(figure)))
			return (0);
		*i = 0;
		coord_array(figure, fig, first, &global_k);
		correct_coords(fig, figures, first);
		*fig_num += 1;
		while (*i < 4)
		{
			free(figure[*i]);
			*i += 1;
		}
		free(figure);
	}
	return (1);
}

int		tetr_check1(char **line, int *text, char **figure, int *i)
{
	static int tetr;
	
	if (*text < 5 && tetr == 0)
		tetr = 0;
	if (!(**line))
	{
		if (*text == 5)
		{
			*text = 1;
			tetr++;
			*i = 0;
			return (1);
		}
		return (0);
	}
	if ((ft_strlen(*line)) == 4)
	{
		figure[*i] = ft_strdup(*line);
		(*text)++;
		free(*line);
		(*i)++;
	}
	if (tetr >= 25 || *text > 5)
		return (0);
	return (1);
}

int		is_valid(int ac, char **av, int *fig_num, t_list **figures)
{
	int			fd;
	char		*line;
	char		**figure;
	int			row;
	int			i;
	
	i = 0;
	row = 1;
	figure = NULL;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0 && row < 6)
	{
		if (row == 1)
			if (!(figure = (char**)malloc(sizeof(*figure) * 5)))
				return (0);
		if (!(tetr_check1(&line, &row, figure, &i)))
			return (0);
		if (!(tetr_check2(figure, figures, fig_num, &i)))
			return (0);
	}
	if (row < 5)
		return (0);
	return (1);
}
