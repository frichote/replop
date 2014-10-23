
#define <R.h>

R_CMethodDef cMethods[] = {
	{"composite_linkage_disequilibrium",
		(DL_FUNC) &composite_linkage_disequilibrium, 5,
		{RAWSXP, INTSXP, INTSXP, INTSXP, REALSXP}
	},
	{NULL, NULL, 0}
};
