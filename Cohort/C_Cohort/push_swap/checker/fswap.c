#include <pushswap.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>

void	fsa(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpb = *stackb;
	if (*stacka && (*stacka)->nx)
	{
		tmpa = (*stacka);
		(*stacka) = (*stacka)->nx;
		tmpa->nx = (*stacka)->nx;
		tmpa->pv = (*stacka);
		(*stacka)->nx = tmpa;
		(*stacka)->pv = NULL;
	}
	tmpa = *stacka;
	while (tmpa->nx)
	{
		(tmpa->nx)->pv = tmpa;
		tmpa = tmpa->nx;
	}
}

void	fsb(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = *stacka;
	if (*stackb && (*stackb)->nx)
	{
		tmpb = (*stackb);
		(*stackb) = (*stackb)->nx;
		tmpb->nx = (*stackb)->nx;
		tmpb->pv = (*stackb);
		(*stackb)->nx = tmpb;
		(*stackb)->pv = NULL;
	}
	tmpb = *stackb;
	while (tmpb->nx)
	{
		(tmpb->nx)->pv = tmpb;
		tmpb = tmpb->nx;
	}
}

void	fss(t_stack **stacka, t_stack **stackb)
{
	fsa(stacka, stackb);
	fsb(stacka, stackb);
}
