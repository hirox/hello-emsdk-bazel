
#include <emscripten.h>
#include <emscripten/bind.h>

#include <iostream>
#include <vector>

// Async JS function
EM_ASYNC_JS(emscripten::EM_VAL, RunAsyncFunction, (), {
  // clang-format off
  await new Promise(resolve => setTimeout(resolve, 3000));
  return Emval.toHandle("3000ms Timeout");
  // clang-format on
});

// C++ - JS Binding
class TargetBinding {
 public:
  emscripten::val Foo(bool arg) {
    std::vector v = {1, 2, 3};
    return arg ? emscripten::val::undefined() : emscripten::val::array(v);
  }

  emscripten::val Bar(const std::vector<std::string> arg) {
    std::vector<std::string> v;
    for (auto& e : arg) {
      v.push_back(e + e);
    }
    return emscripten::val::array(v);
  }

  emscripten::val Baz() {
    return emscripten::val::take_ownership(RunAsyncFunction());
  }
};

EMSCRIPTEN_BINDINGS(target_binding_class) {
  emscripten::register_vector<std::string>("StringList");
  emscripten::class_<TargetBinding>("TargetBinding")
      .constructor()
      .function("Foo", &TargetBinding::Foo)
      .function("Bar", &TargetBinding::Bar)
      .function("Baz", &TargetBinding::Baz);
}

int main(int argc, char* argv[]) {
  std::cout << "Hello World" << std::endl;
  return 0;
}
