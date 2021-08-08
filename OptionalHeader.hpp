#pragma once

#include "DataDirectory.hpp"
#include "Buffer.hpp"
#include <stdint.h>

class OptionalHeader {
public:
#pragma pack(push, 1)
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
        
        DataDirectory::nDataDirectory export_table;
        DataDirectory::nDataDirectory import_table;
        DataDirectory::nDataDirectory resource_table;
        DataDirectory::nDataDirectory exception_table;
        DataDirectory::nDataDirectory certificate_table;
        DataDirectory::nDataDirectory base_relocation_table;
        DataDirectory::nDataDirectory debug;
        DataDirectory::nDataDirectory architecture;
        DataDirectory::nDataDirectory global_ptr;
        DataDirectory::nDataDirectory tls_table;
        DataDirectory::nDataDirectory load_config_table;
        DataDirectory::nDataDirectory bound_import_table;
        DataDirectory::nDataDirectory import_address_table;
        DataDirectory::nDataDirectory delay_import_descriptor;
        DataDirectory::nDataDirectory clr_runtime_header;
        DataDirectory::nDataDirectory unused;
    } nPE32;
#pragma pack(pop)
    
#pragma pack(push, 1)
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
        
        DataDirectory::nDataDirectory export_table;
        DataDirectory::nDataDirectory import_table;
        DataDirectory::nDataDirectory resource_table;
        DataDirectory::nDataDirectory exception_table;
        DataDirectory::nDataDirectory certificate_table;
        DataDirectory::nDataDirectory base_relocation_table;
        DataDirectory::nDataDirectory debug;
        DataDirectory::nDataDirectory architecture;
        DataDirectory::nDataDirectory global_ptr;
        DataDirectory::nDataDirectory tls_table;
        DataDirectory::nDataDirectory load_config_table;
        DataDirectory::nDataDirectory bound_import_table;
        DataDirectory::nDataDirectory import_address_table;
        DataDirectory::nDataDirectory delay_import_descriptor;
        DataDirectory::nDataDirectory clr_runtime_header;
        DataDirectory::nDataDirectory unused;
    } nPE32PLUS;
#pragma pack(pop)
    
    OptionalHeader();
    virtual ~OptionalHeader();
    
    void parse(Buffer buffer, size_t header_size);
    size_t sizeOf();

    DataDirectory getArchitecture() const {
        return architecture;
    }

    uint32_t getBaseOfCodePtr() const {
        return base_of_code_ptr;
    }

    DataDirectory getBaseRelocationTable() const {
        return base_relocation_table;
    }

    DataDirectory getBoundImportTable() const {
        return bound_import_table;
    }

    DataDirectory getCertificateTable() const {
        return certificate_table;
    }

    uint32_t getChecksum() const {
        return checksum;
    }

    DataDirectory getClrRuntimeHeader() const {
        return clr_runtime_header;
    }

    uint32_t getCodeSize() const {
        return code_size;
    }

    DataDirectory getDebug() const {
        return debug;
    }

    DataDirectory getDelayImportDescriptor() const {
        return delay_import_descriptor;
    }

    uint16_t getDllCharacteristics() const {
        return dll_characteristics;
    }

    uint32_t getEntryPointPtr() const {
        return entry_point_ptr;
    }

    DataDirectory getExceptionTable() const {
        return exception_table;
    }

    DataDirectory getExportTable() const {
        return export_table;
    }

    uint32_t getFileAlignment() const {
        return file_alignment;
    }

    DataDirectory getGlobalPtr() const {
        return global_ptr;
    }

    uint64_t getHeapCommitSize() const {
        return heap_commit_size;
    }

    uint64_t getHeapReserveSize() const {
        return heap_reserve_size;
    }

    uint64_t getImageBase() const {
        return image_base;
    }

    DataDirectory getImportAddressTable() const {
        return import_address_table;
    }

    DataDirectory getImportTable() const {
        return import_table;
    }

    uint32_t getInitializedDataSize() const {
        return initialized_data_size;
    }

    DataDirectory getLoadConfigTable() const {
        return load_config_table;
    }

    uint32_t getLoaderFlags() const {
        return loader_flags;
    }

    uint16_t getMagic() const {
        return magic;
    }

    uint16_t getMajorImageVersion() const {
        return major_image_version;
    }

    uint8_t getMajorLinkerVersion() const {
        return major_linker_version;
    }

    uint16_t getMajorOsVersion() const {
        return major_os_version;
    }

    uint16_t getMajorSubsystemVersion() const {
        return major_subsystem_version;
    }

    uint16_t getMinorImageVersion() const {
        return minor_image_version;
    }

    uint8_t getMinorLinkerVersion() const {
        return minor_linker_version;
    }

    uint16_t getMinorOsVersion() const {
        return minor_os_version;
    }

    uint16_t getMinorSubsystemVersion() const {
        return minor_subsystem_version;
    }

    uint32_t getNumberOfDirectoryEntries() const {
        return number_of_directory_entries;
    }

    DataDirectory getResourceTable() const {
        return resource_table;
    }

    uint32_t getSectionAlignment() const {
        return section_alignment;
    }

    uint32_t getSizeOfHeaders() const {
        return size_of_headers;
    }

    uint32_t getSizeOfImage() const {
        return size_of_image;
    }

    uint64_t getStackCommitSize() const {
        return stack_commit_size;
    }

    uint64_t getStackReserveSize() const {
        return stack_reserve_size;
    }

    uint16_t getSubsystem() const {
        return subsystem;
    }

    DataDirectory getTlsTable() const {
        return tls_table;
    }

    uint32_t getUninitializedDataSize() const {
        return uninitialized_data_size;
    }

    DataDirectory getUnused() const {
        return unused;
    }

    uint32_t getWin32VersionValue() const {
        return win32_version_value;
    }

    bool isPe32Plus() const {
        return bPe32Plus;
    }
    
private:
        bool bPe32Plus;
        
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
};