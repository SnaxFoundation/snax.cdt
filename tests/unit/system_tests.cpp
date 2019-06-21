/**
 *  @file
 *  @copyright defined in snax.cdt/LICENSE.txt
 */

#include <string>

#include <snax/snax.hpp>
#include <snax/tester.hpp>

using std::move;
using std::string;

using snax::check;

// Definitions in `snax.cdt/libraries/snaxlib/system.hpp`
SNAX_TEST_BEGIN(system_test)
   silence_output(true);

   // ------------------------------------
   // inline void check(bool, const char*)
   CHECK_ASSERT( "asserted", []() { const char* str{"asserted"}; check(false, str);} );

   // --------------------------------------
   // inline void check(bool, const string&)
   CHECK_ASSERT( "asserted", []() { const string str{"asserted"}; check(false, str);} );

   // ---------------------------------------
   // inline void check(bool, const string&&)
   CHECK_ASSERT( "asserted", []() { const string str{"asserted"}; check(false, move(str));} );

   // --------------------------------------------
   // inline void check(bool, const char*, size_t)
   CHECK_ASSERT( "assert", []() { const char* str{"asserted"}; check(false, str, 6);} );

   // ----------------------------------------------
   // inline void check(bool, const string&, size_t)
   CHECK_ASSERT( "assert", []() { const string str{"asserted"}; check(false, str, 6);} );

   // ---------------------------------
   // inline void check(bool, uint64_t)
   CHECK_ASSERT("1", []() { check(false, 1);} );
   CHECK_ASSERT("100", []() { check(false, 100);} );
   CHECK_ASSERT("18446744073709551615", []() { check(false, 18446744073709551615ULL);} );
   CHECK_ASSERT("18446744073709551615", []() { check(false, -1ULL);} );

   silence_output(false);
SNAX_TEST_END

int main(int argc, char* argv[]) {
   SNAX_TEST(system_test);
   return has_failed();
}
