#include "COFFHeader.hpp"
#include "Defines.hpp"

COFFHeader::COFFHeader() {
}

COFFHeader::~COFFHeader() {
    delete[] symbol_table_ptr;
    delete[] string_table_ptr;
    free(raw_string_table_ptr);
}

void COFFHeader::parse(Buffer buffer, size_t header_offset) {
    // Obtain structure as defined by the documentation
    nCOFF coff_struct = buffer.get<nCOFF>(header_offset);
    this->machine = coff_struct.machine;
    this->number_of_sections = coff_struct.number_of_sections;
    this->time_stamp = coff_struct.time_stamp;
    this->optional_header_size = coff_struct.optional_header_size;
    this->characteristics = coff_struct.characteristics;
    this->symbol_amount = coff_struct.symbol_amount;
    this->symbol_table_ptr = 0;
    
    if(coff_struct.symbol_amount != 0 && coff_struct.symbol_table_ptr != 0) {
        // Initialize the string table only if the symbol table is present
        uint32_t string_table_offset = coff_struct.symbol_table_ptr + (symbol_amount * sizeof(COFFSymbol::nSymbol));
        uint32_t string_table_size = buffer.get<uint32_t>(string_table_offset);

        if(string_table_size != 4) {
            // Calculate amount of strings
            uint32_t string_count = 0;
            for(uint32_t current_offset = string_table_offset + 4; current_offset < string_table_offset + string_table_size;) {
                char* str = current_offset + buffer.getData();
                uint32_t str_len = strlen(str) + 1;
                current_offset += str_len;
                string_count++;
            }

            // Allocate string table
            this->string_amount = string_count;
            this->string_table_ptr = new char*[string_amount];
            if(!string_table_ptr) {
                printf(NO_MALLOC);
                throw std::logic_error(NO_MALLOC);
            }

            // Copy string table
            uint32_t i = 0;
            for(uint32_t current_offset = string_table_offset + 4; current_offset < string_table_offset + string_table_size;) {
                char* str = current_offset + buffer.getData();
                uint32_t str_len = strlen(str) + 1;
                current_offset += str_len;

                string_table_ptr[i] = new char[str_len];
                if(!string_table_ptr[i]) {
                    printf(NO_MALLOC);
                    throw std::logic_error(NO_MALLOC);
                }

                memcpy(string_table_ptr[i], str, str_len);
                i++;
            }

            // Copy raw string table too
            this->raw_string_table_ptr = malloc(string_table_size);
            memcpy(raw_string_table_ptr, buffer.getData() + string_table_offset, string_table_size);
        } else {
            this->string_amount = 0;
            this->string_table_ptr = new char*[0];
            this->raw_string_table_ptr = malloc(0);
        }
        
        // Debugging information is present, copy it
        this->symbol_table_ptr = new COFFSymbol[symbol_amount];
        
        for(uint32_t i = 0; i < symbol_amount; i++) {
            symbol_table_ptr[i].parse(buffer, coff_struct.symbol_table_ptr, &i, this);
        }
    } else {
        this->symbol_amount = 0;
        this->symbol_table_ptr = new COFFSymbol[0];
        this->string_amount = 0;
        this->string_table_ptr = new char*[0];
        this->raw_string_table_ptr = malloc(0);
    }
}