/* Copyright (c) 2017-2021, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/chrono.h>

#include <chrono>
#include <string_view>

#include "roq/chrono.h"
#include "roq/compat.h"
#include "roq/event.h"
#include "roq/format.h"
#include "roq/literals.h"
#include "roq/message_info.h"
#include "roq/numbers.h"
#include "roq/span.h"
#include "roq/string_buffer.h"

namespace roq {

//! Connected to gateway
struct ROQ_PUBLIC Connected final {};

}  // namespace roq

template <>
struct fmt::formatter<roq::Connected> : public roq::formatter {
  template <typename Context>
  auto format(const roq::Connected &value, Context &context) {
    using namespace roq::literals;
    return roq::format_to(context.out(), R"({{}})"_sv);
  }
};
template <>
struct fmt::formatter<roq::Event<roq::Connected> > : public roq::formatter {
  template <typename Context>
  auto format(const roq::Event<roq::Connected> &event, Context &context) {
    using namespace roq::literals;
    return roq::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(connected={})"
        R"(}})"_sv,
        event.message_info,
        event.value);
  }
};
