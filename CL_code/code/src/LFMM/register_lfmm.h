/**
 * @addtogroup register_lfmm
 * @ingroup LFMM
 * @{
 *
 * @brief functions to analyse command line
 */

#ifndef REGISTER_LFMM_H
#define REGISTER_LFMM_H

/**
 * initialize the parameter with the default values for LFMM 
 *
 * @param param	parameter structure
 */
void init_param_lfmm(LFMM_param param);

/**
 * analyse command line set of parameters and set the parameters
 * 
 * @param argc	the number of arguments
 * @param argv	the set of arguments
 * @param param	parameter structure
 */
void analyse_param_lfmm(int argc, char *argv[], LFMM_param param);

/** 
 * free lfmm_param struct allocated memory
 *
 * @param param	parameter structure
 */
void free_param_lfmm(LFMM_param param);

/**
 * @brief Structure containing all parameters for LFMM
 */
typedef struct _lfmm_param {
	// data size parameters
	int D;			/**< @brief the number of the covariable (without intercept)*/
	int K;			/**< @brief the number of latent factors */
	int nd;			/**< @brief nd-th covariable to use */	

	// Gibbs Sampler parameters
	int Niter;		/**< @brief the total number of iterations (with burnin)*/
	int burn;		/**< @brief the number of burnin */ 
	int num_thrd;		/**< @brief the number of processes used */
	int init;		/**< @brief if true, random init. Otherwise, init with zeros */
	
	// model parameters
	double *alpha_beta;	/**< @brief the vector of hyperparameters for beta (of size D) */ 
	double alpha_R;		/**< @brief the inverse of the residual variance */
	double *alpha_U;	/**< @brief the hyperparameter for U */
	double *alpha_V;	/**< @brief the hyperparameter for V */
	double noise_epsilon;	/**< @brief prior for the different variances */
	double b_epsilon;	/**< @brief prior for the correlation coefficient variance */
	int mD;			/**< @brief the number of the covariable for LFMM run using (including intercept)*/

	// init parameters
	int *I;			/**< @brief missing data matrix */
	int missing_data;	/**< @brief boolean: true if missing data */
	long long seed;		/**< @brief seed values */
	int all;		/**< @brief Boolean, true if all covariables at the same time */

	// matrix parameters
	double *U;		/**< @brief the U matrix (of size Kxn)*/
	double *V;		/**< @brief the V matrix (of size KxL)*/
	float *dat;		/**< @brief the data matrix (of size nxL) */
	double *beta;		/**< @brief the beta matrix (of size mDxL)*/
	double *C;		/**< @brief The covariable matrix (of size nxD) */
	double *mC;		/**< @brief The covariable matrix for LFMM run (of size mDxn \warning) */
	double *zscore;		/**< @brief the output zscore matrix */

	// io parameters
	char output_file[512];	/**< @brief output file */ 
	char input_file[512];	/**< @brief input file */
	char cov_file[512];	/**< @brief covariable file */
	int n;			/**< @brief the number of individuals */
	int L;			/**< @brief the number of loci */
	
	// output criterion parameters
	double dev;		/**< @brief deviance criterion */
	double DIC;		/**< @brief DIC criterion */
} lfmm_param;




#endif // REGISTER_LFMM_H

/** @} */
