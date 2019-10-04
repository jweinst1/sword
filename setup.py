from distutils.core import setup, Extension


module1 = Extension('sword',
                    define_macros = [('USE_PRINTER', '1')],
                    include_dirs = ['include'],
                    sources = ['src/demo.c'])

setup (name = 'sword',
       version = '0.0.1',
       description = 'A data mining and searching C extension',
       author = 'Joshua Weinstein',
       author_email = 'jweinst1@berkeley.edu',
       url = 'https://docs.python.org/extending/building',
       long_description = open('README.md').read(),
       ext_modules = [module1])