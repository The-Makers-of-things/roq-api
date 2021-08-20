/* Copyright (c) 2017-2021, Hans Erik Thrane */

#pragma once

#include <limits>

#include "roq/layer.h"
#include "roq/numbers.h"
#include "roq/order_status.h"
#include "roq/request_status.h"
#include "roq/side.h"

namespace roq {
namespace utils {

//! Extract price for \ref roq::Layer given \ref roq::Side.
inline double price_from_side(const Layer &layer, Side side) {
  switch (side) {
    case Side::BUY:
      return layer.bid_price;
    case Side::SELL:
      return layer.ask_price;
    default:
      return NaN;
  }
}

//! Check if order was received
inline bool was_order_received(OrderStatus order_status) {
  switch (order_status) {
    case OrderStatus::SENT:
      return false;
    case OrderStatus::ACCEPTED:
    case OrderStatus::SUSPENDED:
    case OrderStatus::WORKING:
    case OrderStatus::COMPLETED:
    case OrderStatus::EXPIRED:
    case OrderStatus::CANCELED:
    case OrderStatus::REJECTED:
      return true;
    default:
      // XXX throw?
      return false;
  }
}

//! Check if order has reached a final (completed) status
inline bool is_order_complete(OrderStatus order_status) {
  switch (order_status) {
    case OrderStatus::SENT:
    case OrderStatus::ACCEPTED:
    case OrderStatus::SUSPENDED:
    case OrderStatus::WORKING:
      return false;
    case OrderStatus::COMPLETED:
    case OrderStatus::EXPIRED:
    case OrderStatus::CANCELED:
    case OrderStatus::REJECTED:
      return true;
    default:
      // XXX throw?
      return true;
  }
}

//! Map order status to request status
inline RequestStatus to_request_status(OrderStatus order_status) {
  switch (order_status) {
    case OrderStatus::SENT:
      return RequestStatus::FORWARDED;
    case OrderStatus::ACCEPTED:
    case OrderStatus::SUSPENDED:
    case OrderStatus::WORKING:
    case OrderStatus::COMPLETED:
    case OrderStatus::EXPIRED:
    case OrderStatus::CANCELED:
      return RequestStatus::ACCEPTED;
    case OrderStatus::REJECTED:
      return RequestStatus::REJECTED;
    default:
      return {};
  }
}

//! Check if request has reached a final (completed) status
inline bool has_request_completed(RequestStatus request_status) {
  switch (request_status) {
    case RequestStatus::UNDEFINED:
    case RequestStatus::FORWARDED:
      break;
      // note! definitely completed
    case RequestStatus::ACCEPTED:
    case RequestStatus::REJECTED:
      return true;
      // note! we don't know the real status for these
    case RequestStatus::DISCONNECTED:
    case RequestStatus::TIMEOUT:
    case RequestStatus::FAILED:
      break;
    default:
      break;
  }
  return false;
}

//! Check if request has failed
inline bool has_request_failed(RequestStatus request_status) {
  switch (request_status) {
    case RequestStatus::UNDEFINED:
    case RequestStatus::FORWARDED:
    case RequestStatus::ACCEPTED:
      break;
      // note! definitely failed
    case RequestStatus::REJECTED:
      return true;
      // note! we don't know the real status for these
    case RequestStatus::DISCONNECTED:
    case RequestStatus::TIMEOUT:
    case RequestStatus::FAILED:
      return true;
    default:
      break;
  }
  return false;
}

//! Check if request has succeeded
inline bool has_request_succeeded(RequestStatus request_status) {
  switch (request_status) {
    case RequestStatus::UNDEFINED:
    case RequestStatus::FORWARDED:
      break;
      // note! definitely succeeded
    case RequestStatus::ACCEPTED:
      return true;
      // note! definitely did *not* succeed
    case RequestStatus::REJECTED:
      break;
      // note! we don't know the real status for these
    case RequestStatus::DISCONNECTED:
    case RequestStatus::TIMEOUT:
    case RequestStatus::FAILED:
      break;
    default:
      break;
  }
  return false;
}

//! Get the opposite \ref Side.
inline Side invert(Side side) {
  switch (side) {
    case Side::BUY:
      return Side::SELL;
    case Side::SELL:
      return Side::BUY;
    default:
      return side;
  }
}

//! Get notional sign given \ref roq::Side
inline int sign(Side side) {
  switch (side) {
    case Side::BUY:
      return 1;
    case Side::SELL:
      return -1;
    default:
      return 0;
  }
}

}  // namespace utils
}  // namespace roq
