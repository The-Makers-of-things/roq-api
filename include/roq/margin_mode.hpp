/* Copyright (c) 2017-2025, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <magic_enum/magic_enum.hpp>

#include <fmt/core.h>

namespace roq {

//! Enumeration of margin modes
enum class MarginMode : uint8_t {
  UNDEFINED = 0,
  ISOLATED,
  CROSS,
  PORTFOLIO,
};

}  // namespace roq

template <>
struct fmt::formatter<roq::MarginMode> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::MarginMode const &value, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(context.out(), "{}"sv, magic_enum::enum_name(value));
  }
};
