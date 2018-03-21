//                                               -*- C++ -*-
/**
 *  @brief LHS is an implementation of the hit or miss Monte Carlo simulation method
 *
 *  Copyright 2005-2018 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_LHS_HXX
#define OPENTURNS_LHS_HXX

#include "openturns/EventSimulation.hxx"
#include "openturns/Collection.hxx"
#include "openturns/PersistentCollection.hxx"
#include "openturns/Distribution.hxx"
#include "openturns/Matrix.hxx"

BEGIN_NAMESPACE_OPENTURNS



/**
 * @class LHS
 */

class OT_API LHS: public EventSimulation
{

  CLASSNAME
public:

  typedef Collection<Distribution>           Marginals;
  typedef PersistentCollection<Distribution> PersistentMarginals;

  /** Default constructor */
  LHS();

  /** Constructor with parameters */
  LHS(const Event & event);


  /** Virtual constructor */
  virtual LHS * clone() const;

  /** Performs the actual computation. */
  void run();

  /** String converter */
  String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

protected:

  /** Compute the block sample */
  Sample computeBlockSample();

  /** Second antecedent dimension */
  UnsignedInteger dimension_;

  /** Active block index */
  UnsignedInteger blockIndex_;

  /** Cells shuffle */
  Matrix shuffle_;

  /** Marginal distributions */
  PersistentMarginals marginals_;

private:

} ; /* class LHS */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_LHS_HXX */
