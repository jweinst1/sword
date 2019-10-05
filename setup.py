from distutils.core import setup, Extension

classifers_list = [
    'Development Status :: 2 - Pre-Alpha',
    'Operating System :: MacOS',
    'Operating System :: Microsoft :: Windows',
    'Operating System :: Unix',
    'Programming Language :: C',
    'Topic :: Scientific/Engineering :: Information Analysis'
    
]

sources_py = [
    'src/mainpy.c',
    'src/sword_csv.c'
]

module1 = Extension('sword',
                    define_macros = [('USE_PRINTER', '1')],
                    include_dirs = ['include'],
                    sources = sources_py)

setup (name = 'sword',
       version = '0.0.1',
       license= 'MIT',
       description = 'A fast, sharp, Python C extension for data mining.',
       author = 'Joshua Weinstein',
       author_email = 'jweinst1@berkeley.edu',
       url = 'https://github.com/jweinst1/sword',
       classifiers = classifers_list,
       long_description = open('README.md').read(),
       ext_modules = [module1])