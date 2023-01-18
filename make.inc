LOCAL_PATH	:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDFLAGS   := -lpthread -lm -ldl\
                   -L$(PREBUILD_OSS_DIR)/libpcap/usr/lib -lpcap \
                   -L$(PREBUILD_OSS_DIR)/libnl3/usr/lib -lnl-3 \
				   -L$(PREBUILD_OSS_DIR)/ncurses/usr/lib -lncurses \
				   -Wl,-rpath-link=$(PREBUILD_OSS_DIR)/libpcap/usr/lib \
				   -Wl,-rpath-link=$(PREBUILD_OSS_DIR)/libnl3/usr/lib \
				   -Wl,-rpath-link=$(PREBUILD_OSS_DIR)/ncurses/usr/lib
LOCAL_TARGET	:= iftop
LOCAL_CFLAGS := -I$(PREBUILD_OSS_DIR)/libpcap/include -static -I$(PREBUILD_OSS_DIR)/ncurses/include -std=c2x
LOCAL_SRCS	:= $(LOCAL_PATH)/addr_hash.c $(LOCAL_PATH)/edline.c $(LOCAL_PATH)/hash.c $(LOCAL_PATH)/iftop.c $(LOCAL_PATH)/ns_hash.c \
               $(LOCAL_PATH)/options.c $(LOCAL_PATH)/resolver.c $(LOCAL_PATH)/screenfilter.c $(LOCAL_PATH)/serv_hash.c \
			   $(LOCAL_PATH)/sorted_list.c $(LOCAL_PATH)/threadprof.c $(LOCAL_PATH)/ui.c $(LOCAL_PATH)/util.c \
			   $(LOCAL_PATH)/addrs_ioctl.c $(LOCAL_PATH)/addrs_dlpi.c $(LOCAL_PATH)/dlcommon.c\
			   $(LOCAL_PATH)/stringmap.c $(LOCAL_PATH)/cfgfile.c $(LOCAL_PATH)/vector.c


include $(BUILD_APP)

.PHONY: $(LOCAL_TARGET)

$(LOCAL_TARGET): $(LOCAL_MODULE)
	@mkdir -p $(UNIT_TEST_PATH)/
	@cp -dpRf $< $(UNIT_TEST_PATH)/
	@echo "Build $@ Done."

$(call add-target-into-build, $(LOCAL_TARGET))
