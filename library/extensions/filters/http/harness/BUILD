
package(default_visibility = ["//visibility:public"])

load(
    "@envoy//bazel:envoy_build_system.bzl",
    "envoy_cc_binary",
    "envoy_cc_library",
    "envoy_cc_test",
)

load("@envoy_api//bazel:api_build_system.bzl", "api_proto_package")

api_proto_package()

envoy_cc_library(
    name = "harness_filter_lib",
    srcs = ["harness_filter.cc"],
    hdrs = ["harness_filter.h"],
    repository = "@envoy",
    deps = [
        ":pkg_cc_proto",
    ],
)

envoy_cc_library(
    name = "config",
    srcs = ["config.cc"],
    repository = "@envoy",
    deps = [
        ":harness_filter_lib",
        "@envoy//include/envoy/server:filter_config_interface",
    ],
)
