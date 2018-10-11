#include <pushswap.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>

static int	bstructhelpgt(t_stack *sa, t_stack *tmpb)
{
	int i;

	i = 0;
	while (sa->v > tmpb->v)
	{
		i++;
		tmpb = tmpb->nx;
	}
	while (sa->v < tmpb->v)
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

static int	bstructhelpsmallest(t_stack *tmpb, t_stack *sb)
{
	int i;

	i = 1;
	while (tmpb->v != getsmallest(sb))
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

static int	bstructhelplargest(t_stack *tmpb, t_stack *sb)
{
	int i;

	i = 0;
	while (tmpb->v != getlargest(sb))
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

static int	bstructhelplt(t_stack *tmpb, t_stack *sa)
{
	int i;

	i = 0;
	while (sa->v < tmpb->v )
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

void	bstructmoves(t_stack *sa, t_stack *sb)
{
	int i;
	t_stack *tmpb;

	if (!(sb))
		return ;
	while (sa)
	{
		i = 0;
		tmpb = sb;
		if (sa->v < (getend(&tmpb)->v) && sa->v > tmpb->v)
			;
		else if (sa->v > getlargest(sb))
			i = bstructhelplargest(tmpb, sb);
		else if (sa->v < getsmallest(sb))
			i = bstructhelpsmallest(tmpb, sb);
		else if (sa->v > (getend(&tmpb)->v) && sa->v > tmpb->v)
			i = bstructhelpgt(sa, tmpb);
		else
			i = bstructhelplt(tmpb, sa);
		sa->mbf = i;
		sa->mbr = (stacklen(sb)) - i;
		sa = sa->nx;
	}
}
