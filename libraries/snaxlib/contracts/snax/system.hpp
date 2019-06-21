/**
 *  @file
 *  @copyright defined in snax/LICENSE
 */
#pragma once
#include "../../core/snax/time.hpp"
#include "../../core/snax/check.hpp"

namespace snax {
  namespace internal_use_do_not_use {
    extern "C" {
      __attribute__((snax_wasm_import, noreturn))
      void snax_exit( int32_t code );
    }
  }

  /**
   *  @addtogroup system System
   *  @ingroup contracts
   *  @brief Defines time related functions and snax_exit
   */

   /**
    *  This method will abort execution of wasm without failing the contract. This is used to bypass all cleanup / destructors that would normally be called.
    *
    *  @ingroup system
    *  @param code - the exit code
    *  Example:
    *
    *  @code
    *  snax_exit(0);
    *  snax_exit(1);
    *  snax_exit(2);
    *  snax_exit(3);
    *  @endcode
    */
   inline void snax_exit( int32_t code ) {
     internal_use_do_not_use::snax_exit(code);
   }

   /**
   *  Returns the time in microseconds from 1970 of the current block as a time_point
   *
   *  @ingroup system
   *  @return time in microseconds from 1970 of the current block as a time_point
   */
   time_point current_time_point();

   /**
   *  Returns the time in microseconds from 1970 of the current block as a block_timestamp
   *
   *  @ingroup system
   *  @return time in microseconds from 1970 of the current block as a block_timestamp
   */
   block_timestamp current_block_time();
}
