from pprint import pformat
from typing import Any

from pygments import highlight
from pygments.formatters import Terminal256Formatter
from pygments.lexers import PythonLexer


def pprint_color(obj: Any) -> None:
    print(highlight(pformat(obj, compact=True, sort_dicts=False), PythonLexer(), Terminal256Formatter()), end="")