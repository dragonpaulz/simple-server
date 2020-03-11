load("@rules_cc//cc:defs.bzl", "cc_binary")
package(default_visibility = ["//visibility:public"])

cc_library(
    name="serverlib",
    srcs=["handler.cpp",
        "server.cpp",
        "serveroptions.cpp",
    ],
    hdrs=[
        "handler.hpp",
        "server.hpp",
        "serveroptions.hpp",
    ],
)

cc_binary(
    name="server",
    srcs=["main.cpp"],
    deps=[
        ":serverlib",
    ],
)