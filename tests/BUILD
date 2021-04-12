load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "test",
    srcs = ["test_main.cpp"],
    deps = [
        "//src/lib:car-lib",
        "@googletest//:gtest_main",
    ],
)