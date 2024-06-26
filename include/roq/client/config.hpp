/* Copyright (c) 2017-2024, Hans Erik Thrane */

#pragma once

#include "roq/compat.hpp"

#include <string_view>

#include "roq/order_cancel_policy.hpp"
#include "roq/order_management.hpp"

namespace roq {
namespace client {

//! Settings
struct ROQ_PUBLIC Settings {
  OrderCancelPolicy order_cancel_policy = {};  //!< Cancel orders on disconnect?
  OrderManagement order_management = {};       //!< Order management style
};

//! Account regex
struct ROQ_PUBLIC Account {
  std::string_view regex;  //!< Regular expression
};

//! Symbol regex
struct ROQ_PUBLIC Symbol {
  std::string_view regex;     //!< Regular expression
  std::string_view exchange;  //!< Exchange name (optional)
};

//! Dispatch interface used to manage subscriptions.
struct ROQ_PUBLIC Config {
  struct ROQ_PUBLIC Handler {
    virtual void operator()(Settings const &) {}
    virtual void operator()(Account const &) = 0;
    virtual void operator()(Symbol const &) = 0;
  };

  virtual ~Config() {}

  //! Framework will request subscriptions by calling this method
  virtual void dispatch(Handler &) const = 0;
};

}  // namespace client
}  // namespace roq

template <>
struct fmt::formatter<roq::client::Settings> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::client::Settings const &value, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(context.out(), "{{order_cancel_policy={}, order_management={}}}"sv, value.order_cancel_policy, value.order_management);
  }
};
