from distutils.core import setup, Extension

pyrk_hash_module = Extension('pyrk_hash',
                                 sources = ['pyrkmodule.c',
                                            'pyrk.c',
                                            'pyrk/yespower/yespower-sha256.c',
                                            'pyrk/yespower/yespower-opt.c',
                                            'pyrk/yespower/yespower.c',
                                            'pyrk/x11/blake.c',
                                            'pyrk/x11/bmw.c',
                                            'pyrk/x11/cubehash.c',
                                            'pyrk/x11/echo.c',
                                            'pyrk/x11/groestl.c',
                                            'pyrk/x11/jh.c',
                                            'pyrk/x11/keccak.c',
                                            'pyrk/x11/luffa.c',
                                            'pyrk/x11/shavite.c',
                                            'pyrk/x11/simd.c',
                                            'pyrk/x11/skein.c',
                                            'pyrk/x11/x11.c',
                                            'pyrk/sha256/sha256.c',
                                            'pyrk/scrypt/scrypt.c'],
                               include_dirs=['.', './pyrk/x11', './pyrk/yespower', './pyrk/sha256', './pyrk/scrypt'],
                               libraries = ['ssl', 'crypto'])

setup (name = 'pyrk_hash',
       version = '1.0',
       description = 'Binding for pyrk multialgo hash.',
       ext_modules = [pyrk_hash_module])
