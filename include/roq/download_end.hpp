/* Copyright (c) 2017-2024, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include "roq/compat.hpp"

#include <fmt/core.h>

#include <string_view>

#include "roq/event.hpp"
#include "roq/name.hpp"
#include "roq/trace.hpp"

namespace roq {

//! Identifies the end of a download sequence
struct ROQ_PUBLIC DownloadEnd final {
  std::string_view account;    //!< Account name
  uint64_t max_order_id = {};  //!< Highest previous order identifier (as seen by gateway)
};

template <>
inline constexpr std::string_view get_name<DownloadEnd>() {
  using namespace std::literals;
  return "download_end"sv;
}

}  // namespace roq

template <>
struct fmt::formatter<roq::DownloadEnd> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::DownloadEnd const &value, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(account="{}", )"
        R"(max_order_id={})"
        R"(}})"sv,
        value.account,
        value.max_order_id);
  }
};

template <>
struct fmt::formatter<roq::Event<roq::DownloadEnd>> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::Event<roq::DownloadEnd> const &event, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(download_end={}, )"
        R"(message_info={})"
        R"(}})"sv,
        event.value,
        event.message_info);
  }
};

template <>
struct fmt::formatter<roq::Trace<roq::DownloadEnd>> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::Trace<roq::DownloadEnd> const &event, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(download_end={}, )"
        R"(trace_info={})"
        R"(}})"sv,
        event.value,
        event.trace_info);
  }
};
