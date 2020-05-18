// Copyright (c) 2020 Zano Project
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#pragma once

#include "chaingen.h"
#include "wallet_tests_basic.h"

struct hard_fork_2_base_test : virtual public test_chain_unit_enchanced
{
  hard_fork_2_base_test(size_t hardfork_height);
  bool configure_core(currency::core& c, size_t ev_index, const std::vector<test_event_entry>& events);

  size_t m_hardfork_height;
};

struct hard_fork_2_tx_payer_in_wallet : public wallet_test, public hard_fork_2_base_test
{
  hard_fork_2_tx_payer_in_wallet();
  bool generate(std::vector<test_event_entry>& events) const;
  bool c1(currency::core& c, size_t ev_index, const std::vector<test_event_entry>& events);
};

struct hard_fork_2_tx_receiver_in_wallet : public wallet_test, public hard_fork_2_base_test
{
  hard_fork_2_tx_receiver_in_wallet();
  bool generate(std::vector<test_event_entry>& events) const;
  bool c1(currency::core& c, size_t ev_index, const std::vector<test_event_entry>& events);

  mutable uint64_t m_alice_start_balance;
};

struct hard_fork_2_tx_extra_alias_entry_in_wallet : public wallet_test, public hard_fork_2_base_test
{
  hard_fork_2_tx_extra_alias_entry_in_wallet();
  bool generate(std::vector<test_event_entry>& events) const;
  bool c1(currency::core& c, size_t ev_index, const std::vector<test_event_entry>& events);
};

struct hard_fork_2_auditable_addresses_basics : public wallet_test, public hard_fork_2_base_test
{
  hard_fork_2_auditable_addresses_basics();
  bool generate(std::vector<test_event_entry>& events) const;
  bool c1(currency::core& c, size_t ev_index, const std::vector<test_event_entry>& events);
};

struct hard_fork_2_no_new_structures_before_hf : public wallet_test, public hard_fork_2_base_test
{
  hard_fork_2_no_new_structures_before_hf();
  bool generate(std::vector<test_event_entry>& events) const;
  bool c1(currency::core& c, size_t ev_index, const std::vector<test_event_entry>& events);
};
