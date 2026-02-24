# overview

Source code for "Computer Graphics Programming in OpenGL Using C++, 3rd" on my understanding

## Book information

"Computer Graphics Programming in OpenGL with C++, 3rd Edition"
by V. Scott Gordon and John Clevenger
published by Mercury Learning ©2024.
![Book Cover](images/cover.png)

- [The book website from author](https://athena.ecs.csus.edu/~gordonvs/textC3E.html)
You can download the companion files there.

## Prepare the development environment

### Operation System

This repo is based on Windows 11 x64. And GPU is NVIDIA GeForce GTX 1080 with OpenGL 4.6 support. (Detected by [gpu-z](https://www.techpowerup.com/gpuz/))

### IDE

This repo uses Visual Studio 2026 Community Edition with Desktop C++ feature enabled.

### Powershell

Original version is 5.1. Now upgrade to 7.5.

#### check the current verson

```powershell
PS c:\> $PSVersionTable

Name                           Value
----                           -----
PSVersion                      5.1.26100.7705
PSEdition                      Desktop
PSCompatibleVersions           {1.0, 2.0, 3.0, 4.0...}
BuildVersion                   10.0.26100.7705
CLRVersion                     4.0.30319.42000
WSManStackVersion              3.0
PSRemotingProtocolVersion      2.3
SerializationVersion           1.1.0.1
```

#### upgrade to 7.5

Download the PowerShell-7.5.4-win-x64.msi package directly from Microsoft and install it.

```powershell
PS C:\> $PSVersionTable

Name                           Value
----                           -----
PSVersion                      7.5.4
PSEdition                      Core
GitCommitId                    7.5.4
OS                             Microsoft Windows 10.0.26100
Platform                       Win32NT
PSCompatibleVersions           {1.0, 2.0, 3.0, 4.0…}
PSRemotingProtocolVersion      2.3
SerializationVersion           1.1.0.1
WSManStackVersion              3.0
```

### Scoop

[Scoop](https://scoop.sh/) is A command-line installer for Windows. We will use it to install cmake and premake.

#### Installation

```powershell
PS C:\> Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
PS C:\> irm get.scoop.sh | iex
Initializing...
Downloading...
Extracting...
Creating shim...
Adding ~\scoop\shims to your path.
Scoop was installed successfully!
Type 'scoop help' for instructions.
PS C:\> scoop help
Usage: scoop <command> [<args>]

Available commands are listed below.

Type 'scoop help <command>' to get more help for a specific command.

Command    Summary
-------    -------
alias      Manage scoop aliases
bucket     Manage Scoop buckets
cache      Show or clear the download cache
cat        Show content of specified manifest.
checkup    Check for potential problems
cleanup    Cleanup apps by removing old versions
config     Get or set configuration values
create     Create a custom app manifest
depends    List dependencies for an app, in the order they'll be installed
download   Download apps in the cache folder and verify hashes
export     Exports installed apps, buckets (and optionally configs) in JSON format
help       Show help for a command
hold       Hold an app to disable updates
home       Opens the app homepage
import     Imports apps, buckets and configs from a Scoopfile in JSON format
info       Display information about an app
install    Install apps
list       List installed apps
prefix     Returns the path to the specified app
reset      Reset an app to resolve conflicts
search     Search available apps
shim       Manipulate Scoop shims
status     Show status and check for new app versions
unhold     Unhold an app to enable updates
uninstall  Uninstall an app
update     Update apps, or Scoop itself
virustotal Look for app's hash or url on virustotal.com
which      Locate a shim/executable (similar to 'which' on Linux)

```

### cmake

[cmake website](https://cmake.org)

#### Installation

```powershell
PS C:\> scoop install cmake
Installing 'cmake' (4.2.3) [64bit] from 'main' bucket
cmake-4.2.3-windows-x86_64.zip (48.1 MB) [====================================================================] 100%
Checking hash of cmake-4.2.3-windows-x86_64.zip ... ok.
Extracting cmake-4.2.3-windows-x86_64.zip ... done.
Linking ~\scoop\apps\cmake\current => ~\scoop\apps\cmake\4.2.3
Creating shim for 'cmake'.
Creating shim for 'cmcldeps'.
Creating shim for 'cpack'.
Creating shim for 'ctest'.
Creating shim for 'cmake-gui'.
Making C:\Users\boyal\scoop\shims\cmake-gui.exe a GUI binary.
Creating shortcut for cmake-gui (cmake-gui.exe)
'cmake' (4.2.3) was installed successfully!

PS C:\>  cmake --version
cmake version 4.2.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

### premake

```powershell
PS C:\> scoop install premake
Installing 'premake' (5.0.0-beta8) [64bit] from 'main' bucket
premake-5.0.0-beta8-windows.zip (597.4 KB) [==================================================================] 100%
Checking hash of premake-5.0.0-beta8-windows.zip ... ok.
Extracting premake-5.0.0-beta8-windows.zip ... done.
Linking ~\scoop\apps\premake\current => ~\scoop\apps\premake\5.0.0-beta8
Creating shim for 'premake5'.
'premake' (5.0.0-beta8) was installed successfully!

PS C:\> premake5 --version
premake5 (Premake Build Script Generator) 5.0.0-beta8
```

### Window Management

- [GLFW - Graphics Library Framework](https://www.glfw.org/)
- [GLFW source code](https://github.com/glfw/glfw)

#### Compile and build

Open the 'x64 Native Tools Command Prompt for VS' in the Visual Studio 2026 group of the start menu. Cmake will detect the VS2026 automatically.

```powershell
E:\test\glfw-3.4>cmake -S E:\test\glfw-3.4 -B E:\test\glfw-3.4\build
-- Building for: Visual Studio 18 2026
-- The C compiler identification is MSVC 19.50.35724.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files/Microsoft Visual Studio/18/Community/VC/Tools/MSVC/14.50.35717/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - not found
-- Found Threads: TRUE
-- Including Win32 support
-- Could NOT find Doxygen (missing: DOXYGEN_EXECUTABLE)
-- Documentation generation requires Doxygen 1.9.8 or later
-- Configuring done (7.4s)
-- Generating done (0.3s)
-- Build files have been written to: E:/test/glfw-3.4/build

E:\test\glfw-3.4>cmake --build build --config Release
...
...
Done.

```

You will find glfw3.lib in the build\src\Release.

### Extension Library

![alt text](images/glew.png)

- [GLEW - OpenGL Extension Wrangler](https://glew.sourceforge.net/) Download the binary directly.
- [GLEW source code](https://github.com/nigels-com/glew.git)

Download the binary version glew-2.3.1-win32.zip, for example.

### Math Library

![glm](images/glm.png)

- [GLM - OpenGL Mathematics](https://glm.g-truc.net)
- [GLM source code](https://github.com/g-truc/glm)

Download the source code and it is a header-only libary.

### Texture Management

![SOIL](images/soil.png)

- [SOIL2 - Simple OpenGL Image Loader](https://github.com/SpartanJ/SOIL2)

Download the source code zip.
using premake to generate the visual studio solution.

```powershell
E:\test\SOIL2-1.31>premake5 vs2026
Building configurations...
Running action 'vs2026'...
Generated make/windows/SOIL2.slnx...
Generated make/windows/soil2-static-lib.vcxproj...
Generated make/windows/soil2-shared-lib.vcxproj...
Generated make/windows/soil2-test.vcxproj...
Generated make/windows/soil2-test.vcxproj.filters...
Generated make/windows/soil2-perf-test.vcxproj...
Generated make/windows/soil2-perf-test.vcxproj.filters...
Done (96ms).
```

The open the make\windows\SOIL2.slnx with Visual Studio 2026. Set the release and x64, then build the project soil2-static-lib. You will see the soil2.lib in lib\windows folder.

```powershell
E:\test\SOIL2-1.31>dir lib\windows

2026/02/13  22:29    <DIR>          .
2026/02/13  22:29    <DIR>          ..
2026/02/13  22:29         1,178,996 soil2.lib
2026/02/13  22:29           159,744 soil2.pdb

```

### Prepare shared "lib" and "include" folders

Choose a location where you would like to house the library files. It could be a folder anywhere you prefer. Inside that folder, create subfolders named "lib" an d "include".

- In the "lib" folder, place glew32.lib, glew32.dll, glfw3.lib and soil2.lib.
- In the "include" folder, place the **GL**, **GLFW** and **glm** folders.
  - copy glm/glm to inculude
  - copy SOIL2/src/SOIL2 to include

Then, the folder should be simular like below:

```powershell
E:\libs>tree /F
├─include
│  ├─GL
│  │      eglew.h
│  │      glew.h
│  │      glxew.h
│  │      wglew.h
│  │
│  ├─GLFW
│  │      glfw3.h
│  │      glfw3native.h
│  │
│  ├─glm
│  │  │  CMakeLists.txt
│  │  │  common.hpp
│  │  │  exponential.hpp
│  │  │  ext.hpp
│  │  │  fwd.hpp
│  │  │  geometric.hpp
│  │  │  glm.cppm
│  │  │  glm.hpp
│  │  │  integer.hpp
│  │  │  mat2x2.hpp
│  │  │  mat2x3.hpp
│  │  │  mat2x4.hpp
│  │  │  mat3x2.hpp
│  │  │  mat3x3.hpp
│  │  │  mat3x4.hpp
│  │  │  mat4x2.hpp
│  │  │  mat4x3.hpp
│  │  │  mat4x4.hpp
│  │  │  matrix.hpp
│  │  │  packing.hpp
│  │  │  trigonometric.hpp
│  │  │  vec2.hpp
│  │  │  vec3.hpp
│  │  │  vec4.hpp
│  │  │  vector_relational.hpp
│  │  │
│  │  ├─detail
│  │  │      compute_common.hpp
│  │  │      compute_vector_decl.hpp
│  │  │      compute_vector_relational.hpp
│  │  │      func_common.inl
│  │  │      func_common_simd.inl
│  │  │      func_exponential.inl
│  │  │      func_exponential_simd.inl
│  │  │      func_geometric.inl
│  │  │      func_geometric_simd.inl
│  │  │      func_integer.inl
│  │  │      func_integer_simd.inl
│  │  │      func_matrix.inl
│  │  │      func_matrix_simd.inl
│  │  │      func_packing.inl
│  │  │      func_packing_simd.inl
│  │  │      func_trigonometric.inl
│  │  │      func_trigonometric_simd.inl
│  │  │      func_vector_relational.inl
│  │  │      func_vector_relational_simd.inl
│  │  │      glm.cpp
│  │  │      qualifier.hpp
│  │  │      setup.hpp
│  │  │      type_float.hpp
│  │  │      type_half.hpp
│  │  │      type_half.inl
│  │  │      type_mat2x2.hpp
│  │  │      type_mat2x2.inl
│  │  │      type_mat2x3.hpp
│  │  │      type_mat2x3.inl
│  │  │      type_mat2x4.hpp
│  │  │      type_mat2x4.inl
│  │  │      type_mat3x2.hpp
│  │  │      type_mat3x2.inl
│  │  │      type_mat3x3.hpp
│  │  │      type_mat3x3.inl
│  │  │      type_mat3x4.hpp
│  │  │      type_mat3x4.inl
│  │  │      type_mat4x2.hpp
│  │  │      type_mat4x2.inl
│  │  │      type_mat4x3.hpp
│  │  │      type_mat4x3.inl
│  │  │      type_mat4x4.hpp
│  │  │      type_mat4x4.inl
│  │  │      type_mat4x4_simd.inl
│  │  │      type_quat.hpp
│  │  │      type_quat.inl
│  │  │      type_quat_simd.inl
│  │  │      type_vec1.hpp
│  │  │      type_vec1.inl
│  │  │      type_vec2.hpp
│  │  │      type_vec2.inl
│  │  │      type_vec3.hpp
│  │  │      type_vec3.inl
│  │  │      type_vec4.hpp
│  │  │      type_vec4.inl
│  │  │      type_vec_simd.inl
│  │  │      _features.hpp
│  │  │      _fixes.hpp
│  │  │      _noise.hpp
│  │  │      _swizzle.hpp
│  │  │      _swizzle_func.hpp
│  │  │      _vectorize.hpp
│  │  │
│  │  ├─ext
│  │  │      matrix_clip_space.hpp
│  │  │      matrix_clip_space.inl
│  │  │      matrix_common.hpp
│  │  │      matrix_common.inl
│  │  │      matrix_double2x2.hpp
│  │  │      matrix_double2x2_precision.hpp
│  │  │      matrix_double2x3.hpp
│  │  │      matrix_double2x3_precision.hpp
│  │  │      matrix_double2x4.hpp
│  │  │      matrix_double2x4_precision.hpp
│  │  │      matrix_double3x2.hpp
│  │  │      matrix_double3x2_precision.hpp
│  │  │      matrix_double3x3.hpp
│  │  │      matrix_double3x3_precision.hpp
│  │  │      matrix_double3x4.hpp
│  │  │      matrix_double3x4_precision.hpp
│  │  │      matrix_double4x2.hpp
│  │  │      matrix_double4x2_precision.hpp
│  │  │      matrix_double4x3.hpp
│  │  │      matrix_double4x3_precision.hpp
│  │  │      matrix_double4x4.hpp
│  │  │      matrix_double4x4_precision.hpp
│  │  │      matrix_float2x2.hpp
│  │  │      matrix_float2x2_precision.hpp
│  │  │      matrix_float2x3.hpp
│  │  │      matrix_float2x3_precision.hpp
│  │  │      matrix_float2x4.hpp
│  │  │      matrix_float2x4_precision.hpp
│  │  │      matrix_float3x2.hpp
│  │  │      matrix_float3x2_precision.hpp
│  │  │      matrix_float3x3.hpp
│  │  │      matrix_float3x3_precision.hpp
│  │  │      matrix_float3x4.hpp
│  │  │      matrix_float3x4_precision.hpp
│  │  │      matrix_float4x2.hpp
│  │  │      matrix_float4x2_precision.hpp
│  │  │      matrix_float4x3.hpp
│  │  │      matrix_float4x3_precision.hpp
│  │  │      matrix_float4x4.hpp
│  │  │      matrix_float4x4_precision.hpp
│  │  │      matrix_int2x2.hpp
│  │  │      matrix_int2x2_sized.hpp
│  │  │      matrix_int2x3.hpp
│  │  │      matrix_int2x3_sized.hpp
│  │  │      matrix_int2x4.hpp
│  │  │      matrix_int2x4_sized.hpp
│  │  │      matrix_int3x2.hpp
│  │  │      matrix_int3x2_sized.hpp
│  │  │      matrix_int3x3.hpp
│  │  │      matrix_int3x3_sized.hpp
│  │  │      matrix_int3x4.hpp
│  │  │      matrix_int3x4_sized.hpp
│  │  │      matrix_int4x2.hpp
│  │  │      matrix_int4x2_sized.hpp
│  │  │      matrix_int4x3.hpp
│  │  │      matrix_int4x3_sized.hpp
│  │  │      matrix_int4x4.hpp
│  │  │      matrix_int4x4_sized.hpp
│  │  │      matrix_integer.hpp
│  │  │      matrix_integer.inl
│  │  │      matrix_projection.hpp
│  │  │      matrix_projection.inl
│  │  │      matrix_relational.hpp
│  │  │      matrix_relational.inl
│  │  │      matrix_transform.hpp
│  │  │      matrix_transform.inl
│  │  │      matrix_uint2x2.hpp
│  │  │      matrix_uint2x2_sized.hpp
│  │  │      matrix_uint2x3.hpp
│  │  │      matrix_uint2x3_sized.hpp
│  │  │      matrix_uint2x4.hpp
│  │  │      matrix_uint2x4_sized.hpp
│  │  │      matrix_uint3x2.hpp
│  │  │      matrix_uint3x2_sized.hpp
│  │  │      matrix_uint3x3.hpp
│  │  │      matrix_uint3x3_sized.hpp
│  │  │      matrix_uint3x4.hpp
│  │  │      matrix_uint3x4_sized.hpp
│  │  │      matrix_uint4x2.hpp
│  │  │      matrix_uint4x2_sized.hpp
│  │  │      matrix_uint4x3.hpp
│  │  │      matrix_uint4x3_sized.hpp
│  │  │      matrix_uint4x4.hpp
│  │  │      matrix_uint4x4_sized.hpp
│  │  │      quaternion_common.hpp
│  │  │      quaternion_common.inl
│  │  │      quaternion_common_simd.inl
│  │  │      quaternion_double.hpp
│  │  │      quaternion_double_precision.hpp
│  │  │      quaternion_exponential.hpp
│  │  │      quaternion_exponential.inl
│  │  │      quaternion_float.hpp
│  │  │      quaternion_float_precision.hpp
│  │  │      quaternion_geometric.hpp
│  │  │      quaternion_geometric.inl
│  │  │      quaternion_relational.hpp
│  │  │      quaternion_relational.inl
│  │  │      quaternion_transform.hpp
│  │  │      quaternion_transform.inl
│  │  │      quaternion_trigonometric.hpp
│  │  │      quaternion_trigonometric.inl
│  │  │      scalar_common.hpp
│  │  │      scalar_common.inl
│  │  │      scalar_constants.hpp
│  │  │      scalar_constants.inl
│  │  │      scalar_integer.hpp
│  │  │      scalar_integer.inl
│  │  │      scalar_int_sized.hpp
│  │  │      scalar_packing.hpp
│  │  │      scalar_packing.inl
│  │  │      scalar_reciprocal.hpp
│  │  │      scalar_reciprocal.inl
│  │  │      scalar_relational.hpp
│  │  │      scalar_relational.inl
│  │  │      scalar_uint_sized.hpp
│  │  │      scalar_ulp.hpp
│  │  │      scalar_ulp.inl
│  │  │      vector_bool1.hpp
│  │  │      vector_bool1_precision.hpp
│  │  │      vector_bool2.hpp
│  │  │      vector_bool2_precision.hpp
│  │  │      vector_bool3.hpp
│  │  │      vector_bool3_precision.hpp
│  │  │      vector_bool4.hpp
│  │  │      vector_bool4_precision.hpp
│  │  │      vector_common.hpp
│  │  │      vector_common.inl
│  │  │      vector_double1.hpp
│  │  │      vector_double1_precision.hpp
│  │  │      vector_double2.hpp
│  │  │      vector_double2_precision.hpp
│  │  │      vector_double3.hpp
│  │  │      vector_double3_precision.hpp
│  │  │      vector_double4.hpp
│  │  │      vector_double4_precision.hpp
│  │  │      vector_float1.hpp
│  │  │      vector_float1_precision.hpp
│  │  │      vector_float2.hpp
│  │  │      vector_float2_precision.hpp
│  │  │      vector_float3.hpp
│  │  │      vector_float3_precision.hpp
│  │  │      vector_float4.hpp
│  │  │      vector_float4_precision.hpp
│  │  │      vector_int1.hpp
│  │  │      vector_int1_sized.hpp
│  │  │      vector_int2.hpp
│  │  │      vector_int2_sized.hpp
│  │  │      vector_int3.hpp
│  │  │      vector_int3_sized.hpp
│  │  │      vector_int4.hpp
│  │  │      vector_int4_sized.hpp
│  │  │      vector_integer.hpp
│  │  │      vector_integer.inl
│  │  │      vector_packing.hpp
│  │  │      vector_packing.inl
│  │  │      vector_reciprocal.hpp
│  │  │      vector_reciprocal.inl
│  │  │      vector_relational.hpp
│  │  │      vector_relational.inl
│  │  │      vector_uint1.hpp
│  │  │      vector_uint1_sized.hpp
│  │  │      vector_uint2.hpp
│  │  │      vector_uint2_sized.hpp
│  │  │      vector_uint3.hpp
│  │  │      vector_uint3_sized.hpp
│  │  │      vector_uint4.hpp
│  │  │      vector_uint4_sized.hpp
│  │  │      vector_ulp.hpp
│  │  │      vector_ulp.inl
│  │  │      _matrix_vectorize.hpp
│  │  │
│  │  ├─gtc
│  │  │      bitfield.hpp
│  │  │      bitfield.inl
│  │  │      color_space.hpp
│  │  │      color_space.inl
│  │  │      constants.hpp
│  │  │      constants.inl
│  │  │      epsilon.hpp
│  │  │      epsilon.inl
│  │  │      integer.hpp
│  │  │      integer.inl
│  │  │      matrix_access.hpp
│  │  │      matrix_access.inl
│  │  │      matrix_integer.hpp
│  │  │      matrix_inverse.hpp
│  │  │      matrix_inverse.inl
│  │  │      matrix_transform.hpp
│  │  │      matrix_transform.inl
│  │  │      noise.hpp
│  │  │      noise.inl
│  │  │      packing.hpp
│  │  │      packing.inl
│  │  │      quaternion.hpp
│  │  │      quaternion.inl
│  │  │      quaternion_simd.inl
│  │  │      random.hpp
│  │  │      random.inl
│  │  │      reciprocal.hpp
│  │  │      round.hpp
│  │  │      round.inl
│  │  │      type_aligned.hpp
│  │  │      type_precision.hpp
│  │  │      type_precision.inl
│  │  │      type_ptr.hpp
│  │  │      type_ptr.inl
│  │  │      ulp.hpp
│  │  │      ulp.inl
│  │  │      vec1.hpp
│  │  │
│  │  ├─gtx
│  │  │      associated_min_max.hpp
│  │  │      associated_min_max.inl
│  │  │      bit.hpp
│  │  │      bit.inl
│  │  │      closest_point.hpp
│  │  │      closest_point.inl
│  │  │      color_encoding.hpp
│  │  │      color_encoding.inl
│  │  │      color_space.hpp
│  │  │      color_space.inl
│  │  │      color_space_YCoCg.hpp
│  │  │      color_space_YCoCg.inl
│  │  │      common.hpp
│  │  │      common.inl
│  │  │      compatibility.hpp
│  │  │      compatibility.inl
│  │  │      component_wise.hpp
│  │  │      component_wise.inl
│  │  │      dual_quaternion.hpp
│  │  │      dual_quaternion.inl
│  │  │      easing.hpp
│  │  │      easing.inl
│  │  │      euler_angles.hpp
│  │  │      euler_angles.inl
│  │  │      extend.hpp
│  │  │      extend.inl
│  │  │      extended_min_max.hpp
│  │  │      extended_min_max.inl
│  │  │      exterior_product.hpp
│  │  │      exterior_product.inl
│  │  │      fast_exponential.hpp
│  │  │      fast_exponential.inl
│  │  │      fast_square_root.hpp
│  │  │      fast_square_root.inl
│  │  │      fast_trigonometry.hpp
│  │  │      fast_trigonometry.inl
│  │  │      float_normalize.inl
│  │  │      functions.hpp
│  │  │      functions.inl
│  │  │      gradient_paint.hpp
│  │  │      gradient_paint.inl
│  │  │      handed_coordinate_space.hpp
│  │  │      handed_coordinate_space.inl
│  │  │      hash.hpp
│  │  │      hash.inl
│  │  │      integer.hpp
│  │  │      integer.inl
│  │  │      intersect.hpp
│  │  │      intersect.inl
│  │  │      io.hpp
│  │  │      io.inl
│  │  │      iteration.hpp
│  │  │      iteration.inl
│  │  │      log_base.hpp
│  │  │      log_base.inl
│  │  │      matrix_cross_product.hpp
│  │  │      matrix_cross_product.inl
│  │  │      matrix_decompose.hpp
│  │  │      matrix_decompose.inl
│  │  │      matrix_factorisation.hpp
│  │  │      matrix_factorisation.inl
│  │  │      matrix_interpolation.hpp
│  │  │      matrix_interpolation.inl
│  │  │      matrix_major_storage.hpp
│  │  │      matrix_major_storage.inl
│  │  │      matrix_operation.hpp
│  │  │      matrix_operation.inl
│  │  │      matrix_query.hpp
│  │  │      matrix_query.inl
│  │  │      matrix_transform_2d.hpp
│  │  │      matrix_transform_2d.inl
│  │  │      mixed_product.hpp
│  │  │      mixed_product.inl
│  │  │      norm.hpp
│  │  │      norm.inl
│  │  │      normal.hpp
│  │  │      normal.inl
│  │  │      normalize_dot.hpp
│  │  │      normalize_dot.inl
│  │  │      number_precision.hpp
│  │  │      optimum_pow.hpp
│  │  │      optimum_pow.inl
│  │  │      orthonormalize.hpp
│  │  │      orthonormalize.inl
│  │  │      pca.hpp
│  │  │      pca.inl
│  │  │      perpendicular.hpp
│  │  │      perpendicular.inl
│  │  │      polar_coordinates.hpp
│  │  │      polar_coordinates.inl
│  │  │      projection.hpp
│  │  │      projection.inl
│  │  │      quaternion.hpp
│  │  │      quaternion.inl
│  │  │      range.hpp
│  │  │      raw_data.hpp
│  │  │      raw_data.inl
│  │  │      rotate_normalized_axis.hpp
│  │  │      rotate_normalized_axis.inl
│  │  │      rotate_vector.hpp
│  │  │      rotate_vector.inl
│  │  │      scalar_multiplication.hpp
│  │  │      scalar_relational.hpp
│  │  │      scalar_relational.inl
│  │  │      spline.hpp
│  │  │      spline.inl
│  │  │      std_based_type.hpp
│  │  │      std_based_type.inl
│  │  │      string_cast.hpp
│  │  │      string_cast.inl
│  │  │      structured_bindings.hpp
│  │  │      structured_bindings.inl
│  │  │      texture.hpp
│  │  │      texture.inl
│  │  │      transform.hpp
│  │  │      transform.inl
│  │  │      transform2.hpp
│  │  │      transform2.inl
│  │  │      type_aligned.hpp
│  │  │      type_aligned.inl
│  │  │      type_trait.hpp
│  │  │      type_trait.inl
│  │  │      vector_angle.hpp
│  │  │      vector_angle.inl
│  │  │      vector_query.hpp
│  │  │      vector_query.inl
│  │  │      vec_swizzle.hpp
│  │  │      wrap.hpp
│  │  │      wrap.inl
│  │  │
│  │  └─simd
│  │          common.h
│  │          exponential.h
│  │          geometric.h
│  │          integer.h
│  │          matrix.h
│  │          neon.h
│  │          packing.h
│  │          platform.h
│  │          trigonometric.h
│  │          vector_relational.h
│  │
│  └─SOIL2
│          image_DXT.c
│          image_DXT.h
│          image_helper.c
│          image_helper.h
│          pkm_helper.h
│          pvr_helper.h
│          SOIL2.c
│          SOIL2.h
│          stbi_DDS.h
│          stbi_DDS_c.h
│          stbi_ext.h
│          stbi_ext_c.h
│          stbi_pkm.h
│          stbi_pkm_c.h
│          stbi_pvr.h
│          stbi_pvr_c.h
│          stbi_qoi.h
│          stbi_qoi_c.h
│          stbi_qoi_write.h
│          stb_image.h
│          stb_image_write.h
│          wfETC.c
│          wfETC.h
│
└─lib
        glew32.dll
        glew32.lib
        glfw3.lib
        soil2.lib
        soil2.pdb

```

### Configurate the Visual Studio project to run the first sample

- Start the Visual Studio 2026
- Create the solution that Empty Project with c++.
- Place the main.cpp with the code below:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

```

- build and run the project, make sure everything is ok.
- In "debug" mode, go into "project properties" and make the following chagnes:
  - Under "c/c++" -> "General" -> "Addition include Directories", add add **include** folder you created previously.
  - Under "Linker" -> "General" -> "Addition Library Directories", and add the **lib** folder you created previously.
  - Under "Linker" -> "Input" -> "Addition Dependencies", and add the following filenames: **glew32.lib**\ng**lfw3.lib**\n**soil2.lib**\n**opengl32.lib**, each filename one line.
- Copy the glew32.dll to your project root folder.
- change the main.cpp to program 2.1 in page 10 of the book.
- make sure you can build and run the project.

**Good lucky!**

## How to build the project in your local machine

### set the environment variable

- Open the "Edit the environment variables for current user" in the start menu.
- Add a new user variable named "CG_OPENGL_3RD_WIN_LIBS_PATH" with the value of the path to the folder where you put the include and lib, for example: C:\libs.
- Save the changes and start the Visual Studio 2026.
- Copy the glew32.dll to your project root folder.
- Then trigger build action, and you should be able to build and run the project successfully.
