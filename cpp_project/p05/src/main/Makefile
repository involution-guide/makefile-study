srcs_with_dir = $(wildcard ./*.cpp)
srcs_without_dir = $(notdir $(srcs_with_dir))
objs_without_path = $(patsubst %.cpp, %.o, $(srcs_without_dir))
objs = $(addprefix $(work_dir)/$(obj_dir)/,$(objs_without_path))
bin_name = $(work_dir)/$(bin_dir)/$(app)

target_main: $(bin_name)

$(bin_name): $(objs)
	$(CC) $(CPPFLAGS) $^ $(inc_path) -L$(work_dir)/$(lib_dir) -Wl,-rpath=$$ORIGIN../lib $(libs) -o $@

$(work_dir)/$(obj_dir)/%.o : %.cpp
	$(CC) $(CPPFLAGS) -c $< $(inc_path) -o $@ 


.PHONY: target_main