from pprint import pformat
from typing import Any
import collections

from pygments import highlight
from pygments.formatters import Terminal256Formatter
from pygments.lexers import PythonLexer


def pprint_color(obj: Any) -> None:
    print(highlight(pformat(obj, compact=True, sort_dicts=False),
          PythonLexer(), Terminal256Formatter()), end="")
    
def print_snapshot(snapshots):
    view = collections.defaultdict(list)
    for snapshot in snapshots:
        for reg, value in snapshot['reg'].items():
            view[reg].append(value)

        for i, value in enumerate(snapshot['memory']):
            view[i].append(value)

    pprint_color(view)