cc_test(
    name = "tests",
    srcs = glob(["**/*.cpp"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:main",
        "//src:serverlib",
    ],
)
