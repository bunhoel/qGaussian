       library(qGaussian)
context("Comparison test")

test_that("Comparison test of random number generation", {
   skip_on_cran()
   x = rqgauss(10000,0,0,1,meth="Box-Muller")
   y = rqgauss(10000,0,0,1,meth="Quantile")
     expect_error( plot(x,y)), NA)
  })
