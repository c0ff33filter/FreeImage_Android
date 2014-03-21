LOCAL_PATH := $(call my-dir)


include $(LOCAL_PATH)/Makefile.srcs
include $(CLEAR_VARS)
LOCAL_MODULE       := LibFreeImage
LOCAL_C_INCLUDES   := $(LOCAL_PATH)/Source \
                        $(LOCAL_PATH)/Source/Metadata \
                        $(LOCAL_PATH)/Source/FreeImageToolkit \
                        $(LOCAL_PATH)/Source/LibJPEG \
                        $(LOCAL_PATH)/Source/LibPNG \
                        $(LOCAL_PATH)/Source/LibTIFF4 \
                        $(LOCAL_PATH)/Source/ZLib \
                        $(LOCAL_PATH)/Source/LibOpenJPEG \
                        $(LOCAL_PATH)/Source/OpenEXR \
                        $(LOCAL_PATH)/Source/OpenEXR/Half \
                        $(LOCAL_PATH)/Source/OpenEXR/Iex \
                        $(LOCAL_PATH)/Source/OpenEXR/IlmImf \
                        $(LOCAL_PATH)/Source/OpenEXR/IlmThread \
                        $(LOCAL_PATH)/Source/OpenEXR/Imath \
                        $(LOCAL_PATH)/Source/LibRawLite \
                        $(LOCAL_PATH)/Source/LibRawLite/dcraw \
                        $(LOCAL_PATH)/Source/LibRawLite/internal \
                        $(LOCAL_PATH)/Source/LibRawLite/libraw \
                        $(LOCAL_PATH)/Source/LibRawLite/src
LOCAL_SRC_FILES    := $(SRCS)
LOCAL_CPP_FEATURES := rtti exceptions
LOCAL_CFLAGS       := -O3 -fPIC 
include $(BUILD_STATIC_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE    := FreeImage
LOCAL_SRC_FILES := FreeImage.cpp
LOCAL_STATIC_LIBRARIES := LibFreeImage
LOCAL_LDLIBS    := -lm
include $(BUILD_SHARED_LIBRARY)