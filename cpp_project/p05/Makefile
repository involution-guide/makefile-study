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
export app = hello
# 构建目录
export build_dir = build
# 可执行文件目录
export bin_dir = $(build_dir)/bin
# 启动脚本目录
export sbin_dir = $(build_dir)/sbin
# 中间文件目录
export obj_dir = $(build_dir)/obj
# 库文件目录
export lib_dir = $(build_dir)/lib

# ----------------------------------------------------------------
# 编译模式 debug | release
export compile_mode = release
# 编译器相关
export CC := g++
export CPPFLAGS := -std=c++14
ifeq ($(compile_mode), debug)
	export CPPFLAGS += -Wall -g
else
	export CPPFLAGS += -O3
endif

# 工作目录
export work_dir = $(shell pwd)

# person 库名称
export person_name = person
# person 动态库名称
export person_dynamic_lib_name = lib$(person_name).so
# person 静态库名称
export person_static_lib_name = lib$(person_name).a
# person 库链接方式 dynamic | static
export person_link_type = dynamic
ifeq ($(person_link_type), dynamic)
	export person_link = -lperson
else
	export person_link = -l:libperson.a
endif
export libs = $(person_link)


# 头文件目录
export inc_path = -I $(work_dir)/include
# 库文件目录
export lib_path = -L $(work_dir)/$(build_dir)/lib

export MAKE = make -w

# 默认目标
ALL: before_build
	@$(MAKE) -C src/person
	@$(MAKE) -C src/main
	@$(MAKE) after_build


# 伪目标
.PHONY:before_build clean run rebuild rerun after_build help ALL
# 构建前准备, 创建目录
before_build:
	@if [ ! -d $(obj_dir) ]; then \
	mkdir -p $(obj_dir); \
	fi
	@if [ ! -d $(bin_dir) ]; then \
	mkdir -p $(bin_dir); \
	fi
	@if [ ! -d $(lib_dir) ]; then \
	mkdir -p $(lib_dir); \
	fi
	@if [ ! -d $(sbin_dir) ]; then \
	mkdir -p $(sbin_dir); \
	fi
# 构建后复制脚本并添加执行权限
after_build:
	@echo 'build success'
	cp $(work_dir)/resources/hello $(sbin_dir)/hello
	chmod u+x $(sbin_dir)/hello
help:
	@echo -e 'run : 编译并运行'
	@echo -e 'clean : 清理'
	@echo -e 'rebuild : 清理并重新构建'
	@echo -e 'rerun : 清理并重新构建然后运行'
	@echo -e 'help : 显示帮助列表'
# 清理
clean:
	-rm -rf $(build_dir)
# 运行
run: ALL
	cd $(bin_dir); ./$(app)
# 重新构建
rebuild: clean ALL
# 重新运行
rerun: clean run
test:
	@echo $(work_dir)
