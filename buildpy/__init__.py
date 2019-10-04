import os

"""
This package contains utilities to asset in the building process of sword
"""

class CDefinitions(object):
    """
    This class acts as a collection of definitions for a C preprocessor
    """
    
    def __init__(self):
        self.dmap = {}
        
    def __len__(self):
        return len(self.dmap)
        
    def to_list(self):
        return [(x, y) for x, y in self.dmap.items()]
        
    def define(self, key, value='1'):
        self.dmap[key] = value
        
    def __repr__(self):
        """
        This method forms a C-like source string of all the macros defined
        in the dmap.
        """
        return "\n".join(["#define {} {}".format(k, v) for k, v in self.dmap.items()])
    