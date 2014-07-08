/**
 * @addtogroup LFMM
 * @ingroup LFMM
 * @{
 *
 * @brief function for LFMM parameter calculation
 */


#ifndef LFMM_H
#define LFMM_H

#include "register_lfmm.h"

/**
 * run LFMM
 *
 * @param param		parameter structure
 */
void LFMM(LFMM_param param);

/**
 * pointer to lfmm_param struct
 */
typedef struct _lfmm_param *LFMM_param;

/**
 * @brief Structure containing all parameters for LFMM
 */
typedef struct _lfmm_param {
        // data size parameters
        int D;                  /**< @brief the number of the covariable (without intercept)*/
        int K;                  /**< @brief the number of latent factors */
        int nd;                 /**< @brief nd-th covariable to use */

        // Gibbs Sampler parameters
        int Niter;              /**< @brief the total number of iterations (with burnin)*/
        int burn;               /**< @brief the number of burnin */
        int num_thrd;           /**< @brief the number of processes used */
        int init;               /**< @brief if true, random init. Otherwise, init with zeros */

        // model parameters
        double *alpha_beta;     /**< @brief the vector of hyperparameters for beta (of size D) */
        double alpha_R;         /**< @brief the inverse of the residual variance */
        double *alpha_U;        /**< @brief the hyperparameter for U */
        double *alpha_V;        /**< @brief the hyperparameter for V */
        double noise_epsilon;   /**< @brief prior for the different variances */
        double b_epsilon;       /**< @brief prior for the correlation coefficient variance */
        int mD;                 /**< @brief the number of the covariable for LFMM run using (including intercept)*/

        // init parameters
        int *I;                 /**< @brief missing data matrix */
        int missing_data;       /**< @brief boolean: true if missing data */
        long long seed;         /**< @brief seed values */
        int all;                /**< @brief Boolean, true if all covariables at the same time */

        // matrix parameters
        double *U;              /**< @brief the U matrix (of size Kxn)*/
        double *V;              /**< @brief the V matrix (of size KxL)*/
        float *dat;             /**< @brief the data matrix (of size nxL) */
        double *beta;           /**< @brief the beta matrix (of size mDxL)*/
        double *C;              /**< @brief The covariable matrix (of size nxD) */
        double *mC;             /**< @brief The covariable matrix for LFMM run (of size mDxn \warning) */
        double *zscore;         /**< @brief the output zscore matrix */

        // io parameters
        char output_file[512];  /**< @brief output file */
        char input_file[512];   /**< @brief input file */
        char cov_file[512];     /**< @brief covariable file */
        int n;                  /**< @brief the number of individuals */
        int L;                  /**< @brief the number of loci */

        // output criterion parameters
        double dev;             /**< @brief deviance criterion */
        double DIC;             /**< @brief DIC criterion */
} lfmm_param;

#endif // LFMM_H


/** @} */
