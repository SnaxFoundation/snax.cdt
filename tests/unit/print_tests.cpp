#include <snax/snax.hpp>
#include <snax/tester.hpp>

using namespace snax::native;

SNAX_TEST_BEGIN(print_test)
   silence_output(false);
   CHECK_PRINT("27", [](){ snax::print((uint8_t)27); });
   CHECK_PRINT("34", [](){ snax::print((int)34); });
   CHECK_PRINT([](std::string s){return s[0] == 'a';},  [](){ snax::print((char)'a'); });
   CHECK_PRINT([](std::string s){return s[0] == 'b';},  [](){ snax::print((int8_t)'b'); });
   CHECK_PRINT("202", [](){ snax::print((unsigned int)202); });
   CHECK_PRINT("-202", [](){ snax::print((int)-202); });
   CHECK_PRINT("707", [](){ snax::print((unsigned long)707); });
   CHECK_PRINT("-707", [](){ snax::print((long)-707); });
   CHECK_PRINT("909", [](){ snax::print((unsigned long long)909); });
   CHECK_PRINT("-909", [](){ snax::print((long long)-909); });
   CHECK_PRINT("404", [](){ snax::print((uint32_t)404); });
   CHECK_PRINT("-404", [](){ snax::print((int32_t)-404); });
   CHECK_PRINT("404000000", [](){ snax::print((uint64_t)404000000); });
   CHECK_PRINT("-404000000", [](){ snax::print((int64_t)-404000000); });
   CHECK_PRINT("0x0066000000000000", [](){ snax::print((uint128_t)102); });
   CHECK_PRINT("0xffffff9affffffffffffffffffffffff", [](){ snax::print((int128_t)-102); });
   silence_output(false);
SNAX_TEST_END

int main(int argc, char** argv) {
   SNAX_TEST(print_test);
   return has_failed();
}
