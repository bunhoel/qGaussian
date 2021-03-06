// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// Chaotic
NumericVector Chaotic(int n, double q, double v0, double z0);
RcppExport SEXP qGaussian_Chaotic(SEXP nSEXP, SEXP qSEXP, SEXP v0SEXP, SEXP z0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type q(qSEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    Rcpp::traits::input_parameter< double >::type z0(z0SEXP);
    rcpp_result_gen = Rcpp::wrap(Chaotic(n, q, v0, z0));
    return rcpp_result_gen;
END_RCPP
}
