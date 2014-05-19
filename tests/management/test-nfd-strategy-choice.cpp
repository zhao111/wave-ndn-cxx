/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/**
 * Copyright (c) 2013-2014,  Regents of the University of California.
 * All rights reserved.
 *
 * This file is part of ndn-cxx library (NDN C++ library with eXperimental eXtensions).
 * See AUTHORS.md for complete list of ndn-cxx authors and contributors.
 *
 * This file licensed under New BSD License.  See COPYING for detailed information about
 * ndn-cxx library copyright, permissions, and redistribution restrictions.
 */

#include "management/nfd-strategy-choice.hpp"

#include "boost-test.hpp"

namespace ndn {
namespace nfd {
namespace tests {

BOOST_AUTO_TEST_SUITE(ManagementTestNfdStrategyChoice)

BOOST_AUTO_TEST_CASE(Encode)
{
  StrategyChoice strategyChoice1;
  strategyChoice1
    .setName("/hello/world")
    .setStrategy("/some/non/existing/strategy/name")
    ;

  Block wire;
  BOOST_REQUIRE_NO_THROW(wire = strategyChoice1.wireEncode());

  // These octets are obtained by the snippet below.
  // This check is intended to detect unexpected encoding change in the future.
  // for (Buffer::const_iterator it = wire.begin(); it != wire.end(); ++it) {
  //  printf("0x%02x, ", *it);
  // }
  static const uint8_t expected[] = {
    0x80, 0x39, 0x07, 0x0e, 0x08, 0x05, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x08, 0x05, 0x77,
    0x6f, 0x72, 0x6c, 0x64, 0x6b, 0x27, 0x07, 0x25, 0x08, 0x04, 0x73, 0x6f, 0x6d, 0x65,
    0x08, 0x03, 0x6e, 0x6f, 0x6e, 0x08, 0x08, 0x65, 0x78, 0x69, 0x73, 0x74, 0x69, 0x6e,
    0x67, 0x08, 0x08, 0x73, 0x74, 0x72, 0x61, 0x74, 0x65, 0x67, 0x79, 0x08, 0x04, 0x6e,
    0x61, 0x6d, 0x65
  };
  BOOST_REQUIRE_EQUAL_COLLECTIONS(expected, expected + sizeof(expected),
                                  wire.begin(), wire.end());

  BOOST_REQUIRE_NO_THROW(StrategyChoice(wire));
  StrategyChoice strategyChoice2(wire);
  BOOST_CHECK_EQUAL(strategyChoice1.getName(), strategyChoice2.getName());
  BOOST_CHECK_EQUAL(strategyChoice1.getStrategy(), strategyChoice2.getStrategy());
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests
} // namespace nfd
} // namespace ndn
