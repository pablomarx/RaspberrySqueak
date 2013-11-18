LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE_SRCS += \
	$(LOCAL_DIR)/atags.c \
	$(LOCAL_DIR)/errors.c \
	$(LOCAL_DIR)/framebuffer.c \
	$(LOCAL_DIR)/interrupts.c \
	$(LOCAL_DIR)/mailbox.c \
	$(LOCAL_DIR)/mmu.c \
	$(LOCAL_DIR)/sqRpiMinimal.c \
	$(LOCAL_DIR)/sqRpiStubs.c \
	$(LOCAL_DIR)/start.s \
	$(LOCAL_DIR)/timer.c \
	$(LOCAL_DIR)/uart.c \
