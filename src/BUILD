load("@rules_cc//cc:defs.bzl", "cc_binary")
package(default_visibility = ["//visibility:public"])

cc_library(
    name="serverlib",
    srcs=[
        "handler.cpp",
        "server.cpp",
        "serveroptions.cpp",
        "connection.cpp",
        "handler/Byte.cpp",
        "handler/MsgLen.cpp",
        "handler/TLVComponent/Type.cpp",
    ],
    hdrs=[
        "handler.hpp",
        "server.hpp",
        "serveroptions.hpp",
        "connection.hpp",
        "handler/Byte.hpp",
        "handler/MsgLen.hpp",
        "handler/TLVComponent/Type.hpp",
        "handler/TLVComponent/Value.hpp",
    ],
    deps=[
        "@boost//:asio",
        "@boost//:bind",
        "@boost//:enable_shared_from_this",
        "@boost//:shared_ptr",
    ],
)

cc_binary(
    name="server",
    srcs=["main.cpp"],
    deps=[
        ":serverlib",
        "@boost//:asio",
        "@boost//:program_options",
    ],
)
