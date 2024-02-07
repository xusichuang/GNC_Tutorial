
# 动态库
cpp_srcs := $(shell find src -name *.cpp)
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))

so_objs := $(filter-out objs/main.o,$(cpp_objs))

include_dir := /root/GNC_tutorial/Test/include
library_dirs := /root/GNC_tutorial/Test/lib
linking_libs := ddd

I_options := $(include_dir:%=-I%)
l_options := $(linking_libs:%=-l%)
L_options := $(library_dirs:%=-L%)
# 代表-Wl,-rpath
r_options := $(library_dirs:%=-Wl,-rpath=%)

compile_options := -g -O3 -w -fPIC $(I_options)
linking_options := $(l_options) $(L_options) $(r_options)

# 编译
objs/%.o : src/%.cpp
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options)

compile : $(cpp_objs)

lib/libddd.so : $(so_objs)
	@mkdir -p $(dir $@)
	@g++ -shared $^ -o$@

dynamic : lib/libddd.so

# 链接
workspace/exec : objs/main.o compile dynamic
	@mkdir -p $(dir $@)
	@g++ $< -o $@ $(linking_options)

run : workspace/exec
	@./$<


clean :
	@rm -rf lib objs workspace/exec

debug:
	@echo $(cpp_srcs)
	@echo $(cpp_objs)

.PHONY : debug compile