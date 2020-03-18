load("@rules_cc//cc:defs.bzl", "cc_binary")
package(default_visibility = ["//visibility:public"])

cc_library(
    name="serverlib",
    srcs=[
        "handler/TLVmessage.cpp",
        "setup/server.cpp",
        "setup/setup_helper/serveroptions.cpp",
        "setup/setup_helper/connection.cpp",
        "handler/TLVComponent/Length.cpp",
        "handler/TLVComponent/Type.cpp",
        "handler/TLVComponent/helper/Byte.cpp",
    ],
    hdrs=[
        "handler/TLVmessage.hpp",
        "setup/server.hpp",
        "setup/setup_helper/serveroptions.hpp",
        "setup/setup_helper/connection.hpp",
        "handler/TLVComponent/Length.hpp",
        "handler/TLVComponent/Type.hpp",
        "handler/TLVComponent/Value.hpp",
        "handler/TLVComponent/helper/Byte.hpp",
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
