#include <pushswap.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>

static void	insertbest(t_stack **sa, t_stack **sb, t_out *ret)
{
	t_stack *tmp;
	t_stack *target;
	int moves;

	tmp = *sa;
	target = tmp;
	moves = tmp->moves;
	while (tmp)
	{
		if (tmp->moves < moves)
		{
			moves = tmp->moves;
			target = tmp;
		}
		tmp = tmp->nx;
	}
	prepoprot(target, sa, sb, ret);
	updateretstack(ret, PB, sa, sb);
}

static void	mergetwo(t_stack **sa, t_stack **sb, t_out *ret)
{
	while (*sb)
	{
		if ((*sb)->v > getlargest(*sa))
		{
			rotcor(ret, sa, sb, 0);
			updateretstack(ret, PA, sa, sb);
		}
		else if ((*sb)->v < getsmallest(*sa))
		{
			rotcor(ret, sa, sb, 0);
			updateretstack(ret, PA, sa, sb);
		}
		else if ((*sb)->v > (*sa)->v )
			updateretstack(ret, RA, sa, sb);
		else if ((*sb)->v < (*sa)->v && (*sb)->v > (getend(sa))->v)
			updateretstack(ret, PA, sa, sb);
		else
			updateretstack(ret, RRA, sa, sb);
	}
}

static int	threesort(t_stack **sa, t_stack **sb, t_out *ret)
{
	if (stacklen(*sa) != 3)
		return (0);
	if ((*sa)->v == getlargest(*sa) && ((*sa)->nx)->v < (getend(sa))->v)
		return (1);
	else if ((*sa)->v > ((*sa)->nx)->v)
		updateretstack(ret, SA, sa, sb);
	else if ((*sa)->v == getsmallest(*sa) && ((*sa)->nx)->v == getlargest(*sa))
		updateretstack(ret, SA, sa, sb);
	return (1);
}

static int numsort(t_stack **sa, t_stack **sb, t_out *ret, int size)
{
	int i;
	int num;

	i = 0;
	num = size;
	if (stacklen(*sa) != num)
		return (0);
	while (i < (num - 3))
	{
		rotcor(ret, sa, sb, 0);
		updateretstack(ret, PB, sa, sb);
		i++;
	}
	threesort(sa, sb, ret);
	i = 0;
	while (i < (num - 3))
	{
		rotcor(ret, sa, sb, 0);
		updateretstack(ret, PA, sa, sb);
		i++;
	}
	return (1);
}

void	fortysort(t_stack **sa, t_stack **sb, t_out *ret)
{
	int i;
	int len;

	if (ordered(*sa) == 1)
		return ;
	i = 0;
	len = 3;
	if (stacklen(*sa) > 101)
		len = 7;
	while (*sa)
	{
		if (almostordered(*sa) || numsort(sa, sb, ret, len))
			{
				rotcor(ret, sa, sb, 0);
				mergetwo(sa, sb, ret);
				rotcor(ret, sa, sb, 0);
				break;
			}
		astructmoves(*sa);
		bstructmoves(*sa, *sb);
		movedir(*sa);
		insertbest(sa, sb, ret);
	}
}
