#include <pushswap.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>

#define SWAPTOPB ((*sb)->nx && (*sb)->v < ((*sb)->nx)->v)

/*
static void	rotcor(t_out *ret, t_stack **sa, t_stack **sb, int descending)
{
	int tmp;

	tmp = 0;
	if (descending)
	{
		tmp = getlargest(*sb);
		if (wheredest(*sb) > 0)
			while ((*sb)->v != tmp)
				updateretstack(ret, RB, sa, sb);
		else
			while ((*sb)->v != tmp)
				updateretstack(ret, RRB, sa, sb);
		bassigngroups(sb);
	}
	else
	{
		tmp = getsmallest(*sa);
		if (wheredest(*sa) > 0)
			while ((*sa)->v != tmp)
				updateretstack(ret, RA, sa, sb);
		else
			while ((*sa)->v != tmp)
				updateretstack(ret, RRA, sa, sb);
		aassigngroups(sa);
	}
}
*/

static void	mergestack(t_stack **sa, t_stack **sb, t_out *ret)
{
	t_stack *tmpb;
	int		group;
	t_stack *end;
	int		largest;


	if (!(*sb))
		return ;
	if (SWAPTOPB)
	{
		updateretstack(ret, SB, sa, sb);
		if (bassigngroups(sb) == 1)
			return ;
	}
	largest = 0;
	group = (*sb)->g;
	tmpb = *sb;
	while ((*sb)->g == group)
	{
		updateretstack(ret, PA, sa, sb);
	}
	while ((*sa)->g == group)
	{
		end = getend(sb);
		if (ordered(*sa))
			break;
		else if ((*sa)->v < end->v && ((*sa)->v) < (*sb)->v)
		{
			updateretstack(ret, PB, sa, sb);
			updateretstack(ret, RB, sa, sb);
		}
		else if ((*sa)->v < (*sb)->v)
		{
			while ((*sa)->v < (*sb)->v)
			{
				updateretstack(ret, RB, sa, sb);
			}
			updateretstack(ret, PB, sa, sb);
		}
		else if ((*sa)->v > (*sb)->v && !((*sa)->v < end->v))
		{
			if ((*sa)->v > (largest = getlargest(*sb)))
			{
				while ((*sb)->v != largest)
				{
					updateretstack(ret, RRB, sa, sb);
				}
			}
			else
			{
				while (((*sa)->v > (*sb)->v) && ((*sa)->v > end->v))
				{
					updateretstack(ret, RRB, sa, sb);
					end = getend(sb);
				}
			}
			updateretstack(ret, PB, sa, sb);
		}
		else
		{
			updateretstack(ret, PB, sa, sb);
		}
	}
	rotcor(ret, sa, sb, 1);
	bassigngroups(sb);
}

static void	mergetwo(t_stack **sa, t_stack **sb, t_out *ret)
{
	int	smallest;
	int largest;
	t_stack *end;

	while (*sb)
	{
		end = getend(sa);
		if ((*sb)->v < (smallest = getsmallest(*sa)))
		{
			while ((*sa)->v != smallest)
				updateretstack(ret, RA, sa, sb);
			updateretstack(ret, PA, sa, sb);
		}
		else if ((*sa)->v > (largest = getlargest(*sb)) && ordered(*sa))
		{
			while ((*sb)->v != largest)
				updateretstack(ret, RB, sa, sb);
			updateretstack(ret, PA, sa, sb);
		}
		else if ((*sb)->v > (*sa)->v)
			updateretstack(ret, RA, sa, sb);
		else if ((*sb)->v < (*sa)->v && (*sb)->v > end->v)
			updateretstack(ret, PA, sa, sb);
		else if ((*sb)->v < (*sa)->v && (*sb)->v < end->v)
			updateretstack(ret, RRA, sa, sb);
	}
	smallest = getsmallest(*sa);
	rotcor(ret, sa, sb, 0);
}

int	similarsizegroup(t_stack *sb)
{
	int i;
	int j;
	t_stack *tmp;

	tmp = sb;
	i = 0;
	j = 0;
	//ft_putstr_fd("you are here\n", 2);
	while (tmp && tmp->g == -1)
	{
	//	ft_putstr_fd("you are here\n", 2);
		i++;
		tmp = tmp->nx;
	}
	while (tmp && tmp->g == -2)
	{
	//	ft_putstr_fd("second\n", 2);
		j++;
		tmp = tmp->nx;
	}
	//ft_putstr_fd("third\n", 2);
	if (i > (j / 2) || j < 16)
		return (1);
	return (0);
}

static void	timdecision(t_stack **sa, t_stack **sb, t_stack *end, t_out *ret)
{
	if ((!(*sa)->nx) || ((*sa)->v < end->v && (*sa)->v < ((*sa)->nx)->v))
	{
		if ((*sb) && ((*sa)->v < (*sb)->v) && (bassigngroups(sb) > 1))
		{
			if (similarsizegroup(*sb))
				mergestack(sa, sb, ret);
			//ft_putstr_fd("foruth\n", 2);
			//mergestack(sa, sb, ret);
		//	ft_putstr_fd("fifth\n", 2);

		}
		updateretstack(ret, PB, sa, sb);
	}
	else if (((*sa)->nx)->v < (*sa)->v)
	{
		updateretstack(ret, SA, sa, sb);
	}
	else if (((*sa)->nx)->v <= (end)->v && ((*sa)->nx)->v < (*sa)->v)
	{
		updateretstack(ret, SA, sa, sb);
	}
	else if ((((stacklen(*sa) == 1) && (end->v < (*sa)->v))) ||
			(end->v < (*sa)->v && (end)->v <= ((*sa)->nx)->v))
	{
		updateretstack(ret, RRA, sa, sb);
	}
	if((*sb) && (*sb)->v < ((getend(sb))->v))
	{
		updateretstack(ret, RB, sa, sb);
	}
}

void	stim(t_stack **sa, t_stack **sb, t_out *ret)
{
	int i;
	t_stack *end;

	i = 0;
	end = getend(sa);
	if (aassigngroups(sa) == 1)
		return ;
	while (*sa)
	{
		timdecision(sa, sb, end, ret);
		aassigngroups(sa);
		bassigngroups(sb);
		end = getend(sa);
		if (ordered(*sa))
		{
			while (bassigngroups(sb) > 1)
				mergestack(sa, sb, ret);
			mergetwo(sa, sb, ret);
			break;
		}
	}
}














