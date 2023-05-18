load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "emsdk",
    strip_prefix = "emsdk-3.1.38/bazel",
    url = "https://github.com/emscripten-core/emsdk/archive/refs/tags/3.1.38.tar.gz",
    sha256 = "45ffb273503e48aae28c04549026b9cbdd750a5d36e3da3e22bc9977d2bfd61f",
)

load("@emsdk//:deps.bzl", emsdk_deps = "deps")
emsdk_deps()

load("@emsdk//:emscripten_deps.bzl", emsdk_emscripten_deps = "emscripten_deps")
emsdk_emscripten_deps()

load("@emsdk//:toolchains.bzl", "register_emscripten_toolchains")
register_emscripten_toolchains()

