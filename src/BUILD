load("@rules_cc//cc:defs.bzl", "cc_binary")
package(default_visibility = ["//visibility:public"])

cc_library(
    name="serverlib",
    srcs=[
        "handler/handler.cpp",
        "setup/server.cpp",
        "setup/setup_helper/serveroptions.cpp",
        "setup/setup_helper/connection.cpp",
        "handler/Byte.cpp",
        "handler/TLVComponent/Length.cpp",
        "handler/TLVComponent/Type.cpp",
    ],
    hdrs=[
        "handler/handler.hpp",
        "setup/server.hpp",
        "setup/setup_helper/serveroptions.hpp",
        "setup/setup_helper/connection.hpp",
        "handler/Byte.hpp",
        "handler/TLVComponent/Length.hpp",
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
