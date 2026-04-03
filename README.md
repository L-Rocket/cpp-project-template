# test

这是一个 C++ 项目模板，包含标准的文件夹结构：

- `src/`：源代码文件
- `include/`：头文件
- `tests/`：测试代码
- `third_party/`：第三方库
- `build/`：编译输出（自动生成）
- `CMakeLists.txt`：构建脚本

## 构建规则

- `src/` 下所有 `*.cpp` 会被递归收集为项目源码（`src/main.cpp` 作为主程序入口单独处理）。
- `tests/` 下所有 `*.cpp` 会被递归收集并自动生成测试目标。
- 测试通过 CTest 执行，无需额外依赖。

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

5. 新增源码或测试文件后，重新构建即可自动纳入，无需手动修改 CMakeLists。
