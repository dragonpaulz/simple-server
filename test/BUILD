cc_test(
    name = "tests",
    srcs = ["serveroptions_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@googletest//:main",
        "//src:serverlib",
    ],
)

cc_test(
    name = "handler-tests",
    srcs = ["handler_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@googletest//:main",
        "//src:serverlib",
    ],
)