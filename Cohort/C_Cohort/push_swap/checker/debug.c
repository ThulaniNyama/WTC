#include <pushswap.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>

static void phelp(t_stack *tmpa, t_stack *tmpb)
{
		if (tmpa && tmpb)
		{
			ft_putnbr_fd((tmpa)->v, 2);
			ft_putstr_fd("\t", 2);
			ft_putnbr_fd((tmpb)->v, 2);
			ft_putstr_fd("\n", 2);
		}
		else if (tmpa)
		{
			ft_putnbr_fd((tmpa)->v, 2);
			ft_putstr_fd("\t", 2);
			ft_putstr_fd("\n", 2);
		}
		else if (tmpb)
		{
			ft_putstr_fd("\t\t", 2);
			ft_putnbr_fd(tmpb->v, 2);
			ft_putstr_fd("\n", 2);
		}
}

void	debug_pstacks(t_stack *stacka, t_stack *stackb)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = stacka;
	tmpb = stackb;

	ft_putstr_fd("Stack A\tStack BB\n", 2);
	while (tmpa || tmpb)
	{
		phelp(tmpa, tmpb);
		if (tmpa && tmpb)
		{
			tmpa = (tmpa)->nx;
			tmpb = (tmpb)->nx;
		}
		else if (tmpa)
			tmpa = (tmpa)->nx;
		else if (tmpb)
			tmpb = (tmpb)->nx;
	}
}

int	debug_ops(t_op *begin)
{
	int i;

	i = 0;
	while (begin)
	{
		if (begin->op == nothing)
		{
			break;
		}
		i++;
		printelement(begin->op);
		begin = begin->next;
	}
	ft_putstr_fd("Total number of Ops is:", 2);
	ft_putnbr_fd(i, 2);
	ft_putstr_fd("\n", 2);
	return (i);
}
