/**
 *  @file
 *  @copyright defined in evt/LICENSE.txt
 */
#pragma once
#include <evt/chain/chain_config.hpp>
#include <evt/chain/types.hpp>

#include <fc/crypto/sha256.hpp>

#include <string>
#include <vector>

namespace evt { namespace chain { namespace contracts {

struct genesis_state {
   chain_config   initial_configuration = {
      .max_block_net_usage                  = config::default_max_block_net_usage,
      .target_block_net_usage_pct           = config::default_target_block_net_usage_pct,
      .max_transaction_net_usage            = config::default_max_transaction_net_usage,
      .base_per_transaction_net_usage       = config::default_base_per_transaction_net_usage,
      .net_usage_leeway                     = config::default_net_usage_leeway,
      .context_free_discount_net_usage_num  = config::default_context_free_discount_net_usage_num,
      .context_free_discount_net_usage_den  = config::default_context_free_discount_net_usage_den,

      .max_block_cpu_usage                  = config::default_max_block_cpu_usage,
      .target_block_cpu_usage_pct           = config::default_target_block_cpu_usage_pct,
      .max_transaction_cpu_usage            = config::default_max_transaction_cpu_usage,
      .base_per_transaction_cpu_usage       = config::default_base_per_transaction_cpu_usage,
      .base_per_action_cpu_usage            = config::default_base_per_action_cpu_usage,
      .base_setcode_cpu_usage               = config::default_base_setcode_cpu_usage,
      .per_signature_cpu_usage              = config::default_per_signature_cpu_usage,
      .cpu_usage_leeway                     = config::default_cpu_usage_leeway,
      .context_free_discount_cpu_usage_num  = config::default_context_free_discount_cpu_usage_num,
      .context_free_discount_cpu_usage_den  = config::default_context_free_discount_cpu_usage_den,

      .max_transaction_lifetime             = config::default_max_trx_lifetime,
      .deferred_trx_expiration_window       = config::default_deferred_trx_expiration_window,
      .max_transaction_delay                = config::default_max_trx_delay,
      .max_inline_action_size               = config::default_max_inline_action_size,
      .max_inline_action_depth              = config::default_max_inline_action_depth,
      .max_authority_depth                  = config::default_max_auth_depth,
      .max_generated_transaction_count      = config::default_max_gen_trx_count,
   };

   time_point                               initial_timestamp = fc::time_point::from_iso_string( "2018-03-01T12:00:00" );;
   public_key_type                          initial_key = fc::variant("EVT6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV").as<public_key_type>();

   /**
    * Temporary, will be moved elsewhere.
    */
   chain_id_type initial_chain_id;

   /**
    * Get the chain_id corresponding to this genesis state.
    *
    * This is the SHA256 serialization of the genesis_state.
    */
   chain_id_type compute_chain_id() const;
};

}}} // namespace evt::contracts


FC_REFLECT(evt::chain::contracts::genesis_state,
           (initial_timestamp)(initial_key)(initial_configuration)(initial_chain_id))
