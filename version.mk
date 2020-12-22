# module version as a C literal
MODULE_VERSION?=7
# module version as hex string in little endian format
MODULE_VERSION_LE?=0700

FIRMWARE_VERSION?=0.0.7

CPPFLAGS += -DESP32_NCP_FIRMWARE_VERSION=$(FIRMWARE_VERSION)
CPPFLAGS += -DESP32_NCP_FIRMWARE_MODULE_VERSION=$(MODULE_VERSION)
