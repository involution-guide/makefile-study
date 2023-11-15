# 通用 C++ Makefile 
# 版本: V2024
# 
# 使用方法:
# make run : 编译并运行
# make clean : 清理
# make rebuild : 清理并重新编译
# make rerun : 清理并重新编译然后运行
# make help : 显示帮助列表
#
#

# 可执行程序
app = hello
# 构建目录
build_dir = build
# 可执行文件目录
bin_dir = $(build_dir)/bin
# 中间文件目录
obj_dir = $(build_dir)/obj

# ----------------------------------------------------------------

# 头文件目录
inc_path = -I ./include

# 源文件目录
src_path = ./src
# 源文件列表
srcs = $(foreach dir, $(src_path),$(wildcard $(dir)/*.cpp))

# .o 文件列表
srcs_without_dir = $(notdir $(srcs))
objs_without_dir = $(patsubst %.cpp, %.o, $(srcs_without_dir))
objs = $(addprefix $(obj_dir)/,$(objs_without_dir))

# 源文件搜索路径
vpath %.cpp $(src_path)

# 默认目标
ALL: build_prepare $(bin_dir)/$(app)

# 构建可执行程序
$(bin_dir)/$(app): $(objs)
	g++ $^ -o $@

# 生成中间文件
$(obj_dir)/%.o : %.cpp
	g++ -c $< -I ./include -o $@ 

# 为目标
.PHONY:build_prepare clean run rebuild rerun test ALL
# 构建前准备, 创建目录
build_prepare:
	@if [ ! -d $(build_dir) ]; then \
	mkdir -p $(obj_dir); \
	mkdir -p $(bin_dir); \
	fi
# 清理
clean:
	-rm -rf $(build_dir)
# 运行
run: build_prepare $(bin_dir)/$(app)
	./$(bin_dir)/hello
# 重新构建
rebuild: clean ALL
# 重新运行
rerun: clean run
