# test

这是一个 C++ 项目模板，包含标准的文件夹结构：

- `src/`：源代码文件
- `include/`：头文件
- `tests/`：测试代码
- `third_party/`：第三方库
- `build/`：编译输出（自动生成）
- `CMakeLists.txt`：构建脚本（自动发现 src/tests）

## 构建规则

- `src/` 下所有 `*.cpp` 会被递归收集为项目源码（`src/main.cpp` 作为主程序入口单独处理）。
- `tests/` 下所有 `*.cpp` 会被递归收集并生成测试目标。
- 测试框架统一使用 GoogleTest，通过 CTest 执行。

## 快速开始

1. 配置项目

```bash
cmake -S . -B build
```

2. 构建

```bash
cmake --build build
```

3. 运行主程序

```bash
./build/main
```

4. 运行测试

```bash
ctest --test-dir build --output-on-failure
```

5. 在 `src/` 或 `tests/` 新增多层目录 `*.cpp` 文件后，重新构建即可自动纳入（无需额外脚本）。

6. 首次配置时如果本地没有 GoogleTest，CMake 会自动拉取依赖。