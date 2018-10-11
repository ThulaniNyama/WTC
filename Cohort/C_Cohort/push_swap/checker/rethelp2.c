#include <pushswap.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>

int		getsmallest(t_stack *sb)
{
	int		smallest;
	t_stack	*tmp;

	tmp = sb;
	smallest = tmp->v;
	while (tmp)
	{
		if (smallest > tmp->v)
			smallest = tmp->v;
		tmp = tmp->nx;
	}
	return (smallest);
}

void	updateretstackrev(t_out *ret, t_onum op, t_stack **sa, t_stack **sb)
{
	t_out *tmp;

	tmp = ret;
	while (tmp->nx)
		tmp = tmp->nx;
	tmp->num = op;
	tmp->nx = outinit();
	dooprev(op, sa, sb);
}

void	updateretstack(t_out *ret, t_onum op, t_stack **sa, t_stack **sb)
{
	t_out *tmp;

	tmp = ret;
	while (tmp->nx)
		tmp = tmp->nx;
	tmp->num = op;
	tmp->nx = outinit();
	doop(op, sa, sb);
}

void	printret(t_out *ret)
{
	int i;

	i = 0;
	while (ret)
	{
		if (ret->num == NOTHING)
		{
			break;
		}
		printelement2(ret->num);
		ret = ret->nx;
		i++;
	}
}

int	retnumber(t_out *ret)
{
	int i;

	i = 0;
	while (ret->num != NOTHING)
	{
		i++;
		ret = ret->nx;
	}
	return (i);
}
