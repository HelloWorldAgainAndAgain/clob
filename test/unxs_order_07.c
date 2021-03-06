#include <stdio.h>
#include "dfp754_d64.h"
#include "clob.h"
#include "unxs.h"
#include "nifty.h"

#define NANPX		NAND64


int
main(void)
{
	clob_t c;

	c = make_clob();

	clob_add(c, (clob_ord_t){CLOB_TYPE_LMT, CLOB_SIDE_ASK, {100.dd, 0.0dd}, .lmt = 200.0dd});
	clob_add(c, (clob_ord_t){CLOB_TYPE_LMT, CLOB_SIDE_BID, {10.dd, 50.0dd}, .lmt = 198.0dd});
	clob_add(c, (clob_ord_t){CLOB_TYPE_LMT, CLOB_SIDE_BID, {10.dd, 50.0dd}, .lmt = 197.0dd});

	clob_prnt(c);

	/* eat into the limits */
	unxs_order(c, (clob_ord_t){CLOB_TYPE_MKT, CLOB_SIDE_SHORT, {80.dd, 0.0dd}}, NANPX);

	clob_prnt(c);

	free_clob(c);
	return 0;
}
