#pragma once

#include "DataDirectory.hpp"

class OptionalHeader {
public:
    OptionalHeader();
    virtual ~OptionalHeader();
private:
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
        
        DataDirectory export_table;
        DataDirectory import_table;
        DataDirectory resource_table;
        DataDirectory exception_table;
        DataDirectory certificate_table;
        DataDirectory base_relocation_table;
        DataDirectory debug;
        DataDirectory architecture;
        DataDirectory global_ptr;
        DataDirectory tls_table;
        DataDirectory load_config_table;
        DataDirectory bound_import_table;
        DataDirectory import_address_table;
        DataDirectory delay_import_descriptor;
        DataDirectory clr_runtime_header;
        DataDirectory unused;
    } nPE32;
    
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
        
        DataDirectory export_table;
        DataDirectory import_table;
        DataDirectory resource_table;
        DataDirectory exception_table;
        DataDirectory certificate_table;
        DataDirectory base_relocation_table;
        DataDirectory debug;
        DataDirectory architecture;
        DataDirectory global_ptr;
        DataDirectory tls_table;
        DataDirectory load_config_table;
        DataDirectory bound_import_table;
        DataDirectory import_address_table;
        DataDirectory delay_import_descriptor;
        DataDirectory clr_runtime_header;
        DataDirectory unused;
    } nPE32PLUS;
};