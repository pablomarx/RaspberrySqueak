LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE_SRCS += \
	$(LOCAL_DIR)/B2DPlugin.c \
	$(LOCAL_DIR)/BitBltPlugin.c \
	$(LOCAL_DIR)/FilePlugin.c \
	$(LOCAL_DIR)/LargeIntegers.c \
	$(LOCAL_DIR)/Matrix2x3Plugin.c \
	$(LOCAL_DIR)/MiscPrimitivePlugin.c \
	$(LOCAL_DIR)/SecurityPlugin.c \
	$(LOCAL_DIR)/interp.c \
	$(LOCAL_DIR)/sqNamedPrims.c \
	$(LOCAL_DIR)/sqVirtualMachine.c \


include $(LOCAL_DIR)/FloatMathPlugin/rules.mk
