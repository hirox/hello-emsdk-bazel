load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")
load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")

cc_binary(
    name = "hello",
    srcs = ["main.cc"],
    deps = [
    ],
    linkopts = [
        "--bind",           # For EMSCRIPTEN_BINDINGS
        "-s ASYNCIFY=1",    # For EM_ASYNC_JS
        "-s EXPORTED_RUNTIME_METHODS='[\"callMain\"]'"]
)

wasm_cc_binary(
    name = "hello-wasm",
    cc_target = ":hello",
)
