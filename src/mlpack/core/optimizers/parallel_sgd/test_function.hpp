/*
 * @file test_function.hpp
 * @author Ranjan Mondal
 *
 * Very simple test function for PSGD.
 */
#ifndef __MLPACK_CORE_OPTIMIZERS_PPSGD_TEST_FUNCTION_HPP
#define __MLPACK_CORE_OPTIMIZERS_PPSGD_TEST_FUNCTION_HPP

#include <mlpack/core.hpp>

namespace mlpack {
namespace optimization {
namespace test {

//! Very, very simple test function which is the composite of three other
//! functions.  The gradient is not very steep far away from the optimum, so a
//! larger step size may be required to optimize it in a reasonable number of
//! iterations.
class PSGDTestFunction
{
 public:
  //! Nothing to do for the constructor.
  PSGDTestFunction() { }

  //! Return 3 (the number of functions).
  size_t NumFunctions() const { return 3; }
//  size_t NumFunctions() const { return 1; }


  //! Get the starting point.
  arma::mat GetInitialPoint() const {return arma::mat("6; -45.6; 6.2");} 
//arma::mat GetInitialPoint() const {return arma::mat("6;");}// -45.6; 6.2");} 

  //! Evaluate a function.
  double Evaluate(const arma::mat& coordinates, const size_t i) const;

  //! Evaluate the gradient of a function.
  void Gradient(const arma::mat& coordinates,
                const size_t i,
                arma::mat& gradient) const;
};


/* This class represents the function f(x,y)=(x+2y-7)^2 +(2x+y-5)^2
 * minimum value of this function is 0,  at x=1  y=3;
 */

class BoothsFunction
{
  public:
  BoothsFunction() { }
  size_t NumFunctions() const { return 2; }
  
  arma::mat GetInitialPoint() const  { return arma::mat("6;5"); }
  
  double Evaluate(const arma::mat& coordinates, const size_t i) const;
  void Gradient(const arma::mat& coordinates,const size_t i,arma::mat& gradient) const;
};



} // namespace test
} // namespace optimization
} // namespace mlpack

#endif