/**
 *  @file
 *  @copyright defined in snax/LICENSE
 */
#pragma once
#include "action.hpp"
#include "print.hpp"
#include "multi_index.hpp"
#include "dispatcher.hpp"
#include "contract.hpp"

#warning "<snaxlib/snax.hpp> is deprecated use <snax/snax.hpp>"

#ifndef SNAX_NATIVE
static_assert( sizeof(long) == sizeof(int), "unexpected size difference" );
#endif

/**
 * Helper macros to reduce the verbosity for common contracts
 */
#define CONTRACT class [[snax::contract]]
#define ACTION   [[snax::action]] void
#define TABLE struct [[snax::table]]

/**
 * @defgroup core Core API
 * @brief C++ Core API for chain-agnostic smart-contract functionality
 */

 /**
  * @defgroup contracts Contracts API
  * @brief C++ Chain API for chain-dependent smart-contract functionality
  */

/**
 * @defgroup types Types
 * @brief TODO
 */
