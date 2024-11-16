/* Copyright (c) 2017-2024, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <magic_enum/magic_enum.hpp>

#include <fmt/core.h>

namespace roq {

//! Enumeration of update actions
enum class UpdateAction : uint8_t {
  UNDEFINED = 0,
  NEW,     //!< New
  CHANGE,  //!< Change
  DELETE,  //!< Delete
  TRADE,   //!< Trade  !!! FOR INTERNAL USE !!!
};

}  // namespace roq

template <>
struct fmt::formatter<roq::UpdateAction> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::UpdateAction const &value, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(context.out(), "{}"sv, magic_enum::enum_name(value));
  }
};
