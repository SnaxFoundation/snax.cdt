#include <boost/test/unit_test.hpp>
#include <snax/testing/tester.hpp>
#include <snax/chain/abi_serializer.hpp>

#include <Runtime/Runtime.h>

#include <fc/variant_object.hpp>

#include <contracts.hpp>

using namespace snax;
using namespace snax::testing;
using namespace snax::chain;
using namespace snax::testing;
using namespace fc;

using mvo = fc::mutable_variant_object;

BOOST_AUTO_TEST_SUITE(memory_tests)

BOOST_FIXTURE_TEST_CASE( malloc_tests, tester ) try {
   create_accounts( { N(test) } );
   produce_block();
/*
   set_code( N(test), contracts::malloc_tests_wasm() );
   set_abi( N(test), contracts::malloc_tests_abi().data() );
   produce_blocks();

   push_action(N(test), N(malloctest), N(test), {});
   push_action(N(test), N(mallocalot), N(test), {});
   push_action(N(test), N(mallocpass), N(test), {});
   push_action(N(test), N(mallocpass2), N(test), {});
   BOOST_CHECK_EXCEPTION( push_action(N(test), N(mallocfail), N(test), {}),
                          snax_assert_message_exception,
                          snax_assert_message_is("failed to allocate pages") );
                          */
} FC_LOG_AND_RETHROW() }
