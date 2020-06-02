#include <string>

#include "http_filter.h"

#include "envoy/server/filter_config.h"

namespace Envoy {
namespace Http {

HarnessFilterConfig::HarnessFilterConfig(
    const sample::Decoder& proto_config)
    : name_(proto_config.name()) {}

HarnessFilter::HarnessFilter(HarnessFilterConfigSharedPtr config)
    : config_(config) {}

FilterHeadersStatus HttpSampleDecoderFilter::decodeHeaders(RequestHeaderMap& headers, bool) {
  headers.addCopy("x-envoy-mobile-harness", config_.name());

  return FilterHeadersStatus::Continue;
}

} // namespace Http
} // namespace Envoy
