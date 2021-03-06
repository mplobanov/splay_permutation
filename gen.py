preamble = '// This file is autogenerated by the script\n' \
           '// It contains all source and headers files from the project\n' \
           '// without unnecessary `#include` and `#pragma` directives\n' \
           '// Special for Y.Contest\n' \
           '\n\n\n'

ending = '\n// Generated by the script\n'

source_files = [
    'splay-tree/Tree.h',
    'splay-tree/construct.cpp',
    'splay-tree/std_in_out.cpp',
    'splay-tree/splay.cpp',
    'splay-tree/utilitites.cpp',
    'splay-tree/find.cpp',
    'splay-tree/basic_operations.cpp',
    'splay-tree/operations.cpp',
    'main.cpp',
]
main_source = ''
for file in source_files:
    with open(file) as f:
        main_source += "\n"
        main_source += '//' + ('-' * 100) + '\n'
        main_source += f'// FILE {file} BEGINS HERE\n'
        main_source += '//' + ('-' * 100) + '\n'
        main_source += f.read()
        main_source += "\n"
        main_source += '//' + ('-' * 100) + '\n'
        main_source += f'// FILE {file} ENDS HERE\n'
        main_source += '//' + ('-' * 100) + '\n'

strs = main_source.split('\n')
incls = list(filter(lambda x: x.startswith('#include'),  strs))
othrs = list(filter(lambda x: not x.startswith('#'), strs))
system_incls = list(filter(lambda x: '"' not in x, incls))

main_source = preamble +  "\n".join(system_incls + othrs) + ending

with open('output.cpp', 'w') as f:
    f.write(main_source)