import os
import re

# Current script directory
script_directory = os.path.dirname(os.path.abspath(__file__))

# Construct the source directory path by going up one level from the script directory and then into the 'Source' directory
source_directory = os.path.join(script_directory, os.pardir, 'Source')

# Normalize the path to resolve any ".." components
source_directory = os.path.normpath(source_directory)

print(f"Source directory set to: {source_directory}")

def find_structs(source_directory):
    """Scan source files for structs with the APPLY_ENTTUE_REFLECTION() macro on the same line or nearby."""
    structs = {}
    print("Starting to scan source files for tagged structs...")
    files_scanned = 0
    structs_found = 0

    struct_declaration_pattern = re.compile(r'struct\s+(F\w+)')
    reflection_macro = 'APPLY_ENTTUE_REFLECTION()'

    for root, dirs, files in os.walk(source_directory):
        for file in files:
            if file.endswith('.h'):
                file_path = os.path.join(root, file)
                print(f"Scanning file: {file_path}")
                files_scanned += 1
                
                with open(file_path, 'r') as f:
                    lines = f.readlines()
                    for i, line in enumerate(lines):
                        match = struct_declaration_pattern.search(line)
                        if match:
                            struct_name = match.group(1)
                            # Check the line above, the same line, and the line below for the macro
                            if (i > 0 and reflection_macro in lines[i-1]) or \
                               reflection_macro in line or \
                               (i < len(lines) - 1 and reflection_macro in lines[i+1]):
                                structs[struct_name] = file_path
                                structs_found += 1
                                print(f"Found tagged struct: {struct_name} in {file_path}")

    print(f"Finished scanning. Files scanned: {files_scanned}, Tagged structs found: {structs_found}")
    return structs

def generate_files(structs):
    """Generate or update .h and .cpp files based on templates for each struct or tag found, placing them in a 'generated' subdirectory."""
    generated_files = []  # Keep track of generated files
    print("Starting to generate/update files for found structs and tags...")
    
    # Paths to templates for structs
    template_h_path = os.path.join(script_directory, 'struct_layout.h')
    template_cpp_path = os.path.join(script_directory, 'struct_layout.cpp')
    
    # Paths to templates for tags
    tag_template_h_path = os.path.join(script_directory, 'tag_layout.h')
    tag_template_cpp_path = os.path.join(script_directory, 'tag_layout.cpp')

    event_template_h_path = os.path.join(script_directory, 'event_layout.h')
    event_template_cpp_path = os.path.join(script_directory, 'event_layout.cpp')
    
    for struct_name, original_file_path in structs.items():
        class_name = struct_name[1:]  # Remove the initial 'F' from the struct name
        
        # Determine if it's a tag or a struct based on whether the name ends with "Tag"
        is_tag = struct_name.endswith('Tag')
        is_event = struct_name.endswith('Event')
        
        # Choose the correct templates
        if is_tag:
            with open(tag_template_h_path, 'r') as file:
                template_h_content = file.read()
            with open(tag_template_cpp_path, 'r') as file:
                template_cpp_content = file.read()
        elif is_event:
            with open(event_template_h_path, 'r') as file:
                template_h_content = file.read()
            with open(event_template_cpp_path, 'r') as file:
                template_cpp_content = file.read()
        else:
            with open(template_h_path, 'r') as file:
                template_h_content = file.read()
            with open(template_cpp_path, 'r') as file:
                template_cpp_content = file.read()
        
        # Assuming the original struct headers are in the parent directory of 'generated'
        include_directive_h = f'#include "../{os.path.basename(original_file_path)}"'  # Adjusted for .h
        include_directive_cpp = f'#include "Generated_U{class_name}BlueprintLibrary.h"'  # For .cpp includes, since they are in the same 'generated' directory
        
        output_dir = os.path.join(os.path.dirname(original_file_path), 'generated')
        os.makedirs(output_dir, exist_ok=True)
        
        output_h_file_name = os.path.join(output_dir, f'Generated_U{class_name}BlueprintLibrary.h')
        output_cpp_file_name = os.path.join(output_dir, f'Generated_U{class_name}BlueprintLibrary.cpp')
        
        output_h_content = template_h_content.replace('$TypeName$', class_name).replace('$IncludePath$', include_directive_h)
        output_cpp_content = template_cpp_content.replace('$TypeName$', class_name).replace('$IncludePath$', include_directive_cpp)
        
        with open(output_h_file_name, 'w') as file:
            file.write(output_h_content)
        generated_files.append(output_h_file_name)
        
        with open(output_cpp_file_name, 'w') as file:
            file.write(output_cpp_content)
        generated_files.append(output_cpp_file_name)

    print("Finished generating/updating files.")
    return generated_files

def cleanup_old_files(source_directory):
    """Remove generated .h and .cpp files from '/generated' subdirectories."""
    print("Starting cleanup of old files in '/generated' subdirectories...")
    for root, dirs, files in os.walk(source_directory):
        # Check if we're in a 'generated' subdirectory
        if os.path.basename(root) == 'generated':
            for file in files:
                if file.endswith('BlueprintLibrary.h') or file.endswith('BlueprintLibrary.cpp'):
                    file_path = os.path.join(root, file)
                    print(f'Removing old file: {file_path}')
                    os.remove(file_path)
    print("Finished cleanup.")

structs = find_structs(source_directory)
cleanup_old_files(source_directory)
generated_files = generate_files(structs)
