#include <pushswap.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>

void	fpb(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmp;

	tmp = *stacka;
	if (*stacka)
	{
		if (!(*stackb))
		{
			*stackb = *stacka;
			*stacka = (*stacka)->nx;
			(*stackb)->nx = NULL;
			(*stackb)->pv = NULL;
		}
		else
		{
			*stacka = (*stacka)->nx;
			tmp->nx = (*stackb);
			(*stackb)->pv = tmp;
			*stackb = tmp;
		}
	}
	if (*stacka)
	{
		(*stacka)->pv = NULL;
	}
}

void	fpa(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmp;

	tmp = *stackb;
	if (*stackb)
	{
		if (!(*stacka))
		{
			*stacka = *stackb;
			*stackb = (*stackb)->nx;
			(*stacka)->nx = NULL;
			(*stacka)->pv = NULL;
		}
		else
		{
			*stackb = (*stackb)->nx;
			tmp->nx = (*stacka);
			(*stacka)->pv = tmp;
			*stacka = tmp;
		}
	}
	if (*stackb)
	{
		(*stackb)->pv = NULL;
	}

}
