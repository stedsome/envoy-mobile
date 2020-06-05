licenses(["notice"])  # Apache 2

load("@io_bazel_rules_kotlin//kotlin/internal:toolchains.bzl", "define_kt_toolchain")
exports_files(["Info.plist"])
alias(
    name = "ios_framework",
    actual = "@envoy_mobile//library/swift/src:ios_framework",
)

genrule(
    name = "ios_dist",
    srcs = ["@envoy_mobile//:ios_framework"],
    outs = ["ios_out"],
    cmd = """
unzip -o $< -d dist/
touch $@
""",
    stamp = True,
)

alias(
    name = "android_pom",
    actual = "@envoy_mobile//library/kotlin/src/io/envoyproxy/envoymobile:android_aar_pom",
)

alias(
    name = "android_aar",
    actual = "@envoy_mobile//library/kotlin/src/io/envoyproxy/envoymobile:android_aar",
)

alias(
    name = "android_javadocs",
    actual = "@envoy_mobile//library:javadocs",
)

alias(
    name = "android_sources",
    actual = "@envoy_mobile//library/kotlin/src/io/envoyproxy/envoymobile:sources_jar_deploy-src.jar",
)

genrule(
    name = "android_zip",
    srcs = [
        "android_aar",
        "android_pom",
        "android_javadocs",
        "android_sources",
    ],
    visibility = ["//visibility:public"],
    tools = ["@bazel_tools//tools/zip:zipper"],
    outs = ["envoy_mobile.zip"],
    cmd = "$(location @bazel_tools//tools/zip:zipper) fc $@ $(SRCS)",
    stamp = True
)

genrule(
    name = "android_dist",
    srcs = [
        "android_aar",
    ],
    outs = ["stub_android_dist_output"],
    cmd = """
cp $(location :android_aar) dist/envoy.aar
chmod 755 dist/envoy.aar
touch $@
""",
    stamp = True,
)

genrule(
    name = "android_deploy",
    srcs = [
        "android_zip",
    ],
    outs = ["stub_android_deploy_output"],
    cmd = """
tmp_dir=$$(mktemp -d)
unzip $(SRCS) -d $$tmp_dir
chmod 755 $$tmp_dir/*
mv $$tmp_dir/* ./dist
touch $@
""",
    stamp = True,
)

define_kt_toolchain(
    name = "kotlin_toolchain",
    jvm_target = "1.8",
)

filegroup(
    name = "kotlin_lint_config",
    srcs = [".kotlinlint.yml"],
    visibility = ["//visibility:public"],
)
