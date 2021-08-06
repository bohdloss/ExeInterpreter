#pragma once

#include <stdint.h>
#include <cstddef>

#define NO_MALLOC "Memory allocation failed\n"
#define NO_SIGNATURE "Executable file does not contain a valid signature\n"
#define NO_MAGIC "Executable file does not contain a valid magic number in its optional header\n"
    
#define IMAGE_PE32 0x10b
#define IMAGE_PE32PLUS 0x20b
    
#define IMAGE_FILE_MACHINE_UNKNOWN 0x0
#define IMAGE_FILE_MACHINE_AM33 0x1d3
#define IMAGE_FILE_MACHINE_AMD64 0x8664
#define IMAGE_FILE_MACHINE_ARM 0x1c0
#define IMAGE_FILE_MACHINE_ARM64 0xaa64
#define IMAGE_FILE_MACHINE_ARMNT 0x1c4
#define IMAGE_FILE_MACHINE_EBC 0xebc
#define IMAGE_FILE_MACHINE_I386 0x14c
#define IMAGE_FILE_MACHINE_IA64 0x200
#define IMAGE_FILE_MACHINE_M32R 0x9041
#define IMAGE_FILE_MACHINE_MIPS16 0x266
#define IMAGE_FILE_MACHINE_MIPSFPU 0x366
#define IMAGE_FILE_MACHINE_MIPSFPU16 0x466
#define IMAGE_FILE_MACHINE_POWERPC 0x1f0
#define IMAGE_FILE_MACHINE_POWERPCFP 0x1f1
#define IMAGE_FILE_MACHINE_R4000 0x166
#define IMAGE_FILE_MACHINE_RISCV32 0x5032
#define IMAGE_FILE_MACHINE_RISCV64 0x5064
#define IMAGE_FILE_MACHINE_RISCV128 0x5128
#define IMAGE_FILE_MACHINE_SH3 0x1a2
#define IMAGE_FILE_MACHINE_SH3DSP 0x1a3
#define IMAGE_FILE_MACHINE_SH4 0x1a6
#define IMAGE_FILE_MACHINE_SH5 0x1a8
#define IMAGE_FILE_MACHINE_THUMB 0x1c2
#define IMAGE_FILE_MACHINE_WCEMIPSV2 0x169
    
#define IMAGE_FILE_RELOCS_STRIPPED 0x0001
#define IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#define IMAGE_FILE_LINE_NUMS_STRIPPED 0x0004
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#define IMAGE_FILE_AGGRESSIVE_WS_TRIM 0x0010
#define IMAGE_FILE_LARGE_ADDRESS_AWARE 0x0020
#define IMAGE_FILE_BYTES_REVERSED_LO 0x0080
#define IMAGE_FILE_32BIT_MACHINE 0x0100
#define IMAGE_FILE_DEBUG_STRIPPED 0x0200
#define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP 0x0400
#define IMAGE_FILE_NET_RUN_FROM_SWAP 0x0800
#define IMAGE_FILE_SYSTEM 0x1000
#define IMAGE_FILE_DLL 0x2000
#define IMAGE_FILE_UP_SYSTEM_ONLY 0x4000
#define IMAGE_FILE_BYTES_REVERSED_HI 0x8000
    
#define IMAGE_SUBSYSTEM_UNKNOWN 0
#define IMAGE_SUBSYSTEM_NATIVE 1
#define IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#define IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#define IMAGE_SUBSYSTEM_OS2_CUI 5
#define IMAGE_SUBSYSTEM_POSIX_CUI 7
#define IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#define IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#define IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#define IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#define IMAGE_SUBSYSTEM_EFI_ROM 13
#define IMAGE_SUBSYSTEM_XBOX 14
#define IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION 16
    
#define IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA 0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#define IMAGE_DLLCHARACTERISTICS_NO_SEH 0x400
#define IMAGE_DLLCHARACTERISTICS_NO_BIND 0x800
#define IMAGE_DLLCHARACTERISTICS_APPCONTAINER 0x1000
#define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#define IMAGE_DLLCHARACTERISTICS_GUARD_CF 0x4000
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000
    
