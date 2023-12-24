from pprint import pformat
from typing import Any
import collections

from pygments import highlight
from pygments.formatters import Terminal256Formatter
from pygments.lexers import PythonLexer


def printc(obj: Any) -> None:
    print(highlight(pformat(obj, compact=True, sort_dicts=False),
          PythonLexer(), Terminal256Formatter()), end="")
    
def printt(reg: dict, memory: list):
    for key, value in reg.items():
        print(value, end=" ")
    for index, value in enumerate(memory):
        print(value, end=" ")