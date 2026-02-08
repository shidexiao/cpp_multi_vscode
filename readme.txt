从 0 上手：单个文件 → 系统工程（分阶段）
前置准备：环境搭建（核心区别于 Python）
Python 开发只需装解释器 + pip，C/C++ 必须先装编译器 / 构建工具链：

操作系统适配：
Windows：装 MinGW-w64（gcc/g++）或 MSVC（Visual Studio Build Tools）
macOS：装 Xcode Command Line Tools（xcode-select --install）
Linux：装 gcc/g++/make（sudo apt install build-essential）

工具配置：
VSCode：装核心插件「C/C++」（Microsoft 官方）+ 可选「CMake」「CMake Tools」
CLion：无需额外插件，安装时会自动检测编译器，若未检测到手动指定路径即可（同 PyCharm 指定 Python 解释器）


Python 的def → C++ 的函数（声明 + 实现）；
Python 的类 → C++ 的类（头文件声明，源文件实现）；
Python 的import → C++ 的#include+ 链接；
Python 的虚拟环境 → C++ 的 CMake 指定编译器 / 库路径。


多文件项目（对应 Python 多模块脚本，如app.py + utils.py）
核心目标：管理多个源文件的依赖、编译链接（Python 直接 import 即可，C/C++ 需手动声明 / 链接）。
my_project/
  ├── src/
  │   ├── main.cpp       # 主程序
  │   └── utils.cpp      # 工具函数
  └── include/
      └── utils.h        # 头文件（声明函数，对应Python的模块导出）


==========
场景 2：多文件项目（对标 Python 多模块脚本，如 main.py + utils.py）

目标
拆分代码为「头文件（声明）+ 源文件（实现）+ 主文件（调用）」，用 CMake 管理编译（替代手动敲复杂编译命令）。
步骤 1：创建目录结构
cpp_multi_file/
  ├── include/          # 头文件目录（对标Python的utils模块的接口）
  │   └── calculator.h  # 计算器工具类的声明
  ├── src/              # 源文件目录
  │   ├── calculator.cpp # 计算器工具类的实现
  │   └── main.cpp      # 主程序
  └── CMakeLists.txt    # CMake配置文件（对标Python的setup.py）


步骤 2：编写文件内容
1. include/calculator.h（头文件：声明函数 / 类，对标 Python 的函数定义）

2. src/calculator.cpp（源文件：实现函数）

3. src/main.cpp（主文件：调用工具函数）

4. CMakeLists.txt（核心配置文件）


步骤 3：编译运行（CMake 方式）
1，打开 VSCode 终端，进入项目根目录；
2，创建 build 目录（分离源码和编译产物，对标 Python 的 venv）：
mkdir build && cd build

3，CMake 配置（生成 Makefile）：
# Windows（MinGW）
cmake .. -G "MinGW Makefiles"
# macOS/Linux
cmake ..

4，编译（执行 Makefile）：
# Windows（MinGW）
mingw32-make
# macOS/Linux
make

5，运行可执行文件：
# Windows
.\app.exe
# macOS/Linux
./app

步骤 4：VSCode 中调试多文件项目
按Ctrl+Shift+P，输入「CMake: Configure」，选择编译器（如 g++）；
再输入「CMake: Build」，完成编译；
点击「运行和调试」面板（Ctrl+Shift+D），点击「创建 launch.json 文件」，选择「C/C++」→「(gdb) 启动」；
修改launch.json中的program字段为编译后的可执行文件路径：
"program": "${workspaceFolder}/build/app", // Windows改为${workspaceFolder}/build/app.exe
打断点后按 F5，即可调试多文件代码（断点可打在 calculator.cpp 中）。