#define IMAGE_SCN_TYPE_NO_PAD 0x00000008
#define IMAGE_SCN_CNT_CODE 0x00000020
#define IMAGE_SCN_CNT_INITIALIZED_DATA 0x00000040
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA 0x00000080
#define IMAGE_SCN_LNK_OTHER 0x00000100
#define IMAGE_SCN_LNK_INFO 0x00000200
#define IMAGE_SCN_LNK_REMOVE 0x00000800
#define IMAGE_SCN_LNK_COMDAT 0x00001000
#define IMAGE_SCN_GPREL 0x00008000
#define IMAGE_SCN_MEM_PURGEABLE 0x00020000
#define IMAGE_SCN_MEM_16BIT 0x00020000
#define IMAGE_SCN_MEM_LOCKED 0x00040000
#define IMAGE_SCN_MEM_PRELOAD 0x00080000
#define IMAGE_SCN_ALIGN_1BYTES 0x00100000
#define IMAGE_SCN_ALIGN_2BYTES 0x00200000
#define IMAGE_SCN_ALIGN_4BYTES 0x00300000
#define IMAGE_SCN_ALIGN_8BYTES 0x00400000
#define IMAGE_SCN_ALIGN_16BYTES 0x00500000
#define IMAGE_SCN_ALIGN_32BYTES 0x00600000
#define IMAGE_SCN_ALIGN_64BYTES 0x00700000
#define IMAGE_SCN_ALIGN_128BYTES 0x00800000
#define IMAGE_SCN_ALIGN_256BYTES 0x00900000
#define IMAGE_SCN_ALIGN_512BYTES 0x00A00000
#define IMAGE_SCN_ALIGN_1024BYTES 0x00B00000
#define IMAGE_SCN_ALIGN_2048BYTES 0x00C00000
#define IMAGE_SCN_ALIGN_4096BYTES 0x00D00000
#define IMAGE_SCN_ALIGN_8192BYTES 0x00E00000
#define IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#define IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#define IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#define IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#define IMAGE_SCN_MEM_SHARED 0x10000000
#define IMAGE_SCN_MEM_EXECUTE 0x20000000
#define IMAGE_SCN_MEM_READ 0x40000000
#define IMAGE_SCN_MEM_WRITE 0x80000000
    
