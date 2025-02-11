# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "C"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_C
  "/opt/wasm-micro-runtime/core/shared/utils/uncommon/bh_getopt.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/loader.dir/opt/wasm-micro-runtime/core/shared/utils/uncommon/bh_getopt.c.o"
  "/opt/wasm-micro-runtime/core/shared/utils/uncommon/bh_read_file.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/loader.dir/opt/wasm-micro-runtime/core/shared/utils/uncommon/bh_read_file.c.o"
  "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/src/loader.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/loader.dir/src/loader.c.o"
  "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/src/main.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/loader.dir/src/main.c.o"
  "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/src/ppl_if.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/loader.dir/src/ppl_if.c.o"
  "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/loader.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.o"
  )
set(CMAKE_C_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_C
  "BH_DEBUG=1"
  "BH_FREE=wasm_runtime_free"
  "BH_MALLOC=wasm_runtime_malloc"
  "BH_PLATFORM_LINUX"
  "BUILD_TARGET_X86_32"
  "WASM_DISABLE_HW_BOUND_CHECK=0"
  "WASM_DISABLE_STACK_HW_BOUND_CHECK=0"
  "WASM_ENABLE_AOT=1"
  "WASM_ENABLE_BULK_MEMORY=1"
  "WASM_ENABLE_DEBUG_INTERP=1"
  "WASM_ENABLE_FAST_INTERP=0"
  "WASM_ENABLE_INTERP=1"
  "WASM_ENABLE_LIBC_BUILTIN=1"
  "WASM_ENABLE_LIBC_WASI=1"
  "WASM_ENABLE_LIB_PTHREAD=1"
  "WASM_ENABLE_MEMORY_PROFILING=1"
  "WASM_ENABLE_MINI_LOADER=0"
  "WASM_ENABLE_MULTI_MODULE=0"
  "WASM_ENABLE_SHARED_MEMORY=1"
  "WASM_ENABLE_THREAD_MGR=1"
  "WASM_GLOBAL_HEAP_SIZE=10485760"
  )

# The include file search paths:
set(CMAKE_C_TARGET_INCLUDE_PATH
  "/opt/wasm-micro-runtime/core/iwasm/interpreter"
  "/opt/wasm-micro-runtime/core/iwasm/aot"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/libc-builtin"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/libc-wasi/sandboxed-system-primitives/include"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/libc-wasi/sandboxed-system-primitives/src"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/lib-pthread"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/thread-mgr"
  "/opt/wasm-micro-runtime/core/iwasm/include"
  "/opt/wasm-micro-runtime/core/shared/platform/linux"
  "/opt/wasm-micro-runtime/core/shared/platform/linux/../include"
  "/opt/wasm-micro-runtime/core/shared/mem-alloc"
  "/opt/wasm-micro-runtime/core/iwasm/common"
  "/opt/wasm-micro-runtime/core/shared/utils"
  "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/src"
  "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/../../sdk/vision_app_sdk/include"
  "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/../../sdk/third_party/include/parson"
  "/opt/wasm-micro-runtime/core/shared/utils/uncommon"
  "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/../include"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/DependInfo.cmake"
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
