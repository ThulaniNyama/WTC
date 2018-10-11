#include <pushswap.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>

static void	ppr4(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->mar;
	b = target->mbf;
	if (b > 0 & a > 0)
	{
		updateretstack(ret, RRA, sa, sb);
		updateretstack(ret, RB, sa, sb);
	}
	else if (b > 0)
		updateretstack(ret, RB, sa, sb);
	else if (a > 0)
		updateretstack(ret, RRA, sa, sb);
	target->mar -= 1;
	target->mbf -= 1;
}

static void	ppr3(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->maf;
	b = target->mbr;
	if (b > 0 & a > 0)
	{
		updateretstack(ret, RA, sa, sb);
		updateretstack(ret, RRB, sa, sb);
	}
	else if (b > 0)
		updateretstack(ret, RRB, sa, sb);
	else if (a > 0)
		updateretstack(ret, RA, sa, sb);
	target->maf -= 1;
	target->mbr -= 1;
}

static void	ppr2(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->mar;
	b = target->mbr;
	if (b > 0 & a > 0)
		updateretstack(ret, RRR, sa, sb);
	else if (b > 0)
		updateretstack(ret, RRB, sa, sb);
	else if (a > 0)
	updateretstack(ret, RRA, sa, sb);
	target->mar -= 1;
	target->mbr -= 1;
}

static void	ppr1(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->maf;
	b = target->mbf;
	if (b > 0 & a > 0)
		updateretstack(ret, RR, sa, sb);
	else if (b > 0)
		updateretstack(ret, RB, sa, sb);
	else if (a > 0)
		updateretstack(ret, RA, sa, sb);
	target->maf -= 1;
	target->mbf -= 1;
}

void	prepoprot(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int moves;

	moves = target->moves;
	while (moves)
	{
		if (target->dir == 1)
			ppr1(target, sa, sb, ret);
		else if (target->dir == 2)
			ppr2(target, sa, sb, ret);
		else if (target->dir == 3)
			ppr3(target, sa, sb, ret);
		else if (target->dir == 4)
			ppr4(target, sa, sb, ret);
		if (ordered(*sa))
			return ;
		moves--;
	}
}