#define IMAGE_COFFSYMBOL_N_UNDEF 0
#define IMAGE_COFFSYMBOL_N_ABS -1
#define IMAGE_COFFSYMBOL_N_DEBUG -2
    
    typedef struct {
      uint32_t virtual_address;
      uint32_t size;
    } DATA_DIRECTORY;
    
    typedef struct {
        union {
            char name[8];
            struct {
                uint32_t zero;
                uint32_t offset;
            };
        };
        uint32_t value;
        int16_t section_number;
        uint16_t type;
        uint8_t cclass;
        uint8_t auxiliary_number;
    } COFF_SYMBOL_ENTRY;
    
    typedef struct {
        uint16_t machine;
        uint16_t number_of_sections;
        uint32_t time_stamp;
        uint32_t symbol_table_ptr;
        uint32_t symbol_amount;
        uint16_t optional_header_size;
        uint16_t characteristics;
    } __COFF__;
    
    typedef struct {
        uint16_t machine;
        uint16_t number_of_sections;
        uint32_t time_stamp;
        COFF_SYMBOL_ENTRY* symbol_table_ptr;
        uint32_t symbol_amount;
        uint16_t optional_header_size;
        uint16_t characteristics;
    } COFF;
    
    typedef struct {
        uint16_t magic;
        uint8_t major_linker_version;
        uint8_t minor_linker_version;
        uint32_t code_size;
        uint32_t initialized_data_size;
        uint32_t uninitialized_data_size;
        uint32_t entry_point_ptr;
        uint32_t base_of_code_ptr;
        uint32_t base_of_data_ptr;
        
        uint32_t image_base;
        uint32_t section_alignment;
        uint32_t file_alignment;
        uint16_t major_os_version;
        uint16_t minor_os_version;
        uint16_t major_image_version;
        uint16_t minor_image_version;
        uint16_t major_subsystem_version;
        uint16_t minor_subsystem_version;
        uint32_t win32_version_value;
        uint32_t size_of_image;
        uint32_t size_of_headers;
        uint32_t checksum;
        uint16_t subsystem;
        uint16_t dll_characteristics;
        uint32_t stack_reserve_size;
        uint32_t stack_commit_size;
        uint32_t heap_reserve_size;
        uint32_t heap_commit_size;
        uint32_t loader_flags;
        uint32_t number_of_directory_entries;
        
        DATA_DIRECTORY export_table;
        DATA_DIRECTORY import_table;
        DATA_DIRECTORY resource_table;
        DATA_DIRECTORY exception_table;
        DATA_DIRECTORY certificate_table;
        DATA_DIRECTORY base_relocation_table;
        DATA_DIRECTORY debug;
        DATA_DIRECTORY architecture;
        DATA_DIRECTORY global_ptr;
        DATA_DIRECTORY tls_table;
        DATA_DIRECTORY load_config_table;
        DATA_DIRECTORY bound_import_table;
        DATA_DIRECTORY import_address_table;
        DATA_DIRECTORY delay_import_descriptor;
        DATA_DIRECTORY clr_runtime_header;
        DATA_DIRECTORY unused;
    } PE32;
    
    typedef struct {
        uint16_t magic;
        uint8_t major_linker_version;
        uint8_t minor_linker_version;
        uint32_t code_size;
        uint32_t initialized_data_size;
        uint32_t uninitialized_data_size;
        uint32_t entry_point_ptr;
        uint32_t base_of_code_ptr;
        
        uint64_t image_base;
        uint32_t section_alignment;
        uint32_t file_alignment;
        uint16_t major_os_version;
        uint16_t minor_os_version;
        uint16_t major_image_version;
        uint16_t minor_image_version;
        uint16_t major_subsystem_version;
        uint16_t minor_subsystem_version;
        uint32_t win32_version_value;
        uint32_t size_of_image;
        uint32_t size_of_headers;
        uint32_t checksum;
        uint16_t subsystem;
        uint16_t dll_characteristics;
        uint64_t stack_reserve_size;
        uint64_t stack_commit_size;
        uint64_t heap_reserve_size;
        uint64_t heap_commit_size;
        uint32_t loader_flags;
        uint32_t number_of_directory_entries;
        
        DATA_DIRECTORY export_table;
        DATA_DIRECTORY import_table;
        DATA_DIRECTORY resource_table;
        DATA_DIRECTORY exception_table;
        DATA_DIRECTORY certificate_table;
        DATA_DIRECTORY base_relocation_table;
        DATA_DIRECTORY debug;
        DATA_DIRECTORY architecture;
        DATA_DIRECTORY global_ptr;
        DATA_DIRECTORY tls_table;
        DATA_DIRECTORY load_config_table;
        DATA_DIRECTORY bound_import_table;
        DATA_DIRECTORY import_address_table;
        DATA_DIRECTORY delay_import_descriptor;
        DATA_DIRECTORY clr_runtime_header;
        DATA_DIRECTORY unused;
    } PE32PLUS;
    
    typedef struct {
        char name[0x8];
        uint32_t virtual_size;
        uint32_t virtual_address;
        uint32_t raw_data_size;
        uint32_t raw_data_ptr;
        uint32_t relocation_ptr;
        uint32_t line_number_ptr;
        uint16_t number_of_relocation;
        uint16_t number_of_line_number;
        uint32_t characteristics;
    } SECTION_TABLE_ENTRY;

class PE {
public:
    PE();
    virtual ~PE();
    
    bool parse(size_t size, void* raw);
    bool relocate(void* address);
private:
    unsigned char* msdos_stub;
    char* signature;
    COFF* coff_header;
    union {
        PE32* optional_header; 
        PE32PLUS* optional_header_plus;
    };
    SECTION_TABLE_ENTRY* section_table;
};