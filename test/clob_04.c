#include <stdio.h>
#include "clob.h"


int
main(void)
{
	clob_t c;
	clob_oid_t i;

	c = make_clob();

	i = clob_add(c, (clob_ord_t){TYPE_LMT, SIDE_BID, 0.5dd, -4.0dd, .lmt = 1.23227dd});
	printf("%zu\n", i.qid);
	i = clob_add(c, (clob_ord_t){TYPE_LMT, SIDE_ASK, 0.0dd, 0.0dd, .lmt = 1.23230dd});
	printf("%zu\n", i.qid);

	clob_prnt(c);

	free_clob(c);
	return 0;
}
