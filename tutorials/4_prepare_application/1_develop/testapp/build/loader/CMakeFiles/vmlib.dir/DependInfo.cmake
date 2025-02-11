# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  "C"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/opt/wasm-micro-runtime/core/iwasm/common/arch/invokeNative_ia32.s" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/common/arch/invokeNative_ia32.s.o"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
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
  "vmlib_EXPORTS"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
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
  )
set(CMAKE_DEPENDS_CHECK_C
  "/opt/wasm-micro-runtime/core/iwasm/aot/aot_intrinsic.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/aot/aot_intrinsic.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/aot/aot_loader.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/aot/aot_loader.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/aot/aot_runtime.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/aot/aot_runtime.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/aot/arch/aot_reloc_x86_32.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/aot/arch/aot_reloc_x86_32.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/common/wasm_application.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/common/wasm_application.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/common/wasm_c_api.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/common/wasm_c_api.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/common/wasm_exec_env.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/common/wasm_exec_env.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/common/wasm_memory.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/common/wasm_memory.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/common/wasm_native.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/common/wasm_native.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/common/wasm_runtime_common.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/common/wasm_runtime_common.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/common/wasm_shared_memory.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/common/wasm_shared_memory.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/interpreter/wasm_interp_classic.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/interpreter/wasm_interp_classic.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/interpreter/wasm_loader.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/interpreter/wasm_loader.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/interpreter/wasm_runtime.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/interpreter/wasm_runtime.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine/debug_engine.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine/debug_engine.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine/gdbserver.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine/gdbserver.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine/handler.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine/handler.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine/packets.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine/packets.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine/utils.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/debug-engine/utils.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/lib-pthread/lib_pthread_wrapper.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/lib-pthread/lib_pthread_wrapper.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/libc-builtin/libc_builtin_wrapper.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/libc-builtin/libc_builtin_wrapper.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/libc-wasi/libc_wasi_wrapper.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/libc-wasi/libc_wasi_wrapper.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/libc-wasi/sandboxed-system-primitives/src/posix.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/libc-wasi/sandboxed-system-primitives/src/posix.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/libc-wasi/sandboxed-system-primitives/src/random.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/libc-wasi/sandboxed-system-primitives/src/random.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/libc-wasi/sandboxed-system-primitives/src/str.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/libc-wasi/sandboxed-system-primitives/src/str.c.o"
  "/opt/wasm-micro-runtime/core/iwasm/libraries/thread-mgr/thread_manager.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/iwasm/libraries/thread-mgr/thread_manager.c.o"
  "/opt/wasm-micro-runtime/core/shared/mem-alloc/ems/ems_alloc.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/mem-alloc/ems/ems_alloc.c.o"
  "/opt/wasm-micro-runtime/core/shared/mem-alloc/ems/ems_hmu.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/mem-alloc/ems/ems_hmu.c.o"
  "/opt/wasm-micro-runtime/core/shared/mem-alloc/ems/ems_kfc.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/mem-alloc/ems/ems_kfc.c.o"
  "/opt/wasm-micro-runtime/core/shared/mem-alloc/mem_alloc.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/mem-alloc/mem_alloc.c.o"
  "/opt/wasm-micro-runtime/core/shared/platform/common/posix/posix_malloc.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/platform/common/posix/posix_malloc.c.o"
  "/opt/wasm-micro-runtime/core/shared/platform/common/posix/posix_memmap.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/platform/common/posix/posix_memmap.c.o"
  "/opt/wasm-micro-runtime/core/shared/platform/common/posix/posix_socket.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/platform/common/posix/posix_socket.c.o"
  "/opt/wasm-micro-runtime/core/shared/platform/common/posix/posix_thread.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/platform/common/posix/posix_thread.c.o"
  "/opt/wasm-micro-runtime/core/shared/platform/common/posix/posix_time.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/platform/common/posix/posix_time.c.o"
  "/opt/wasm-micro-runtime/core/shared/platform/linux/platform_init.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/platform/linux/platform_init.c.o"
  "/opt/wasm-micro-runtime/core/shared/utils/bh_assert.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/utils/bh_assert.c.o"
  "/opt/wasm-micro-runtime/core/shared/utils/bh_common.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/utils/bh_common.c.o"
  "/opt/wasm-micro-runtime/core/shared/utils/bh_hashmap.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/utils/bh_hashmap.c.o"
  "/opt/wasm-micro-runtime/core/shared/utils/bh_list.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/utils/bh_list.c.o"
  "/opt/wasm-micro-runtime/core/shared/utils/bh_log.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/utils/bh_log.c.o"
  "/opt/wasm-micro-runtime/core/shared/utils/bh_queue.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/utils/bh_queue.c.o"
  "/opt/wasm-micro-runtime/core/shared/utils/bh_vector.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/utils/bh_vector.c.o"
  "/opt/wasm-micro-runtime/core/shared/utils/runtime_timer.c" "/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/vmlib.dir/opt/wasm-micro-runtime/core/shared/utils/runtime_timer.c.o"
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
  "vmlib_EXPORTS"
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
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
