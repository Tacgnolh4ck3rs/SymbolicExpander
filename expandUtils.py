import sympy
from sympy import expand, symbols 
from sympy.abc import *

def add(a, b):
    return a+b;

def expF(expr):
    return str(expand(expr));
    
