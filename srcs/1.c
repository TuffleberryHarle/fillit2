#include "fillit.h"

int				ext_k;
int				ext_j;
int				ext_num;

int		tetr_verify(char **figure)
{
	int			row;
	int			col;
	int			num;
	
	row = 0;
	col = 0;
	num = 0;
	while (row < 4)
	{
		while (figure[row][col] != '\0')
		{
			if (figure[row][col] != '#' && figure[row][col] != '.')
				return (0);
			if (figure[row][col++] == '#')
				num++;
		}
		col = 0;
		row++;
	}
	row = 0;
	ext_num = -1;
	if (num == 4 && conect_check(&row, &col, &num, figure))
		return (1);
	return (0);
}

void	tetr_array(char **figure, t_figure *fig, int *first, int *ext_k)
{
	ext_j = -1;
	while (*ext_k < 4)
	{
		while (figure[*ext_k][++ext_j] != '\0')
		{
			if (figure[*ext_k][ext_j] == '#')
			{
				if (++ext_num == 0)
				{
					first[0] = (int)ext_j;
					first[1] = (int)*ext_k;
					fig->x[0] = (int)ext_j;
					fig->y[0] = (int)*ext_k;
				}
				else
				{
					(ext_j < first[0]) ? first[0] = ext_j : first[0];
					fig->y[ext_num] = (int)*ext_k;
					fig->x[ext_num] = (int)ext_j;
				}
			}
		}
		ext_j = -1;
		*ext_k += 1; /++
	}
}

int		tetr_check2(char **figure, t_list **figures, int *fig_num, int *i)
{
	int			*first;
	t_figure	*fig;
	
	ext_k = 0;
	fig = (t_figure*)malloc(sizeof(t_figure));
	fig->x = (int*)malloc(sizeof(int) * 4);
	fig->y = (int*)malloc(sizeof(int) * 4);
	first = (int*)malloc(sizeof(int) * 2);
	if (*i == 4)
	{
		figure[5] = NULL;
		if (!(tetr_verify(figure)))
			return (0);
		*i = 0;
		tetr_array(figure, fig, first, &ext_k);
		correct_coord(fig, figures, first);
		(*fig_num)++;
		while (*i < 4)
		{
			free(figure[*i]);
			(*i)++;
		}
		free(figure);
	}
	return (1);
}

int		tetr_check1(char **line, int *row, char **figure, int *i)
{
	static int tetr;
	
	if (*row < 5 && tetr == 0)
		tetr = 0;
	if (!(**line))
	{
		if (*row == 5)
		{
			*row = 1;
			tetr++;
			*i = 0;
			return (1);
		}
		return (0);
	}
	if ((ft_strlen(*line)) == 4)
	{
		figure[*i] = ft_strdup(*line);
		(*row)++;
		free(*line);
		(*i)++;
	}
	if (tetr >= 25 || *row > 5)
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
	fd = open("samples/1", O_RDONLY);
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
