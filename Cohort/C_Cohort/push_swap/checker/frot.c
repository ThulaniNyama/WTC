#include <pushswap.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>

void	fra(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmpb;
	t_stack *tmpa;

	tmpb = *stackb;
	tmpa = *stacka;
	if (*stacka && (*stacka)->nx)
	{
		while (tmpa->nx)
		{
			tmpa = tmpa->nx;
		}
		tmpa->nx = *stacka;
		*stacka = (*stacka)->nx;
		(tmpa->nx)->nx = NULL;
		(tmpa->nx)->pv = tmpa;
	}
	(*stacka)->pv = NULL;
}

void	frb(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmpb;
	t_stack *tmpa;

	tmpb = *stackb;
	tmpa = *stacka;
	if (*stackb && (*stackb)->nx)
	{
		while (tmpb->nx)
			tmpb = tmpb->nx;
		tmpb->nx = *stackb;
		*stackb = (*stackb)->nx;
		(tmpb->nx)->nx = NULL;
		(tmpb->nx)->pv = tmpb;
	}
	(*stackb)->pv = NULL;
}

void	frr(t_stack **stacka, t_stack **stackb)
{
	fra(stacka, stackb);
	frb(stacka, stackb);
}
