module;

#include "logging.hpp"

export module lsplant:jit;

import :art_method;
import :common;
import :thread;
import hook_helper;

namespace lsplant::art::jit {
enum class CompilationKind {
    kOsr [[maybe_unused]],
    kBaseline [[maybe_unused]],
    kOptimized,
};

export class Jit {
    inline static Hooker<
        "_ZN3art3jit3Jit27EnqueueOptimizedCompilationEPNS_9ArtMethodEPNS_6ThreadE",
        void(Jit *, ArtMethod *, Thread *)>
        EnqueueOptimizedCompilation_ = +[](Jit *thiz, ArtMethod *method, Thread *self) -> void {
            if (auto target = IsBackup(method); target) [[unlikely]] {
                LOGD("Propagate enqueue compilation: %p -> %p", method, target);
                method = target;
            }
            return EnqueueOptimizedCompilation_(thiz, method, self);
        };

    inline static Hooker<
        "_ZN3art3jit3Jit14AddCompileTaskEPNS_6ThreadEPNS_9ArtMethodENS_15CompilationKindEb",
        void(Jit *, Thread *, ArtMethod *, CompilationKind, bool)>
        AddCompileTask_ = +[](Jit *thiz, Thread *self, ArtMethod *method,
                              CompilationKind compilation_kind, bool precompile) -> void {
            if (compilation_kind == CompilationKind::kOptimized && !precompile) {
                if (auto b = IsHooked(method); b) [[unlikely]] {
                    LOGD("Propagate compile task: %p -> %p", method, b);
                    method = b;
                }
            }
            return AddCompileTask_(thiz, self, method, compilation_kind, precompile);
        };

public:
    static bool Init(const HookHandler &handler) {
        auto sdk_int = GetAndroidApiLevel();

        if (sdk_int <= __ANDROID_API_U__) [[likely]] {
            handler(EnqueueOptimizedCompilation_);
            handler(AddCompileTask_);
        }
        return true;
    }
};
}  // namespace lsplant::art::jit
